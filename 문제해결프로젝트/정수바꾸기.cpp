#include<iostream>
#include<string>

using namespace std;

int cnt = 1 ; //������ �ּҰ� ���ϴ� ī��Ʈ

int division2(int b) { //b�� ¦���� �� 2�� �������ִ� �Լ�
	cnt += 1; //ī��Ʈ 1 ����
	return b / 2;
}

int minusone(int b) { //b�� �� �ڿ� �ִ� 1�� �����ִ� �Լ�
	
	string str1 = to_string(b); //���� b�� ���ڿ��� ��ȯ
	
	int len = str1.length(); //���ڿ��� ��ȯ��Ų �� ���� ����

	str1.erase(len-1,len); //b�� �ǵڿ� 1�� ���� 
	
	cnt += 1; //ī��Ʈ 1����


	return stoi(str1);
}

int main() {
	//b�� Ȧ�� -> �ǵ��� 1�� ����
	//b�� ¦�� -> %2  �� �ݺ��Ͽ� a�� ã�� �ּ� Ƚ���� ���ϴ� �˰����Դϴ�.

	int a; // ���� ����
	int b; // ���� ����

	cin >> a >> b;


	string strb = to_string(b); //b�� ���ڿ��� ��ȯ
	int blen = strb.length(); //���ڿ��� ���� Ȯ��
	string last = strb.substr(blen - 1, blen); //������ ���� Ȯ��
	if (stoi(last) %2 == 1 && stoi(last) != 1) { //������ ���ڰ� 1�� �ƴ� Ȧ�����
		cout << -1;								 // -1 ��°� ����
		return 0;
	}

	while (1) {
		if (b == a) { //b�� a�� ���ٸ� cnt ��°� �ݺ��� ����
			cout << cnt;
			break;
		}
		else if (b == 1) { //b�� 1�� �ǵ��� a�� ������ ���Ѵٸ� -1�� ���
			cout << -1;
			break;
		}
		else {
			if (b % 2 == 0) { // b�� ¦����� 2�� �������ش�.
				b = division2(b);
			}
			else {
				b = minusone(b); //b�� Ȧ����� 1�� ���ִ� �Լ��� ������.
			}
		}
	}

	return 0;
}