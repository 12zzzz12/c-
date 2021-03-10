#include<iostream>
#include<queue>
using namespace std;


int map[10][10]; //그래프 그릴 맵
int visited[10] = { 0 }; 
queue<int> q;    //탐색 순서대로 넣을 큐
int num, edge_num; //점의 개수 , 선분의 개수

void bfs(int v) { //너비 우선 탐색 
	cout << v << endl; //입력받은 값을 출력 
	q.push(v);         //큐에 입력받은 값을 저장
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
	cin >> num >> edge_num; //점의 개수, 선분의 개수 입력
	for (int i = 0; i < edge_num; i++) { //선분의 개수만큼 점두개를 입력
		int v1, v2;
		cin >> v1 >> v2;
		map[v1][v2] = map[v2][v1] = 1; //해당 점들을 map에서 1로 설정
	}

	bfs(1);
	return 0;
}


