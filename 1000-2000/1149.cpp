#include<iostream>
#include<memory.h>
#include<algorithm>

using namespace std;

int r_cache[1001];
int g_cache[1001];
int b_cache[1001];
int r_calculate(int cost[100][3], int n);
int g_calculate(int cost[100][3], int n);
int b_calculate(int cost[100][3], int n);

int r_calculate(int cost[1001][3],int n) 
{
	if (n == 1) {
		r_cache[1] = cost[1][0];
		return r_cache[1];
	}
	if (r_cache[n] != 0) {
		return r_cache[n];
	}
	else {
		r_cache[n] = min(b_calculate(cost, n - 1) + cost[n][0], g_calculate(cost, n - 1)+cost[n][0]);
		return r_cache[n];
	}
}
int g_calculate(int cost[1001][3], int n) {
	if (n == 1) {
		g_cache[1] = cost[1][1];
		return g_cache[1];
	}
	if (g_cache[n] != 0) {
		return g_cache[n];
	}
	else {
		g_cache[n] = min(r_calculate(cost, n - 1) + cost[n][1], b_calculate(cost, n - 1) + cost[n][1]);
		return g_cache[n];
	}

}
int b_calculate(int cost[1001][3], int n) {
	if (n == 1) {
		b_cache[1] = cost[1][2];
		return b_cache[1];
	}
	if (b_cache[n] != 0) {
		return b_cache[n];
	}
	else {
		b_cache[n] = min(r_calculate(cost, n - 1) + cost[n][2], g_calculate(cost, n - 1) + cost[n][2]);
		return b_cache[n];
	}

}
int main() 
{
	int num;
	cin >> num;
	int cost[1001][3];
	for (int i = 1; i <= num; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> cost[i][j];
		}
	}
	cout<<min(r_calculate(cost, num),min(g_calculate(cost,num),b_calculate(cost,num)));


}
