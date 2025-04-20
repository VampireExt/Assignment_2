#include<iostream>
#include<fstream>
using namespace std;

void saim(char str[]) {
    ofstream file("output.txt");  

    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }

    file << str << endl;  
    file.close();

    cout << "String written to file successfully." << endl;
}

int main() {
    char str[100];

    cout << "Enter a string to store in a file: ";
    cin.getline(str, 100);  

    saim(str);  

    system("pause");
    return 0;
}
