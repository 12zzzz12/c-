#include<iostream>
#include<math.h>
using namespace std;



bool isInside(long x, long y, long R)
{
	long sqd = x * x + y * y; //x^2 + y^2 < r^2 �� ã������ ��
	if (sqd < R*R) // r^2 ���� �۴ٸ� �� ���̹Ƿ� true����
		return true;
	return false;
}

void testcase(int caseIndex)
{
	long R;			// ���� ������
	cin >> R;

	long sum = 0;	// ���ȿ� ���� 1��и� �ȼ� ��
	long y = R;	    // �ȼ��� ã�� ���� y��ǥ �� ����
	for (long x = 0; x <= R; x++) { // x��ǥ�� ���� �ȼ� ã������ for��
		long height = 0;
		for (; y >= 0; y--) { //y��ǥ�� ���������� ã�� for��
			if (isInside(x, y, R)) { //�ȼ��� ���ٸ� �װ��� y��ǥ��
				height = (y + 1);    //���� ���� ���̹Ƿ� �װ��� height�� ����
				break;
			}
		}
		sum += height; // �� x��ǥ�� �ȼ����� ���ذ���.
	}


	cout << "#" << caseIndex << "\n";
	cout << sum * 4 << "\n"; //sum�� 1��и� ���� �ȼ����̹Ƿ� *4�� ���ش�.
}

int main() {
	int caseSize; //�Է¹��� ���� ����
	cin >> caseSize;

	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex ++) {
		testcase(caseIndex);
	}
	return 0;
}