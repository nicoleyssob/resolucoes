#include <iostream>
#include <stdexcept> //biblioteca pra usar a exceção throw runtime_error
#include <string>

using namespace std;

template <typename Thing>
class Node
{
public:
    Thing D;
    Node<Thing>* Next; //ponteiro que guarda o endereço do prox nó
};

template <typename Thing>
class Queue
{
    Node<Thing>* Head;
    Node<Thing>* Tail;
    int N;
public:
    Queue();//construtor
    int Size(); //tamanho
    bool Empty();
    bool Push(Thing T);
    Thing Front();
    Thing Back();
    void Pop();
    void Clear();
    ~Queue();
};

template <typename Thing>
Queue<Thing>::Queue()//construtor
{
    Head=Tail=N=0;
}

template <typename Thing>
bool Queue<Thing>::Empty()
{
    return !Head;
}

template <typename Thing>
int Queue<Thing>::Size()
{
    return N;
}

template <typename Thing> 
bool Queue<Thing> ::Push(Thing T){
    Node<Thing>*P=new Node<Thing>;
    if(!P){
        return false;
    }
    P->D=T;
    P->Next=0;
    if(!Head){
        Head =P;
    }else{
        Tail->Next=P;
    }
    Tail=P;
    N++;
    return true;
}

template <typename Thing>
Thing Queue <Thing>::Front(){
    if(!N){
        throw runtime_error("Fila vazia."); 
    }
    return Head->D;
}

template <typename Thing>
Thing Queue <Thing> :: Back(){
    if(!N){
        throw runtime_error("Fila vazia.");
    }
    return Tail->D;
}

template <typename Thing>
void Queue <Thing> :: Pop(){
    if(!Empty){
        Node<Thing>*P=Head;
        Head=Head->Next;
        delete P;
        if(!Head){
            Tail=Head;
        }
        N--;
    }
}

template <typename Thing>
void Queue <Thing> ::Clear(){
    Node<Thing>*P;
    while(Head){
        P=Head;
        Head=Head->Next;
        delete P;
    }
    Tail=N=0;
}

template<typename Thing>
Queue <Thing> ::~Queue(){
    Clear();
} 

template <typename Thing>
class Node
{
public:
    Thing D;
    Node<Thing>* Next;
};

template <typename Thing>
class Stack
{
    Node<Thing>* Top;
    int N;
public:
    Stack();//construtor
    int size();//tamanho
    bool Empty();//vazia
    Thing TOP(); //retorna quem ta no topo
    bool Push(Thing T); //insere na pilha
    void Pop(); //retira da pilha
    void Clear(); //limpa
    ~Stack(); //destrutor
};

template <typename Thing>
Stack<Thing>::Stack() //construtor
{
    Top=nullptr;
    N=0;
}

template <typename Thing>
int Stack<Thing>::size()
{
    return N;
}

template <typename Thing>
bool Stack<Thing>::Empty()
{
    return !Top;
}

template <typename Thing>
Thing Stack<Thing>:: TOP()
{
    if(!N){
        throw runtime_error("Pilha vazia."); //throw sendo a exceção
                                            //como se fosse um break
    }
    return Top->D;
}

template <typename Thing>
bool Stack<Thing>::Push(Thing T)
{
    Node<Thing>* P= new Node<Thing>;
    if(!P)
    {
        return false;
    }
    P->D=T;
    P->Next=Top;
    Top=P;
    N++;
    return true;
}

template <typename Thing>
void Stack<Thing>::Pop(){
    if(!Empty()){
        Node<Thing>* P=Top;
        Top=Top->Next;
        delete P;
        N--;
    }
    
}

template <typename Thing>
void Stack<Thing>::Clear(){
    Node<Thing>* P;
    while(Top){
        P=Top;
        Top=Top->Next;
        delete P;
    }
    N=0;
}

template <typename Thing>
Stack<Thing>::~Stack(){
    Clear();
}

void inserirFichaEmTorre(char ficha, int torreInicial, Stack<char>& s1, Stack<char>& s2, Stack<char>& s3, Stack<char>& s4, Stack<char>& s5, Stack<char>& s6)
{

    Stack<char>* torres[6] = { &s1, &s2, &s3, &s4, &s5, &s6 };
    int tentativas = 0;
    int torre = torreInicial - 1; // transformar 1~6 em 0~5

    while (tentativas < 6) {
        if (torres[torre]->size() < 6) {
            torres[torre]->Push(ficha);
            return;
        } else {
            torre = (torre + 1) % 6;
            tentativas++;
        }
    }
}

int main(){
    Queue<string> q1,q2,q3,q4;
    Stack<char> s1,s2,s3,s4,s5,s6;

    //entrada
    for(int i=0;i<52;i++){
        string jogada;
        getline(cin,jogada);   
        switch(jogada[0]){
            case '1': 
                q1.Push(jogada);
                break;
            case '2':
                q2.Push(jogada);
                break;
            case '3': 
                q3.Push(jogada);
                break;
            case '4':  
                q4.Push(jogada);
                break;
        }
    }
    while(!q1.Empty()&&!q2.Empty()&&!q3.Empty()&&!q4.Empty()){//verifica se as filas n estao vazias
        string rodada[4]= {q1.Front(),q2.Front(),q3.Front(),q4.Front()}; //forma um vetor com as jogadas da rodada 
        q1.Pop(),q2.Pop(),q3.Pop(),q4.Pop();

        for(int i=0;i<4;i++){
            string mao=rodada[i];
            char cor=mao[1];
            int torre=mao[2]-0;// -0 pra transformar char em int

            if (cor == 'P') {
                // Ficha preta: remove topo da torre, se houver
                switch (torre) {
                    case 1: if (!s1.Empty()) s1.Pop(); break;
                    case 2: if (!s2.Empty()) s2.Pop(); break;
                    case 3: if (!s3.Empty()) s3.Pop(); break;
                    case 4: if (!s4.Empty()) s4.Pop(); break;
                    case 5: if (!s5.Empty()) s5.Pop(); break;
                    case 6: if (!s6.Empty()) s6.Pop(); break;
                }
            } else {
                // Ficha colorida: inserir na torre com fallback
                inserirFichaEmTorre(cor, torre, s1, s2, s3, s4, s5, s6);
            }
        }
    }
}
