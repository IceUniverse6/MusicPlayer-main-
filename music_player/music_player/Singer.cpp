#include "Singer.h"

Singer::Singer() {
	this->singer_name = "null";
	this->number_of_albums = 0;
	this->number_of_released_songs = 0;
}
Singer::Singer(std::string singer_name, int number_of_albums, int number_of_released_songs) {
	this->singer_name = singer_name;
	this->number_of_albums = number_of_albums;
	this->number_of_released_songs = number_of_released_songs;
}
Singer::~Singer() {

}

void Singer::set_singer_name(std::string singer_name) {
	this->singer_name.clear();
	this->singer_name = singer_name;
}
void Singer::set_number_of_albums(int number_of_albums) {
	this->number_of_albums = number_of_albums;
}
void Singer::set_number_of_released_songs(int number_of_released_songs) {
	this->number_of_released_songs = number_of_released_songs;
}

void Singer::add_song(std::shared_ptr<Song> song) {
	this->song_list.push_back(song);
}
void Singer::remove_song(int index) {
	this->song_list.erase(this->song_list.begin() + index);
}

void Singer::add_play_list(std::shared_ptr<PlayList> playlist) {
	this->artist_playlists.push_back(playlist);
}
void Singer::remove_play_list(int index) {
	this->artist_playlists.erase(this->artist_playlists.begin() + index);
}
void Singer::remove_play_list(std::shared_ptr<PlayList> playlist) {
	for (size_t i = 0; i < this->artist_playlists.size(); i++) {
		if ((this->artist_playlists.at(i)->get_playlist_name() == playlist->get_playlist_name()) && (this->artist_playlists.at(i)->get_number_of_songs() == playlist->get_number_of_songs())) {
			this->artist_playlists.erase(this->artist_playlists.begin() + i);
			break;
		}
	}
}

std::string Singer::get_singer_name()const {
	return this->singer_name;
}
int Singer::get_number_of_albums()const {
	return this->number_of_albums;
}
int Singer::get_number_of_released_songs()const {
	return this->number_of_released_songs;
}
std::vector<std::shared_ptr<Song>> Singer::get_all_songs()const {
	return this->song_list;
}
std::vector<std::shared_ptr<PlayList>> Singer::get_all_playlists()const {
	return this->artist_playlists;
}

int Singer::get_size_of_song_list()const {
	return this->song_list.size();
}
int Singer::get_number_of_playlists()const {
	return this->artist_playlists.size();
}

void Singer::show_artist_info()const {
	line
		std::cout << "singer name: " << this->singer_name << std::endl;
	std::cout << "number of albums: " << this->number_of_albums << std::endl;
	std::cout << "number of released songs: " << this->number_of_released_songs << std::endl;
	line
}

void Singer::show_singer_song_list()const {

	if (this->song_list.size() == 0) {
		std::cout << "no songs found" << std::endl;
		return;
	}
	for (size_t i = 0; i < this->song_list.size(); i++) {
		std::cout << i + 1 << ") ";
		this->song_list.at(i)->show_song_info();
	}
}
void Singer::show_singer_playlists()const {
	if (this->artist_playlists.size() == 0) {
		std::cout << "no playlists found" << std::endl;
		return;
	}
	for (size_t i = 0; i < this->artist_playlists.size(); i++) {
		std::cout << i + 1 << ") ";
		this->artist_playlists.at(i)->show_play_list_info();
	}
}