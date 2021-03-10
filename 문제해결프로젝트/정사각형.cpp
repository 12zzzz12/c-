#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;


class Point2d {
public:
	int x;           //�� ���� x��ǥ
	int y;			 //�� ���� y��ǥ
	int index;       //�� ���� ��ȣ

	Point2d(int index, int x, int y) { //�� ����
		this->index = index;
		this->x = x;
		this->y = y;
	}
	Point2d( int x, int y) { //�� ����
		this->index = 1;
		this->x = x;
		this->y = y;
	}

	long long getSquaredDistance(Point2d target) { // �� ���� �� x��ǥ �Ÿ� , y��ǥ �Ÿ� ���ϴ� �޼ҵ�
		long long dx = abs(this->x - target.x);    // �� ���� x��ǥ �Ÿ�
		long long dy = abs(this->y - target.y);    // �� ���� y�� �Ÿ�
		return dx * dx + dy * dy;
	}

	bool operator < (const Point2d& other) const { //�� ������ ��Һ�

		if (this->x != other.x) {     //x��ǥ ������ ���� ��
			return this->x < other.x;
		}

		return this->y < other.y;    //x��ǥ ���� ���ٸ� y��ǥ ������ ��
	}

};

long long getMaximumSquare(int n, const vector<Point2d>& points) { //�ִ� �簢�� ���� ���ϴ� �޼ҵ�
	long long answer = 0;     //�ִ� �簢�� ���̸� ���� ����

	set<Point2d> pset;        //�� ����ü���� ������� set

	for(int i = 0; i < n; i++) { //���� ������ŭ ����ü�� �����ѵ� set�� ����ִ´�.
		pset.insert(points[i]);
	}

	for (int i = 0; i < n; i++) {    //���� ������ŭ for���� �ݺ��Ѵ�.
		Point2d pa = points[i];      //�ӽ� ���� pa�� �����Ѵ�. 
		for (int j = 0; j < n; j++) {
			Point2d pb = points[j];  //�ι�° ���� pb�� �ӽ� �����Ѵ�.
		
			if (i == j) continue;     //i, j�� ���ٸ� ���� ���̹Ƿ� �����ϰ� �Ѿ��.

			long long area = pa.getSquaredDistance(pb); //�� ���� �̿��� �簢�� ���̸� ���Ѵ�.

			if (area < answer) {     //���� area�� answer���� �۴ٸ� �ִ� ���� �ƴϹǷ� continue�� �̿��� �Ѿ��.
				continue;
			}
			//���簢���� ����� ���� ������ �� ���� ã�� ���� x,y�Ÿ�
			int dx = pb.x - pa.x;   // ������ �� ���� ã�� ���� x�Ÿ�
			int dy = pb.y - pa.y;   // ������ �� ���� ã�� ���� y�Ÿ�

			Point2d pd(pa.x - dy, pa.y + dx);  //���簢���� ����� ���� �� 1
			Point2d pc(pb.x - dy, pb.y + dx);  //���簢���� ����� ���� �� 2
			
			//�� 1,2 �� pset�� �ִ��� Ȯ���Ͽ� ���簢���� ���� �� �ִ��� Ȯ���Ѵ�.
			if (pset.count(pc) > 0 && pset.count(pd) > 0) 
				answer = max(answer, area); //���� �־��� ����� ���簢���� ���� �� �ִٸ� answer�� ���� ���� ���Ͽ� ū ������ �����Ѵ�.
			
		}
	}


	return answer;
}

void process(int caseIndex) { // ������ �Է��ϰ� �ִ� �簢�����̸� ����ϴ� �޼ҵ�
	int n; //���� ����
	cin >> n;

	vector<Point2d> points; // �� ����ü���� ���� ����

	for (int i = 0; i < n; i++) { // ���� ������ŭ x,y��ǥ�� �Է¹ް� ����ü�� �����Ѵ�.
		int x, y;
		cin >> x >> y;
		points.push_back(Point2d(i, x, y)); //�� �ϳ��� �����ϰ� ���Ϳ� ����ִ´�.
	}
	long long answer = getMaximumSquare(n, points); //�ִ� �簢�� ���̸� answer�� �޾� �����Ѵ�.
	cout << fixed << setprecision(2) << answer << endl; //�ִ� �簢�� ���� �Ҽ��� 2°�ڸ����� ����Ѵ�.
}

int main() {
	int caseSize;   //�Է¹��� �׽�Ʈ ���̽� ��
	cin >> caseSize;

	for (int i = 1; i <= caseSize; i++) { //�׽�Ʈ ���̽���ŭ for���� �ݺ��Ѵ�.
		process(i);
	}
	return 0;
}