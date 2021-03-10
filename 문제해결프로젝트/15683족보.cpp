#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Camera {
public:
	int type; //ī�޶� ����
	int y; //ī�޶� y��ǥ
	int x; //ī�޶� x��ǥ
	Camera(int type, int y, int x) {
		this->type = type;
		this->x = x;
		this->y = y;
	};
};

int N, M;         //�繫�� ���� ���� ����
int ans = 100;    //�簢 ���� �ּ�
int camera_cnt = 0; //ī�޶� ����
vector<vector<int>> map(8, vector<int>(8, 0)); //�繫�� ��
vector<Camera> car; //ī�޶� ���� ����



void checkmap(int dir, int y, int x) {

	if (dir == 0) {//��
		for (int i = y - 1; i >= 0; i--) { //y��ǥ�� �̿��� 0���� �˻�
			if (map[i][x] == 6) break; //�˻��� ���� ������ for�� ����
			if (map[i][x] == 0) map[i][x] = -1; //���� ������ ���� -1�� ����
		}
	}

	else if (dir == 1) {//��
		for (int j = x + 1; j < M; j++) { //x��ǥ�� �̿��� M���� �˻�
			if (map[y][j] == 6) break;
			if (map[y][j] == 0) map[y][j] = -1;
		}
	}

	else if (dir == 2) {
		for (int i = y + 1; i < N; i++) {  //y��ǥ�� �̿��� N���� �˻�
			if (map[i][x] == 6) break;
			if (map[i][x] == 0) map[i][x] = -1;
		}
	}

	else if (dir == 3) {//��
		for (int j = x - 1; j >= 0; j--) { //x��ǥ�� �̿��� 0���� �˻�
			if (map[y][j] == 6) break;
			if (map[y][j] == 0) map[y][j] = -1;
		}
	}
}
//DFS�� �̿��Ͽ� ī�޶� �簢���� �ּҰ��� ���Ѵ�.
void dfs(int step) {

	//ī�޶� ������ŭ Ȯ�������� �簢���� �ּڰ��� ���Ѵ�.
	if (step == camera_cnt) {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 0)
					cnt++;
			}
		}
		ans = min(ans, cnt);
		return;
	}

	int camera_type = car[step].type; //�� ī�޶� ���� ����
	int y = car[step].y;              //�� ī�޶� x��ǥ ����
	int x = car[step].x;              //�� ī�޶� y��ǥ ����

	//������ Ȯ���� �繫�� ���°� ����
	vector<vector<int>> map2 = map;

	if (camera_type == 1)		//��,��,��,��
		for (int dir = 0; dir < 4; dir++) {
			checkmap(dir, y, x); //�� �������� �˻�
			dfs(step + 1);
			map = map2;      //map�� �ӽ� ����
		}

	else if (camera_type == 2)		//��,��
		for (int dir = 0; dir < 2; dir++) {
			checkmap(dir, y, x);     //���� ���� �˻�
			checkmap(dir + 2, y, x); // 180�� �ݴ� ���� �˻�
			dfs(step + 1);
			map = map2;
		}

	else if (camera_type == 3)		//��,����,��,����
		for (int dir = 0; dir < 4; dir++) {
			checkmap(dir, y, x);          //90�� ���� �˻�
			checkmap((dir + 1) % 4, y, x);
			dfs(step + 1);
			map = map2;
		}

	else if (camera_type == 4)		//��,��,��,��
		for (int dir = 0; dir < 4; dir++) {
			checkmap(dir, y, x);
			checkmap((dir + 1) % 4, y, x);
			checkmap((dir + 2) % 4, y, x);
			dfs(step + 1);
			map = map2;
		}

	else if (camera_type == 5) {    //4���� ���
		for (int dir = 0; dir < 4; dir++)
			checkmap(dir, y, x);   //�ѹ��� ��� ���� �˻� �ѵ� dfs
		dfs(step + 1);
	}
}




int main() {

	cin >> N >> M; //�繫�� ���� ���� �Է�

	for (int i = 0; i < N; i++) {    //�繫�� ī�޶�, �� �Է�
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0 && map[i][j] != 6) { //0�� 6�� �ƴϸ� ī�޶� �̹Ƿ� 
				camera_cnt++;                       //ī�޶� ���� ����
				car.push_back(Camera(map[i][j], i, j)); //ī�޶� ����ü ���� �� ���Ϳ� ����
			}
		}
	}

	dfs(0);
	cout << ans;

	return 0;
}