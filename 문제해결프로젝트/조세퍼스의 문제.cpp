#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Player {      //플레이어 클래스
public:
	int index;      // 각 플레이어의 번호

	Player(int index) {
		this->index = index;
	}
};

vector<Player> getDeadPalyer(int n, int m, const vector<Player>& players) { //플레어들이 제거되는 순서를 알아낼 메소드
 	vector<Player> deadplayer;   //제거되는 플레이어들을 넣을 벡터

	queue<Player> que;

	for (int i = 0; i < n; i++) { //모든 플레이어들을 1~n 순서로 큐에 집어넣는다.
		que.push(players[i]);
	}

	for (int i = 0; i < n; i++) {           //제거되는 플레이어들을 빼내고 큐순서를 바꾸는 반복문

		int jump = 1 + (m - 1) % que.size(); // 제거되는 간격앞까지의 플레이어들을 뒤로 보내기 위한 변수
		for (int j = 0; j < jump - 1; j++) {//m이 3이라면 1,2번 플레이어들을 뒤로 보내는 반복문
			Player p = que.front();         //맨 위의 플레이어를 p에 저장
			que.pop();					    //p의 저장한 플레이어를 제거
			que.push(p);				    //p에 저장해논 플레이어를 다시 저장하여 맨뒤로 보낸다.
		}// ex) 1 2 3  4 5 6 -> 3 4 5 6 1 2

		Player dead = que.front(); //이제 큐 가장앞에 있는 수가 제거해야할 플레이어이므로 dead에 저장
		que.pop();			      //pop을 이용해 큐에서 삭제
		deadplayer.push_back(dead); // deadplayer 벡터에 제거된 플레이어 순서대로 저장
	}
	
	return deadplayer;
}

void process(int caseindex) { //각 case를 실행할 메소드
	int n, m;  
	cin >> n >> m; // 플레이어의 수와 제거할 간격

	vector<Player> players;           //플레이어 구조체를 넣을 벡터

	for (int i = 0; i < n; i++) {         //1~ n 까지의 플레이어들을 벡터에 집어넣는다.
		players.push_back(Player(i + 1));
	}
	vector<Player> deadplayer = getDeadPalyer(n, m, players);  // 제거된 순서로 플레이어들을 넣을 벡터

	for (int i = 0; i < n; i++) { // n명의 플레이어들을 제거한 순서대로 출력한다.
		if (i > 0) {
			cout << " ";
		}
		Player p = deadplayer[i];  //제거당한 플레이어를 p에 저장
		cout << p.index;           // p의 인덱스를 꺼내 출력한다.

	}
	cout << endl;
}

int main() {
	int caseSize;   //테스트 개수
	cin >> caseSize;

	for (int i = 0; i < caseSize; i++) { //테스트 개수만큼 메소드 실행
		process(i);
	}
}
