
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main(void)
{
    cout << "Enter in the 48 digit binary input" << endl;

    string binaryInput;
    std::cin >> binaryInput;

    string current;
    string rowS;
    string colS;
    int row;
    int col;
    int count = 0;
    for(int i = 0; i < binaryInput.length(); i += 6){
        count++;
        current = binaryInput.substr(i, 6);

        rowS = current.substr(0,1) + (current.substr(5,1));
        colS = current.substr(1, 4);

        row = std::stoi(rowS, nullptr, 2);
        col = std::stoi(colS, nullptr, 2);
        // cout << current << " : "  << i << endl;

        //cout << col << " : "  << row << " : " << current << " : "  << i << endl;
        cout << "S-Box: " << count <<  " Column: " << col << "  Row: " << row << endl;
    }
}