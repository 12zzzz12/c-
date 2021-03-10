#include<iostream>
#include<map>
#include<string>

using namespace std;

int main() {
	int n;   //입력할 투표의 수
	cin >> n;

	map<string, int> frequencymap; //각 후보와 득표수를 저장할 map

	int maxfrequency = 0; //최대 득표수를 0으로 초기화

	for (int i = 0; i < n; i++) { //투표 수만큼 for문 반복
		string st; //후보의 이름을 저장할 변수
		cin >> st; //후보이름으로 투표
		frequencymap[st]++;       //투표받은 후보의 map위치에 득표수 1증가
		int k = frequencymap[st]; // 입력받은 후보의 득표수 k에 저장

		if (k > maxfrequency) // 이번에 입력받은 후보의 득표수가 최대 득표수보다 높다면
			maxfrequency = k; //최대 득표수를 변경한다.
	}

	cout << maxfrequency << endl; //최대 득표수를 출력

	map<string, int>::iterator it; //map을 탐색하기 위한 변수

	//map을 탐색하면서 key값이 최대득표수와 같다면 후보이름을 출력한다.
	for (it = frequencymap.begin(); it != frequencymap.end(); it++) {
		if (it->second == maxfrequency)
			cout <<it->first.c_str() << " ";
	}


	return 0;
}

