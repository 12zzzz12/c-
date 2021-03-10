#include <iostream>
#include<vector>
using namespace std;

const int MAX_SERIAL_NUMBER = 100000;	

void fillFrequencyTable(const vector<int> & data, int n, vector<int> &table) {
	table.clear(); //table ���͸� �ʱ�ȭ
	table.resize(MAX_SERIAL_NUMBER + 1, 0); //table ����ũ�⸦ MAX_SERIAL_NUMBER + 1, ��� 0���� �ʱ�ȭ�Ѵ�. 

	for (int i = 0; i < n; i++) {
		int serial = data[i]; //�Է¹��� ���ڸ� serial�� ����
		table[serial] += 1; //serial���� �ε����� �̿��� ī��Ʈ�� ����.
	}
}

vector<int> getUniqueElements(const vector<int> &data, int n) {
	vector<int> ret; //ret ���� �������ش�.

	vector<int> table; //table ���� ����
	fillFrequencyTable(data, n, table); //�Է¹��� ���ڸ� index�� ������ ���̺�� ��ȯ.

	for (int number = 1; number <= MAX_SERIAL_NUMBER; number += 1) { 
		if (table[number] == 1) // �Է¹��� ���ڰ� �Ѱ��� ���鸸�� ret���Ϳ� �ٽ� �־��ش�.
			ret.push_back(number);
	}

	return ret; //�Ѱ��� �Էµ� ���ڵ��� ������ �ִ� ret���͸� �������ش�.
}

int main() {
	int n; //������ ������ ����
	cin >> n;

	vector<int> data = vector<int>(n); //������� ���ڸ� ���� ����

	for (int i = 0; i < n; ++i) { //���Ϳ� ���ڵ��� �Է�
		cin >> data[i];
	}
	const vector<int> answer = getUniqueElements(data, n); //���ڵ��� ����, �ߺ����� �Ѵ�.

	for (int i = 0; i < answer.size(); ++i) { //�߷��� ���ڵ��� ���
		if (i > 0) {
			cout << " ";
		}
		cout << answer[i];
	}


	return 0;
}