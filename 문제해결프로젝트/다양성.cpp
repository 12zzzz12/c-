#include<iostream>
using namespace std;

int getElementTypeCount(int data[], int n) {
	int countType = 0;
	
	for (int i = 0; i < n - 1; i++) {       // 앞선 오름차순 for문을 이용해 data를 오름차순으로 정렬해준다.
		for (int j = i + 1; j < n; j++) {  
			if (data[i] > data[j]) {		// 비교했을 때 앞 데이터가 더 크다면 뒤 데이터와 바꿔준다.
				int temp = data[j];
				data[j] = data[i];
				data[i] = temp;
			}
		}
	}

	for (int i = 0; i < n; i++) {			// 오름차순으로 정리한 배열을 앞에서부터 같은 값을 가졌는지 비교한다.
		if (data[i - 1] != data[i])		    // 값이 다르다면 종류가 다르므로 count를 1씩 더해준다.
			countType++;
	}
	return countType;
}
int main() {
	int n;
	cin >> n;
	int *data = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> data[i];
	}
	int answer = getElementTypeCount(data, n);
	
	cout << answer;

	delete[] data;
	return 0;
}