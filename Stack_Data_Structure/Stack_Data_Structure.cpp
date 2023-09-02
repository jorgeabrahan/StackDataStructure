#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Stack.h"
using namespace std;

int main()
{
    string filePath;
    cout << "Ingresa la dirección del archivo con el código fuente:"<<endl;
    cout << "> ";
    getline(cin, filePath);

    ifstream InterpreterFile(filePath);
    if (!InterpreterFile) {
        cerr << "---- Archivo no encontrado ----" << endl;
        return 1;
    }
    string text; // variable to store the first line of the text file
    getline(InterpreterFile, text); // get the first line from the text file and save it in "text"
    InterpreterFile.close(); // close the file

    vector<string> elements;
    size_t pos = 0; // variable to store position of commas
    string separator = " "; // variable that indicates the separator within elements in the text
    while ((pos = text.find(separator)) != string::npos) { // while there's still a comma in the text
        elements.push_back(text.substr(0, pos)); // add element to the vector
        text.erase(0, pos + separator.length()); // remove element from the text
    }
    elements.push_back(text); // add the last element in the text to the vector

    Stack stack;
    for (const auto& element : elements) {
        if (element == ">>") {
            float number;
            cout << "Ingrese un valor:" << endl;
            cout << "> ";
            // while user is not typing a valid number
            while (!(cin >> number)) {
                cout << "ERROR. Porfavor ingrese un numero valido:" << endl; // ask user to input a number again
                cout << "> ";
                cin.clear(); // clear error status from standard input to allow a new input
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear invalid input from buffer
            }
            stack.push(number); // add number to stack
            continue;
        }

        // --------- Basic methods --------- //
        if (element == "TOP") { cout << "(top) returned: " << stack.top() << endl; continue; }
        if (element == "POP") { cout << "(pop) returned: " << stack.pop() << endl; continue; }

        // --------- Management methods --------- //
        if (element == "CLEAR") { stack.clear(); continue; }
        if (element == "DEPTH") { stack.depth(); continue; }
        if (element == "DROP") { stack.drop(); continue; }
        if (element == "DROPN") { stack.dropn(); continue; }
        if (element == "DUP") { stack.dup(); continue; }
        if (element == "DUPN") { stack.dupn(); continue; }
        if (element == "PICK") { stack.pick(); continue; }
        if (element == "ROLLD") { stack.rolld(); continue; }
        if (element == "ROLLU") { stack.rollu(); continue; }
        if (element == "SHOW") { cout << stack; continue; }
        if (element == "SWAP") { stack.swap(); continue; }

        // --------- Operation methods --------- //
        if (element == "+") { stack.add(); continue; }
        if (element == "-") { stack.sub(); continue; }
        if (element == "/") { stack.div(); continue; }
        if (element == "*") { stack.mult(); continue; }
        if (element == "^") { stack.pot(); continue; }


        try {
            // if the element is a number
            float number = stof(element);
            stack.push(number);
            continue;
        }
        catch (const invalid_argument&) {
            // the element is Not a number
        }
        cout << "La instruccion \"" << element << "\" no es valida!" << endl;
    }

    return 0;
}