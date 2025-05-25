#pragma once
#include<iostream>
#include<string>
class BaseUser
{
private:
	std::string user_name;
	std::string password;

public:
	BaseUser();
	BaseUser(std::string, std::string);
	~BaseUser();
	void set_user_name(std::string);
	void set_password(std::string);
	std::string get_user_name()const;
	std::string get_password()const;

	void change_user_name_and_password();
};



