#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

static const int MAX_SPACES = 40;

// -------------------------------
// Data class (NOT a struct)
// -------------------------------
class MonopolySpace {
public:
    string propertyName;
    string propertyColor;
    int value;
    int rent;

    MonopolySpace() {
        // TODO: define default constructor (recommended)
        propertyName = "";
        propertyColor = "";
        value = 0;
        rent = 0;
    }

    MonopolySpace(string propertyName, string propertyColor, int value, int rent) {
        /* TODO: Define overloaded constructor here */
        this -> propertyName = propertyName;
        this -> propertyColor = propertyColor;
        this -> value = value;
        this -> rent = rent;
    }

    bool isEqual(MonopolySpace other) {
        /* TODO: Define isEqual here (compare by name is fine if you enforce uniqueness) */
        return this -> propertyName == other.propertyName;
    }

    void print() {
        /* TODO: Define print here */
        // Example style:
        // cout << propertyName << " | " << propertyColor << " | $" << value << " | Rent " << rent;
        cout << propertyName << ", " << propertyColor << ", $" << value << ", Rent:" << rent << endl;
    }
};

// -------------------------------
// Template Node class (NOT a struct)
// -------------------------------
template <typename T>
class Node {
public:
    T data;
    Node<T>* nextNode;

    Node(T value) {
        data = value;
        nextNode = nullptr;
    }
};

// -------------------------------
// Template Circular Linked List class
// Spring 2026 version: traversable board
// -------------------------------
template <typename T>
class CircularLinkedList {
private:
    Node<T>* headNode;
    Node<T>* tailNode;

    // player cursor for traversal-based gameplay
    Node<T>* playerNode;

    int nodeCount;
    int passGoCount;

public:
    CircularLinkedList() {
        headNode = nullptr;
        tailNode = nullptr;
        playerNode = nullptr;

        nodeCount = 0;
        passGoCount = 0;
    }

    // -------------------------------
    // Board Construction Policy (Reminder)
    // -------------------------------
    // Spaces are added during board construction BEFORE gameplay.
    // You choose how to construct the board:
    // - hardcode spaces, read from file, or generate programmatically
    // The only non-negotiable requirement:
    // - enforce MAX_SPACES
    // - maintain circular integrity
    // -------------------------------

    // -------------------------------
    // Core A: Add a Space with Capacity Enforcement
    // -------------------------------
    bool addSpace(T value) {
        // TODO:
        // - If nodeCount == MAX_SPACES return false (do not corrupt list)
        // - Create new node
        // - If empty list: head=tail=player=new, new->next=head
        // - Else: tail->next=new, tail=new, tail->next=head
        // - nodeCount++

        //Check if the list is full
        if (nodeCount == MAX_SPACES) {
            return false;
        }

        Node<T>* newNode = new Node<T>(value);

        //If the list is empty
        if (headNode == nullptr) {
            headNode = newNode;
            tailNode = newNode;
            playerNode = newNode;
            newNode->nextNode = headNode;
        } else { //adds the new node to the end
            tailNode->nextNode = newNode;
            tailNode = newNode;
            tailNode -> nextNode = headNode;
        }

        //increase space count
        nodeCount++;
        return true;
    }

    // -------------------------------
    // Core B: Add Multiple Spaces at Once
    // -------------------------------
    int addMany(vector<T> values) {
        // TODO:
        // - Add sequentially until full
        // - Stop exactly when you reach MAX_SPACES
        // - Return number successfully added
        // - Do not corrupt pointers if capacity is exceeded
        int addedCount = 0;

        //add each space at a time
        for (int i = 0; i < values.size(); i++) {
            if (addSpace(values[i])) {
                addedCount++;
            }
            else { //stops when full
                break;
            }
        }
        return addedCount;
    }

    // -------------------------------
    // Core C: Traversal-Based Player Movement
    // -------------------------------
    void movePlayer(int steps) {
        // TODO:
        // - Move playerNode forward 'steps' times, node-by-node
        // - Wrap naturally because list is circular
        // - Detect and track passing GO:
        //   increment passGoCount when a move crosses from tail back to head
        // - Must handle empty list safely

        //checks for empty board
        if (playerNode == nullptr) {
            return;
        }

        //moves player one node at a time
        for (int i = 0; i < steps; i++) {
            //at tail, move passes GO
            if (playerNode == tailNode) {
                passGoCount++;
            }
            playerNode = playerNode->nextNode;
        }
    }

