// Smart University ID Registration System 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<fstream>
#include<cstdlib>  //for rand() & srand()
#include<ctime>   // for time()
using namespace std;


int main() {
	string fullname, firstname, lastname;
	string password, confirmedpassword;
	int age;
	float GPA;

	cout << "===== Cougar University Registration Terminal =====" << endl;

	//Name 
	cout << "Please enter your first name: " << endl;
	cin >> firstname;
	cout << "Please enter your last name: " << endl;
	cin >> lastname;
	fullname = firstname + "  " + lastname;

	//Age
	cout << "What is your age ?" << endl;
	cin >> age;
	if (age < 17) {
		cout << fullname << ", You are not eligible to register (age must be 17 or older)." << endl;
		return 0;
	}

	//GPA
	cout << "Enter your GPA(0.0 to 4.0) : " << endl;
	cin >> GPA;
	if (GPA < 0.0 || GPA>4.0) {
		cout << "Invalid GPA. It must be between 0.0 and 4.0." << endl;
		return 0;
	}

	//Password
	cout << "Creat your Password:" << endl;
	cin >> password;

	for (int i = 0; i < 3; i++) {
		cout << "Confirm your password:" << endl;
		cin >> confirmedpassword;

		if (confirmedpassword == password) {
			cout << fullname << ", Password confirmed successfully!" << endl;
			break; // This allows the code to stop after confirming this requirment 
		}
		else if (i == 2) {
			cout << "Registration failed: Too many incorrect attempts." << endl;
			return 0;
		}
		else {
			cout << "Passwords do not match. Try again later" << endl;
		}
	}

	//ID Generation 
	srand(time(0)); // seed for random number generation
	string universityAbbrev;
	cout << "Enter your university abbreviation (e.g., MIT, UH, NYU):" << endl;
	cin >> universityAbbrev;

	int randomnumber = rand() % 9000 + 1000; // Genrate a 4- digit number (1000-9999)
	string universityID = universityAbbrev + to_string(randomnumber);

	cout << "\n=====  University ID Generated =====" << endl;
	cout << "Student Name: " << fullname << endl;
	cout << "Your University ID is:" << universityID << endl;

	// save to file 
	ofstream file("student_info.txt");
	file << "Name :" << fullname << endl;
	file << "Age: " << age << endl;
	file << "GPA:" << GPA << endl;
	file << "university: " << universityAbbrev << endl;
	file << "university ID :" << universityID << endl;
	file.close();

	cout << "\nYour date has been saved to 'student_info.txt' " << endl;


	return 0;

}


 

