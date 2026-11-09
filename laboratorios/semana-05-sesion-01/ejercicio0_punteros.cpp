#include <iostream>
using namespace std;

int main (){

    int numero= 10;
    int *pt_numero = &numero;
    cout<<"direccion de memoria: "<<pt_numero<<endl;
    cout<<"valor de numero por puntero: "<< *pt_numero<<endl;
    

    int notas[5 ]={80,90,60,50,71};
    
    int *ptr_notas = notas;

    cout<<"direccion de memoria: "<< ptr_notas<<endl;
    cout<<"valor de numero por puntero: "<< *ptr_notas<<endl;
    for(int i=0; i < 5;i++){

        cout<<"valor de numero por puntero: "<<*(ptr_notas + i)<<" numero del arreglo: "<< i+ 1<<endl; 

    }
    return 0;


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