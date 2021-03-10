#include<iostream>
#include<queue>
using namespace std;


int map[10][10]; //�׷��� �׸� ��
int visited[10] = { 0 }; 
queue<int> q;    //Ž�� ������� ���� ť
int num, edge_num; //���� ���� , ������ ����

void bfs(int v) { //�ʺ� �켱 Ž�� 
	cout << v << endl; //�Է¹��� ���� ��� 
	q.push(v);         //ť�� �Է¹��� ���� ����
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (int i = 0; i < num; i++) {
			if (map[node][i] && visited[i] == 0) {
				cout << i << endl;
				visited[node] = 1;
				q.push(i);
			}
		}
	}
}

void dfs(int v) {
	cout << v << endl;
	visited[v] = 0;
	for (int i = 0; i <= num; i++) {
		if (map[v][i] && visited[i]) {
			dfs(i);
		}
	}
}
int main() {
	cin >> num >> edge_num; //���� ����, ������ ���� �Է�
	for (int i = 0; i < edge_num; i++) { //������ ������ŭ ���ΰ��� �Է�
		int v1, v2;
		cin >> v1 >> v2;
		map[v1][v2] = map[v2][v1] = 1; //�ش� ������ map���� 1�� ����
	}

	bfs(1);
	return 0;
}


