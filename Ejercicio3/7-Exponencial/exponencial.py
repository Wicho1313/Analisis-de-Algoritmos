#Se importa la librería para sacar la exponencial
import numpy
#Se importa la librería de graficación para python
from matplotlib import pyplot
#Funcion cuadratica recive el parametro x evaluado de 0<x<100,000
def f(x):
	y=numpy.exp(x)
	return y 
#se establece un dominio de la funcion donde 0<x<100,000
x=range(1,999)
#Se grafica la funcion con un color de linea amarillo y una etiqueta
#el ciclo funciona para cada valor de x en el rango establecido
pyplot.plot(x,[f(i) for i in x],"y",label="O(a^n)")
#Título de la gráfica
pyplot.title("Complejidad a^n")
#Una etiqueta en el eje de las y
pyplot.ylabel("a^n")
#Una etiqueta en el eje de las x
pyplot.xlabel("n | 0<n<1000")
#Se agrega una leyenda con la etiqueta de la funcion en la esquina sup izq
pyplot.legend(loc="upper left")
#Cuadriculado de la gráfica
pyplot.grid()
#Se guarda la gráfica con extensión .png en el mismo directorio
#en donde se encuentra el programa
pyplot.savefig("Complejidad-exp.png")
#Se muestra la grafica
pyplot.show()