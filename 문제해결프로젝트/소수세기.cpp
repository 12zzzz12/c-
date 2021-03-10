#include<iostream>
#include<vector>

using namespace std;

class Sieve {
public:
	int maximumValue; //범위의 최댓값
	vector<bool> isPrime; //소수 인지 판별하기 위한 벡터
	Sieve(int maximumValue) {
		this->maximumValue = maximumValue;
		this->isPrime.assign(maximumValue + 1, false); //벡터를 maximumValue+1 크기로 false로 초기화
		this->fillSieve(); // 범위내의 소수들을 확인하는 메소드
	}

	bool isPrimeNumber(int num) const {
		return this->isPrime[num]; //isPrime의 값을 통해 소수인지 판별
	}
	void fillSieve() {
		isPrime.assign(this->maximumValue+1, true); //isPrime벡터를 true로 초기화
		isPrime[0] = isPrime[1] = false; // 0과 1은 소수가 아니므로 false 저장

		for (int num = 2; num <= maximumValue; num += 1) { //2~범위 최댓값 까지 for문
			if (isPrime[num] == false) // 소수가 아니라면 뒤의 for문 생략
				continue;
			for (long long mul = (long long)num * num; mul <= maximumValue; mul += num) {
				int index = (int)mul;  // //소수가 아닌 숫자위치 (index)에 false저장
				isPrime[index] = false;
		}
		}

	}
};
vector<int> getAllPrimeNumbers(int from, int to, const Sieve& sieve) { //범위내의 소수들 벡터에 넣는 메소드
	vector<int> primes;

	for (int num = from; num <= to; num += 1){
	if (sieve.isPrimeNumber(num)) //소수가 맞다면 primes벡터에 집어넣는다.
		primes.push_back(num);
	}
	return primes;// primes벡터 리턴
}

void process(int caseIndex, const Sieve& sieve) {
	int L, R;
	cin >> L >> R; //범위 값 입력

	vector<int> allPrimeNumbers = getAllPrimeNumbers(L, R, sieve); //allPrimeNumbers벡터에 범위내 소수들 저장

	cout << "Case#" << caseIndex << ":\n"; 
	cout << (int)allPrimeNumbers.size() << "\n"; //소수가 저장된 벡터의 size를 출력함으로 소수들 갯수출력
}

int main() {
	const int MAX_VALUE = 1000000;	
	Sieve sieve = Sieve(MAX_VALUE);

	int caseSize; //입력받을 테스트케이스의 수
	cin >> caseSize;
	for (int i = 1; i <= caseSize; i++) { //테스트케이스 수만큼 process메소드 반복
		process(i, sieve);
	}
}
