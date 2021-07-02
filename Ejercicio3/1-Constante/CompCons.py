#Se declara las librerías para graficar
from matplotlib import pyplot 
#funcion que retorna un valor constante
def f1(x):
	return 1
#se establece un rango cuando 0<n<100,000
x=range(1,999)
#se manda a graficar en el rango establecido 
pyplot.plot(x,[f1(i) for i in x], label="O(1)")
#se le da un título a la gráfica
pyplot.title("Complejidad constante O(1)")
#Una etiqueta en el eje de las y
pyplot.ylabel("1")
#Una etiqueta en el eje de las x
pyplot.xlabel("n | 0<n<1000")
#Se añade una leyenda en la parte superior derecha
pyplot.legend(loc="upper right")
#se añade una cuadrícula
pyplot.grid()
#se guarda la grafica como imagen .png
pyplot.savefig("Complejidad-constante.png")
#se muestra la gráfica
pyplot.show()