#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){

   int N=0;
   cin>>N;
   cin.ignore();

   for(int i=0;i<N;i++){
        int diamante=0;
        string linha;
        getline(cin, linha);
        stack <char> P;

        for(char c: linha){ //um caracter c que vai percorrer a minha string
            if(c=='<'){
            P.push(c);
        }else if(c=='>'){
            if(!P.empty()){
                diamante++;
                P.pop();
            }
            
        }
    }
    cout<<diamante<<endl;

   }
   return 0;
}
