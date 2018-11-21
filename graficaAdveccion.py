import matplotlib.pyplot as plt
import numpy as np


datosU0 = np.loadtxt("condiciones_iniciales.txt")
datosUNT = np.loadtxt("condiciones.txt")

y = np.linspace(-1,1,len(datosU0))

plt.plot(y, datosU0, c = "b", label='t = 0')
plt.plot(y, datosUNT, c = "g", label='nt')
plt.ylabel("Magnitud")
plt.xlabel("Posicion")
plt.savefig("Gafica.png")


	 

