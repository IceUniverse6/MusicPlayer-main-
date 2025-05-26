#pragma once
#include<iostream>
#include<vector>
#include<memory>
#include"BaseUser.h"
#include"Player.h"
#include"PlayList.h"

class DataBase;
class RegularUser :public BaseUser
{
private:

	std::vector<std::shared_ptr<PlayList>> created_playlists;

	std::vector<std::shared_ptr<Song>> favourite_songs;
	std::vector<std::shared_ptr<Song>> saved_songs;

	std::vector<std::shared_ptr<PlayList>> favourite_playlists;
	std::vector<std::shared_ptr<PlayList>> saved_playlists;

	Player music_player;

public:
	RegularUser(std::string, std::string);
	~RegularUser();

	void show_list_of_favourite_songs()const;//*
	void show_list_of_saved_songs()const;//*
	void show_list_of_favourite_playlists()const;//*
	void show_list_of_saved_playlists()const;//*
	void show_created_playlists()const;//*

	void play_song();//*

	void search_for_song(DataBase&);//*
	void search_for_playlist(DataBase&);//*
	void search_for_singer(DataBase&);//*

	void create_playlist(DataBase&);//*
	void add_song_to_playlist(DataBase&);//*
	void remove_song_from_playlist();//*
	void remove_playlist(DataBase&);//*
	void remove_playlist(std::shared_ptr<PlayList>);

	void add_saved_song(std::shared_ptr<Song>);//*
	void remove_saved_song();//*

	void add_favourite_song(std::shared_ptr<Song>);//*
	void remove_favourite_song();//*

	void add_favourite_playlist(std::shared_ptr<PlayList>);//*
	void remove_favourite_playlist();//*

	void add_saved_playlist(std::shared_ptr<PlayList>);//*
	void remove_saved_plylist();//*

	void filter_song();//*

	int get_number_of_favourite_songs()const;
	int get_number_of_saved_songs()const;

	int get_number_of_favourite_playlists()const;
	int get_number_of_saved_playlists()const;

	int get_number_of_created_playlists()const;
};

