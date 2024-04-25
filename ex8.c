/*
Escribir un programa que cree N procesos iterados,
P1 -> P2 -> P3 -> P4
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    int pid, n;

    printf("numero de hijos para el padre: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
    {
        // creamos un nuevo proceso hijo
        pid = fork();

        switch ( pid )
        {
            case -1:
                printf("Error al crear el proceso\n");
            break;

            // codigo para el hijo
            case 0:
                printf("\tSoy el proceso hijo [%d] y mi padre es [%d]\n", getpid(), getppid());
            break;

            // codigo para el padre
            default:
                printf("Soy el proceso padre [%d] y mi hijo es [%d]\n", getpid(), pid);
                /*
                matamos al padre para que no suba al for
                y cree un nuevo proceso
                */
                exit(0);
            break;
        }
    }
    
    
    return 0;
}