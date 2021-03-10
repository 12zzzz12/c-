#include<iostream>
#include<vector>
#include<stack>
using namespace std;


class Tower {
public:
	int index;           //tower�� �ε���
	int height;		     //tower�� ����
	int targetTowerindex;//tower�� ��ȣ�� ������ tower�� �ε���

	Tower(int index, int height) { //tower������ 
		this->index = index;
		this->height = height;
		this->targetTowerindex = 0; //�ʱ� ���� 0
	}
	void setTargettowerindex(int targetTowerindex) { //��ȣ�� ���� Ÿ���� �ִٸ�
		this->targetTowerindex = targetTowerindex;   //��ȣ ���� Ÿ���� �ε��� ����
	}
	int getTargetTowerindex() {  // ��ȣ�� ������ Ÿ���� �ε��� Ȯ���ϴ� �޼ҵ�
		return this->targetTowerindex;
	}
};

void findtargettowers(vector<Tower>& towers) {
	stack<Tower> stk;

	for (int i = 0; i < towers.size(); i++) { //Ÿ���� ������ŭ for�� ����
		Tower& t = towers[i];    //����ü�� ������ ������� Ÿ���� ������ �����´�.
		int targetTowerindex = 0;


		while (stk.empty() == false && stk.top().height < t.height) { //������ ������� �ʰ� ���� �ֱٿ� ���� Ÿ���� ���̰�
			stk.pop();											      // ���� Ÿ������ ���̰� ���� ��� ���� �ֱ��� Ÿ�������� �����Ѵ�.
		}															  //�ռ� Ÿ���� ���� Ÿ������ ���� Ÿ���� �ִ��� Ȯ���ϴ� �۾�

		if (stk.size() > 0) { // ���ÿ� ���빰�� �ִٴ� �� ���� Ÿ���� �ڽź��� ���� Ÿ���� �ִٴ� ���̹Ƿ�
			targetTowerindex = stk.top().index;  //�ڽź��� ���� Ÿ���� �ε����� Ÿ���ε����� ����
		}

		t.setTargettowerindex(targetTowerindex);  //���� �ڽź��� ���� Ÿ���� ���ٸ� Ÿ���ε����� 0���� �����Ѵ�.
	
		stk.push(t); // ���ÿ� �ڽ��� ������ �����Ѵ�. 
	}

}
int main() {
	int n;    //�Է¹��� Ÿ���� ����
	cin >> n; 

	vector<Tower> towers; //Ÿ������ ������ ���� ����ü�� ���� ����

	for (int i = 0; i < n; i++) { 
		int hi;
		cin >> hi; //Ÿ������ ���̸� �Է� 
		towers.push_back(Tower(i + 1, hi)); //Ÿ���� �ε����� ���̸� ������ ����ü�� ���Ϳ� ����
	}

	findtargettowers(towers); //�� Ÿ������ ��� Ÿ������ ��ȣ�� �������� Ȯ��

	for (int i = 0; i < n; i++) {
		if (i > 0)
			cout << " ";
		Tower t = towers[i];
		int targetindex = t.getTargetTowerindex(); 
		cout << targetindex; //�� Ÿ���� ��ȣ�� ������ Ÿ���� ��ġ�� ���
	}

	return 0;
}