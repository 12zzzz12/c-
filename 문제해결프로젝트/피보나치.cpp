#include <iostream>
#include<vector>
using namespace std;

const int MAX_N = 1000000;
vector<int> FIBONACCI_TABLE;


vector<int> makeFibonacciTable(int n) {
	const int MOD = 100000000; 

	vector<int> ret(n + 1); // ret ���� ����
	ret[1] = 0; //�Ǻ���ġ ù��° ������ 0�̹Ƿ� �ʱ�ȭ
	ret[2] = 1; // �ι�° ���ڴ� 1�̹Ƿ� 1�� �ʱ�ȭ

	for (int i = 3; i <= n; ++i) { //�Ǻ���ġ ������ ����ϴ� for��
		ret[i] = ret[i - 1] + ret[i - 2];
		ret[i] %= MOD;
	}
	return ret; //���ϴ� ������ �Ǻ���ġ �� ����
}

int getFibo(int n) {
	int answer = FIBONACCI_TABLE[n]; //���ϴ� n��° �Ǻ���ġ ���� ����
	return answer;
}

int main() {
	FIBONACCI_TABLE = makeFibonacciTable(MAX_N);

	int caseSize;  //�Է¹��� �Ǻ���ġ ���� ����
	cin >> caseSize;

	int *data = new int[caseSize]; //��� ° �Ǻ���ġ ������ �����ϴ� �迭

	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex++) { //���ϴ� n��° ���ڵ� �Է�
		int n;
		cin >> n;
		data[caseIndex - 1] = n; //�迭�� ���ϴ� n���� ���ڵ��� ����
	}
	for (int i = 0; i< caseSize; i++) {
			cout << getFibo(data[i]) << "\n"; //data�迭�� �����ص� ���ڷ� ���ϴ� n��° ���ڵ���
	}										//getFibo�޼ҵ带 �̿��� ���ٿ� �Ѱ��� ����Ѵ�.
	FIBONACCI_TABLE.clear();
	return 0;
}