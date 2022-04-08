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

//Prepare Output channels
SetupFile();

//Write the Parameters of Program
ParamOut();

//Begin Simulation
Simulate();

//Write out Final Fluid Profile
FlowCondNew();
PrintFlowPrimitive();

//Write Dimensions of Problem
PrintGridCoords();

//Close File channels
CloseFiles();

//Deallocate Memory from solution pointers
MemDeAlloc();

return 0;}
