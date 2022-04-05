//Bound_Cond.cpp
#include "Header.h"

/*Apply Boundary Conditions to New Solution Vector*/
void AppBC(){rhoNew[0] = rhoOld[1]; rhoNew[sdom-1] = rhoOld[sdom-2];
    rhoVNew[0] = 0; rhoVNew[sdom-1] = 0;
    ElNew[0] = Pr[1]/(gam-1.); ElNew[sdom-1] = Pr[sdom-2]/(gam-1.); return;}
