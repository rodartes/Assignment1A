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
	myDA ->cap = 0;
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
/*
Bag *newBag(int capacity){

}				
void deleteBag(Bag *myBag){

}						
int sizeBag(Bag *myBag){
	
}								
int isBagEmpty(Bag *myBag){

}					
void addBag(Bag *myBag, TYPE value){

}				
int containsBag(Bag *myBag, TYPE value){

}				
void removeBag(Bag *myBag, TYPE value){

}
*/