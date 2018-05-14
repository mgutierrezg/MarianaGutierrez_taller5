import numpy as np
import matplotlib.pyplot as plt
import numpy as np
import matplotlib.pyplot as plt

datos = np.loadtxt("datos.txt").reshape(510,510,3)

potencial = datos[:,:,0]
Ex = datos[:,:,1]
Ey = datos[:,:,2]
x = np.linspace(0,500,510)
plt.imshow(potencial,cmap = "plasma")
plt.colorbar()
plt.streamplot(x,x,Ex,Ey)
plt.savefig("placas.pdf")
#extent = [-3,3,-3,3] 
