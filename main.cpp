#include <iostream>
#include <string>
#include "translator/translator.h"

using namespace std;

int main() {
    string word = "Hello world";
    string result = encode(word);
    cout << result << endl;
    return 0;
}
