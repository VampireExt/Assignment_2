#include<iostream>
using namespace std;

int sum(int arr[5]) {

	int sum = 0;
	for (int i = 0; i < 5; i++) {
		sum += arr[i];
	}
	
	return sum;
}


int main() {
	int arr[5];
	cout << "Enter the elements of array to calculate the sum:";
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
	}
	cout<<sum(arr);

	return 0;
}