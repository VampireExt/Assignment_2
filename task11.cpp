#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void addStudent() {
    ofstream file("students.txt", ios::app);
    string name, rollNo, dept;
    float gpa;

    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Roll Number: ";
    getline(cin, rollNo);
    cout << "Enter Department: ";
    getline(cin, dept);
    cout << "Enter GPA: ";
    cin >> gpa;

    if (file.is_open()) {
        file << rollNo << " " << name << " " << dept << " " << gpa << endl;
        cout << "\nStudent record added successfully!"<<endl;
    }

    file.close();
}

void viewStudents() {
    ifstream file("students.txt");
    string rollNo, name, dept;
    float gpa;

    cout << "\nStudent Records:"<<endl;
    cout << endl;
    cout << "Roll No\t\tName\t\tDepartment\tGPA"<<endl;
    cout << endl;

    while (file >> rollNo >> name >> dept >> gpa) {
        cout << rollNo << "\t\t" << name << "\t\t" << dept << "\t\t" << gpa << endl;
    }
    file.close();
}

void searchStudent() {
    ifstream file("students.txt");
    string rollNo, name, dept, inputRoll;
    float gpa;
    bool found = false;

    cout << "Enter Roll Number to search: ";
    cin.ignore();
    getline(cin, inputRoll);

    while (file >> rollNo >> name >> dept >> gpa) {
        if (rollNo == inputRoll) {
            {
                cout << "\nStudent Found:\n";
                cout << "Roll No: " << rollNo << "\n";
                cout << "Name: " << name << "\n";
                cout << "Department: " << dept << "\n";
                cout << "GPA: " << gpa << "\n";
                found = true;
            }
            break;
        }
    }

    if (found==false) {
        {
            cout << "\nStudent not found."<<endl;
        }
    }

    file.close();
}

void updateGPA() {
    ifstream file("students.txt");
    ofstream temp("temp.txt");
    string rollNo, name, dept, inputRoll;
    float gpa, newGPA;
    bool found = false;

    cout << "Enter roll number to update GPA of specific student.: ";
    cin.ignore();
    getline(cin, inputRoll);

    while (file >> rollNo >> name >> dept >> gpa) {
        if (rollNo == inputRoll) {
            {
                cout << "Current GPA: " << gpa;
                cout<< "\nEnter New GPA: ";
                cin >> newGPA;
                gpa = newGPA;
                found = true;
            }
        }
        temp << rollNo << " " << name << " " << dept << " " << gpa << endl;
    }

    file.close();
    temp.close();

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found==true) {
        {
            cout << "\nGPA updated successfully."<<endl;
        }
    }
    else {
        {
            cout << "\nStudent not found." << endl;
        }
    }
}

void deleteStudent() {
    ifstream file("students.txt");
    ofstream temp("temp.txt");
    string rollNo, name, dept, inputRoll;
    float gpa;
    bool found = false;

    cout << "Enter Roll Number to delete: ";
    cin.ignore();
    getline(cin, inputRoll);

    while (file >> rollNo >> name >> dept >> gpa) {
        if (rollNo != inputRoll) {
            {
                temp << rollNo << " " << name << " " << dept << " " << gpa << endl;
            }
        }
        else {
            {
                found = true;
                continue;
            }
        }
    }

    file.close();
    temp.close();

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found==true) {
        {
            cout << "\nStudent record deleted successfully." << endl;
        }
    }
    else {
        {
            cout << "\nStudent not found." << endl;
        }
    }
}

int main() {
    int choice;

menu:
    cout << "\n***Student Management System ***\n";
    cout << "1. Add Student\n";
    cout << "2. View All Students\n";
    cout << "3. Search Student\n";
    cout << "4. Update GPA\n";
    cout << "5. Delete Student\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        addStudent();
    }
    else if (choice == 2) {
        viewStudents();
    }
    else if (choice == 3) {
        searchStudent();
    }
    else if (choice == 4) {
        updateGPA();
    }
    else if (choice == 5) {
        deleteStudent();
    }
    else if (choice == 6) {
        {
            cout << endl;
            cout << "Exiting the program.\n";
            return 0;
        }
    }
    else {
        {
            cout << "\nInvalid choice! Try again."<<endl;
        }
    }

    goto menu;
}
