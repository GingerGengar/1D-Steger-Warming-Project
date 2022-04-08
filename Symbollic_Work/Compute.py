#Compute.py
#Library Import Statements
from Var import *

#Pressure in terms of Sound Speed and density
P = rho*a_s**2/gam

#Construction of Last element of solution vector
E = P/(gam-1) + haf*rho*Ve**2
E = E.simplify()

#Construction of Solution vector 
phi = Matrix([[rho],[rho*Ve],[E]])

#Construction of T Matrix
T = Matrix([[1, alpha, alpha],
[Ve , alpha*(Ve+a_s) , alpha*(Ve-a_s)],
[haf*(Ve**2) , alpha*(haf*(Ve**2)+Ve*a_s+(a_s**2)/(gam-1)) , alpha*(haf*(Ve**2)-Ve*a_s+(a_s**2)/(gam-1))]])

#Construction of T Inverse Matrix
Tinv = T**-1

#Construction of eigenvalue matrix
lam = Matrix([[lambda_1,0,0],[0,lambda_2,0],[0,0,lambda_3]])

#Construction of Jacobian Matrix
Amatrix = T*lam*Tinv
Amatrix = Amatrix.applyfunc(simplify)

#Construction of Flux Vector
Flux = Amatrix*phi
Flux = Flux.applyfunc(simplify)

#Matrix Dimensions
[i,j] = shape(Flux)
for index1 in range(0,i):
    for index2 in range(0,j):
        Flux[index1,index2] = collect(Flux[index1,index2], lambda_1)
        Flux[index1,index2] = collect(Flux[index1,index2], lambda_2)
        Flux[index1,index2] = collect(Flux[index1,index2], lambda_3)
