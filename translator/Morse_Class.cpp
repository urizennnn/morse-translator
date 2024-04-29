#include "../includes/translator.h"
#include <sstream>
#include <algorithm>
#include <iostream>

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

std::string MorseCodeTranslator::encode(const std::string& text) {
    std::string encodedText;
    for (char c : text) {
        char uppercaseChar = std::toupper(c);
        if (morseCodeMap.find(uppercaseChar) != morseCodeMap.end()) {
            encodedText += morseCodeMap[uppercaseChar] + " ";
        } else {
            encodedText += c;
        }
    }
    return encodedText;
}

std::string MorseCodeTranslator::decode(const std::string& morseCode) {
    std::stringstream ss(morseCode);
    std::string word;
    std::string decodedText;
    while (std::getline(ss, word, ' ')) {
        if (reverseMorseCodeMap.find(word) != reverseMorseCodeMap.end()) {
            decodedText += reverseMorseCodeMap[word];
        } else {
            decodedText += "[INVALID]";
        }
    }
    return decodedText;
}
