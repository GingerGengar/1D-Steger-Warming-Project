//Mappings.cpp
#include "Header.h"

/*Maps spatial space into index space using dx*/
int x2i(double x){return (int)(x-XB[0])/dx;}

/*Maps index space into spatial space using dx*/
double i2x(int i){return i*dx + XB[0];}

/*Equates the elements of 2 possibly different sized arrays together*/
void Equate(double *trg, double *ref, int start, int stop){
    for(int i = 0; i < stop; i++){trg[start+i] = ref[start+i];}}

/*Please Rememeber, these functions are dependent on each other. The Pressure function needs the Fluid Velocity function to run first to update the velocities correctly, Likewise the pressure function needs to be run before the speed of sound can be correctly computed*/

/*Sets the rho array to the correct one*/
void FluidDensity(double *rhoinput){Equate(rho, rhoinput, 0, sdom); return;}

/*Takes in rho array and rhoV array and computes Velocity array*/
void FluidVelocity(double *rhoV){
    for(int i = 0; i<sdom; i++){Ve[i] = rhoV[i]/rho[i];} return;}

/*Takes in full solution vector, and computes the pressure array*/
void FluidPressure(double *rhoV, double *E){
for(int i = 0; i<sdom; i++){Pr[i] = (gam-1.)*(E[i] - 0.5*rhoV[i]*Ve[i]);} return;}

/*Computes the Sound speed of the fluid*/
void FlSpeeda(){
    for(int i = 0; i<sdom; i++){a_s[i] = pow(gam*Pr[i]/rho[i],0.5);} return;}
