/*
El proceso padre deberá de escribir a pantalla “Soy el proceso padre con PID=### y mi hijo es PID=###”
El proceso hijo deberá de escribir a pantalla “Soy el proceso hijo con PID=### y mi padre es PID=###”
Si no se pudo clonar el proceso, mandar un mensaje a pantalla y terminar el programa con exit(0).
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    
    switch ( fork() )
    {
        case -1:
            printf("Error al crear el proceso\n");
            exit(0);
        break;
    
        case 0:
            printf("Soy el proceso hijo [%d] y mi padre es [%d]\n", getpid(), getppid());
            exit(0);
        break;

        default:
            printf("Soy el proceso padre [%d] y mi hijo es [%d]\n", getppid(), getpid());
            exit(0);
        break;
    }

    return 0;
}