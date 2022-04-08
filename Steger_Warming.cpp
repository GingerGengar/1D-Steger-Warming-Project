//Steger_Warming.cpp
#include "Header.h"

/*Update Flow Conditions Based on New Solution*/
void FlowCondNew(){
    FluidDensity(rhoNew);
    FluidVelocity(rhoVNew); 
    FluidPressure(rhoVNew, ElNew); 
    FlSpeeda(); return;}

/*Update Flow Conditions based on Old Solution*/
void FlowCondOld(){
    FluidDensity(rhoOld);
    FluidVelocity(rhoVOld); 
    FluidPressure(rhoVOld, ElOld); 
    FlSpeeda();return;}

/*Updates the Solution Vector, Leaves the Boundaries ALONE, 0 for +, 1 for -*/
void AppFlux(int option){for(int i = 1; i<sdom-1; i++){
    rhoNew[i] = rhoNew[i] - lkm*(Flux1[i+option]-Flux1[i-1+option]);
    rhoVNew[i] = rhoVNew[i] - lkm*(Flux2[i+option]-Flux2[i-1+option]);
    ElNew[i] = ElNew[i] - lkm*(Flux3[i+option]-Flux3[i-1+option]);
    }return;}

/*Searches the maximum value over the computational domain size*/
double MaxVal(double *arr){double current; double maximum = 0; for(int i=0;i<sdom;i++){
    current = fabs(arr[i]); if (current>maximum){maximum = current;}}return maximum;}

/*Computes the Time step based on fluid state*/
void TimeStep(){
    double current; double maxu = 0; double maxa = 0;
    maxu = MaxVal(Ve); maxa = MaxVal(a_s);
    dt = SF*dx/(maxa + maxu); return;}

/*Hosts the Time Loop, makes call to other high level functions*/
void Simulate(){for(int i = 0; i < TIter; i++){
    //Update Flow Conditions Based on Old Solution
    FlowCondOld(); 
    //Compute the time step
    TimeStep();
    //Update CFL-Like Number
    lkm = dt/dx;
    //Apply Boundary Condition
    AppBC();
    //Construct First Term
    Equate(rhoNew, rhoOld, 1, sdom-2);
    Equate(rhoVNew, rhoVOld, 1, sdom-2);
    Equate(ElNew, ElOld, 1, sdom-2);
    //Compute the + Fluxes
    CompFluxes(1);
    //Apply Positive Fluxes
    AppFlux(0);
    //Compute the - Fluxes
    CompFluxes(0);
    //Apply Negative Fluxes
    AppFlux(1);
    //Print Old Solution 
    PrintFlowPrimitive();
    //Advance by copying solutions
    Equate(rhoOld, rhoNew, 0, sdom);
    Equate(rhoVOld, rhoVNew, 0, sdom);
    Equate(ElOld, ElNew, 0, sdom);
    } return;}
