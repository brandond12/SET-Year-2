/*
* FILE : TestHarness.cpp
* PROJECT : PROG1165 - VideoSim
* PROGRAMMER : Brandon Davies
* FIRST VERSION : 2014-02-27
* DESCRIPTION : This File contains the test harness for all VideoSim class methods
*/

#include "VideoSim.h"

int main (void){
	VideoSim screen1;

	//API Test 1
	//Test writing to video memory
	screen1.outputString("test1: Top Left of Screen");		
	screen1.DisplayVideoMemory();

	//API Test 2
	//Test Change Cursor possition with valid input
	screen1.setCursorPosition(11, 8);						
	screen1.outputString("test2: Middle of Screen");
	screen1.DisplayVideoMemory();

	//API Test 3
	//Test Change Cursor possition with valid input
	screen1.setCursorPosition(23, 1);
	screen1.outputString("test3: Bottom of Screen");
	screen1.DisplayVideoMemory();

	//API Test 4
	//Test Change Cursor possition with invalid input, test row boundy 
	screen1.setCursorPosition(24, 10);						
	screen1.outputString("test4: Invalid Location");
	screen1.DisplayVideoMemory();

	//API Test 5
	//Test Change Cursor possition with invalid input, test coloumn boundy 
	screen1.setCursorPosition(2, 40);						
	screen1.outputString("test5: Invalid Location");
	screen1.DisplayVideoMemory();

	//API Test 6
	//Test writing to video memory, make input wrap to next line
	screen1.setCursorPosition(12, 23);						
	screen1.outputString("test6: Make The Text Drop to the Next Line");
	screen1.DisplayVideoMemory();

	//API Test 7
	//Test writing to video memory, make input scroll
	screen1.setCursorPosition(23, 30);						
	screen1.outputString("test7: A Test That Will Make the Screen Scroll");
	screen1.DisplayVideoMemory();

	//API Test 8
	//Test writing to video memory, make input overwrite old input
	screen1.setCursorPosition(22, 30);						
	screen1.outputString("test8: Test Writing Over Old Data");
	screen1.DisplayVideoMemory();

	//API Test 9
	//Test writing to video memory, make input scroll multiple lines
	screen1.setCursorPosition(22, 30);						
	screen1.outputString("test9: A Test That Will Make The Code Wrap the Output Over Multiple Lines");
	screen1.DisplayVideoMemory();

	//API Test 10
	//Test scroll screen function on its own
	screen1.scrollScreen();									
	screen1.DisplayVideoMemory();

	//API Test 11
	//Test clear screen function
	screen1.clearScreen();									
	screen1.DisplayVideoMemory();

	return 0;
}