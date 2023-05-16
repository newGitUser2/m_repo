#include "cu.cpp"

class ALU{

	public:
	ControlUnit cu;

	void execute(int op_code, int first_op, 
			int sec_op,int address){
		int result = 0;
		switch(op_code){
			case 1:
				result = first_op + sec_op;
				break;
			case 2:
				result = (first_op > sec_op) ? (first_op - 
					sec_op) : (sec_op - first_op);
				break;
			case 3:
				result = first_op * sec_op;
				break;
			default:
				std::cout << "Choice other than 1, 2 and 3";
				break;	
		}
		cu.ram.write(address, result);
	}
};
