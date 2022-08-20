#include<iostream>
#include<math.h>
using namespace std;

int main(){
	long q = 83, p = 5, xa = 6, xb = 10, ya, yb, k1,k2;
	// long  q = 13, p = 6, xa = 3, xb = 10, ya, yb, k1,k2;
	ya = (long)(pow(p, xa))%q;
	yb = (long)(pow(p, xb))%q;
	k1 = (long)(pow(yb, xa))%q;
	k2 = (long)(pow(ya, xb))%q;

	cout << "Key at A=" << k1 << endl;
	cout << "Key at B=" << k2 << endl;

	return 0;
	
}