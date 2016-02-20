/* 
 * Filename: sortedSinglyLL.c 
 * Author:   Carlo Sgro
 * Date:     January 29/06
 * Description: This implements an example of a sorted singly-linked list.  
 *              Functionality provided is: enter item, delete item, list all items, 
 *              delete all items.
 */

#include <stdio.h>
#include <malloc.h>
#include <conio.h>
#include <string.h>

#pragma warning(disable: 4996)


/*
 * define linked list structure
 */

typedef struct phoneInfo {
	char name[50];
	char address[50];
	char phoneNumber[10];
	struct phoneInfo *next;
} phoneInfo;




// prototypes
phoneInfo *enterNewInfo (phoneInfo *newHead);
void listInfo (phoneInfo *head);
phoneInfo *deleteAllInfo (phoneInfo *head);
phoneInfo *deleteOne (phoneInfo *head);
void clearCRLF(char *str);



// functions


int main (void)
{
phoneInfo *head = NULL;
char key = 0;
#define kEnter     '1'
#define kList      '2'
#define kDeleteAll '3'
#define kDeleteOne '4'
#define kQuit      '5'
#define kLoopForever   1


	// loop getting user input until they indicate that they want to quit
	while (kLoopForever) 
	{
		/*
		 * display menu and get input
		 */

		printf ("\n\nMenu\n\n");
		printf ("%c . . . Enter new info\n", kEnter);
		printf ("%c . . . List all info\n", kList);
		printf ("%c . . . Delete all info\n", kDeleteAll);
		printf ("%c . . . Delete one item\n", kDeleteOne);
		printf ("%c . . . Quit\n", kQuit);
		printf ("Enter your choice . . .");

		key = getch();
		// quit on entry of kQuit ('5')
		if (key == kQuit)
		{
			break;
		}

		switch (key) 
		{
		case kEnter:
			head = enterNewInfo(head);
			break;

		case kList:
			listInfo(head);
			break;

		case kDeleteAll:
			head = deleteAllInfo(head);
			break;

		case kDeleteOne:
			head = deleteOne(head);
			break;
		default:
			printf ("\nInvalid choice\n");
			break;
		}	/* end switch */
	}	/* end while */

	// clean up memory allocated
	if( head != NULL )
	{
		deleteAllInfo(head);
	}
	return 0;
}	/* end main */



/*
 * Function: phoneInfo * enterNewInfo (phoneInfo *newHead)
 *
 * Description:	This function will allocate a new entry in the
 *				linked list, allow data entry, and append this
 *				entry to the end of the chain.
 *
 * Parameter: phoneInfo *newHead: start of the linked list
 * Return Value: new value of the head parameter pointing to the start of the linked list
 */

phoneInfo *enterNewInfo (phoneInfo *newHead)
{
	phoneInfo *newBlock = NULL;
	phoneInfo *ptr = NULL;
	phoneInfo *prev = NULL;

	// allocate a block of memory for new record
	newBlock = (phoneInfo *)malloc (sizeof (phoneInfo));
	if (newBlock == NULL) 
	{
		printf ("Error! No more memory\n");
		return newHead;
	}	/* endif */

	// obtain information for new record, getting rid of '\n' at end of string, if present
	printf("\nEnter name: ");
	fgets(newBlock->name, sizeof (newBlock->name), stdin);
	clearCRLF(newBlock->name);
	printf("Enter address: ");
	fgets(newBlock->address, sizeof (newBlock->address), stdin);
	clearCRLF(newBlock->address);
	printf("Enter phone number (xxx-xxxx): ");
	fgets(newBlock->phoneNumber, sizeof (newBlock->phoneNumber), stdin);
	clearCRLF(newBlock->phoneNumber);
	newBlock->next = NULL;

	// now link this record to the list in the appropriate place
	if (newHead == NULL) 
	{
		// empty list, so set head
		newHead = newBlock;
	} 
	else if(strcmp(newHead->name, newBlock->name) >= 0) // special case
	{
		// we're inserting at the front of the list
		
		// set the next pointer for the newBlock record to be the
		// location that used to be at the front of the list
		newBlock->next = newHead;
		// set first_number to point to the new start of the list
		newHead = newBlock;
	}
	else
	{
		/*
		 * non-empty list where we're not inserting at the front
		 * of the list, so use ptr to follow links until we reach the 
		 * right place, according to the sorting order
		 */

		prev = newHead;		// first item in list
		ptr = newHead->next;	// second item in list 
		
		while (ptr != NULL) 
		{
			if (strcmp(ptr->name, newBlock->name) >= 0)
			{
				// we've found a name in the list that is either equal to or greater 
				// than the one we're entering now
				break;
			}
			prev = ptr;
			ptr = ptr->next;
		}	/* end while */

		// add the new node here, between prev and ptr
		newBlock->next = ptr;
		prev->next = newBlock;

	}	/* endif */

	return newHead;

}	/* end enterNewInfo */





