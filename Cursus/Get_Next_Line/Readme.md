*This project has been created as part of the 42 curriculum by juannune.*
 
/* Char *stash: Es un puntero que apunta a la memoria dinámica donde se acumula el texto leìdo 
del fd que todavía no se ha entregado como línea. Guardas los fragmentos sobrantes después de
extraer una línea. 

Static char *stash: Hace que el puntero conserve su valor entre llamadas y así el resto no
se pierde.

El buffer: Es el bloque temporal de memoria donde se guardan los bytes recién leídos del fd.
No conserva datos entre llamadas sólo sirve de contenedor momentáneo para cada lectura.

bytes_read: Es la variable donde guardas el resultado de read(fd, buffer, BUFFER_SIZE).

L44-45 : Inicializo en 1 para que sea verdadera la primera vez y el bucle empiece.

L45 : Mientras no se haya encontrado un '\n' y aún hayan bytes por leer.

L47 : read : Permite obtener bytes desde un fd hacia un buffer de memoria. Su llamada devuelve
un ssize_t.
>0 = (número de bytes leídos), 0 = EOF(fin del fichero), -1 = (error)

L57-59 : Añade los nuebos bytes leídos (buffer) al acumulador (stash) mediante append quien
crea una nueva cadena uniendo stash + buffer. 
Si hubo fallo de memoria en donde appen fue NULL se procede a liberar el buffer y se retorna
NULL. No libera stash porque ya se liberó dentro de append.

En append_to_stash construimos una cadena acumulada ( stash ). Si stash llega como NULL en la
primera vez pues la inicilizamos como cadena vacía con ft_strdup("") para poder trabajarla.
En temp guardamos la concatenación de temp con buffer que hace ft_strjoin asignando el resultado
a stash.

L75 : Reserva memoria para i y +2 por el '\n' y '\0'.

L79 : El post incremento (line[i++] = '\n') avanza un espacio más en donde irá el valor '\0'.

L104 : Reservo memoria y a la longitud de stash le resto la posición en donde encontró el '\n'.
ejemplo: h o l a \n m u n d o \0 = 10 | ('\n' = i = 4) | (10-4=6) | Len = 6;

L107 : Libero stash para no dejarlo ocupado en memoria ya que si no lo hago estaría dejando
texto viejo en memoria.

L110 : Me hubico en la posición siguiente al '\n' para emepezar a copiar el resto a newstash.
*/
