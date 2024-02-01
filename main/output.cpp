#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void displayContent(const string &filename) {
    ifstream output(filename);

    if(!output) {
        cout << "Error occurred while opening file!" << endl;
        return;
    }

    string line;
    while(getline(output, line)) {
        cout << line << endl;
    }
}

int main () {
    displayContent("output.txt");
    return 0;
}
