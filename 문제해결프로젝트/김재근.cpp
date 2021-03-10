#include<iostream>
#include<string>
#include<time.h>

using namespace std;

string *sort(string data[], int n) {		//�Է¹��� ����, ����, ���� ���� ������� �����ϴ� �Լ� (�迭1, �����)
	
	for (int i = 0; i < n - 1; i++) {       //������������ �ٲ��ִ� for��
		for (int j = i + 1; j < n; j++) {
			if (data[i] > data[j]) {		// ������ �� �� �����Ͱ� �� ũ�ٸ� �� �����Ϳ� �ٲ��ش�.
				string temp = data[j];
				data[j] = data[i];
				data[i] = temp;
			}
		}
	}

	return data;
}

int getCount(string data[], int n) {		// ����,����,�� �� ����� �ԷµǾ����� Ȯ���ϴ� �Լ�
	
	int countType = 0;

	sort(data, n);						    // sort �Լ��� �̿��� �迭1�� ������������  ����

	for (int i = 0; i < n; i++) {			// ������ �迭�� ��,�ڷ� ������ ���Ѵ�.
		if (data[i - 1] != data[i])		    // ���� �ٸ��ٸ� ������ �ٸ��Ƿ� count�� 1�� �����ش�.
			countType++;
	}

	return countType;						// ��� ������ ���Դ��� ���� ex.1, 2, 3 
}

string *getType(string data[], int n) {     // ���ºΰ� �ƴ� �� 2������ ���� �˾Ƴ��� �Լ� (�迭1, �����)  
	
	string *twoType = new string[2];	        //return �� ������ �� �迭 
	

	twoType[0] = data[0];						//�̹� ���ĵ� �迭1�� �����Ƿ� ù ��° ���� twoType[0]�� �־��ش�.

	for (int i = 0; i < n; i++) {			
		if (data[i - 1] != data[i])       		// �յڷ� ���� �ٸ� �κп��� �� ��° ���� twoType[1]�� �־��ص� data2 ����  
			twoType[1] = data[i];
	}
	return twoType;
}



int main() {
	
	int n;														   // ����� ��
	cin >> n;			

	if (n > 5 || n < 2) {										   // ������� 2~5���� �ƴϸ� ���α׷� ����
		cout << "2~5 ������ ���ڸ� �Է��ϼ���";
		return 0;
	}
	
	string *ropasi1 = new string[n];									   //�� ����� ���������� �� ���� string �迭1
	string *ropasi2 = new string[n];								       //�迭1�� ���纻

	for (int i = 0; i < n; i++) {								   //�迭1�� ����,����,�� �Է�
		cin >> ropasi1[i];
		if (ropasi1[i] != "����" && ropasi1[i] != "����" && ropasi1[i] != "��") { //����� �Էµ��� ������ ����
			cout << "����,����,���� �Է��ϼ���.";
			return 0;
		}
		ropasi2[i] = ropasi1[i];											   //�迭2�� ��������
	}

	clock_t start = clock();

	int count = getCount(ropasi1, n);								   // ����,����,�� �� ����� �ִ��� Ȯ��
	if (count == 3 || count ==1) {								   // 3���� ��� ���� ��� or 1������ ���� ��� draw
		cout << "draw"; 
	}
	else {
		string r1 = getType(ropasi1, n)[0];							   //2���� ������ �� ex.(����,����) �̸� ���� ���� 
		string r2 = getType(ropasi1, n)[1];							   //2���� ������ �� ex.(����, ��) �̸� �� ����

		for (int i = 0; i < n; i++) {							   //�����ص� �迭2�� �ε��� ã��
			if(r1 == "����" && r2 == "����")					   // (����,����) ��� ������ �ε��� ã�� ���
				if (ropasi2[i] == "����")
					cout << i << " ";
			if (r1 == "����" && r2 == "��")				           // (����,��) ��� ������ �ε��� ã�� ��� 
				if (ropasi2[i] == "����")
					cout << i << " ";
			if (r1 == "����" && r2 == "��")						   // (����,��) ��� ������ �ε��� ã�� ���
				if (ropasi2[i] == "��")
					cout << i << " ";
		}
	}
	clock_t end = clock();

	cout << "\ntime : " << (double)(end - start)/CLOCKS_PER_SEC ;
	return 0;

}