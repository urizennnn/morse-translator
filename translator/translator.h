#ifndef TRANSLATE_H
#define TRANSLATE_H

#include <unordered_map>
#include <string>

using namespace std;

class MorseCodeTranslator {
private:
    unordered_map<char, string> morseCodeMap;
    unordered_map<string, char> reverseMorseCodeMap;

public:
    MorseCodeTranslator();

    string encode(const string& text);
    string decode(const string& morseCode);
};

#endif

