#include<bits/stdc++.h>
#define MaxNum 370
using namespace std;
vector<int> val(MaxNum);
int DayValue(int CoiledDays) {
	if (CoiledDays >= 365) {
		return val[365];
	} else if (CoiledDays >= 120) {
		return val[120];
	} else if (CoiledDays >= 30) {
		return val[30];
	} else if (CoiledDays >= 7) {
		return val[7];
	} else if (CoiledDays >= 3) {
		return val[3];
	} else if (CoiledDays >= 1) {
		return val[1];
	} else {
		return 0;
	}
}
int Answer = 0, N, CoiledDays = 0;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	cin >> val[1] >> val[3] >> val[7] >> val[30] >> val[120] >> val[365];
	for (int i = 1; i <= N; i++) {
		int x;
		cin >> x;
		if (x) {
			CoiledDays++;
		} else {
			CoiledDays = 0;
		}
		Answer += DayValue(CoiledDays);
	}
	cout << Answer;
	return 0;
}