#include<iostream>
#include<set>	
using namespace std;

int main() {
	int n; //�Է¹��� �׽�Ʈ ���̽��� ����
	cin >> n;

	set<int> s; //�ߺ��Ǵ� ���ڵ��� ������� ��Ʈ

	for (int i = 0; i < n; i++) {  // �׽�Ʈ���̽� ��ŭ for���� �ݺ��ϸ� �ߺ��� Ȯ���Ѵ�.
		int x;
		cin >> x;

		if (s.count(x) > 0) {	    //s�� �̹� x�� �� �ִٸ� �ߺ��Ǵ� ���̹Ƿ�
			cout << "DUPLICATED\n"; //DUPLCATED�� ����Ѵ�.
		}
		else {                      //s�� x�� �� ���� �������̹Ƿ� �ߺ��� �ƴѰ���
			s.insert(x);            //s�� x�� �־��ص� ok�� ����Ѵ�.
			cout << "OK" << endl;
		}
	}
	return 0;
}

