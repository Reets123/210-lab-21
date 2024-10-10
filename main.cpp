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
        age = rand() % 20 + 1; // Random age between 1 and 20
        name = names[rand() % 15]; // Random name from names array
        color = colors[rand() % 15]; // Random color from colors array
    }

    // Parameterized constructor
    Goat(int age, string name, string color) : age(age), name(name), color(color) {}

    // Overloading << operator for easy printing of Goat object
    friend ostream& operator<<(ostream& os, const Goat& goat) {
        os << goat.name <
