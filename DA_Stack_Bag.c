// DA_Stack_Bag.c: Dynamic Array, Stack and Bag implementations
#include <assert.h>
#include <stdlib.h>
#include "DA_Stack_Bag.h"


/* ************************************************************************
	Struct DynArr
************************************************************************ */
struct DynArr{
	TYPE * data;
	int size;
	int cap;
};

/* ************************************************************************
	Dynamic Array Functions
************************************************************************ */

/*function to allocate and initialize a dynamic array, coded by Samantha Rodarte*/

DynArr* newDynArr(int capacity){
	//DynArr *r = (DynArr *)malloc(sizeof( DynArr));
	//assert(r != 0);
	//initDynArr(r,cap);

	struct DynArr *myDA = (DynArr *)malloc(sizeof( DynArr));
	assert(myDA != 0);
	assert(capacity >= 0);
	myDA -> cap = capacity;
	myDA -> size = 0;
	myDA -> data = (TYPE *) malloc(myDA -> cap * sizeof(TYPE));
	assert(myDA -> data != 0);
	return myDA;
	
}

/*function to deallocate data and delete a dynamic array, coded by Samantha Rodarte*/

void deleteDynArr(DynArr *myDA){
	assert(myDA != 0);
	free(myDA -> data);
	myDA -> cap = 0;
	myDA -> size = 0;
}						

/*function to return the size of the dynamic array, coded by Samantha Rodarte*/

int sizeDynArr(DynArr *myDA){
	return myDA -> size;
}						

/*function to add an element to the end of the array, coded by Samantha Rodarte*/

void addDynArr(DynArr *myDA, TYPE value){
	/*
	if(myDA->size >= myDA->cap)
	{
	assert(myDA != 0);
	int x;
	TYPE * temp = myDA->data;
	int oldSize = myDA->size;
	
	myDA = newDynArr(2* myDA->cap);
	
	for(x = 0; x < sizeDynArr(myDA); x++)
	{
		myDA->data[x] = temp[x];
	}
	myDA->size = oldSize;
	free(temp);
	}
	*/
	
	myDA -> data[myDA -> size] = value;
	myDA -> size++;
}

/*function to get an element's data at a certain index, coded by Samantha Rodarte*/

TYPE getDynArr(DynArr *myDA, int position){
	assert((sizeDynArr(myDA) > position) && (position >= 0));
	return myDA -> data[position];
}

/*function to place an element at a specific index, coded by ...*/

void putDynArr(DynArr *myDA, int position, TYPE value){

	myDA->data[position] = value;

}

/*function to swap two elements within an array, coded by ...*/

void swapDynArr(DynArr *myDA, int idx_i, int  idx_j){
	TYPE temp = myDA->data[idx_i];
	myDA->data[idx_i] = myDA->data[idx_j];
	myDA->data[idx_j] = temp;
}

/*function to remove an element at a specific index, coded by ...*/

void removeAtDynArr(DynArr *myDA, int idx_i){
	for(int i = idx_i; i < sizeDynArr(myDA); i++)
	{
		myDA->data[i] =myDA->data[i+1];
	}
	myDA->size--;

}

/* ************************************************************************
	Stack Interface Functions
************************************************************************ */
Stack *newStack(int capacity){
	
	struct DynArr *myDA = (DynArr *)malloc(sizeof( DynArr));
	assert(capacity >= 0);
	myDA -> cap = capacity;
	myDA -> size = 0;
	myDA -> data = (TYPE *) malloc(myDA -> cap * sizeof(TYPE));
	assert(myDA -> data != 0);
	return myDA;
}							
void deleteStack(Stack *myStack){
	deleteDynArr(myStack);
}
int sizeStack(Stack *myStack){
	return myStack->size;

}					
int isStackEmpty(Stack *myStack){
	return (sizeStack(myStack) == 0); 

}						
void pushStack(Stack *myStack, TYPE value){
	addDynArr(myStack, value);

}
TYPE topStack(Stack *myStack){
	assert(sizeDynArr(myStack) > 0);
	return getDynArr(myStack, sizeStack(myStack) - 1);

}			
void popStack(Stack *myStack){
	assert(sizeStack(myStack) > 0);
	myStack->size--;

}

/* ************************************************************************
	Bag Interface Functions
************************************************************************ */

/*function to allocate and initialize a bag, coded by Samantha Rodarte*/
Bag *newBag(int capacity){
	struct DynArr *myBag = (DynArr *)malloc(sizeof( DynArr));
	assert(capacity >= 0);
	myBag -> cap = capacity;
	myBag -> size = 0;
	myBag -> data = (TYPE *) malloc(myBag -> cap * sizeof(TYPE));
	assert(myBag -> data != 0);
	return myBag;
}

/*function to deallocate data and delete a bag, coded by Samantha Rodarte*/
void deleteBag(Bag *myBag){
	assert(myBag != 0);
	free(myBag -> data);
	myBag -> cap = 0;
	myBag -> size = 0;
}

/*function to return the size of a bag, coded by Samantha Rodarte*/
int sizeBag(Bag *myBag){
	return myBag -> size;
}

/*function which returns 1 if a bag is empty, and 0 if the bag has data, coded by Samantha Rodarte*/
int isBagEmpty(Bag *myBag){
	if(myBag -> size == 0)
		return 1;
	else
		return 0;
}

/*function to add an element to a bag, coded by Samantha Rodarte*/
void addBag(Bag *myBag, TYPE value){
	/*(assert(myBag != NULL);
	if(myBag -> size >= myBag -> cap)
		return; */
	myBag -> data[myBag -> size] = value;
	myBag -> size++;

}

/*function to check if an element is contained within a bag, returning 1 if it is and 0 if it is not*/
int containsBag(Bag *myBag, TYPE value){
	assert(myBag != NULL);
	int i = myBag -> size - 1;
	while(i >= 0){
		if(myBag -> data[i] == value)
			return 1;
	i--;
	}
	return 0;
}

/*function to remove a specific element from a bag, coded by Samantha Rodarte*/
void removeBag(Bag *myBag, TYPE value){
	assert(myBag != NULL);
	int i = myBag -> size - 1;
	while(i >= 0) {
		if(myBag -> data[i] == value) {
			myBag -> data[i] = myBag -> data[myBag -> size - 1];
			myBag -> size-- ;
			return;
		}
	i--;
	}
}				
