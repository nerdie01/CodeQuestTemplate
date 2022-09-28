#include <iostream>
#include <fstream>

#include <string>
#include <vector>

using namespace std;

vector<string> getInput() {
    vector<string> lines(0);
    ifstream scanner("input.txt", std::ifstream::in);

    if (!scanner) {
        cerr << "error opening file input.txt" << endl;
        return lines;
    }

    string str;
    while (getline(scanner, str)) {
        if (str.size() > 0) {
            lines.push_back(str);
        }
    }

    scanner.close();
    return lines;
}

vector<string> seperateString(const char* delimiter, char str[])
{
    vector<string> lines;
    char* token = strtok(str, delimiter);

    while (token != NULL)
    {
        lines.push_back(token);
        token = strtok(NULL, delimiter);
    }

    return lines;
}

int main()
{
    vector<string> input = getInput();

    for (int i = 0; i < input.size(); i++) {
        cout << input[i] << endl;
    }
}