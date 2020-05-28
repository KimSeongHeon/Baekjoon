#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;
struct disk {
	int idx;
	int during;
};
struct camp{
	bool operator()(disk a, disk b) {
		if (a.during == b.during) return a.idx > b.idx;
		return a.during > b.during;
	}
};
priority_queue<disk,vector<disk>,camp> q;
set<int> s;
bool cmp(vector<int> &a, vector<int> &b) {
	if (a[0] == b[0]) return a[1] < b[1];
	return a[0] < b[0];
}
int solution(vector<vector<int>> job) {
	int answer = 0;
	for (int i = 0; i < job.size(); i++) s.insert(i);
	sort(job.begin(), job.end(), cmp);
	q.push({job[0][0],job[0][1]});
	s.erase(s.find(0));
	int idx = job[0][0];
	int during = job[0][1];
	int pre_dist = idx + during;
	vector<disk> ans;
	int check = 0;
	while (!q.empty()) {
		if (check == 1) {
			pre_dist = idx + during;
		}
		else if (check == 2) {
			pre_dist = pre_dist + during;
		}
		disk temp= q.top(); q.pop();
		idx = temp.idx; //start 지점
		during = temp.during; //기간
		//cout << idx << " " << during << endl;
		ans.push_back(temp);
		vector<int> delete_list;
		for (auto iter = s.begin(); iter != s.end();iter++) {
			if (pre_dist >= job[(*iter)][0]) {
				q.push({ job[(*iter)][0],job[(*iter)][1]});
				delete_list.push_back((*iter));
			}
		}
		if (delete_list.size() == 0) { //한번도 안 겹친 경우
			check = 1;
			int m = 987654321;
			int idx = -1;
			//cout << s.size() << endl;
			if (s.empty()) continue;
			for (auto iter = s.begin(); iter != s.end(); iter++) {
				m = min(m, job[(*iter)][0]);
				if (m == job[(*iter)][0]) idx = *iter;
			}
			//cout << idx << endl;
			q.push({ job[idx][0],job[idx][1] });
			s.erase(s.find(idx));
		}
		else { //겹친경우
			check = 2;
			for (int i = 0; i < delete_list.size(); i++) {
				s.erase(s.find(delete_list[i]));
			}
		}
		
	}
	int start = ans[0].idx;
	int dist = ans[0].during;
	int pre_dest = start + dist;
	answer = answer + dist;
	//cout << start << " " << dist << endl;
	for (int i = 1; i < ans.size(); i++) {
		start = ans[i].idx;
		dist = ans[i].during;
		//cout << start << " " << dist << endl;
		if (pre_dest > start) {
			answer = answer + pre_dest - start + dist;
			pre_dest = pre_dest + dist;
		}
		else {
			answer = answer + dist;
			pre_dest = start + dist;
		}
	}
	answer = answer / job.size();
	return answer;
}
int main() {
	vector<vector<int>> a;
	a.push_back({ 0,3 });
	a.push_back({ 1,9 });
	a.push_back({2500,6});
	cout << solution(a);
	return 0;
}