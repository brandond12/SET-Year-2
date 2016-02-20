int main (void)
{
	VideoSim v;
	ClearScreen();				// test API #1
	OutputString ("top left corner");
	DisplayVideoMemory();
	SetCursorPosition (10, 5);	// test API #2
	OutputString ("here's some text in the middle of the screen");	// test API #3
	DisplayVideoMemory();
	SetCursorPosition (35, 9);  // test API #2
	OutputString ("here's text that will scroll the screen!");		// test API #3
	DisplayVideoMemory();
	return 0;
}
