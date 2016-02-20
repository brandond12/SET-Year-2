// Filename: vectorObjects.cpp
// Author: Carlo Sgro
// Date: March 3/15
// Description: This program works with a vector of ints to demonstrate how elements are put into the vector.

#include <iostream>
#include <vector>
#include <string>
using namespace std;



void displayVectorDetails(vector<string> myVector, char *intro);



int main(void)
{
	vector<string> myVector(3, "Fred");
	vector<string>::iterator iter;

	// display the contents and addresses of the elements
	displayVectorDetails(myVector, "Startup:");

	// change values of the vector elements
	myVector.at(1) = string("Barney");
	myVector.at(2) = string("Wilma");
	displayVectorDetails(myVector, "After changing two values using at():");

	// declare a string object
	string newName("Betty");
	cout << "newName variable is located at address " << &newName << endl << endl;

	// insert that string into the vector, overwriting Wilma
	myVector.at(2) = newName;
	displayVectorDetails(myVector, "After replacing Wilma with Betty:");

	// we're inserting two elements with value 15 before the 20 we just inserted
	newName.assign("Pebbles");
	myVector.at(1) = newName;
	displayVectorDetails(myVector, "After replacing Betty with Pebbles in the string variable and using that variable to replace Barney:");

	// let's use push_back to insert at the end
	myVector.push_back(newName);
	displayVectorDetails(myVector, "After using push_back(newName)");

	// display one last time
	displayVectorDetails(myVector, "At end:");

	return 0;
}




// Function: displayVectorDetails()
// Description: Displays the contents and addresses of all elements in a vector of ints
// Parameters:  vector<string> myVector: the vector to display
//				char *intro: a string to display before all output (so we know why we're displaying it
// Returns: nothing

void displayVectorDetails(vector<string> myVector, char *intro)
{
	cout << intro << endl << "The vector contains:" << endl;

	for (vector<string>::iterator iter = myVector.begin(); iter != myVector.end(); ++iter)
	{
		// display the value and the address (addressof from http://stackoverflow.com/questions/12179460/address-of-the-pointed-element-whatever-the-iterator-type-pointer-is-passed)
		cout << *iter << " at address " << std::addressof(*iter) << endl;
	}
	cout << endl;
}