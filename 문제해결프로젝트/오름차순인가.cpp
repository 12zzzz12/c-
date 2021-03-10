#include<iostream>
using namespace std;

bool isOrdered(int data[], int n) {

	for (int i = 0; i < n-1; i++) {       // 0 ~ n-2 번(index) 까지의 for문
		for (int j = i + 1; j < n; j++) { // 1 ~ n-1 번(index) 까지의 for문을 이용해 
			if (data[i] > data[j])		  // (0,1),(0,2)...(0,n-1) 같은 방법으로 앞에 있는 수를 뒤에 있는 수와 비교하는 작업을 한다. 
				return false;			  // 앞에 있는게 더 크다면 false를 리턴하며 종료한다.
		}
	}
	return true;						  // false에서 종료되지 않았다면 오름차순이 맞으므로 true를 리턴한다.
}

int main() {
	int n;
	
	cin >> n;
	int *data = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> data[i];
	}
	bool result = isOrdered(data, n);

	if (result) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	
	delete[] data;
	return 0;
}