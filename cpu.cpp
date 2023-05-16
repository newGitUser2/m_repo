#include "cu.cpp"

class CPU{

	public:
	ControlUnit cu;

	void load(int *inst_array, int size){
		for(int i  = 0; i < size; i++){
			if(inst_array[i] != 0 &&
				i <= cu.ram.get_size()){
				cu.ram.write(i, inst_array[i]);
			}
		}
	}

};
