#include<iostream>
#include<string>


using namespace std;

class Cock {     //톱니 클래스 
public:
	int cock;    //톱니 상태

	bool getRight() { //톱니의 오른쪽 부분 극을 알아내는 함수
		return cock & (1 << 2); // 비트 연산을 이용해 0b00000100 의 위치를 알아내는 방법
	}
	
	bool getLeft() { //톱니의 왼쪽 부분 극을 알아내는 함수
		return cock & (1 << 6); // 비트 연산을 이용해 0b01000000 의 위치를 알아내는 방법
	}
	void rightturn() {
		bool temp = cock & 0x80;  // 왼쪽 시프트 연산을 하면 사라지는 왼쪽 부분을 temp에 저장
		cock <<= 1; 					//cock을 왼쪽으로 1만큼 쉬프트 연산
		cock |= temp;                   //tmep와 cock을 or 연산을 통해 1번 비트에 값 저장 
		cock &= 0xff;			    //왼쪽 쉬프트연산으로 생길 수 있는 앞쪽 1값을 없애기 위해 0xff을 &연산해준다.
	}
	void leftturn() {			
		bool temp = cock & 0x01;         //오른쪽 쉬프트 연산을 하면 사라지는 오른쪽 부분을 temp에 저장
		cock >>= 1;					 //cock을 오른쪽으로 1만큼 쉬프트 연산
		cock |= (temp << 7);         //temp에 저장되어 있는 숫자를 7만큼 쉬프트해서 위치를 바꾸고 cock과 or연산을 해준다.
	}
	bool score() {
		return cock & 1;             //12시 방향의 극이 가장 오른쪽에 있는 값이므로 & 1 연산을 통해 값을 알아낸다.
	}

	void setbit(int n) {
		for (int i = 0; i < 8; i++) {  // 입력받는 cock의 상태를 비트형태로 저장하는 for문
			cock <<= 1;                
			cock += n % 10;           
			n /= 10;
		}
	}
};


int main() {
	Cock *cocks = new Cock[4];
	int cock;//톱니상태
	int n; // 회전 횟수
	int number, direction; // 톱니바퀴, 방향

	for (int i = 0; i < 4; i++) {	 //4개 톱니 상태 입력 
		cin >> cock;
		cocks[i].setbit(cock); // 톱니 상태를 setbit()함수를 이용해 저장
	} 


	cin >> n; //회전 횟수 입력

	
	while (n--) {                      //회전 횟수 만큼 while문을 이용해 돌린다.

		cin >> number >> direction;    //회전 시킬 톱니와 방향 입력

		int whereturn[4] = { 0 };      //각각의 톱니바퀴 회전 방향을 넣을 배열,, 0으로 초기화
		whereturn[number-1] = direction; // 처음에 회전시킬 톱니바퀴의 번호(인덱스)에 방향 저장 

		//각 톱니바퀴가 어느 방향으로 돌아야 하는지 확인
		//각각의 톱니바퀴를 회전 시킴
		
		for (int i = number-1; i < 3; i++) {					 //선택한 톱니와 오른쪽으로 순차적 비교	
			if (cocks[i].getRight() ^ cocks[i + 1].getLeft())	 //맞닿는 부분이 다르면 
				whereturn[i + 1] = -whereturn[i];	             //오른쪽 톱니의 회전방향을 반대방향으로 지정
			else		                                         // 처음 맞닿는 부분이 같다면 나머지 오른쪽 부분도 움직이지 않으므로 for문 종료
				break;
		}
		for (int i = number-1; i > 0; i--) {                     //선택한 톱니와 왼쪽으로 순차적 비교
			
			if (cocks[i].getLeft() ^ cocks[i - 1].getRight())    //맞닿는 부분이 다르다면
				whereturn[i - 1] = -whereturn[i];			     // 톱니의 회전방향을 맞닿는 톱니의 반대방향으로 저장
			else                                                 // 처음 맞닿는 부분이 같다면 나머지 왼쪽 부분도 움직이지 않으므로 for문 종료
				break;
		}
		for (int i = 0; i < 4; i++) {                            //모든 톱니의 회전 방향을 확인하고 확인 방향에 따라 회전시킨다.
			if (whereturn[i] == 1) {							 //1이 저장되어 있다면 시계방향으로 회전
				cocks[i].rightturn();
			}
			else if (whereturn[i] == -1){                       // -1이 저장되어 있다면 반시계방향으로 회전
				cocks[i].leftturn();
			}
		}
	}

	int k = 1;
	int sum = 0;
	for (int i = 0; i < 4; i++) {								//각각의 톱니바퀴의 첫 번째 극을 확인하고 
		sum += cocks[i].score() * k;                            //순서대로 1, 2, 4, 8 을 곱하여 sum에 저장
		k *= 2;
	}
	cout << sum;
		
	return 0;
}