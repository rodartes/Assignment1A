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
	struct DynArr *myDA;
	assert(capacity >= 0);
	myDA -> cap = capacity;
	myDA -> size = 0;
	myDA -> data = (TYPE *) malloc(myDA -> cap * sizeof(TYPE));
	assert(myDA -> data != 0);
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
	myDA -> data[myDA -> size] = value;
	myDA -> size++;
}

/*function to get an element's data at a certain index, coded by Samantha Rodarte*/

TYPE getDynArr(DynArr *myDA, int position){
	assert((myDA -> cap > position) && (position >= 0));
	return myDA -> data[position];
}

/*function to place an element at a specific index, coded by ...*/

void putDynArr(DynArr *myDA, int position, TYPE value){

}

/*function to swap two elements within an array, coded by ...*/

void swapDynArr(DynArr *myDA, int idx_i, int  idx_j){

}

/*function to remove an element at a specific index, coded by ...*/

void removeAtDynArr(DynArr *myDA, int idx_i){

}

/* ************************************************************************
	Stack Interface Functions
************************************************************************ */


/* ************************************************************************
	Bag Interface Functions
************************************************************************ */