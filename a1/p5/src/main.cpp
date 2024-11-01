#include <iostream>
#include <vector>

using namespace std;
int main(void) {

    cout << endl;
    cout << "  /-------------/" << endl;
    cout << " / Problem 1.5 /" << endl;
    cout << "/-------------/" << endl;
    cout << endl;

    vector<string> str_vec;

    // get user input
    char line[1024];
    while (true) {
        cin.getline(line, 1024, '\n');
        string input(line);

        if (input == "END") break;

        str_vec.push_back(input);
    }

    // handle swap if possible
    if (str_vec.size() < 5 )
        cout << "Swap not possible. Line 5 is empty!\n";

    if (str_vec.size() < 2 ) 
        cout << "Swap not possible. Line 2 does not exist!\n";

    if (str_vec.size() > 4) {
        const string swp = str_vec[1];
        str_vec[1] = str_vec[4];
        str_vec[4] = swp;
    }

    // replace last string with `???`
    if (str_vec.size() > 0) *(str_vec.end() - 1) = "???";

    // print strings via index
    cout << "[";
    for (size_t i = 0; i < str_vec.size() - 1; ++i) {
        cout << str_vec[i] << ",";
    }
    cout << str_vec[str_vec.size() - 1] << "]\n";

    // print strings via iterator
    cout << "[";
    vector<string>::const_iterator iter;
    for (iter = str_vec.cbegin(); iter < str_vec.cend(); ++iter) {
        string semicolon = (iter == str_vec.cend() - 1) ? "" : ";";

        cout << *iter << semicolon;
    }
    cout <<"]\n";

    // print in reverse using iterator
    cout << "[ ";
    vector<string>::const_reverse_iterator r_iter;
    for (r_iter = str_vec.crbegin(); r_iter < str_vec.crend(); ++r_iter) {
        cout << *r_iter << " ";
    }
    cout << "]\n\n";


    return 0;
}
