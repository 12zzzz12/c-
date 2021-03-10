#include <iostream>
using namespace std;

const int MAX_SEAT_NUMBER = 1000;
const int MAX_COLOR_NUMBER = 100;

class Painting { //����Ʈ Ŭ���� 
public:
	int left; //ó���� ��ĥ�� �ڸ�
	int right;//�ι�°�� ��ĥ�� �ڸ�
	int color;

	Painting() {}

	Painting(int left, int right, int color) {
		this->left = left;      
		this->right = right;
		this->color = color;
	}
};

void fillFrequencyTable(int data[], int n, int table[]) { //���̺��� ���ϴ� �Լ�
	for (int i = 0; i < MAX_COLOR_NUMBER; i++) //��� �¼��� ó���� 0���� �ʱ�ȭ
		table[i] = 0;
	for (int i = 0; i < n; i++) { //�Է¹��� ������ �÷����� ���� 
		int color = data[i];
		table[color] += 1; //frequency ������ ���ϱ� ���� 1�� �����ش�.
	}

}
void solve(int n, int m, const Painting *paintings) {  
	int *seats = new int[n]; //�¼� �迭�� n��ŭ ����
	for (int i = 0; i < n; i++) { //��� �¼��� 0���� �ʱ�ȭ
		seats[i] = 0;
	}
	for (int i = 0; i < m; i++) { //��ĥ�� �����ŭ ����ü ���� 
		const Painting &p = paintings[i];

		for (int j = p.left; j <= p.right; j++) { // �� ����ü�� ������ �¼��� ���� ����
			seats[j] = p.color;
		}
	}

	int *table = new int[MAX_COLOR_NUMBER]; //���� ������ŭ ���̺� ũ�� ����
	fillFrequencyTable(seats, n, table); // ��ĥ�� �¼����� �˾Ƴ��� ���� �޼ҵ�

	int minColor = seats[0]; //���� ���� ����
	int maxColor = seats[0]; //���� ���� ����
	
	for (int color = 0; color < MAX_COLOR_NUMBER; color += 1) { //max�÷��� min�÷��� ã�� ���� for��
		if (table[color] == 0) {
			continue;
		}
		if (table[minColor] > table[color])
			minColor = color;
		if (table[maxColor] < table[color])
			maxColor = color;
	}
	cout << maxColor << "\n"; //maxColor ��� ù��° ���
	cout << minColor; //minColor ��� �ι�° ���

	delete[] table;
	
}



int main() {
	int n; //�¼��� ��  
 	int m; //��ĥ�� ����� ��
	cin >> n >> m;

	Painting *paintings = new Painting[n];

	for (int i = 0; i < m; i++) { //
		cin >> paintings[i].left;
		cin >> paintings[i].right;
		cin >> paintings[i].color;

		paintings[i].left -= 1;
		paintings[i].right -= 1;
	}
	solve(n, m, paintings);
	return 0;
}