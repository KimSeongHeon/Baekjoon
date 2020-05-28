#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
#include<queue>
using namespace std;
queue<string> q;
bool cmp(string &a, string &b) {
	string a_temp;
	string b_temp;
	a_temp = a.substr(0, 2);
	b_temp = b.substr(0, 2);
	if (a_temp == b_temp) {
		a_temp = a.substr(3,2);
		b_temp = b.substr(3,2);
		return atoi(a_temp.c_str()) < atoi(b_temp.c_str());
	}
	return atoi(a_temp.c_str()) < atoi(b_temp.c_str());
}
string next_time(string current, int m) {
	string hour;
	string minute;
	hour = current.substr(0,2);
	minute = current.substr(3,2);
	if (atoi(minute.c_str()) + m >= 60) {
		hour = to_string(atoi(hour.c_str()) + 1);
		minute = to_string(atoi(minute.c_str()) + m - 60);
	}
	else minute = to_string(atoi(minute.c_str()) + m);
	if(atoi(minute.c_str()) < 10) return hour + ":0" + minute;
	else return hour + ":" + minute;
}
string before_oneminute(string current) {
	string hour;
	string minute;
	hour = current.substr(0, 2);
	minute = current.substr(3, 2);
	if (atoi(minute.c_str()) -1 < 0) {
		hour = to_string(atoi(hour.c_str()) - 1);
		minute = to_string(59);
	}
	else minute = to_string(atoi(minute.c_str()) - 1);
	if (atoi(minute.c_str()) - 1 < 10) return hour + ":0" + minute;
	else return hour + ":" + minute;
}
string solution(int n, int t, int m, vector<string> timetable) {
	string answer = "";
	sort(timetable.begin(), timetable.end(),cmp);
	for (int i = 0; i < timetable.size(); i++) {
		q.push(timetable[i]);
	}
	string arrive = "09:00";
	for (int i = 0; i < n; i++) {
		arrive = next_time(arrive, t);
		
	}
	return answer;
}
int main() {
	vector<string> s;
	s = { "08:00", "08:01", "08:02", "08:03" };
	cout << solution(1, 1, 5, s) << endl;
	s = { "09:10", "09:09", "08:00" };
	cout << solution(2, 10, 2, s) << endl;
	return 0;
}