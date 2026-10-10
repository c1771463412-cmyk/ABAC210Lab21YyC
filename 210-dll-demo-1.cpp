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
        // Goat() randomly generates a goat's age, name, and color
        // arguments: none
        // returns: none
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

            // Copy the names and colors into the class arrays
            for (int i = 0; i < GOAT_SIZE; i++) {
                names[i] = goatNames[i];
                colors[i] = goatColors[i];
            }

            age = rand() % 20 + 1; // Random age between 1-20
            name = names[rand() % GOAT_SIZE];
            color = colors[rand() % GOAT_SIZE];
        }

        // Goat() creates a goat with the given information
        // arguments: a - age, n - name, c - color
        // returns: none
        Goat(int a, string n, string c) {
            age = a;
            name = n;
            color = c;
        }

        // getAge() returns the goat's age
        // arguments: none
        // returns: the age of the goat
        int getAge()      { return age; }

        // getName() returns the goat's name
        // arguments: none
        // returns: the name of the goat
        string getName()  { return name; }

        // getColor() returns the goat's color
        // arguments: none
        // returns: the color of the goat
        string getColor() { return color; }
};

class DoublyLinkedList {
private:
    struct Node {
        Goat data;
        Node* prev;
        Node* next;

        // Node() creates a node and sets its pointers
        // arguments: val - goat, p - previous node, n - next node
        // returns: none
        Node(Goat val, Node* p = nullptr, Node* n = nullptr) {
            data = val; 
            prev = p;
            next = n;
        }
    };

    Node* head;
    Node* tail;

public:
    // DoublyLinkedList() creates an empty linked list
    // arguments: none
    // returns: none
    DoublyLinkedList() { head = nullptr; tail = nullptr; }

    // push_back() adds a goat to the end of the list
    // arguments: value - goat to add
    // returns: none
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

    // push_front() adds a goat to the beginning of the list
    // arguments: value - goat to add
    // returns: none
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

    // print() displays all goats from head to tail
    // arguments: none
    // returns: none
    void print() {
        if (!head) {
            cout << "List is empty" << endl;
            return;
        }

        Node* current = head;

        // Move forward through the list
        while (current) {
            cout << "    " << current->data.getName()
                 << " (" << current->data.getColor()
                 << ", " << current->data.getAge() << ")" << endl;

            current = current->next;
        }
    }

    // print_reverse() displays all goats from tail to head
    // arguments: none
    // returns: none
    void print_reverse() {
        if (!tail) {
            cout << "List is empty" << endl;
            return;
        }

        Node* current = tail;

        // Move backward through the list
        while (current) {
            cout << "    " << current->data.getName()
                 << " (" << current->data.getColor()
                 << ", " << current->data.getAge() << ")" << endl;

            current = current->prev;
        }
    }

    // ~DoublyLinkedList() deletes all nodes to free memory
    // arguments: none
    // returns: none
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

    // Generate a random number of goats between 5 and 20
    int size = rand() % (MAX_LS - MIN_LS + 1) + MIN_LS;

    // Add randomly generated goats to the list
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
