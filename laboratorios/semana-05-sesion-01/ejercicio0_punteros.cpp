#include <iostream>

    int numero=10;
    int* ptr_numero=&numero;
    std::cout<<"Direccion de memoria"<<ptr_numero<<std::endl;
    std::cout<<"Valor "<<*ptr_numero<<std::endl;

    int notas[5]={100,70,98,90,80};
    int* ptr_notas=notas;
    std::cout<<"Direccion de memoria "<<ptr_notas<<std::endl;
    std::cout<<"Valor "<<*ptr_notas<<std::endl;
    for(int i=0;i<5;i++){
        std::cout<<"Direccion "<<i+1<<" : "<<(ptr_notas+i)<<std::endl;
        std::cout<<"Valor "<<i+1<<" : "<<*(ptr_notas+i)<<std::endl;
    }
int main() {

    int numero = 10;

    int *ptr_numero = &numero;

    std::cout << "Direccion de memoria: " << ptr_numero << std::endl;    
    std::cout << "Valor en memoria desde puntero: " << *ptr_numero << std::endl;    
    std::cout << "Valor en memoria desde la variable:" << numero << std::endl;
    
    int notas[5] = {80, 90, 60, 50, 71};

    int *ptr_notas = notas;
 
    std::cout << "Direccion de memoria: " << ptr_notas << std::endl;    
    std::cout << "Valor en memoria desde puntero: " << *ptr_notas << std::endl;    

    ptr_notas += 1;
    std::cout << "Valor en memoria desde puntero: " << *ptr_notas << std::endl;    

    return 0;
}