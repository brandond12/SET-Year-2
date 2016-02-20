void VideoSim::DisplayVideoMemory (void)
{
int i = 0, j = 0;

	printf ("Video memory holds:\n");

	printf ("   ");
	for (i = 0; i < MAX_COLS; i++) {	// constant that needs definition
		if ((i % 10) == 0)
			printf ("%d", i / 10);
		else
			printf (" ");
	}	/* end for */
	printf ("\n");

	printf ("   ");
	for (i = 0; i < MAX_COLS; i++) {
		printf ("%d", i % 10);
	}	/* end for */
	printf ("\n");

	for (i = 0; i < MAX_ROWS; i++) {	// constant that needs definition
		printf ("%02d ", i);
		for (j = 0; j < MAX_COLS; j++) {
			printf ("%c", video[i][j]);	// private data member
		}
		printf ("\n");
	}
	printf ("\n\n");
}
