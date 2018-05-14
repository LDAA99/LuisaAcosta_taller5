import numpy as np 
import matplotlib.pyplot as plt 
from matplotlib.animation import FuncAnimation



"""
Metodo encontrado en https://stackoverflow.com/questions/37111571/passing-arguments-in-animation-funcanimation
"""
data=np.loadtxt("datos.txt")

x=data[:,0]
y=data[:,1]

f=plt.figure()
xx=f.add_subplot(111)
linea, =xx.plot([],[], '-')
linea2, =xx.plot([],[],'--')
xx.set_xlim(np.min(x), np.max(x))
xx.set_ylim(np.min(y), np.max(y))

def creador(a, fact):
	linea.set_xdata(x[:a])
	linea.set_ydata(y[:a])
	linea2.set_xdata(x[:a])
	linea2.set_ydata(fact*y[:a])
	return linea, linea2


K=0.75
gif=animation.FuncAnimation(f, creador, frames=len(x), fargs=(K,), interval=100, blit=True)

gif.save("cuerda.gif", fps=30)

