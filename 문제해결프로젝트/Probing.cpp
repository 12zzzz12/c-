#include<iostream>
#include<vector>

using namespace std;

class TicketTable{
public:
	vector<bool> used;//행운권 번호 있는지 확인하는 백터
	int length; //백터의 길이를 의미 = 입장하는 회원 수

	TicketTable(int length) {
		this->length = length;
		this->used.assign(length, false); // 모두 false로 초기화
	}

	int findEmptyIndexByUserId(int userId) { //회원번호로 행운권번호 계산하는 메소드
		int index = userId % length; //회원권 번호%행운권 수 로 행운권 번호 계산
		while (this->isEmpty(index) == true) { //행운권 번호가 비어 있다면 건너뜀 
			index = (index + 1) % length; //행운권번호가 있다면 다음번호를 조사
		}
		return index; //행운권 번호 반환
	}

	bool isEmpty(int ticketIndex) { //행운권 자리가 비어있다면 false
		return this->used[ticketIndex];  //이미 자리가 찻다면 true
	}
	void setUsed(int index, bool status) { //행운권 번호 자리를 차지하면 
		this->used[index] = status; //그 자리를 true로 변환
	}
};

vector<int> getTicketNumbers(int n, int m, const vector<int>& ids) {
	vector<int> tickets;
	TicketTable table = TicketTable(n); //테이블 객체 생성

	for (int i = 0; i < m; i++) {
		int userId = ids[i]; // userid에 회원권 번호 저장
		int ticketIndex = table.findEmptyIndexByUserId(userId); 
		tickets.push_back(ticketIndex); // 행운권 번호를 백터에 저장
		table.setUsed(ticketIndex, true); // 해당 행운권 번호 자리를 true로 변환
	}
	return tickets;
}

int main() {
	int n, m;
	cin >> n >> m; // 준비한 행운권 수, 입자할 회원 수

	vector<int> ids(m); //회원 수 만큼의 백터 생성
	for (int i = 0; i < m; i++) { //회원번호 백터에 저장
		cin >> ids[i];
	}
	vector<int> tickets = getTicketNumbers(n, m, ids); //행운권 번호 저장
	for (int i = 0; i < tickets.size(); i++) {
		cout << tickets[i] << "\n"; //행운권 번호 출력
	}

}