#pragma once
#include <string>

using namespace std;

class admin {
private:
	string Name = "Hasan";
	string Password = "Idk1";
public:
	int AdminLogin();
	void ViewUsers();
	void AddUser();
	void Addbooks();
	void ViewBooks();
	void BorrowRec();
	

};

class user : public admin {
private:
	string Username = "\0";
	string Password = "\0";
public:
	int Validate();
	void Borrow(user obj);
};