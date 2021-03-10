#include<iostream>

using namespace std;

int **a; //사각형 a의 2차원 배열
int **b; //사각형 b의 2차원 배열

//예를 들어 2x2 구역을 비교한다고 하면 아래와 같은 식을 얻을 수 있고    a( a1 a2 )	b ( b1 b2 ) 
//																		 ( a3 a4 )	  ( b3 b4 )
//a1 * p + q = b1			[a1 1]				[b1]
//a2 * p + q = b2   -->     [a2 1] * [p]   =	[b2]                옆에 식을 풀면 b1 - a1*p = b2 -a2*p = b3 -a3*p = b4 -a4*p 를 구할 수 있다.
//a3 * p + q = b3			[a3 1]	 [q]		[b3]                           즉,  (b2-b1)/(a2-a1) = (b3-b2)(a3-a2) = p 를 만족하는 a,b의 요소들을 가져야만
//a4 * p + q = b4			[a4 1]				[b4]                           매칭이되는 것을 이용한 알고리즘입니다.

int matching(int N, int M, int R, int C) {    
	int cnt = 0; // 매칭이 되는 영역 카운트

	int axcnt, aycnt; //사각형 a에서의 좌측상단 꼭지점 위치를 옮겨가는 카운트

	int *amult = new int[R*C];    //a사각형 내에서 매칭할 영역의 숫자들을 순서대로 넣을 배열
	int *bmult = new int[R*C];    //b사각형 숫자들을 순서대로 넣을 배열
	 
	for (axcnt=0; axcnt < N-R+1; axcnt++) {         // 사각형 a 내에서 꼭지점x 위치를 이동하는 for문
		for (aycnt = 0; aycnt < M-C+1; aycnt++) {   //                 꼭지점y 위치를 이동하는 for문
			
			int i = 0;          // amult 배열에 순서대로 집어넣기 위한 인덱스
			bool same = true;   // 영역이 매칭되는지 확인하기 위한 변수

			//꼭지점 위치에서의 b크기(R,C)만큼 for문 시작
			for (int x = 0; x < R; x++) {                 //사각형 a,b의 x인덱스값 증가
				for (int y = 0; y < C ; y++) {            //사각형 a,b의 y인덱스값 증가
					amult[i] = a[x + axcnt][y + aycnt];   // a사각형에서 매칭할 구역의 숫자들을 순서대로 집어넣는다.
					bmult[i] = b[x][y];                   // b사각형에서 매칭할 구역의 숫자들을 순서대로 집어넣는다.
					i++;
				}
			}

			for (int k = 0; k < R*C - 3; k++) {             // 매칭할 구역내에서 (b2-b1)/(a2-a1) = (b3-b2)(a3-a2) 확인하는 반복문 
				if ((bmult[k + 1] - bmult[k])*(amult[k + 2] - amult[k + 1]) != (bmult[k + 2] - bmult[k + 1]) * (amult[k + 1] - amult[k])){
					same = false;                           //만약 조건이 다르다면 same을 false로 바꿔주고 for문 탈출
					break;
				}
			}
			if (same)  // 꼭지점(x,y)에서 이미지매칭을 했을 때 same이 true상태라면 카운트 1증가
				cnt += 1;
		}
	}
	return cnt;
}


int main() {

	int N, M; //사각형 a의 행, 열
	int R, C; //사각형 b의 행, 열

	//직사각형 a 입력
	cin >> N >> M;
	a = new int*[M]; //사각형 a의 2차원 배열
	
	for (int i = 0; i < M; i++) { //2차원 열 설정
		a[i] = new int[N];
	}

	for (int i = 0; i < N; i++) { //각 행마다 입력
		for (int k = 0; k < M; k++) {
			cin >> a[i][k];
		}
	}

	//직사각형 b 입력
	cin >> R >> C;
	b = new int*[C];   //사각형 b의 2차원 배열

	for (int i = 0; i < C; i++) { //2차원 열 설정
		b[i] = new int[R];
	}

	bool allsame = true; //사각형 b의 요소들이 모두 같을 경우를 위해 true설정

	for (int i = 0; i < R; i++) { //각 행마다 입력
		for (int k = 0; k < C; k++) {
			cin >> b[i][k];
			if (b[i][k] != b[0][0]) {
				allsame = false; //사각형 b의 요소가 다른경우 false
			}
		}
	}


	if (allsame) //b의 요소가 모두 같다면 아래의 개수만큼 매칭가능
		cout << (N - R + 1)*(M - C + 1);
	else
		cout << matching(N, M, R, C);
	

	delete[] a;
	delete[] b;
	return 0;
}