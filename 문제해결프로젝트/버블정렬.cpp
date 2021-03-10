#include<iostream>
#include<math.h>
using namespace std;


void bubbleSort(int data[], int n) {

	for (int i = 0; i < n; i++) {
		int na = 0;					//2�� ° for���� ù ����Ŭ�� ������������ Ȯ��
		for (int k = 0; k < n - 1 -i; k++) {
			if (data[k] > data[k + 1]) { //�� �����Ͱ� �ں��� ũ�� �ڸ��� �ٲ��ش�.
				int temp = data[k];
				data[k] = data[k + 1];
				data[k + 1] = temp;
				na = 1;			// ū�� �� �տ� ������ na�� 1�� �ٲ�
			}
		}
		if (na == 0)      //���� 2��° for������ ù ����Ŭ�� ���������̶�� na=0�̹Ƿ� for�� ����
			break;
	}
}

int main() {
	
	int n;					//�Է¹��� ������ ����
	cin >> n;

	int* data = new int[n];  // �Է¹��� ���ڸ� ���� �迭

	for (int i = 0; i < n; i++) { //�迭�� ���ڸ� ����־��ش�.
		cin >> data[i];
	}
	bubbleSort(data, n);   //�迭�� ���������Ѵ�.

	for (int i = 0; i < n; i++) {
		cout << data[i] << " ";
	}
	delete[] data;
	return 0;
}