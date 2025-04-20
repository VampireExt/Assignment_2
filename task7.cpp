#include<iostream>
#include<string>
using namespace std;

void  saim(char ch[100]) {
	int length = 0;
	for (int i = 0; ch[i] != '\0'; i++) {
		length++;
	}
	cout << "The string in reversed form is:";
	for (int i = length - 1; i >= 0; i--) {
		cout << ch[i];
	}


}

int main() {
	char ch[100];
	cout << "Enter a string:";
	cin.getline(ch, 100);

	saim(ch);

	system("pause");
	return 0;
}