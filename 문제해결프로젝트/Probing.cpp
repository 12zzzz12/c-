#include<iostream>
#include<vector>

using namespace std;

class TicketTable{
public:
	vector<bool> used;//���� ��ȣ �ִ��� Ȯ���ϴ� ����
	int length; //������ ���̸� �ǹ� = �����ϴ� ȸ�� ��

	TicketTable(int length) {
		this->length = length;
		this->used.assign(length, false); // ��� false�� �ʱ�ȭ
	}

	int findEmptyIndexByUserId(int userId) { //ȸ����ȣ�� ���ǹ�ȣ ����ϴ� �޼ҵ�
		int index = userId % length; //ȸ���� ��ȣ%���� �� �� ���� ��ȣ ���
		while (this->isEmpty(index) == true) { //���� ��ȣ�� ��� �ִٸ� �ǳʶ� 
			index = (index + 1) % length; //���ǹ�ȣ�� �ִٸ� ������ȣ�� ����
		}
		return index; //���� ��ȣ ��ȯ
	}

	bool isEmpty(int ticketIndex) { //���� �ڸ��� ����ִٸ� false
		return this->used[ticketIndex];  //�̹� �ڸ��� ���ٸ� true
	}
	void setUsed(int index, bool status) { //���� ��ȣ �ڸ��� �����ϸ� 
		this->used[index] = status; //�� �ڸ��� true�� ��ȯ
	}
};

vector<int> getTicketNumbers(int n, int m, const vector<int>& ids) {
	vector<int> tickets;
	TicketTable table = TicketTable(n); //���̺� ��ü ����

	for (int i = 0; i < m; i++) {
		int userId = ids[i]; // userid�� ȸ���� ��ȣ ����
		int ticketIndex = table.findEmptyIndexByUserId(userId); 
		tickets.push_back(ticketIndex); // ���� ��ȣ�� ���Ϳ� ����
		table.setUsed(ticketIndex, true); // �ش� ���� ��ȣ �ڸ��� true�� ��ȯ
	}
	return tickets;
}

int main() {
	int n, m;
	cin >> n >> m; // �غ��� ���� ��, ������ ȸ�� ��

	vector<int> ids(m); //ȸ�� �� ��ŭ�� ���� ����
	for (int i = 0; i < m; i++) { //ȸ����ȣ ���Ϳ� ����
		cin >> ids[i];
	}
	vector<int> tickets = getTicketNumbers(n, m, ids); //���� ��ȣ ����
	for (int i = 0; i < tickets.size(); i++) {
		cout << tickets[i] << "\n"; //���� ��ȣ ���
	}

}