#include <iostream>
#include <string>
#include "includes/translator.h"

using namespace std;

int main() {
    MorseCodeTranslator translator;
    string word = "Hello world";
    string result = translator.encode(word);
    cout << result << endl;
    return 0;
}
