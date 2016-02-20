/*
* FILE : mini3.cpp
* PROJECT : PROG1370 - mini3
* PROGRAMMER : Brandon Davies
* FIRST VERSION : 2014-03-10
* DESCRIPTION : This program will take user input until user inputs only a period.
* The user input is stored in a vector of strings
* The user can then seach for a name and exit by entering only a period
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void){
	vector<string> userWord;
	string Word = "";

	//Enter to vector
	while (true){
		cout<<"Please enter input for list: ";
		cin >> Word;
		if (Word == "."){//if input if '.' move to search code
			break;
		}
		userWord.push_back(Word);//add word to list
	}

	//Get search value
	while (true){
		vector<string>::iterator iter = userWord.begin();//initilize interator to start of vector
		cout << "Please enter input to search list: ";
		cin >> Word;
		if (Word == "."){//if input if '.' exit program
			break;
		}

		while (iter != userWord.end() && Word != *iter){//increment inter until matches search or end of vector
			iter++;
		}
		if (iter != userWord.end() && Word == *iter){//display if search word is in vector
			cout<<"Success!\n";
		}
		else{
			cout<<"Not There!\n";
		}
	}
	return 0;
}
