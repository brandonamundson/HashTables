/*************************************************************************/ /**
 * @file
 *****************************************************************************/
#include "HashTable.h"


/**************************************************************************/ /**
 * @author Brandon Amundson
 *
 * @par Description:
 * This function creates the HashTable by initializing all of ht array values
 * to nullptr
 *****************************************************************************/
HashTable::HashTable()
{
	// create new hash table as array of entries at tablesize
	ht = new HashTableEntry*[tableSize];
	// for all values in array, init to nullptr
	for (int i = 0; i < tableSize; i++)
		ht[i] = nullptr;
}

/**************************************************************************/ /**
 * @author Brandon Amundson
 *
 * @par Description:
 * This function destroys the HashTable by deleting the values of the ht array
 *****************************************************************************/
HashTable::~HashTable()
{
	delete[] ht; // delete all array values of ht
}

/**************************************************************************/ /**
 * @author Brandon Amundson
 *
 * @par Description:
 * This function gets the Table Size and returns it to user
 *****************************************************************************/
int HashTable::getTS()
{
	return this->tableSize;
}

/**************************************************************************/ /**
 * @author Brandon Amundson
 *
 * @par Description:
 * This function resets the table size and rearranges keys as necessary
 *****************************************************************************/
void HashTable::resize(int tableSize)
{
	int curr = this->tableSize;
	this->tableSize = tableSize;

	if (curr < tableSize) // if current table is smaller than new
	{
		// add values from current to new size
		for (int i = curr; i < tableSize; i++)
			ht[i] = nullptr;
	}
	// start from beginning and rehash current values
	for (int i = 0; i < curr; i++)
	{
		HashTableEntry* entry = ht[i]; // create an entry point
		bool repeat = false; // will be used to check for repeated values
		// will hold values already reinserted in list
		std::list<HashTableEntry*> entries;

		// while we are not at end of list and do not have repeats
		while (entry != nullptr && !repeat)
		{
			if (entry->next != nullptr) // if there is a chain
				ht[i] = entry->next; // move it to the front
			insert(entry); // insert the item
			entries.emplace_back(entry); // add entry to list
			// iterate list
			for (auto it = entries.begin(); it != entries.end(); ++it)
				// if value in list matches value at beginning of chain
				if (*it == ht[i])
					repeat = true; // it is a repeat, need to break loop
		}
	}
	if (tableSize > curr)
	{
		// start at end of table and if values exist in nodes, rehash and
		// insert them then delete the node.
		for (int i = curr - 1; i > tableSize; i--)
		{
			if (ht[i] != nullptr) // if there is a value
			{
				// reinsert the beginning value as it is, chain will remain
				// intact per implementation of overloaded insert function
				insert(ht[i]);
			}
			// once reinserted, value may be deleted
			delete ht[i];
		}
	}
}

/**************************************************************************/ /**
 * @author Brandon Amundson
 *
 * @par Description:
 * This function hashes key value by taking the ascii value of each char in key
 * and adding them together, then modding it against the table size.
 *****************************************************************************/
int HashTable::hashFunc(std::string key)
{
	int hash = 0;

	for (char i : key)
	{
		hash += static_cast<int>(i);
	}
	return (hash % tableSize);
}

/**************************************************************************/ /**
 * @author Brandon Amundson
 *
 * @par Description:
 * This function is used by the resize function to readjust entries locations
 * in the list
 *****************************************************************************/
void HashTable::insert(HashTableEntry* ht)
{
	int hash_v = hashFunc(ht->k); // get hash value of key
	// entry point is hashed location of ht->k
	HashTableEntry* entry = this->ht[hash_v];
	HashTableEntry* prev = nullptr; // set prev to nullptr

	if (entry == nullptr) // if entry is null, first in list
	{
		entry = ht; // set entry to passed in value
		this->ht[hash_v] = entry; // assign to element location in ht
	}
	else // else we are chaining
	{
		while (entry != nullptr) // while entry is not empty
		{
			prev = entry; // previous key is entry
			entry = entry->next; // entry is entry->next
		}
		entry = ht; // set entry to passed in value
		prev->next = entry; // point previous to this entry
	}
}

/**************************************************************************/ /**
 * @author Brandon Amundson
 *
 * @par Description:
 * This function inserts key and string into list after hashing key.
 *****************************************************************************/
void HashTable::insert(std::string k, std::string v)
{
	int hash_v = hashFunc(k); // get hash value of key
	HashTableEntry* prev = nullptr; // set prev to nullptr
	HashTableEntry* entry = ht[hash_v]; // entry point is hashed location of ht

	if (entry == nullptr) // if entry is null, first in list
	{
		entry = new HashTableEntry(k, v); // create new table entry
		ht[hash_v] = entry; // insert entry at hash value
	}
	else // else we are chaining
	{
		while (entry != nullptr) // while entry is not empty
		{
			prev = entry; // previous key is entry
			entry = entry->next; // entry is entry->next
		}
		// once entry hits end of list, create new hash table entry
		entry = new HashTableEntry(k, v);
		prev->next = entry; // point previous to new table entry
	}
}

/**************************************************************************/ /**
 * @author Brandon Amundson
 *
 * @par Description:
 * This function creates the list by setting the root of the Tree to nullptr
 *****************************************************************************/
void HashTable::searchKey(std::string k)
{
	int hash_v = hashFunc(k);
	bool flag = false;
	HashTableEntry* entry = ht[hash_v];

	if (entry != nullptr)
	{
		while (entry != nullptr)
		{
			if (entry->k == k)
				flag = true;
			if (flag)
			{
				std::cout << "Element found at key " << k << ": ";
				std::cout << entry->v << std::endl;
			}
			entry = entry->next;
		}
	}
	if (!flag)
		std::cout << "Element not found with key " << k << std::endl;
}

/**************************************************************************/ /**
 * @author Brandon Amundson
 *
 * @par Description:
 * This function removes item from table with specific key value
 *****************************************************************************/
void HashTable::remove(std::string k)
{
	int hash_v = hashFunc(k); // hash key for entrypoint
	// create entry pointer and previous pointer
	HashTableEntry *entry = ht[hash_v], *prev = nullptr;

	// check k value matches what we are looking for
	// then traverse chain while not at end of chain
	while (k != entry->k && entry != nullptr)
	{
		prev = entry;
		entry = entry->next;
	}
	if (entry == nullptr) // if we reached the end, we found nothing
	{
		std::cout << "\nUnable to find element " << k << ".  Nothing deleted.";
		return;
	}
	// if there is a value after the one we want
	// and we moved down a chain
	if (entry->next != nullptr && prev != nullptr)
		prev->next = entry->next; // point the previous one to it
	delete entry; // delete the entry we need
}
