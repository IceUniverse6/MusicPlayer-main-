#pragma once
#include<iostream>
#include<vector>
#include<memory>
#include<string>
#include"BaseUser.h"
#include"DataBase.h"

class DataBase;
class Admin :public BaseUser
{
private:
	std::vector<std::shared_ptr<Song>> added_songs;
	std::vector<std::shared_ptr<PlayList>> added_playlists;
	std::vector<std::shared_ptr<Singer>> added_singers;
public:
	Admin(std::string, std::string);
	~Admin();

	void add_song(DataBase&);//*
	void add_playlist(DataBase&);//*
	void add_song_to_playlist(DataBase&);//*
	void remove_song_from_playlist();//*
	void add_singer_page(DataBase&);//*
	void add_playlist_for_singer(DataBase&);//*
	void add_music_for_singer(DataBase&);//*

	void remove_playlist_for_singer();//*
	void remove_song_for_singer();//*
	void edit_singer_info();
	void remove_singer_page(DataBase&);//*

	void remove_song_from_system(DataBase&);//*
	void remove_playlist_from_system(DataBase&);//*

	void show_added_songs()const;
	void show_added_playlists()const;
	void show_added_singers()const;

	int get_number_of_added_songs()const;
	int get_number_of_added_playlists()const;
	int get_number_of_added_singers()const;
};

