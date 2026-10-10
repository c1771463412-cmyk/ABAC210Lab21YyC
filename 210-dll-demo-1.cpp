// COMSC-210-5293 | Lab 21 | Yuyi Chen

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MIN_LS = 5, MAX_LS = 20;
const int GOAT_SIZE = 15;

class Goat {
    private:
        int age;
        string name;
        string color;
        string names[GOAT_SIZE];
        string colors[GOAT_SIZE];
    
    public:
        Goat() {
            string goatNames[GOAT_SIZE] = {
                "Billy", "Daisy", "Clover", "Luna", "Oreo",
                "Peanut", "Maple", "Willow", "Hazel", "Coco",
                "Mochi", "Biscuit", "Poppy", "Rosie", "Charlie"
            };

            string goatColors[GOAT_SIZE] = {
                "White", "Black", "Brown", "Gray", "Cream",
                "Tan", "Gold", "Red", "Yellow", "Chocolate",
                "Caramel", "Beige", "Silver", "Spotted", "Mixed"
            };

            for (int i = 0; i < GOAT_SIZE; i++) {
                names[i] = goatNames[i];
                colors[i] = goatColors[i];
            }

            age = rand() % 20 + 1; // Random age between 1-20
            name = names[rand() % GOAT_SIZE];
            color = colors[rand() % GOAT_SIZE];
        }

        Goat(int a, string n, string c) {
            age = a;
            name = n;
            color = c;
        }

        int getAge()      { return age; }
        string getName()  { return name; }
        string getColor() { return color; }
};

class DoublyLinkedList {
private:
    struct Node {
        Goat data;
        Node* prev;
        Node* next;

        Node(Goat val, Node* p = nullptr, Node* n = nullptr) {
            data = val; 
            prev = p;
            next = n;
        }
    };

    Node* head;
    Node* tail;

public:
    // constructor
    DoublyLinkedList() { head = nullptr; tail = nullptr; }

    void push_back(Goat value) {
        Node* newNode = new Node(value);
        if (!tail)  // if there's no tail, the list is empty
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void push_front(Goat value) {
        Node* newNode = new Node(value);
        if (!head)  // if there's no head, the list is empty
            head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void print() {
        if (!head) {
            cout << "List is empty" << endl;
            return;
        }

        Node* current = head;

        while (current) {
            cout << "    " << current->data.getName()
                 << " (" << current->data.getColor()
                 << ", " << current->data.getAge() << ")" << endl;

            current = current->next;
        }
    }

    void print_reverse() {
        if (!tail) {
            cout << "List is empty" << endl;
            return;
        }

        Node* current = tail;

        while (current) {
            cout << "    " << current->data.getName()
                 << " (" << current->data.getColor()
                 << ", " << current->data.getAge() << ")" << endl;

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

// Driver program
int main() {
    srand(time(0));

    DoublyLinkedList list;

    // Test printing and empty list
    cout << "Empty list test:" << endl;
    list.print();
    list.print_reverse();
    cout << endl;

    int size = rand() % (MAX_LS - MIN_LS + 1) + MIN_LS;

    for (int i = 0; i < size; ++i) {
        Goat goat;
        list.push_back(goat);
    }

    cout << "List forward:\n";
    list.print();

    cout << endl;

    cout << "List backward:\n";
    list.print_reverse();

    return 0;
}
