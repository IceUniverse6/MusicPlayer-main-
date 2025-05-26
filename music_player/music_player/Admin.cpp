#include "Admin.h"

Admin::Admin(std::string user_name, std::string password)
	:BaseUser(user_name, password)
{
}
Admin::~Admin() {

}

void Admin::add_song(DataBase& database) {
	std::string song_name, singer_name, genre;
	int release_year;

	std::cout << "please enter song name: ";
	std::getline(std::cin, song_name);
	std::cout << "please enter singer name: ";
	std::getline(std::cin, singer_name);
	std::cout << "please enter release year: ";
	std::cin >> release_year;
	std::cin.ignore();
	std::cout << "please enter song genre: ";
	std::getline(std::cin, genre);

	std::shared_ptr<Song> new_song = std::make_shared<Song>(song_name, singer_name, release_year, genre);
	database.add_song(new_song);
	this->added_songs.push_back(new_song);

	std::cout << "song added to system successfully" << std::endl;
}
void Admin::add_playlist(DataBase& database) {
	int command, index;
	std::string playlist_name;
	std::cout << "please enter playlist name: ";
	std::getline(std::cin, playlist_name);

	std::shared_ptr<PlayList> new_playlist = std::make_shared<PlayList>(playlist_name);
	database.add_playlist(new_playlist);
	this->added_playlists.push_back(new_playlist);

	std::cout << "playlist added to system successfully" << std::endl;

	while (true) {
		std::cout << "do you want to add any song to it? (1 is yes and 0 is no): ";
		std::cin >> command;
		std::cin.ignore();

		if ((command == 0) || (command == 1)) {
			break;
		}
		else {
			std::cout << "invalid input!, try again" << std::endl;
		}
	}

	if (command == 0) {
		return;
	}
	else if (command == 1) {
		if (database.get_number_of_all_songs() > 0) {
			database.show_all_songs();

			while (true) {
				std::cout << "choose the song that you want to add to playlist: ";
				std::cin >> index;
				std::cin.ignore();

				if ((index >= 1) && (index <= database.get_number_of_all_songs())) {
					break;
				}
				else {
					std::cout << "invalid input!, try again" << std::endl;
				}
			}

			new_playlist->add_song(database.song_at(index - 1));
			std::cout << "song added to playlist successfully" << std::endl;

		}
		else {
			database.show_all_songs();
		}
	}
}
void Admin::add_song_to_playlist(DataBase& database) {
	int song_index, playlist_index;
	if (this->added_playlists.size() == 0) {
		std::cout << "you have not added any playlists yet" << std::endl;
		return;
	}
	this->show_added_playlists();
	while (true) {
		std::cout << "choose the playlist that you want to add song to: ";
		std::cin >> playlist_index;
		std::cin.ignore();

		if ((playlist_index >= 1) && (playlist_index <= this->added_playlists.size())) {
			break;
		}
		else {
			std::cout << "invalid input!, try again" << std::endl;
		}
	}

	if (database.get_number_of_all_songs() > 0) {
		database.show_all_songs();

		while (true) {
			std::cout << "choose the song that you want to add to playlist: ";
			std::cin >> song_index;
			std::cin.ignore();

			if ((song_index >= 1) && (song_index <= database.get_number_of_all_songs())) {
				break;
			}
			else {
				std::cout << "invalid input!, try again" << std::endl;
			}
		}
		this->added_playlists.at(playlist_index - 1)->add_song(database.song_at(song_index - 1));
		std::cout << "song added to playlist successfully" << std::endl;
	}
	else {
		database.show_all_songs();
	}
}
void Admin::remove_song_from_playlist() {
	int song_index, playlist_index;
	if (this->added_playlists.size() == 0) {
		std::cout << "you have not added any playlists yet" << std::endl;
		return;
	}
	this->show_added_playlists();
	while (true) {
		std::cout << "choose the playlist that you want to remove song from: ";
		std::cin >> playlist_index;
		std::cin.ignore();

		if ((playlist_index >= 1) && (playlist_index <= this->added_playlists.size())) {
			break;
		}
		else {
			std::cout << "invalid input!, try again" << std::endl;
		}
	}
	if (this->added_playlists.at(playlist_index - 1)->get_number_of_songs() > 0) {
		this->added_playlists.at(playlist_index - 1)->show_songs();

		while (true) {
			std::cout << "choose the song that you want to remove from this playlist: ";
			std::cin >> song_index;
			std::cin.ignore();

			if ((song_index >= 1) && (song_index <= this->added_playlists.at(playlist_index - 1)->get_number_of_songs())) {
				break;
			}
			else {
				std::cout << "invalid input!, try again" << std::endl;
			}
		}
		this->added_playlists.at(playlist_index - 1)->remove_song(song_index - 1);
		std::cout << "song removed from system successfully" << std::endl;
	}
	else {
		this->added_playlists.at(playlist_index - 1)->show_songs();
	}
}
void Admin::add_singer_page(DataBase& database) {
	std::string singer_name;
	int number_of_albums, number_of_released_songs;

	std::cout << "please enter singer name: ";
	std::getline(std::cin, singer_name);
	std::cout << "please enter number of albums: ";
	std::cin >> number_of_albums;
	std::cin.ignore();
	std::cout << "please enter number of released songs: ";
	std::cin >> number_of_released_songs;
	std::cin.ignore();

	std::shared_ptr<Singer> new_singer = std::make_shared<Singer>(singer_name, number_of_albums, number_of_released_songs);

	database.add_singer(new_singer);
	this->added_singers.push_back(new_singer);

	std::cout << "singer page created successfully" << std::endl;
}
void Admin::add_playlist_for_singer(DataBase& database) {
	int singer_index, playlist_index;

	if (this->added_singers.size() == 0) {
		std::cout << "you have not added any singers yet" << std::endl;
		return;
	}
	this->show_added_singers();

	while (true) {
		std::cout << "please choose the singer that you want to add playlist for: ";
		std::cin >> singer_index;
		std::cin.ignore();

		if ((singer_index >= 1) && (singer_index <= this->added_singers.size())) {
			break;
		}
		else {
			std::cout << "invalid input!, try again" << std::endl;
		}
	}
	if (database.get_number_of_all_playlists() > 0) {
		database.show_all_playlists();

		while (true) {
			std::cout << "please choose the playlist that you want to add for this singer: ";
			std::cin >> playlist_index;
			std::cin.ignore();

			if ((playlist_index >= 1) && (playlist_index <= database.get_number_of_all_playlists())) {
				break;
			}
			else {
				std::cout << "invalid input!, try again" << std::endl;
			}
		}

		this->added_singers.at(singer_index - 1)->add_play_list(database.playlist_at(playlist_index - 1));
		std::cout << "play list added for singer successfully" << std::endl;
	}
	else {
		database.show_all_playlists();
	}
}
void Admin::add_music_for_singer(DataBase& database) {
	int singer_index, song_index;

	if (this->added_singers.size() == 0) {
		std::cout << "you have not added any singers yet" << std::endl;
		return;
	}
	this->show_added_singers();

	while (true) {
		std::cout << "please choose the singer that you want to add song for: ";
		std::cin >> singer_index;
		std::cin.ignore();

		if ((singer_index >= 1) && (singer_index <= this->added_singers.size())) {
			break;
		}
		else {
			std::cout << "invalid input!, try again" << std::endl;
		}
	}

	if (database.get_number_of_all_songs() > 0) {
		database.show_all_songs();

		while (true) {
			std::cout << "please choose the song that you want to add for this singer: ";
			std::cin >> song_index;
			std::cin.ignore();

			if ((song_index >= 1) && (song_index <= database.get_number_of_all_songs())) {
				break;
			}
			else {
				std::cout << "invalid input!, try again" << std::endl;
			}
		}

		this->added_singers.at(singer_index - 1)->add_song(database.song_at(song_index - 1));
		std::cout << "song added for singer successfully" << std::endl;
	}
	else {
		database.show_all_songs();
	}
}

