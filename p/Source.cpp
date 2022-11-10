#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <chrono>
#include "Header.h"
#include <conio.h>
using namespace std;
//Function to draw line
void drawLine(char ch) {
	for (int i = 1; i < 120; i++)
		cout << ch;
	cout << endl;
}

int main() {
	int x = 0;
	system("COLOR 5F");
	drawLine('+');
	cout << "\t\t\t\t\tW E L C O M E   T O   L I B R A R Y \n";
	drawLine('+');
	system("pause");

label1://Labelled 1 to return control
	system("CLS");
	system("COLOR 8E");
	cout << "Enter 1 for admin Login: " << endl;
	cout << "Enter 2 for User Login: " << endl;
	cout << "Enter -1 to exit: " << endl;
	cin >> x;
	//Loop to keep program running
	while (x != -1) {
		if (x == 1) {
			system("COLOR 8F");
			//x = 0;
			admin obj;
			if (obj.AdminLogin() != 0) {//Validate Input
				cout << "Invalid Credentials!" << endl;
				return 1;
				break;
			}
			else {
				//Label 2 for control to return	
			label2:
				int a = -1;
				system("CLS");
				cout << "Enter 1 to add users" << endl;
				cout << "Enter 2 to add Books" << endl;
				cout << "Enter 3 to view Book List" << endl;
				cout << "Enter 4 to show users that have a Library membership" << endl;
				cout << "Enter 5 to view borrow record" << endl;
				cout << "Enter 0 to go back: ";
				while (a != 0) {

					cin >> a;
					if (a == 0) {
						goto label1;
					}
					if (a == 1) {

						obj.AddUser();
						cout << "User added successfully" << endl;
						system("pause");
						goto label2;

					}
					else if (a == 2) {
						obj.Addbooks();
						cout << "Book Added Successfully!" << endl;
						system("pause");
						goto label2;

					}
					else if (a == 3) {
						cout << "Showing books available: " << endl;
						obj.ViewBooks();
						system("pause");
						goto label2;

					}
					else if (a == 4) {
						cout << "Showing lst of registered users: " << endl;
						obj.ViewUsers();
						system("pause");
						goto label2;

					}
					else if (a == 5) {
						obj.BorrowRec();
						system("pause");
						goto label2;
					}

				}
			}
		}
		if (x == 2) {
			system("CLS");
			system("COLOR 0A");
			user obj2;
			int x = -1;
			if (obj2.Validate() == 1) {
				cout << "Invalid Crdentials!" << endl;
				return 4;
				break;
			}
			else {
			label3:
				system("CLS");
				cout << "Enter 1 to view books available: " << endl;
				cout << "Enter 2 to borrow a book: " << endl;
				cout << "Enter 0 to go back: ";
				cin >> x;
				if (x == 0) {
					goto label1;
				}
				if (x == 1) {
					cout << "Showing books available: " << endl;
					obj2.ViewBooks();
					system("pause");
					goto label3;

				}
				else if (x == 2) {
					obj2.Borrow(obj2);
					system("pause");
					goto label3;

				}
			}

		}
	}

}
