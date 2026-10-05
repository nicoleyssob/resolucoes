#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main(){
    int N;
    do{
        cin>>N;
        if(N>50||N==0){
            break;
        }
        queue <int> P; //"pilha" de cartas
        queue <int> Q;// fila de descartes
        for(int i=1;i<=N;i++){
            P.push(i); //insere na "pilha"
        }
        while(P.size()>1) //enquanto tiver mais q 1 elemento na "pilha"
        {
            int x;
            x=P.front();//retorna e guarda o topo
            Q.push(x);//insere nos descartes
            P.pop();//retira o topo
            int base;
            base=P.front();//retorna e guarda a nova base
            P.pop();//retira o topo
            P.push(base);//insere esse topo antigo na base da pilha(rabo da fila)

        }
        cout<<"Discarted cards: ";
        while(!Q.empty()){
            cout<<Q.front();
            Q.pop();
            if(!Q.empty()){//n imprime a virgula se for o ultimo elemento 
                cout<<", ";
            }
        }
        cout<<"\nRemaining card: "<<P.front()<<endl;

    }while (N);
}