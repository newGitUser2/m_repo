#include <iostream>
#include <cassert>

#pragma once

class RegFile{

	private:
	int size;
	int * array;

	public:
	RegFile(int s = 10){
		size = 10;
		array = new int[size];
	}

	int get_size(){
		return size;
	}

	void write(int address, int data){
		try{
			if(address > size)
				throw "Enter a number smaller\
					than the memory size!";
			array[address] = data;
		}
		catch(const char* exception){
			std::cerr << "Error: " << exception << '\n';
		}
	}

	int read(int address){
		assert(address <= size && "The address value should not be\
				larger than the memory size!");
		return array[address];
	}	
};
