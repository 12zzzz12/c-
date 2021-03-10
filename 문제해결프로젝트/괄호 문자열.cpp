#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;


class Parenthesis {
public:
	bool type; // (인지 )인지 확인하는 변수
	int index; // 문자열의 순자를 확인할 인덱스

	Parenthesis(int index, bool type) { //구조체 생성시 index, type 설정
		this->index = index;
		this->type = type;
	}

	Parenthesis(int index, char c) { //구조체 생성시 문자열의 위치와 문자열의 타입확인
		this->index = index;
		if (c == '(')  //넘겨받은 문자가 '('이면 type을 true로 설정
			this->type = true;
		else //'('가 아닌 ')'라면 false로 설정
			this->type = false;
	}
};

bool isVaildParentheses(const vector<Parenthesis>& parentheses) { //문자열의 각 위치와 타입을 확인할 수 있는 구조체 벡터를 넘겨받는다
	stack<Parenthesis> st;   //'('라면 push ')'라면 pop을 하기위한 stack 

	for (int i = 0; i < parentheses.size(); i++) { //넘겨받은 벡터 즉, 문자열의 길이만큼 for문을 수행한다.
		Parenthesis p = parentheses[i];            //순서대로 구조체를 생성

		if (p.type == true)         //'(' 라면 st에 생성한 구조체를 집어넣는다.
			st.push(p);
		else if (p.type == false) { // '('가 아닌경우
			if (st.size() > 0)      // stack안에 내용물이 있으면 pop으로 삭제한다.
				st.pop();
			else                    // stack의 크기가 0이라면 '('가 없는 상태로 짝이 안맞기 떄문에 false를 반환
				return false;
		}
	}

	if (st.size() > 0)     // 위의 for문을 수행한뒤 stack에 내용물이 남아있다면 짝이 맞지 않았다는 뜻이므로 false를 반환
		return false;
	
	return true; //위를 다 실행했을 때 아무런 문제가 없다면 짝이 맞는 것이므로 true를 반환
}

void process() {
	string str; //()() 를 저장할 string
	cin >> str;

	vector<Parenthesis> parentheses; //입력받은 문자열을 확인할 벡터구조체

	for (int i = 0; i < str.length(); i++) { //입력받은 문자열의 문자들을 확인하는 반복문
		parentheses.push_back(Parenthesis(i, str[i])); //입력받은 문자가 '(',')'인지 확인하여 타입을 정하고 벡터에 넣어준다
	}

	bool isValid = isVaildParentheses(parentheses); //'(',')'가 올바르게 있는지 확인하는 메소드

	if (isValid) //true라면 짝이 맞게 입력이 된 것이므로 yes출력
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}

int main() {

	int caseSize;    //테스트받을 횟수
	cin >> caseSize;

	for (int i = 0; i < caseSize; i++) { //테스트 받을 횟수만큼 process메소드를 반복
		process();
	}
	return 0;
}