    int getPassGoCount() {
        return passGoCount; //number of time player passes GO
    }

    // -------------------------------
    // Core D: Controlled Board Display
    // -------------------------------
    void printFromPlayer(int count) {
        // TODO:
        // - Print exactly 'count' nodes starting from playerNode
        // - Must not infinite loop
        // - Must handle empty list
        // - Output must be deterministic and readable

       //empty board
        if (playerNode == nullptr) {
            cout << "Empty board." << endl;
            return;
        }

        //0 or negative
        if (count <= 0) {
            return;
        }

        Node<T>* temp = playerNode;

        //print spaces count from player
        for (int i = 0; i < count; i++) {
            cout << "Index " << i << " | ";
            temp -> data.print();
            temp = temp -> nextNode;
        }
    }

    // Optional helper: print full board once (one full cycle)
    void printBoardOnce() {
        // TODO:
        // - Traverse exactly one full cycle and print each node

        //empty board
        if (headNode == nullptr) {
            cout << "Empty board." << endl;
            return;
        }

        Node<T>* temp = headNode;

        //print the head
        temp -> data.print();
        temp = temp -> nextNode;

        //print the rest
        while (temp != headNode) {
            temp -> data.print();
            temp = temp -> nextNode;
        }

    }

    // -------------------------------
    // Advanced Option A (Level 1): removeByName
    // -------------------------------
    bool removeByName(string name) {
        // TODO:
        // - Delete FIRST matching node
        // - Must handle:
        //   - deleting head
        //   - deleting tail
        //   - deleting the only-node list
        // - Maintain circular link tail->next=head
        // - If playerNode points to deleted node, move playerNode to a safe node
        // - nodeCount--

        //empty list
        if (headNode == nullptr) {
            return false;
        }

        //one node
        if (headNode == tailNode) {
            if (headNode -> data.propertyName == name) {
                delete headNode;
                headNode = nullptr;
                tailNode = nullptr;
                playerNode = nullptr;
                nodeCount--;
                return true;
            }
            return false;
        }

        //head
        if (headNode -> data.propertyName == name) {
            Node<T>* old = headNode;
            headNode = headNode -> nextNode;
            tailNode -> nextNode = headNode;
            if (playerNode == old) {
                playerNode = headNode;
            }
            delete old;
            nodeCount--;
            return true;
        }

        //after head
        Node<T>* prev = headNode;
        Node<T>* curr = headNode -> nextNode;

        while (curr != headNode) {
            if (curr -> data.propertyName == name) {
                prev -> nextNode = curr -> nextNode;
                if (curr == tailNode) {
                    tailNode = prev; //if tail
                }
                if (playerNode == curr) {
                    playerNode = curr -> nextNode; //if player
                }
                delete curr;
                nodeCount--;
                return true;
            }
            prev = curr;
            curr = curr -> nextNode;
        }
        return false; //does not exist
    }

    // -------------------------------
    // Advanced Option A (Level 1): findByColor
    // -------------------------------
    vector<string> findByColor(string color) {
        // TODO:
        // - Traverse ring exactly once
        // - Collect matching names in vector<string>
        // - Return matches
        vector<string> matches;

        //empty board
        if (headNode == nullptr) {
            return matches;
        }

        Node<T>* temp = headNode;

        //check the headNode
        if (temp -> data.propertyColor ==  color) {
            matches.push_back(temp -> data.propertyName);
        }
        temp = temp -> nextNode;

        //check the rest of the list
        while (temp != headNode) {
            if (temp -> data.propertyColor == color) {
                matches.push_back(temp -> data.propertyName);
            }
            temp = temp -> nextNode;
        }

        return matches;
    }

    // -------------------------------
    // Edge-case helper: countSpaces O(n)
    // -------------------------------
    int countSpaces() {
        // TODO:
        // - Must be O(n), traverse exactly once with correct stop condition
        // - Do NOT rely on nodeCount for this method
        cout << "countSpaces unwritten" << endl;
        return 0;
    }

