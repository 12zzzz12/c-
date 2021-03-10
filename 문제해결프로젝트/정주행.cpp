#include<iostream>
#include<math.h>
using namespace std;

bool isConsecutive(int data[], int n) {

	int max_data = data[0];  //배열 내 최댓값
	int min_data = data[0];  //배열 내 최솟값

	for (int i = 0; i < n; i++) {  // 배열 내 최대, 최소 값 설정하는 for문
		if (max_data < data[i])
			max_data = data[i];
		if (min_data > data[i])
			min_data = data[i];
	}
	if (max_data - min_data == n - 1) //배열 내 최대값 -최솟값이 n-1이라면 연속된 숫자들
		return true;
	else           // 그렇지 않다면 연속되지 않음
		return false;
}

int main() {
	int n;	//입력받을 숫자의 개수
	cin >> n;

	int* data = new int[n]; // 숫자들을 집어넣을 배열
	for (int i = 0; i < n; i++) {
		cin >> data[i];
	}
	bool result = isConsecutive(data, n); //숫자들이 연속되는지 확인

	if (result)
		cout << "YES";
	else
		cout << "NO";

	delete[] data;
	return 0;
}