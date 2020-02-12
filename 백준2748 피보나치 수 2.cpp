#include<iostream>
using namespace std;
int n;
unsigned long long cache[91];
unsigned long long fibo(int x) {
	if (x == 0) return cache[0] = 0;
	else if (x == 1) return cache[1] = 1;
	else if (x == 2) return cache[2] = 1;
	if (cache[x] != 0) return cache[x];
	else {
		return cache[x] = fibo(x - 1) + fibo(x - 2);
	}
}
int main(){
	cin >> n;
	cout << fibo(n);
	return 0;

}