#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;


class Point2d {
public:
	int x;           //각 점의 x좌표
	int y;			 //각 점의 y좌표
	int index;       //각 점의 번호

	Point2d(int index, int x, int y) { //점 생성
		this->index = index;
		this->x = x;
		this->y = y;
	}
	Point2d( int x, int y) { //점 생성
		this->index = 1;
		this->x = x;
		this->y = y;
	}

	long long getSquaredDistance(Point2d target) { // 두 점의 점 x좌표 거리 , y좌표 거리 구하는 메소드
		long long dx = abs(this->x - target.x);    // 두 점의 x좌표 거리
		long long dy = abs(this->y - target.y);    // 두 점의 y좌 거리
		return dx * dx + dy * dy;
	}

	bool operator < (const Point2d& other) const { //점 사이의 대소비교

		if (this->x != other.x) {     //x좌표 값으로 순서 비교
			return this->x < other.x;
		}

		return this->y < other.y;    //x좌표 값이 같다면 y좌표 값으로 비교
	}

};

long long getMaximumSquare(int n, const vector<Point2d>& points) { //최대 사각형 값을 구하는 메소드
	long long answer = 0;     //최대 사각형 넓이를 넣을 변수

	set<Point2d> pset;        //점 구조체들을 집어넣을 set

	for(int i = 0; i < n; i++) { //점의 개수만큼 구조체를 생성한뒤 set에 집어넣는다.
		pset.insert(points[i]);
	}

	for (int i = 0; i < n; i++) {    //점의 개수만큼 for문을 반복한다.
		Point2d pa = points[i];      //임시 점을 pa에 저장한다. 
		for (int j = 0; j < n; j++) {
			Point2d pb = points[j];  //두번째 점을 pb에 임시 저장한다.
		
			if (i == j) continue;     //i, j가 같다면 같은 점이므로 생략하고 넘어간다.

			long long area = pa.getSquaredDistance(pb); //두 점을 이용한 사각형 넓이를 구한다.

			if (area < answer) {     //만약 area가 answer보다 작다면 최대 값이 아니므로 continue를 이용해 넘어간다.
				continue;
			}
			//정사각형을 만들기 위해 나머지 두 점을 찾기 위한 x,y거리
			int dx = pb.x - pa.x;   // 나머지 두 점을 찾기 위한 x거리
			int dy = pb.y - pa.y;   // 나머지 두 점을 찾기 위한 y거리

			Point2d pd(pa.x - dy, pa.y + dx);  //정사각형을 만들기 위한 점 1
			Point2d pc(pb.x - dy, pb.y + dx);  //정사각형을 만들기 위한 점 2
			
			//점 1,2 가 pset에 있는지 확인하여 정사각형을 만들 수 있는지 확인한다.
			if (pset.count(pc) > 0 && pset.count(pd) > 0) 
				answer = max(answer, area); //만약 주어진 점들로 정사각형을 만들 수 있다면 answer를 이전 값과 비교하여 큰 값으로 저장한다.
			
		}
	}


	return answer;
}

void process(int caseIndex) { // 점들을 입력하고 최대 사각형넓이를 출력하는 메소드
	int n; //점의 개수
	cin >> n;

	vector<Point2d> points; // 점 구조체들을 넣을 벡터

	for (int i = 0; i < n; i++) { // 점의 개수만큼 x,y좌표를 입력받고 구조체를 생성한다.
		int x, y;
		cin >> x >> y;
		points.push_back(Point2d(i, x, y)); //점 하나를 생성하고 벡터에 집어넣는다.
	}
	long long answer = getMaximumSquare(n, points); //최대 사각형 넓이를 answer에 받아 저장한다.
	cout << fixed << setprecision(2) << answer << endl; //최대 사각형 넓이 소수점 2째자리까지 출력한다.
}

int main() {
	int caseSize;   //입력받을 테스트 케이스 수
	cin >> caseSize;

	for (int i = 1; i <= caseSize; i++) { //테스트 케이스만큼 for문을 반복한다.
		process(i);
	}
	return 0;
}