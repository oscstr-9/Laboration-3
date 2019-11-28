#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

void initDatabase(vector<string> *database, string command) {

		cout << "Are you sure? This will empty the database. Press y to confirm." << endl;
		cin >> command;
		cout << endl;
		if (command == "y" || command == "Y") {
			(*database).clear();//empties the database
			cout << "Database has been cleared!" << endl;

		}
	}

void insert(vector<string> *database, string command) {
		cout << "Add some names to the database, press q to stop:" << endl;
		while (true) {
			cin >> command;
			if (command == "q" || command == "Q") {
				break;
			}
			(*database).push_back(command);//adds name et the back of the database
		}
		cout << endl;
	}

void search(const vector<string> *DATABASE, string command) {

		cout << endl << "Enter something to search for:" << endl;
		cin >> command;
		cout << endl;
		for (int i = 0; i < (*DATABASE).size(); i++) {// goes through array looking for entered name
			if ((*DATABASE)[i].find(command) != string::npos) {// checks the whole string of each value in the database
				cout << (*DATABASE)[i] << endl;
			}
		}
		cout << endl;
	}

void deleteName(vector<string> *database, string command) {
		int flag = 1;

		cout << "Enter a name to delete, press q to stop:" << endl;
		while (true) {
			flag = 1;
			cin >> command;
			cout << endl;
			for (int i = 0; i < (*database).size(); i++) { // goes through array checking for the entered name
				if (command == (*database)[i]) {
					(*database).erase((*database).begin() + i); // if name is found, delete it
					cout << "Name removed!" << endl;
					flag = 0;
				}
			}

			if (command == "q" || command == "Q") {
				break;
			}
			else if (flag == 1) {
				cout << "That name was not found." << endl;

			}
		}
	}

void print(const vector<string> *DATABASE) {
		for (auto i : *DATABASE) {
			cout << i << " " << endl;
		}
		cout << endl;
	}

void save(const vector<string> *DATABASE) {
	string fileName;
	ofstream saveFile;
	cout << "Enter a file name to save to:" << endl;
	cin >> fileName;
	saveFile.open(fileName + ".txt");

	for (int i = 0; i < (*DATABASE).size(); i++) {//writes each value of the vector into the chosen file line by line
		saveFile << (*DATABASE)[i] << endl;
	}
	saveFile.close();
}

void load(vector<string> *database) {
	string fileName;
	ifstream loadFile;
	string contents;
	(*database).clear();
	cout << "Enter a file name to load:" << endl;
	cin >> fileName;
	loadFile.open(fileName + ".txt");

	if (loadFile.fail()) {//if file is not found, error is printed
		cout << "File was not found!" << endl;
	}
	else {
		while (loadFile >> contents) {//pushes contents from chosen file into database vector one by one
			(*database).push_back(contents);
		}
	}
	loadFile.close();
}

void main() {
	string command;
	vector	<string> database;
	vector <string> *ptrDatabase = &database;
	int saveFile = 0;

	while (true) {
		//menu printout
		cout << endl << "Enter a command:" << endl << "1. initialise database" << endl << "2. insert" << endl << "3. search" << endl << "4. delete" << endl << "5. print" << endl << "6. save" << endl << "7. load" << endl << "8. quit" << endl << endl;
		cin >> command;
		cout << endl;

		//options
		if (command == "initialise database" || command == "init" || command == "1") {
			initDatabase(ptrDatabase, command);
		}

		if (command == "insert" || command == "2") {
			insert(ptrDatabase, command);
		}

		if (command == "search" || command == "3") {
			search(ptrDatabase, command);
		}

		if (command == "delete" || command == "4") {
			deleteName(ptrDatabase, command);
		}

		if (command == "print" || command == "5") {
			print(ptrDatabase);
		}

		if (command == "save" || command == "6") {
			save(ptrDatabase);
		}

		if (command == "load" || command == "7") {
			load(ptrDatabase);
		}
		if (command == "quit" || command == "8") {
				cout << "Exiting program...";
				return;
		}
	}
}