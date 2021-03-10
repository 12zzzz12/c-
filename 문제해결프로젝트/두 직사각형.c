#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int get_area(int la, int ra, int ta, int ba, int lb, int rb, int tb, int bb) {

	int l, r, t, b;
	l = max(la, lb); //��ġ�� �簢���� ���� x ��ǥ
	r = min(ra, rb); //��ġ�� �簢���� ������ x ��ǥ
	t = min(ta, tb); //��ġ�� �簢���� ���� y ��ǥ
	b = max(ba, bb); //��ġ�� �簢���� �Ʒ��� y ��ǥ
	
	if(l<=r && b<=t)  //�簢���� ũ�Ⱑ +�ΰ��� Ȯ�� 
	return ((r - l)*(t - b));

	return 0;


}

void test_case() {
	int ax, ay, bx, by; //���簢�� a�� �� 4��
	int px, py, qx, qy; //���簢�� b�� �� 4��
	cin >> ax >> ay >> bx >> by;
	cin >> px >> py >> qx >> qy;

	int la, ra, ba, ta; //���簢�� a
	la = min(ax, bx); //�簢�� a�� ���� x��ǥ
	ra = max(ax, bx); //�簢�� a�� ������ x��ǥ
	ta = max(ay, by); //�簢�� a�� ���� y��ǥ
	ba = min(ay, by); //�簢�� a�� �Ʒ��� y��ǥ

	int lb, rb, bb, tb; //���簢�� b
	lb = min(px, qx); //�簢�� b�� ���� x��ǥ
	rb = max(px, qx); //�簢�� b�� ������ x��ǥ
	tb = max(py, qy); //�簢�� b�� ���� y��ǥ
	bb = min(py, qy); //�簢�� b�� �Ʒ��� y��ǥ

	int answer = get_area(la, ra, ta, ba, lb, rb, tb, bb);

	cout << answer;
}
int main() {
	int t; //�׽�ũ ���̽��� ��
	cin >> t;

	for (int i = 0; i < t; i++) { //�׽�Ʈ ���̽� ����ŭ test_case�Լ� ����
		test_case(); 
	}

	return 0;
}