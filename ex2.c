/*
Modificar el programa anterior y agregar al mensaje “Se ha creado un proceso” el
ID del proceso y el ID del padre
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    
    fork();
    // getpid: retorna el id del hijo
    // getppid: retorna el id del padre
    printf("\tSe ha creado un proceso (%d) y mi padre es (%d)\n", getpid(), getppid());

    return 0;
}