#include<iostream>
using namespace std;

void copying(int arr[10], int arr2[10]) {

	for (int i = 0; i < 10; i++) {
		arr2[i] = arr[i];
	}
	cout << "The second array is :";
	for (int i = 0; i < 10; i++) {
		cout << arr2[i] << " ";
	}
}


int main() {

	int arr[10];
	int arr2[10];

	cout << "Enter one array value to copy them to the other:";
	for (int i = 0; i < 10; i++) {
		cin >> arr[i];
	}
	copying(arr, arr2);
	cout << endl;
	return 0;
}