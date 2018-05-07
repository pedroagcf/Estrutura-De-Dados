#include <iostream>

using namespace std;

struct Node{

    int value;
    Node* next;

    Node(int value = 0, Node* next = nullptr){

        this->value = value;
        this->next = next;
    }
};


struct SList{

    Node* head;

    SList(){

        this->head = nullptr;
    }


    void pushFront(int value){

        this->head = new Node(value, this->head);

//        Node* node = new Node(value);
//        node->next = head;
//        this->head = node;
    }


    void popFront(){

        if(head == nullptr)
            return;

        Node* aux = head;
        head = head->next;

        delete aux;
    }


    //push back interativo
    void pushBack(int value){

       if(head == nullptr){

           head = new Node(value);
           return;
       }

       auto node = head;

       while(node->next != nullptr)
           node = node->next;

       node->next = new Node(value);
    }


    //push back recursivo
    Node* r_PushBack(Node* node, int value){

        if(node->next == nullptr){

            node->next = new Node(value);
            return node->next;
        }

        return r_PushBack(node->next, value);
    }

    //pushBack externo
    void R_PushBack(int value){

        r_PushBack(head, value);
    }


    // pop back interativo
    void popBack(){

        auto node = head;

        if(head == nullptr)
            return;

        if(head->next == nullptr){

            delete head;
            head = nullptr;

            return;
        }

        while(node->next->next != nullptr)
            node = node->next;

        delete node->next;
        node->next = nullptr;

    }


    //show interativo
    void show(){

        auto node = head;

        while(node != nullptr){

            cout<<node->value<<" ";
            node = node->next;
        }

        cout<<endl;
    }

    //show recursivo interno
    void r_Show(Node* node){

        if(node == nullptr)
            return;

        cout<<node->value<<" ";
        r_Show(node->next);
    }


    //show recursivo externo
    void R_Show(){

        r_Show(head);
        cout<<endl;
    }


    //pop back recursivo interno
    Node* r_PopBack(Node* node){

        if(node->next == nullptr){

            delete node;
            return nullptr;
        }

        node->next = r_PopBack(node->next);
    }


    //pop back recursivo externo
    void  R_PopBack(){

        r_PopBack(head);
    }


    //conferir este metodo! OBS: nao sei se esta correto.
    Node* back(){

        auto node = new Node();

        while(node->next != nullptr){
            node = node->next;
        }

        return node->next;
    }

    //remove recursivo interno
    Node* _remove(Node* node, int value){

        if(node == nullptr)
            return nullptr;

        if(node->value == value){

            auto aux = node->next;
            delete node;

            return aux;
        }

        node->next = _remove(node->next, value);
    }

    //remove recursio externo
    void remove(int value){

        _remove(head, value);
    }


    // remove interativo
    Node* iremove(int value){

        auto node = head;

        if(node == nullptr)
            return nullptr;

        if(head->value == value){

            auto aux = head;

            head = head->next;

            delete aux;
            return head;
        }

        while(node->next != nullptr){

            if(node->next->value == value){

                auto aux = node->next;
                node->next = node->next->next;

                delete aux;
                return node->next;
            }

            node = node->next;
        }

        return node;
    }


    //remove externo
    void Remove(int value){

        iremove(value);
    }


    //metodo interativo
    void inserirOrdenado(int value ){

        auto node = head;

        if(head == nullptr || head->value > value){

            this->head = new Node(value, head);
            return;
        }

        while(node->next != nullptr && node->next->value < value){

            node = node->next;
        }

        node->next = new Node(value, node->next);
    }

    //metodo recursivo interno
    Node* R_InserirOrdenado(Node* node, int value){

        node = head;

        if(head->next != nullptr && node->next->value < value){

            R_InserirOrdenado(node->next, value);
        }

        if(head == nullptr || head->value > value){

            this->head = new Node(value, head);
            return nullptr;
        }
    }


    //metodo recursivo externo
    void r_InserirOrdenado(int value){

        R_InserirOrdenado(head, value);
    }


    // somar recursivo interno
    int somar(Node* node){

        if(node == nullptr)
            return 0;

        return node->value += somar(node->next);
    }

    //somar externo
    int Somar(){

        return somar(head);
    }


    //somar iterativo interno
    int I_Somar(Node* node){

        int value = 0;

        while(node != nullptr){

            value += node->value;
            node = node->next;
        }

        return value;
    }


    //somar externo
    int I_somar(){

        return I_Somar(head);
    }


    //pegar o minimo recursivo interno
    int r_min(Node* node){

        if(node->next == nullptr)
            return node->value;

        return min(node->value, r_min(node->next));
    }


    //pega minimo externo
    int R_min(){

        return r_min(head);
    }


    // pega minino iterativo interno
    int I_min(Node* node){

        int min = node->value;

        while(node != nullptr){

            if(node->value < min){
                min = node->value;
            }

            node = node->next;
        }

        return min;
    }


    // pega minino externo
    int I_Min(){

        return I_min(head);
    }


    //inserir ordenado iterativo
    void I_inserir(int value){

        if(head == nullptr || (head->value > value)){

            head = new Node(value, head);
            return;
        }

        auto node = head;

        while(true){

            if(node->next == nullptr || (node->next->value > value)){

                node->next = new Node(value, node->next);
                break;
            }

            node = node->next;
        }
    }


    Node* deletarTudo(Node* node){

        if(node == nullptr)
            return nullptr;

        deletarTudo(node->next);

        delete node;
        return nullptr;
    }

    void R_deletarTudo(){

        head = deletarTudo(head);
    }


    Node* arrancaRabo(Node* node, int value){

        if(node == nullptr)
            return nullptr;

        node->next = arrancaRabo(node->next, value);

        if(node->next == nullptr){

            if(node->value != value){

                delete node;
                return nullptr;

            }else{

                return node;
            }
        }

        return node;
    }


    void ArrancaRabo(int value){

        arrancaRabo(head, value);
    }

};


int main(){

    SList lista;

    lista.I_inserir(5);
    lista.I_inserir(10);
    lista.I_inserir(-3);
    lista.I_inserir(100);
    lista.I_inserir(-20);

    lista.show();

    lista.iremove(5);

    lista.Remove(-20);

    lista.show();

    lista.R_PushBack(9);
    lista.R_PushBack(46);

    lista.show();

    lista.I_inserir(18);
    lista.I_inserir(-5);
    lista.I_inserir(67);
    lista.I_inserir(35);

    lista.ArrancaRabo(18);

    lista.show();

    cout<<lista.I_Min()<<endl;
    cout<<lista.I_somar()<<endl;

    lista.R_deletarTudo();

    lista.show();

    return 0;
}
