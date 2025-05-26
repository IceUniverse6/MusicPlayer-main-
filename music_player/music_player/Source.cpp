#include<iostream>
#include"Admin.h"
#include"RegularUser.h"

using namespace std;


void sign_in(DataBase&);
void sign_up(DataBase&);
void admin_page(shared_ptr<Admin>, DataBase&);
void user_page(shared_ptr<RegularUser>, DataBase&);

int main() {

	int command;
	DataBase database;

	shared_ptr<Admin> admin1 = make_shared<Admin>("admin1", "1234");
	shared_ptr<Admin> admin2 = make_shared<Admin>("admin2", "abcd");
	shared_ptr<Admin> admin3 = make_shared<Admin>("admin3", "1234");

	database.add_admin(admin1);
	database.add_admin(admin2);
	database.add_admin(admin3);

	cout << "WELCOME" << endl;

	while (true) {
		cout << "1. already have an account (sign in)" << endl;
		cout << "2. don't have an account (sign up, users only)" << endl;
		cout << "3. exit" << endl;
		cout << "command: ";

		cin >> command;
		cin.ignore();

		if (command == 1) {
			sign_in(database);
		}
		else if (command == 2) {
			sign_up(database);
		}
		else if (command == 3) {
			break;
		}
		else {
			cout << "invalid command!, try again" << endl;
		}
	}

	return 0;
}




