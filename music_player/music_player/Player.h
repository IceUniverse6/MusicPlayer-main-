#pragma once
#include<iostream>
#include<vector>
#include<memory>
#include"PlayList.h"
class Player
{
private:
	std::vector<std::shared_ptr<Song>> songs;
	bool loop;
	bool shuffle;
public:
	Player();
	~Player();

	void generate_play_order(std::shared_ptr<PlayList>);
	void generate_play_order(std::vector<std::shared_ptr<Song>>);
	void play_single_song(const std::shared_ptr<Song>);
	void play_playlist();

	void shuffle_list();
	void reverse();
};

