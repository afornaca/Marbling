
#ifndef MARBLING_MARBLESTRING_H
#define MARBLING_MARBLESTRING_H
#include <string>
#include <iostream>
#include <array>
using namespace std;

class MarbleString {
private:
    string prembl;
public:
    MarbleString(char pm[]) {
        prembl = pm;
    }

    friend ostream& operator<<(ostream& os, const MarbleString& ms);
    string generateMbl(string);
    int size(string);

};
#endif //MARBLING_MARBLESTRING_H
