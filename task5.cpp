#include<iostream>
#include<fstream>
using namespace std;

void saim(char str[]) {
  

    for (int i = 0; str[i] != '\0'; i++) {
        cout << str[i] << endl;
   }

    cout << "Each character printed on new line successfully.";
    cout << endl;
   
}

int main() {
    char str[100];

    cout << "Enter a string: ";
    cin.getline(str, 100);

    saim(str);

    system("pause");
    return 0;
}