#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> getPossibleTargets(int n, int m, int *cards, int *targets) {
	vector<int> possibleTargets; //가능한 요소넣을 벡터
	sort(cards, cards + n); //카드배열을 오름차순으로 정렬

	for (int i = 0; i < m; ++i)//당첨번호 값을 순서대로 비교할 for문
	{ 
		int k = targets[i]; //당첨번호 값 
		bool possible = false;
		
		for (int j = 0; j < n; ++j)  //카드 첫번째 값 순서대로 넣을 for문
		{ 
			int x = cards[j];
			for (int p = 0; p <= j; p += 1) // 카드 두번째 값 순서대로 넣을 for문
			{ 

				int y = cards[p];
				int z = k - (x + y); //카드값 두개를 이용해 세번째 값을 z에 저장
			
				if (binary_search(cards, cards + n, z) == true) { //cards배열에 z값이 있다면 만들 수 있는 당첨번호
					possible = true;							  //이므로 possible을 true로 변환
					break;
				}
			}
			if (possible) //두번째 for문도 벗어나기 위한 if문
				break;
		}
		if (possible)
			possibleTargets.push_back(k); //가능한 당첨번호 값을 벡터에 집어넣는다.
	}
	sort(possibleTargets.begin(), possibleTargets.end()); //리턴할 벡터를 정렬
	return possibleTargets;
}

int main() {
	int n;  //카드의 개수
	int m;  //당첨번호의 후보 개수
	cin >> n >> m;
	
	int *cards = new int[n]; // 카드 값을 넣을 배열
	int *targets = new int[m]; //당첨번호를 넣을 배열

	for (int i = 0; i < n; i++) { //카드 값 입력
		cin >> cards[i];
	}
	for (int i = 0; i < m; i++) { //당첨번호 입력
		cin >> targets[i];
	}
	vector<int> answers = getPossibleTargets(n, m, cards, targets);//당첨번호를 만들 수 있는 카드값 저장 벡터

	if (answers.size() == 0) { //answer 벡터가 비어있다면 없다는 뜻의 NO출력
		cout << "NO";
	}
	else { //answer 벡터의 요소들 출력
		for (int i = 0; i < answers.size(); i++) {
			if (i > 0)
				cout << " ";
			cout << answers[i];
		}
	}
	//배열 삭제
	delete[] cards;
	delete[] targets;

	return 0;
}
