#pragma once
#include<iostream>
#include<string>
#define line std::cout << "------------------------------" << std::endl;
class Song
{
private:
	std::string song_name;
	std::string singer_name;
	int release_year;
	std::string genre;
public:
	Song();
	Song(std::string, std::string, int, std::string);
	~Song();
	void set_song_name(std::string);
	void set_singer_name(std::string);
	void set_release_year(int);
	void set_genre(std::string);

	void show_song_info()const;
	std::string get_song_name()const;
	std::string get_singer_name()const;
	int get_release_year()const;
	std::string get_genre()const;
};


