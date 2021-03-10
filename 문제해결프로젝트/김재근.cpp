#include<iostream>
#include<string>
#include<time.h>

using namespace std;

string *sort(string data[], int n) {		//입력받은 가위, 바위, 보를 사전 순서대로 정렬하는 함수 (배열1, 사람수)
	
	for (int i = 0; i < n - 1; i++) {       //오름차순으로 바꿔주는 for문
		for (int j = i + 1; j < n; j++) {
			if (data[i] > data[j]) {		// 비교했을 때 앞 데이터가 더 크다면 뒤 데이터와 바꿔준다.
				string temp = data[j];
				data[j] = data[i];
				data[i] = temp;
			}
		}
	}

	return data;
}

int getCount(string data[], int n) {		// 가위,바위,보 중 몇가지가 입력되었는지 확인하는 함수
	
	int countType = 0;

	sort(data, n);						    // sort 함수를 이용해 배열1을 오름차순으로  정렬

	for (int i = 0; i < n; i++) {			// 정렬한 배열을 앞,뒤로 같은지 비교한다.
		if (data[i - 1] != data[i])		    // 값이 다르다면 종류가 다르므로 count를 1씩 더해준다.
			countType++;
	}

	return countType;						// 몇가지 종류가 나왔는지 리턴 ex.1, 2, 3 
}

string *getType(string data[], int n) {     // 무승부가 아닐 때 2가지의 종류 알아내는 함수 (배열1, 사람수)  
	
	string *twoType = new string[2];	        //return 할 데이터 값 배열 
	

	twoType[0] = data[0];						//이미 정렬된 배열1을 받으므로 첫 번째 값을 twoType[0]에 넣어준다.

	for (int i = 0; i < n; i++) {			
		if (data[i - 1] != data[i])       		// 앞뒤로 값이 다른 부분에서 두 번째 값을 twoType[1]에 넣어준뒤 data2 리턴  
			twoType[1] = data[i];
	}
	return twoType;
}



int main() {
	
	int n;														   // 사람의 수
	cin >> n;			

	if (n > 5 || n < 2) {										   // 사람수가 2~5명이 아니면 프로그램 종료
		cout << "2~5 사이의 숫자를 입력하세요";
		return 0;
	}
	
	string *ropasi1 = new string[n];									   //각 사람의 가위바위보 를 넣을 string 배열1
	string *ropasi2 = new string[n];								       //배열1의 복사본

	for (int i = 0; i < n; i++) {								   //배열1에 가위,바위,보 입력
		cin >> ropasi1[i];
		if (ropasi1[i] != "가위" && ropasi1[i] != "바위" && ropasi1[i] != "보") { //제대로 입력되지 않으면 종료
			cout << "가위,바위,보만 입력하세요.";
			return 0;
		}
		ropasi2[i] = ropasi1[i];											   //배열2에 복사저장
	}

	clock_t start = clock();

	int count = getCount(ropasi1, n);								   // 가위,바위,보 중 몇가지가 있는지 확인
	if (count == 3 || count ==1) {								   // 3가지 모두 나온 경우 or 1가지만 나온 경우 draw
		cout << "draw"; 
	}
	else {
		string r1 = getType(ropasi1, n)[0];							   //2가지 종류중 앞 ex.(가위,바위) 이면 가위 저장 
		string r2 = getType(ropasi1, n)[1];							   //2가지 종류중 뒤 ex.(가위, 보) 이면 보 저장

		for (int i = 0; i < n; i++) {							   //복사해둔 배열2로 인덱스 찾기
			if(r1 == "가위" && r2 == "바위")					   // (가위,바위) 라면 바위의 인덱스 찾아 출력
				if (ropasi2[i] == "바위")
					cout << i << " ";
			if (r1 == "가위" && r2 == "보")				           // (가위,보) 라면 바위의 인덱스 찾아 출력 
				if (ropasi2[i] == "가위")
					cout << i << " ";
			if (r1 == "바위" && r2 == "보")						   // (바위,보) 라면 바위의 인덱스 찾아 출력
				if (ropasi2[i] == "보")
					cout << i << " ";
		}
	}
	clock_t end = clock();

	cout << "\ntime : " << (double)(end - start)/CLOCKS_PER_SEC ;
	return 0;

}