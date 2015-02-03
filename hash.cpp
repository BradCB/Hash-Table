//Brad Bolton A01383991
//This file contains the function implementations of the hash table

#include<iostream>
#include<string>
#include "hash.h"

//-------Hash Table Constructor
//This function creates a tablesized hash table with a
//Node at each index
hash::hash()
{
	for(int i = 0; i < tableSize; i++)		
	{
		HashTable[i] = new item;		//create a new node item
		HashTable[i]->word ="empty";	//set the word to a place holder
		HashTable[i]->next = NULL;		//set its next node to null
		HashTable[i]->count = 0;		
	}
}
//-------Hash Function
//This function takes a string word and for its lenght 
//casts it into an int and the sum of all the chars is moded by
//the table size to create its hash table id and returns it.
int hash::hashFunct(std::string word)
{
	int hash =0;
	int hashId;
	for(int y=0; y< word.length(); y++)	//loop through chars of string and sum them
	{
		hash = (hash + (int)word[y]);
	}
	hashId =hash % tableSize;			//Take the sum of the string and mod it by the table size
	return hashId;
}
//-------Add fuction
//This function takes the passed in word, calls hashFunct to generate its index in the hash table
//it then checks if the first node is empty, then checks if it is eaqual to a word already in the link list and 
//incremnets cout if it is found. If the word is not in the list, it adds a new node to the list
void hash::addItem(std::string word)
{
	int index = hashFunct(word);		//call hash function to get index
	if(HashTable[index]->word=="empty") //If hash index points to an empty list head
	{
		HashTable[index]->word = word; //Set head of empty list to word
		HashTable[index]->count = 1; //Set count to 1
	}
	else
	{
		item* ptr = HashTable[index];	//ptr to item at current index of hash table
		if(ptr->word == word)			//If the pointer is pointing to a word that is equal to the word past in
		{
			ptr->count++;				//Increment count for that word
			return;
		}
		
		while(ptr->next != NULL)		//While the pointers next is not null change current pointer to it
		{
			ptr = ptr->next;	
			if(ptr->word == word)		//If the word is equal to the word incrment count and return
			{
				ptr->count++;
				return;
			}
		}
		item* newPtr = new item;				//If ptr is poining to a null node, create a new node
		newPtr->word = word;					//Set the new node newPtr is pointing to to word and set count to 1
		newPtr->next = NULL;
		newPtr->count = 1;					
		ptr->next = newPtr;
	}
}
//-------Print Function
//This function prints the contents of the link list with the number of occurrences of the word
void hash::print()
{
	int num;
	std::string temp, temp2;
	for(int i = 0; i< tableSize; i++)
	{
	item* ptr = HashTable[i];
	//std::cout<<"BUCKET INDEX = "<<i<<"-----------"<<std::endl;
	if(ptr->word !="empty")
	{
		while(ptr!= NULL)
		{
			
			std::cout<<ptr->word<<" "<<ptr->count<<std::endl;
			ptr = ptr->next;
			}	
		}
		}
	
}