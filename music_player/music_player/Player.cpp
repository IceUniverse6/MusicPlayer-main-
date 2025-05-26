#include "Player.h"

Player::Player() {
	this->loop = false;
	this->shuffle = false;
}
Player::~Player() {

}

void Player::generate_play_order(std::shared_ptr<PlayList> playlist) {
	int order;
	this->songs = playlist->get_all_songs();

	std::cout << "please choose play order" << std::endl;
	std::cout << "1. default" << std::endl;
	std::cout << "2. reverse" << std::endl;
	std::cout << "3. shuffle" << std::endl;
	while (true) {
		std::cout << "order: ";
		std::cin >> order;
		std::cin.ignore();

		if ((order >= 1) && (order <= 3)) {
			break;
		}
		else {
			std::cout << "invalid input!, try again" << std::endl;
		}
	}


	if (order == 2) {
		this->reverse();
	}
	else if (order == 3) {
		this->shuffle = true;
		this->shuffle_list();
	}

	this->play_playlist();
}
void Player::generate_play_order(std::vector<std::shared_ptr<Song>> playlist) {
	int order;
	this->songs = playlist;

	std::cout << "please choose play order" << std::endl;
	std::cout << "1. default" << std::endl;
	std::cout << "2. reverse" << std::endl;
	std::cout << "3. shuffle" << std::endl;
	while (true) {
		std::cout << "order: ";
		std::cin >> order;
		std::cin.ignore();

		if ((order >= 1) && (order <= 3)) {
			break;
		}
		else {
			std::cout << "invalid input!, try again" << std::endl;
		}
	}


	if (order == 2) {
		this->reverse();
	}
	else if (order == 3) {
		this->shuffle = true;
		this->shuffle_list();
	}
	this->play_playlist();
}
void Player::play_single_song(const std::shared_ptr<Song> song) {
	int command;

	for (size_t i = 0; i < 1; i++) {
		std::cout << song->get_song_name() << " (" << song->get_singer_name() << ") " << std::endl;

		std::cout << "1. pause song" << std::endl;
		std::cout << "2. repeat track" << std::endl;
		std::cout << "3. show song info" << std::endl;
		std::cout << "4. exit" << std::endl;

		while (true) {
			std::cout << "choose command: ";
			std::cin >> command;
			std::cin.ignore();

			if ((command >= 1) && (command <= 4)) {
				break;
			}
			else {
				std::cout << "invalid command!, try again" << std::endl;
			}
		}

		if (command == 1) {
			while (true) {
				std::cout << "paused, enter 1 to continue, enter 0 to exit: ";
				std::cin >> command;
				std::cin.ignore();

				if ((command == 0) || (command == 1)) {
					break;
				}
				else {
					std::cout << "invalid command!, try again" << std::endl;
				}
			}

			if (command == 0) {
				return;
			}
			else if (command == 1) {
				i--;
				continue;
			}
		}
		else if (command == 2) {
			i--;
			continue;
		}
		else if (command == 3) {
			song->show_song_info();
			i--;
		}
		else if (command == 4) {
			return;
		}
	}

}
void Player::play_playlist() {
	int command;
	for (size_t i = 0; i < this->songs.size(); i++) {
		if ((i == this->songs.size() - 1) && (this->loop)) {
			if (this->shuffle) {
				this->shuffle_list();
			}
			i = -1;
			continue;
		}
		std::cout << this->songs.at(i)->get_song_name() << " (" << this->songs.at(i)->get_singer_name() << ") " << std::endl;

		std::cout << "1. pause song" << std::endl;
		std::cout << "2. play next" << std::endl;
		std::cout << "3. play previous" << std::endl;
		std::cout << "4. repeat track" << std::endl;
		std::cout << "5. enable loop" << std::endl;
		std::cout << "6. disable loop" << std::endl;
		std::cout << "7. show song info" << std::endl;
		std::cout << "8. exit player" << std::endl;

		while (true) {
			std::cout << "choose command: ";
			std::cin >> command;
			std::cin.ignore();

			if ((command >= 1) && (command <= 8)) {
				break;
			}
			else {
				std::cout << "invalid command!, try again" << std::endl;
			}
		}

		if (command == 1) {
			while (true) {
				std::cout << "paused, enter 1 to continue, enter 0 to exit: ";
				std::cin >> command;
				std::cin.ignore();

				if ((command == 0) || (command == 1)) {
					break;
				}
				else {
					std::cout << "invalid command!, try again" << std::endl;
				}
			}

			if (command == 0) {
				this->songs.clear();
				this->loop = false;
				this->shuffle = false;
				return;
			}
			else if (command == 1) {
				i--;
				continue;
			}
		}
		else if (command == 2) {
			continue;
		}
		else if (command == 3) {
			if (i >= 1) {
				i -= 2;
				continue;
			}
		}
		else if (command == 4) {
			i--;
			continue;
		}
		else if (command == 5) {
			this->loop = true;
		}
		else if (command == 6) {
			this->loop = false;
		}
		else if (command == 7) {
			this->songs.at(i)->show_song_info();
		}
		else if (command == 8) {
			this->songs.clear();
			this->loop = false;
			this->shuffle = false;
			return;
		}
	}
}

void Player::shuffle_list() {
	std::srand(std::time(0));

	for (size_t i = this->songs.size() - 1; i > 0; i--) {
		size_t j = rand() % (i + 1);

		std::swap(this->songs.at(i), this->songs.at(j));
	}
}
void Player::reverse() {
	std::reverse(this->songs.begin(), this->songs.end());
}