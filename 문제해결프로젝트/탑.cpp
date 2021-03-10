#include<iostream>
#include<vector>
#include<stack>
using namespace std;


class Tower {
public:
	int index;           //tower의 인덱스
	int height;		     //tower의 높이
	int targetTowerindex;//tower가 신호를 보내는 tower의 인덱스

	Tower(int index, int height) { //tower생성자 
		this->index = index;
		this->height = height;
		this->targetTowerindex = 0; //초기 설정 0
	}
	void setTargettowerindex(int targetTowerindex) { //신호를 받은 타워가 있다면
		this->targetTowerindex = targetTowerindex;   //신호 받은 타워의 인덱스 저장
	}
	int getTargetTowerindex() {  // 신호를 보내는 타워의 인덱스 확인하는 메소드
		return this->targetTowerindex;
	}
};

void findtargettowers(vector<Tower>& towers) {
	stack<Tower> stk;

	for (int i = 0; i < towers.size(); i++) { //타워의 개수만큼 for문 수행
		Tower& t = towers[i];    //구조체를 생성해 순서대로 타워의 정보를 가져온다.
		int targetTowerindex = 0;


		while (stk.empty() == false && stk.top().height < t.height) { //스택이 비어있지 않고 가장 최근에 넣은 타워의 높이가
			stk.pop();											      // 현재 타워보다 높이가 낮을 경우 가장 최근의 타워정보를 삭제한다.
		}															  //앞선 타워중 현재 타워보다 높은 타워가 있는지 확인하는 작업

		if (stk.size() > 0) { // 스택에 내용물이 있다는 건 앞쪽 타워에 자신보다 높은 타워가 있다는 것이므로
			targetTowerindex = stk.top().index;  //자신보다 높은 타워의 인덱스를 타겟인덱스로 저장
		}

		t.setTargettowerindex(targetTowerindex);  //만약 자신보다 높은 타워가 없다면 타겟인덱스를 0으로 저장한다.
	
		stk.push(t); // 스택에 자신의 정보를 저장한다. 
	}

}
int main() {
	int n;    //입력받을 타워의 개수
	cin >> n; 

	vector<Tower> towers; //타워들의 정보를 가진 구조체를 넣을 벡터

	for (int i = 0; i < n; i++) { 
		int hi;
		cin >> hi; //타워들의 높이를 입력 
		towers.push_back(Tower(i + 1, hi)); //타워의 인덱스와 높이를 설정한 구조체를 벡터에 저장
	}

	findtargettowers(towers); //각 타워들이 어느 타워에게 신호를 보내는지 확인

	for (int i = 0; i < n; i++) {
		if (i > 0)
			cout << " ";
		Tower t = towers[i];
		int targetindex = t.getTargetTowerindex(); 
		cout << targetindex; //각 타워가 신호를 보내는 타워의 위치를 출력
	}

	return 0;
}