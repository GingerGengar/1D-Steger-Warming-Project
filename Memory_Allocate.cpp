//Memory_Allocate.cpp
#include "Header.h"

/*Allocates Memory for the various array pointers*/
void MemAllocate(){
    rhoOld = new double [sdom]; rhoVOld = new double [sdom]; ElOld = new double [sdom]; 
    rhoNew = new double [sdom]; rhoVNew = new double [sdom];ElNew = new double [sdom];
    Flux1 = new double [sdom]; Flux2 = new double [sdom]; Flux3 = new double [sdom]; 
    rho = new double [sdom]; Ve = new double [sdom]; Pr = new double [sdom]; 
    a_s = new double [sdom];}

/*De-allocates Memory for the various array pointers*/
void MemDeAlloc(){
    delete [] rhoOld; delete [] rhoVOld; delete [] ElOld;
    delete [] rhoNew; delete [] rhoVNew; delete [] ElNew;
    delete [] Flux1; delete [] Flux2; delete [] Flux3; 
    delete [] rho; delete [] Ve; delete [] Pr; delete [] a_s;}
