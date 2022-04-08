//Flux.cpp
#include "Header.h"

/*Gives back the absolute value of some number*/
double AbsVal(double val){return pow(pow(val,2.) + pow(epsilon_fix,2.),0.5);}

/*Gives back either just positive or negative value, 1 for positive return, 0 for negative*/
double PNVal(int option, double val){
    return 0.5*(val + option*AbsVal(val) - (1-option)*AbsVal(val));}

#if 0
    /*Computes First Element of Flux Vector*/
    Flux1[i] = rho[i]*(2.*lambda_1*(gam - 1.) + lambda_2 + lambda_3)/(2.*gam);
    /*Computes Second Element of Flux Vector*/
    Flux2[i] = rho[i]*(lambda_1*(gam - 1.)*2.*Ve[i] + lambda_2*(a_s[i] + Ve[i]) 
        + lambda_3*(-a_s[i] + Ve[i]))/(2.*gam);
    /*Computes Third Element of Flux Vector*/
    Flux3[i] = rho[i]*(lambda_1*(2.*pow(gam,2.)*pow(Ve[i],2.) - 4.*gam*pow(Ve[i],2.) 
        + 2.*pow(Ve[i],2.)) + lambda_2*(2.*pow(a_s[i],2.) + 2.*a_s[i]*gam*Ve[i] 
        - 2.*a_s[i]*Ve[i] + gam*pow(Ve[i],2.) - pow(Ve[i],2.)) + lambda_3*(2.*pow(a_s[i],2.) 
        - 2.*a_s[i]*gam*Ve[i] + 2.*a_s[i]*Ve[i] + pow(gam*Ve[i],2.) 
        - pow(Ve[i],2.)))/(4.*gam*(gam - 1.));} 
#endif


/*Compute the Flux arrays, 1 for positive flux, 0 for negative flux*/
void CompFluxes(int option){
    //Local Variables not Tampered anywhere
    double lambda_1; double lambda_2; double lambda_3;
    for(int i = 0; i<sdom; i++){
    /*Compute the eigenvalues*/
    lambda_1 = PNVal(option, Ve[i]); 
    lambda_2 = PNVal(option, Ve[i]+a_s[i]);
    lambda_3 = PNVal(option, Ve[i]-a_s[i]);
    /*Computes First Element of Flux Vector*/
    Flux1[i] = rho[i]*(lambda_1*(2.*gam - 2.) + lambda_2 + lambda_3)/(2.*gam);
    /*Computes Second Element of Flux Vector*/
    Flux2[i] = rho[i]*(lambda_1*(2.*Ve[i]*gam - 2.*Ve[i]) 
            + lambda_2*(Ve[i] + a_s[i]) + lambda_3*(Ve[i] - a_s[i]))/(2.*gam);
    /*Computes Third Element of Flux Vector*/
    Flux3[i] = rho[i]*(lambda_1*(2.*pow(Ve[i],2.)*pow(gam,2.) - 4.*pow(Ve[i],2.)*gam + 2.*pow(Ve[i],2.)) + lambda_2*(pow(Ve[i],2.)*gam - pow(Ve[i],2.) + 2.*Ve[i]*a_s[i]*gam - 2.*Ve[i]*a_s[i] + 2.*pow(a_s[i],2.)) + lambda_3*(pow(Ve[i],2.)*gam - pow(Ve[i],2.) - 2.*Ve[i]*a_s[i]*gam + 2.*Ve[i]*a_s[i] + 2.*pow(a_s[i],2.)))/(4.*gam*(gam - 1.));
    } return;}


#if 0
    Flux3[i] = rho[i]*(lambda_1*(2.*Ve[i]**2.*gam**2. - 4.*Ve[i]**2.*gam + 2.*Ve[i]**2.) + lambda_2*(Ve[i]**2.*gam - Ve[i]**2. + 2.*Ve[i]*a_s[i]*gam - 2.*Ve[i]*a_s[i] + 2.*a_s[i]**2.) + lambda_3*(Ve[i]**2.*gam - Ve[i]**2. - 2.*Ve[i]*a_s[i]*gam + 2.*Ve[i]*a_s[i] + 2.*a_s[i]**2.))/(4.*gam*(gam - 1.))
#endif

