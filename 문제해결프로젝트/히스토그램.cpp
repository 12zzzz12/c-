#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

class Histogram { //각 기둥의 구조체를 만들 클래스
public:
	int height; //기둥의 높이
	int leftX;  //기둥의 왼쪽 x좌표
	int rightX; //기둥의 오른쪽 x좌표

	Histogram(){}

	Histogram(int index, int height) { //기둥의 위치와 높이 설정
		this->leftX = index; //왼쪽 x좌표는 index값
		this->rightX = this->leftX + 1; //오른쪽 x좌표는 leftx +1 값
		this->height = height; //높이 저장
	}
};
long getLargestRectanglearea(const vector<Histogram>& histograms) {
	long answer = 0;

	stack<Histogram> stk; //기둥 구조체를 순차적으로 넣을 스택

	stk.push(Histogram(-1, 0)); //(0,0)좌표를 설정한다

	for (int i = 0; i < histograms.size() + 1; i++) { //기둥의 개수+1만큼 for문 수행
		Histogram h;               //임시 구조체
		if (i < histograms.size()) //임시 구조체에 순차적으로 입력받은 기둥 구조체 저장
			h = histograms[i];
		else
			h = Histogram(histograms.size(), 0); //가장 오른쪽 x좌표를 설정하기위한 임시구조체
	
		while (stk.size() > 1 && stk.top().height > h.height) { //2번째 기둥부터 자신의 왼쪽 기둥보다 높이가 낮은경우 while문 수행  ㅡ ㅡ ㅡ 세개의 기둥을 가지고 넓이를 비교한다.
																//(0,0) 좌표까지 while문을 반복하여 가장 큰 넓이를 구하는 방법

			Histogram lh = stk.top();                           //스택의 가장 윗부분의 정보를 갖는 임시구조체 생성 (while문 처음 시작할 기준: 현재 기둥의 왼쪽 기둥)
			stk.pop();                                          //스택의 가장 윗부분 삭제

			Histogram bh = stk.top();                           //스택의 윗부분을 제거한 뒤의 top정보를 갖는 임시구조체

			long width = abs(h.leftX - bh.rightX);              //현재 기둥부터 가장 왼쪽 기둥까지의 밑변길이
			long height = lh.height;                            //비교하는 세가지 기둥 중 가운데 기둥의 높이
			long area = width * height;                         //현재 가질 수 있는 넓이 
			 
			answer = max(answer, area);                          //앞서 구한 answer와 area를 비교했을 때 더 큰값을 answer로 넣어준다.
		}
	
		stk.push(h);                                             //현재 기둥의 정보를 스택에 저장
	}


	return answer;
}

void process(int caseindex) {
	int n;    // 입력받을 기둥의 개수
	cin >> n;

	vector<Histogram> histograms; //기둥 구조체를 저장할 벡터

	for (int i = 0; i < n; i++) { //기둥의 개수만큼 구조체를 생성 및 벡터에 저장
		int height;
		cin >> height;
		histograms.push_back(Histogram(i, height)); // 기둥 구조체를 벡터에 저장
	}

	long answer = getLargestRectanglearea(histograms); //최대사각형 넓이 구하는 메소드를 통해 답 저장
	cout << answer << endl;
}

int main() {
	int caseSize; //입력받을 테스트케이스의 개수
	cin >> caseSize;

	for (int i = 1; i <= caseSize; i++) { //테스트케이스의 수만 큼 for문 수행
		process(i);
	}
}