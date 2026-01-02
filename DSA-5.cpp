#include <iostream>
using namespace std;

class StackBase {
public:
    virtual void push(int value) = 0;
    virtual void pop() = 0;
    virtual void topElement() = 0;
    virtual void isEmpty() = 0;
    virtual void isFull() = 0;
    virtual void display() = 0;  
};

class Stack : public StackBase {
private:
    int arr[5];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int value) {
        if (top == 4) {
            cout << "stack is full\n";
        } else {
            top++;
            arr[top] = value;
            cout << value << " pushed into stack\n";
        }
    }

    void pop() {
        if (top == -1) {
            cout << "stack is empty\n";
        } else {
            cout << arr[top] << " popped from stack\n";
            top--;
        }
    }

    void topElement() {
        if (top == -1) {
            cout << "stack is empty\n";
        } else {
            cout << "top element is: " << arr[top] << endl;
        }
    }

    void isEmpty() {
        if (top == -1)
            cout << "stack is empty\n";
        else
            cout << "stack is not empty\n";
    }

    void isFull() {
        if (top == 4)
            cout << "stack is full\n";
        else
            cout << "stack is not full\n";
    }

    void display() {
        if (top == -1) {
            cout << "stack is empty\n";
        } else {
            cout << "stack elements are:\n";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << endl;
            }
        }
    }
};

int main() {
    StackBase* s = new Stack();

    int choice, value;

    do {
        cout << "\n--Stack Menu--\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Top Element\n";
        cout << "4. Is Empty\n";
        cout << "5. Is Full\n";
        cout << "6. Display Stack\n";  
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "enter value: ";
            cin >> value;
            s->push(value);
            break;

        case 2:
            s->pop();
            break;

        case 3:
            s->topElement();
            break;

        case 4:
            s->isEmpty();
            break;

        case 5:
            s->isFull();
            break;

        case 6:
            s->display();
            break;

        case 0:
            cout << "exit\n";
            break;

        default:
            cout << "invalid choice\n";
        }

    } while (choice != 0);

    return 0;
}
