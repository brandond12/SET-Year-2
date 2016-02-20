/*
* FILE : VideoSim.cpp
* PROJECT : PROG1165 - VideoSim
* PROGRAMMER : Brandon Davies
* FIRST VERSION : 2014-02-27
* DESCRIPTION : This File contains all code for VideoSim class methods
*/

#include "VideoSim.h"
#include <stdio.h>


/*
*FUNCTION		:	DisplayVideoMemory
*
*DESCRIPTION	:	Method provided by Norbert Mika
*					This method prints the video memory to the screen in a formatted table
*
*PARAMETERS		:	void
*
*RETURNS		:	void
*
*/
void VideoSim::DisplayVideoMemory(void){
	int i = 0, j = 0;

	printf("Video memory holds:\n");

	printf("   ");
	for (i = 0; i < MAX_COLS; i++) {
		if ((i % 10) == 0)
			printf("%d", i / 10);
		else
			printf(" ");
	}	/* end for */
	printf("\n");

	printf("   ");
	for (i = 0; i < MAX_COLS; i++) {
		printf("%d", i % 10);
	}	/* end for */
	printf("\n");

	for (i = 0; i < MAX_ROWS; i++) {
		printf("%02d ", i);
		for (j = 0; j < MAX_COLS; j++) {
			printf("%c", video[i][j]);	
		}
		printf("\n");
	}
	printf("\n\n");
}


/*
*FUNCTION		:	clearScreen
*
*DESCRIPTION	:	This method sets every location in the video memory to ' '
*
*PARAMETERS		:	void
*
*RETURNS		:	void
*
*/
void VideoSim::clearScreen(void){
	int i = 0;
	char *pVideo = &video[0][0];
	for (i = 0; i< (MAX_ROWS * MAX_COLS); i++)
	{
		*(pVideo++) = ' ';
	}
}


/*
*FUNCTION		:	setCursorPosition
*
*DESCRIPTION	:	This method sets the cursor position to the cordinates given if valid
*
*PARAMETERS		:	int x:	The selected row	
*					int y:	The selected coloumn
*
*RETURNS		:	void
*
*/
void VideoSim::setCursorPosition(int x, int y){
	if (x < (MAX_ROWS) && x >= 0 && y < (MAX_COLS) && y >= 0){
		this->currentRow = x;
		this->currentColumn = y;
	}
}


/*
*FUNCTION		:	outputString
*
*DESCRIPTION	:	This method saves the inputed string to the current location in the video memory
*
*PARAMETERS		:	char *s:	The string to be inputed
*
*RETURNS		:	void
*
*/
void VideoSim::outputString(char *s){
	int x = 0;
	int vid_offset = currentRow * MAX_COLS + currentColumn;
	char *pVideo = &video[0][0];
	while (*(s+x) != '\0'){//while not at end of the string
		*(pVideo + vid_offset) = *(s + x);//save the input character to screen location
		vid_offset++;
		if (vid_offset >= (MAX_COLS * MAX_ROWS)){//if input goes off the end of the screen
			vid_offset = ((MAX_ROWS - 1)*MAX_COLS);//set location to begining of last row
			scrollScreen();
		}
		x++;
	}
}


/*
*FUNCTION		:	scrollScreen
*
*DESCRIPTION	:	This method moves all characters up a line on the screen and sets the bottom row to all ' '
*
*PARAMETERS		:	void
*
*RETURNS		:	void
*
*/
void VideoSim::scrollScreen(void){
	char *pVideo = &video[0][0];
	for (int i = 0; i < ((MAX_ROWS-1)*MAX_COLS); i++){//until we hit the last row
		*(pVideo + i) = *(pVideo + i + MAX_COLS);
	}
	for (int i = ((MAX_ROWS-1)*MAX_COLS); i <= ((MAX_ROWS)*MAX_COLS); i++){//replace the last row with ' '
		*(pVideo + i) = ' ';
	}
}


/*
*FUNCTION		:	VideoSim
*
*DESCRIPTION	:	This is the constructor that sets the default location to 0,0 and sets all video locations to ' '
*
*PARAMETERS		:	void
*
*RETURNS		:	void
*
*/
VideoSim::VideoSim(void){
	currentColumn = 0;
	currentRow = 0;
	clearScreen();
}