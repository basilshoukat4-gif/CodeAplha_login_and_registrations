#include <iostream>
#include <fstream>
using namespace std;

// Registration Function
void registerUser() {

    string username, password;

    cout << "\n===== USER REGISTRATION =====\n";

    cout << "Enter username: ";
    cin.ignore();
    getline(cin, username);

    cout << "Enter password: ";
    getline(cin, password);

    // Check empty fields
    if(username.empty() || password.empty()) {

        cout << "\nUsername or Password cannot be empty!\n";
        return;
    }

    // Check duplicate username
    ifstream checkFile(username + ".txt");

    if(checkFile.is_open()) {

        cout << "\nUsername already exists!\n";
        checkFile.close();
        return;
    }

    checkFile.close();

    // Create user file
    ofstream file(username + ".txt");

    file << username << endl;
    file << password << endl;

    file.close();

    cout << "\nRegistration Successful!\n";
}

// Login Function
void loginUser() {

    string username, password;
    string storedUsername, storedPassword;

    cout << "\n===== USER LOGIN =====\n";

    cout << "Enter username: ";
    cin.ignore();
    getline(cin, username);

    cout << "Enter password: ";
    getline(cin, password);

    // Open file
    ifstream file(username + ".txt");

    if(!file.is_open()) {

        cout << "\nUser does not exist!\n";
        return;
    }

    // Read stored data
    getline(file, storedUsername);
    getline(file, storedPassword);

    file.close();

    // Verify credentials
    if(username == storedUsername && password == storedPassword) {

        cout << "\nLogin Successful!\n";
        cout << "Welcome " << username << "!\n";
    }
    else {

        cout << "\nIncorrect Password!\n";
    }
}

// Main Function
int main() {

    int choice;

    do {

        cout << "\n\n===== LOGIN SYSTEM =====\n";

        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {

            case 1:
                registerUser();
                break;

            case 2:
                loginUser();
                break;

            case 3:
                cout << "\nProgram Closed.\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while(choice != 3);

    return 0;
}