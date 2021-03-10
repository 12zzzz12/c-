#include<iostream>
#include<set>	
using namespace std;

int main() {
	int n; //입력받을 테스트 케이스의 개수
	cin >> n;

	set<int> s; //중복되는 숫자들을 집어넣을 세트

	for (int i = 0; i < n; i++) {  // 테스트케이스 만큼 for문을 반복하며 중복을 확인한다.
		int x;
		cin >> x;

		if (s.count(x) > 0) {	    //s에 이미 x가 들어가 있다면 중복되는 수이므로
			cout << "DUPLICATED\n"; //DUPLCATED를 출력한다.
		}
		else {                      //s에 x가 들어가 있지 않은것이므로 중복이 아닌경우다
			s.insert(x);            //s에 x를 넣어준뒤 ok를 출력한다.
			cout << "OK" << endl;
		}
	}
	return 0;
}

