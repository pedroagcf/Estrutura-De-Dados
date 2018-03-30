#include <iostream>
#include <list>

using namespace std;

int main(){

    list<int> soldados;

    int tamanho = 0;
    int soldado = 0;
    int saltos = 0;

    cout<<"Digite a quantidade de pessoas: "<<endl;
    cin>>tamanho;

    cout<<"Digite o numero do soldado: "<<endl;
    cin>>soldado;

    cout<<"Digite o numero de saltos: "<<endl;
    cin>>saltos;

    for (int i = 1; i <= tamanho; i++){
        
        soldados.push_back(i);
    }

    while(soldados.back() != soldado){
        
        soldados.push_front(soldados.back());
        soldados.pop_back();
    }


    while((int) soldados.size() > 1){
        
        int aux = 1;
        
        while(aux != saltos){
        
            soldados.push_front(soldados.back());
            soldados.pop_back();
            aux++;
        }
        
        soldados.pop_front();
    }


    cout<<soldados.front()<<endl;

    return 0;
}
