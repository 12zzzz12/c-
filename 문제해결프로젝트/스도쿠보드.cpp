#include<iostream>


using namespace std;

const int MAX_ROW = 9; //행의 최댓값 설정
const int MAX_COL = 9; //열의 최댓값 설정

class SudokuBoard { //보드 클래스
public:
	int getRowByIndex(int index) { //입력된 값의 행을 알아내는 함수
		return (index - 1) / 9 + 1; //9단위로 행의 값이 바뀌므로 식을 설정해준다. 
	}
	int getColByIndex(int index) { //입력된 값의 열을 알아내는 함수
		return (index - 1) % 9 + 1;//9단위로 열의 값이 바뀌므로 식을 설정
	}
	int getGroupByIndex(int index) {//입력된 값의 그룹을 알아내는 함수
		int r = getRowByIndex(index); //행의 값을 r에 저장
		int w = getColByIndex(index); //열의 값을 w에 저장
		return getGroupByPosition(r, w); //groupbyposition 함수를 통해 그룹값을 리턴
	}
	int getGroupByPosition(int row, int column) { //어느 그룹인지 알아내는 함수
		int left = ((row - 1) / 3) * 3 + 1; //그룹의 값은 내려갈수록 3씩 증가
		int offset = ((column - 1) / 3); //그룹의 값은 오른쪽으로 갈수록 1씩증가
		return left + offset; //두 개의 값을 더하면 그룹값이 나온다.
	}
};
void process(int caseIndex) { //index를 입력하면 행,열,그룹을 출력하는 메소드
	int index;
	cin >> index; //선택한 값 입력

	SudokuBoard board = SudokuBoard(); //board클래스 객체 생성
	int row = board.getRowByIndex(index); //행의 값 저장
	int col = board.getColByIndex(index); //열의 값 저장
	int group = board.getGroupByIndex(index); //그룹 값 저장

	cout << "Case #" << caseIndex << ":\n";
	cout << row << col << group << "\n";
}
int main() {
	int caseSize;
	cin >> caseSize; //입력받을 숫자의 갯수 입력

	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex++) //casesize 만큼 process 반복
		process(caseIndex);
	return 0;
}