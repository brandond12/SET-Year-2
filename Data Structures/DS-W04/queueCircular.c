//
// Filename: queueCircular.c
// Date: Feb. 6, 2005
// Author: Carlo Sgro
// Description: Example of implementation of a queue of 'X' characters using a circular array
//



#include "stdio.h"
#include "conio.h"

#pragma warning(disable:4996)

#define kMaxQueueSize 10

struct queue
{
	unsigned int head;
	unsigned int tail;
	char buffer[kMaxQueueSize];
};

int main(int argc, char* argv[])
{
struct queue q = {0, 0, {0}};
char c = 0;
int i = 0;
const int kFalse = 0;
const int kTrue = 1;
int done = kFalse;

	for( i = 0; i < kMaxQueueSize; i++ )
	{
		q.head = 0;
		q.tail = 0;
		q.buffer[i] = ' ';
	}

	while( done == kFalse )
	{
		printf("\nPress 'a' to add an 'X', 'd' to delete an 'X', 'p' to print, and 'q' to quit\n");

		switch( getch() )
		{
		case 'p':
			printf("Head is %d, tail is %d\n", q.head, q.tail);
			printf("Contents (X indicates a used element):\n");
			for( i = 0; i < kMaxQueueSize; i++ )
			{
				printf("%3d: %c\n", i, q.buffer[i]);
			}
			printf("\n");
			break;
		case 'a':
			if( q.head == q.tail )
			{
				// queue is empty
				printf("Added to empty queue in position %d\n", q.tail);
				q.buffer[q.tail] = 'X';
				q.tail++;

				// handle wrapping
				if( q.tail >= kMaxQueueSize )
				{
					// wrap around end
					q.tail = 0;
				}
			}
			else if( (q.head - 1 == q.tail) 
							|| ((q.head == 0) && (q.tail == kMaxQueueSize - 1)) )
			{
				// queue is full
				printf("Queue full\n");
			}
			else
			{
				printf("Adding item %d\n", q.tail);
				q.buffer[q.tail] = 'X';
				q.tail++;
				// handle wrapping
				if( q.tail >= kMaxQueueSize )
				{
					// wrap around end
					q.tail = 0;
				}
			}
			break;
		case 'd':
			if( q.head == q.tail )
			{
				// queue is empty
				printf("Queue empty\n");
			}
			else
			{
				printf("Deleting item %d\n", q.head);
				q.buffer[q.head] = ' ';
				q.head++;
				// handle wrapping
				if( q.head >= kMaxQueueSize )
				{
					// wrap around end
					q.head = 0;
				}
			}
			break;
		case 'q':
			done = kTrue;
			break;
		default:
			printf("Invalid input\n");
			break;
		}
	}
	return 0;
}

