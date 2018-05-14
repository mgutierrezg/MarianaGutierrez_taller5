import numpy as np
from numpy import genfromtxt, size, shape
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

#metodo para hacer un gif basado en: http://www.jamesphoughton.com/2013/08/23/making-gif-animations-with-matplotlib.html

datos = genfromtxt("cuerda.txt", delimiter = " ")
frms,points = shape(datos)

def metodo(i):
    datos_i = datos[i,:]
    plt.cla()
    plt.plot(datos_i, c = "m")
    plt.ylim([-1,1])

imagen = plt.figure()
gif = FuncAnimation(imagen, metodo, frames=int(frms/2), interval=40)
gif.save("cuerda.gif", writer = "imagemagick", fps = int(frms/4))
    
