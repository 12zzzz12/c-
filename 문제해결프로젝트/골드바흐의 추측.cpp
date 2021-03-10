#include<iostream>
#include<vector>
using namespace std;

#define MAX_VALUE 1000000 // �ִ밪 ����
vector<int> isPrime; //�� ���ڰ� �Ҽ����� Ȯ���ϴ� ����
int cnt;      // ���° ���̽����� ī��Ʈ

void Eratosthenes() { //�����佺�׳׽��� ü �˰����� ���� isPrime���Ϳ� �Ҽ��ΰ��� �Ǻ�
	isPrime.assign(MAX_VALUE, 1); //�ִ� �� ��ŭ ���͸� ��� true�� �ʱ�ȭ

	for (int i = 2; i*i < MAX_VALUE; i++) //�Ʒ��� ������ ���� �Ҽ��Ǻ��ϹǷ� size�� ��Ʈ�������� for��
		if (isPrime[i])
			for (int j = i * i; j < MAX_VALUE; j += i) //������ �̿��Ͽ� �Ҽ� �Ǻ�
				isPrime[j] = 0;                   //�Ҽ��� �ƴ϶�� 0���� ��ȯ
}


void solve(int test) {

	for (int i = 3; i < test / 2 + 1; i++) { //i�� 3���� �����Ͽ� 1�� test�� ���� ������ �ö󰣴�  (Ȧ���� �Ҽ��� ���ϹǷ�)
		for (int k = test; k >= 3; k--) {	  //k�� test�� ���ں��� 1�� �ٿ� 3���� ��������        (3������ ���δ�)
			if (i + k == test && isPrime[i] && isPrime[k]) { //i,k�� ������ �� test���� �����鼭 �Ѵ� �Ҽ� �ΰ�� ���
				cout << "Case #" << cnt << ":\n";
				cout << test << " = " << i << " + " << k << "\n";
				cnt++; //case�� ����ѵ� ī��Ʈ 1����
				return;//���� �������Ƿ� �޼ҵ� ����
			}
		}
	}
	cout << "Case #" << cnt << "\n" << "-1\n"; //���� �ݺ����� ���ٸ� ���� �� ���°��̹Ƿ� -1���
	cnt++;	                                   //ī��Ʈ 1 ����
}

int main() {
	cnt = 1;          //ī��Ʈ 1 �� ����
	Eratosthenes();  //�����佺�׳׽� �޼ҵ�� isPrime���� �Ҽ� ����

	int casesize;     // �׽�Ʈ���̽��� ����
	cin >> casesize;  // �׽�Ʈ���̽� �Է�

	int *test = new int[casesize]; //�׽�Ʈ�� ���ڸ� ���� �迭

	for (int i = 0; i < casesize; i++) {  //�׽�Ʈ�� ���ڸ� �迭�� �Է�
		cin >> test[i];
	}
	for (int i = 0; i < casesize; i++) {  //������� �׽�Ʈ�� ���ڸ� solve�޼ҵ忡 ����
		solve(test[i]);
	}

	return 0;
}
