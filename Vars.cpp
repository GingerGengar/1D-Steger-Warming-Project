//Vars.cpp
#include "Header.h"

//Represents the size of the number of nodes in the computational domain
int sdom;

//is going to be an array that holds the density for the entire computational domain. It will be of size sdom
double *rhoOld; 

//is going to be an array that holds the product of density and fluid velocity. It will be of size sdom 
double *rhoVOld; 

//Represents last element of the solution vector. It will be of size sdom 
double *ElOld;

//Density of the fluid for new time step
double *rhoNew;

//Density Velocity product of fluid new time step
double *rhoVNew;

//"Energy" of fluid in new time step
double *ElNew;
