#include <string>
#include <vector>
#include<stack>
#include<iostream>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	stack<int> s;
	for (int i = 0; i < moves.size(); i++) {
		int temp = 0;
		for (int j = 0; j < board.size(); j++) {
			if (board[j][moves[i]-1] != 0) {
				temp = board[j][moves[i] - 1];
				board[j][moves[i]-1] = 0;
				break;
			}
		}
		if (temp != 0) {
			if (!s.empty()) {
				if (temp == s.top()) {
					s.pop();
					answer++;
				}
				else {
					s.push(temp);
				}
			}
			else {
				s.push(temp);
			}
		}
	}
	return 2*answer;
}

int main() {

}