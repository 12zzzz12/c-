#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;


class Parenthesis {
public:
	bool type; // (���� )���� Ȯ���ϴ� ����
	int index; // ���ڿ��� ���ڸ� Ȯ���� �ε���

	Parenthesis(int index, bool type) { //����ü ������ index, type ����
		this->index = index;
		this->type = type;
	}

	Parenthesis(int index, char c) { //����ü ������ ���ڿ��� ��ġ�� ���ڿ��� Ÿ��Ȯ��
		this->index = index;
		if (c == '(')  //�Ѱܹ��� ���ڰ� '('�̸� type�� true�� ����
			this->type = true;
		else //'('�� �ƴ� ')'��� false�� ����
			this->type = false;
	}
};

bool isVaildParentheses(const vector<Parenthesis>& parentheses) { //���ڿ��� �� ��ġ�� Ÿ���� Ȯ���� �� �ִ� ����ü ���͸� �Ѱܹ޴´�
	stack<Parenthesis> st;   //'('��� push ')'��� pop�� �ϱ����� stack 

	for (int i = 0; i < parentheses.size(); i++) { //�Ѱܹ��� ���� ��, ���ڿ��� ���̸�ŭ for���� �����Ѵ�.
		Parenthesis p = parentheses[i];            //������� ����ü�� ����

		if (p.type == true)         //'(' ��� st�� ������ ����ü�� ����ִ´�.
			st.push(p);
		else if (p.type == false) { // '('�� �ƴѰ��
			if (st.size() > 0)      // stack�ȿ� ���빰�� ������ pop���� �����Ѵ�.
				st.pop();
			else                    // stack�� ũ�Ⱑ 0�̶�� '('�� ���� ���·� ¦�� �ȸ±� ������ false�� ��ȯ
				return false;
		}
	}

	if (st.size() > 0)     // ���� for���� �����ѵ� stack�� ���빰�� �����ִٸ� ¦�� ���� �ʾҴٴ� ���̹Ƿ� false�� ��ȯ
		return false;
	
	return true; //���� �� �������� �� �ƹ��� ������ ���ٸ� ¦�� �´� ���̹Ƿ� true�� ��ȯ
}

void process() {
	string str; //()() �� ������ string
	cin >> str;

	vector<Parenthesis> parentheses; //�Է¹��� ���ڿ��� Ȯ���� ���ͱ���ü

	for (int i = 0; i < str.length(); i++) { //�Է¹��� ���ڿ��� ���ڵ��� Ȯ���ϴ� �ݺ���
		parentheses.push_back(Parenthesis(i, str[i])); //�Է¹��� ���ڰ� '(',')'���� Ȯ���Ͽ� Ÿ���� ���ϰ� ���Ϳ� �־��ش�
	}

	bool isValid = isVaildParentheses(parentheses); //'(',')'�� �ùٸ��� �ִ��� Ȯ���ϴ� �޼ҵ�

	if (isValid) //true��� ¦�� �°� �Է��� �� ���̹Ƿ� yes���
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}

int main() {

	int caseSize;    //�׽�Ʈ���� Ƚ��
	cin >> caseSize;

	for (int i = 0; i < caseSize; i++) { //�׽�Ʈ ���� Ƚ����ŭ process�޼ҵ带 �ݺ�
		process();
	}
	return 0;
}