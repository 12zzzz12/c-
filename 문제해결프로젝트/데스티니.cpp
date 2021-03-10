#include<iostream>
#include<math.h>
using namespace std;



class Point2D {
private:
	int x;
	int y;
public:
	Point2D(int x = 0, int y = 0) {    //구조체 만들면 x,y 값 집어넣기
		this->x = x;          
		this->y = y;
	}

	int getSquaredDistanceTo(const Point2D &target) const { // 구조체 간 거리 계산하는 메소드
		int dx = abs(this->x - target.x);
		int dy = abs(this->y - target.y);

		return dx * dx + dy * dy;
	}

	//getDistanceTo 함수는 사용하지 않아서 지웠습니다.
};

int main() {
	int n;          //점의 개수를 받는 변수
	Point2D *points;

	cin >> n;
	points = new Point2D[n];  // 점의 개수만큼 Point2D구조체를 만든다.

	for (int i = 0; i < n; i++) {   //각 점의 좌표들을 point2d 구조체에 넣어주는 for문
		int x, y;					//각 점의 x,y좌표 
		cin >> x >> y;
		points[i] = Point2D(x, y);  
	}
	int min_sqd = INT_MAX;
	int min_cnt = 0; // 최소 거리에 벌어진 점의 쌍

	for (int i = 0; i < n; i++) {  //각 점의 거리 비교하는 for 문
		for (int j = 0; j < i; j++) {
			int sqd = points[i].getSquaredDistanceTo(points[j]);
			if (sqd < min_sqd) {
				min_sqd = sqd;
				min_cnt = 1;
			}
			else if (sqd == min_sqd) { //거리가 최소 거리와 같다면 점의 개수를 추가
				min_cnt++;
			}
		}
	}
	double distance = sqrt(min_sqd);  //위에서 구한 거리를 루트씌워주는 작업
	
	cout << fixed;      //distance 가 소수점 1자리 까지
	cout.precision(1);  // 나오도록 함

	cout << distance << '\n';
	cout << min_cnt;

	delete[] points;
	return 0;
}




