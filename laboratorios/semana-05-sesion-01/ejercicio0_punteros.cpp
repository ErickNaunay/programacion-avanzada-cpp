# include <iostream>

int main(){
    int numero=10;
    int *ptr_numero=&numero;

    std::cout<<"Direccion de memoria: "<<ptr_numero<<std::endl;

    std::cout<<"Valor en memoria desde puntero: "<<*ptr_numero<<std::endl;
    std::cout<<"Valor en memoria desde la memoria: "<<numero<<std::endl;

    int notas[5]={80, 90, 60, 50, 71};
    int *ptr_notas=notas;
    std::cout<<"Valores del array: ";
    for(int i=0; i<5;i++){
        std::cout<<*ptr_notas<<" ";
        ptr_notas+=1;
    }
    return 0;
}