void sign_in(DataBase& database) {
	int command;
	size_t i;
	shared_ptr<Admin> found_admin;
	shared_ptr<RegularUser> found_user;
	string user_name, password;

	cout << "sign in" << endl;

	while (true) {
		cout << "1. admin" << endl;
		cout << "2. user" << endl;
		cout << "3. exit" << endl;
		cout << "choose your role: ";
		cin >> command;
		cin.ignore();

		if (command == 1) {
			cout << "please enter your username: ";
			getline(cin, user_name);
			cout << "please enter your password: ";
			getline(cin, password);

			found_admin = database.find_admin(user_name, password);

			if (found_admin) {
				admin_page(found_admin, database);
			}
			else {
				cout << "admin not found!" << endl;
			}
			user_name.clear();
			password.clear();
		}
		else if (command == 2) {
			cout << "please enter your username: ";
			getline(cin, user_name);
			cout << "please enter your password: ";
			getline(cin, password);

			found_user = database.find_user(user_name, password);

			if (found_user) {
				user_page(found_user, database);
			}
			else {
				cout << "user not found" << endl;
			}
			user_name.clear();
			password.clear();
		}
		else if (command == 3) {
			return;
		}
		else {
			cout << "invalid input!, try again" << endl;
		}
	}
}
void sign_up(DataBase& database) {
	string user_name, password;

	cout << "sign up" << endl;

	cout << "please enter username: ";
	getline(cin, user_name);
	cout << "please enter password: ";
	getline(cin, password);

	shared_ptr<RegularUser> new_user = make_shared<RegularUser>(user_name, password);
	database.add_user(new_user);

	cout << "account created successfully" << endl;

}
void admin_page(shared_ptr<Admin> admin, DataBase& database) {

	int command;

	cout << "welcome " << admin->get_user_name() << endl;

	while (true) {

		cout << "please choose a task" << endl;
		cout << "1. add new song" << endl;
		cout << "2. add new playlist" << endl;
		cout << "3. add singer page" << endl;
		cout << "4. add song to playlist" << endl;
		cout << "5. add song for singer" << endl;
		cout << "6. add playlist for singer" << endl;

		cout << "7. remove song from system" << endl;
		cout << "8. remove playlist from system" << endl;
		cout << "9. remove singer page" << endl;
		cout << "10. remove song from playlist" << endl;
		cout << "11. remove song for singer" << endl;
		cout << "12. remove playlist for singer" << endl;

		cout << "13. edit singer info" << endl;

		cout << "14. show added songs" << endl;
		cout << "15. show added playlists" << endl;
		cout << "16. show added singers" << endl;

		cout << "17. exit" << endl;

		cout << "task: ";
		cin >> command;
		cin.ignore();


		if (command == 1) {
			admin->add_song(database);
		}
		else if (command == 2) {
			admin->add_playlist(database);
		}
		else if (command == 3) {
			admin->add_singer_page(database);
		}
		else if (command == 4) {
			admin->add_song_to_playlist(database);
		}
		else if (command == 5) {
			admin->add_music_for_singer(database);
		}
		else if (command == 6) {
			admin->add_playlist_for_singer(database);
		}
		else if (command == 7) {
			admin->remove_song_from_system(database);
		}
		else if (command == 8) {
			admin->remove_playlist_from_system(database);
		}
		else if (command == 9) {
			admin->remove_singer_page(database);
		}
		else if (command == 10) {
			admin->remove_song_from_playlist();
		}
		else if (command == 11) {
			admin->remove_song_for_singer();
		}
		else if (command == 12) {
			admin->remove_playlist_for_singer();
		}
		else if (command == 13) {
			admin->edit_singer_info();
		}
		else if (command == 14) {
			admin->show_added_songs();
		}
		else if (command == 15) {
			admin->show_added_playlists();
		}
		else if (command == 16) {
			admin->show_added_singers();
		}
		else if (command == 17) {
			return;
		}
		else {
			cout << "invalid input!, try again" << endl;
		}
	}
}
void user_page(shared_ptr<RegularUser> user, DataBase& database) {

	int command, index;

	cout << "welcome " << user->get_user_name() << endl;

	while (true) {
		cout << "please choose a task" << endl;

		cout << "1. play song" << endl;
		cout << "2. create new playlist" << endl;
		cout << "3. add song to playlist" << endl;
		cout << "4. add favourite song" << endl;
		cout << "5. add saved song" << endl;
		cout << "6. add favourite playlist" << endl;
		cout << "7. add saved playlist" << endl;
		cout << "8. remove playlist" << endl;
		cout << "9. remove song from playlist" << endl;
		cout << "10. remove favourite song" << endl;
		cout << "11. remove saved song" << endl;
		cout << "12. remove favoutite playlist" << endl;
		cout << "13. remove saved playlist" << endl;
		cout << "14. search for song" << endl;
		cout << "15. search for playlist" << endl;
		cout << "16. search for singer" << endl;
		cout << "17. filter song" << endl;
		cout << "18. show list of favourite songs" << endl;
		cout << "19. show list of saved songs" << endl;
		cout << "20. show list of favourite playlists" << endl;
		cout << "21. show list of saved playlists" << endl;
		cout << "22. show created playlists" << endl;

		cout << "23. show all songs in database" << endl;
		cout << "24. show all playlists in database" << endl;
		cout << "25. show all singers in database" << endl;

		cout << "26. change username or password" << endl;

		cout << "27. exit" << endl;

		cout << "task: ";
		cin >> command;
		cin.ignore();
		if (command == 1) {
			user->play_song();
		}
		else if (command == 2) {
			user->create_playlist(database);
		}
		else if (command == 3) {
			user->add_song_to_playlist(database);
		}
		else if (command == 4) {
			if (database.get_number_of_all_songs() > 0) {
				database.show_all_songs();
				while (true) {
					cout << "please choose the song: ";
					cin >> index;
					cin.ignore();

					if ((index >= 1) && (index <= database.get_number_of_all_songs())) {
						break;
					}
					else {
						cout << "invalid input!, try again" << endl;
					}
				}
				user->add_favourite_song(database.song_at(index - 1));
				cout << "song added to your favourites" << endl;
			}
			else {
				database.show_all_songs();
			}
		}
		else if (command == 5) {
			if (database.get_number_of_all_songs() > 0) {
				database.show_all_songs();
				while (true) {
					cout << "please choose the song: ";
					cin >> index;
					cin.ignore();

					if ((index >= 1) && (index <= database.get_number_of_all_songs())) {
						break;
					}
					else {
						cout << "invalid input!, try again" << endl;
					}
				}
				user->add_saved_song(database.song_at(index - 1));
				cout << "song added to your saved songs" << endl;
			}
			else {
				database.show_all_songs();
			}
		}
		else if (command == 6) {
			if (database.get_number_of_all_playlists() > 0) {
				database.show_all_playlists();
				while (true) {
					cout << "please choose the playlist: ";
					cin >> index;
					cin.ignore();

					if ((index >= 1) && (index <= database.get_number_of_all_playlists())) {
						break;
					}
					else {
						cout << "invalid input!, try again" << endl;
					}
				}
				user->add_favourite_playlist(database.playlist_at(index - 1));
				cout << "playlist added to your favourites" << endl;
			}
			else {
				database.show_all_playlists();
			}
		}
		else if (command == 7) {
			if (database.get_number_of_all_playlists() > 0) {
				database.show_all_playlists();
				while (true) {
					cout << "please choose the playlist: ";
					cin >> index;
					cin.ignore();

					if ((index >= 1) && (index <= database.get_number_of_all_playlists())) {
						break;
					}
					else {
						cout << "invalid input!, try again" << endl;
					}
				}
				user->add_saved_playlist(database.playlist_at(index - 1));
				cout << "playlist added to your saved playlists" << endl;
			}
			else {
				database.show_all_playlists();
			}
		}
		else if (command == 8) {
			user->remove_playlist(database);
		}
		else if (command == 9) {
			user->remove_song_from_playlist();
		}
		else if (command == 10) {
			user->remove_favourite_song();
		}
		else if (command == 11) {
			user->remove_saved_song();
		}
		else if (command == 12) {
			user->remove_favourite_playlist();
		}
		else if (command == 13) {
			user->remove_saved_plylist();
		}
		else if (command == 14) {
			user->search_for_song(database);
		}
		else if (command == 15) {
			user->search_for_playlist(database);
		}
		else if (command == 16) {
			user->search_for_singer(database);
		}
		else if (command == 17) {
			//user->filter_song();
		}
		else if (command == 18) {
			user->show_list_of_favourite_songs();
		}
		else if (command == 19) {
			user->show_list_of_saved_songs();
		}
		else if (command == 20) {
			user->show_list_of_favourite_playlists();
		}
		else if (command == 21) {
			user->show_list_of_saved_playlists();
		}
		else if (command == 22) {
			user->show_created_playlists();
		}
		else if (command == 23) {
			database.show_all_songs();
		}
		else if (command == 24) {
			database.show_all_playlists();
		}
		else if (command == 25) {
			database.show_all_singers();
		}
		else if (command == 26) {
			user->change_user_name_and_password();
		}
		else if (command == 27) {
			return;
		}
		else {//************************************
			cout << "invalid input!, try again" << endl;
		}

	}
}