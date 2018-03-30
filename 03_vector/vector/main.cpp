#include <iostream>
#include <vector>

using namespace std;


struct vetor{

    int * data; //bloco de dados
    int capacidade;//tamanho maximo do vetor
    int size; // aqui eu tenho quantos elementos sao inseridos


    vetor(int capacidade){

        this->capacidade = capacidade;
        this->size = 0;
        this->data = new int[capacidade];
    }

    void push_back(int value){

        if(this->size == this->capacidade){

            reserve(capacidade*2);
        }

        this->data[this->size] = value;
        this->size++;
    }

    void pop_back(){

        if(this->size == 0){
            return;
        }

        size--;
    }

    int& at(int indice){

        return this->data[indice];
    }

    int& front(){

        return this-> data[0];
    }

    int& back(){

       return this->data[size - 1];
    }

    int * begin(){

        return &data[0];
    }

    int * end(){

       return &data[size];
    }

    int capacity(){

        return this->capacidade;
    }

    void reserve(int capacity){

        int capac = this->capacidade;
        this->capacidade = capacity;
        int *bloco = new int[capac];

        for(int i = 0; i < this->size; i++){

            bloco[i] = this->data[i];
        }

        this->data = new int[capacity];

        for(int i = 0; i < this->size; i++){

            this->data[i] = bloco[i];
        }

        delete [] bloco; // liberando memoria
    }

};

    /*fazer:

        void push_back(){} ok
        void pop_back(){} ok
        at(); retorna a referencia a variavel dessa posiçao ok
        void front() ok
        void back() ok
        int * begin()  ok
        int *end()  ok
        int size() ok
        int capacity() ok
        void reserve(int capacity) ok
    */

int main(){

    vetor v(10);

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    v.push_back(9);
    v.push_back(10);
    v.push_back(11);
    v.push_back(12);
    v.push_back(13);
    v.push_back(14);

    for(int i = 0; i < v.size; i++){
        cout<<v.at(i)<<" ";
    }

    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();

    cout<<"\n";

    for(int i = 0; i < v.size; i++)
        cout<<v.at(i)<<" ";


    //testando os metodos!
    cout<<"\n"<<v.front()<<endl;
    cout<<v.back()<<endl;
    cout<<*v.begin()<<endl;
    cout<<v.capacity()<<endl;
    cout<<*v.end()<<endl;
    //todos funcionam!

    return 0;
}

