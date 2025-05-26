#include "RegularUser.h"
#include"DataBase.h"

RegularUser::RegularUser(std::string user_name, std::string password)
	:BaseUser(user_name, password), music_player()
{
}
RegularUser::~RegularUser() {

}

void RegularUser::show_list_of_favourite_songs()const {
	int command, release_year;
	std::string filter;
	if (this->favourite_songs.size() == 0) {
		std::cout << "you don't have any favourite songs" << std::endl;
		return;
	}
	/*************************************************************************************/
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
		for (size_t i = 0; i < this->favourite_songs.size(); i++) {
			std::cout << i + 1 << ") ";
			this->favourite_songs.at(i)->show_song_info();
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

			for (size_t i = 0; i < this->favourite_songs.size(); i++) {
				if (this->favourite_songs.at(i)->get_singer_name() == filter) {
					std::cout << i + 1 << ") ";
					this->favourite_songs.at(i)->show_song_info();
				}
			}
		}
		else if (command == 2) {
			std::cout << "enter release year: ";
			std::cin >> release_year;
			std::cin.ignore();

			for (size_t i = 0; i < this->favourite_songs.size(); i++) {
				if (this->favourite_songs.at(i)->get_release_year() == release_year) {
					std::cout << i + 1 << ") ";
					this->favourite_songs.at(i)->show_song_info();
				}
			}
		}
		else if (command == 3) {
			std::cout << "enter genre: ";
			std::getline(std::cin, filter);

			for (size_t i = 0; i < this->favourite_songs.size(); i++) {
				if (this->favourite_songs.at(i)->get_genre() == filter) {
					std::cout << i + 1 << ") ";
					this->favourite_songs.at(i)->show_song_info();
				}
			}
		}
	}
	/*************************************************************************************/

}
void RegularUser::show_list_of_saved_songs()const {
	int command, release_year;
	std::string filter;

	if (this->saved_songs.size() == 0) {
		std::cout << "you don't have any saved songs" << std::endl;
		return;
	}
	/************************************************************************************/
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
		for (size_t i = 0; i < this->saved_songs.size(); i++) {
			std::cout << i + 1 << ") ";
			this->saved_songs.at(i)->show_song_info();
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

			for (size_t i = 0; i < this->saved_songs.size(); i++) {
				if (this->saved_songs.at(i)->get_singer_name() == filter) {
					std::cout << i + 1 << ") ";
					this->saved_songs.at(i)->show_song_info();
				}
			}
		}
		else if (command == 2) {
			std::cout << "enter release year: ";
			std::cin >> release_year;
			std::cin.ignore();

			for (size_t i = 0; i < this->saved_songs.size(); i++) {
				if (this->saved_songs.at(i)->get_release_year() == release_year) {
					std::cout << i + 1 << ") ";
					this->saved_songs.at(i)->show_song_info();
				}
			}
		}
		else if (command == 3) {
			std::cout << "enter genre: ";
			std::getline(std::cin, filter);

			for (size_t i = 0; i < this->saved_songs.size(); i++) {
				if (this->saved_songs.at(i)->get_genre() == filter) {
					std::cout << i + 1 << ") ";
					this->saved_songs.at(i)->show_song_info();
				}
			}
		}
	}
	/************************************************************************************/

}
void RegularUser::show_list_of_favourite_playlists()const {
	if (this->favourite_playlists.size() == 0) {
		std::cout << "you don't have any favourite playlists" << std::endl;
		return;
	}
	for (size_t i = 0; i < this->favourite_playlists.size(); i++) {
		std::cout << i + 1 << ") ";
		this->favourite_playlists.at(i)->show_play_list_info();
	}
}
void RegularUser::show_list_of_saved_playlists()const {
	if (this->saved_playlists.size() == 0) {
		std::cout << "you don't have any saved playlists" << std::endl;
		return;
	}
	for (size_t i = 0; i < this->saved_playlists.size(); i++) {
		std::cout << i + 1 << ") ";
		this->saved_playlists.at(i)->show_play_list_info();
	}
}
void RegularUser::show_created_playlists()const {
	if (this->created_playlists.size() == 0) {
		std::cout << "you have not created any playlists yet" << std::endl;
		return;
	}

	for (size_t i = 0; i < this->created_playlists.size(); i++) {
		std::cout << i + 1 << ") ";
		this->created_playlists.at(i)->show_play_list_info();
	}
}

