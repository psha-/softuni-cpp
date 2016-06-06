#include <iostream>

using namespace std;

int main()
{
    string line;

    getline(cin, line);

    unsigned int upperCount = 0;
    unsigned int lowerCount = 0;
    unsigned int otherCount = 0;
    for( size_t i=0; i<line.size(); i++) {
        unsigned short asciiChar = line[i];
        if( asciiChar >= 65 && asciiChar <= 90  ) {
            upperCount++;
        }
        else if( asciiChar >= 97 && asciiChar <= 122  ) {
            lowerCount++;
        }
        else {
            otherCount++;
        }
    }

    cout << "Characters count:" << endl;
    cout << "Uppercase: " << upperCount << endl;
    cout << "Lowercase: " << lowerCount << endl;
    cout << "Other: " << otherCount << endl;

    return 0;
}

