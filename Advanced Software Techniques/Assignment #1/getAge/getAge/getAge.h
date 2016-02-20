#include <stdio.h> 
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>

int getNum(int *age);
int allDigit(char *pStart, char *pStop);
void LogError(char *error);

#pragma warning(disable: 4996)

#define kErrorLogFilePath "./Output.txt"
#define kTextFile
#define kDebugConsole
#define kProgramConsole
#define kErrorNoInput -1
#define kErrorNotNumber -2
#define kErrorNotRange -3