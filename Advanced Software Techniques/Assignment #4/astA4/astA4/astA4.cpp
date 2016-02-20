#include "address.h"
#include <stdio.h>

int main(void){
//small test harness
	address test;
	int result = 0;

	test.setProvince("ON");

	printf("\n\n Telephone Number Tests:\n\n");
	result = test.setTelephone("(519)456 7890");
	printf("Test 1: Telephone:\nInput : 519-456-7890\nError code: %d\nSaved phone number: %s", result, test.getTelephone());

	printf("\n\n Telephone Number Tests:\n\n");
	result = test.setTelephone("(519) 456 7890");
	printf("Test 1: Telephone:\nInput : 519-456-7890\nError code: %d\nSaved phone number: %s", result, test.getTelephone());

	printf("\n\n Telephone Number Tests:\n\n");
	result = test.setTelephone("519 456 7890");
	printf("Test 1: Telephone:\nInput : 519-456-7890\nError code: %d\nSaved phone number: %s", result, test.getTelephone());

	printf("\n\n Telephone Number Tests:\n\n");
	result = test.setTelephone("519.456.7890");
	printf("Test 1: Telephone:\nInput : 519-456-7890\nError code: %d\nSaved phone number: %s", result, test.getTelephone());

	printf("\n\n Telephone Number Tests:\n\n");
	result = test.setTelephone("519-456-7890");
	printf("Test 1: Telephone:\nInput : 519-456-7890\nError code: %d\nSaved phone number: %s", result, test.getTelephone());

	printf("\n\n Telephone Number Tests:\n\n");
	result = test.setTelephone("5194567890");
	printf("Test 1: Telephone:\nInput : 519-456-7890\nError code: %d\nSaved phone number: %s", result, test.getTelephone());

	printf("\n\n Telephone Number Tests:\n\n");
	result = test.setTelephone("(519)4567890");
	printf("Test 1: Telephone:\nInput : 519-456-7890\nError code: %d\nSaved phone number: %s", result, test.getTelephone());

	printf("\n\n Telephone Number Tests:\n\n");
	result = test.setTelephone("(519) 4567890");
	printf("Test 1: Telephone:\nInput : 519-456-7890\nError code: %d\nSaved phone number: %s", result, test.getTelephone());

	printf("\n\n");
	test.printAddress();
	return 0;
}