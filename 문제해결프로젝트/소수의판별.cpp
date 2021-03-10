#include<iostream>

using namespace std;

bool isPrime(int N) {
	if (N == 1 || N==2) return false; // N�� 1�Ǵ� 2�̸� false ����

	for (int i = 2; i*i <= N; i++) { // N�� ���ݱ����� ����ϵ��� ������ �̿�
		if (N % i == 0) // 2�̻��� ���� ���������ٸ� �Ҽ��� �ƴϹǷ� false����
			return false;
	}
	return true; //for���� �Ϸ�ȴٸ� ����� ���ٴ� ���̹Ƿ� true ����
}

void testcase(int caseIndex) {
	int n;       //�Ǻ����� ���� 
	cin >> n;

	bool result = isPrime(n); 

	cout << "Case #" << caseIndex << "\n";
	if (result)         //isPrime �Լ��� ���� true�̸� �Ҽ��̹Ƿ� YES���
		cout << "YES \n";
	else
		cout << "NO \n";
}

int main() {
	int caseSize; //��� ���ڸ� �Ǻ��Ұ��� �޴� ��
	cin >> caseSize;
	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex++) { // caseSize��ŭ�� for��
		testcase(caseIndex);
	}
	return 0;
}