#include <iostream>
#include <fstream>

#include <string>
#include <vector>
#include <map>

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

void sort(vector<string> &v, int start, int end) {
    int pivot = end;
    int j = start;
    for (int i = start; i < end; ++i) {
        if (v[i] < v[pivot]) {
            swap(v[i], v[j]);
            ++j;
        }
    }
    swap(v[j], v[pivot]);

    if (start < end) {
        int p = j;
        sort(v, start, p - 1);
        sort(v, p + 1, end);
    }
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

}