#include<iostream>
#include<map>

using namespace std;

int main() {
	int n;    //�Է¹��� �׽�Ʈ ������ ����
	cin >> n;

	map<int, int> fremap; // <����, �󵵼�> �� ������ map

	for (int i = 0; i < n; i++) { //�׽�Ʈ ������ŭ for�� �ݺ�
		int x;       //�Է¹��� ����
		cin >> x;
		fremap[x]++; //�Է¹��� ������ map��ġ�� �󵵼� 1����
		cout << fremap.size()<< " " << fremap[x] << endl; //���� �߰����ִ� map�� ������� �� ������ �󵵼� ���
	}

	return 0;
}



