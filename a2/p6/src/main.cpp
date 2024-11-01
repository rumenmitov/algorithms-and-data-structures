#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;
int main(void) {

    cout << endl;
    cout << "  /-------------/" << endl;
    cout << " / Problem 2.6 /" << endl;
    cout << "/-------------/" << endl;
    cout << endl;

    // Initializing state
    map<string,string> bday_db;

    ifstream f_in("p6/data.txt");

    string name;
    string bday;

    // Adding entries to database
    while ( getline(f_in, name) ) {
        getline(f_in, bday);

        bday_db[name] = bday;
    }

    // Query the database
    string input;
    while (1) {
        cout << "Enter name (or \"help\"): ";
        getline(cin, input);

        if (input == "quit") break;

        if (input == "help") {
            cout <<
                "Options:\n" <<
            "help       Displays this help menu.\n" <<
            "[ name ]   Retrieves birthday of given name, if it exists.\n" <<
            "list       Lists all names in the database.\n" <<
            "quit       Exits program.\n" 
            << endl;

            continue;
        }

        if (input == "list") {
            for (auto [name, bday] : bday_db) {
                cout << name << endl;
            }

            continue;
        }

        if ( bday_db.count(input) == 0 ) {
            cout << "Name not found!" << endl;
        } else {
            cout << bday_db[input] << endl;
        }
    }

    f_in.close();
    return 0;
}
