#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include "marblestring.h"
using namespace std;


void findMatches(string file) {
    ifstream inputFile(file);
    string line;
    string filePattern = "(.*/)(.*[.]cpp)";
    string pattern = "char\\s+(\\w+)\\s*.*\\s*.*=\\s*\"(.+)\"\\s*;";
    smatch fmatches;
    smatch matches;
    regex r(filePattern);
    regex rgx(pattern);

    regex_match(file, fmatches, r);
    string toAdd = "mbl-";
    string newName = fmatches.str(1) + toAdd + fmatches.str(2);

    ofstream log(newName.c_str(), ios_base::app | ios_base::out);
    log << "#include \"marblestring.h\"" << endl;

    while (getline(inputFile, line)) {
        if (regex_search(line, matches, rgx)) {
            // matches(1): var name
            // matches(2): var content
            char matched[matches.str(2).length()];
            for (int j = 0; j < sizeof(matched); j++) {
                matched[j] = matches.str(2)[j];
            }
            MarbleString ms = MarbleString(matched);
            line = regex_replace(line, rgx, "MarbleString " + matches.str(1)
            + " = \"" + ms.generateMbl(matches.str(2)) + "\";");
        }
        log << line << endl;
    }
}


int main() {
    string fileName;
    cout << "Enter the name of the file you would like to marble:" << endl;
    cin >> fileName;
    findMatches(fileName.c_str());

    // we use this code to test that overloading the << operator  works
//    MarbleString data = "hgfedcb";
//    MarbleString example = "239523[{65432";
//    cout << data << endl << example << endl;
}
