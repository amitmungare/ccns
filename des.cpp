#include <iostream>
#include <string>
using namespace std;
string hex2bin(string p){
    string ap = "";
    int l = p.length();
    for (int i = 0; i < l; i++){
        string st = "";
        if (p[i] >= '0' && p[i] <= '9'){
            int te = int(p[i]) - 48;
            while (te > 0)
            {
                st += char(te % 2 + 48);
                te /= 2;
            }
            while (st.length() != 4)
                st += '0';
            for (int j = 3; j >= 0; j--)
                ap += st[j];
        }else{
            int te = p[i] - 'A' + 10;
            while (te > 0){
                st += char(te % 2 + 48);
                te /= 2;
            }
            for (int j = 3; j >= 0; j--)
                ap += st[j];
        }
    }
    return ap;
}

int main(){
    string p, l, r, ap = "", ke, kp, rtem;
    string pp1[64], lo[32], ro[32], ero[48];

    string key1[56], lkey[28], rkey[28];
    cout << "Enter the key in hexadecimal form (16bit) \n";
    cin >> ke;

    p = hex2bin(p);
    kp = hex2bin(ke);

    for (int i = 0; i < 64; i++)
        cout << kp[i];
    cout << endl;
    int keyp1[56] = {57, 49, 41, 33, 25, 17, 9,1, 58, 50, 42, 34, 26, 18,10, 2, 59, 51, 43, 35, 27,19, 11, 3, 60, 52, 44, 36,63, 55, 47, 39, 31, 23, 15,7, 62, 54, 46, 38, 30, 22,14, 6, 61, 53, 45, 37, 29, 21, 13, 5, 28, 20, 12, 4};

    cout << "Applying permutation 1" << endl;
    for (int i = 0; i < 56; i++){
        int indx = keyp1[i];
        key1[i] = kp[indx - 1];
        cout << key1[i];
    }
    cout << endl;

    for (int i = 0; i < 28; i++){
        lkey[i] = key1[i];
        cout << lkey[i];
    }
    cout << endl;

    int index = 28;
    for (int i = 0; i < 28; i++){
        rkey[i] = key1[index];
        index++;
        cout << rkey[i];
    }
    cout << endl;

    string key[16][48], keyip1[56], keyip2[48], temp1, temp2, pkey[56];
    // LEFT SHIFT
    temp1 = lkey[0];
    temp2 = rkey[0];
    for (int j = 0; j < 27; j++){
        lkey[j] = lkey[j + 1];
        rkey[j] = rkey[j + 1];
    }
    lkey[27] = temp1;
    rkey[27] = temp2;

    cout << "After right shift by 1" << endl;
    cout << "Left subkey" << endl;
    for (int j = 0; j < 28; j++){
        cout << lkey[j];
    }
    cout << endl;
    cout << "Right subkey" << endl;
    for (int j = 0; j < 28; j++){
        cout << rkey[j];
    }
    cout << endl;

    // CONCATENATE LEFT AND RIGHT KEY
    for (int i = 0; i < 28; i++)
        keyip1[i] = lkey[i];
    int idx = 0;
    for (int i = 28; i < 56; i++){
        keyip1[i] = rkey[idx];
        idx++;
    }
    // OUTPUT 56 bit key
    cout << "56 bit key is given as" << endl;
    for (int i = 0; i < 56; i++)
        cout << keyip1[i];
    cout << endl;

    int keyp2[48] = {14, 17, 11, 24, 1, 5, 3, 28, 15, 6, 21, 10, 23, 19, 12, 4, 26, 8, 16, 7, 27, 20, 13, 2, 41, 52, 31, 37, 47, 55, 30, 40, 51, 45, 33, 48, 44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32};

    cout << endl;

    cout << "Applying permutation 2 THE 48 BIT KEY IS GIVEN AS" << endl;
    for (int i = 0; i < 48; i++){
        int indx = keyp2[i];
        keyip2[i] = keyip1[indx - 1];
        cout << keyip2[i];
    }
    cout << endl;

    // PLAINTEXT

    for (int i = 0; i < 64; i++)
        cout << p[i];
    cout << endl;

    int ip[64] = {58, 50, 42, 34, 26, 18, 10, 2,60, 52, 44, 36, 28, 20, 12, 4,62, 54, 46, 38, 30, 22, 14, 6,64, 56, 48, 40, 32, 24, 16, 8,57, 49, 41, 33, 25, 17, 9, 1,59, 51, 43, 35, 27, 19, 11, 3,61, 53, 45, 37, 29, 21, 13, 5,63, 55, 47, 39, 31, 23, 15, 7};

    cout << "Applying permutation 1" << endl;
    for (int i = 0; i < 64; i++){
        int indx1 = ip[i];
        pp1[i] = p[indx1 - 1];
        cout << pp1[i];
    }
    cout << endl;

    for (int i = 0; i < 32; i++){
        lo[i] = pp1[i];
        cout << lo[i];
    }
    cout << endl;

    int index3 = 32;
    for (int i = 0; i < 32; i++){
        ro[i] = pp1[index3];
        index++;
        cout << ro[i];
    }

    int epp1[48] = {12, 1, 2, 3, 4, 5, 4, 5,6, 7, 8, 9, 8, 9, 10, 11,12, 13, 12, 13, 14, 15, 16, 17,16, 17, 18, 19, 20, 21, 20, 21,22, 23, 24, 25, 24, 25, 26, 27,28, 29, 28, 29, 30, 31, 32, 1};

    cout << "Applying expansion of Ro" << endl;
    for (int i = 0; i < 48; i++){
        int index2 = epp1[i];
        ero[i] = ro[index2 - 1];
        cout << ero[i];
    }
    cout << endl;

    string res[48];
    cout << "Bitwise XOR" << endl;
    for (int i = 0; i < 48; i++){
        if ((ero[i] == "0" && keyip2[i] == "0") || (ero[i] == "1" && keyip2[i] == "1"))
            res[i] = "0";

        if ((ero[i] == "0" && keyip2[i] == "1") || (ero[i] == "1" && keyip2[i] == "0"))
            res[i] = "1";

        cout << res[i];
    }
    cout << endl;

    // SBOX
    int s1[4][16] = {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7,0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8,4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0,15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13};

    int s2[4][16] = {15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10,3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5,0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15,13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9};

    int s3[4][16] = {10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8,13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1,13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7,1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12};

    int s4[4][16] = {7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15,13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9,10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4,3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14};

    int s5[4][16] = {2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9,14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6,4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14,11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3};

    int s6[4][16] = {12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11, 10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8, 9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6, 4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13};

    int s7[4][16] = {4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1, 13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6, 1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2, 6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12};

    int s8[4][16] = {13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7, 1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2, 7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8, 2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11};

    for (int i = 0; i < 6; i++){
        string a = res[i];
    }
}
