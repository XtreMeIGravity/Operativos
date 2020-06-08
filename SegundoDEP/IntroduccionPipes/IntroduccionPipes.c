/* INSTITUTO POLITÉCNICO NACIONAL
         ESCUELA SUPERIOR DE CÓMPUTO
           SISTEMAS OPERATIVOS
              SEMESTRE 2020-2
                GRUPO: 2CV8
        ALUMNO:
          -- LÓPEZ HERNÁNDEZ DAVID
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define LEER		0
#define ESCRIBIR	1

int main (){
  int descr[2],descr1[2];	/* Descriptores de E y S de la turbería */
  int  bytesleidos,bytesleidos1;
  char mensaje[100],mensaje1[100],
	frase[30],frase2[30];

  printf ("Ejemplo de tuberÍa entre padre e hijo.\n");

  pipe (descr);
  pipe(descr1);

  if (fork () == 0)
  {
    //ESTA ES LA CONFIGURACION DE LAS TUBERIAS
    //tuberia del padre hacia hijo
    close (descr1[ESCRIBIR]);
    //tuberia del hijo hacia padre
    close (descr[LEER]);

    //ESTA ES LA PARTE DE LA COMUNICACION DE LAS TUBERIAS
    //tuberia del padre hacia hijo
    bytesleidos1 = read (descr1[LEER], mensaje1, 100);
    printf ("El hijo recibio: %d %s\n", bytesleidos1,mensaje1);
    //tuberia del hijo hacia padre
    printf("Escribe el mensaje hacia el padre\n");
    scanf("%[^\n]s",frase);
    write (descr[ESCRIBIR], frase, strlen(frase));

    //CERRADO DE LAS TUBERIAS
    close (descr1[LEER]);
    close (descr[ESCRIBIR]);
  }
  else
  {
    //ESTA ES LA CONFIGURACION DE LAS TUBERIAS
    //tuberia del padre hacia hijo
    close (descr1[LEER]);
    //tuberia del hijo hacia padre
    close (descr[ESCRIBIR]);


    //ESTA ES LA PARTE DE LA COMUNICACION DE LAS TUBERIAS
    //tuberia del padre hacia hijo
    printf("Escribe el mensaje hacia el hijo\n");
    scanf("%[^\n]s",frase2);
    write (descr1[ESCRIBIR], frase2, strlen(frase2));
    //tuberia del hijo hacia padre
    bytesleidos = read (descr[LEER], mensaje, 100);
    printf ("El padre recibio: %d %s\n", bytesleidos,mensaje);

    //CERRADO DE LAS TUBERIAS
    close (descr1[ESCRIBIR]);
    close (descr[LEER]);
    //prueba chat
  }
}
