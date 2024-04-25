#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    
    fork();
    fork(); // El hijo crea un nuevo proceso "nieto"
    printf("\tSe ha creado un proceso (%d) y mi padre es (%d)\n", getpid(), getppid());

    return 0;
}