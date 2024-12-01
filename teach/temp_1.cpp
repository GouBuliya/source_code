#include<bits/stdc++.h>
#define MaxNumber 5000001
using namespace std;
int n, k;
int prime[MaxNumber] = {1, 1};
int arr[25];
void Prime() {
	for (int i = 2; i * i <= MaxNumber; i++) {
		if (!prime[i]) {
			for (int j = i * i; j <= MaxNumber; j += i) {
				prime[j] = 1;
			}
		}
	}
}
int Count = 0;
void DFS(int ind, int sum, int last) {
	if (ind == k + 1) {
		if (!prime[sum])
			Count++;
	}
	for (int i = last + 1; i <= n; i++) {
		DFS(ind + 1, sum + arr[i], i);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	Prime();
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	DFS(1, 0, 0);
	cout << Count;
	return 0;
}