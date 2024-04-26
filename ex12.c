/*
Escribir un programa que cree N procesos para un mismo
padre y estos esperen a que sus hermanos terminen
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    system("clear");

    int pid, n = 6;
    int status;

    // printf("numero de hijos para el padre: ");
    // scanf("%d", &n);
    
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
                printf("%d: Soy el proceso hijo [%d] y mi padre es [%d]\n", i + 1, getpid(), getppid());

                // ponemos a trabajar al hijo
                sleep(1);

                printf("\thijo [%d]...Termine\n", getpid());
                // matamos al hijo para que no haga nietos
                exit(0);
            break;

            // codigo para el padre
            default:
                if (i==0)
                {
                    printf("Soy el proceso principal [%d]\n", getpid());
                }
                /*
                Esperamos a que el nuevo proceso hijo termine para subir al fork de nuevo 
                y crear un nuevo hijo */
                waitpid(pid, NULL, 0);
            break;
        }
    }

    return 0;
}