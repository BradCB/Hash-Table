
//This program is the header file for the hash table class
#include<iostream>
#include<string>


#ifndef HASH_H
#define HASH_H


class hash
{
private:
	static const int  tableSize = 128;

	struct item                 //Word node with its count and a pointer to next
	{
		std::string word;
		int count;
		item*next;
		item(){
			count=0;
		}
	};

	item* HashTable[tableSize]; 

public: 
	hash();
	
	int hashFunct(std::string word);
	void addItem(std::string);
	void print();
	
};

#endif
