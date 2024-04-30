#include "../includes/translator.h"
#include <sstream>

using namespace std;


MorseCodeTranslator::MorseCodeTranslator() {
    morseCodeMap = {
        {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."},
        {'F', "..-."}, {'G', "--."}, {'H', "...."}, {'I', ".."}, {'J', ".---"},
        {'K', "-.-"}, {'L', ".-.."}, {'M', "--"}, {'N', "-."}, {'O', "---"},
        {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"},
        {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"}, {'Y', "-.--"},
        {'Z', "--.."},
        {'0', "-----"}, {'1', ".----"}, {'2', "..---"}, {'3', "...--"}, {'4', "....-"}, {'5', "....."},
        {'6', "-....."}, {'7', "--..."}, {'8', "---.."}, {'9', "----."},
        {'.', ".-.-.-"}, {',', "--..--"}, {'?', "..--.."}, {'\'', ".----."}, {'!', "-.-.--"}, {'/', "-..-."}, {'(', "-.--."},
        {')', "-.--.-"}, {'&', ".-..."}, {':', "---..."}, {';', "-.-.-."}, {'=', "-...-"}, {'+', ".-.-."}, {'-', "-....-"},
        {'_', "..--.-"}, {'"', ".-..-."}, {'$', "...-..-"}, {'@', ".--.-."}, {' ', "/"}
    };

    for (const auto& [key, value] : morseCodeMap) {
        reverseMorseCodeMap[value] = key;
    }
}

string MorseCodeTranslator::encode(const string& text) {
    string encodedText;
    for (char c : text) {
        char uppercaseChar = toupper(c);
        if (morseCodeMap.find(uppercaseChar) != morseCodeMap.end()) {
            encodedText += morseCodeMap[uppercaseChar] + " ";
        } else {
            encodedText += c;
        }
    }
    return encodedText;
}

string MorseCodeTranslator::decode(const string& morseCode) {
    stringstream ss(morseCode);
    string word;
    string decodedText;
    while (getline(ss, word, ' ')) {
        if (reverseMorseCodeMap.find(word) != reverseMorseCodeMap.end()) {
            decodedText += reverseMorseCodeMap[word];
        } else {
            decodedText += "[INVALID]";
        }
    }
    return decodedText;
}
