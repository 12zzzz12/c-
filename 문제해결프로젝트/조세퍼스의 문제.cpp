#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Player {      //�÷��̾� Ŭ����
public:
	int index;      // �� �÷��̾��� ��ȣ

	Player(int index) {
		this->index = index;
	}
};

vector<Player> getDeadPalyer(int n, int m, const vector<Player>& players) { //�÷������ ���ŵǴ� ������ �˾Ƴ� �޼ҵ�
 	vector<Player> deadplayer;   //���ŵǴ� �÷��̾���� ���� ����

	queue<Player> que;

	for (int i = 0; i < n; i++) { //��� �÷��̾���� 1~n ������ ť�� ����ִ´�.
		que.push(players[i]);
	}

	for (int i = 0; i < n; i++) {           //���ŵǴ� �÷��̾���� ������ ť������ �ٲٴ� �ݺ���

		int jump = 1 + (m - 1) % que.size(); // ���ŵǴ� ���ݾձ����� �÷��̾���� �ڷ� ������ ���� ����
		for (int j = 0; j < jump - 1; j++) {//m�� 3�̶�� 1,2�� �÷��̾���� �ڷ� ������ �ݺ���
			Player p = que.front();         //�� ���� �÷��̾ p�� ����
			que.pop();					    //p�� ������ �÷��̾ ����
			que.push(p);				    //p�� �����س� �÷��̾ �ٽ� �����Ͽ� �ǵڷ� ������.
		}// ex) 1 2 3  4 5 6 -> 3 4 5 6 1 2

		Player dead = que.front(); //���� ť ����տ� �ִ� ���� �����ؾ��� �÷��̾��̹Ƿ� dead�� ����
		que.pop();			      //pop�� �̿��� ť���� ����
		deadplayer.push_back(dead); // deadplayer ���Ϳ� ���ŵ� �÷��̾� ������� ����
	}
	
	return deadplayer;
}

void process(int caseindex) { //�� case�� ������ �޼ҵ�
	int n, m;  
	cin >> n >> m; // �÷��̾��� ���� ������ ����

	vector<Player> players;           //�÷��̾� ����ü�� ���� ����

	for (int i = 0; i < n; i++) {         //1~ n ������ �÷��̾���� ���Ϳ� ����ִ´�.
		players.push_back(Player(i + 1));
	}
	vector<Player> deadplayer = getDeadPalyer(n, m, players);  // ���ŵ� ������ �÷��̾���� ���� ����

	for (int i = 0; i < n; i++) { // n���� �÷��̾���� ������ ������� ����Ѵ�.
		if (i > 0) {
			cout << " ";
		}
		Player p = deadplayer[i];  //���Ŵ��� �÷��̾ p�� ����
		cout << p.index;           // p�� �ε����� ���� ����Ѵ�.

	}
	cout << endl;
}

int main() {
	int caseSize;   //�׽�Ʈ ����
	cin >> caseSize;

	for (int i = 0; i < caseSize; i++) { //�׽�Ʈ ������ŭ �޼ҵ� ����
		process(i);
	}
}
