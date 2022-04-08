//Vars.cpp
#include "Header.h"

//The spatial dimensions of the simulation
double XB[2];

//How long the simulation is supposed to last
double TB[2];

//Infinitesmially small space
double dx;

//Infinitesmially small time
double dt;

//Obscure name for dt/dx. This is supposed to be CFL-like
double lkm;

//Represents the size of the number of nodes in the computational domain
int sdom;

//Represents how many time iterations
int TIter;

//is going to be an array that holds the density for the entire computational domain, size sdom
double *rhoOld; 

//is going to be an array that holds the product of density and fluid velocity, size sdom 
double *rhoVOld; 

//Represents last element of the solution vector, size sdom 
double *ElOld;

//Density of the fluid for new time step
double *rhoNew;

//Density Velocity product of fluid new time step
double *rhoVNew;

//"Energy" of fluid in new time step
double *ElNew;

//Fluid Density array
double *rho;

//Fluid Velocity array
double *Ve;

//Pressure array
double *Pr;

//Speed of Sound array
double *a_s;

//Flux first solution vector
double *Flux1;

//Flux second solution vector
double *Flux2;

//Flux third solution vector
double *Flux3;

//Ratio of Specific heats
double gam;

//Safety Factor
double SF;

//Initializes basic variables
void Initialize(){
//Flow Parameters
gam = 1.4;
//Safety Factor
SF = 0.1;
//Spatial and Time Iteration Number
sdom = 1001; TIter = 3000;
//Spatial and Time dimensions of simulation
XB[0] = -5.; XB[1] = 5.; TB[0] = 0.; TB[1] = 0.9;
//Infinitesmially small distance and time
dx = (XB[1]-XB[0])/(sdom-1); 
dt = (TB[1]-TB[0])/TIter;
lkm = dt/dx;
return;}
