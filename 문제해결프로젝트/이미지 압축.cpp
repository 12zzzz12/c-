#include<iostream>
#include<vector>
#include<stdlib.h>

using namespace std;

vector<int> code;             //변환 코드를 저장할 벡터

class Number {      //수열 클래스
public:
	int num;      // 각 수열의 숫자
	int level;    // 각 수열의 레벨

	Number(int num) {
		this->num = num;
		//각 수열의 크기에 따른 임시 레벨 부여
		if (num < 44)
			this->level = 1;
		else if (num < 129)
			this->level = 86;
		else if (num < 214)
			this->level = 172;
		else
			this->level = 256;
	}
};

void pushcode(int level) {  //레벨에 따른 변환코드 값(2-bit) 저장하는 메소드

	if (level == 1) {   //코드에 00 추가
		code.push_back(0); code.push_back(0);
	}
	else if (level == 86) { //코드에 01추가
		code.push_back(0); code.push_back(1);
	}
	else if (level == 172) { // 코드에 10추가
		code.push_back(1); code.push_back(0);
	}
	else { //코드에 11추가
		code.push_back(1); code.push_back(1);
	}

}

void compression(vector<int> an, int N, int W) {
	
	vector<Number> number;        //각 수열의 객체들을 저장할 벡터
	
	for (int i = 0; i < N; i++) {
		number.push_back(Number(an[i])); //각 수열의 객체를 생성하고 number벡터에 저장
	}

	int len = 2; // 코드길이 
	int sum = 0; // 변환비용
	
	pushcode(number[0].level); //변환코드에 첫번째 수열의 레벨(2-bit)을 입력한다.

	for (int i = 0; i < N-1; i++) {                    //각 수열의 에러값 저장 및 연속된 레벨 비교 반복문

		//첫번째 숫자가 두 번째 숫자보다 큰 경우
		if (number[i].num > number[i + 1].num) { //
			if (abs(abs(number[i].num - number[i + 1].level) - abs(number[i].num - number[i].level)) < W * 2)
				number[i].level = number[i + 1].level;
		}

		else{
			if (number[i].level != number[i + 1].level) {  //연속된 숫자의 레벨이 다른 경우 
				//각 레벨에 따른 에러값과 (코드길이 * 가중치)의 대소비교를 통해 뒤의 원소레벨을 결정한다.  
				if(abs(number[i + 1].num - number[i].level) < abs(number[i + 1].num - number[i + 1].level) + 2 * W)
					number[i + 1].level = number[i].level;
			}
		}
		//뒤의 원소의 레벨 결정을 한 뒤 레벨이 다른 경우와 같은 경우 수행
		if (number[i].level != number[i + 1].level) { //레벨이 다른 경우
			len += 3;								  //코드길이 3 증가 , 변환코드에 1+(2-bit)가 추가되므로
			code.push_back(1);						  //코드에 1 추가     
			pushcode(number[i + 1].level);			  //코드에 레벨만큼 추가
		}
		else{                                        //레벨이 같을 경우
			len += 1;							     //코드길이 1 증가  , 변환코드에 0만 추가되므로
			code.push_back(0);						 //코드에 0 추가
		}
		//각 수열의 에러값 변환비용에 저장
		sum += abs(number[i].num - number[i].level);
	}

	sum += abs(number[N - 1].num - number[N - 1].level) + len * W; //변환 비용에 마지막 요소 값과 (코드길이*가중치)를 더한다.
	
	cout << sum << endl; //최소 변환 비용 출력

	for (int i = 0; i < code.size(); i++) // 변환 코드 출력
		cout << code[i];
}

int main() {

	int N, W;          //수열 길이, 가중치
	cin >> N >> W;                //수열 길이, 가중치 입력

	vector<int> an;               //입력받은 수열을 넣을 벡터
	for (int i = 0; i < N; i++) { //수열 입력
		int test;
		cin >> test;
		an.push_back(test);
	}
	compression(an, N ,W);

	return 0;

}