void Admin::remove_playlist_for_singer() {
	int singer_index, playlist_index;

	if (this->added_singers.size() == 0) {
		std::cout << "you have not added any singers yet" << std::endl;
		return;
	}
	this->show_added_singers();

	while (true) {
		std::cout << "please choose the singer that you want to remove playlist for: ";
		std::cin >> singer_index;
		std::cin.ignore();

		if ((singer_index >= 1) && (singer_index <= this->added_singers.size())) {
			break;
		}
		else {
			std::cout << "invalid input!, try again" << std::endl;
		}
	}

	if (this->added_singers.at(singer_index - 1)->get_number_of_playlists() > 0) {
		this->added_singers.at(singer_index - 1)->show_singer_playlists();

		while (true) {
			std::cout << "please choose the playlist that you want to remove: ";
			std::cin >> playlist_index;
			std::cin.ignore();

			if ((playlist_index >= 1) && (playlist_index <= this->added_singers.at(singer_index - 1)->get_number_of_playlists())) {
				break;
			}
			else {
				std::cout << "invalid input!, try again" << std::endl;
			}
		}

		this->added_singers.at(singer_index - 1)->remove_play_list(playlist_index - 1);
		std::cout << "playlist removed for singer successfully" << std::endl;
	}
	else {
		this->added_singers.at(singer_index - 1)->show_singer_playlists();
	}
}
void Admin::remove_song_for_singer() {
	int singer_index, song_index;

	if (this->added_singers.size() == 0) {
		std::cout << "you have not added any singers yet" << std::endl;
		return;
	}
	this->show_added_singers();

	while (true) {
		std::cout << "please choose the singer that you want to remove song for: ";
		std::cin >> singer_index;
		std::cin.ignore();

		if ((singer_index >= 1) && (singer_index <= this->added_singers.size())) {
			break;
		}
		else {
			std::cout << "invalid input!, try again" << std::endl;
		}
	}

	if (this->added_singers.at(singer_index - 1)->get_size_of_song_list() > 0) {
		this->added_singers.at(singer_index - 1)->show_singer_song_list();

		while (true) {
			std::cout << "please choose the song that you want to remove: ";
			std::cin >> song_index;
			std::cin.ignore();

			if ((song_index >= 1) && (song_index <= this->added_singers.at(singer_index - 1)->get_size_of_song_list())) {
				break;
			}
			else {
				std::cout << "invalid input!, try again" << std::endl;
			}
		}

		this->added_singers.at(singer_index - 1)->remove_song(song_index - 1);
		std::cout << "song removed for singer successfully" << std::endl;
	}
	else {
		this->added_singers.at(singer_index - 1)->show_singer_song_list();
	}
}
void Admin::edit_singer_info() {
	int singer_index;
	std::string singer_name;
	int number_of_albums, number_of_released_songs;

	if (this->added_singers.size() == 0) {
		std::cout << "you have not added any singers yet" << std::endl;
		return;
	}

	this->show_added_singers();

	while (true) {
		std::cout << "please choose the singer: ";
		std::cin >> singer_index;
		std::cin.ignore();

		if ((singer_index >= 1) && (singer_index <= this->added_singers.size())) {
			break;
		}
		else {
			std::cout << "invalid input!, try again" << std::endl;
		}
	}

	std::cout << "please enter singer name (if you don't want to change it just press enter): ";
	std::getline(std::cin, singer_name);
	std::cout << "please enter number of albums (if you don't want to change it enter 0): ";
	std::cin >> number_of_albums;
	std::cin.ignore();
	std::cout << "please enter number of released songs (if you don't want to change it enter 0): ";
	std::cin >> number_of_released_songs;
	std::cin.ignore();

	if (!singer_name.empty()) {
		this->added_singers.at(singer_index - 1)->set_singer_name(singer_name);
	}
	if (number_of_albums != 0) {
		this->added_singers.at(singer_index - 1)->set_number_of_albums(number_of_albums);
	}
	if (number_of_released_songs != 0) {
		this->added_singers.at(singer_index - 1)->set_number_of_released_songs(number_of_released_songs);
	}

	std::cout << "singer infos edited successfully" << std::endl;

}

