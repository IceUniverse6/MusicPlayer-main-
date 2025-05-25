#include "Song.h"

Song::Song() {
	this->song_name = "null";
	this->singer_name = "null";
	this->release_year = 0;
	this->genre = "unknown";
}
Song::Song(std::string song_name, std::string singer_name, int release_year, std::string genre) {
	this->song_name = song_name;
	this->singer_name = singer_name;
	this->release_year = release_year;
	this->genre = genre;
}
Song::~Song() {

}
void Song::set_song_name(std::string song_name) {
	this->song_name = song_name;
}
void Song::set_singer_name(std::string singer_name) {
	this->singer_name = singer_name;
}
void Song::set_release_year(int release_year) {
	this->release_year = release_year;
}
void Song::set_genre(std::string genre) {
	this->genre = genre;
}

void Song::show_song_info()const {
	line
		std::cout << "song name: " << this->song_name << std::endl;
	std::cout << "singer: " << this->singer_name << std::endl;
	std::cout << "release year: " << this->release_year << std::endl;
	std::cout << "genre: " << this->genre << std::endl;
	line
}
std::string Song::get_song_name()const {
	return this->song_name;
}
std::string Song::get_singer_name()const {
	return this->singer_name;
}
int Song::get_release_year()const {
	return this->release_year;
}
std::string Song::get_genre()const {
	return this->genre;
}