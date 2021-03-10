#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> getPossibleTargets(int n, int m, int *cards, int *targets) {
	vector<int> possibleTargets; //������ ��ҳ��� ����
	sort(cards, cards + n); //ī��迭�� ������������ ����

	for (int i = 0; i < m; ++i)//��÷��ȣ ���� ������� ���� for��
	{ 
		int k = targets[i]; //��÷��ȣ �� 
		bool possible = false;
		
		for (int j = 0; j < n; ++j)  //ī�� ù��° �� ������� ���� for��
		{ 
			int x = cards[j];
			for (int p = 0; p <= j; p += 1) // ī�� �ι�° �� ������� ���� for��
			{ 

				int y = cards[p];
				int z = k - (x + y); //ī�尪 �ΰ��� �̿��� ����° ���� z�� ����
			
				if (binary_search(cards, cards + n, z) == true) { //cards�迭�� z���� �ִٸ� ���� �� �ִ� ��÷��ȣ
					possible = true;							  //�̹Ƿ� possible�� true�� ��ȯ
					break;
				}
			}
			if (possible) //�ι�° for���� ����� ���� if��
				break;
		}
		if (possible)
			possibleTargets.push_back(k); //������ ��÷��ȣ ���� ���Ϳ� ����ִ´�.
	}
	sort(possibleTargets.begin(), possibleTargets.end()); //������ ���͸� ����
	return possibleTargets;
}

int main() {
	int n;  //ī���� ����
	int m;  //��÷��ȣ�� �ĺ� ����
	cin >> n >> m;
	
	int *cards = new int[n]; // ī�� ���� ���� �迭
	int *targets = new int[m]; //��÷��ȣ�� ���� �迭

	for (int i = 0; i < n; i++) { //ī�� �� �Է�
		cin >> cards[i];
	}
	for (int i = 0; i < m; i++) { //��÷��ȣ �Է�
		cin >> targets[i];
	}
	vector<int> answers = getPossibleTargets(n, m, cards, targets);//��÷��ȣ�� ���� �� �ִ� ī�尪 ���� ����

	if (answers.size() == 0) { //answer ���Ͱ� ����ִٸ� ���ٴ� ���� NO���
		cout << "NO";
	}
	else { //answer ������ ��ҵ� ���
		for (int i = 0; i < answers.size(); i++) {
			if (i > 0)
				cout << " ";
			cout << answers[i];
		}
	}
	//�迭 ����
	delete[] cards;
	delete[] targets;

	return 0;
}
