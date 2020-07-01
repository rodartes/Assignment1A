//This is just a file I created to make sure the code compiles

#include <stdio.h>
#include <stdlib.h>
#include "DA_Stack_Bag.h"

void assertTrue(int predicate, char *message) 
{
	printf("%s: ", message);
	if (predicate)
		printf("PASSED\n");
	else
		printf("FAILED\n");
}

int main(int argc, char* argv[])
{
	Bag *myBag;
	myBag = newBag(2);
	
	printf("\n\nTesting bag interface...\n");
	addBag(myBag, 3);
	addBag(myBag, 6);
	addBag(myBag, 5);
	addBag(myBag, 9);
	printf("The bag's content: [3,6,5,9]\n");
	assertTrue(!isBagEmpty(myBag), "Testing isBagEmpty");
	assertTrue(sizeBag(myBag) == 4, "Test size = 4");
	assertTrue(containsBag(myBag, 3), "Test containing 3");
	assertTrue(containsBag(myBag, 6), "Test containing 6");
	assertTrue(containsBag(myBag, 5), "Test containing 5");
	assertTrue(containsBag(myBag, 9), "Test containing 9");
	assertTrue(!containsBag(myBag, 7), "Test not containing 7");
	
	removeBag(myBag, 3);
	printf("Removing 3...\nThe bag's content: [6,5,9]\n");
 	assertTrue(!containsBag(myBag, 3), "Test not containing 3");
	
    deleteBag(myBag); 
	return 0;
}