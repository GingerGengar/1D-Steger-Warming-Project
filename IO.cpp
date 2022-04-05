//IO.cpp
#include "Header.h"

/*File pointer to spatial x*/
std::ofstream XWrite;

/*File pointer to density*/
std::ofstream RhoWrite;

/*File pointer to fluid velocity*/
std::ofstream VelWrite;

/*File pointer to fluid Pressure*/
std::ofstream PresWrite;

/*File pointer to Parameters*/
std::ofstream ParWrite;

/*Makes the file pointer output in terms of scientific notation*/
void SetupFileFormat(std::ofstream *SolutionFPointer){
    SolutionFPointer[0].setf(std::ios_base::left, std::ios_base::adjustfield);
    SolutionFPointer[0].setf(std::ios_base::scientific, std::ios_base::floatfield);return;}

/*Prepare File Output Names*/
void SetupFileNames(){XWrite.open("XDimensions.dat"); RhoWrite.open("Density.dat");
    VelWrite.open("Velocity.dat"); PresWrite.open("Pressure.dat"); 
    ParWrite.open("Parameters.dat"); return;}

/*Prepares the various output channels of the program*/
void SetupFile(){
    SetupFileFormat(&XWrite); SetupFileFormat(&RhoWrite); SetupFileFormat(&VelWrite);
    SetupFileFormat(&PresWrite); SetupFileNames();return;}

/*Close Files*/
void CloseFiles(){
    XWrite.close(); RhoWrite.close(); VelWrite.close(); PresWrite.close(); 
    ParWrite.close(); return;}

/*Prints a variable sized array*/
void PrintArr(int size, double *arr, std::ofstream *Channel){
    for(int i = 0; i < size; i++){Channel[0] << arr[i] << " ";} Channel[0] << std::endl; return;}

/*Prints Problem Parameters*/
void ParamOut(){
    ParWrite << "#Specific Heat Ratio gamma" << std::endl << gam << std::endl;
    ParWrite << "#Lower Bound Spatial Dimension" << std::endl << XB[0] << std::endl;
    ParWrite << "#Upper Bound Spatial Dimension" << std::endl << XB[1] << std::endl;
    ParWrite << "#Start Time of Simulation" << std::endl << TB[0] << std::endl;
    ParWrite << "#End Time of Simulation" << std::endl << TB[1] << std::endl;
    ParWrite << "#Number of Spatial Partitions" << std::endl << sdom << std::endl;
    ParWrite << "#Number of Time Iterations" << std::endl << TIter << std::endl;
    ParWrite << "#size of dx" << std::endl << dx << std::endl;
    ParWrite << "#size of dt" << std::endl << dt << std::endl;
    //ParWrite << "#" << std::endl << << std::endl;
    return; }

/*Prints Flow Conditions*/
void PrintFlowPrimitive(){
    PrintArr(sdom, rho, &RhoWrite);
    PrintArr(sdom, Ve, &VelWrite);
    PrintArr(sdom, Pr, &PresWrite); return;}


#if 0
int main(void){
SetupFile();
RhoWrite << 123.4124;
CloseFiles();
return 0;}
#endif

