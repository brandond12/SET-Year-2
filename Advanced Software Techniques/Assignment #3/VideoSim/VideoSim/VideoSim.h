/*
* FILE : VideoSim.h
* PROJECT : PROG1165 - VideoSim
* PROGRAMMER : Brandon Davies
* FIRST VERSION : 2014-02-27
* DESCRIPTION : This File contains the class deffinition for VideoSim
*/

#define MAX_ROWS 24
#define MAX_COLS 40

class VideoSim{
private:
	char video[MAX_ROWS][MAX_COLS];
	int currentRow;
	int currentColumn;
public:
	void DisplayVideoMemory(void);
	void clearScreen(void);
	void setCursorPosition(int x, int y);
	void outputString(char *s);
	void scrollScreen(void);
	VideoSim(void);
};