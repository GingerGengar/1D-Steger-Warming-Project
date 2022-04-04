#Compute.py
#Library Import Statements
from Var import *

#Pressure in terms of Sound Speed and density
P = rho*a**2/gamma

#Construction of Last element of solution vector
E = P/(gamma-1) + haf*rho*u**2
E = E.simplify()

#Construction of Solution vector 
phi = Matrix([[rho],[rho*u],[E]])

#Construction of T Matrix
T = Matrix([[1, alpha, alpha],
[u , alpha*(u+a) , alpha*(u-a)],
[haf*(u**2) , alpha*(haf*(u**2)+u*a+(a**2)/(gamma-1)) , alpha*(haf*(u**2)-u*a+(a**2)/(gamma-1))]])

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