    // -------------------------------
    // Cleanup
    // -------------------------------
    void clear() {
        // TODO:
        // - Safely delete all nodes
        // - Tip: if tailNode exists, break the cycle first: tailNode->nextNode = nullptr
        // - Then delete like a normal singly linked list

        //empty list
        if (headNode == nullptr) {
            return;
        }

        //convert to normal linked list
        tailNode -> nextNode = nullptr;

        Node<T>* current = headNode;
        Node<T>* nextNode = nullptr;

        //delete the nodes
        while (current != nullptr) {
            nextNode = current -> nextNode;
            delete current;
            current = nextNode;
        }

        //reset everything
        headNode = nullptr;
        tailNode = nullptr;
        playerNode = nullptr;
        nodeCount = 0;
        passGoCount = 0;
    }
};

// -------------------------------
// Main: playable loop demo
// -------------------------------
int rollDice2to12() {
    return (rand() % 6 + 1) + (rand() % 6 + 1);
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    CircularLinkedList<MonopolySpace> board;

    // -------------------------------
    // Board Construction Phase
    // -------------------------------
    // You decide how to build the board:
    // - hardcode spaces, load from file, or generate spaces programmatically
    // The only requirement: never exceed MAX_SPACES and keep the list circular.
    //
    // Example (hardcoded) usage:
    // vector<MonopolySpace> spaces;
    // spaces.push_back(MonopolySpace("GO","None",0,0));
    // ...
    // board.addMany(spaces);
    //
    // NOTE: This starter calls addSpace once to show the intended API,
    // but your final submission should build a meaningful board.

    vector<MonopolySpace> spaces;
    spaces.push_back(MonopolySpace("GO", "None", 0, 0));
    spaces.push_back(MonopolySpace("Tenocha", "Brown", 60, 2));
    spaces.push_back(MonopolySpace("King's Park", "Brown", 60, 4));
    spaces.push_back(MonopolySpace("Kona Beach Walk", "Light Blue", 100, 6));
    spaces.push_back(MonopolySpace("Maleina Lane", "Light Blue", 100, 6));
    spaces.push_back(MonopolySpace("Mikaela Market", "Pink", 140, 10));
    spaces.push_back(MonopolySpace("Shanelle Shore", "Pink", 140, 10));
    spaces.push_back(MonopolySpace("RJ Road", "Orange", 180, 14));
    spaces.push_back(MonopolySpace("Filipino Food Stop", "Red", 220, 18));
    spaces.push_back(MonopolySpace("SDSU", "Red", 220, 18));
    spaces.push_back(MonopolySpace("McDonald's", "Yellow", 260, 22));
    spaces.push_back(MonopolySpace("Afters Ice  Cream", "Yellow", 260, 22));
    spaces.push_back(MonopolySpace("Seal Beach", "Green", 300, 26));
    spaces.push_back(MonopolySpace("Eureka!", "Green", 300, 26));
    spaces.push_back(MonopolySpace("Aztec Corner", "Blue", 350, 35));

    int added = board.addMany(spaces);

    cout << "Board created with " << added << " spaces." << endl;
    cout << "Starting board:" << endl;
    board.printBoardOnce();

    // -------------------------------
    // Playable Traversal Loop
    // -------------------------------
    for (int turn = 1; turn <= 10; turn++) {
        int roll = rollDice2to12();
        cout << "\nTurn " << turn << " | Rolled: " << roll << endl;

        board.movePlayer(roll);

        cout << "Board view from player (next 5 spaces):" << endl;
        board.printFromPlayer(5);

        cout << "Times passed GO so far: " << board.getPassGoCount() << endl;
    }

    // -------------------------------
    // Advanced Feature Demos (students choose path)
    // -------------------------------
    // Option A examples:
    // board.removeByName("Baltic Avenue");
    // vector<string> brownProps = board.findByColor("Brown");
    //
    // Option B example:
    // board.mirrorBoard();

    //findByColor()
    cout << "\nBrown spaces:" << endl;
    vector<string> brownProps = board.findByColor("Brown");

    for (int i = 0; i < brownProps.size(); i++) {
        cout << brownProps[i] << endl;
    }

    //removeByName
    cout << "\nRemove 'Eureka!'" << endl;
    board.removeByName("Eureka!");

    //print board to check
    cout << "\nBoard after removing Eureka:" << endl;
    board.printBoardOnce();

    return 0;
}
