#include <iostream>
using namespace std;

const int MAX_SEAT_NUMBER = 1000;
const int MAX_COLOR_NUMBER = 100;

class Painting { //페인트 클래스 
public:
	int left; //처음에 색칠할 자리
	int right;//두번째로 색칠할 자리
	int color;

	Painting() {}

	Painting(int left, int right, int color) {
		this->left = left;      
		this->right = right;
		this->color = color;
	}
};

void fillFrequencyTable(int data[], int n, int table[]) { //테이블을 구하는 함수
	for (int i = 0; i < MAX_COLOR_NUMBER; i++) //모든 좌석을 처음에 0으로 초기화
		table[i] = 0;
	for (int i = 0; i < n; i++) { //입력받은 값으로 컬러값을 지정 
		int color = data[i];
		table[color] += 1; //frequency 정보를 구하기 위해 1씩 더해준다.
	}

}
void solve(int n, int m, const Painting *paintings) {  
	int *seats = new int[n]; //좌석 배열을 n만큼 지정
	for (int i = 0; i < n; i++) { //모든 좌석을 0으로 초기화
		seats[i] = 0;
	}
	for (int i = 0; i < m; i++) { //색칠할 방법만큼 구조체 생성 
		const Painting &p = paintings[i];

		for (int j = p.left; j <= p.right; j++) { // 각 구조체의 지정된 좌석의 색을 지정
			seats[j] = p.color;
		}
	}

	int *table = new int[MAX_COLOR_NUMBER]; //색의 갯수만큼 테이블 크기 지정
	fillFrequencyTable(seats, n, table); // 색칠된 좌석들을 알아내기 위한 메소드

	int minColor = seats[0]; //가장 적은 색상
	int maxColor = seats[0]; //가장 많은 색상
	
	for (int color = 0; color < MAX_COLOR_NUMBER; color += 1) { //max컬러와 min컬러를 찾기 위한 for문
		if (table[color] == 0) {
			continue;
		}
		if (table[minColor] > table[color])
			minColor = color;
		if (table[maxColor] < table[color])
			maxColor = color;
	}
	cout << maxColor << "\n"; //maxColor 출력 첫번째 출력
	cout << minColor; //minColor 출력 두번째 출력

	delete[] table;
	
}



int main() {
	int n; //좌석의 수  
 	int m; //색칠할 방법의 수
	cin >> n >> m;

	Painting *paintings = new Painting[n];

	for (int i = 0; i < m; i++) { //
		cin >> paintings[i].left;
		cin >> paintings[i].right;
		cin >> paintings[i].color;

		paintings[i].left -= 1;
		paintings[i].right -= 1;
	}
	solve(n, m, paintings);
	return 0;
}