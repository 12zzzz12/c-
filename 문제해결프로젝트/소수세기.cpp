#include<iostream>
#include<vector>

using namespace std;

class Sieve {
public:
	int maximumValue; //������ �ִ�
	vector<bool> isPrime; //�Ҽ� ���� �Ǻ��ϱ� ���� ����
	Sieve(int maximumValue) {
		this->maximumValue = maximumValue;
		this->isPrime.assign(maximumValue + 1, false); //���͸� maximumValue+1 ũ��� false�� �ʱ�ȭ
		this->fillSieve(); // �������� �Ҽ����� Ȯ���ϴ� �޼ҵ�
	}

	bool isPrimeNumber(int num) const {
		return this->isPrime[num]; //isPrime�� ���� ���� �Ҽ����� �Ǻ�
	}
	void fillSieve() {
		isPrime.assign(this->maximumValue+1, true); //isPrime���͸� true�� �ʱ�ȭ
		isPrime[0] = isPrime[1] = false; // 0�� 1�� �Ҽ��� �ƴϹǷ� false ����

		for (int num = 2; num <= maximumValue; num += 1) { //2~���� �ִ� ���� for��
			if (isPrime[num] == false) // �Ҽ��� �ƴ϶�� ���� for�� ����
				continue;
			for (long long mul = (long long)num * num; mul <= maximumValue; mul += num) {
				int index = (int)mul;  // //�Ҽ��� �ƴ� ������ġ (index)�� false����
				isPrime[index] = false;
		}
		}

	}
};
vector<int> getAllPrimeNumbers(int from, int to, const Sieve& sieve) { //�������� �Ҽ��� ���Ϳ� �ִ� �޼ҵ�
	vector<int> primes;

	for (int num = from; num <= to; num += 1){
	if (sieve.isPrimeNumber(num)) //�Ҽ��� �´ٸ� primes���Ϳ� ����ִ´�.
		primes.push_back(num);
	}
	return primes;// primes���� ����
}

void process(int caseIndex, const Sieve& sieve) {
	int L, R;
	cin >> L >> R; //���� �� �Է�

	vector<int> allPrimeNumbers = getAllPrimeNumbers(L, R, sieve); //allPrimeNumbers���Ϳ� ������ �Ҽ��� ����

	cout << "Case#" << caseIndex << ":\n"; 
	cout << (int)allPrimeNumbers.size() << "\n"; //�Ҽ��� ����� ������ size�� ��������� �Ҽ��� �������
}

int main() {
	const int MAX_VALUE = 1000000;	
	Sieve sieve = Sieve(MAX_VALUE);

	int caseSize; //�Է¹��� �׽�Ʈ���̽��� ��
	cin >> caseSize;
	for (int i = 1; i <= caseSize; i++) { //�׽�Ʈ���̽� ����ŭ process�޼ҵ� �ݺ�
		process(i, sieve);
	}
}