/*
 * Function: void listInfo (phoneInfo *head)
 *
 * Description:	This function will print all information in the list
 *				to the screen.
 *
 * Parameter: phoneInfo *head: start of the linked list
 * Return Value: none
 */

void listInfo (phoneInfo *head)
{
	phoneInfo *ptr = head;

	/*
	 * follow the chain until the pointer is null
	 */

	while (ptr != NULL) 
	{
		printf ("\n");
		printf ("Name:         %s\n", ptr->name);
		printf ("Address:      %s\n", ptr->address);
		printf ("Phone Number: %s\n\n",	ptr->phoneNumber);
		ptr = ptr->next;
	}	/* end while */

	printf ("\n\nEnd of data\n");
}	/* end listInfo */


/*
 * phoneInfo * deleteAllInfo (phoneInfo *head)
 *
 * This function will free() all allocated memory
 * in the linked list.
 *
 * Parameter: phoneInfo *head: start of the linked list
 * Return Value: NULL indicating a newly-empty list
 */

phoneInfo *deleteAllInfo (phoneInfo *head)
{
	phoneInfo *curr = NULL, *ptr = head;

	/*
	 * follow the chain until the pointer is null
	 */

	while (ptr != NULL) 
	{
		/*
		 * first, save ptr to next, then 
		 * delete current
		 */

		curr = ptr;
		ptr = ptr->next;
		free (curr);
	}	/* end while */

	/*
	 * before we leave, reset
	 * the head pointer to NULL since
	 * there isn't anything left in
	 * memory to work with
	 */

	printf ("\n\nAll data deleted\n");

	return NULL;
}	/* end deleteAllInfo */




/*
 * phoneInfo * deleteOne (phoneInfo *head)
 *
 * This function will delete one specific item from
 * the linked list.  If items are duplicated, we are only 
 * deleting the first one found.
 *
 * Parameter: phoneInfo *head: start of the linked list
 * Return Value: phoneInfo *: new start of the linked list
 */

phoneInfo *deleteOne (phoneInfo *head)
{
	phoneInfo *prev = NULL, *ptr = NULL;
	char record[50] = "";
	char *endDelim = NULL;

	// special case: empty list?
	if( head == NULL )
	{
		printf("\nList is already empty\n");
		return head;
	}

	// get name of item to delete from user, stripping off \n
	printf("\nEnter name to delete: ");
	fgets(record, sizeof record, stdin);
	if( (endDelim = strchr(record, '\n')) != NULL )
	{
		*endDelim = '\0';
	}

	// special case: are we deleting the first item?
	if( strcmp(head->name, record) == 0 )
	{
		printf("Deleting %s / %s / %s\n", head->name, head->address, head->phoneNumber);
		// save pointer, reassign head, and delete the first item
		ptr = head;
		head = head->next;
		free(ptr);
		return head;
	}

	/*	
	 * follow the chain until the item is found 
	 * or the pointer is null 
	 */

	for( ptr = head; ptr != NULL; ptr = ptr->next ) 
	{
		// do we have a match?
		if( strcmp(ptr->name, record) == 0 )
		{
			printf("Deleting %s / %s / %s\n", ptr->name, ptr->address, ptr->phoneNumber);
			// bypass the item
			prev->next = ptr->next;
			// delete the item
			free(ptr);
			return head;
		}


		//save ptr to next, then advance
		prev = ptr;
	}	/* end while */

	printf("\nNo match found\n");
	return head;
}	/* end deleteOne() */



/*
* Function: void clearCRLF(char *str)
*
* Description: This function will get rid of a \n at the end of a string.
*			   If there isn't one, it doesn't change the string.
*
* Parameter: char *str: start of the string
* Return Value: nothing
*/

void clearCRLF(char *str)
{
	char *whereIsCRLF = strchr(str, '\n');
	if (whereIsCRLF != NULL)
	{
		*whereIsCRLF = '\0';
	}
}
