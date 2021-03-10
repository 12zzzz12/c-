#define WIN32_LEAN_AND_MEAN
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <process.h>

DWORD WINAPI ThreadFunc(LPVOID Param); //monte carlo ��� �ϴ� �Լ�
int main(int argc, char *argv[]) {

	clock_t start, finish; //�ð� ����ϱ� ���� ����
	double duration; //�ð� ����ϴ� ����
	
	DWORD threadId[4];
	HANDLE hThrd[4]; //��Ƽ ������ ���� �迭
	DWORD Result = 0;
	DWORD Total = 0;

	start = clock();//�ð� ����

	for (int i = 0; i < 4; i++) //4���� ������ ����
	{
		hThrd[i] = CreateThread(NULL,0,ThreadFunc, (LPVOID)i,0,&threadId[i]);
	}

	WaitForMultipleObjects(4, hThrd, TRUE, INFINITE); //������ ���� �� ���� ���

	for (DWORD i = 0; i < 4; i++) { //������ �����忡�� ���ϰ��� ��� ����
		GetExitCodeThread(hThrd[i], &Result);
		Total += Result;
		CloseHandle(hThrd[i]);
	}

	finish = clock(); // �ð� ����
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	
	printf("pi = %f\n",4 * (double)Total/40000000);
	printf("��Ƽ ������� %f ���Դϴ�\n", duration);
	printf("163926 �����\n");

	return 0;
}
DWORD WINAPI ThreadFunc(LPVOID n)// �� �����帶�� 1õ���� ����
{
	DWORD circle = 0;
	srand((unsigned)time(NULL)); // �Ź� �ٸ� �õ尪 ����
	for (int i = 0; i < 10000000; i++) { //monte carlo �˰���
		double x = (double)rand() / (double)RAND_MAX;
		double y = (double)rand() / (double)RAND_MAX;

		if ((x*x) + (y*y) <= 1) {
			circle = circle + 1;
		}
	}
	return circle;
}
