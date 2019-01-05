/*****************************************************
*	main.cpp
*
*	Dustin Meckley
*	ciss350
*	7/09/15
*****************************************************/
#include <iostream>

#include "Search.h"

/*****************************************************
*	main()
*
*	Test Driver for execution of program.
*
*/
int main()
{
	try
	{
		Search s;	
	}
	catch(Search::InvalidKeyException e)
	{
		e.message();
	}
	
	return 0;
}
