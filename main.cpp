#include "cpu.cpp"
#include "alu.cpp"

int main(){

	CPU cpu;
	//ControlUnit cu;
	cpu.cu.store(6, 4);
	cpu.cu.store(7, 9);
	cpu.cu.print();
	const int size = 4;
	int array[size] = {5479};
	cpu.load(array, size);
	cpu.cu.fetch();
	cpu.cu.print();
	cpu.cu.decode();
	cpu.cu.operand_fetch();

	ALU alu;

	int firstOp, secOp, opCode, address;
	firstOp = cpu.cu.first_operand;
	secOp = cpu.cu.sec_operand;
	opCode = cpu.cu.op_code;
	address = cpu.cu.res_address;
	std::cout << "******************"  << '\n';
	alu.execute(opCode, firstOp, secOp, address);
	return 0;

}
