#include <iostream>

using namespace std;

int arr2[100000];
int count2=0;
void Eratos(int n)
{
	int count = 0;
	/*  ���� n�� 1���� �۰ų� ������ �Լ� ���� */
	if (n <= 1) return;

	/*	2���� n���� n-1���� ������ �� �ִ� �迭 �Ҵ�
		�迭 ���� ��ȣ�� �Ҽ��� ��ġ�ϵ��� �迭�� ũ���
		n+1 ���̸�ŭ �Ҵ�(�ε��� ��ȣ 0�� 1�� ������� ����)	*/
	bool* PrimeArray = new bool[n + 1];

	/*  �迭�ʱ�ȭ: ó���� ��� �Ҽ��� ���� true���� ��	*/
	for (int i = 2; i <= n; i++)
		PrimeArray[i] = true;

	/*	�����佺�׳׽��� ü�� �°� �Ҽ��� ����
		����, PrimeArray[i]�� true�̸� i ������ i ����� ����� i��
		������ �ִ� ���� �ǹǷ� i ������ i ����� ���� false���� �ش�.
		PrimeArray[i]�� false�̸� i�� �̹� �Ҽ��� �ƴϹǷ� i�� ��� ����
		�Ҽ��� �ƴϰ� �ȴ�. �׷��Ƿ� �˻��� �ʿ䵵 ����.	*/
	for (int i = 2; i * i <= n; i++)
	{
		if (PrimeArray[i])
			for (int j = i * i; j <= n; j += i)
				PrimeArray[j] = false;
	}

	for (int i = 3; i <= n; i++)
	{
		if (PrimeArray[i] == true) {
			arr2[count++] = i;
		}
	}

	count2 = count;
}

int main() {
	ios::sync_with_stdio(false);
	int n;

	cin >> n;
	Eratos(1000000);

	while (n) {
		//Eratos(n);
		bool check = true;
		if (n < count2) {
			count2 = n;
		}
		for (int i = 0; i < count2; i++) {
			for (int j = count2; j >= i; j--) {
				if (arr2[i] + arr2[j] == n) {
					cout << n << " = " << arr2[i] << " + " << arr2[j] << endl;
					check = false;
					break;
				}
			}
			if (check == false) break;
		}
		if (check == true) {
			cout << "Goldbach's conjecture is wrong." << endl;
		}
		count2 = 0;
		cin >> n;
	}
}