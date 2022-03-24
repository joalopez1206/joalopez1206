#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint;
uint borrar_bits(uint x, uint pat, int len);

//#include "borrar-bits.h"

uint borrar_bits(uint x, uint pat, int len) {
    int m1 = ~(-1<<len); // creamos la mascara para ver dos numeros
    for(int i = 0; i<(sizeof(x)<<3)-len+1; i++){ // hacemos el ciclo
        
        if((x >> i)& m1 == pat){ //si se cumple que es igual al patron 
            
            int m2 = m1 << i; //hacemos otra mascara para desplazar el cambio
            
            x &= ~m2; // lo hacemos 0 ya que m2 es de la forma 0000..1111.000
        }
    }
    return x;
}


uint borrar_bits2(uint x, uint pat, int len) {
    int m1 = ~(-1<<len); // creamos la mascara para ver dos numeros

    for(int i = 0; i<(sizeof(x)<<3)-len+1; i++){ // hacemos el ciclo

        int m2 = m1 << i;
        
        if((x & m2) == (pat << i) ){ //si se cumple que es igual al patron

            x &= ~m2; // lo hacemos 0 ya que m2 es de la forma 0000..1111.000
        }
    }
    return x;
}

int main(){
    //printf("si niegas este numero ~ %d va a ser: %d \n", 0, ~0);
    printf("borrar_bits(0x%x,0x1,1) = 0x%x", 0x89,
    borrar_bits(0x89,0x1,1));
    printf("borrar_bits(0x%x,0x2,2) = 0x%x", 0x1d9,
    borrar_bits(0x1d9,0x2,2));
    return 0;
}
