#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include "ArrayInversionCount.h"

using namespace std;

int main(int argc, char* argv[]) {
    string file_name;
    vector<int> numbers;
    ArrayInversionCount arrayInversionCount;

    ios_base::sync_with_stdio(false);

    if (argc < 2) {
        cerr << "File path expected, exiting..." << endl;
        return 1;
    }

    file_name = argv[1];
    ifstream ifs {file_name};
    int number;
    if (ifs) {
        cout << "Opened file: " << file_name << endl;
        while (ifs.good()) {
            ifs >> number;
            numbers.push_back(number);
        }
        InversionContainer inversionContainer = arrayInversionCount.sort_and_count_inv(numbers);
        cout << inversionContainer.getSize() << endl;
    } else {
        cerr << "Could not open file: " << file_name << endl;
        return 1;
    }

    return 0;
}