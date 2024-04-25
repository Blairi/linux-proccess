/*
Escribir un programa que cree N procesos hijos y a su
vez cada hijo debe crear x procesos
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    system("clear");

    int pid, n, x;

    printf("numero de hijos para el padre principal: ");
    scanf("%d", &n);
    printf("numero de nietos para los hijos: ");
    scanf("%d", &x);

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
                printf("\tPadre [%d] --> hijo%d:[%d]\n", getppid(), i+1, getpid());
                
                // creando x nietos
                for (int j = 0; j < x; j++)
                {
                    switch ( fork() )
                    {
                        case -1:
                            printf("Error al crear el proceso\n");
                        break;

                        // codigo para el nieto
                        case 0:
                            printf("\t\tHijo [%d] --> nieto%d:[%d]\n", getppid(), j+1, getpid());

                            /*
                            Matamos al nieto para que no
                            cree procesos hermanos nietos
                            */
                            exit(0);
                        break;
                    
                        // codigo de padre de los nietos
                        default:
                        // dejamos que el padre de los nietos cree x nietos
                        break;
                    }
                }

                /*
                Matamos al hijo para que no suba al
                fork principal y cree hermanos
                */
                exit(0);
            break;

            // codigo para el padre
            default:
                // dejamos que el padre cree n procesos
                if (i == 0)
                {
                    printf("Soy el proceso principal [%d]\n", getpid());
                }
            break;
        }
    }
    
    
    return 0;
}