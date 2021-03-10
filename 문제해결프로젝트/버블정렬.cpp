#include<iostream>
#include<math.h>
using namespace std;


void bubbleSort(int data[], int n) {

	for (int i = 0; i < n; i++) {
		int na = 0;					//2번 째 for문이 첫 사이클에 오름차순인지 확인
		for (int k = 0; k < n - 1 -i; k++) {
			if (data[k] > data[k + 1]) { //앞 데이터가 뒤보다 크면 자리를 바꿔준다.
				int temp = data[k];
				data[k] = data[k + 1];
				data[k + 1] = temp;
				na = 1;			// 큰게 더 앞에 있으면 na를 1로 바꿈
			}
		}
		if (na == 0)      //만약 2번째 for문에서 첫 사이클에 오름차순이라면 na=0이므로 for문 종료
			break;
	}
}

int main() {
	
	int n;					//입력받을 숫자의 개수
	cin >> n;

	int* data = new int[n];  // 입력받은 숫자를 넣을 배열

	for (int i = 0; i < n; i++) { //배열에 숫자를 집어넣어준다.
		cin >> data[i];
	}
	bubbleSort(data, n);   //배열을 버블정렬한다.

	for (int i = 0; i < n; i++) {
		cout << data[i] << " ";
	}
	delete[] data;
	return 0;
}