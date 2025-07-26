
// LinkedList Code Series
#include <iostream>
using namespace std;
// Declaring the structure of the Nodes in Linkedlist
class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};
// Function to Dsiplay the LinkedList 
void show(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    };
    cout << endl;
};
// Main Function
int main()
{
    int num, n;

    cout << "Enter the number of elements";
    cin >> n;

    Node *head = nullptr;
    Node *temp = nullptr;
    Node *tail = nullptr;

    if (n <= 0)
    {
        cout << "Linkedlist cannot have zero elements" << endl;
        return 0;
    }

    // Creating linkedList.
    cout << "Enter the elements of linkedlist :" << endl;
    for (int i = 1; i <= n; i++)
    {
        int val;
        cin >> val;
        Node *newNode = new Node(val);

        if (!head)
        {
            head = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }
    // Updating the Tail pointer to the last Node.
    tail = temp;

    
    while (true)
    {
        cout << "Enter number from 1-4 for further task:\n"
             << "1. Show the Entered linked list.\n"
             << "2. Add an element in the beginning.\n"
             << "3. Add an element in the last.\n"
             << "4. Remove First element.\n"
             << "5. Remove Last element.\n"
             << "6. To exit the code.";

        cin >> num;

        switch (num)
        {
        case 1:
        {
            // Case 1 to display the linkedlist.
            cout << "you Selected: case 1 to show the entered linkedlist.\n";
            show(head);
            break;
        }
        case 2:
        {
            // Case 2 to add the element in the start of the linkedList.
            int first;
            cout << "enter the element you want to add" << endl;
            cin >> first;

            Node *first_ele = new Node(first);
            if (!head)
            {
                head = tail = first_ele;
            }
            else
            {
                first_ele->next = head;
                head = first_ele;
            }

            cout << "Updated LinkedList :" << endl;
            show(head);

            break;
        }
        case 3:
        {
            // Case 3 to add to element in the last of the linkedList.
            int last;
            cout << "enter the element you want to add in the last" << endl;
            cin >> last;
            Node *last_ele = new Node(last);
            if (!head)
            {
                // Empty list case — update both head and tail
                head = tail = last_ele;
            }
            // add the element and Udate the tail.
            else
            {
                tail->next = last_ele;
                tail = last_ele;
            }

            cout << "Updated Linkedlist" << endl;
            show(head);
        }
        break;
        case 4:
        {
            // Remove first element from the linkedList.

            if (!head)
            {
                cout << "LinkedList is empty!" << endl;
                continue;
            }

            Node *toDelete = head;
            head = head->next;
            delete toDelete;

            if (!head)
                tail = nullptr; //  Update tail if list becomes empty

            cout << "First element removed. Updated list: ";
            show(head);
            break;
        }
        case 5: {
            // Remove the last element from the linkedList.
            if (!head)
            {
                cout << "LinkedList is empty!" << endl;
                continue;
            }

            if(head == tail){
                delete tail;
                head = tail = nullptr;
            }
            else{
                Node* curr = head;
                while(curr->next!= tail){
                    curr = curr->next;
                }
                delete tail;
                curr->next = nullptr;
                tail = curr;
            }
            
            if (!head)
                tail = nullptr; // Update tail if list becomes empty

            show(head);
            break;
        }
        case 6:
        // Exit the Program.
            cout << "exit";
            return 0;
        default:
            cout << "Invalid input.\n";
        }
    }
    return 0;
}