#include<iostream>


using namespace std;

const int MAX_ROW = 9; //���� �ִ� ����
const int MAX_COL = 9; //���� �ִ� ����

class SudokuBoard { //���� Ŭ����
public:
	int getRowByIndex(int index) { //�Էµ� ���� ���� �˾Ƴ��� �Լ�
		return (index - 1) / 9 + 1; //9������ ���� ���� �ٲ�Ƿ� ���� �������ش�. 
	}
	int getColByIndex(int index) { //�Էµ� ���� ���� �˾Ƴ��� �Լ�
		return (index - 1) % 9 + 1;//9������ ���� ���� �ٲ�Ƿ� ���� ����
	}
	int getGroupByIndex(int index) {//�Էµ� ���� �׷��� �˾Ƴ��� �Լ�
		int r = getRowByIndex(index); //���� ���� r�� ����
		int w = getColByIndex(index); //���� ���� w�� ����
		return getGroupByPosition(r, w); //groupbyposition �Լ��� ���� �׷찪�� ����
	}
	int getGroupByPosition(int row, int column) { //��� �׷����� �˾Ƴ��� �Լ�
		int left = ((row - 1) / 3) * 3 + 1; //�׷��� ���� ���������� 3�� ����
		int offset = ((column - 1) / 3); //�׷��� ���� ���������� ������ 1������
		return left + offset; //�� ���� ���� ���ϸ� �׷찪�� ���´�.
	}
};
void process(int caseIndex) { //index�� �Է��ϸ� ��,��,�׷��� ����ϴ� �޼ҵ�
	int index;
	cin >> index; //������ �� �Է�

	SudokuBoard board = SudokuBoard(); //boardŬ���� ��ü ����
	int row = board.getRowByIndex(index); //���� �� ����
	int col = board.getColByIndex(index); //���� �� ����
	int group = board.getGroupByIndex(index); //�׷� �� ����

	cout << "Case #" << caseIndex << ":\n";
	cout << row << col << group << "\n";
}
int main() {
	int caseSize;
	cin >> caseSize; //�Է¹��� ������ ���� �Է�

	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex++) //casesize ��ŭ process �ݺ�
		process(caseIndex);
	return 0;
}