#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main(){
    string N;
    queue <string> oeste;
    queue <string> norte;
    queue <string> sul;
    queue <string> leste;
    
    while(getline(cin,N)&&N!="0"){
        if(N=="-1"){
            while(getline(cin,N)&&N!="-3"&&N!="-2"&&N!="-4"){
                oeste.push(N);
            }
        }if(N=="-3"){
            while(getline(cin,N)&&N!="-1"&&N!="-2"&&N!="-4"){
                norte.push(N);
            }
        }if(N=="-2"){
            while(getline(cin,N)&&N!="-1"&&N!="-3"&&N!="-4"){
                sul.push(N);
            }
        }if(N=="-4"){
            while(getline(cin,N)&&N!="-1"&&N!="-2"&&N!="-3"){
                leste.push(N);
            }
        }
    }

    while(!oeste.empty()||!norte.empty()||!sul.empty()||!leste.empty()){
        if(!oeste.empty()){
            cout<<oeste.front()<<" "<<endl;
            oeste.pop();
        }
        if(!norte.empty()){
            cout<<norte.front()<<" "<<endl;
            norte.pop();
        }
        if(!sul.empty()){
            cout<<sul.front()<<" "<<endl;
            sul.pop();
        }
        if(!leste.empty()){
            cout<<leste.front()<<" "<<endl;
            leste.pop();
        }
    }
    return 0;
}