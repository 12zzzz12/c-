#include<iostream>
#include<string>
#include<algorithm>
#include<time.h>
using namespace std;

const int MAX_LENGTH = 100000; //���ڿ� �ִ����

class MyString {
private:
	char *characters;         //���ڿ� �迭 
	int length;				  //���ڿ� ����

public:
	MyString(const char *str) {
		this->length = strnlen(str, MAX_LENGTH);      //����ü ���� ����
		this->characters = new char[this->length];    //����ü ���ڹ迭 ����
		for (int i = 0; i < this->length; i += 1)     //����ü ���ڹ迭�� �����Ͱ� �ֱ�
			this->characters[i] = str[i];
	}
	
	MyString(const string & original) {
		this->length = original.length();			   //����ü ���� ����
		this->characters = new char[this->length];     //����ü ���ڹ迭 ���� 
		for (int i = 0; i < this->length; i += 1)	   //����ü ���ڹ迭�� �����Ͱ� �ֱ�
			this->characters[i] = original[i];
	}

	~MyString() {
		delete[] characters;							//����ü �迭 ����
	}

	bool operator < (const MyString & o) const {	     // ù ��° ���ڿ��� �ռ����� Ȯ��
		int n = min(this->length, o.length);			 //algorithm ����� min�Լ��� �̿��� ���� ���̸� n���� ����
		for (int i = 0; i < n; i++) {					 //���� �ϳ��ϳ��� ���ϸ� �������� ��
			if (this->characters[i] < o.characters[i])	 //���� �� ������ true 
				return true;
			else if (this->characters[i] > o.characters[i])
				return false;
		}
		if (this->length < o.length)					//���� ���ڰ� �� �Ȱ��ٸ� ���̷� �������� ���Ѵ�.
			return true;
		else
			return false;
	}

	bool operator > (const MyString & o) const {		 // �� ��° ���ڿ��� �ռ����� Ȯ��
		int n = min(this->length, o.length);			 //algorithm ����� min�Լ��� �̿��� ���� ���̸� n���� ����
		for (int i = 0; i < n; i++) {					 //���� �ϳ��ϳ��� ���ϸ� �������� ��
			if (this->characters[i] > o.characters[i])	 //�ڰ� �� ������ true
				return true;
			else if (this->characters[i] < o.characters[i])
				return false;
		}
		if (this->length > o.length)                     //���� ���ڰ� �� �Ȱ��ٸ� ���̷� �������� ���Ѵ�.
			return true;
		else
			return false;
	}

	bool operator == (const MyString & o) const {		 // ���ڿ��� ������ Ȯ��		
		if (this->length != o.length)					 //���̰� �ٸ��ٸ� false�� ����
			return false;

		for (int i = 0; i < this->length; i++) {		 //���ڸ� �ϳ��ϳ� ���ϸ� �ٸ��ٸ� false ���� 
			if (this->characters[i] != o.characters[i])
				return false;
		}
		return true;
	}
			
};

int main() {

	clock_t start = clock();
	string s1;					// �� ���ڿ�
	string s2;					// �� ���ڿ�
	cin >> s1 >> s2;

	MyString mys1(s1);	
	MyString mys2(s2);

	if (mys1 < mys2) 
		cout << -1;
	else if (mys1 > mys2)
		cout << 1;
	else 
		cout << 0;
	clock_t end = clock();

	cout << "time : " << (double)(end - start);
	return 0;
}

