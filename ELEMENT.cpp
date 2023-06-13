
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <climits>

using namespace std;

//create ELEMENT Class
class ELEMENT {

//declare variables and methods
public:
int key; 
ELEMENT(){}
ELEMENT(int k){key = k;}
void setKey(int k){key = k;}
int getKey(){
return key;
}

};

