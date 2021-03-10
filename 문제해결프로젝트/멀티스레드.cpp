#define WIN32_LEAN_AND_MEAN
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <process.h>

DWORD WINAPI ThreadFunc(LPVOID Param); //monte carlo 계산 하는 함수
int main(int argc, char *argv[]) {

	clock_t start, finish; //시간 출력하기 위한 변수
	double duration; //시간 출력하는 변수
	
	DWORD threadId[4];
	HANDLE hThrd[4]; //멀티 스레드 넣을 배열
	DWORD Result = 0;
	DWORD Total = 0;

	start = clock();//시간 시작

	for (int i = 0; i < 4; i++) //4개의 스레드 실행
	{
		hThrd[i] = CreateThread(NULL,0,ThreadFunc, (LPVOID)i,0,&threadId[i]);
	}

	WaitForMultipleObjects(4, hThrd, TRUE, INFINITE); //스레드 끝날 떄 까지 대기

	for (DWORD i = 0; i < 4; i++) { //각각의 스레드에서 리턴값을 얻고 종료
		GetExitCodeThread(hThrd[i], &Result);
		Total += Result;
		CloseHandle(hThrd[i]);
	}

	finish = clock(); // 시간 종료
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	
	printf("pi = %f\n",4 * (double)Total/40000000);
	printf("멀티 스레드는 %f 초입니다\n", duration);
	printf("163926 김재근\n");

	return 0;
}
DWORD WINAPI ThreadFunc(LPVOID n)// 각 스레드마다 1천만번 실행
{
	DWORD circle = 0;
	srand((unsigned)time(NULL)); // 매번 다른 시드값 생성
	for (int i = 0; i < 10000000; i++) { //monte carlo 알고리즘
		double x = (double)rand() / (double)RAND_MAX;
		double y = (double)rand() / (double)RAND_MAX;

		if ((x*x) + (y*y) <= 1) {
			circle = circle + 1;
		}
	}
	return circle;
}
