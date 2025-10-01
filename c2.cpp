#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

class User {
public:
    string name, address, contact;
    User(string name, string address, string contact)
        : name(name), address(address), contact(contact) {}
};

class Waste {
public:
    string type, date, contact;
    Waste(string type, string date, string contact)
        : type(type), date(date), contact(contact) {}
};

class Feedback {
public:
    string contact, message;
    Feedback(string contact, string message)
        : contact(contact), message(message) {}
};

class WasteManagementSystem {
private:
    vector<User> users;
    vector<Waste> wastes;
    vector<Feedback> feedbacks;

public:
    void displayDivider() {
        cout << "===========================================\n";
    }

    void centerText(const string& text) {
        int width = 42;
        int pad = (width - text.size()) / 2;
        for (int i = 0; i < pad; ++i) cout << " ";
        cout << text << endl;
    }

    void registerUser() {
        string name, address, contact;
        cout << "Enter Contact Number: ";
        cin >> contact;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Address: ";
        getline(cin, address);

        ofstream fout("users.txt", ios::app);
        fout << name << "," << address << "," << contact << endl;
        fout.close();
        cout << "User registered successfully.\n";
    }

    bool loginUser(string& contact) {
        cout << "Enter Contact Number: ";
        cin >> contact;
        ifstream fin("users.txt");
        string line;
        while (getline(fin, line)) {
            stringstream ss(line);
            string name, address, storedContact;
            getline(ss, name, ',');
            getline(ss, address, ',');
            getline(ss, storedContact);
            if (storedContact == contact) {
                cout << "Login successful.\n";
                return true;
            }
        }
        cout << "User not found. Please register.\n";
        return false;
    }

    void scheduleWasteCollection(const string& contact) {
        string type, date;
        cin.ignore();
        cout << "Enter Waste Type: ";
        getline(cin, type);
        cout << "Enter Collection Date: ";
        getline(cin, date);

        ofstream fout("waste.txt", ios::app);
        fout << type << "," << date << "," << contact << endl;
        fout.close();
        cout << "Waste scheduled successfully.\n";
    }

    void processWaste(const string& contact) {
        cout << "Processing waste for contact: " << contact << endl;
    }

    void generateReport(const string& contact) {
        cout << "Generating report for contact: " << contact << endl;
    }

    void getUserFeedback(const string& contact) {
        string message;
        cin.ignore();
        cout << "Enter feedback: ";
        getline(cin, message);

        ofstream fout("feedback.txt", ios::app);
        fout << contact << "," << message << endl;
        fout.close();
        cout << "Thank you for your feedback.\n";
    }

    void deleteWasteRecord(const string& contact) {
        cout << "Deleting waste record for contact: " << contact << endl;
    }

    void searchWasteByType() {
        string type;
        cin.ignore();
        cout << "Enter waste type: ";
        getline(cin, type);
        ifstream fin("waste.txt");
        string line;
        bool found = false;
        while (getline(fin, line)) {
            if (line.find(type) != string::npos) {
                cout << line << endl;
                found = true;
            }
        }
        if (!found) cout << "No records found.\n";
    }

    void showMainMenu(const string& contact) {
        int ch;
        do {
            displayDivider();
            centerText("SMART WASTE MENU");
            displayDivider();
            cout << "1. Schedule Waste\n";
            cout << "2. Process Waste\n";
            cout << "3. Generate Report\n";
            cout << "4. Submit Feedback\n";
            cout << "5. Delete Waste\n";
            cout << "6. Search Waste\n";
            cout << "0. Logout\n";
            cout << "Choice: ";
            cin >> ch;

            switch (ch) {
                case 1: scheduleWasteCollection(contact); break;
                case 2: processWaste(contact); break;
                case 3: generateReport(contact); break;
                case 4: getUserFeedback(contact); break;
                case 5: deleteWasteRecord(contact); break;
                case 6: searchWasteByType(); break;
                case 0: cout << "Logging out...\n"; break;
                default: cout << "Invalid option.\n";
            }
        } while (ch != 0);
    }

    void displayTeamInfo() {
        displayDivider();
        centerText("TEAM MEMBERS");
        displayDivider();
        cout << "1. NOSHIN\n";
        cout << "2. RUMMAN\n";
        cout << "3. MOWA\n";
        displayDivider();
    }
};

int main() {
    WasteManagementSystem system;
    string contact;
    int ch;
    do {
        system.displayDivider();
        system.centerText("SMART WASTE MANAGEMENT SYSTEM");
        system.displayDivider();
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Team Info\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> ch;

        switch (ch) {
            case 1: system.registerUser(); break;
            case 2:
                if (system.loginUser(contact))
                    system.showMainMenu(contact);
                break;
            case 3: system.displayTeamInfo(); break;
            case 0: cout << "Exiting program.\n"; break;
            default: cout << "Invalid option.\n";
        }
    } while (ch != 0);
    return 0;
}