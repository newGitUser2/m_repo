#include <iostream>
#include <cstdlib>
#include "ram.cpp"
#include "reg.cpp"

#pragma once

class ControlUnit{

	public:
	int op_code, res_address = 0;
	int first_operand, sec_operand = 0;	
	int pc_value;
	Ram ram;
	RegFile reg;

	void store(int address, int data){
		if(address > ram.get_size()){
			std::cout << "The address is larger than the\
					memory size.";
			exit(1);
		}
		else
			ram.write(address, data);
	}

	/*As a result of the method it turns out:
	 * reg[0]-PC, reg[1]-MAR, reg[2]-MDR.  */ 
	void fetch(){
		reg.write(0, 0);
		reg.write(1, reg.read(0));
		int mar_value = reg.read(1);
		int instruction = ram.read(mar_value);
		reg.write(2, instruction);
		//reg.write(0, 1);//increment PC

	}
	//As a result of the method: reg[3]-op_code.
	void decode(){
		pc_value = reg.read(0);
		reg.write(3, (ram.read(pc_value) >> 12 & 0xF));
		op_code = reg.read(3);
	}

	void operand_fetch(){
		int first_op_address = reg.read(2) >> 4 & 0xF;
		int sec_op_address = reg.read(2) & 0xF;
		res_address = reg.read(2) >> 8 & 0xF;
		reg.write(1, first_op_address);
		reg.write(2, ram.read(first_op_address));
		first_operand = reg.read(2);
		reg.write(1, sec_op_address);
		reg.write(2, ram.read(sec_op_address));
		sec_operand = reg.read(2);
		reg.write(3, ++pc_value);

	}


/*	void print(){
		std::cout << "ram elems: ";
		for(int i = 0; i < ram.get_size(); i++){
				std::cout << ram.read(i) << " ";
		}
		std::cout << '\n' << "reg elems: ";
	       	for(int i = 0; i < reg.get_size(); i++){
				std::cout << reg.read(i) << " ";
		}
		std::cout << std::endl;	
	}
*/

};
