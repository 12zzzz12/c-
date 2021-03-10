#include<iostream>
#include<math.h>
using namespace std;



class Point2D {
private:
	int x;
	int y;
public:
	Point2D(int x = 0, int y = 0) {    //����ü ����� x,y �� ����ֱ�
		this->x = x;          
		this->y = y;
	}

	int getSquaredDistanceTo(const Point2D &target) const { // ����ü �� �Ÿ� ����ϴ� �޼ҵ�
		int dx = abs(this->x - target.x);
		int dy = abs(this->y - target.y);

		return dx * dx + dy * dy;
	}

	//getDistanceTo �Լ��� ������� �ʾƼ� �������ϴ�.
};

int main() {
	int n;          //���� ������ �޴� ����
	Point2D *points;

	cin >> n;
	points = new Point2D[n];  // ���� ������ŭ Point2D����ü�� �����.

	for (int i = 0; i < n; i++) {   //�� ���� ��ǥ���� point2d ����ü�� �־��ִ� for��
		int x, y;					//�� ���� x,y��ǥ 
		cin >> x >> y;
		points[i] = Point2D(x, y);  
	}
	int min_sqd = INT_MAX;
	int min_cnt = 0; // �ּ� �Ÿ��� ������ ���� ��

	for (int i = 0; i < n; i++) {  //�� ���� �Ÿ� ���ϴ� for ��
		for (int j = 0; j < i; j++) {
			int sqd = points[i].getSquaredDistanceTo(points[j]);
			if (sqd < min_sqd) {
				min_sqd = sqd;
				min_cnt = 1;
			}
			else if (sqd == min_sqd) { //�Ÿ��� �ּ� �Ÿ��� ���ٸ� ���� ������ �߰�
				min_cnt++;
			}
		}
	}
	double distance = sqrt(min_sqd);  //������ ���� �Ÿ��� ��Ʈ�����ִ� �۾�
	
	cout << fixed;      //distance �� �Ҽ��� 1�ڸ� ����
	cout.precision(1);  // �������� ��

	cout << distance << '\n';
	cout << min_cnt;

	delete[] points;
	return 0;
}




