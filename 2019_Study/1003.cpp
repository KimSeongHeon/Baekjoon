#include<iostream>
#include<memory.h>

using namespace std;

int cache[41];
int zero[41];
int one[41];

int fibonacci(int n) {
	
	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	else {
		if (cache[n] != 0) {
			return cache[n];
		}
		else {
			cache[n] = fibonacci(n - 1) + fibonacci(n - 2);
			one[n] = one[n - 1] + one[n - 2];
			zero[n] = zero[n - 1] + zero[n - 2];
			return cache[n];
		}
		
	}
}


int main() {
	int T;
	cin >> T;
	memset(cache, 0, sizeof(cache));
	cache[0] = 0;
	cache[1] = 1;
	zero[0] = 1;
	zero[1] = 0;
	one[0] = 0;
	one[1] = 1;

	for (int i = 1; i <= T; i++) {
		int data;
		cin >> data;
		fibonacci(data);
		cout << zero[data] << " " << one[data] << endl;
		
	}
}
