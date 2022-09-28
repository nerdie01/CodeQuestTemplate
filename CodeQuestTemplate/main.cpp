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

vector<string> seperateString(string delimiter, string str)
{
    vector<string> lines;
    size_t pos = 0;
    std::string token;

    while ((pos = str.find(delimiter)) != std::string::npos) {
        token = str.substr(0, pos);
        lines.push_back(token);
        str.erase(0, pos + delimiter.length());
    }
    
    lines.push_back(str);
    return lines;
}

int main()
{
    vector<string> input = getInput();
}