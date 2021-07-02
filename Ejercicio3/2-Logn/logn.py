#Se importa la librería para poder extraer funciones 
#Entre las que se encuentran sen(),cos() y log()
import numpy 
#Se importa la librería de graficación para python
from matplotlib import pyplot
#se establece un dominio de la funcion donde 0<x<100,000
#con incrementos de 1,000 en 1,000
x=range(1,999)
#Se evalua la funcion de la lista de puntos x en la funcion y
y=numpy.log(x)
#Se grafica la funcion con un color de linea verde y una etiqueta
pyplot.plot(x,y,'g',label="O(log n)")
#Título de la gráfica
pyplot.title("Complejidad log n")
#Una etiqueta en el eje de las y
pyplot.ylabel("log n")
#Una etiqueta en el eje de las x
pyplot.xlabel("n | 0<n<1000")
#Se agrega una leyenda con la etiqueta de la funcion en la esquina sup izq
pyplot.legend(loc="upper left")
#Cuadriculado de la gráfica
pyplot.grid()
#Se guarda la gráfica con extensión .png en el mismo directorio
#en donde se encuentra el programa
pyplot.savefig("Complejidad-logn.png")
#Se muestra la grafica
pyplot.show()