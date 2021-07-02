#Se importa las librerías para graficar
from matplotlib import pyplot
#se establece un dominio de la funcion donde 0<x<100,000
x=range(1,999)
#Se evalua la funcion de la lista de puntos x en la funcion y
y=x
#Se grafica la funcion con un color de linea verde y una etiqueta
pyplot.plot(x,y,'r',label="O(n)")
#Título de la gráfica
pyplot.title("Complejidad n")
#Una etiqueta en el eje de las y
pyplot.ylabel("n")
#Una etiqueta en el eje de las x
pyplot.xlabel("n | 0<n<1000")
#Se agrega una leyenda con la etiqueta de la funcion en la esquina sup izq
pyplot.legend(loc="upper left")
#Cuadriculado de la gráfica
pyplot.grid()
#Se guarda la gráfica con extensión .png en el mismo directorio
#en donde se encuentra el programa
pyplot.savefig("Complejidad-lineal-n.png")
#Se muestra la grafica
pyplot.show()