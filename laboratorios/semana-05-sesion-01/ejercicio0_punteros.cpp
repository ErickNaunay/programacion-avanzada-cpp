#include <iostream>


int main(){

    int notas[5]={100,90,80,70,60};

    int *ptr_notas=notas;
     for (int i = 1; i <= 5; i++) {
        std::cout << "Elemento " << i << ": " << *ptr_notas <<std::endl;
        
        ptr_notas++; 
    }
}