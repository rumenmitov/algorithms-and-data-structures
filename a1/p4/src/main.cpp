#include <iostream>
#include <vector>

using namespace std;
int main(void) {

    cout << endl;
    cout << "  /-------------/" << endl;
    cout << " / Problem 1.4 /" << endl;
    cout << "/-------------/" << endl;
    cout << endl;

    vector<string> str_vec;
    string input;

    while (true) {
        cin >> input;
        if (input == "END") break;

        str_vec.push_back(input);
    }

    cout << endl << "Vector (using index operator): [ ";
    for (size_t i = 0; i < str_vec.size(); ++i) {
        cout << str_vec[i] << " ";
    }
    cout << "]\n\n";

    cout << "Vector (using iterator): [";

    vector<string>::const_iterator iter;
    for (iter = str_vec.cbegin(); iter < str_vec.cend(); ++iter) {
        string comma = (iter == str_vec.cend() - 1) ? "" : ",";
        cout << *iter << comma;
    }
    cout << "]\n\n";

    return 0;
}
