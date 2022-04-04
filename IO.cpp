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
void PrintArr(int size, double *arr, std::ofstream Channel){
    for(int i = 0; i < size; i++){Channel << arr[i] << " ";} Channel << std::endl; return;}

/*Prints Problem Parameters*/
void ParamOut(){
    //ParWrite << "#" << std::endl;
    //ParWrite << stime << " " << dt;
    return; }

#if 0
int main(void){
SetupFile();
RhoWrite << 123.4124;
CloseFiles();
return 0;}
#endif

