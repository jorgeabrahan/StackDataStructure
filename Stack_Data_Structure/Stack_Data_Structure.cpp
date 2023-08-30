#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Stack.h"
using namespace std;

int main()
{
    string text; // variable to store the first line of the text file
    ifstream InterpreterFile("Interpreter.txt"); // Create ifstream object from the txt file
    getline(InterpreterFile, text); // get the first line from the text file and save it in "text"
    InterpreterFile.close(); // close the file

    vector<string> elements;
    size_t pos = 0; // variable to store position of commas
    string separator = ","; // variable that indicates the separator within elements in the text
    while ((pos = text.find(separator)) != string::npos) { // while there's still a comma in the text
        elements.push_back(text.substr(0, pos)); // add element to the vector
        text.erase(0, pos + separator.length()); // remove element from the text
    }
    elements.push_back(text); // add the last element in the text to the vector

    Stack stack;
    for (const auto& element : elements) {
        if (element == ">>") {
            float number;
            cout << "Insert a number: " << endl;
            // while user is not typing a valid number
            while (!(cin >> number)) {
                cout << "ERROR. Please enter a valid number: " << endl; // ask user to input a number again
                cin.clear(); // clear error status from standard input to allow a new input
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear invalid input from buffer
            }
            stack.push(number); // add number to stack
            continue;
        }
        if (element == "<<") { cout << stack; continue; }

        // --------- Basic methods --------- //
        if (element == "drop") { stack.drop(); continue; }
        if (element == "top") { cout << "(top) returned: " << stack.top() << endl; continue; }
        if (element == "pop") { cout << "(pop) returned: " << stack.pop() << endl; continue; }

        // --------- Management methods --------- //
        if (element == "swap") { stack.swap(); continue; }
        if (element == "dup") { stack.dup(); continue; }
        if (element == "depth") { stack.depth(); continue; }
        if (element == "pick") { stack.pick(); continue; }
        if (element == "dupn") { stack.dupn(); continue; }
        if (element == "dropn") { stack.dropn(); continue; }
        if (element == "rolld") { stack.rolld(); continue; }
        if (element == "rollu") { stack.rollu(); continue; }
        if (element == "clear") { stack.clear(); continue; }

        // --------- Operation methods --------- //
        if (element == "add") { stack.add(); continue; }
        if (element == "sub") { stack.sub(); continue; }
        if (element == "div") { stack.div(); continue; }
        if (element == "mult") { stack.mult(); continue; }
        if (element == "pot") { stack.pot(); continue; }


        try {
            // if the element is a number
            float number = stof(element);
            stack.push(number);
            continue;
        }
        catch (const invalid_argument&) {
            // the element is Not a number
        }
        cout << "The string \"" << element << "\" is not a valid stack instruction!" << endl;

    }

    return 0;
}