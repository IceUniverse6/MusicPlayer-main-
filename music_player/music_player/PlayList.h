#pragma once
#include<iostream>
#include<vector>
#include<memory>
#include<string>
#include"Song.h"
#define line std::cout << "------------------------------" << std::endl;
class PlayList
{
private:
	std::string playlist_name;
	std::vector<std::shared_ptr<Song>> song_list;
public:
	PlayList();
	PlayList(std::string);
	~PlayList();

	void set_playlist_name(std::string);
	void add_song(std::shared_ptr<Song>);
	void remove_song(int);
	void remove_song(std::shared_ptr<Song>);

	std::string get_playlist_name()const;
	int get_number_of_songs()const;
	std::vector<std::shared_ptr<Song>> get_all_songs()const;

	void show_songs()const;
	void show_play_list_info()const;
};