void RegularUser::play_song() {
	int command;
	std::cout << "1. play favourite songs" << std::endl;
	std::cout << "2. play saved songs" << std::endl;

	while (true) {
		std::cout << "choose command: ";
		std::cin >> command;
		std::cin.ignore();

		if ((command == 1) || (command == 2)) {
			break;
		}
		else {
			std::cout << "invalid input!, try again" << std::endl;
		}
	}

	if (command == 1) {
		if (this->favourite_songs.size() == 0) {
			std::cout << "you don't have any favourite songs" << std::endl;
			return;
		}
		this->music_player.generate_play_order(this->favourite_songs);
	}
	else if (command == 2) {
		if (this->saved_songs.size() == 0) {
			std::cout << "you don't have any saved songs" << std::endl;
			return;
		}
		this->music_player.generate_play_order(this->saved_songs);
	}
}

void RegularUser::search_for_song(DataBase& database) {
	int command;
	std::string song_name;
	std::cout << "please enter song name: ";
	std::getline(std::cin, song_name);

	std::shared_ptr<Song> found_song = database.find_song(song_name);

	if (found_song) {

		while (true) {
			std::cout << "do you want to play it(1) or add it to favourites(2) or save it(3)?: ";
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
			this->music_player.play_single_song(found_song);
		}
		else if (command == 2) {
			this->add_favourite_song(found_song);
		}
		else if (command == 3) {
			this->add_saved_song(found_song);
		}

	}
	else {
		std::cout << "song not found" << std::endl;
	}
}
void RegularUser::search_for_playlist(DataBase& database) {
	int command;
	std::string playlist_name;
	std::cout << "please enter playlist name: ";
	std::getline(std::cin, playlist_name);

	std::shared_ptr<PlayList> found_playlist = database.find_playlist(playlist_name);

	if (found_playlist) {
		while (true) {
			std::cout << "do you want to play it(1) or add it to favourites(2) or save it(3)?: ";
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
			this->music_player.generate_play_order(found_playlist);
		}
		else if (command == 2) {
			this->add_favourite_playlist(found_playlist);
		}
		else if (command == 3) {
			this->add_saved_playlist(found_playlist);
		}
	}
	else {
		std::cout << "playlist not found" << std::endl;
	}
}

void RegularUser::search_for_singer(DataBase& database) {
	std::string singer_name;
	std::cout << "please enter singer name: ";
	std::getline(std::cin, singer_name);

	database.find_singer(singer_name);
}

