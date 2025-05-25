#include "PlayList.h"

PlayList::PlayList() {
	this->playlist_name = "null";
}
PlayList::PlayList(std::string playlist_name) {
	this->playlist_name = playlist_name;
}
PlayList::~PlayList() {

}

void PlayList::set_playlist_name(std::string playlist_name) {
	this->playlist_name.clear();
	this->playlist_name = playlist_name;
}
void PlayList::add_song(std::shared_ptr<Song> song) {
	this->song_list.push_back(song);
}
void PlayList::remove_song(int index) {
	this->song_list.erase(this->song_list.begin() + index);
}

void PlayList::remove_song(std::shared_ptr<Song> song) {
	for (size_t i = 0; i < this->song_list.size(); i++) {
		if ((this->song_list.at(i)->get_song_name() == song->get_song_name()) && (this->song_list.at(i)->get_singer_name() == song->get_singer_name())) {
			this->song_list.erase(this->song_list.begin() + i);
			break;
		}
	}
}

std::string PlayList::get_playlist_name()const {
	return this->playlist_name;
}
int PlayList::get_number_of_songs()const {
	return this->song_list.size();
}
std::vector<std::shared_ptr<Song>> PlayList::get_all_songs()const {
	return this->song_list;
}

void PlayList::show_songs()const {
	if (this->song_list.size() == 0) {
		std::cout << "playlist is empty" << std::endl;
		return;
	}
	for (size_t i = 0; i < this->song_list.size(); i++) {
		std::cout << i + 1 << ") ";
		this->song_list.at(i)->show_song_info();
	}
}
void PlayList::show_play_list_info()const {
	line
		std::cout << "playlist name: " << this->playlist_name << std::endl;
	std::cout << "number of songs: " << this->song_list.size() << std::endl;
	line
}