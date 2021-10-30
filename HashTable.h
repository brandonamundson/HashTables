/*************************************************************************/ /**
 * @file
 *****************************************************************************/
#pragma once
#include <iostream>
#include <string>
using namespace std;

class HashTable
{
private:
	/*!
	* @brief 
	*/
	struct HashTableEntry
	{
		int k;
		string v;

		HashTableEntry* next;

		HashTableEntry(int k, string v)
		{
			this->k = k;
			this->v = v;
			next = nullptr;
		}
	};

	int tableSize = 200;
	HashTableEntry **ht, **top;
	int hashFunc(int key);

public:
	HashTable(); /*!< The constructor of the Binary Tree*/
	~HashTable();
	int getTS();
	void insert(int k, string v);
	void remove(int k);
	void searchKey(int k);
	void setTS(int tableSize);
};
