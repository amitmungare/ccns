#include<iostream>
#include<math.h>
using namespace std;

float en[3][1], de[3][1], msg[3][1], a[3][3], b[3][3], c[3][3];

void getKeyMatrix() {

   cout<<"Enter 3x3 matrix for key (should have inverse):\n";
   for(int i = 0; i < 3; i++)
   for(int j = 0; j < 3; j++) {
      cin>>a[i][j];
      c[i][j] = a[i][j];
   }

   char mes[3];
   cout<<"\nEnter a string of 3 letter(use A through Z): ";
   cin>>mes;
   for(int i = 0; i < 3; i++)
        msg[i][0] = mes[i] - 65;
}

void encrypt() { 
   
   for(int i = 0; i < 3; i++)
   for(int j = 0; j < 1; j++)
   for(int k = 0; k < 3; k++)
        en[i][j] = en[i][j] + a[i][k] * msg[k][j];

   cout<<"\nEncrypted string is: ";
   for(int i = 0; i < 3; i++)
        cout<<(char)(fmod(en[i][0], 26) + 65); 
}

void inversematrix() { 
   
   float p, q;
   for(int i = 0; i < 3; i++)
   for(int j = 0; j < 3; j++) {
      if(i == j)
         b[i][j]=1;
      else
         b[i][j]=0;
   }

   for(int k = 0; k < 3; k++) {
      for(int i = 0; i < 3; i++) {
         p = c[i][k];
         q = c[k][k];
         for(int j = 0; j < 3; j++) {
            if(i != k) {
               c[i][j] = c[i][j]*q - p*c[k][j];
               b[i][j] = b[i][j]*q - p*b[k][j];
            }
         }
      }
   }

   for(int i = 0; i < 3; i++)
   for(int j = 0; j < 3; j++)
      b[i][j] = b[i][j] / c[i][i];

   cout<<"\n\nInverse Matrix is:\n";
   for(int i = 0; i < 3; i++) {
      for(int j = 0; j < 3; j++)
      cout<<b[i][j]<<" ";
      cout<<"\n";
   }
}
void decrypt() { 
   
   inversematrix();

   for(int i = 0; i < 3; i++)
   for(int j = 0; j < 1; j++)
   for(int k = 0; k < 3; k++)
        de[i][j] = de[i][j] + b[i][k] * en[k][j];

   cout<<"\nDecrypted string is: ";
   for(int i = 0; i < 3; i++)
        cout<<(char)(fmod(de[i][0], 26) + 65);

   cout<<"\n";
}

int main() {
   getKeyMatrix();
   encrypt();
   decrypt();
}