#include <iostream>
#include <string>
using namespace std;

#define MAX 100

class TextEditor {
    string stack[MAX];
    int top;

public:
    
    TextEditor() {
        top = -1;
    }

    // Push: Add a new editing action
    void push(string action) {
        if (top == MAX - 1) {
            cout << "Stack is full!\n";
        } else {
            stack[++top] = action;
            cout << "Action added successfully!\n";
        }
    }

    // Pop: Undo the latest action
    void undo() {
        if (top == -1) {
            cout << "Nothing to Undo! No previous actions.\n";
        } else {
            cout << "Undoing action: " << stack[top] << endl;
            top--;
        }
    }

    // Display all editing actions
    void display() {
        if (top == -1) {
            cout << "No editing actions available.\n";
            return;
        }

        cout << "\nEditing Actions:\n";
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << endl;
        }
    }

    // Peek: Display the latest action
    void peek() {
        if (top == -1) {
            cout << "No actions available.\n";
        } else {
            cout << "Latest Action: " << stack[top] << endl;
        }
    }
};

int main() {
    TextEditor editor;
    int choice;
    string action;

    do {
        cout << "\n===== TEXT EDITOR UNDO SYSTEM =====\n";
        cout << "1. Write Text\n";
        cout << "2. Delete Text\n";
        cout << "3. Insert Sentence\n";
        cout << "4. Modify Text\n";
        cout << "5. Copy Text\n";
        cout << "6. Display Editing Actions\n";
        cout << "7. Undo Last Action\n";
        cout << "8. Show Latest Action (Peek)\n";
        cout << "9. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter text to write: ";
                getline(cin, action);
                editor.push("Write: " + action);
                break;

            case 2:
                cout << "Enter text to delete: ";
                getline(cin, action);
                editor.push("Delete: " + action);
                break;

            case 3:
                cout << "Enter sentence to insert: ";
                getline(cin, action);
                editor.push("Insert: " + action);
                break;

            case 4:
                cout << "Enter modified text: ";
                getline(cin, action);
                editor.push("Modify: " + action);
                break;

            case 5:
                cout << "Enter text to copy: ";
                getline(cin, action);
                editor.push("Copy: " + action);
                break;

            case 6:
                editor.display();
                break;

            case 7:
                editor.undo();
                break;

            case 8:
                editor.peek();
                break;

            case 9:
                cout << "Exiting Text Editor Undo System.\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 9);

    return 0;
}
