#include<iostream>
#include <string>
#include <vector>
#include<map>
using namespace std;
#define ALPHABET 26
int char_to_index(char c) {
	return c - 'a';
}
class Trie {
public:
	bool is_terminal;
	Trie *children[ALPHABET];
	int cnt = 0;
	Trie() : is_terminal(false) {
		memset(children, 0, sizeof(children));
	}
	~Trie() {
		for (int i = 0; i < 26; ++i) {
			if (children[i])
				delete children[i];
		}
	}
	void insert(const char * key) {
		cnt++;
		if (*key == '\0') {
			is_terminal = true;
		}
		else {
			int index = char_to_index(*key);
			if (children[index] == 0) {
				children[index] = new Trie();
			}
			children[index]->insert(key + 1);
		}
	}
	Trie* find(const char * key) {
		if (*key == 0) {
			return this;
		}
		int index = char_to_index(*key);
		if (children[index] == 0) {
			return NULL;
		}
		return children[index]->find(key + 1);
	}
};
int solution(vector<string> words) {
	int answer = 0;
	Trie *root = new Trie();
	for (int i = 0; i < words.size(); i++) root->insert(words[i].c_str());
	for (int i = 0; i < words.size(); i++) {
		bool check = false;
		for (int j = 0; j <= words[i].length(); j++) {
			string temp = words[i].substr(0, j);
			if (root->find(temp.c_str())->cnt == 1) {
				check = true;
				answer = answer + j;
				break;
			}
		}
		if (!check) answer = answer + words[i].length();
	}
	return answer;
}
int main() {
	vector<string> a;
	a = {"go","gone","guild"};
	cout << solution(a);
}