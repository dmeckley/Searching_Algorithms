/*****************************************************
*	Search.h
*
*	Dustin Meckley
*	ciss350
*	07/09/15
*****************************************************/
#ifndef SEARCH_H_
#define SEARCH_H_

class Search
{
	// -----------------------------------------------------
	//                    Class Methods: 
	// -----------------------------------------------------
public:
	// Exception Handler Class:
	class InvalidKeyException
	{
	public: 
		void message()
		{
			std::cerr << "Error: That value is not within the list! " 
			<< std::endl << std::endl;
		}
	};

	// Search Class Object Constructor and Destructor:
	Search();
	~Search();

	// mergeSort Search Class Object Function Methods:
	void mergeInit(int[], int);
	void merge(int[], int, int, int);
	void mergeSort(int[], int, int);

	// binarySearch Search Class Object Function Methods:
	int binary(int[], int, int, int);

	// miscellanous Search Class Object Function Methods:
	void setValue();
	int getValue() const;
	void printList(int[], const int) const;

	// ----------------------------------------------------
	//                         Class Members:
	// ----------------------------------------------------
private:
	int choice;
	const static int SIZE = 10;
};

#endif