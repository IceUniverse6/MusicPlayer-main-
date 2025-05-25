#include "BaseUser.h"

BaseUser::BaseUser() {
	this->user_name = "unknown";
	this->password = "null";
}
BaseUser::BaseUser(std::string user_name, std::string password) {
	this->user_name = user_name;
	this->password = password;
}
BaseUser::~BaseUser() {

}
void BaseUser::set_user_name(std::string user_name) {
	this->user_name.clear();
	this->user_name = user_name;
}
void BaseUser::set_password(std::string password) {
	this->password.clear();
	this->password = password;
}
std::string BaseUser::get_user_name()const {
	return this->user_name;
}
std::string BaseUser::get_password()const {
	return this->password;
}

void BaseUser::change_user_name_and_password() {
	int command;
	std::string current_password;
	std::string new_user_name, new_password;

	while (true) {

		std::cout << "enter your current password: ";
		std::getline(std::cin, current_password);

		if (this->password == current_password) {
			break;
		}
		else {
			std::cout << "wrong password! try again" << std::endl;

			while (true) {
				std::cout << "enter 1 to continue, enter 0 to exit: ";
				std::cin >> command;
				std::cin.ignore();

				if ((command == 0) || (command == 1)) {
					break;
				}
				else {
					std::cout << "invalic command!, try again" << std::endl;
				}

			}
			if (command == 0) {
				return;
			}
			else if (command == 1) {
				continue;
			}
		}
	}

	std::cout << "enter your new user name (if you don't want to change it, leave it empty by just clicking enter): ";
	std::getline(std::cin, new_user_name);

	std::cout << "enter your new password (if you don't want to change it, leave it empty by just clicking enter): ";
	std::getline(std::cin, new_password);

	if (!new_user_name.empty()) {
		this->set_user_name(new_user_name);
	}
	if (!new_password.empty()) {
		this->set_password(new_password);
	}
}