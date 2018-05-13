import numpy as np
import matplotlib.pyplot as plt

datos = np.loadtxt("caos.txt")
q2 = datos[:,0]
p2 = datos[:,1]

plt.scatter(q2,p2, c= "m")
plt.xlabel("q2")
plt.ylabel("p2")
plt.title("q2 vs p2, caos")

plt.savefig("caos.pdf")
