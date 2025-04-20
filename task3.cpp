#include<iostream>
using namespace std;
int saim(char ch[100]) {
	int count = 0;
	for (int i = 0; ch[i] != '\0'; i++) {
		if (ch[i] == 'a' ||ch[i] == 'e' || ch[i] == 'i' || ch[i] == 'o' || ch[i] == 'u' || ch[i] == 'A' || ch[i] == 'E' || ch[i] == 'I' || ch[i] == 'O' || ch[i] == 'U') {
			count++;
		}
	}
	return count;
}

int main() {
	
	char ch[100];
	cout << "Enter a string to calculate the no of vowles:";
	cin.getline(ch, 100);
	
	cout << "Number of vowels are:";
	cout << saim(ch);
	cout << endl;

	system("pause");
	return 0;
}