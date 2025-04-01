#include <iostream>
#include <string>
using namespace std;

class RecursiveDescentParser {
private:
    string input;
    int index;
    bool S();
    bool L();
    bool L_prime();
public:
    RecursiveDescentParser(string str) : input(str), index(0) {}
    bool parse();
};

bool RecursiveDescentParser::S() {
    if (index < input.size() && input[index] == 'a') {
        index++;
        return true;
    }
    else if (index < input.size() && input[index] == '(') {
        index++;
        if (L() && index < input.size() && input[index] == ')') {
            index++;
            return true;
        }
    }
    return false;
}

bool RecursiveDescentParser::L() {
    if (S()) {
        return L_prime();
    }
    return false;
}

bool RecursiveDescentParser::L_prime() {
    if (index < input.size() && input[index] == ',') {
        index++;
        if (S()) {
            return L_prime();
        }
        return false;
    }
    return true; // ε (epsilon) case
}

bool RecursiveDescentParser::parse() {
    if (S() && index == input.size()) {
        return true;
    }
    return false;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;
    RecursiveDescentParser parser(input);
    if (parser.parse()) {
        cout << "Valid string" << endl;
    } else {
        cout << "Invalid string" << endl;
    }
    return 0;
}
