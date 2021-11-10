#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    string plainText;
    cout << "Enter some text: ";
    getline(cin, plainText);
    cout << endl << endl;
    int plainTextLength = plainText.length();
    int row = 5;
    
    int col = plainTextLength / row;
    if (plainTextLength & row != 0) col += 1;
    
    string arr[col];
    int loop = 0;
    
    for (unsigned i = 0; i < plainText.length(); i += 5) {
        string text = plainText.substr(i, 5);
        arr[loop] = text;
        loop += 1;
    }

    cout << "=======BLOCKING FORM=======" << endl << endl;
    for (int x = 0; x < row; x++) {
        for (int y = 0; y < col; y++) {
            string target = arr[y];
            int targetLength = target.length();
            if (targetLength >= x) cout << target[x];
        }
        cout << endl;
    }
    
    string blockingCipher;
    for (int x = 0; x < row; x++) {
        for (int y = 0; y < col; y++) {
            string target = arr[y];
            int targetLength = target.length();
            if (targetLength >= x) blockingCipher += target[x];
        }
    }
    
    cout << endl << "BLOCKING CIPHER TEXT = ";
    cout << blockingCipher << endl << endl;
    cout << "==========================";

    return 0;
}