void RegularUser::create_playlist(DataBase& database) {
	int command;
	std::string playlist_name;
	std::cout << "please enter playlist name: ";
	std::getline(std::cin, playlist_name);

	std::shared_ptr<PlayList> new_playlist = std::make_shared<PlayList>(playlist_name);
	this->created_playlists.push_back(new_playlist);
	database.add_playlist(new_playlist);
	std::cout << "playlist created successfully" << std::endl;

	while (true) {
		std::cout << "do you want to save it(1) or add it to favourites(2)? (otherwise enter 0): ";
		std::cin >> command;
		std::cin.ignore();

		if ((command >= 0) && (command <= 2)) {
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
		this->add_saved_playlist(new_playlist);
	}
	else if (command == 2) {
		this->add_favourite_playlist(new_playlist);
	}
}
void RegularUser::add_song_to_playlist(DataBase& database) {
	int playlist_index, song_index;

	if (this->get_number_of_created_playlists() > 0) {
		this->show_created_playlists();

		while (true) {
			std::cout << "please choose the playlist that you want to add song to: ";
			std::cin >> playlist_index;
			std::cin.ignore();

			if ((playlist_index >= 1) && (playlist_index <= this->get_number_of_created_playlists())) {
				break;
			}
			else {
				std::cout << "invalid input!, try again" << std::endl;
			}

		}

		if (database.get_number_of_all_songs() > 0) {
			database.show_all_songs();

			while (true) {
				std::cout << "please choose the song that you want to add to playlist: ";
				std::cin >> song_index;
				std::cin.ignore();

				if ((song_index >= 1) && (song_index <= database.get_number_of_all_songs())) {
					break;
				}
				else {
					std::cout << "invalid input!, try again" << std::endl;
				}
			}

			this->created_playlists.at(playlist_index - 1)->add_song(database.song_at(song_index - 1));
			std::cout << "song added to playlist successfully" << std::endl;
		}
		else {
			database.show_all_songs();
		}
	}
	else {
		this->show_created_playlists();
	}

}
void RegularUser::remove_song_from_playlist() {

	int playlist_index, song_index;
	if (this->created_playlists.size() == 0) {
		std::cout << "you have not created any playlist" << std::endl;
		return;
	}
	this->show_created_playlists();

	while (true) {
		std::cout << "please choose the playlist that you want to remove song from: ";
		std::cin >> playlist_index;
		std::cin.ignore();

		if ((playlist_index >= 1) && (playlist_index <= this->created_playlists.size())) {
			break;
		}
		else {
			std::cout << "invalid input!, try again" << std::endl;
		}
	}

	if (this->created_playlists.at(playlist_index - 1)->get_number_of_songs() > 0) {
		this->created_playlists.at(playlist_index - 1)->show_songs();

		while (true) {
			std::cout << "choose the song that you want to remove: ";
			std::cin >> song_index;
			std::cin.ignore();

			if ((song_index >= 1) && (song_index <= this->created_playlists.at(playlist_index - 1)->get_number_of_songs())) {
				break;
			}
			else {
				std::cout << "invalid input!, try again" << std::endl;
			}
		}

		this->created_playlists.at(playlist_index - 1)->remove_song(song_index - 1);
		std::cout << "song remove successfull" << std::endl;
	}
	else {
		this->created_playlists.at(playlist_index - 1)->show_songs();
	}
}
void RegularUser::remove_playlist(DataBase& database) {
	int playlist_index;

	if (this->created_playlists.size() > 0) {
		this->show_created_playlists();

		while (true) {
			std::cout << "please choose the playlist that you want to remove: ";
			std::cin >> playlist_index;
			std::cin.ignore();

			if ((playlist_index >= 1) && (playlist_index <= this->created_playlists.size())) {
				break;
			}
			else {
				std::cout << "invalid input!, try again" << std::endl;
			}
		}

		database.remove_playlist(this->created_playlists.at(playlist_index - 1));
		std::cout << "playlist removed successfully" << std::endl;
	}
	else {
		this->show_created_playlists();
	}
}
void RegularUser::remove_playlist(std::shared_ptr<PlayList> playlist) {
	for (size_t i = 0; i < this->favourite_playlists.size(); i++) {
		if ((this->favourite_playlists.at(i)->get_playlist_name() == playlist->get_playlist_name()) && (this->favourite_playlists.at(i)->get_number_of_songs() == playlist->get_number_of_songs())) {
			this->favourite_playlists.erase(this->favourite_playlists.begin() + i);
			break;
		}
	}
	for (size_t i = 0; i < this->saved_playlists.size(); i++) {
		if ((this->saved_playlists.at(i)->get_playlist_name() == playlist->get_playlist_name()) && (this->saved_playlists.at(i)->get_number_of_songs() == playlist->get_number_of_songs())) {
			this->saved_playlists.erase(this->saved_playlists.begin() + i);
			break;
		}
	}

	for (size_t i = 0; i < this->created_playlists.size(); i++) {
		if ((this->created_playlists.at(i)->get_playlist_name() == playlist->get_playlist_name()) && (this->created_playlists.at(i)->get_number_of_songs() == playlist->get_number_of_songs())) {
			this->created_playlists.erase(this->created_playlists.begin() + i);
			break;
		}
	}
}

void RegularUser::add_saved_song(std::shared_ptr<Song> song) {
	this->saved_songs.push_back(song);
}
void RegularUser::remove_saved_song() {
	int song_index;
	if (this->saved_songs.size() == 0) {
		std::cout << "you have not saved any song" << std::endl;
		return;
	}

	this->show_list_of_saved_songs();
	while (true) {
		std::cout << "please choose the song that you want to remove: ";
		std::cin >> song_index;
		std::cin.ignore();

		if ((song_index >= 1) && (song_index <= this->saved_songs.size())) {
			break;
		}
		else {
			std::cout << "invalid input!, try again" << std::endl;
		}
	}

	this->saved_songs.erase(this->saved_songs.begin() + song_index - 1);
	std::cout << "song removed successfully" << std::endl;
}

void RegularUser::add_favourite_song(std::shared_ptr<Song> song) {
	this->favourite_songs.push_back(song);
}
void RegularUser::remove_favourite_song() {
	int song_index;

	if (this->favourite_songs.size() == 0) {
		std::cout << "you don't have any favourite song" << std::endl;
		return;
	}

	this->show_list_of_favourite_songs();
	while (true) {
		std::cout << "please choose the song that you want to remove: ";
		std::cin >> song_index;
		std::cin.ignore();

		if ((song_index >= 1) && (song_index <= this->favourite_songs.size())) {
			break;
		}
		else {
			std::cout << "invalid input!, try again" << std::endl;
		}
	}

	this->favourite_songs.erase(this->favourite_songs.begin() + song_index - 1);
	std::cout << "song removed successfully" << std::endl;
}

void RegularUser::add_favourite_playlist(std::shared_ptr<PlayList> playlist) {
	this->favourite_playlists.push_back(playlist);
}
void RegularUser::remove_favourite_playlist() {
	int playlist_index;
	if (this->favourite_playlists.size() == 0) {
		std::cout << "you don't have any favourite playlist" << std::endl;
		return;
	}

	this->show_list_of_favourite_playlists();
	while (true) {
		std::cout << "please choose the playlist that you want to remove: ";
		std::cin >> playlist_index;
		std::cin.ignore();

		if ((playlist_index >= 1) && (playlist_index <= this->favourite_playlists.size())) {
			break;
		}
		else {
			std::cout << "invalid input!, try again" << std::endl;
		}
	}

	this->favourite_playlists.erase(this->favourite_playlists.begin() + playlist_index - 1);
	std::cout << "playlist removed successfully" << std::endl;

}

void RegularUser::add_saved_playlist(std::shared_ptr<PlayList> playlist) {
	this->saved_playlists.push_back(playlist);
}
void RegularUser::remove_saved_plylist() {
	int playlist_index;

	if (this->saved_playlists.size() == 0) {
		std::cout << "you have not saved any playlists" << std::endl;
		return;
	}
	this->show_list_of_saved_playlists();
	while (true) {
		std::cout << "please choose the playlist that you want to remove: ";
		std::cin >> playlist_index;
		std::cin.ignore();

		if ((playlist_index >= 1) && (playlist_index <= this->saved_playlists.size())) {
			break;
		}
		else {
			std::cout << "invalid input!, try again" << std::endl;
		}
	}

	this->saved_playlists.erase(this->saved_playlists.begin() + playlist_index - 1);
	std::cout << "playlist removed successfully" << std::endl;
}

/*void RegularUser::filter_song() {

}*/

int RegularUser::get_number_of_favourite_songs()const {
	return this->favourite_songs.size();
}
int RegularUser::get_number_of_saved_songs()const {
	return this->saved_songs.size();

}

int RegularUser::get_number_of_favourite_playlists()const {
	return this->favourite_playlists.size();
}
int RegularUser::get_number_of_saved_playlists()const {
	return this->saved_playlists.size();
}
int RegularUser::get_number_of_created_playlists()const {
	return this->created_playlists.size();
}