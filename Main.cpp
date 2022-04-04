//Main.cpp
#include "Header.h"

//Entry Point of the program
int main(void){

//Initializes common flow parameters
Initialize();

//Allocate Memory to solution pointers
MemAllocate();

//Initializes Flow Profile
FlowInit();

//Write out Initialized Flow Profile

//Write the Parameters of Program
ParamOut();

//Begin Simulation
Simulate();

//Deallocate Memory from solution pointers
MemDeAlloc();

return 0;}
