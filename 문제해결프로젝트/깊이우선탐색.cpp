#include<iostream>

using namespace std;

int map[10][10]; //그래프 그릴 맵
int visited[10] = { 0 };
int num;
void init() { //맵 요소들을 0으로 초기화
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			map[i][j] = 0;
		}
	}
}

void dfs(int v) { //깊이 우선 탐색
	cout << v << endl; // 입력받은 숫자를 출력
	visited[v] = 0;     //숫자를 출력하고 방문 배열에서 0으로 설정
	for (int i = 0; i <= num; i++) { //해당 숫자와 인접한 점들을 찾는 메소드
		if (map[v][i] && visited[i]) //인접한 점을 찾았다면 
			dfs(i);                  //그 숫자로 다시 dfs 탐색
	}
}

int main() {
	int v1, v2; //연결된 두 점을 입력할 변수
	init();
	cin >> num; //선분의 개수 입력
	for (int i = 0; i < num; i++) {
		cin >> v1 >> v2;
		map[v1][v2] = map[v2][v1] = 1; //그래프로 연결된 부분을 map에선 1로 표시
		visited[v1] = visited[v2] = 1; //해당 점들을 visited에 1로 저장
	}
	dfs(1); //1부터 탐색 시작

	return 0;
}
