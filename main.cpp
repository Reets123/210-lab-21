// Lab 21: Goat Herd Manager 3000
// COMSC-210 - Ibrahim Alatig 

#include <iostream>
#include <string>
#include <cstdlib>  
#include <ctime>    

using namespace std;

class Goat {
private:
    int age;
    string name;
    string color;
    
    static const string names[15];
    static const string colors[15];

public:
    Goat() {
        age = rand() %
