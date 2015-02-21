//Brad Bolton 
//This program opens the text file input and each word is passed to the addItem function
//After all the words have been added the program calls the hash tables print function and
//displays each word and its frequency

#include<iostream>
#include<string>
#include<vector>
#include "hash.h"
#include<fstream>

int main(){



	hash hashObj;
	std::string word;
	std::ifstream file;

	file.open("input.txt"); //open file
	if(file.is_open())
	{
		while(!file.eof()) //while there are words to read, pass each word to the additem function
		{
			file>>word;
			hashObj.addItem(word);
		}
		file.close();          
	}
	else
	{
		std::cout<<"ERROR FILE NOT FOUND"<<std::endl;
	}
	hashObj.print(); //This function prints each word and its frequency in the text file

	return 0;
}
