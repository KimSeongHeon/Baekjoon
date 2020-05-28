#include<iostream>
#include <string>
#include <vector>
using namespace std;
int map[101][101];
bool check_gidung(int x,int y) {
	if (x == 0) return true;
	else if (map[x - 1][y] == 1) return true;
	else if()
	return false;

}
bool check_bo(int x,int y) {

}
vector<vector<int>> solution(int n, vector<vector<int>> frame) {
	vector<vector<int>> answer;
	for (int i = 0; i < frame.size(); i++) {
		if (frame[i][2] == 0) { //±âµÕ
			if(check_gidung(frame[i][0], frame[i][1])) map[frame[i][0]][frame[i][1]] = 1;
		}
		else if (frame[i][2] == 1) { // º¸
			if (check_bo(frame[i][0], frame[i][1])) map[frame[i][0]][frame[i][1]] = 1;

		}
	}
	return answer;
}
int main(){
	//[[1,0,0,1],[1,1,1,1],[2,1,0,1],[2,2,1,1],[5,0,0,1],[5,1,0,1],[4,2,1,1],[3,2,1,1]]
	vector<vector<int>> a;
	a.push_back({ 1,0,0,1 });
	a.push_back({ 1,1,1,1 });
	a.push_back({ 2,1,0,1 });
	a.push_back({ 2,2,0,1 });
	a.push_back({ 5,0,0,1 });
	a.push_back({ 5,1,0,1 });
	a.push_back({ 4,2,1,1 });
	a.push_back({ 3,2,1,1 });
	vector<vector<int>> b = solution(5, a);
	for (int i = 0; i < b.size(); i++) {
		for (int j = 0; j < b[i].size(); j++) {
			cout << b[i][j] << " ";
		}
		cout << endl;
	}

}