#include <iostream>
using namespace std;
const int MAX_TABLE_LENGTH = 10000;

void fillFrequencyTable(int data[], int n, int table[]) {

	int frquent_number = 0; 
	for (int i = 0; i < MAX_TABLE_LENGTH; i++) //테이블을 모두 0으로 초기화
		table[i] = 0;
	for (int i = 0; i < n; i++) {  //데이터 갯수만큼 
		frquent_number = data[i];  //frequent에 데이터 값을 넣는다.
		table[frquent_number] += 1; //frequent_numver를 인덱스로 정하고 카운트를 1개씩 올려준다.
	}
}

int getFrequencyNumber(int data[], int n) { //가장 많은 전화번호를 찾는 메소드
	int frequent_number = 0; 
	int table[MAX_TABLE_LENGTH]; //테이블을 최댓값으로 지정

	fillFrequencyTable(data, n, table);
	
	for (int i = 0; i < MAX_TABLE_LENGTH; i++) {
		if (table[i] > table[frequent_number])  //두 값을 비교해서 i값이크면 frquent넘버를 i로 바꿔준다.
			frequent_number = i;
	}


	return frequent_number;
}

int main() {
	int n; //입력받을 전화번호의 갯수

	cin >> n;
	int *data = new int[n]; //전화번호를 집어넣을 배열

	for (int i = 0; i < n; i++) {
		cin >> data[i];
	}
	int answer = getFrequencyNumber(data, n); //가장 많은 전화번호를 찾는 메소드

	cout << answer;

	return 0;
}