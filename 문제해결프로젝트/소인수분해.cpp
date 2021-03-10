#include<iostream>
#include<vector>

using namespace std;


vector<int> factorize(int n) {
	vector<int> factors; //소인수들을 넣을 벡터

	for (int div = 2; div * div <= n; div += 1) {
		while (n%div <= 0) { //div이 n의 약수라면 
			factors.push_back(div); // factors벡터에 div 추가
			n /= div; // n을 div만큼 나눈 값을 n에 저장
		}
	}
	if (n > 1) //위의 for문을 다 돌렸을 때 n이 1보다 크다면 
		factors.push_back(n); //그 값만큼 factors에 추가 
	return factors;
}
void process(int caseIndex) {
	int n; // 소인수분해할 숫자
	cin >> n;
	vector<int> factors = factorize(n); // factorize메소드를 통해 n을 소인수분해

	cout << "#"<<caseIndex << ":\n"; //소인수분해한 결과를 출력하는 과정
	for (int i = 0; i < factors.size(); i++) {
		if (i > 0)
			cout << " ";
		cout << factors[i];
	}
	cout << "\n";
}

int main() {
	int caseSize; //입력받을 숫자의 갯수 
	cin >> caseSize;
	for (int caseIndex = 1; caseIndex <= caseSize; ++caseIndex) {
		process(caseIndex); //입력받을 숫자의 갯수만큼 process메소드 반복
	}
}