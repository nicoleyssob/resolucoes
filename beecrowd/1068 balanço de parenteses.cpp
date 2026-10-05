#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
        string expressao;
        while(getline(cin, expressao)){//loop pra pegar as expressoes enquanto o usuario digitar
            stack <char> P;
            bool flag=false;
            for(char c :expressao){
                if(c=='('){//se for começo de parenteses, empilha
                    P.push(c);
                }else if(c==')'){
                    if(P.empty()){//se a pilha tiver vazia e encontra o final, sinaliza erro
                        flag=true;
                    }else{//sem erro, retira um começo de parenteses
                        P.pop();
                    }
                }
            }
            if(P.empty()&&flag==false){
                cout<<"correct"<<endl;
            }else{
                cout<<"incorrect"<<endl;
            }
        }        
    return 0;
}