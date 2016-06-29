#include <iostream>
using namespace std;

int ans[100];
void printall(int arr[], int i, int j, int len, int n) {

	if(j == len) {

		if(j == 0) cout << "Empty set";
		else for(int k = 0; k < len; k++) cout << ans[k] << " ";
		cout << endl;
		return;
	}

	if(i == n) return;

	ans[j] = arr[i];
	printall(arr, i+1, j+1, len, n);
	printall(arr, i+1, j, len, n);
}

void solve(int arr[], int n) {

	for(int len = 0; len <= n; len++) printall(arr, 0, 0, len, n);
}

int main() {

	int arr[] = {1, 2, 3, 4};
	int n = sizeof(arr)/sizeof(arr[0]);
	solve(arr, n);
	return 0;
}