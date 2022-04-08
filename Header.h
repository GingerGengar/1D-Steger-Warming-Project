//Include guards
#ifndef Thunder
#define Thunder

//Library Includes
#include <iostream>
#include <fstream>
#include <math.h>

//Small number for shifting the mod function
#define epsilon_fix 1e-6

//Definition of variables
extern double XB[2];
extern double TB[2];
extern double dx;
extern double dt;
extern double lkm;
extern int sdom;
extern int TIter;
extern double *rhoOld; 
extern double *rhoVOld; 
extern double *ElOld;
extern double *rhoNew;
extern double *rhoVNew;
extern double *ElNew;
extern double *rho;
extern double *Ve;
extern double *Pr;
extern double *a_s;
extern double *Flux1;
extern double *Flux2;
extern double *Flux3;
extern double gam;
extern double R;
extern double SF;

//Function Prototypes
//In Vars.cpp
void Initialize();
//In Memory_allocate.cpp
void MemAllocate();
void MemDeAlloc();
//In Bound_Cond.cpp
void AppBC();
//In Initial_Profile.cpp
double InitDensity(double x);
double InitVelocity(double x);
double InitPressure(double x);
void FlowInit();
//In Flux.cpp
double AbsVal(double val);
double PNVal(int option, double val);
void CompFluxes(int option);
//In Mappings.cpp
int x2i(double x);
double i2x(int i);
void Equate(double *trg, double *ref, int start, int stop);
void FluidDensity(double *rhoinput);
void FluidVelocity(double *rho, double *rhoV);
void FluidPressure(double *rho, double *rhoV, double *E);
void FlSpeeda(double *rho);
//In Steger_Warming.cpp
void FlowCondNew();
void AppFlux(int option);
void Simulate();
//In IO.cpp
void SetupFileFormat(std::ofstream *SolutionFPointer);
void SetupFileNames();
void SetupFile();
void CloseFiles();
void PrintArr(int size, double *arr, std::ofstream *Channel);
void ParamOut();
void PrintFlowPrimitive();
void PrintGridCoords();

#endif
