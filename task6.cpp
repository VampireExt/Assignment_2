#include<iostream>
using namespace std;

int mx(int arr[10]) {
	int temp = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = i + 1; j < 10; j++) {
			if (arr[i] < arr[j]) {
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}
	cout << "The maximum value in array is:" << arr[0];
	return 0;
}

int main() {
	int arr[10];
	for (int i = 0; i < 10; i++) {
		cout << "enter value for index:" << i << " of aray.";
		cin >> arr[i];
	}
	mx(arr);
}