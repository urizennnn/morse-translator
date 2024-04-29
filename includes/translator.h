#ifndef MORSE_CODE_TRANSLATOR_H
#define MORSE_CODE_TRANSLATOR_H

using namespace std;

#include <unordered_map>
#include <string>

class MorseCodeTranslator {
private:
    unordered_map<char, string> morseCodeMap;
    unordered_map<string, char> reverseMorseCodeMap;

public:
    MorseCodeTranslator();

    string encode(const string& text);
    string decode(const string& morseCode);
};

#endif // MORSE_CODE_TRANSLATOR_H
