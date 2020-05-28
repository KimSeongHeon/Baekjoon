#include<iostream>
#include <string>
#include <vector>
#include<queue>
#include<tuple>
#include<map>
using namespace std;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 0,0,1,-1 };
map < pair<pair<int,int>,pair<int, int>>, bool> m;
typedef tuple < int,pair<int, int>, pair<int, int>> mov;
struct cmp {
	bool operator()(mov &u, mov &v) { 
		return get<0>(u) > get<0>(v); 
	}
};
priority_queue<mov, vector<mov>, cmp> q;
int solution(vector<vector<int>> board) {
	int answer = -1;
	q.push({ 0,{0,0},{0,1} });
	m.insert({{ { 0,0 }, { 0,1 } }, true});
	int size = board.size();
	while (!q.empty()) {
		mov temp = q.top(); q.pop();
		int x1 = get<1>(temp).first;
		int y1 = get<1>(temp).second;
		int x2 = get<2>(temp).first;
		int y2 = get<2>(temp).second ;
		int depth = get<0>(temp);
		cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " <<depth <<endl;
		if (get<1>(temp).first == size - 1 && get<1>(temp).second == size - 1) return get<0>(temp);
		if (get<2>(temp).first == size - 1 && get<2>(temp).second == size - 1) return get<0>(temp);
		for (int i = 0; i < 4; i++) {
			int depth = get<0>(temp);
			int nx1 = get<1>(temp).first + dx[i];
			int ny1 = get<1>(temp).second +dy[i];
			int nx2 = get<2>(temp).first + dx[i];
			int ny2 = get<2>(temp).second + dy[i];
			if (nx1 >= 0 && nx1 < size && nx2 >= 0 && nx2 < size && ny1 >= 0 && ny1 < size && ny2 >= 0 && ny2 < size) {
				if (m.find({ {nx1,ny1}, {nx2,ny2} }) == m.end() && board[nx1][ny1] == 0 && board[nx2][ny2] == 0) {
					q.push({ depth + 1,{nx1,ny1},{nx2,ny2} });
					m.insert({ { {nx1,ny1}, {nx2,ny2} },true });
				}
			}
		}
		//회전
		//0번 점을 피봇으로 잡음
		if (x1 == x2) {
			//1번점 피봇
			// 아래 회전
			if (x2+1<=size-1) {
				if (board[x1 + 1][y1] == 0 && board[x2 + 1][y2] == 0) {
					int nx1 = x1;
					int ny1 = y1;
					int nx2 = x1 + 1;
					int ny2 = y1;
					if (m.find({ {nx1,ny1}, {nx2,ny2} }) == m.end() && board[nx1][ny1] == 0 && board[nx2][ny2] == 0) {
						q.push({ depth + 1,{nx1,ny1},{nx2,ny2} });
						m.insert({ { {nx1,ny1}, {nx2,ny2} },true });
					}
				}
			}
			// 위 회전
			if ( x2 - 1 >= 0) {
				if (board[x1 - 1][y1] == 0 && board[x2 - 1][y2] == 0) {
					int nx1 = x1;
					int ny1 = y1;
					int nx2 = x1 - 1;
					int ny2 = y1;
					if (m.find({ {nx1,ny1}, {nx2,ny2} }) == m.end() && board[nx1][ny1] == 0 && board[nx2][ny2] == 0) {
						q.push({ depth + 1,{nx1,ny1},{nx2,ny2} });
						m.insert({ { {nx1,ny1}, {nx2,ny2} },true });
					}
				}
			}
			// 2번점 피봇
			//위회전
			if ( x1 - 1 >= 0) {
				if (board[x2 - 1][y2] == 0 && board[x1 - 1][y1] == 0 ) {
					int nx1 = x2 - 1;
					int ny1 = y2;
					int nx2 = x2;
					int ny2 = y2;
					if (m.find({ {nx1,ny1}, {nx2,ny2} }) == m.end() && board[nx1][ny1] == 0 && board[nx2][ny2] == 0) {
						q.push({ depth + 1,{nx1,ny1},{nx2,ny2} });
						m.insert({ { {nx1,ny1}, {nx2,ny2} },true });
					}
				}
			}
			//아래회전
			if ( x1 + 1 <= size-1) {
				if (board[x2 + 1][y2] == 0 && board[x1 + 1][y1] == 0 ) {
					int nx1 = x2 + 1;
					int ny1 = y2;
					int nx2 = x2;
					int ny2 = y2;
					if (m.find({ {nx1,ny1}, {nx2,ny2} }) == m.end() && board[nx1][ny1] == 0 && board[nx2][ny2] == 0) {
						q.push({ depth + 1,{nx1,ny1},{nx2,ny2} });
						m.insert({ { {nx1,ny1}, {nx2,ny2} },true });
					}
				}
			}
		}
		else if (y1 == y2) {
			//1번점 피봇
			// 아래 회전
			if (y2 + 1 <= size - 1) {
				if (board[x1][y1+1] == 0 && board[x2][y2 + 1] == 0) {
					int nx1 = x1;
					int ny1 = y1;
					int nx2 = x1;
					int ny2 = y1+1;
					if (m.find({ {nx1,ny1}, {nx2,ny2} }) == m.end() && board[nx1][ny1] == 0 && board[nx2][ny2] == 0) {
						q.push({ depth + 1,{nx1,ny1},{nx2,ny2} });
						m.insert({ { {nx1,ny1}, {nx2,ny2} },true });
					}
				}
			}
			// 위 회전
			if ( y2 - 1 >= 0) {
				if (board[x1][y1 - 1] == 0 && board[x2][y2 - 1] == 0) {
					int nx1 = x1;
					int ny1 = y1;
					int nx2 = x1;
					int ny2 = y1 - 1;
					if (m.find({ {nx1,ny1}, {nx2,ny2} }) == m.end() && board[nx1][ny1] == 0 && board[nx2][ny2] == 0) {
						q.push({ depth + 1,{nx1,ny1},{nx2,ny2} });
						m.insert({ { {nx1,ny1}, {nx2,ny2} },true });
					}
				}
			}
			// 2번점 피봇
			//위회전
			if ( y1 - 1 >= 0) {
				if (board[x2][y2 - 1] == 0 && board[x1][y1 - 1] == 0) {
					int nx1 = x2;
					int ny1 = y2 - 1;
					int nx2 = x2;
					int ny2 = y2;
					if (m.find({ {nx1,ny1}, {nx2,ny2} }) == m.end() && board[nx1][ny1] == 0 && board[nx2][ny2] == 0) {
						q.push({ depth + 1,{nx1,ny1},{nx2,ny2} });
						m.insert({ { {nx1,ny1}, {nx2,ny2} },true });
					}
				}
			}
			//아래회전
			if ( y1 + 1 <= size-1) {
				if (board[x2][y2 + 1] == 0 && board[x1][y1 + 1] == 0) {
					int nx1 = x2;
					int ny1 = y2 + 1;
					int nx2 = x2;
					int ny2 = y2;
					if (m.find({ {nx1,ny1}, {nx2,ny2} }) == m.end() && board[nx1][ny1] == 0 && board[nx2][ny2] == 0) {
						q.push({ depth + 1,{nx1,ny1},{nx2,ny2} });
						m.insert({ { {nx1,ny1}, {nx2,ny2} },true });
					}
				}
			}
		}

	}
	return answer;
}
int main() {
	//[[0, 0, 0, 1, 1],[0, 0, 0, 1, 0],[0, 1, 0, 1, 1],[1, 1, 0, 0, 1],[0, 0, 0, 0, 0]]
	vector<vector<int>> a;
	a.push_back({ 0, 0, 0, 1, 1 });
	a.push_back({ 0, 0, 0, 1, 0 });
	a.push_back({ 0, 1, 0, 1, 1 });
	a.push_back({ 1, 1, 0, 0, 1 });
	a.push_back({ 0, 0, 0, 0, 0 });
	cout << solution(a);
	return 0;
}