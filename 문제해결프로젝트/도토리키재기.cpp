#include<iostream>
using namespace std;


int getMaximumHeight(int height[],int month[],int n, int m) {
	int answer = -1;         

	for (;n>-1; n--) {           // n값을 이용해 뒤에서 부터 for문을 돌린다.
		if (month[n] == m) {     // 현재 달과 같은 월을 가진 도토리를 찾는다.
			answer = height[n];  // 찾았다면 인덱스 값을 이용해 키를 알아내 answer에 저장한다.
			return answer;		 // answer 값을 리턴해주면 메소드를 종료한다.
		}
	}
	return answer;				//for문이 종료되면 찾지 못한 것이므로 -1로 저장된 answer가 리턴된다.
}

int main() {
	int n, m;                  // 도토리의 수 , 달
	
	cin >> n;

	int *height = new int[n];  //도토리 키 배열
	int *month = new int[n];   //도토리 생월 배열

	for (int i = 0; i < n; i++) {  //도토리 키 입력 및 배열저장
		cin >> height[i];
	}

	for (int i = 0; i < n; i++) { //도토리 생월 입력 및 배열저장
		cin >> month[i];
	}

	cin >> m; // 현재 달 입력

	int answer = getMaximumHeight(height, month, n, m);
	cout << answer;

	delete[] height;
	delete[] month;
	return 0;
}