/*
 * firstName: doublyLL.c
 * By: Carlo Sgro
 * Date: Jan. 22/10
 * Description: This is an example of a doubly-linked sorted list with head and tail.
 *				Deletion is supported.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#pragma warning( disable : 4996 )


// constants
#define kInputLength 121



// data types
typedef struct personInfo    
{
	char firstName[kInputLength];
	struct personInfo *prev;
	struct personInfo *next;
} personInfo;





// prototypes
int  insert(char *insertingFirstName, personInfo **head, personInfo **tail);
void showList(personInfo *head);
void showListBackwards(personInfo *tail);
int deleteOne(char *who, personInfo **head, personInfo **tail);
void freeAll(personInfo *head);
void eliminateEndOfLine(char *buffer);




int main(int argc, char *argv[])
{
personInfo *head = NULL, *tail = NULL;
char buffer[kInputLength] = {0};
 
	// enter info into list
	do
	{
		// prompt user for a first name
		printf("Enter a first name (ENTER to quit input): ");
		fgets(buffer, kInputLength, stdin);

		// if it's empty, quit inputting
		if( strcmp(buffer, "\n") == 0 )
		{
			break;
		}

		// get rid of the '\n' that fgets() put in if it's there
		eliminateEndOfLine(buffer);

		// put the first name into the list
		insert(buffer, &head, &tail);
	} while( 1 );

	// display the contents of the list
	showList(head);
	showListBackwards(tail);

	// prompt user for one item to delete
	printf("Enter one name to delete: ");
	fgets(buffer, kInputLength, stdin);
	eliminateEndOfLine(buffer);
	deleteOne(buffer, &head, &tail);

	// redisplay the contents of the list
	showList(head);
	showListBackwards(tail);

	// free the list now that we're done with it
	freeAll(head);
	head = NULL;
	tail = NULL;

	return 0;
}








/*
 * Function: insert()
 * Description: This function inserts an element in the correct location in the list, sorted alphabetically.
 * Parameters:  char *firstName: string containing the firstName
 *				personInfo **head, **tail: POINTERS TO head and tail of the list
 * Returns: 0 if the insertion failed, 1 otherwise
*/

int insert(char *insertingFirstName, personInfo **head, personInfo **tail)
{
personInfo *newBlock = NULL;
personInfo *beforeElement = NULL;
personInfo *afterElement = NULL;
	
	// allocate a block of memory for new record
	newBlock = (personInfo *) malloc(sizeof (personInfo));
	if( newBlock == NULL ) 
	{
		printf("Error! No more memory!\n");
		return 0;
	}	/* end if */

	// obtain information for new record
	strcpy(newBlock->firstName, insertingFirstName);
	newBlock->prev = newBlock->next = NULL;


	// now link this record to the list in the appropriate place
	if( *head == NULL) 
	{
		// empty list, so set head and tail
		*head = *tail = newBlock;
		return 1;
	} 
	else if( strcmp((*head)->firstName, insertingFirstName) >= 0 ) // special case!
	{
		// we're inserting at the front of the list
		
		// set the next pointer for the newBlock record to be the
		// location that used to be at the front of the list
		newBlock->next = *head;
		// set the old head's prev to point to the new start of the list
		(*head)->prev = newBlock;
		// set head to point to the new start of the list
		*head = newBlock;
	}
	else
	{
		/*
		 * non-empty list where we're not inserting at the front
		 * of the list, so use ptr to follow links until we reach the 
		 * right place, according to the sorting order
		 */

		beforeElement = *head;		// first item in list
		afterElement = (*head)->next;	// second item in list 
		
		while( afterElement != NULL ) 
		{
			if( strcmp(afterElement->firstName, insertingFirstName) >= 0 )
			{
				// we've found a name in the list that is either equal to or greater 
				// than the one we're entering now
				break;
			}
			beforeElement = afterElement;
			afterElement = afterElement->next;
		}	/* end while */

		// add the new node here, between beforeElement and afterElement
		newBlock->prev = beforeElement;
		newBlock->next = afterElement;
		beforeElement->next = newBlock;
		// are we at the end?
		if( afterElement == NULL )
		{
			*tail = newBlock;
		}
		else
		{
			afterElement->prev = newBlock;
		}

	}	/* endif */

	return 1;
}





