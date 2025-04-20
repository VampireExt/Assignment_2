#include<iostream>
#include<fstream>

using namespace std;

int saim(ifstream& file) {
	string word;
	int count = 0;

	while (file >> word) {
		count++;
	}
	return count;
}

int main() {

	ifstream input("output.txt");
	cout << "The number of words in the file are:";
	cout << saim(input);
	
	system("pause");
	return 0;
}