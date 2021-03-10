#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> password; //패스워드 넣을 벡터
int pre;          //패스워드 이전 숫자 확인할 변수

//패스워드 벡터에 현재 번호가 존재하는지 확인 하는 메소드
int passwordcheck(int pattern) {
	if (find(password.begin(), password.end(), pattern) != password.end())
		return 1;
	else
		return 0;
}

//중간 숫자가 필요한 8개의 쌍을 확인하는 메소드
int visitcheck(int pre, int pattern) { //이전 값과 현재 값을 매개변수로 받는다.
	if ((pre == 1 && pattern == 3) || (pre == 3 && pattern ==1)) {
		return passwordcheck(2); //숫자 1,3 이 연속될 경우 숫자 2가 있는지 확인
	}
	else if ((pre == 1 && pattern == 7) || (pre == 7 && pattern == 1)) {
		return passwordcheck(4);
	}
	else if ((pre == 1 && pattern == 9) || (pre == 9 && pattern == 1)) {
		return passwordcheck(5);
	}
	else if ((pre == 3 && pattern == 7) || (pre == 7 && pattern == 3)) {
		return passwordcheck(5);
	}
	else if ((pre == 9 && pattern == 7) || (pre == 7 && pattern == 9)) {
		return passwordcheck(8);
	}
	else if ((pre == 3 && pattern == 9) || (pre == 9 && pattern == 3)) {
		return passwordcheck(6);
	}
	else if ((pre == 2 && pattern ==8) || (pre == 8 && pattern ==2)) {
		return passwordcheck(5);
	}
	else if ((pre == 4 && pattern == 6) || (pre == 6 && pattern == 4)) {
		return passwordcheck(5);
	}

	return 1;

}

int process(int pattern) {

	//패턴 중복검사 if문
	if (passwordcheck(pattern))
		return 0; //중복된다면 0 리턴

	else   //패턴이 중복되지 않는다면 숫자를 벡터에 집어넣는다.
		password.push_back(pattern);

	//이전 숫자와 현재 숫자 사이에 숫자가 있는지 확인하는 작업
	if (visitcheck(pre, pattern) == 0)
		return 0;

	//이전 값에 현재의 값을 넣고 메소드 종료
	pre = pattern;

	return 1;
}

int main() {

	int n; //입력받을 숫자 개수
	int pattern; //비밀번호 
	int yes; //올바른 패턴인지 확인할 변수

	cin >> n; 

	for (int i = 0; i < n; i++) {
		cin >> pattern;
		yes = process(pattern); // yes에 올바른 패턴인지 변수 저장
		if (!yes) { //올바르지 않다면 no를 출력하고 종료
			cout << "NO";
			return 0;
		}
	}
	//위의 for문을 무사히 마쳤다면 YES를 출력한다.
	cout << "YES";
	return 0;
}