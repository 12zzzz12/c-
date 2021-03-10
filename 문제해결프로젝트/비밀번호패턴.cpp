#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> password; //�н����� ���� ����
int pre;          //�н����� ���� ���� Ȯ���� ����

//�н����� ���Ϳ� ���� ��ȣ�� �����ϴ��� Ȯ�� �ϴ� �޼ҵ�
int passwordcheck(int pattern) {
	if (find(password.begin(), password.end(), pattern) != password.end())
		return 1;
	else
		return 0;
}

//�߰� ���ڰ� �ʿ��� 8���� ���� Ȯ���ϴ� �޼ҵ�
int visitcheck(int pre, int pattern) { //���� ���� ���� ���� �Ű������� �޴´�.
	if ((pre == 1 && pattern == 3) || (pre == 3 && pattern ==1)) {
		return passwordcheck(2); //���� 1,3 �� ���ӵ� ��� ���� 2�� �ִ��� Ȯ��
	}
	else if ((pre == 1 && pattern == 7) || (pre == 7 && pattern == 1)) {
		return passwordcheck(4);
	}
	else if ((pre == 1 && pattern == 9) || (pre == 9 && pattern == 1)) {
		return passwordcheck(5);
	}
	else if ((pre == 3 && pattern == 7) || (pre == 7 && pattern == 3)) {
		return passwordcheck(5);
	}
	else if ((pre == 9 && pattern == 7) || (pre == 7 && pattern == 9)) {
		return passwordcheck(8);
	}
	else if ((pre == 3 && pattern == 9) || (pre == 9 && pattern == 3)) {
		return passwordcheck(6);
	}
	else if ((pre == 2 && pattern ==8) || (pre == 8 && pattern ==2)) {
		return passwordcheck(5);
	}
	else if ((pre == 4 && pattern == 6) || (pre == 6 && pattern == 4)) {
		return passwordcheck(5);
	}

	return 1;

}

int process(int pattern) {

	//���� �ߺ��˻� if��
	if (passwordcheck(pattern))
		return 0; //�ߺ��ȴٸ� 0 ����

	else   //������ �ߺ����� �ʴ´ٸ� ���ڸ� ���Ϳ� ����ִ´�.
		password.push_back(pattern);

	//���� ���ڿ� ���� ���� ���̿� ���ڰ� �ִ��� Ȯ���ϴ� �۾�
	if (visitcheck(pre, pattern) == 0)
		return 0;

	//���� ���� ������ ���� �ְ� �޼ҵ� ����
	pre = pattern;

	return 1;
}

int main() {

	int n; //�Է¹��� ���� ����
	int pattern; //��й�ȣ 
	int yes; //�ùٸ� �������� Ȯ���� ����

	cin >> n; 

	for (int i = 0; i < n; i++) {
		cin >> pattern;
		yes = process(pattern); // yes�� �ùٸ� �������� ���� ����
		if (!yes) { //�ùٸ��� �ʴٸ� no�� ����ϰ� ����
			cout << "NO";
			return 0;
		}
	}
	//���� for���� ������ ���ƴٸ� YES�� ����Ѵ�.
	cout << "YES";
	return 0;
}