void Admin::remove_song_from_system(DataBase& database) {

	int song_index;
	if (this->added_songs.size() == 0) {
		std::cout << "you have not added any songs to system" << std::endl;
		return;
	}

	this->show_added_songs();

	while (true) {
		std::cout << "please choose the song that you want to remove from system: ";
		std::cin >> song_index;
		std::cin.ignore();

		if ((song_index >= 1) && (song_index <= this->added_songs.size())) {
			break;
		}
		else {
			std::cout << "invalid input!, try again" << std::endl;
		}
	}

	database.remove_song(this->added_songs.at(song_index - 1));
	this->added_songs.erase(this->added_songs.begin() + song_index - 1);

	std::cout << "song removed from system successfully" << std::endl;

}
void Admin::remove_playlist_from_system(DataBase& database) {
	int playlist_index;
	if (this->added_playlists.size() == 0) {
		std::cout << "you have not added any playlists to system" << std::endl;
		return;
	}
	this->show_added_playlists();

	while (true) {
		std::cout << "please choose the playlist that you want to remove from system: ";
		std::cin >> playlist_index;
		std::cin.ignore();

		if ((playlist_index >= 1) && (playlist_index <= this->added_playlists.size())) {
			break;
		}
		else {
			std::cout << "invalid input!, try again" << std::endl;
		}
	}

	database.remove_playlist(this->added_playlists.at(playlist_index - 1));
	this->added_playlists.erase(this->added_playlists.begin() + playlist_index - 1);
	std::cout << "playlist removed from system successfully" << std::endl;
	// user class shoud be written
}

