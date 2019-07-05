#include <iostream>
#include <string>

using namespace std;

int main() {
	string first, answer="";
	
	for (int i = 0; i < 2; i++) {
		cin >> first;
		if (first == "black" && i == 1) answer += "0";
		else if (first == "brown") answer += "1";
		else if (first == "red") answer += "2";
		else if (first == "orange") answer += "3";
		else if (first == "yellow") answer += "4";
		else if (first == "green") answer += "5";
		else if (first == "blue") answer += "6";
		else if (first == "violet") answer += "7";
		else if (first == "grey") answer += "8";
		else if (first == "white") answer += "9";
	}
	cin >> first;
	if (answer != "0") {
		if (first == "brown") answer += "0";
		else if (first == "red") answer += "00";
		else if (first == "orange") answer += "000";
		else if (first == "yellow") answer += "0000";
		else if (first == "green") answer += "00000";
		else if (first == "blue") answer += "000000";
		else if (first == "violet") answer += "0000000";
		else if (first == "grey") answer += "00000000";
		else if (first == "white") answer += "000000000";
	}
	cout << answer;
}