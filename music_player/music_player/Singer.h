#pragma once
#include<iostream>
#include<vector>
#include<memory>
#include<string>
#include"Song.h"
#include"PlayList.h"
#define line std::cout << "------------------------------" << std::endl;
class Singer
{
private:
	std::string singer_name;
	int number_of_albums;
	int number_of_released_songs;
	std::vector<std::shared_ptr<Song>> song_list;
	std::vector<std::shared_ptr<PlayList>> artist_playlists;
public:
	Singer();
	Singer(std::string, int, int);
	~Singer();

	void set_singer_name(std::string);
	void set_number_of_albums(int);
	void set_number_of_released_songs(int);

	void add_song(std::shared_ptr<Song>);
	void remove_song(int);

	void add_play_list(std::shared_ptr<PlayList>);
	void remove_play_list(int);
	void remove_play_list(std::shared_ptr<PlayList>);

	std::string get_singer_name()const;
	int get_number_of_albums()const;
	int get_number_of_released_songs()const;
	std::vector<std::shared_ptr<Song>> get_all_songs()const;
	std::vector<std::shared_ptr<PlayList>> get_all_playlists()const;
	int get_size_of_song_list()const;
	int get_number_of_playlists()const;

	void show_artist_info()const;

	void show_singer_song_list()const;
	void show_singer_playlists()const;
};

