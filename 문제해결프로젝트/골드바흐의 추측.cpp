#include<iostream>
#include<vector>
using namespace std;

#define MAX_VALUE 1000000 // 최대값 설정
vector<int> isPrime; //각 숫자가 소수인지 확인하는 벡터
int cnt;      // 몇번째 케이스인지 카운트

void Eratosthenes() { //에라토스테네스의 체 알고리즘을 통해 isPrime벡터에 소수인값을 판별
	isPrime.assign(MAX_VALUE, 1); //최대 값 만큼 벡터를 모두 true로 초기화

	for (int i = 2; i*i < MAX_VALUE; i++) //아래서 제곱을 통해 소수판별하므로 size의 루트값까지만 for문
		if (isPrime[i])
			for (int j = i * i; j < MAX_VALUE; j += i) //제곱을 이용하여 소수 판별
				isPrime[j] = 0;                   //소수가 아니라면 0으로 변환
}


void solve(int test) {

	for (int i = 3; i < test / 2 + 1; i++) { //i는 3부터 시작하여 1씩 test의 절반 값까지 올라간다  (홀수인 소수를 비교하므로)
		for (int k = test; k >= 3; k--) {	  //k는 test할 숫자부터 1씩 줄여 3까지 내려간다        (3까지만 줄인다)
			if (i + k == test && isPrime[i] && isPrime[k]) { //i,k를 더했을 때 test값과 같으면서 둘다 소수 인경우 출력
				cout << "Case #" << cnt << ":\n";
				cout << test << " = " << i << " + " << k << "\n";
				cnt++; //case를 출력한뒤 카운트 1증가
				return;//값을 구했으므로 메소드 종료
			}
		}
	}
	cout << "Case #" << cnt << "\n" << "-1\n"; //위의 반복문에 없다면 만들 수 없는것이므로 -1출력
	cnt++;	                                   //카운트 1 증가
}

int main() {
	cnt = 1;          //카운트 1 로 시작
	Eratosthenes();  //에라토스테네스 메소드로 isPrime벡터 소수 저장

	int casesize;     // 테스트케이스의 개수
	cin >> casesize;  // 테스트케이스 입력

	int *test = new int[casesize]; //테스트할 숫자를 넣을 배열

	for (int i = 0; i < casesize; i++) {  //테스트할 숫자를 배열에 입력
		cin >> test[i];
	}
	for (int i = 0; i < casesize; i++) {  //순서대로 테스트할 숫자를 solve메소드에 넣음
		solve(test[i]);
	}

	return 0;
}
