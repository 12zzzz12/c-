#include<iostream>
using namespace std;


int getMaximumHeight(int height[],int month[],int n, int m) {
	int answer = -1;         

	for (;n>-1; n--) {           // n���� �̿��� �ڿ��� ���� for���� ������.
		if (month[n] == m) {     // ���� �ް� ���� ���� ���� ���丮�� ã�´�.
			answer = height[n];  // ã�Ҵٸ� �ε��� ���� �̿��� Ű�� �˾Ƴ� answer�� �����Ѵ�.
			return answer;		 // answer ���� �������ָ� �޼ҵ带 �����Ѵ�.
		}
	}
	return answer;				//for���� ����Ǹ� ã�� ���� ���̹Ƿ� -1�� ����� answer�� ���ϵȴ�.
}

int main() {
	int n, m;                  // ���丮�� �� , ��
	
	cin >> n;

	int *height = new int[n];  //���丮 Ű �迭
	int *month = new int[n];   //���丮 ���� �迭

	for (int i = 0; i < n; i++) {  //���丮 Ű �Է� �� �迭����
		cin >> height[i];
	}

	for (int i = 0; i < n; i++) { //���丮 ���� �Է� �� �迭����
		cin >> month[i];
	}

	cin >> m; // ���� �� �Է�

	int answer = getMaximumHeight(height, month, n, m);
	cout << answer;

	delete[] height;
	delete[] month;
	return 0;
}