#include <iostream>
using namespace std;

class SimpleNode
{
public:
    int value;    
    SimpleNode* link; 
};

void insert(SimpleNode* &start, int num)
{
    SimpleNode* newNode = new SimpleNode();
    newNode->value = num;
    newNode->link = start;
    start = newNode;

    cout << "\t node inserted at beggining" << endl;
}

void updateNode(SimpleNode* start, int oldNum, int newNum)
{
    SimpleNode* temp = start;

    while (temp != NULL)
    {
        if (temp->value == oldNum)
        {
            temp->value = newNum;
            cout << "\t\value updated successfully." << endl;
            return;
        }
        temp = temp->link;
    }

    cout << "\tvalue not found." << endl;
}

void deleteNode(SimpleNode* &start, int delNum)
{
    if (start == NULL)
    {
        cout << "\tlist is empty." << endl;
        return;
    }

    if (start->value == delNum)
    {
        SimpleNode* temp = start;
        start = start->link;
        delete temp;
        cout << "\t\tnode deleted successfully." << endl;
        return;
    }

    SimpleNode* prevNode = start;
    SimpleNode* currNode = start->link;

    while (currNode != NULL)
    {
        if (currNode->value == delNum)
        {
            prevNode->link = currNode->link;
            delete currNode;
            cout << "\tnode deleted successfully." << endl;
            return;
        }
        prevNode = currNode;
        currNode = currNode->link;
    }

    cout << "\t\tvalue not found." << endl;
}

void reverseList(SimpleNode* &start)
{
    SimpleNode* prevNode = NULL;
    SimpleNode* currNode = start;
    SimpleNode* nextNode = NULL;

    while (currNode != NULL)
    {
        nextNode = currNode->link;
        currNode->link = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }

    start = prevNode;
    cout << "\t\tlinked list reversed." << endl;
}

void display(SimpleNode* start)
{
    if (start == NULL)
    {
        cout << "\t\tlist is empty." << endl;
        return;
    }

    SimpleNode* temp = start;
    cout << "\t\tlinked List: ";
    while (temp != NULL)
    {
        cout << temp->value << "  ";
        temp = temp->link;
    }
}

int main()
{
    SimpleNode* start = NULL;
    int option, num, oldNum, newNum;

    do
    {
        cout << endl << endl;
        cout << "\t linked list menu "<< endl;
        cout << "1. insert at Beginning"<< endl;
        cout << "2. update node" << endl;
        cout << "3. delete node" << endl;
        cout << "4. reverse list" << endl;
        cout << "5. Display list" << endl;
        cout << "6. exit" << endl << endl;
        cout << "enter your choice : ";
        cin >> option;

        switch (option)
        {
        case 1:
            cout << "enter value : ";
            cin >> num;
            insert(start, num);
            break;

        case 2:
            cout << "enter old value : ";
            cin >> oldNum;
            cout << "enter new value : ";
            cin >> newNum;
            updateNode(start, oldNum, newNum);
            break;

        case 3:
            cout << "enter value to delete : ";
            cin >> num;
            deleteNode(start, num);
            break;

        case 4:
            reverseList(start);
            break;

        case 5:
            display(start);
            break;

        case 6:
            cout << "exiting program." << endl;
            break;

        default:
            cout << "invalid choice." << endl;
        }

    } while (option != 6);

    return 0;
}
