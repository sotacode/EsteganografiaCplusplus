# EsteganografiaCplusplus
Proyecto para encriptar un mensaje dentro de una imagen utilizando un codificador. Para obtener el mensaje se usa el decodificador.

## Uso
0. En el código del fichero Codificador.cpp, modificar la línea 12 y escribir el nombre de la imagen .ppm que se usara para encriptar el mensaje.
1. Se debe compilar el codificador y decodificador.
2. Se escribe un fichero con el nombre "mensaje.txt" ubicado en el mismo directorio codificador ejecutable. El mensaje debe terminar si o si con el caracter de corchete cerrado "]".
3. Se ejecuta el codificador.
4. Se genera una imagen llamada "modificada.ppm" la cual es la imagen con el mensaje encriptado.
5. Para decodificar el mensaje, la imagen debe llamarse "modificada.ppm" (puede modificarse en la linea 12 del decodificador.cpp) y ejecutar el propio decodificador.
6. Se genera un fichero llamado "mensaje_decodificado.txt" con el mensaje decodificado.
