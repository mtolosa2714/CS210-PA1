# CS210 Programming Assignment
## Monopoly Board Simulator (Spring 2026)

### **README**
**Your `README.md` must include:**
- **Build and run instructions.**
- **Description of data structures used.**
- **A complete list of functions with short explanations.**
- **Explanation of traversal and movement logic.**
- **Explicit mention of the 40-space board limit.**

### 
### 
### 


### Build and run instructions:
Build:
- Create GitHub public repository
- Upload provided files into a project folder
- Uploaded my project folder into CLion
- Build CMake project

Run:
- Click the play button the top of CLion Project
- The program will simulate the turns of Monopoly using the main function

### Description of data structures used
MonopolySpace
- Stores the property name, property color, property value, and rent for each space

Node<T>
- Stores a singular peice of data and the nextNode pointer

CircularLinkedList<T>
- headNode points to first space
- tailNode points to last space
- playerNode points to the current space
- nodeCount tracks the spaces
- passGoCount tracks the player's "GO"s

### A complete list of functions with short explanations
- MonopolySpace(): default constructor
- MonopolySpace(string propertyName, string propertyColor, int value, int rent): constructor with space values
- bool isEqual(MonopolySpace other): compares property names of 2 spaces
- void print(): prints board space
- Node(T value): creates a null node
- CircularLinkedList(): empty circular linked list
- bool addSpace(T value): adds a space at the end of the board
- int addMany(vector<T> values): adds multiple spaces till none can be added and returns the number of spaces added
- void movePlayer(int steps): moves the player forward and tracks the number of GOs passed
- int getPassGoCount(): returns the number of times the player passes GO
- void printFromPlayer(int count): Prints the number of spaces starting from the player's position
- void printBoardOnce(): prints the full board one time
- bool removeByName(string name): remove the first space that has the desired name
- vector<string> findByColor(string color): goes through each node and returns the property name of the spaces with that color
- int countSpace(): goes through the linked list once and returns the number of spaces
- void clear(): deletes all the nodes and then the entire list

### Explanation of traversal and movement logic
The board moves by following the next node pointer each node at a time. If a player were to move 5 spaces, then the program would just go through 5 nodes one at a time. Since the board is a circular linked list, the end will just loop back to the start. When a player passes GO, that just means that the player moved from the last node to the first node and the passGoCount will go up one. This makes a circular linked list useful in this case because the whole game of Monopoly is based on moving through a certain amount of spaces and goes in a circle, keeping track of how many times a player makes it around.
So, the code will build a board/circular linked list. The player will start at the beginning/headnode. It will roll a dice and move the player through the board while tracking the times a player passes GO.

### Explicit mention of the 40-space board limit
The board can strictly have 40 spaces, so the code will never let the circular linked list to have more than 40 nodes. When the board is full, the code won't be able to insert any spaces through the addSpace or addMany functions.


