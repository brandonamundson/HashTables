/*************************************************************************/ /**
 * @file
 *****************************************************************************/
#pragma once
#include <iostream>
#include <list>
#include <string>

class HashTable
{
private:
	/*!
	* @brief Hash table entry aka node.  Stores key integer and string value.
	* Also has ptr to next table entry and a constructor to init values passed in.
	*/
	struct HashTableEntry
	{
		std::string k;
		std::string v;

		HashTableEntry* next;

		HashTableEntry(std::string k, std::string v)
		{
			this->k = k;
			this->v = v;
			next = nullptr;
		}
	};

	int tableSize = 10; /*!< Set default size for HashTable*/
	HashTableEntry** ht; /*!< The HashTable Array*/
	int hashFunc(std::string key); /*!< The hash function for hash table*/
	/*!< The insert function used by resize to move entries around*/
	void insert(HashTableEntry* ht);

public:
	HashTable(); /*!< The constructor of the Hash Table*/
	~HashTable(); /*!< The destructor of the Hash Table*/
	int getTS(); /*!< Gets tableSize value and returns it*/
	/*!< Inserts key and string into the Hash Table*/
	void insert(std::string k, std::string v);
	void remove(std::string k); /*!< Removes string by provided key value*/
	void searchKey(std::string k); /*!< Searches for key in table*/
	void resize(int tableSize); /*!< Sets tableSize value passed in*/
};
