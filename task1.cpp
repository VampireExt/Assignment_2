#include<iostream>
using namespace std;
void printingArray(int arr[5]) {

	for (int i = 0; i < 5; i++) {
		cout << arr[i] << " ";
	}
	cout << "Array printed successfully.\n";
	
}


int main() {
	int arr[5];
	cout << "Enter the elements of array:";
	for (int i = 0; i < 5; i++) {
		cin>> arr[i];
	}
	printingArray(arr);

	return 0;
}