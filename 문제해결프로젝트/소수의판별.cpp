#include<iostream>

using namespace std;

bool isPrime(int N) {
	if (N == 1 || N==2) return false; // N이 1또는 2이면 false 리턴

	for (int i = 2; i*i <= N; i++) { // N의 절반까지만 계산하도록 제곱을 이용
		if (N % i == 0) // 2이상의 수로 나누어진다면 소수가 아니므로 false리턴
			return false;
	}
	return true; //for문이 완료된다면 약수가 없다는 뜻이므로 true 리턴
}

void testcase(int caseIndex) {
	int n;       //판별받을 숫자 
	cin >> n;

	bool result = isPrime(n); 

	cout << "Case #" << caseIndex << "\n";
	if (result)         //isPrime 함수를 통해 true이면 소수이므로 YES출력
		cout << "YES \n";
	else
		cout << "NO \n";
}

int main() {
	int caseSize; //몇개의 숫자를 판별할건지 받는 수
	cin >> caseSize;
	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex++) { // caseSize만큼의 for문
		testcase(caseIndex);
	}
	return 0;
}