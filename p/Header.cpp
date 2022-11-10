#include <iostream>
#include <fstream>
#include <string>
#include "Header.h"

using namespace std;

ifstream in;
ofstream out;

string UserNameM;//Declared to keep record of name of the user signed in

int user::Validate()
{
	
	in.open("UserDetails.txt");
	string c, n;
	int numcount = 0,alphacount=0;
	string pass, name;
	cout << "Enter UserName; ";
	cin >> name;
	cout << "Enter Password; ";
	cin >> pass;
	while (!in.eof()) {
		
			getline(in, n);
			
			if (name == n) {
				UserNameM = n;
				getline(in, c);
				for (int i = 0; i < c.size(); i++) {//Checking whether the data taken from file is in correct format i.e:
					if (isdigit(c[i])) {			//															7 Alphabets + 1 digit
						numcount = numcount + 1;	//
					}									//
					if (isalpha(c[i])) {				//
						alphacount = alphacount + 1;	//	
					}
														//		 						
				}											///
				if ((numcount == 0) && (alphacount<=6)) {	// If specified format is not met the user is refused entry by:
					c = "Invalid";						//				assigining c "Invalid" and terminating as both strings pass 
				}									//														and c donot match
													//																||
				if (pass == c) {						//															||
					cout << "Access Granted" << endl;	//															||
					in.close();							//															||		
					return 0;							//															||
					break;								//															||
				}										//															||
														//															||
			}											//															||
														//															||
														//															||		
	}													//															||
	in.close();											//												    	    ||
	return 1;											//										<<<<<<<<<<<<<<<<<<<<_|
}

void user::Borrow(user obj)
{
	time_t result = time(NULL);
	char str[26];
	ctime_s(str, sizeof str, &result);
	int No,i=0;
	string output;
	cout << "Books available: " << endl;
	obj.ViewBooks();
	cout << "Enter Book Number to Borrrow it: ";
	cin >> No;
	out.open("Record.txt", ios::app);
	in.open("Books.txt");
	while (i != No) {
		getline(in, output);
		i++;
	}
	out << output << endl;
	out << "Borrowed by: " <<endl;
	out << UserNameM << endl;
	out << "On: " << endl;
	out << str << endl;
	cout << "Borrowed!" << endl;
	in.close();
	out.close();
}

int admin::AdminLogin()
{
	string Inp;
	string pass;
	cout << "Enter Admin Name: ";
	cin >> Inp;
	cout << "Enter Password: ";
	cin >> pass;
	if ((Inp == Name) && (pass == Password)) {
		return 0;
	}
	else {
		return 1;
	}
	
}

void admin::ViewUsers()
{
	in.open("UserDetails.txt");
	string n;
	int c=1;//C is declared to print user count i.e 1.UserA , 2.UserB......
	while (!in.eof()) {

		getline(in, n);
		cout << c << "-" << n << endl;
			
		c++;
		in.ignore(numeric_limits<streamsize>::max(), '\n');
		

	}
	in.close();
}

void admin::AddUser()
{
	out.open("UserDetails.txt", ios::app);
	string Name, Pass;
	cout << "Enter UserName: ";
	cin >> Name;
	out << Name <<endl;
	cout << "Enter Password for New User(Should include atleast '7' alphabets and '1' number): ";
	cin >> Pass;
	out << Pass << endl;
	out.close();

}

void admin::Addbooks()
{
	string bn, Aun; // bn = Book Name, Aun = Author Name
	out.open("Books.txt", ios::app);
	cout << "Enter Book Name: ";
	cin >> bn;
	out << bn;
	cout << "Enter Author Name: ";
	cin >> Aun;
	out << " by " << Aun;
	out << endl;
	out.close();

}

void admin::ViewBooks()
{
	string bk;//String to Store Book Details and View them
	int i = 1;//Counter to print Book Number
	in.open("Books.txt");
	cout << "* Book Name * by * Author Name * " << endl;
	while (!in.eof()) {
		getline(in, bk);
		cout << i << "-" << bk << endl;
		i++;
	}
	in.close();
}

void admin::BorrowRec()
{
	string disp;
	in.open("Record.txt");
	while (!in.eof()) {
		getline(in,disp);
		cout << disp << endl;
	}
	in.close();
}
