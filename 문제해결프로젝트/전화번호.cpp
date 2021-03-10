#include <iostream>
using namespace std;
const int MAX_TABLE_LENGTH = 10000;

void fillFrequencyTable(int data[], int n, int table[]) {

	int frquent_number = 0; 
	for (int i = 0; i < MAX_TABLE_LENGTH; i++) //���̺��� ��� 0���� �ʱ�ȭ
		table[i] = 0;
	for (int i = 0; i < n; i++) {  //������ ������ŭ 
		frquent_number = data[i];  //frequent�� ������ ���� �ִ´�.
		table[frquent_number] += 1; //frequent_numver�� �ε����� ���ϰ� ī��Ʈ�� 1���� �÷��ش�.
	}
}

int getFrequencyNumber(int data[], int n) { //���� ���� ��ȭ��ȣ�� ã�� �޼ҵ�
	int frequent_number = 0; 
	int table[MAX_TABLE_LENGTH]; //���̺��� �ִ����� ����

	fillFrequencyTable(data, n, table);
	
	for (int i = 0; i < MAX_TABLE_LENGTH; i++) {
		if (table[i] > table[frequent_number])  //�� ���� ���ؼ� i����ũ�� frquent�ѹ��� i�� �ٲ��ش�.
			frequent_number = i;
	}


	return frequent_number;
}

int main() {
	int n; //�Է¹��� ��ȭ��ȣ�� ����

	cin >> n;
	int *data = new int[n]; //��ȭ��ȣ�� ������� �迭

	for (int i = 0; i < n; i++) {
		cin >> data[i];
	}
	int answer = getFrequencyNumber(data, n); //���� ���� ��ȭ��ȣ�� ã�� �޼ҵ�

	cout << answer;

	return 0;
}