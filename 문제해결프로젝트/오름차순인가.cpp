#include<iostream>
using namespace std;

bool isOrdered(int data[], int n) {

	for (int i = 0; i < n-1; i++) {       // 0 ~ n-2 ��(index) ������ for��
		for (int j = i + 1; j < n; j++) { // 1 ~ n-1 ��(index) ������ for���� �̿��� 
			if (data[i] > data[j])		  // (0,1),(0,2)...(0,n-1) ���� ������� �տ� �ִ� ���� �ڿ� �ִ� ���� ���ϴ� �۾��� �Ѵ�. 
				return false;			  // �տ� �ִ°� �� ũ�ٸ� false�� �����ϸ� �����Ѵ�.
		}
	}
	return true;						  // false���� ������� �ʾҴٸ� ���������� �����Ƿ� true�� �����Ѵ�.
}

int main() {
	int n;
	
	cin >> n;
	int *data = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> data[i];
	}
	bool result = isOrdered(data, n);

	if (result) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	
	delete[] data;
	return 0;
}