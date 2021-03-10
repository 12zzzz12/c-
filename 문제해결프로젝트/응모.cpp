#include <iostream>
#include<vector>
using namespace std;

const int MAX_SERIAL_NUMBER = 100000;	

void fillFrequencyTable(const vector<int> & data, int n, vector<int> &table) {
	table.clear(); //table 벡터를 초기화
	table.resize(MAX_SERIAL_NUMBER + 1, 0); //table 벡터크기를 MAX_SERIAL_NUMBER + 1, 모두 0으로 초기화한다. 

	for (int i = 0; i < n; i++) {
		int serial = data[i]; //입력받을 숫자를 serial로 저장
		table[serial] += 1; //serial값을 인덱스로 이용해 카운트를 센다.
	}
}

vector<int> getUniqueElements(const vector<int> &data, int n) {
	vector<int> ret; //ret 벡터 생성해준다.

	vector<int> table; //table 벡터 생성
	fillFrequencyTable(data, n, table); //입력받은 숫자를 index로 가지는 테이블로 변환.

	for (int number = 1; number <= MAX_SERIAL_NUMBER; number += 1) { 
		if (table[number] == 1) // 입력받은 숫자가 한개인 값들만을 ret벡터에 다시 넣어준다.
			ret.push_back(number);
	}

	return ret; //한개만 입력된 숫자들을 가지고 있는 ret벡터를 리턴해준다.
}

int main() {
	int n; //응모할 숫자의 갯수
	cin >> n;

	vector<int> data = vector<int>(n); //응모받은 숫자를 넣을 백터

	for (int i = 0; i < n; ++i) { //벡터에 숫자들을 입력
		cin >> data[i];
	}
	const vector<int> answer = getUniqueElements(data, n); //숫자들을 정렬, 중복제거 한다.

	for (int i = 0; i < answer.size(); ++i) { //추려낸 숫자들을 출력
		if (i > 0) {
			cout << " ";
		}
		cout << answer[i];
	}


	return 0;
}