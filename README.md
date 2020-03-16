# G-VRP

Compilar:

Para compilar utilizar el comando make

Ejecutar:

Para ejecutar utilizar el comando make run

Cambiar instancia:
Dirigirse a la linea 121 y especificar el nombre del archivo. Por ejemplo:
newfile.open("nombre.dat",ios::in);

Cambiar probabilidades:
Dirigirse a la linea 363 y especificar en decimal la probabilidad de elegir swap. El complemento de esto es la probabilidad de elegir insert. Además, si se desea forzar swap descomentar la linea 362.

Cambiar parametros de SA:
Dirigirse a la linea 66 y a continuacion se encuentran todos los parametros del SA, los cuales pueden ser cambiados libremente.

Consideraciones:

La instancia que se desee ejecutar debe estar en el mismo directorio que archivo main.cpp y el resultado final se entrega por consola.