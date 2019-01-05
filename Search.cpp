/*****************************************************
*	Search.cpp
*
*	Dustin Meckley
*	ciss350
*	7/09/15
*****************************************************/
#ifndef SEARCH_CPP_
#define SEARCH_CPP_

#include <iostream>

#include "Search.h"

/*****************************************************
*	Search()  
*
*	Constructor for Search class.
*/
Search::Search() 
{
	// Declaration of a static array with an initialization
	// list of elements.
	int test[] = {7, 4, 2, 5, 25, 0, -3, 9, 45, -69};

	// mergeInit function that initiates the execution of 
	// mergeSort function onto the unsorted array list of
	// elements. 
	mergeInit(test, SIZE);

	// Calls the setValue function in order to allow the user
	// to enter their input value that will be searched for 
	// within the array.
	setValue();

	// Displays the value entered by the user.
	std::cout << "The value that you entered is: " << getValue() 
			  << std::endl;

	// Tests whether the binary search function finds the value
	// that the user entered.  If it does then it displays out 
	// the index location to the user.  If it doesn't then it 
	// throws an InvalidKeyException to be displayed to the user. 
	if (binary(test, 0, SIZE - 1, getValue()) == -1)
		throw(InvalidKeyException());
	else
		std::cout << "That value is found at element location #" 
				  << binary(test, 0, SIZE - 1, getValue()) 
				  << std::endl << std::endl;
}

/***************************************************** 
*	~Search()  
*
*	Destructor for Search class.
*/
Search::~Search()
{

}

/*****************************************************
*	mergeInit()
*
*	mergeInit for Search class. 
*/
void Search::mergeInit(int list[], int SIZE)
{
	// Prints the unsorted list to the user.
	std::cout << std::endl;
	std::cout << "Before sorting: " << std::endl;
	printList(list, SIZE);
	std::cout << std::endl;

	// Calls the mergeSort function in order to 
	// sort the array list of elements.
	mergeSort(list, 0, SIZE - 1);

	// Prints the sorted list to the user.
	std::cout << "After sorting: " << std::endl;
	printList(list, SIZE);
	std::cout << std::endl;
}

/*****************************************************
*	merge()
*
*	merge for Search class. 
*/
void Search::merge(int list[], int first, int last, int middle)
{
	// The merge function is utilized by the mergeSort function 
	// in order to merge the two sorted halves of the array based
	// list back into one array based list.

	// Pointers to indicate the current position of the left half
	// and the right half of the array based list.
	int* leftArray = NULL;
	int* rightArray = NULL;

	// Counter Indexes:
	int i = 0;			// Left Sublist Index.
	int j = 0;			// Right Sublist Index.
	int k = 0;			// List Index. 

	// Determining the range of the two halves of the array based list:
	int firstHalf = middle - first + 1;
	int secondHalf = last - middle;

	// Allocating memory necessary for the new two half arrays:
	leftArray = new int[firstHalf];
	rightArray = new int[secondHalf];

	// Create the two half sublists of the array based list.
	for(i = 0; i < firstHalf; i++)
	{
		leftArray[i] = list[first + i];
	}
	for(j -= 0; j < secondHalf; j++)
	{
		rightArray[j] = list[middle + 1 + j];
	}

	// Resetting the counter Indexes:
	i = 0;				// Left Sublist Index.
	j = 0;				// Right Sublist Index.
	k = first;			// List Index. 

	// While there are still more items in the left half
	// and right half of the array based list halves then:
	while(i < firstHalf && j < secondHalf)
	{
		// Set list[k] to leftArray[i]
		if(leftArray[i] <= rightArray[j])
		{
			list[k] = leftArray[i];
			i++;
		}
		// Set list[k] to leftArray[j]
		else
		{
			list[k] = rightArray[j];
			j++;
		}
		// Increment index.
		k++;
	}

	// Copies remaining elements from the left half 
	// of the array based list half.
	while(i < firstHalf)
	{
		list[k] = leftArray[i];
		i++;
		k++;
	}

	// Copies remaining elements from the right half 
	// of the array based list half.
	while(j < secondHalf)
	{
		list[k] = rightArray[j];
		j++;
		k++;
	}

	// Deallocating memory for the two halfs of allocated arrays:
	delete [] leftArray;
	delete [] rightArray;
}

/*****************************************************
*	mergeSort()
*
*	mergeSort for Search class. 
*/
void Search::mergeSort(int list[], int first, int last)
{
	// The mergeSort function splits the original array
	// based list into two half array based lists, then
	// it sorts the first half of the array based list and 
	// then it sorts the last half of the array based list. 
	int middle;
	if (last > first)
	{
		middle = (first + last) / 2;
		mergeSort(list, first, middle);
		mergeSort(list, middle + 1, last);
		merge(list, first, last, middle);
	}
}

/*****************************************************
*	binary()
*
*	binary for Search class. 
*/
int Search::binary(int list[], int first, int last, int key)
{
	// Binary search function which determines if the found value 
	// is in the middle of the list, the lower half of the list, or
	// the upper half of the list by recursion. Then returns the 
	// index location of the found key value if it is in the list
	// otherwise it returns -1 which is then evaluated to throw an 
	// exception.
	if(first <= last)
	{
		int middle = (first + last) / 2;
		if (key == list[middle])
			return middle;
		else if (key < list[middle])
			return binary(list, first, middle - 1, key);
		else
			return binary(list, middle + 1, last, key);
	}
	else
	{
		return -1;
	}
}

/*****************************************************
*	setValue()
*
*	setValue for Search class. 
*/
void Search::setValue()
{
	// Sets the value that the user inputs in order to search for the
	// value within the array list.
	int choice = 0;
	std::cout << "Please enter the key value to search for in the list: ";
	std::cin >> choice;
	this->choice = choice;
}

/*****************************************************
*	getValue()
*
*	getValue for Search class. 
*/
int Search::getValue() const
{
	// Returns the value that the user inputs in order to search
	// through the list for the appropriate index location. 
	return this->choice;
}

/*****************************************************
*	printList()
*
*	printList for Search class. 
*/
void Search::printList(int list[], const int SIZE) const
{
	// Prints the list to the user.
	for(int i = 0; i < SIZE; i++)
	{
		std::cout << list[i] << std::endl;
	}
}

#endif