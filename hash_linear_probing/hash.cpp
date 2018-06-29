#include <iostream>
#include <vector>
#include <tuple>
#include <list>

using namespace std;

enum Marcador {VAZIO, CHEIO, DELETADO};

struct Elem {

    int value;
    Marcador marcador;

    Elem() = default;


    Elem(int value){
        this->value = value;
        this->marcador = CHEIO;
    }

    //sobrecarga de operador!
    bool operator ==(Elem other){
        return value == other.value;
    }

    //sobrecarga de operador!
    friend ostream& operator << (ostream& os, Elem e){
        os << e.value;
        return os;
    }
};

struct HashLinear{ //linear probing

    Elem * vet;
    int capacity;
    int size;

    HashLinear(int capacity){


        this->capacity = capacity;
        this->vet = new Elem[capacity];
        this->size = 0;
    }

    bool insert(int value){

        int index = find(value);

        if(this->vet[index] == value)
            return false;

        this->vet[index] = Elem(value);
        this->size++;
    }


    int find(int value){

        int pos = value % this->capacity;
        int index = pos, i = 0, idel = -1;

        while(!(this->vet[index] == value) &&
              !(this->vet[index].marcador == VAZIO) &&
              (i < this->capacity)){

            if(idel == -1)
                if(this->vet[index].marcador == VAZIO)
                    idel = index;

            i++;
            index = (pos + 1) % this->capacity;
        }

        if(this->vet[index] == value)
            return index;

        if(idel != -1)
            return idel;

        return index;
    }

    bool remove(int value){

        int index = find(value);

        if(!(this->vet[index] == value))
            return false;

        this->vet[index].marcador = DELETADO;
        this->size--;
    }

    bool exists(int value){

        if(this->vet[find(value)] == value)
            return true;

        else
            return false;
    }

};

int main(){

    HashLinear hash(10);

    if(hash.insert(5)){
        cout<<"item inserido!"<<endl;
        if(hash.exists(5)){
            cout<<"item existe!"<<endl;
            if(hash.remove(5))
                cout<<"item removido!"<<endl;
        }
    }

    return 0;
}
