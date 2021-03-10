#define WIN32_LEAN_AND_MEAN
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define MAXTHREAD 5
double circle;

DWORD WINAPI ThreadFunc(LPVOID n); //monte carlo ��� �ϴ� �Լ�
int main() {
	
	clock_t start, finish; //�ð� ����ϱ� ���� ����
	double duration; //�ð� ����ϴ� ����
	DWORD threadId; 
	HANDLE hThrd[MAXTHREAD]; //��Ƽ ������ ���� �迭

	start = clock();//�ð� ����

	ThreadFunc((LPVOID)1); //������ ����
	
	WaitForMultipleObjects(MAXTHREAD, hThrd, TRUE, INFINITE); 

	finish = clock(); // �ð� ����
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	
	printf("pi = %0.15f\n", 4*(circle/40000000));
	printf("���� ������� %f ���Դϴ�\n", duration);
	printf("163926 �����\n");

	return 0;
}
DWORD WINAPI ThreadFunc(LPVOID n)
{
	srand(time(NULL)); // �Ź� �ٸ� �õ尪 ����
	for (int i = 0; i < 40000000; i++) { //monte carlo �˰���
		double x = (double)rand() / (double)RAND_MAX;
		double y = (double)rand() / (double)RAND_MAX;
		if ((x*x) + (y*y) <= 1) {
			circle = circle + 1;
		}		
	}
	return 0;
}
