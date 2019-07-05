#include <iostream>

using namespace std;

int maxsum(int a, int b) {
	return a > b ? a : b;
}

int main() {
	ios::sync_with_stdio(false);

	int n, m;
	int tettriss[500][503] = { 0, };
	int checksum = 0;
	int finalsum = 0;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tettriss[i][j];
		}
	}
	//CASE IS 5

	//ㅡ
	for (int i = 0; i < n; i++) {
		//직사각형부터 시작 직사각형 세로	
		for (int j = 0; j < m-3; j++) {
			checksum = tettriss[i][j] + tettriss[i][j+1] + tettriss[i][j+2] + tettriss[i][j+3];
			finalsum = maxsum(checksum, finalsum);
		}
	}
	//ㅣ
	for (int i = 0; i < n-3; i++) {
		//직사각형부터 시작 직사각형 세로	
		for (int j = 0; j < m; j++) {
			checksum = tettriss[i][j] + tettriss[i+1][j] + tettriss[i+2][j] + tettriss[i+3][j];
			finalsum = maxsum(checksum, finalsum);
		}
	}

	//ㅁ
	for (int i = 0; i < n - 1; i++) {
		//직사각형부터 시작 정사각형
		for (int j = 0; j < m-1; j++) {
			checksum = tettriss[i][j] + tettriss[i + 1][j] + tettriss[i][j+1] + tettriss[i + 1][j+1];
			finalsum = maxsum(checksum, finalsum);
		}
	}

	//L
	for (int i = 0; i < n - 2; i++) {
		//직사각형부터 시작 정사각형
		for (int j = 0; j < m - 1; j++) {
			int temp = (tettriss[i][j] + tettriss[i + 1][j] + tettriss[i + 2][j] + tettriss[i + 2][j + 1]);
			int temp2 = (tettriss[i][j] + tettriss[i][j + 1] + tettriss[i + 1][j + 1] + tettriss[i + 2][j + 1]);
			checksum = (temp > temp2) ? temp : temp2;
			
			temp = (tettriss[i][j] + tettriss[i + 1][j] + tettriss[i + 2][j] + tettriss[i][j + 1]);
			checksum = maxsum(checksum, temp);
			temp2= (tettriss[i][j+1] + tettriss[i+1][j + 1] + tettriss[i + 2][j] + tettriss[i + 2][j + 1]);
			checksum = maxsum(checksum, temp2);
			
			finalsum = maxsum(checksum, finalsum);
		}
	}
	for (int i = 0; i < n - 1; i++) {
		//직사각형부터 시작 정사각형
		for (int j = 0; j < m - 2; j++) {
			int temp = (tettriss[i][j] + tettriss[i + 1][j] + tettriss[i +1][j+1] + tettriss[i + 1][j + 2]);
			int temp2 = (tettriss[i][j] + tettriss[i][j + 1] + tettriss[i][j + 2] + tettriss[i + 1][j]);
			checksum = (temp > temp2) ? temp : temp2;

			temp = (tettriss[i][j+2] + tettriss[i + 1][j] + tettriss[i + 1][j+1] + tettriss[i+1][j + 2]);
			checksum = maxsum(checksum, temp);
			temp2 = (tettriss[i][j] + tettriss[i][j + 1] + tettriss[i][j+2] + tettriss[i + 1][j + 2]);
			checksum = maxsum(checksum, temp2);

			finalsum = maxsum(checksum, finalsum);
		}
	}

	//ㄹ
	for (int i = 0; i < n - 2; i++) {
		//직사각형부터 시작 정사각형
		for (int j = 0; j < m - 1; j++) {
			int temp = (tettriss[i][j] + tettriss[i + 1][j] + tettriss[i+1][j+1] + tettriss[i + 2][j + 1]);
			int temp2 = (tettriss[i][j+1] + tettriss[i+1][j] + tettriss[i+1][j+1] + tettriss[i+2][j]);
			checksum = (temp > temp2) ? temp : temp2;
			finalsum = maxsum(checksum, finalsum);
		}
	}
	for (int i = 0; i < n - 1; i++) {
		//직사각형부터 시작 정사각형
		for (int j = 0; j < m - 2; j++) {
			int temp = (tettriss[i][j+1] + tettriss[i][j+2] + tettriss[i + 1][j] + tettriss[i + 1][j + 1]);
			int temp2 = (tettriss[i][j] + tettriss[i][j+1] + tettriss[i + 1][j + 1] + tettriss[i + 1][j+2]);
			checksum = (temp > temp2) ? temp : temp2;
			finalsum = maxsum(checksum, finalsum);
		}
	}

	//ㅗ
	for (int i = 0; i < n - 2; i++) {
		//직사각형부터 시작 정사각형
		for (int j = 0; j < m - 1; j++) {
			int temp = (tettriss[i][j] + tettriss[i + 1][j] + tettriss[i + 1][j+1] + tettriss[i + 2][j]);
			int temp2 = (tettriss[i][j+1] + tettriss[i+1][j] + tettriss[i + 1][j + 1] + tettriss[i + 2][j + 1]);
			checksum = (temp > temp2) ? temp : temp2;
			finalsum = maxsum(checksum, finalsum);
		}
	}
	for (int i = 0; i < n - 1; i++) {
		//직사각형부터 시작 정사각형
		for (int j = 0; j < m - 2; j++) {
			int temp = (tettriss[i][j] + tettriss[i][j + 1] + tettriss[i][j+2] + tettriss[i + 1][j + 1]);
			int temp2 = (tettriss[i][j+1] + tettriss[i+1][j] + tettriss[i + 1][j + 1] + tettriss[i + 1][j + 2]);
			checksum = (temp > temp2) ? temp : temp2;
			finalsum = maxsum(checksum, finalsum);
		}
	}

	cout << finalsum;
}