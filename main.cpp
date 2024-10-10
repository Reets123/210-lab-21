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
        os << goat.name << " (" << goat.color << ", " << goat.age << ")";
        return os;
    }
};

const string Goat::names[15] = {"Bobby", "Nanny", "Billy", "Daisy", "Ginger", "Coco", "Goaty", "Luna", "Marley", "Bella", "Leo", "Simba", "Misty", "Shadow", "Finn"};
const string Goat::colors[15] = {"Brown", "Black", "White", "Spotted", "Gray", "Tan", "Cream", "Golden", "Red", "Yellow", "Pink", "Blue", "Purple", "Orange", "Green"};

class DoublyLinkedList {
private:
    struct Node {
        Goat data;
        Node* prev;
        Node* next;
        Node(Goat val, Node* p = nullptr, Node* n = nullptr) : data(val), prev(p), next(n) {}
    };
    Node* head;
    Node* tail;

public:
    // Constructor
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void push_back(const Goat& value) {
        Node* newNode = new Node(value);
        if (!tail) // if there's no tail, the list is empty
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void push_front(const Goat& value) {
        Node* newNode = new Node(value);
        if (!head) // if there's no head, the list is empty
            head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void print() const {
        Node* current = head;
        if (!currrent) {
            cout << "List is empty" << endl;
            return;
        }
        while (current) {
            cout << "    " << current->data << endl;
            current = current->next;
        }
    }

    void print_reverse() const {
        Node* current = tail;
        if (!current) {
            cout << "List is empty" << endl;
            return;
        }

        while (current) {
            cout << "    " << current->data << endl;
            current = current->prev;
        }
    }

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    srand(time(0));

    DoublyLinkedList list;
    int size = rand() % (16) + 5; // Random size between 5 and 20
    for (int i = 0; i < size; ++i) {
        Goat goat; 
        list.push_back(goat); 
    }

    cout << "Forward:" << endl;
    list.print(); 

    cout << "Backward:" << endl;
    list.print_reverse(); 

    return 0;
}
