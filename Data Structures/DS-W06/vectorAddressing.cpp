// Filename: vectorAddressing.cpp
// Author: Carlo Sgro
// Date: March 3/15
// Description: This program works with a vector of ints to demonstrate how elements are stored 
//				and moved around when insertion and deletion happens.

#include <iostream>
#include <vector>
using namespace std;



void displayVectorDetails(vector<int> myVector, char *intro);



int main(void)
{
	vector<int> myVector(3, 100);
	vector<int>::iterator iter;

	// display the contents and addresses of the elements
	displayVectorDetails(myVector, "Startup:");
	
	// change values of the vector elements
	myVector.at(1) = 200;
	myVector.at(2) = 300;
	displayVectorDetails(myVector, "After changing two values using at():");

	// change values of the vector elements again
	myVector[1] = 201;
	myVector[2] = 301;
	displayVectorDetails(myVector, "After changing two values using []:");

	// insert a 20 at the start
	iter = myVector.begin();
	iter = myVector.insert(iter, 20);
	displayVectorDetails(myVector, "After inserting 20 at the start:");

	// we're inserting two elements with value 15 before the 20 we just inserted
	myVector.insert(iter, 2, 15);
	displayVectorDetails(myVector, "After inserting two 15s before the 20:");

	// let's use push_back to insert at the end
	myVector.push_back(400);
	displayVectorDetails(myVector, "After using push_back(400):");

	// let's try to add a far-away item
	try{
		myVector.at(10) = 1000;
		displayVectorDetails(myVector, "After adding element 10 as 1000");
	}
	catch (const out_of_range& oor)	// this is a C++ exception object http://www.cplusplus.com/reference/stdexcept/out_of_range/
	{
		cout << "Error: " << oor.what() << endl << endl;
	}

	// display one last time
	displayVectorDetails(myVector, "At end:");

	return 0;
}




// Function: displayVectorDetails()
// Description: Displays the contents and addresses of all elements in a vector of ints
// Parameters:  vector<int> myVector: the vector to display
//				char *intro: a string to display before all output (so we know why we're displaying it
// Returns: nothing

void displayVectorDetails(vector<int> myVector, char *intro)
{
	cout << intro << endl << "The vector contains:" << endl;

	for (vector<int>::iterator iter = myVector.begin(); iter != myVector.end(); ++iter)
	{
		// display the value and the address (addressof from http://stackoverflow.com/questions/12179460/address-of-the-pointed-element-whatever-the-iterator-type-pointer-is-passed)
		cout << *iter << " is at address " << std::addressof(*iter) << endl;
	}
	cout << endl;
}