/*
 * Function: showList()
 * Description: This method will show each first name that is in the linked list.
 * Parameters: personInfo *head: start of the linked list
 * Returns: nothing
*/

void showList(personInfo *head)
{
	personInfo *item = NULL;

	item = head;

	printf("The list contains:\n");
	while( item != NULL )
	{
		printf("%s\n", item->firstName);
		item = item->next;
	}
}



/*
 * Function: showListBackwards()
 * Description: This method will show each first name that is in the linked list, 
 *				in reverse order.
 * Parameters: personInfo *tail: end of the linked list
 * Returns: nothing
*/

void showListBackwards(personInfo *tail)
{
	personInfo *item = NULL;

	item = tail;

	printf("The backwards list contains:\n");
	while( item != NULL )
	{
		printf("%s\n", item->firstName);
		item = item->prev;
	}
}






/*
 * Function: deleteOne()
 * Description: This function removes one specified item from the linked list.  
 *				If there are duplicates, it only deletes the first one.
 *				NOTE: This function would be more efficient if it stopped as soon
 *				as it passed where the item to delete would be in the case of 
 *				not finding it.  That feature has been left out to make the function
 *				more adaptable in the case of searching a field other than the 
 *				sorting field.
 * Parameters:	char *who: name of person to delete
 *				personInfo *head: start of linked list
 *				personInfo *tail: end of linked list
 * Returns: 0 if the item is not in the list, 1 otherwise
*/
int deleteOne(char *who, personInfo **head, personInfo **tail)
{
	personInfo *curr = NULL, *next = NULL;

	curr = *head;  

	// traverse the list, being careful to not access freed blocks
	while( curr != NULL )
	{
		// found it?
		if( strcmp(who, curr->firstName) == 0 )
		{
			// found it!

			// we need to relink the list so that the next pointer of 
			// the preceding element is pointing at the element after 
			// the one to delete AND the prev pointer of the element 
			// after the one to delete is pointing to the preceding element

			// we also need to make sure that we handle the case where we're 
			// deleting at the head and/or tail

			
			if( (curr == *head) && (curr == *tail) )
			{
				// this is the only item in the list
				*head = *tail = NULL;
				free(curr);
				return 1;
			}

			// are we deleting the first of many items?
			if( curr == *head )
			{
			personInfo *secondElement = curr->next;
				// we're deleting the first item
				*head = curr->next;
				// null out the prev pointer for what used to be the second item
				secondElement->prev = NULL;
			}
			else
			{
				// make the following prev pointer point to the element before this one, 
				// as long as we're not deleting the last item
				if( curr == *tail )
				{
				personInfo *secondlastElement = curr->prev;
					// adjust the tail
					*tail = curr->prev;
					// null out the next pointer for what used to be the second-last item
					secondlastElement->next = NULL;
				}
				else
				{
				personInfo *precedingElement = curr->prev;
				personInfo *followingElement = curr->next;

					// set the following element's prev pointer to point to the item before this one
					followingElement->prev = precedingElement; 
					// set the preceding element's next pointer to point to the item after this one
					precedingElement->next = followingElement;
				}
			}
			
			// finally, free the desired element
			free(curr);
			
			return 1;
		}
		
		curr = curr->next;
	}

	// didn't find the item to delete
	return 0;
}



/*
 * Function: freeAll()
 * Description: This function removes all items from the linked list.
 * Parameters: personInfo *head: start of linked list
 * Returns: nothing
*/
void freeAll(personInfo *head)
{
	personInfo *curr = NULL, *next = NULL;

	curr = head;  

	// traverse the list, being careful to not access freed blocks
	while( curr != NULL )
	{
		// keep a pointer to the next block so we can go there after it's freed
		next = curr->next; 
		free(curr);
		curr = next;
	}

}





/*
 * Function: eliminateEndOfLine()
 * Description: This function replaces the first '\n' that is found in a string
 *				with a null-termination.
 *				If there is none, it does nothing.
 * Parameters: char *buffer: string to work with
 * Returns: nothing
*/

void eliminateEndOfLine(char *buffer)
{
char *target = strchr(buffer, '\n');
	if( target != NULL )
	{
		*target = '\0';
	}
}
