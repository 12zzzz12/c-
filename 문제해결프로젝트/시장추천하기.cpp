#include<iostream>
#include<map>
#include<string>

using namespace std;

int main() {
	int n;   //�Է��� ��ǥ�� ��
	cin >> n;

	map<string, int> frequencymap; //�� �ĺ��� ��ǥ���� ������ map

	int maxfrequency = 0; //�ִ� ��ǥ���� 0���� �ʱ�ȭ

	for (int i = 0; i < n; i++) { //��ǥ ����ŭ for�� �ݺ�
		string st; //�ĺ��� �̸��� ������ ����
		cin >> st; //�ĺ��̸����� ��ǥ
		frequencymap[st]++;       //��ǥ���� �ĺ��� map��ġ�� ��ǥ�� 1����
		int k = frequencymap[st]; // �Է¹��� �ĺ��� ��ǥ�� k�� ����

		if (k > maxfrequency) // �̹��� �Է¹��� �ĺ��� ��ǥ���� �ִ� ��ǥ������ ���ٸ�
			maxfrequency = k; //�ִ� ��ǥ���� �����Ѵ�.
	}

	cout << maxfrequency << endl; //�ִ� ��ǥ���� ���

	map<string, int>::iterator it; //map�� Ž���ϱ� ���� ����

	//map�� Ž���ϸ鼭 key���� �ִ��ǥ���� ���ٸ� �ĺ��̸��� ����Ѵ�.
	for (it = frequencymap.begin(); it != frequencymap.end(); it++) {
		if (it->second == maxfrequency)
			cout <<it->first.c_str() << " ";
	}


	return 0;
}

