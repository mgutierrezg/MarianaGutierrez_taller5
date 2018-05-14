import numpy as np
import matplotlib.pyplot as plt
import numpy as np
import matplotlib.pyplot as plt

datos = np.loadtxt("datos.txt").reshape(510,510,3)

potencial = datos[:,:,0]
Ex = datos[:,:,1]
Ey = datos[:,:,2]
x = np.linspace(-3,3,510)
plt.imshow(potencial, extent = [-3,3,-3,3] ,cmap = "plasma")
plt.colorbar()
plt.streamplot(x,x,Ex,Ey)
plt.savefig("placas.pdf")
