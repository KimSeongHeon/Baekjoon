#include<iostream>
#include<algorithm>
#include<memory.h>

using namespace std;

int cache[1000001];

int calculate(int n)
{
	if (n <= 1) {
		return 0;
	}
	if (cache[n] != 0) {
		return cache[n];
	}
	else
	{
		if (n % 3 == 0 && n % 2 == 0)
		{
			cache[n] = min(calculate(n / 3) + 1, min(calculate(n / 2) + 1, calculate(n - 1) + 1));
		}
		else if (n % 3 == 0)
		{
			cache[n] = min(calculate(n / 3) + 1, calculate(n - 1) + 1);
		}
		else if(n % 2 == 0)
		{
			cache[n] = min(calculate(n / 2) + 1, calculate(n - 1) + 1);
		}
		else
		{
			cache[n] = calculate(n - 1) + 1;
		}
		return cache[n];
	}
}

int main() 
{
	cache[2] = 1;
	cache[3] = 1;
	cache[1] = 0;
	int data;
	cin >> data;
	cout<<calculate(data);

}
