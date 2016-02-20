/*
* FILE : mini2.cpp
* PROJECT : PROG1370 - mini2
* PROGRAMMER : Brandon Davies
* FIRST VERSION : 2014-02-03
* DESCRIPTION : This program will take user input until user inputs only a period. 
* The user input is stored in a sorted link list in a bucket determined by a hash. 
* The user can then seach for a name amd exit by entering only a perion
*/


#include "LinkList.h"


int main(void){
	unsigned long bucketSelector = 0;
	char buffer[kmaxUserInputLen + 1] = "";
	WordNodes *newBlock = NULL;
	WordNodes *Buckets[knumBuckets] = { NULL };

	//entering data to sorted link list buckets
	printf("Enter Data:\n");
	while (true){
		fgets(buffer, kmaxUserInputLen, stdin);//get user input
		if (buffer[0] == '.' && buffer[1] == '\n'){//if user enters '.' break
			break;
		}
		if (strlen(buffer) <= 20){//if word is not longer than max length
			newBlock = (WordNodes *)malloc(sizeof(WordNodes));//allocate memory for new node
			strcpy(newBlock->words, buffer);
			newBlock->next = NULL;

			bucketSelector = hash(buffer);//get hash value between 0 and 10

			Buckets[bucketSelector] = addRecord(Buckets[bucketSelector], newBlock);//add node to sorted link list in hash bucket
		}
	}

	//searching for data in sorted link list bucjets
	printf("Search data:\n");
	while (true){
		fgets(buffer, kmaxUserInputLen, stdin);//get user input
		if (buffer[0] == '.' && buffer[1] == '\n'){//if user enters '.' break
			break;
		}
		if (strlen(buffer) <= 20){//if word is not longer than max length
			bucketSelector = hash(buffer);//get hash value between 0 and 10

			searchLinkList(Buckets[bucketSelector], buffer);//search link list for user input
		}
	}

	//free memory
	freeMemory(Buckets);
	return 0;
}


