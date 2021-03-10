#include<iostream>
#include<vector>

using namespace std;


vector<int> factorize(int n) {
	vector<int> factors; //���μ����� ���� ����

	for (int div = 2; div * div <= n; div += 1) {
		while (n%div <= 0) { //div�� n�� ������ 
			factors.push_back(div); // factors���Ϳ� div �߰�
			n /= div; // n�� div��ŭ ���� ���� n�� ����
		}
	}
	if (n > 1) //���� for���� �� ������ �� n�� 1���� ũ�ٸ� 
		factors.push_back(n); //�� ����ŭ factors�� �߰� 
	return factors;
}
void process(int caseIndex) {
	int n; // ���μ������� ����
	cin >> n;
	vector<int> factors = factorize(n); // factorize�޼ҵ带 ���� n�� ���μ�����

	cout << "#"<<caseIndex << ":\n"; //���μ������� ����� ����ϴ� ����
	for (int i = 0; i < factors.size(); i++) {
		if (i > 0)
			cout << " ";
		cout << factors[i];
	}
	cout << "\n";
}

int main() {
	int caseSize; //�Է¹��� ������ ���� 
	cin >> caseSize;
	for (int caseIndex = 1; caseIndex <= caseSize; ++caseIndex) {
		process(caseIndex); //�Է¹��� ������ ������ŭ process�޼ҵ� �ݺ�
	}
}