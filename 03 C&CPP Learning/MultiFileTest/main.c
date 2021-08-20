#include <stdio.h>
#include "add.h"

int main(int argc, char **argv){
    int a = 1;
    int b = 2;
    printf("%d", add(a, b));
}

// The command :
// gcc main.c add.c -o out.exe
// ./out.exe