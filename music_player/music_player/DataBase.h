#pragma once
#include<iostream>
#include<vector>
#include<memory>
#include<string>
#include"RegularUser.h"
#include"Singer.h"

class Admin;

class DataBase
{
private:
	std::vector<std::shared_ptr<Admin>> all_admins;
	std::vector<std::shared_ptr<RegularUser>> all_users;
	std::vector<std::shared_ptr<Song>> all_songs;
	std::vector<std::shared_ptr<PlayList>> all_playlists;
	std::vector<std::shared_ptr<Singer>> all_singers;
public:
	DataBase();
	~DataBase();

	void add_admin(std::shared_ptr<Admin>);
	void add_user(std::shared_ptr<RegularUser>);
	void add_song(std::shared_ptr<Song>);
	void add_playlist(std::shared_ptr<PlayList>);
	void add_singer(std::shared_ptr<Singer>);

	void remove_song(std::shared_ptr<Song>);
	void remove_playlist(std::shared_ptr<PlayList>);
	void remove_singer(std::shared_ptr<Singer>);

	int get_number_of_all_users()const;
	int get_number_of_all_songs()const;
	int get_number_of_all_playlists()const;
	int get_number_of_all_singers()const;

	std::shared_ptr<Admin> find_admin(std::string, std::string);
	std::shared_ptr<RegularUser> find_user(std::string, std::string);

	std::shared_ptr<Song> find_song(std::string);
	std::shared_ptr<PlayList> find_playlist(std::string);
	void find_singer(std::string);

	std::shared_ptr<Song> song_at(int)const;
	std::shared_ptr<PlayList> playlist_at(int)const;

	void show_all_songs()const;
	void show_all_playlists()const;
	void show_all_singers()const;
};

