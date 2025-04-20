#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void addPlayer() {
    ofstream file("players.txt", ios::app);
    string name, team, role;
    int runs, wickets;

    cout << "Enter Player Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Team Name: ";
    getline(cin, team);
    cout << "Enter Role (batsman/bowler/all-rounder): ";
    getline(cin, role);
    cout << "Enter Total Runs: ";
    cin >> runs;
    cout << "Enter Total Wickets: ";
    cin >> wickets;

    if (file.is_open()) {
        file << name << " " << team << " " << role << " " << runs << " " << wickets << endl;
        cout << "\nPlayer record added successfully!\n";
    }

    file.close();
}

void viewPlayers() {
    ifstream file("players.txt");
    string name, team, role;
    int runs, wickets;

    cout << "\nPSL Player Records:\n\n";
    cout << "Name\t\tTeam\t\tRole\t\tRuns\tWickets\n\n";

    while (file >> name >> team >> role >> runs >> wickets) {
        cout << name << "\t\t" << team << "\t\t" << role << "\t\t" << runs << "\t" << wickets << endl;
    }

    file.close();
}

void searchPlayer() {
    ifstream file("players.txt");
    string name, team, role, searchInput;
    int runs, wickets;
    bool found = false;
    int option;

    cout << "Search Player By:\n1. Name\n2. Team\nEnter option: ";
    cin >> option;
    cin.ignore();

    cout << "Enter search input name or team.: ";
    getline(cin, searchInput);

    while (file >> name >> team >> role >> runs >> wickets) {
        if ((option == 1 && name == searchInput) || (option == 2 && team == searchInput)) {
            cout << "\nPlayer Found:\n";
            cout << "Name: " << name << "\nTeam: " << team << "\nRole: " << role;
            cout << "\nRuns: " << runs << "\nWickets: " << wickets << "\n";
            found = true;
        }
    }

    if (!found) {
        cout << "\nPlayer not found.\n";
    }

    file.close();
}

void updateData() {
    ifstream file("players.txt");
    ofstream temp("temp.txt");
    string name, team, role, inputName;
    int runs, wickets, newRuns, newWickets;
    bool found = false;

    cout << "Enter player name to update stats: ";
    cin.ignore();
    getline(cin, inputName);

    while (file >> name >> team >> role >> runs >> wickets) {
        if (name == inputName) {
            cout << "Current Runs: " << runs;
            cout<< " ,Current Wickets: " << wickets << "\n";

            cout << "Enter Updated Runs: ";
            cin >> newRuns;
            cout << "Enter Updated Wickets: ";
            cin >> newWickets;

            runs = newRuns;
            wickets = newWickets;
            found = true;
        }
        temp << name << " " << team << " " << role << " " << runs << " " << wickets << endl;
    }

    file.close();
    temp.close();

    remove("players.txt");
    rename("temp.txt", "players.txt");

    if (found) {
        cout << "\nPlayer stats updated successfully.\n";
    }
    else {
        cout << "\nPlayer not found.\n";
    }
}

void deletePlayer() {

    ifstream file("players.txt");
    ofstream temp("temp.txt");

    string name, team, role, inputName;
    int runs, wickets;
    bool found = false;

    cout << "Enter player name to delete: ";
    cin.ignore();
    getline(cin, inputName);

    while (file >> name >> team >> role >> runs >> wickets) {
        if (name != inputName) {
            temp << name << " " << team << " " << role << " " << runs << " " << wickets << endl;
        }
        else {
            found = true;
        }
    }

    file.close();
    temp.close();

    remove("players.txt");
    rename("temp.txt", "players.txt");

    if (found) {
        cout << "\nPlayer record deleted successfully.\n";
    }
    else {
        cout << "\nPlayer not found.\n";
    }
}

int main() {
    int choice;

menu:
    cout << "\n*** PSL Management System ***\n";
    cout << "1. Add Player\n";
    cout << "2. View All Players\n";
    cout << "3. Search Player\n";
    cout << "4. Update Player Data\n";
    cout << "5. Delete Player\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        addPlayer();
    }
    else if (choice == 2) {
        viewPlayers();
    }
    else if (choice == 3) {
        searchPlayer();
    }
    else if (choice == 4) {
        updateData();
    }
    else if (choice == 5) {
        deletePlayer();
    }
    else if (choice == 6) {
        cout << "\nExiting the program.\n";
        return 0;
    }
    else {
        cout << "\nInvalid choice! Try again.\n";
    }

    goto menu;
}
