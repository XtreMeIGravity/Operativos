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
#include <sys/types.h>
#include <sys/stat.h>
/*char *tuberia = "/tmp/tuberia";*/
int main()
{
FILE *mipipe;
char buffer[128],buffer2[128];
int i=0;
char *fin = "fin";

if(mkfifo("pipetest", S_IWUSR |/* El usuario puede escribir */
                 S_IRUSR |/* El usuario puede leer */
                 S_IRGRP |/* El grupo puede leer */
                     S_IROTH    /* Otros pueden leer */
)!=0)
printf("Hubo un problema al crear la pipe\n");

  mipipe=fopen("pipetest","w");/* Lo abrimos como un fichero normal y corriente */

/* Con esta línea leemos hasta que se cierre la tubería por el otro */

while(1) {
  memset( buffer , 0 , 128 );
  memset( buffer2 , 0 , 128 );
  printf("Ingresa un mensaje:\n");
  scanf(" %[^\n]s", buffer);
  fputs(buffer, mipipe);
  if( strncmp( buffer , fin , 3 ) == 0 )
    break;
  //sprintf(buffer,"CADENA ENVIADA Número: %i\n", i+1);
  if (fgets(buffer2, 128, mipipe))
    printf ("RECIBIDO: %s\n", buffer2);
  if( strncmp( buffer2 , fin , 3 ) == 0 )
    break;
}

fclose(mipipe);/* Cerramos la tubería por aquí también */
}