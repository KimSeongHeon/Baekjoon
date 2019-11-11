#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
using namespace std;

void change_match(int nWork[], vector<int>nPerson[], vector<pair<int, int>>stack, int i, int j) //매칭을 바꿔주는 함수.
{
	for (int k = 0; k < nPerson[i].size(); k++)
	{
		if (nPerson[i][k] != NULL && nPerson[i].size()>0) // 매칭을 바꿔줄 것 이 있을 경우.
		{
			int temp = nPerson[i][k];
			nPerson[i].erase(nPerson[i].begin() + k);
			stack.push_back(make_pair(temp, i));
			break;
		}
		else // 없을 경우.
		{

		}
	}
}

int main()
{
	//int nPerson[101][101];
	int nWork[1001];//일의 개수
	int nRow, nCol;//사람 수, 일의 개수
	vector<int>nPerson[1001];//사람 당 할 수 있는 일
	vector<pair<int,int>> stack; //할 수 있는 일을 담은 벡터
	cin >> nRow >> nCol;
	for (int i = 0; i < nRow; i++)
	{
		cin >> nWork[i];
		for (int j = 0; j < nWork[i]; j++)
		{
			int data;
			cin >> data;
			nPerson[i].push_back(data);
		}
	}
	vector<pair<int, int>>::iterator iter = stack.begin();
	//stack.push_back(make_pair(nPerson[0][0],1));
	cout << stack.size() << endl;
	//cout << "for문 전";
	for (int i = 0; i < nRow; i++)
	{
		for (int j = 0; j < nWork[i]; j++)
		{
			if (stack.empty())
			{
				cout << "empty"<<endl;
				cout << nPerson[i][j] << " " << i << endl;
				stack.push_back(make_pair(nPerson[i][j], i));
				break;
			}
			else
			{
				cout << "not empty" << endl;
				for (iter = stack.begin(); iter != stack.end(); iter++)
				{
					cout << " " << nPerson[i][j] << " / " << i << endl;
					if (iter->first== nPerson[i][j])
					{
						cout << "change_match 호출:" << endl;
						change_match(nWork, nPerson, stack, iter->second, j);
					}
					else
					{
						//cout << "????";
						stack.push_back(make_pair(nPerson[i][j], i));
						nPerson[i][j] = NULL;
						break;
					}
				}
			}
			
		
		}
	}
	for (int i = 0; i < stack.size(); i++)
	{
		cout << stack[i].first << " ";
	}
	cout << stack.size();
	return 0;
}
