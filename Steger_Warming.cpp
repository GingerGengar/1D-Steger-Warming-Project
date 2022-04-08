//Steger_Warming.cpp
#include "Header.h"


/*Update Flow Conditions Based on New Solution*/
void FlowCondNew(){
    FluidDensity(rhoNew);
    FluidVelocity(rhoNew, rhoVNew); 
    FluidPressure(rhoNew, rhoVNew, ElNew); 
    FlSpeeda(rhoNew); return;}

/*Update Flow Conditions based on Old Solution*/
void FlowCondOld(){
    FluidDensity(rhoOld);
    FluidVelocity(rhoOld, rhoVOld); 
    FluidPressure(rhoOld, rhoVOld, ElOld); 
    FlSpeeda(rhoOld);return;}

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
    dt = SF*dx/(maxa + maxu); std::cout << "dt: " << dt << std::endl; return;}

#ifdef DEBUG 
#include <iomanip>
#endif
#ifdef DEBUG
int low = 497; int higher = 506;
int wi = 15;
/*Prints Bounds of Debug*/
void BoundPrint(){
std::cout.setf(std::ios_base::left, std::ios_base::adjustfield);
std::cout.setf(std::ios_base::scientific, std::ios_base::floatfield);
std::cout << "Element: ";
for(int i = low; i< higher; i++){std::cout << i << "," << "             ";} std::cout << std::endl; 
std::cout << "Spatial:";
for(int i = low; i< higher; i++){std::cout << " " << std::setw(wi) << i2x(i) << ",";} std::cout << std::endl; 

return;}

/*Prints the primitive flow array for the bounds*/
void PrintPrimitiveDebug(){
std::cout << "Density:";
for(int i = low; i< higher; i++){std::cout << " " << std::setw(wi) << rho[i] << ",";} std::cout << std::endl;
std::cout << "Velocit:";
for(int i = low; i< higher; i++){std::cout << " " << std::setw(wi) << Ve[i] << ",";} std::cout << std::endl;
std::cout << "Pressur:";
for(int i = low; i< higher; i++){std::cout << " " << std::setw(wi) << Pr[i] << ",";} std::cout << std::endl;
std::cout << "SoundSp:";
for(int i = low; i< higher; i++){std::cout << " " << std::setw(wi) << a_s[i] << ",";} std::cout << std::endl;
return;}


/*Prints the Fluxes array*/
void PrintFluxDebug(){
std::cout << "Flux_01:";
for(int i = low; i< higher; i++){std::cout << " " << std::setw(wi) << Flux1[i] << ",";} std::cout << std::endl;
std::cout << "Flux_02:";
for(int i = low; i< higher; i++){std::cout << " " << std::setw(wi) << Flux2[i] << ",";} std::cout << std::endl;
std::cout << "Flux_03:";
for(int i = low; i< higher; i++){std::cout << " " << std::setw(wi) << Flux3[i] << ",";} std::cout << std::endl;
return;}

#endif

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
    
#ifdef DEBUG
    TIter = 5;
    //std::cout << PNVal(1, -3.) << std::endl; //This works, PNVal is verified to work correctly
    std::cout << "Iteration: " << i << std::endl;
    BoundPrint(); //Print Bounds of Debug mode
    PrintPrimitiveDebug(); //Prints the primitive flow variables
#endif

    //Construct First Term
    Equate(rhoNew, rhoOld, 1, sdom-2);
    Equate(rhoVNew, rhoVOld, 1, sdom-2);
    Equate(ElNew, ElOld, 1, sdom-2);
    //Compute the + Fluxes
    CompFluxes(1);

#ifdef DEBUG
    std::cout << "Positive Fluxes" << std::endl;
    PrintFluxDebug();
#endif

    //Apply Positive Fluxes
    AppFlux(0);
    //Compute the - Fluxes
    CompFluxes(0);

#ifdef DEBUG
    std::cout << "Negative Fluxes" << std::endl;
    PrintFluxDebug();
#endif

    //Apply Negative Fluxes
    AppFlux(1);

#ifdef DEBUG
    std::cout << std::endl;
#endif

    //Print Old Solution 
    PrintFlowPrimitive();
    //Advance by copying solutions
    Equate(rhoOld, rhoNew, 0, sdom);
    Equate(rhoVOld, rhoVNew, 0, sdom);
    Equate(ElOld, ElNew, 0, sdom);
    } return;}
