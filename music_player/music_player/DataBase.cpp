#include "DataBase.h"
#include"Admin.h"

DataBase::DataBase() {

}
DataBase::~DataBase() {

}

void DataBase::add_admin(std::shared_ptr<Admin> admin) {
	this->all_admins.push_back(admin);
}
void DataBase::add_user(std::shared_ptr<RegularUser> user) {
	this->all_users.push_back(user);
}
void DataBase::add_song(std::shared_ptr<Song> song) {
	this->all_songs.push_back(song);
}
void DataBase::add_playlist(std::shared_ptr<PlayList> playlist) {
	this->all_playlists.push_back(playlist);
}
void DataBase::add_singer(std::shared_ptr<Singer> singer) {
	this->all_singers.push_back(singer);
}

void DataBase::remove_song(std::shared_ptr<Song> song) {
	for (size_t i = 0; i < this->all_playlists.size(); i++) {
		this->all_playlists.at(i)->remove_song(song);
	}
	for (size_t i = 0; i < this->all_songs.size(); i++) {
		if ((this->all_songs.at(i)->get_song_name() == song->get_song_name()) && (this->all_songs.at(i)->get_singer_name() == song->get_singer_name())) {
			this->all_songs.erase(this->all_songs.begin() + i);
			break;
		}
	}
}
void DataBase::remove_playlist(std::shared_ptr<PlayList> playlist) {

	for (size_t i = 0; i < this->all_users.size(); i++) {
		this->all_users.at(i)->remove_playlist(playlist);
	}
	for (size_t i = 0; i < this->all_singers.size(); i++) {
		this->all_singers.at(i)->remove_play_list(playlist);
	}

	for (size_t i = 0; i < this->all_playlists.size(); i++) {
		if ((this->all_playlists.at(i)->get_playlist_name() == playlist->get_playlist_name()) && (this->all_playlists.at(i)->get_number_of_songs() == playlist->get_number_of_songs())) {
			this->all_playlists.erase(this->all_playlists.begin() + i);
			break;
		}
	}
}
void DataBase::remove_singer(std::shared_ptr<Singer> singer) {
	for (size_t i = 0; i < this->all_singers.size(); i++) {
		if ((this->all_singers.at(i)->get_singer_name() == singer->get_singer_name()) && (this->all_singers.at(i)->get_number_of_released_songs() == singer->get_number_of_released_songs())) {
			this->all_singers.erase(this->all_singers.begin() + i);
			break;
		}
	}
}

int DataBase::get_number_of_all_users()const {
	return this->all_users.size();
}
int DataBase::get_number_of_all_songs()const {
	return this->all_songs.size();
}
int DataBase::get_number_of_all_playlists()const {
	return this->all_playlists.size();
}
int DataBase::get_number_of_all_singers()const {
	return this->all_singers.size();
}

std::shared_ptr<Admin> DataBase::find_admin(std::string user_name, std::string password) {

	for (size_t i = 0; i < this->all_admins.size(); i++) {
		if ((this->all_admins.at(i)->get_user_name() == user_name) && (this->all_admins.at(i)->get_password() == password)) {
			return this->all_admins.at(i);
		}
	}
	return nullptr;
}
std::shared_ptr<RegularUser> DataBase::find_user(std::string user_name, std::string password) {

	for (size_t i = 0; i < this->all_users.size(); i++) {
		if ((this->all_users.at(i)->get_user_name() == user_name) && (this->all_users.at(i)->get_password() == password)) {
			return this->all_users.at(i);
		}
	}
	return nullptr;
}

