#Symbollic_Debug.py
#Library imports 
from Compute import*

#Specific Heat capacity
gamma = 1.4

#size of dx
dx = 0.01
#size of dt
dt = 9e-05

#Positive Flux is true, Neg Flux is false
Positive = false 

def Determine(number):
    if (Positive):
        if number<0:
            return 0;
        else:
            return number
    else:
        if number <0:
            return number
        else:
            return 0;

#Density Value
Density = 9.966220e-01
#Velocity Value
FluidVelocity = 4.063727e-03
#Speed of Sound Value
SpeedofSound = 1.182341e+00
#eigenvalue values
lamb1 = Determine(FluidVelocity);
lamb2 = Determine(FluidVelocity + SpeedofSound);
lamb3 = Determine(FluidVelocity - SpeedofSound);

def realize(obj):
    #obj = obj.subs(some, )
    obj = obj.subs(lambda_1, lamb1)
    obj = obj.subs(lambda_2, lamb2)
    obj = obj.subs(lambda_3, lamb3)
    obj = obj.subs(gam, gamma)
    obj = obj.subs(Ve, FluidVelocity)
    obj = obj.subs(a_s, SpeedofSound)
    obj = obj.subs(rho, Density)
    obj = obj.evalf()
    return obj

if Positive:
    print('Positive Flux Mode')
else:
    print('Negative Flux Mode')
print('Flux 1:', realize(Flux[0]))
print('Flux 2:', realize(Flux[1]))
print('Flux 3:', realize(Flux[2]))


