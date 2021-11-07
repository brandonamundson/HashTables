/*************************************************************************/ /**
 * @file 
 *
 * @mainpage Hash Tables
 * 
 * @section course_section Course Information 
 *
 * @author Brandon Amundson 
 * 
 * @date 10/29/2021
 * 
 * @par Professor: 
 *         Doug Perez
 * 
 * @par Course: 
 *         CSC382
 * 
 * @section program_section Program Information 
 * 
 * @details Program to demonstrate implementation of a phone book by hash table
 *
 * @section compile_section Compiling and Usage 
 *
 * @par Compiling Instructions: 
 *      None.
 * 
 * @par Usage: 
 *
 * @section todo_bugs_modification_section Todo, Bugs, and Modifications
 * 
 * 
 * @par Modifications and Development Timeline: 
   @verbatim 
   Date          Modification 
   ------------  -------------------------------------------------------------- 
   Oct 29, 2021  Finished HashTable implementation
   Oct 30, 2021  Adding phone book implementation to hash table
   Nov 01, 2021  Fixed implementation of insert and remove functions
   Nov 03, 2021  Finished implementing resize function
   Nov 04, 2021  Verified functionality of hash table implementation
   @endverbatim
 *
 *****************************************************************************/
#include "HashTable.h"

/**************************************************************************/ /*
 * @author Brandon Amundson
 *
 * @par Description:
 * This function is the main function that runs the program.
 *
 *****************************************************************************/
int main()
{
	HashTable hash;
	std::string k;
	std::string v;
	int choice = 0;
	while (choice != 5)
	{
		std::cout << "1. Insert element into the phone book" << std::endl;
		std::cout << "2. Search element by name" << std::endl;
		std::cout << "3. Delete element by name" << std::endl;
		std::cout << "4. Resize the book" << std::endl;
		std::cout << "5. Exit" << std::endl;
		std::cout << "Enter your choice: ";
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			std::cout << "Enter phone number to be inserted: ";
			std::cin >> v;
			std::cout << "Enter name to be inserted with phone number: ";
			std::cin >> k;
			hash.insert(k, v);
			break;
		case 2:
			std::cout << "Enter name to be searched: ";
			std::cin >> k;
			hash.searchKey(k);
			break;
		case 3:
			std::cout << "Enter name to be deleted: ";
			std::cin >> k;
			hash.remove(k);
			break;
		case 4:
			int g;
			std::cout << "The current size of the phone book is: "
				<< hash.getTS() << std::endl;
			std::cout << "What size do you wish to resize the phone book to? ";
			std::cin >> g;
			hash.resize(g);
			break;
		case 5:
			break;
		default:
			std::cout << "\nEnter valid option\n";
		}
	}
	return 0;
}
