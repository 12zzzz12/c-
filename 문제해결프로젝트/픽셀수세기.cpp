#include<iostream>
#include<math.h>
using namespace std;



bool isInside(long x, long y, long R)
{
	long sqd = x * x + y * y; //x^2 + y^2 < r^2 을 찾기위한 식
	if (sqd < R*R) // r^2 보다 작다면 원 안이므로 true리턴
		return true;
	return false;
}

void testcase(int caseIndex)
{
	long R;			// 원의 반지름
	cin >> R;

	long sum = 0;	// 원안에 들어가는 1사분면 픽셀 수
	long y = R;	    // 픽셀을 찾기 위한 y좌표 값 설정
	for (long x = 0; x <= R; x++) { // x좌표를 기준 픽셀 찾기위한 for문
		long height = 0;
		for (; y >= 0; y--) { //y좌표를 위에서부터 찾는 for문
			if (isInside(x, y, R)) { //픽셀이 들어간다면 그곳이 y좌표의
				height = (y + 1);    //가장 높은 곳이므로 그곳을 height로 설정
				break;
			}
		}
		sum += height; // 각 x좌표의 픽셀들을 더해간다.
	}


	cout << "#" << caseIndex << "\n";
	cout << sum * 4 << "\n"; //sum은 1사분면 내의 픽셀들이므로 *4를 해준다.
}

int main() {
	int caseSize; //입력받을 원의 개수
	cin >> caseSize;

	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex ++) {
		testcase(caseIndex);
	}
	return 0;
}