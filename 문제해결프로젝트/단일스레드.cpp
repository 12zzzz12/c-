#define WIN32_LEAN_AND_MEAN
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define MAXTHREAD 5
double circle;

DWORD WINAPI ThreadFunc(LPVOID n); //monte carlo 계산 하는 함수
int main() {
	
	clock_t start, finish; //시간 출력하기 위한 변수
	double duration; //시간 출력하는 변수
	DWORD threadId; 
	HANDLE hThrd[MAXTHREAD]; //멀티 스레드 넣을 배열

	start = clock();//시간 시작

	ThreadFunc((LPVOID)1); //스레드 시작
	
	WaitForMultipleObjects(MAXTHREAD, hThrd, TRUE, INFINITE); 

	finish = clock(); // 시간 종료
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	
	printf("pi = %0.15f\n", 4*(circle/40000000));
	printf("단일 스레드는 %f 초입니다\n", duration);
	printf("163926 김재근\n");

	return 0;
}
DWORD WINAPI ThreadFunc(LPVOID n)
{
	srand(time(NULL)); // 매번 다른 시드값 생성
	for (int i = 0; i < 40000000; i++) { //monte carlo 알고리즘
		double x = (double)rand() / (double)RAND_MAX;
		double y = (double)rand() / (double)RAND_MAX;
		if ((x*x) + (y*y) <= 1) {
			circle = circle + 1;
		}		
	}
	return 0;
}
