/*************************************************************************/ /**
 * @file
 *****************************************************************************/
#include "HashTable.h"

/**************************************************************************/ /**
 * @author Brandon Amundson
 *
 * @par Description:
 * This function creates the list by setting the root of the Tree to nullptr
 *
 *****************************************************************************/
HashTable::HashTable()
{
	ht = new HashTableEntry*[tableSize];
	for (int i = 0; i < tableSize; i++)
		ht[i] = nullptr;
	top = nullptr;
}

/**************************************************************************/ /**
 * @author Brandon Amundson
 *
 * @par Description:
 * This function creates the list by setting the root of the Tree to nullptr
 *
 *****************************************************************************/
HashTable::~HashTable()
{
	delete[] ht;
}

/**************************************************************************/ /**
 * @author Brandon Amundson
 *
 * @par Description:
 * This function creates the list by setting the root of the Tree to nullptr
 *
 *****************************************************************************/
int HashTable::getTS()
{
	return this->tableSize;
}

/**************************************************************************/ /**
 * @author Brandon Amundson
 *
 * @par Description:
 * This function creates the list by setting the root of the Tree to nullptr
 *
 *****************************************************************************/
void HashTable::setTS(int tableSize)
{
	this->tableSize = tableSize;
}

/**************************************************************************/ /**
 * @author Brandon Amundson
 *
 * @par Description:
 * This function creates the list by setting the root of the Tree to nullptr
 *
 *****************************************************************************/
int HashTable::hashFunc(int key)
{
	return (key % tableSize);
}

/**************************************************************************/ /**
 * @author Brandon Amundson
 *
 * @par Description:
 * This function creates the list by setting the root of the Tree to nullptr
 *
 *****************************************************************************/
void HashTable::insert(int k, string v)
{
	int hash_v = hashFunc(k);
	HashTableEntry* prev = nullptr;
	HashTableEntry* entry = ht[hash_v];

	while (entry != nullptr)
	{
		prev = entry;
		entry = entry->next;
	}
	if (entry == nullptr)
	{
		entry = new HashTableEntry(k, v);
		if (prev == nullptr)
			ht[hash_v] = entry;
		else
			prev->next = entry;
	}
	else
		entry->v = v;
}

/**************************************************************************/ /**
 * @author Brandon Amundson
 *
 * @par Description:
 * This function creates the list by setting the root of the Tree to nullptr
 *
 *****************************************************************************/
void HashTable::searchKey(int k)
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
				cout << "Element found at key " << k << ": ";
				cout << entry->v << endl;
			}
			entry = entry->next;
		}
	}
	if (!flag)
		cout << "Element not found with key " << k << endl;
}

/**************************************************************************/ /**
 * @author Brandon Amundson
 *
 * @par Description:
 * This function creates the list by setting the root of the Tree to nullptr
 *
 *****************************************************************************/
void HashTable::remove(int k)
{
	int hash_v = hashFunc(k);
	HashTableEntry *entry = ht[hash_v], *prev = nullptr;

	if (entry == nullptr || entry->k != k)
	{
		cout << "No element found at key " << k << endl;
		return;
	}
	while (entry->next != nullptr)
	{
		prev = entry;
		entry = entry->next;
	}
	if (prev != nullptr)
		prev->next = entry->next;
	delete entry;
	cout << "Element deleted" << endl;
}
