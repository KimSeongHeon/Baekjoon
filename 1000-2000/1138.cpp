#include<iostream>

using namespace std;

class edge
{
private:
	int node1, node2;//연결할 노드 2개 넘버
	int g;//가중치
public:
	edge(int node1,int node2,int g);
	~edge();
	//void connect(int node1, int node2,int g);
	//void set_g(int g);
	int get_g();
	int get_node1();
	int get_node2();
	void set_g(int n);
};

edge::edge(int num1,int num2,int weight)
{
	node1 = num1;
	node2 = num2;
	g = weight;
}

int edge::get_g()
{
	return g;
}
void edge::set_g(int n)
{
	g = n;
}
int edge::get_node1()
{
	return node1;
}
int edge::get_node2()
{
	return node2;
}
int find(int node, int *union_find) //node를 입력받았을 때, root를 찾아주는 find 구문.
{
	if (node == union_find[node])
	{
		return node; // 같으면 그게 root임.
	}
	else
	{
		int temp = find(union_find[node], union_find); //찾을때까지 재귀 돌림.
		union_find[node] = temp;
		return temp;
	}
}
void Union(int node1, int node2, int *union_find) //node1과 node2 연결.
{
	node1 = find(node1, union_find); //node1의 루트
	node2 = find(node2, union_find); //node2의 루트
	if (node1 != node2) //루트가 다르면
	{
		union_find[node2] = node1; //node1이 루트가 node2의 루트가 됨.
	}
}
bool is_cycle(edge *e_array,int *union_find,int i)
{
	if (i == 0 || i == 1) // 0과 1일때, 즉 엣지가 1개 2개일떄는 사이클이 안생김.
	{
		//왜 if?? node1과 node2중 작은값이 root가 되게 하려는 것
		if (e_array->get_node1() < e_array->get_node2())
		{
			Union(e_array->get_node1(), e_array->get_node2(), union_find); // 그냥 두개 묶어줌.
		}
		else
		{
			Union(e_array->get_node2(), e_array->get_node1(), union_find); // 이것두
		}
		return false; // 사이클이 안생긴다.
	}
	else // 사이클이 생길 가능성이 생김.
	{
		if (e_array->get_node1() < e_array->get_node2())
		{
			if (find(e_array->get_node2(), union_find) == find(e_array->get_node1(), union_find)) // 병합하기전, node1 과 node2 의 root가 같으면, union시 사이클이 생김.
			{
				return true; // 사이클이 생긴다.
			}
			else
			{
				Union(e_array->get_node1(), e_array->get_node2(), union_find); // 아니면 그냥 병합.
				return false; //사이클이 안생긴다.
			}
		}
		else
		{
			if (find(e_array->get_node2(), union_find) == find(e_array->get_node1(), union_find))
			{
				return true;
			}
			else
			{
				Union(e_array->get_node2(), e_array->get_node1(), union_find);
				return false;
			}
		}
	}

}

void quickSort(edge* arr[], int left, int right) {
	int i = left, j = right;
	int pivot = arr[(left + right) / 2]->get_g();
	edge* temp;
	do
	{
		while (arr[i]->get_g() < pivot)
			i++;
		while (arr[j]->get_g() > pivot)
			j--;
		if (i <= j)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	} while (i <= j);

	/* recursion */
	if (left < j)
		quickSort(arr, left, j);

	if (i < right)
		quickSort(arr, i, right);
}

int main()
{
	int node_num;
	int edge_num;
	cin >> node_num; //노드 갯수
	cin >> edge_num; //엣지 갯수

	edge *e_array[100000] = { NULL }; //엣지 배열 생성.
	for (int i = 0; i < edge_num; i++)
	{
		int node1,node2,g;
		cin >> node1; //노드 1
		cin >> node2; //노드 2
		cin >> g; // 가중치 입력
		edge *e = new edge(node1,node2,g); // 엣지 새로 생성
		e_array[i] = e; //엣지 배열에다가 새로 만든 엣지를 넣어줌
	}
	/*for (int i = 0; i < edge_num - 1; i++) // 가중치에 따른 내림차순 정리
	{
		for (int j = 0; j < edge_num - i - 1; j++)
		{
			if (e_array[j]->get_g() > e_array[j + 1]->get_g())
			{
				edge *temp_e = e_array[j];
				e_array[j] = e_array[j + 1];
				e_array[j + 1] = temp_e;
			}
		}
	}*/
	quickSort(e_array, 0, edge_num-1);
	int sp = 0; // 최소 신장 트리의 가중치 합.
	int *union_find = new int[node_num+1]; //union_find 시 사용할 배열.
	for (int i = 1; i < node_num + 1; i++)
	{
		union_find[i] = i; //자신의 값으로 초기화
	}
	//크루스칼은 유니온 파인드가 핵심!!
	for (int i = 0; i < edge_num; i++)//엣지를 다 볼때까지 돌림
	{
		if (is_cycle(e_array[i],union_find,i)) // 사이클이 있는지 없는지 탐색 구문.
		{
			//cout << "is_cycle?" << endl;
			e_array[i] = NULL; // 사이클이 있으면 추가 시켜주지 않음.
		}
		else
		{
			sp = sp + e_array[i]->get_g(); // 사이클이 없으면 sp에다가 값 추가.
		}
		
	}
	/*for (int i = 0; i < edge_num; i++)
	{
		if (e_array[i] != NULL) //NULL 표시 안해준 것들, 즉 사이클 검사에 걸리지 않은것들.
		{
			cout << "1노드 :" << e_array[i]->get_node1() << "/ 2노드 :" << e_array[i]->get_node2() << "/ g : " << e_array[i]->get_g();
			cout << endl;
		}
		
	}*/
	cout << sp;
	
	
	return 0;
}
