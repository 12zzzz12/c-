#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

class Histogram { //�� ����� ����ü�� ���� Ŭ����
public:
	int height; //����� ����
	int leftX;  //����� ���� x��ǥ
	int rightX; //����� ������ x��ǥ

	Histogram(){}

	Histogram(int index, int height) { //����� ��ġ�� ���� ����
		this->leftX = index; //���� x��ǥ�� index��
		this->rightX = this->leftX + 1; //������ x��ǥ�� leftx +1 ��
		this->height = height; //���� ����
	}
};
long getLargestRectanglearea(const vector<Histogram>& histograms) {
	long answer = 0;

	stack<Histogram> stk; //��� ����ü�� ���������� ���� ����

	stk.push(Histogram(-1, 0)); //(0,0)��ǥ�� �����Ѵ�

	for (int i = 0; i < histograms.size() + 1; i++) { //����� ����+1��ŭ for�� ����
		Histogram h;               //�ӽ� ����ü
		if (i < histograms.size()) //�ӽ� ����ü�� ���������� �Է¹��� ��� ����ü ����
			h = histograms[i];
		else
			h = Histogram(histograms.size(), 0); //���� ������ x��ǥ�� �����ϱ����� �ӽñ���ü
	
		while (stk.size() > 1 && stk.top().height > h.height) { //2��° ��պ��� �ڽ��� ���� ��պ��� ���̰� ������� while�� ����  �� �� �� ������ ����� ������ ���̸� ���Ѵ�.
																//(0,0) ��ǥ���� while���� �ݺ��Ͽ� ���� ū ���̸� ���ϴ� ���

			Histogram lh = stk.top();                           //������ ���� ���κ��� ������ ���� �ӽñ���ü ���� (while�� ó�� ������ ����: ���� ����� ���� ���)
			stk.pop();                                          //������ ���� ���κ� ����

			Histogram bh = stk.top();                           //������ ���κ��� ������ ���� top������ ���� �ӽñ���ü

			long width = abs(h.leftX - bh.rightX);              //���� ��պ��� ���� ���� ��ձ����� �غ�����
			long height = lh.height;                            //���ϴ� ������ ��� �� ��� ����� ����
			long area = width * height;                         //���� ���� �� �ִ� ���� 
			 
			answer = max(answer, area);                          //�ռ� ���� answer�� area�� ������ �� �� ū���� answer�� �־��ش�.
		}
	
		stk.push(h);                                             //���� ����� ������ ���ÿ� ����
	}


	return answer;
}

void process(int caseindex) {
	int n;    // �Է¹��� ����� ����
	cin >> n;

	vector<Histogram> histograms; //��� ����ü�� ������ ����

	for (int i = 0; i < n; i++) { //����� ������ŭ ����ü�� ���� �� ���Ϳ� ����
		int height;
		cin >> height;
		histograms.push_back(Histogram(i, height)); // ��� ����ü�� ���Ϳ� ����
	}

	long answer = getLargestRectanglearea(histograms); //�ִ�簢�� ���� ���ϴ� �޼ҵ带 ���� �� ����
	cout << answer << endl;
}

int main() {
	int caseSize; //�Է¹��� �׽�Ʈ���̽��� ����
	cin >> caseSize;

	for (int i = 1; i <= caseSize; i++) { //�׽�Ʈ���̽��� ���� ŭ for�� ����
		process(i);
	}
}