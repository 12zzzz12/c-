#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

int main() {

	
	int p, n, h;

	cin >> p >> n >> h;

	process(p,n,h);
	

}

int process(int p,int n, int h) {

	int *x = new int[n];
	int *y = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}

	sort( x, y, n);
}

int sort(int *x, int *y , int n) {

	int a = x[0];
	int cnt = 1;

	for (int i = 0; i < n; i++) {
		if (a != x[i])
			cnt += 1;
	}

	for ( int i=0; i<cnt; i++){
	}


}