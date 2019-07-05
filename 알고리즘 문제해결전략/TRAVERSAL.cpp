#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t, n, temp;

vector<int> slice(vector<int> v, int a, int b) {
	return vector<int>(v.begin() + a, v.begin() + b);
}

void printPostOrder(vector<int> preorder, vector<int> inorder) {
	
	int N = preorder.size();

	if (preorder.empty()) return;

	int root = preorder[0];

	int L = find(inorder.begin(), inorder.end(), root) - inorder.begin();

	int R = N -1 -L;

	printPostOrder(slice(preorder, 1, L + 1), slice(inorder, 0, L));
	printPostOrder(slice(preorder, L + 1, N), slice(inorder, L + 1, N));

	cout << root << ' ';
}

int main() {
	
	cin >> t;
	vector<int> arr1;
	vector<int> arr2;
	for (int i = 0; i < t; i++) {
		arr1.clear();
		arr2.clear();
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> temp;
			arr1.push_back(temp);
		}
		for (int j = 0; j < n; j++) {
			cin >> temp;
			arr2.push_back(temp);
		}
		printPostOrder(arr1, arr2);
		cout << '\n';
	}
}