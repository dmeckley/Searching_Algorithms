Dustin Meckley
Search File

Search.h, Search.cpp, main.cpp, Makefile, README.txt are all of the documents for the search file.

This program takes the key value choice from the user and looks for the element index location within the array.  It does this by first sorting the unsorted list with the mergeSort method and then transfers the newly sorted list into the binary function along with the key value that performs the binary search based off of the users input data.  Finally, it returns the index number of the found value within the array to the user or throws an exception if the value is not within the list.

I utilized the Sublime text editor and the Ubunta Commandline in order to compile this program by methods of creating a Makefile.  In order to compile this program correctly, then all of the files have to be copied into their own directory which I called mine "Lab5".  After this is done, then you have to make the "search" file by typing <make> into the commandline.  Then by looking at the "Lab5" directory, you should have a "search" file which usually appears as a bright yellow directory.  In order to run this you must type  </.search> and then <enter> into the commandline.  In order to clean the file or to re-make the file, then you must type <make clean> in the same lab5 directory. This should clean the file for a new rebuild.  

Enclosed in "double-quotation marks" indicates a file or directory name.
Enclosed in <arrow operators tag structure> indicates buttons needed to be pressed by programmer or end-user.

Test data for the Input Values are from the list and include: 7, 4, 2, 5, 25, 0, -3, 9, 45, -69.
Test data for the User Key Value Input are: -100, 7, 4, 2, 5, 25, 0, -3, 9, 45, -69, 100.