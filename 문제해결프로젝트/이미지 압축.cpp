#include<iostream>
#include<vector>
#include<stdlib.h>

using namespace std;

vector<int> code;             //��ȯ �ڵ带 ������ ����

class Number {      //���� Ŭ����
public:
	int num;      // �� ������ ����
	int level;    // �� ������ ����

	Number(int num) {
		this->num = num;
		//�� ������ ũ�⿡ ���� �ӽ� ���� �ο�
		if (num < 44)
			this->level = 1;
		else if (num < 129)
			this->level = 86;
		else if (num < 214)
			this->level = 172;
		else
			this->level = 256;
	}
};

void pushcode(int level) {  //������ ���� ��ȯ�ڵ� ��(2-bit) �����ϴ� �޼ҵ�

	if (level == 1) {   //�ڵ忡 00 �߰�
		code.push_back(0); code.push_back(0);
	}
	else if (level == 86) { //�ڵ忡 01�߰�
		code.push_back(0); code.push_back(1);
	}
	else if (level == 172) { // �ڵ忡 10�߰�
		code.push_back(1); code.push_back(0);
	}
	else { //�ڵ忡 11�߰�
		code.push_back(1); code.push_back(1);
	}

}

void compression(vector<int> an, int N, int W) {
	
	vector<Number> number;        //�� ������ ��ü���� ������ ����
	
	for (int i = 0; i < N; i++) {
		number.push_back(Number(an[i])); //�� ������ ��ü�� �����ϰ� number���Ϳ� ����
	}

	int len = 2; // �ڵ���� 
	int sum = 0; // ��ȯ���
	
	pushcode(number[0].level); //��ȯ�ڵ忡 ù��° ������ ����(2-bit)�� �Է��Ѵ�.

	for (int i = 0; i < N-1; i++) {                    //�� ������ ������ ���� �� ���ӵ� ���� �� �ݺ���

		//ù��° ���ڰ� �� ��° ���ں��� ū ���
		if (number[i].num > number[i + 1].num) { //
			if (abs(abs(number[i].num - number[i + 1].level) - abs(number[i].num - number[i].level)) < W * 2)
				number[i].level = number[i + 1].level;
		}

		else{
			if (number[i].level != number[i + 1].level) {  //���ӵ� ������ ������ �ٸ� ��� 
				//�� ������ ���� �������� (�ڵ���� * ����ġ)�� ��Һ񱳸� ���� ���� ���ҷ����� �����Ѵ�.  
				if(abs(number[i + 1].num - number[i].level) < abs(number[i + 1].num - number[i + 1].level) + 2 * W)
					number[i + 1].level = number[i].level;
			}
		}
		//���� ������ ���� ������ �� �� ������ �ٸ� ���� ���� ��� ����
		if (number[i].level != number[i + 1].level) { //������ �ٸ� ���
			len += 3;								  //�ڵ���� 3 ���� , ��ȯ�ڵ忡 1+(2-bit)�� �߰��ǹǷ�
			code.push_back(1);						  //�ڵ忡 1 �߰�     
			pushcode(number[i + 1].level);			  //�ڵ忡 ������ŭ �߰�
		}
		else{                                        //������ ���� ���
			len += 1;							     //�ڵ���� 1 ����  , ��ȯ�ڵ忡 0�� �߰��ǹǷ�
			code.push_back(0);						 //�ڵ忡 0 �߰�
		}
		//�� ������ ������ ��ȯ��뿡 ����
		sum += abs(number[i].num - number[i].level);
	}

	sum += abs(number[N - 1].num - number[N - 1].level) + len * W; //��ȯ ��뿡 ������ ��� ���� (�ڵ����*����ġ)�� ���Ѵ�.
	
	cout << sum << endl; //�ּ� ��ȯ ��� ���

	for (int i = 0; i < code.size(); i++) // ��ȯ �ڵ� ���
		cout << code[i];
}

int main() {

	int N, W;          //���� ����, ����ġ
	cin >> N >> W;                //���� ����, ����ġ �Է�

	vector<int> an;               //�Է¹��� ������ ���� ����
	for (int i = 0; i < N; i++) { //���� �Է�
		int test;
		cin >> test;
		an.push_back(test);
	}
	compression(an, N ,W);

	return 0;

}