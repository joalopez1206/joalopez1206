#include <stdio.h>
#include <stdlib.h>

int bits1(int n){
    int valor = 0;
    for(int i = 0; i<(sizeof(n)*8); i++){
        valor += (n >> i)&1;
    }    
    return valor;
}

int posicionbits(int x, int p, int n){
    int i = 0;
    while(i<(sizeof(x)*8)){
        if(((x >> i) & (~(-1 << n))) == p){
            return i;
        }
    return -1;
    }
}

int main(){
    printf("el numero de 1's de %d es: %d \n", 5, bits1(5)); // tiene que ser 2 !
    printf("el numero de 1's de %d es: %d \n", 8, bits1(8)); // tiene que ser 1 !
    printf("la posicion del bit del numero %d con el patron dado es: %d", 0x5, posicionbits(0x4, 0x1, 2)); // tiene que ser 0
    return 0;
}
