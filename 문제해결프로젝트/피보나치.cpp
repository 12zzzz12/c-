#include <iostream>
#include<vector>
using namespace std;

const int MAX_N = 1000000;
vector<int> FIBONACCI_TABLE;


vector<int> makeFibonacciTable(int n) {
	const int MOD = 100000000; 

	vector<int> ret(n + 1); // ret 벡터 생성
	ret[1] = 0; //피보나치 첫번째 수열은 0이므로 초기화
	ret[2] = 1; // 두번째 숫자는 1이므로 1로 초기화

	for (int i = 3; i <= n; ++i) { //피보나치 수열을 계산하는 for문
		ret[i] = ret[i - 1] + ret[i - 2];
		ret[i] %= MOD;
	}
	return ret; //원하는 순서의 피보나치 수 리턴
}

int getFibo(int n) {
	int answer = FIBONACCI_TABLE[n]; //원하는 n번째 피보나치 수열 리턴
	return answer;
}

int main() {
	FIBONACCI_TABLE = makeFibonacciTable(MAX_N);

	int caseSize;  //입력받을 피보나치 수의 갯수
	cin >> caseSize;

	int *data = new int[caseSize]; //몇번 째 피보나치 수인지 저장하는 배열

	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex++) { //원하는 n번째 숫자들 입력
		int n;
		cin >> n;
		data[caseIndex - 1] = n; //배열에 원하는 n번쨰 숫자들을 저장
	}
	for (int i = 0; i< caseSize; i++) {
			cout << getFibo(data[i]) << "\n"; //data배열에 저장해둔 숫자로 원하는 n번째 숫자들을
	}										//getFibo메소드를 이용해 한줄에 한개씩 출력한다.
	FIBONACCI_TABLE.clear();
	return 0;
}