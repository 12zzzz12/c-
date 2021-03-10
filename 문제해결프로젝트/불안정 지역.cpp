#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class City {//각 도시의 번호와 소득을 저장할 클래스
public:
	int index; //번호
	int income;//소득

	City(int index, int income) {
		this->index = index;   //도시의 순서 설정
		this->income = income; //도시의 소득 설정
	}

	bool operator < (const City& o) const { //우선순위 큐 대소관계를 정의하기 위한 operator
		return this->income < o.income; //income으로 대소관계 비교
	}

	bool operator > (const City& o) const {//우선순위 큐 대소관계를 정의하기 위한 operator
		return this->income > o.income; //income으로 대소관계 비교
	}

};

int getMaximumRange(int n, int k, const vector<City>& cities) {
	int answer = 0; //소득차를 저장할 변수

	priority_queue<City, vector<City>, greater<City>> rangeMinimum; //소득이 가장 낮은 도시부터 pop되는 우선순위 큐

	priority_queue<City> rangeMaximum; //소득이 가장 높은 도시부터 pop되는 우선순위 큐

	for (int i = 0; i < k - 1; i++) { //연속된 도시 k개가 있을 때 k-1개 만큼 저장하는 반복문
		rangeMaximum.push(cities[i]); //소득이 가장 높은 도시 순서대로 큐에 저장
		rangeMinimum.push(cities[i]); //소득이 가장 낮은 도시 순서대로 큐에 저장
	}
	for (int i = k - 1; i < n; i++) { //k번째 도시부터 n번째 도시까지 저장하고 answer값을 저장하는 반복문
		rangeMaximum.push(cities[i]); //소득이 가장 높은 도시 순서대로 큐에 저장
		rangeMinimum.push(cities[i]); //소득이 가장 낮은 도시 순서대로 큐에 저장
		while (rangeMaximum.top().index < i - k + 1) //연속된 k개의 도시 개수를 맞추기 위해 큐에서 pop을 이용해 삭제
			rangeMaximum.pop();
		while (rangeMinimum.top().index < i - k + 1) //연속된 k개의 도시 개수를 맞추기 위해 큐에서 pop을 이용해 삭제
			rangeMinimum.pop();
		answer = max(answer, rangeMaximum.top().income - rangeMinimum.top().income); //연속된 k개의 도시 중 (소득 큰 순서 큐의 탑 - 소득 낮은 순서 큐의 탑)을 이용해 answer값을 저장 
	}



	return answer;
}

void process(int caseIndex) { //정답을 출력할 메소드
	int n, k; // 도시의 개수, 연속되는 도시의 개수

	cin >> n >> k;
	vector<City> cities; //도시 구조체를 넣을 벡터

	for (int i = 0; i < n; i++) { //각도시의 소득과 순서를 입력하는 반복문
		int income; 
		cin >> income; //소득입력
		cities.push_back(City(i, income)); //벡터에 도시 구조체 저장
	}

	int answer = getMaximumRange(n, k, cities); //정답을 가져온다.

	cout << answer << endl;
}

int main() {
	int caseSize; //테스트 받을 개수
	cin >> caseSize;

	for (int i = 0; i < caseSize; i++) { //테스트 개수만큼 반복
		process(i);
	}
}