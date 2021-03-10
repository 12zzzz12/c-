#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class City {//�� ������ ��ȣ�� �ҵ��� ������ Ŭ����
public:
	int index; //��ȣ
	int income;//�ҵ�

	City(int index, int income) {
		this->index = index;   //������ ���� ����
		this->income = income; //������ �ҵ� ����
	}

	bool operator < (const City& o) const { //�켱���� ť ��Ұ��踦 �����ϱ� ���� operator
		return this->income < o.income; //income���� ��Ұ��� ��
	}

	bool operator > (const City& o) const {//�켱���� ť ��Ұ��踦 �����ϱ� ���� operator
		return this->income > o.income; //income���� ��Ұ��� ��
	}

};

int getMaximumRange(int n, int k, const vector<City>& cities) {
	int answer = 0; //�ҵ����� ������ ����

	priority_queue<City, vector<City>, greater<City>> rangeMinimum; //�ҵ��� ���� ���� ���ú��� pop�Ǵ� �켱���� ť

	priority_queue<City> rangeMaximum; //�ҵ��� ���� ���� ���ú��� pop�Ǵ� �켱���� ť

	for (int i = 0; i < k - 1; i++) { //���ӵ� ���� k���� ���� �� k-1�� ��ŭ �����ϴ� �ݺ���
		rangeMaximum.push(cities[i]); //�ҵ��� ���� ���� ���� ������� ť�� ����
		rangeMinimum.push(cities[i]); //�ҵ��� ���� ���� ���� ������� ť�� ����
	}
	for (int i = k - 1; i < n; i++) { //k��° ���ú��� n��° ���ñ��� �����ϰ� answer���� �����ϴ� �ݺ���
		rangeMaximum.push(cities[i]); //�ҵ��� ���� ���� ���� ������� ť�� ����
		rangeMinimum.push(cities[i]); //�ҵ��� ���� ���� ���� ������� ť�� ����
		while (rangeMaximum.top().index < i - k + 1) //���ӵ� k���� ���� ������ ���߱� ���� ť���� pop�� �̿��� ����
			rangeMaximum.pop();
		while (rangeMinimum.top().index < i - k + 1) //���ӵ� k���� ���� ������ ���߱� ���� ť���� pop�� �̿��� ����
			rangeMinimum.pop();
		answer = max(answer, rangeMaximum.top().income - rangeMinimum.top().income); //���ӵ� k���� ���� �� (�ҵ� ū ���� ť�� ž - �ҵ� ���� ���� ť�� ž)�� �̿��� answer���� ���� 
	}



	return answer;
}

void process(int caseIndex) { //������ ����� �޼ҵ�
	int n, k; // ������ ����, ���ӵǴ� ������ ����

	cin >> n >> k;
	vector<City> cities; //���� ����ü�� ���� ����

	for (int i = 0; i < n; i++) { //�������� �ҵ�� ������ �Է��ϴ� �ݺ���
		int income; 
		cin >> income; //�ҵ��Է�
		cities.push_back(City(i, income)); //���Ϳ� ���� ����ü ����
	}

	int answer = getMaximumRange(n, k, cities); //������ �����´�.

	cout << answer << endl;
}

int main() {
	int caseSize; //�׽�Ʈ ���� ����
	cin >> caseSize;

	for (int i = 0; i < caseSize; i++) { //�׽�Ʈ ������ŭ �ݺ�
		process(i);
	}
}