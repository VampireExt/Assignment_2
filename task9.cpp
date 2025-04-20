#include<iostream>
#include<string>
using namespace std;

int palindrome(char ch[100]) {
	int length = 0;
	bool flag = false;
	for (int i = 0; ch[i] != '\0'; i++) {
		length++;
	}
	
	for (int j = length - 1,i=0; j >= 0; j--) {
			if (ch[i] == ch[j]) {
				flag = true;
				
			}
			else {
				flag = false;
				break;
			}
			i++;
		}
	
	return flag;

}
int main() {
	char ch[100];
	cout << "Enter a character array to check if its a palindrome or not:";
	cin.getline(ch, 100);
	cout << palindrome(ch);

	return 0;
}