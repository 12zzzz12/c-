#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Camera {
public:
	int type; //카메라 종류
	int y; //카메라 y좌표
	int x; //카메라 x좌표
	Camera(int type, int y, int x) {
		this->type = type;
		this->x = x;
		this->y = y;
	};
};

int N, M;         //사무실 가로 세로 개수
int ans = 100;    //사각 지대 최소
int camera_cnt = 0; //카메라 개수
vector<vector<int>> map(8, vector<int>(8, 0)); //사무실 맵
vector<Camera> car; //카메라 넣을 벡터



void checkmap(int dir, int y, int x) {

	if (dir == 0) {//북
		for (int i = y - 1; i >= 0; i--) { //y좌표를 이용해 0까지 검사
			if (map[i][x] == 6) break; //검사중 벽을 만나면 for문 종료
			if (map[i][x] == 0) map[i][x] = -1; //감시 가능한 곳은 -1로 저장
		}
	}

	else if (dir == 1) {//동
		for (int j = x + 1; j < M; j++) { //x좌표를 이용해 M까지 검사
			if (map[y][j] == 6) break;
			if (map[y][j] == 0) map[y][j] = -1;
		}
	}

	else if (dir == 2) {
		for (int i = y + 1; i < N; i++) {  //y좌표를 이용해 N까지 검사
			if (map[i][x] == 6) break;
			if (map[i][x] == 0) map[i][x] = -1;
		}
	}

	else if (dir == 3) {//서
		for (int j = x - 1; j >= 0; j--) { //x좌표를 이용해 0까지 검사
			if (map[y][j] == 6) break;
			if (map[y][j] == 0) map[y][j] = -1;
		}
	}
}
//DFS를 이용하여 카메라 사각지대 최소값을 구한다.
void dfs(int step) {

	//카메라 개수만큼 확인했으면 사각지대 최솟값을 구한다.
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

	int camera_type = car[step].type; //각 카메라 종류 저장
	int y = car[step].y;              //각 카메라 x좌표 저장
	int x = car[step].x;              //각 카메라 y좌표 저장

	//이전에 확인한 사무실 상태값 저장
	vector<vector<int>> map2 = map;

	if (camera_type == 1)		//북,동,남,서
		for (int dir = 0; dir < 4; dir++) {
			checkmap(dir, y, x); //각 방향으로 검사
			dfs(step + 1);
			map = map2;      //map에 임시 저장
		}

	else if (camera_type == 2)		//ㅣ,ㅡ
		for (int dir = 0; dir < 2; dir++) {
			checkmap(dir, y, x);     //양쪽 방향 검사
			checkmap(dir + 2, y, x); // 180도 반대 방향 검사
			dfs(step + 1);
			map = map2;
		}

	else if (camera_type == 3)		//ㄴ,동남,ㄱ,서북
		for (int dir = 0; dir < 4; dir++) {
			checkmap(dir, y, x);          //90도 방향 검사
			checkmap((dir + 1) % 4, y, x);
			dfs(step + 1);
			map = map2;
		}

	else if (camera_type == 4)		//ㅏ,ㅜ,ㅓ,ㅗ
		for (int dir = 0; dir < 4; dir++) {
			checkmap(dir, y, x);
			checkmap((dir + 1) % 4, y, x);
			checkmap((dir + 2) % 4, y, x);
			dfs(step + 1);
			map = map2;
		}

	else if (camera_type == 5) {    //4방향 모두
		for (int dir = 0; dir < 4; dir++)
			checkmap(dir, y, x);   //한번에 모든 방향 검사 한뒤 dfs
		dfs(step + 1);
	}
}




int main() {

	cin >> N >> M; //사무실 가로 세로 입력

	for (int i = 0; i < N; i++) {    //사무실 카메라, 벽 입력
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0 && map[i][j] != 6) { //0과 6이 아니면 카메라 이므로 
				camera_cnt++;                       //카메라 개수 증가
				car.push_back(Camera(map[i][j], i, j)); //카메라 구조체 생성 및 벡터에 저장
			}
		}
	}

	dfs(0);
	cout << ans;

	return 0;
}