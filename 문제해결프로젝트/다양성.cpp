#include<iostream>
using namespace std;

int getElementTypeCount(int data[], int n) {
	int countType = 0;
	
	for (int i = 0; i < n - 1; i++) {       // �ռ� �������� for���� �̿��� data�� ������������ �������ش�.
		for (int j = i + 1; j < n; j++) {  
			if (data[i] > data[j]) {		// ������ �� �� �����Ͱ� �� ũ�ٸ� �� �����Ϳ� �ٲ��ش�.
				int temp = data[j];
				data[j] = data[i];
				data[i] = temp;
			}
		}
	}

	for (int i = 0; i < n; i++) {			// ������������ ������ �迭�� �տ������� ���� ���� �������� ���Ѵ�.
		if (data[i - 1] != data[i])		    // ���� �ٸ��ٸ� ������ �ٸ��Ƿ� count�� 1�� �����ش�.
			countType++;
	}
	return countType;
}
int main() {
	int n;
	cin >> n;
	int *data = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> data[i];
	}
	int answer = getElementTypeCount(data, n);
	
	cout << answer;

	delete[] data;
	return 0;
}