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
 * @details 
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
   Oct 29, 2021  Started Creation
   @endverbatim
 *
 *****************************************************************************/
#include "HashTable.h"

/**************************************************************************/ /**
 * @author Brandon Amundson
 *
 * @par Description:
 * This function creates the list by setting the root of the Tree to nullptr
 *
 *****************************************************************************/
int main()
{
	HashTable hash;
	int k;
	string v;
	int choice = 0;
	while (choice != 4)
	{
		cout << "1.Insert element into the table" << endl;
		cout << "2.Search element from the key" << endl;
		cout << "3.Delete element at a key" << endl;
		cout << "4.Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter element value to be inserted: ";
			cin >> v;
			cout << "Enter key at which element to be inserted: ";
			cin >> k;
			hash.insert(k, v);
			break;
		case 2:
			cout << "Enter key of the element to be searched: ";
			cin >> k;
			hash.searchKey(k);
			break;
		case 3:
			cout << "Enter key of the element to be deleted: ";
			cin >> k;
			hash.remove(k);
			break;
		case 4:
			break;
		default:
			cout << "\nEnter correct option\n";
		}
	}
	return 0;
}
