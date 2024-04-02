#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
struct Node
{
    double value;
    struct Node *next;
};

struct Node *makeNumbers(int N);
void printNumbers(struct Node *head);
int getLength(struct Node *head);
struct Node *sortNumbers(struct Node *head);
struct Node *swapNode(struct Node *prev, struct Node *ptr);

struct Node *makeNumbers(int N)
{
    struct Node *head = nullptr;
    struct Node *current = nullptr;

    for (int i = 0; i < N; ++i)
    {
        // Create a new node
        struct Node *newNode = new Node;

        // Generate a random value and assign it to the node
        newNode->value = static_cast<double>(rand()) / RAND_MAX;

        // Link the new node
        newNode->next = nullptr;
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            current->next = newNode;
        }
        current = newNode;
    }

    return head;
}

void printNumbers(struct Node *head)
{
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->value << "\t";
        ptr = ptr->next;
    }
    cout << endl;
}

int getLength(struct Node *head)
{
    int length = 0;
    while (head != nullptr)
    {
        ++length;
        head = head->next;
    }
    return length;
}

struct Node *sortNumbers(struct Node *head)
{
    struct Node *sortedList = nullptr;

    // Traverse the original list
    while (head != nullptr)
    {
        struct Node *current = head;
        head = head->next;

        // Find the correct position to insert current node in sortedList
        if (sortedList == nullptr || current->value < sortedList->value)
        {
            current->next = sortedList;
            sortedList = current;
        }
        else
        {
            struct Node *temp = sortedList;
            while (temp->next != nullptr && temp->next->value <= current->value)
            {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
    }

    return sortedList;
}

struct Node *swapNode(struct Node *prev, struct Node *ptr)
{
      if (prev == nullptr)
        return ptr;

    struct Node *nextNode = ptr->next;
    ptr->next = nextNode->next;
    nextNode->next = ptr;
    prev->next = nextNode;

    return nextNode;
}