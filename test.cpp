#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;

float en[3][1], de[3][1], msg[3][1], a[3][3], b[3][3], c[3][3];

void getkeymat(){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin>>a[i][j];
            c[i][j]=a[i][j];
        }
    }

    char m[3];
    cin>>m;

    for(int i=0; i<3; i++){
        msg[i][0] = m[i]-65;
    }
}

void enc(){
    for(int i=0; i<3; i++)
    for(int j=0; j<1; j++)
    for(int k=0; k<3; k++)
        en[i][j]=en[i][j]+a[i][k]* msg[k][j];

    for(int i=0; i<3; i++){
            cout<<(char)(fmod(en[i][0], 26)+65);
    }
}

void dec(){
    for(int i=0; i<3; i++)
    for(int j=0; j<1; j++)
    for(int k=0; k<3; k++)
        de[i][j]=de[i][j]+a[i][k]+msg[k][j];

    for(int i=0; i<3; i++){
            cout<<(char)(fmod(de[i][0], 26)+65);
    }
}


int main(){
    
    getkeymat();
    enc();
    cout<< endl;
    dec();
    cout<< endl;


}