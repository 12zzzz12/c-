#include<iostream>
#include<math.h>
using namespace std;

bool isConsecutive(int data[], int n) {

	int max_data = data[0];  //�迭 �� �ִ�
	int min_data = data[0];  //�迭 �� �ּڰ�

	for (int i = 0; i < n; i++) {  // �迭 �� �ִ�, �ּ� �� �����ϴ� for��
		if (max_data < data[i])
			max_data = data[i];
		if (min_data > data[i])
			min_data = data[i];
	}
	if (max_data - min_data == n - 1) //�迭 �� �ִ밪 -�ּڰ��� n-1�̶�� ���ӵ� ���ڵ�
		return true;
	else           // �׷��� �ʴٸ� ���ӵ��� ����
		return false;
}

int main() {
	int n;	//�Է¹��� ������ ����
	cin >> n;

	int* data = new int[n]; // ���ڵ��� ������� �迭
	for (int i = 0; i < n; i++) {
		cin >> data[i];
	}
	bool result = isConsecutive(data, n); //���ڵ��� ���ӵǴ��� Ȯ��

	if (result)
		cout << "YES";
	else
		cout << "NO";

	delete[] data;
	return 0;
}