void Admin::remove_singer_page(DataBase& database) {
	int singer_index;
	if (this->added_singers.size() == 0) {
		std::cout << "you have not added any singers" << std::endl;
		return;
	}

	this->show_added_singers();

	while (true) {
		std::cout << "please choose the singer that you want to remove: ";
		std::cin >> singer_index;
		std::cin.ignore();

		if ((singer_index >= 1) && (singer_index <= this->added_singers.size())) {
			break;
		}
		else {
			std::cout << "invalid input!, try again" << std::endl;
		}
	}

	database.remove_singer(this->added_singers.at(singer_index - 1));
	this->added_singers.erase(this->added_singers.begin() + singer_index - 1);
	std::cout << "singer page removed from system successfully" << std::endl;
}

void Admin::show_added_songs()const {
	if (this->added_songs.size() == 0) {
		std::cout << "you have not added any songs yet" << std::endl;
		return;
	}
	for (size_t i = 0; i < this->added_songs.size(); i++) {
		std::cout << i + 1 << ") ";
		this->added_songs.at(i)->show_song_info();
	}
}
void Admin::show_added_playlists()const {

	if (this->added_playlists.size() == 0) {
		std::cout << "you have not added any playlists yet" << std::endl;
		return;
	}
	for (size_t i = 0; i < this->added_playlists.size(); i++) {
		std::cout << i + 1 << ") ";
		this->added_playlists.at(i)->show_play_list_info();
	}
}
void Admin::show_added_singers()const {
	if (this->added_singers.size() == 0) {
		std::cout << "you have not added any singers yet" << std::endl;
		return;
	}
	for (size_t i = 0; i < this->added_singers.size(); i++) {
		std::cout << i + 1 << ") ";
		this->added_singers.at(i)->show_artist_info();
	}
}
int Admin::get_number_of_added_songs()const {
	return this->added_songs.size();
}
int Admin::get_number_of_added_playlists()const {
	return this->added_playlists.size();
}
int Admin::get_number_of_added_singers()const {
	return this->added_singers.size();
}