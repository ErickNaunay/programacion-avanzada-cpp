
#include <iostream>

int main (){
    
    int numero = 10;

    int *puntero = &numero;

    std::cout << "La direccion de memoria es: " << puntero << std::endl;
    std::cout << "El valor en memoria es: " << numero << std::endl;
    std::cout << "El valor al que apunta el puntero es: " << *puntero << std::endl;

    int notas[5] = {80, 90, 60, 50, 71};

    int *punteroNotas = notas;

    std::cout << "La direccion de memoria del arreglo es: " << punteroNotas << std::endl << std::endl;

    for (int i = 0; i < 5; i++){
        std::cout << "El valor en memoria del elemento " << i + 1 << " es: " << *(punteroNotas + i) << std::endl;
    }
#include <iostream>

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