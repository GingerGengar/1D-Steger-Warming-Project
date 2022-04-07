#Profile_Plotting.py
#Library Imports
import numpy as np
import matplotlib.pyplot as plt

#Load Density Data
Density = np.genfromtxt('Density.dat')

#Load Velocity Data
Velocity = np.genfromtxt('Velocity.dat')

#Load Pressure Data
Pressure = np.genfromtxt('Pressure.dat')

#Load XDimensions
XDimensions = np.genfromtxt('XDimensions.dat')

index = 600

#Plot Result
figure1, axis1 = plt.subplots()
axis1.plot(XDimensions, Density[index,:])
#Labels
axis1.set_xlabel('Displacement (m)')
axis1.set_ylabel('Density (kg/m^3)')
axis1.set_title('Density of the Sod Tube Problem')
#axis1.legend()
axis1.grid()

#Plot Result
figure2, axis2 = plt.subplots()
axis2.plot(XDimensions, Velocity[index,:])
#Labels
axis2.set_xlabel('Displacement (m)')
axis2.set_ylabel('Fluid Velocity (m/s)')
axis2.set_title('Velocity of the Sod Tube Problem')
#axis2.legend()
axis2.grid()

#Plot Result
figure3, axis3 = plt.subplots()
axis3.plot(XDimensions, Pressure[index,:])
#Labels
axis3.set_xlabel('Displacement (m)')
axis3.set_ylabel('Pressure (Pa)')
axis3.set_title('Pressure of the Sod Tube Problem')
#axis3.legend()
axis3.grid()

#Show Plot
plt.show()
