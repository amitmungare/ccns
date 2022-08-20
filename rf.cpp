#include<iostream>
#include<string.h> 
using namespace std; 
string encryptMsg(char msg[], int key){

    int l = strlen(msg);
    int k = -1, row = 0, col = 0;
    char mat[key][l]; 

    for(int i = 0; i < key; ++i)
        for(int j = 0; j < l; ++j)
            mat[i][j] = '\n'; 

    for(int i = 0; i < l; ++i){
        mat[row][col++] = msg[i]; 
        if(row==0 || row==key-1)k*=-1; 
        row +=k;
    } 

    string op="";
    cout<<"\nEncrypted Message: "; 
    for(int i = 0; i < key; ++i)
        for(int j = 0; j < l; ++j)
            if(mat[i][j] != '\n'){
                cout<<mat[i][j];
                op+=mat[i][j];
            }

    return op;
} 

void decryptMsg(char enMsg[], int key){
    int l = strlen(enMsg);
    int k = -1, row = 0, col = 0, m = 0;
    char mat[key][l];
 
    for(int i = 0; i < key; ++i)
        for(int j = 0; j < l; ++j)
            mat[i][j] = '\n'; 

    for(int i = 0; i < l; ++i){
        mat[row][col++] = '*'; 
        if(row==0 || row==key-1)k=k*-1; 
        row=row+k;
    }

    for(int i = 0; i < key; ++i)
        for(int j = 0; j < l; ++j)
            if(mat[i][j] == '*')
                mat[i][j] = enMsg[m++]; 

    row = col = 0;
    k = -1; 

    cout<<"\nDecrypted Message: "; 
    for(int i = 0; i < l; ++i){
        cout<<mat[row][col++];
        if(row==0 || row==key-1)k=k*-1; 
        row=row+k;
    }
} 
int main(){
    char msg[] = "amitmungare";
    int key = 2; 

    cout<<"Original Message: "<<msg; 
    string s = encryptMsg(msg, key);
    char enc[4];
    strcpy(enc, s.c_str());

    decryptMsg(enc, key); 
    return 0;
}
