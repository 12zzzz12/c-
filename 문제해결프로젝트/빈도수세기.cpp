#include<iostream>
#include<map>

using namespace std;

int main() {
	int n;    //입력받을 테스트 숫자의 개수
	cin >> n;

	map<int, int> fremap; // <숫자, 빈도수> 를 저장할 map

	for (int i = 0; i < n; i++) { //테스트 개수만큼 for문 반복
		int x;       //입력받을 숫자
		cin >> x;
		fremap[x]++; //입력받은 숫자의 map위치에 빈도수 1증가
		cout << fremap.size()<< " " << fremap[x] << endl; //현재 추가되있는 map의 사이즈와 각 숫자의 빈도수 출력
	}

	return 0;
}



