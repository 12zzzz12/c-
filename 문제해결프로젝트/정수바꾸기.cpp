#include<iostream>
#include<string>

using namespace std;

int cnt = 1 ; //연산의 최소값 구하는 카운트

int division2(int b) { //b가 짝수일 때 2로 나누어주는 함수
	cnt += 1; //카운트 1 증가
	return b / 2;
}

int minusone(int b) { //b의 맨 뒤에 있는 1을 없애주는 함수
	
	string str1 = to_string(b); //정수 b를 문자열로 변환
	
	int len = str1.length(); //문자열로 변환시킨 뒤 길이 측정

	str1.erase(len-1,len); //b의 맨뒤에 1을 제거 
	
	cnt += 1; //카운트 1증가


	return stoi(str1);
}

int main() {
	//b가 홀수 -> 맨뒤의 1을 제거
	//b가 짝수 -> %2  를 반복하여 a를 찾아 최소 횟수를 구하는 알고리즘입니다.

	int a; // 시작 숫자
	int b; // 최종 숫자

	cin >> a >> b;


	string strb = to_string(b); //b를 문자열로 변환
	int blen = strb.length(); //문자열의 길이 확인
	string last = strb.substr(blen - 1, blen); //마지막 문자 확인
	if (stoi(last) %2 == 1 && stoi(last) != 1) { //마지막 문자가 1이 아닌 홀수라면
		cout << -1;								 // -1 출력과 종료
		return 0;
	}

	while (1) {
		if (b == a) { //b가 a와 같다면 cnt 출력과 반복문 종료
			cout << cnt;
			break;
		}
		else if (b == 1) { //b가 1이 되도록 a를 만나지 못한다면 -1을 출력
			cout << -1;
			break;
		}
		else {
			if (b % 2 == 0) { // b가 짝수라면 2로 나누어준다.
				b = division2(b);
			}
			else {
				b = minusone(b); //b가 홀수라면 1을 빼주는 함수로 보낸다.
			}
		}
	}

	return 0;
}