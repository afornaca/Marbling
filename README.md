# Marbling
Takes .cpp file as input and makes a new file that 'marbles' the char array declarations. Overloads << operator in order to return the original, unmarbled contents.

Inspired by: https://wikileaks.org/ciav7p1/cms/page_14588467.html

## Future plans
  * Make it so a random obfuscation algorithm is chosen rather than having a single built in one
  * Revamp with a simple cross-platform GUI using QT in order to provide a user friendly experience where you can select any files to be marbled rather than providing their path in a console application.

## How it is done
  * Iteratively recreate the target file while using Regex to find and replace all of the character array declarations with MarbleString instantiations
  * The MarbleString object takes the original string content as a parameter and applies the marbling algorithm to it to produce an obfuscated string
  * In order to retrieve the original, unmarbled contents, I overloaded the << operator so that it undoes the marbling.
  * The result gives a new file with 'mbl-' appended to the beginning of the original file name to denote that it has been obfuscated

### Example
#### Original file: main.cpp
```
#include <iostream>
#include <string>

using namespace std;

int filler = 12;
string fillerString = "hello";
char data[] = "abcdefg";
int randomStuff = 987;
char example[    ] ="12345zZ214821";

// empty ones shouldn't be marbled
char dontTakeMe[] = "";
```

#### Marbled file: mbl-main.cpp
```
#include "marblestring.hpp"
#include <iostream>
#include <string>

using namespace std;

int filler = 12;
string fillerString = "hello";
MarbleString data = "hgfedcb";
int randomStuff = 987;
MarbleString example = "239523[{65432";

// empty ones shouldn't be marbled
char dontTakeMe[] = "";
```
