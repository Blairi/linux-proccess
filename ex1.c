/*
Escribir un programa que clone un proceso mediante la llamada fork(), y que
imprima a pantalla el mensaje “Se ha creado un proceso”.
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    
    // creamos un proceso hijo
    fork();
    printf("\tHola mundo\n");

    return 0;
}