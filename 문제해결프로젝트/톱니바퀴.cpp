#include<iostream>
#include<string>


using namespace std;

class Cock {     //��� Ŭ���� 
public:
	int cock;    //��� ����

	bool getRight() { //����� ������ �κ� ���� �˾Ƴ��� �Լ�
		return cock & (1 << 2); // ��Ʈ ������ �̿��� 0b00000100 �� ��ġ�� �˾Ƴ��� ���
	}
	
	bool getLeft() { //����� ���� �κ� ���� �˾Ƴ��� �Լ�
		return cock & (1 << 6); // ��Ʈ ������ �̿��� 0b01000000 �� ��ġ�� �˾Ƴ��� ���
	}
	void rightturn() {
		bool temp = cock & 0x80;  // ���� ����Ʈ ������ �ϸ� ������� ���� �κ��� temp�� ����
		cock <<= 1; 					//cock�� �������� 1��ŭ ����Ʈ ����
		cock |= temp;                   //tmep�� cock�� or ������ ���� 1�� ��Ʈ�� �� ���� 
		cock &= 0xff;			    //���� ����Ʈ�������� ���� �� �ִ� ���� 1���� ���ֱ� ���� 0xff�� &�������ش�.
	}
	void leftturn() {			
		bool temp = cock & 0x01;         //������ ����Ʈ ������ �ϸ� ������� ������ �κ��� temp�� ����
		cock >>= 1;					 //cock�� ���������� 1��ŭ ����Ʈ ����
		cock |= (temp << 7);         //temp�� ����Ǿ� �ִ� ���ڸ� 7��ŭ ����Ʈ�ؼ� ��ġ�� �ٲٰ� cock�� or������ ���ش�.
	}
	bool score() {
		return cock & 1;             //12�� ������ ���� ���� �����ʿ� �ִ� ���̹Ƿ� & 1 ������ ���� ���� �˾Ƴ���.
	}

	void setbit(int n) {
		for (int i = 0; i < 8; i++) {  // �Է¹޴� cock�� ���¸� ��Ʈ���·� �����ϴ� for��
			cock <<= 1;                
			cock += n % 10;           
			n /= 10;
		}
	}
};


int main() {
	Cock *cocks = new Cock[4];
	int cock;//��ϻ���
	int n; // ȸ�� Ƚ��
	int number, direction; // ��Ϲ���, ����

	for (int i = 0; i < 4; i++) {	 //4�� ��� ���� �Է� 
		cin >> cock;
		cocks[i].setbit(cock); // ��� ���¸� setbit()�Լ��� �̿��� ����
	} 


	cin >> n; //ȸ�� Ƚ�� �Է�

	
	while (n--) {                      //ȸ�� Ƚ�� ��ŭ while���� �̿��� ������.

		cin >> number >> direction;    //ȸ�� ��ų ��Ͽ� ���� �Է�

		int whereturn[4] = { 0 };      //������ ��Ϲ��� ȸ�� ������ ���� �迭,, 0���� �ʱ�ȭ
		whereturn[number-1] = direction; // ó���� ȸ����ų ��Ϲ����� ��ȣ(�ε���)�� ���� ���� 

		//�� ��Ϲ����� ��� �������� ���ƾ� �ϴ��� Ȯ��
		//������ ��Ϲ����� ȸ�� ��Ŵ
		
		for (int i = number-1; i < 3; i++) {					 //������ ��Ͽ� ���������� ������ ��	
			if (cocks[i].getRight() ^ cocks[i + 1].getLeft())	 //�´�� �κ��� �ٸ��� 
				whereturn[i + 1] = -whereturn[i];	             //������ ����� ȸ�������� �ݴ�������� ����
			else		                                         // ó�� �´�� �κ��� ���ٸ� ������ ������ �κе� �������� �����Ƿ� for�� ����
				break;
		}
		for (int i = number-1; i > 0; i--) {                     //������ ��Ͽ� �������� ������ ��
			
			if (cocks[i].getLeft() ^ cocks[i - 1].getRight())    //�´�� �κ��� �ٸ��ٸ�
				whereturn[i - 1] = -whereturn[i];			     // ����� ȸ�������� �´�� ����� �ݴ�������� ����
			else                                                 // ó�� �´�� �κ��� ���ٸ� ������ ���� �κе� �������� �����Ƿ� for�� ����
				break;
		}
		for (int i = 0; i < 4; i++) {                            //��� ����� ȸ�� ������ Ȯ���ϰ� Ȯ�� ���⿡ ���� ȸ����Ų��.
			if (whereturn[i] == 1) {							 //1�� ����Ǿ� �ִٸ� �ð�������� ȸ��
				cocks[i].rightturn();
			}
			else if (whereturn[i] == -1){                       // -1�� ����Ǿ� �ִٸ� �ݽð�������� ȸ��
				cocks[i].leftturn();
			}
		}
	}

	int k = 1;
	int sum = 0;
	for (int i = 0; i < 4; i++) {								//������ ��Ϲ����� ù ��° ���� Ȯ���ϰ� 
		sum += cocks[i].score() * k;                            //������� 1, 2, 4, 8 �� ���Ͽ� sum�� ����
		k *= 2;
	}
	cout << sum;
		
	return 0;
}