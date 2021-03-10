#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int get_area(int la, int ra, int ta, int ba, int lb, int rb, int tb, int bb) {

	int l, r, t, b;
	l = max(la, lb); //겹치는 사각형의 왼쪽 x 좌표
	r = min(ra, rb); //겹치는 사각형의 오른쪽 x 좌표
	t = min(ta, tb); //겹치는 사각형의 위쪽 y 좌표
	b = max(ba, bb); //겹치는 사각형의 아래쪽 y 좌표
	
	if(l<=r && b<=t)  //사각형의 크기가 +인것을 확인 
	return ((r - l)*(t - b));

	return 0;


}

void test_case() {
	int ax, ay, bx, by; //직사각형 a의 점 4개
	int px, py, qx, qy; //직사각형 b의 점 4개
	cin >> ax >> ay >> bx >> by;
	cin >> px >> py >> qx >> qy;

	int la, ra, ba, ta; //직사각형 a
	la = min(ax, bx); //사각형 a의 왼쪽 x좌표
	ra = max(ax, bx); //사각형 a의 오른쪽 x좌표
	ta = max(ay, by); //사각형 a의 위쪽 y좌표
	ba = min(ay, by); //사각형 a의 아래쪽 y좌표

	int lb, rb, bb, tb; //직사각형 b
	lb = min(px, qx); //사각형 b의 왼쪽 x좌표
	rb = max(px, qx); //사각형 b의 오른쪽 x좌표
	tb = max(py, qy); //사각형 b의 위쪽 y좌표
	bb = min(py, qy); //사각형 b의 아래쪽 y좌표

	int answer = get_area(la, ra, ta, ba, lb, rb, tb, bb);

	cout << answer;
}
int main() {
	int t; //테스크 케이스의 수
	cin >> t;

	for (int i = 0; i < t; i++) { //테스트 케이스 수만큼 test_case함수 실행
		test_case(); 
	}

	return 0;
}