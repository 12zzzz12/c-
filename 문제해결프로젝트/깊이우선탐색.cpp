#include<iostream>

using namespace std;

int map[10][10]; //�׷��� �׸� ��
int visited[10] = { 0 };
int num;
void init() { //�� ��ҵ��� 0���� �ʱ�ȭ
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			map[i][j] = 0;
		}
	}
}

void dfs(int v) { //���� �켱 Ž��
	cout << v << endl; // �Է¹��� ���ڸ� ���
	visited[v] = 0;     //���ڸ� ����ϰ� �湮 �迭���� 0���� ����
	for (int i = 0; i <= num; i++) { //�ش� ���ڿ� ������ ������ ã�� �޼ҵ�
		if (map[v][i] && visited[i]) //������ ���� ã�Ҵٸ� 
			dfs(i);                  //�� ���ڷ� �ٽ� dfs Ž��
	}
}

int main() {
	int v1, v2; //����� �� ���� �Է��� ����
	init();
	cin >> num; //������ ���� �Է�
	for (int i = 0; i < num; i++) {
		cin >> v1 >> v2;
		map[v1][v2] = map[v2][v1] = 1; //�׷����� ����� �κ��� map���� 1�� ǥ��
		visited[v1] = visited[v2] = 1; //�ش� ������ visited�� 1�� ����
	}
	dfs(1); //1���� Ž�� ����

	return 0;
}
