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
    
    cout << endl << "BLOCKING CHIPERTEXT= ";
    cout << blockingCipher << endl << endl;
    cout << "==========================";
    
    cout << endl << endl;
    cout << "SUBTITUTING BLOCKING CHIPERTEXT";
    cout << endl << endl;
    
    string subtitute;
    int subtituteLength = blockingCipher.length();
    
    for (int m = 0; m < subtituteLength; m++) {
        char target = blockingCipher[m];
        int asci = int(target);
        
        // A - Z
        if (asci >= 65 && asci <= 77) asci += 2;
        if (asci >= 78 && asci <= 90) asci -= 2;
        
        // a - z
        if (asci >= 97 && asci <= 109) asci += 2;
        if (asci >= 110 && asci <= 122) asci -= 2;
        
        // 0 - 9
        if (asci >= 48 && asci <= 52) asci += 2;
        if (asci >= 53 && asci <= 57) asci -+ 2;
        
        // space & _
        if (asci == 32) asci = 95;
        if (asci == 95) asci = 32;
        
        char newAsci = char(asci);
        subtitute += newAsci;
    }
    
    cout << "SUBTITUTION CHIPERTEXT= " << subtitute << endl;

    return 0;
}
