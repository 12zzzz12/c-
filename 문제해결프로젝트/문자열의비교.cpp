#include<iostream>
#include<string>
#include<algorithm>
#include<time.h>
using namespace std;

const int MAX_LENGTH = 100000; //문자열 최대길이

class MyString {
private:
	char *characters;         //문자열 배열 
	int length;				  //문자열 길이

public:
	MyString(const char *str) {
		this->length = strnlen(str, MAX_LENGTH);      //구조체 길이 저장
		this->characters = new char[this->length];    //구조체 문자배열 생성
		for (int i = 0; i < this->length; i += 1)     //구조체 문자배열에 데이터값 넣기
			this->characters[i] = str[i];
	}
	
	MyString(const string & original) {
		this->length = original.length();			   //구조체 길이 설정
		this->characters = new char[this->length];     //구조체 문자배열 생성 
		for (int i = 0; i < this->length; i += 1)	   //구조체 문자배열에 데이터값 넣기
			this->characters[i] = original[i];
	}

	~MyString() {
		delete[] characters;							//구조체 배열 삭제
	}

	bool operator < (const MyString & o) const {	     // 첫 번째 문자열이 앞서는지 확인
		int n = min(this->length, o.length);			 //algorithm 헤더로 min함수를 이용해 작은 길이를 n으로 저장
		for (int i = 0; i < n; i++) {					 //문자 하나하나를 비교하며 사전순을 비교
			if (this->characters[i] < o.characters[i])	 //앞이 더 빠르면 true 
				return true;
			else if (this->characters[i] > o.characters[i])
				return false;
		}
		if (this->length < o.length)					//만약 문자가 다 똑같다면 길이로 사전순을 구한다.
			return true;
		else
			return false;
	}

	bool operator > (const MyString & o) const {		 // 두 번째 문자열이 앞서는지 확인
		int n = min(this->length, o.length);			 //algorithm 헤더로 min함수를 이용해 작은 길이를 n으로 저장
		for (int i = 0; i < n; i++) {					 //문자 하나하나를 비교하며 사전순을 비교
			if (this->characters[i] > o.characters[i])	 //뒤가 더 빠르면 true
				return true;
			else if (this->characters[i] < o.characters[i])
				return false;
		}
		if (this->length > o.length)                     //만약 문자가 다 똑같다면 길이로 사전순을 구한다.
			return true;
		else
			return false;
	}

	bool operator == (const MyString & o) const {		 // 문자열이 같은지 확인		
		if (this->length != o.length)					 //길이가 다르다면 false를 리턴
			return false;

		for (int i = 0; i < this->length; i++) {		 //문자를 하나하나 비교하며 다르다면 false 리턴 
			if (this->characters[i] != o.characters[i])
				return false;
		}
		return true;
	}
			
};

int main() {

	clock_t start = clock();
	string s1;					// 앞 문자열
	string s2;					// 뒤 문자열
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