std::shared_ptr<Song> DataBase::find_song(std::string song_name) {
	int song_index;
	bool found = false;

	if (this->all_songs.size() == 0) {
		std::cout << "database is empty" << std::endl;
		return nullptr;
	}
	for (size_t i = 0; i < this->all_songs.size(); i++) {
		if (this->all_songs.at(i)->get_song_name() == song_name) {
			found = true;
			std::cout << i + 1 << ") ";
			this->all_songs.at(i)->show_song_info();
		}
	}
	if (found) {
		std::cout << "if you want to play any of them, or save them, enter song code, else enter 0: ";
		std::cin >> song_index;
		std::cin.ignore();

		if (song_index == 0) {
			return nullptr;
		}
		else {
			return this->all_songs.at(song_index - 1);
		}
	}
	return nullptr;


}
std::shared_ptr<PlayList> DataBase::find_playlist(std::string playlist_name) {
	int playlist_index;
	bool found;

	if (this->all_playlists.size() == 0) {
		std::cout << "database is empty" << std::endl;
		return nullptr;
	}

	for (size_t i = 0; i < this->all_playlists.size(); i++) {
		if (this->all_playlists.at(i)->get_playlist_name() == playlist_name) {
			found = true;
			std::cout << i + 1 << ") ";
			this->all_playlists.at(i)->show_play_list_info();
		}
	}
	if (found) {
		std::cout << "if you want to play any of them, or save them, enter playlist code, else enter 0: ";
		std::cin >> playlist_index;
		std::cin.ignore();

		if (playlist_index == 0) {
			return nullptr;
		}
		else {
			return this->all_playlists.at(playlist_index - 1);
		}
	}

	return nullptr;
}
void DataBase::find_singer(std::string singer_name) {
	bool found = false;
	int singer_index;
	if (this->all_singers.size() == 0) {
		std::cout << "database is empty" << std::endl;
		return;
	}

	for (size_t i = 0; i < this->all_singers.size(); i++) {
		if (this->all_singers.at(i)->get_singer_name() == singer_name) {
			found = true;
			std::cout << i + 1 << ") ";
			this->all_singers.at(i)->show_artist_info();
		}
	}

	if (found) {
		std::cout << "if you want to see singer song list, enter it's code, else enter 0 to exit: ";
		std::cin >> singer_index;
		std::cin.ignore();

		if (singer_index == 0) {
			return;
		}
		else {
			this->all_singers.at(singer_index - 1)->show_singer_song_list();
		}
	}


}

std::shared_ptr<Song> DataBase::song_at(int index)const {
	return this->all_songs.at(index);
}
std::shared_ptr<PlayList> DataBase::playlist_at(int index)const {
	return this->all_playlists.at(index);
}

void DataBase::show_all_songs()const {
	int command, release_year;
	std::string filter;

	if (this->all_songs.size() == 0) {
		std::cout << "database is empty" << std::endl;
		return;
	}

	while (true) {
		std::cout << "do you want to filter songs? (1 for yes and 0 for no): ";
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
		for (size_t i = 0; i < this->all_songs.size(); i++) {
			std::cout << i + 1 << ") ";
			this->all_songs.at(i)->show_song_info();
		}
	}
	else if (command == 1) {
		std::cout << "1. singer" << std::endl;
		std::cout << "2. release year" << std::endl;
		std::cout << "3. genre" << std::endl;

		while (true) {
			std::cout << "filter by: ";
			std::cin >> command;
			std::cin.ignore();

			if ((command >= 1) && (command <= 3)) {
				break;
			}
			else {
				std::cout << "invalid input!, try again" << std::endl;
			}

		}
		if (command == 1) {
			std::cout << "enter singer name: ";
			std::getline(std::cin, filter);

			for (size_t i = 0; i < this->all_songs.size(); i++) {
				if (this->all_songs.at(i)->get_singer_name() == filter) {
					std::cout << i + 1 << ") ";
					this->all_songs.at(i)->show_song_info();
				}
			}
		}
		else if (command == 2) {
			std::cout << "enter release year: ";
			std::cin >> release_year;
			std::cin.ignore();

			for (size_t i = 0; i < this->all_songs.size(); i++) {
				if (this->all_songs.at(i)->get_release_year() == release_year) {
					std::cout << i + 1 << ") ";
					this->all_songs.at(i)->show_song_info();
				}
			}
		}
		else if (command == 3) {
			std::cout << "enter genre: ";
			std::getline(std::cin, filter);

			for (size_t i = 0; i < this->all_songs.size(); i++) {
				if (this->all_songs.at(i)->get_genre() == filter) {
					std::cout << i + 1 << ") ";
					this->all_songs.at(i)->show_song_info();
				}
			}
		}
	}
}
void DataBase::show_all_playlists()const {
	if (this->all_playlists.size() == 0) {
		std::cout << "database is empty" << std::endl;
		return;
	}
	for (size_t i = 0; i < this->all_playlists.size(); i++) {
		std::cout << i + 1 << ") ";
		this->all_playlists.at(i)->show_play_list_info();
	}
}
void DataBase::show_all_singers()const {
	if (this->all_singers.size() == 0) {
		std::cout << "database is empty" << std::endl;
		return;
	}
	for (size_t i = 0; i < this->all_singers.size(); i++) {
		std::cout << i + 1 << ") ";
		this->all_singers.at(i)->show_artist_info();
	}
}