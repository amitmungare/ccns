#include<iostream>
#include<string>
using namespace std;

string enc(int k, string m){
    string op;
    for(int i=0;i<m.size();i++)
        op+=(m[i]-'A'+k)%26+'A';
    return op;
}

string dec(int k, string e){
    string op;
    for(int i=0;i<e.size();i++)
        op+=(e[i]-'A'-k+26)%26+'A';
    return op;
}

int main(){
    string m="ABC";
    int k=2;
    string e = enc(k, m);
    string d = dec(k,e);
    cout<<"\nMessage is "<<m;
    cout<<"\nEncrypted message is "<<e;
    cout<<"\nDecrypted message is "<<d;
    
    return 0;
}

