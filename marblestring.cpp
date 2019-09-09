
#include "marblestring.h"
#include <iostream>
#include <string>

using namespace std;

ostream& operator<<(ostream& os, const MarbleString& ms) {
    char char_array[ms.prembl.size() + 1];
    strcpy(char_array, ms.prembl.c_str());
    for (int i = 0; i < ms.prembl.length(); i++) {
        char_array[i] = static_cast<char>(char_array[i] - 1);
    }
    string post(char_array);
    reverse(post.begin(), post.end());
    os << post;
    return os;
}


string MarbleString::generateMbl(string prembl) {
    reverse(prembl.begin(), prembl.end());
    char char_array[size(prembl)];
    strcpy(char_array, prembl.c_str());
    for (int i = 0; i < size(prembl); i++) {
        char_array[i] = static_cast<char>(char_array[i] + 1);
    }
    string postmbl(char_array);
    return postmbl;
}


int MarbleString::size(string prembl) {
    // if we include the null terminator we will get encoding issues, so use the length as the true size
    return prembl.length();
}









