//Initial_Profile.cpp
#include "Header.h"

/*Accepts index space and returns corresponding density*/
double InitDensity(double x){
    double density; if(x>0){density=0.125;} else {density=1;} return density;}

/*Accepts index space and returns corresponding velocity*/
double InitVelocity(double x){return 0.;}

/*Accepts index space and returns corresponding pressure*/
double InitPressure(double x){
    double Pres; if(x>0){Pres=0.1;}else{Pres=1.;} return Pres;}

/*Initializes the old solution array with the initial flow conditions*/
void FlowInit(){double x; double v;for(int i = 0; i<sdom; i++){
    x = i2x(i); v = InitVelocity(x);
    rhoOld[i] = InitDensity(x); rhoVOld[i] = rhoOld[i]*v;
    ElOld[i] = InitPressure(x)/(gam-1.) + 0.5*rhoVOld[i]*v;} return;}

