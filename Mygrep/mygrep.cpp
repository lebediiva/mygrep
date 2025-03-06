#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void interactiveSearch() {
    string fullString, searchString;

    // kysyt‰‰n k‰ytt‰j‰lt‰ mist‰ se haluu etsii

    cout << "Give a string to search from: ";
    getline(cin, fullString);

    // kysyt‰‰n ett‰ mit‰ se haluu etsii

    cout << "Give search string: ";
    getline(cin, searchString);

    size_t found = fullString.find(searchString);
    if (found != string::npos) {
        cout << "\"" << searchString << "\" found in \"" << fullString << "\" at position " << found << endl;
    }
    else {
        cout << "\"" << searchString << "\" not found in \"" << fullString << "\"" << endl;
    }
}

void fileSearch(const string& searchString, const string& fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cout << "Could not open file " << fileName << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        if (line.find(searchString) != string::npos) {
            cout << line << endl;
        }
    }
    file.close();
}

int main(int argc, char* argv[]) {
    if (argc == 1) {
        interactiveSearch();
    }
    else if (argc == 3) {
        string searchString = argv[1];
        string fileName = argv[2];
        fileSearch(searchString, fileName);
    }
    else {
        cout << "Usage: " << argv[0] << endl;
        cout << "       " << argv[0] << " <searchString> <fileName>" << endl;
    }
    return 0;
}
