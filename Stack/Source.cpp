#include <iostream>
using namespace std;

template <typename T>

struct Node
{
    T data;
    Node* next;
};

template <typename T>
class Stack
{
private:
    Node<T>* top;
    int count;

public:
    Stack() : top(nullptr), count(0) {}

    ~Stack()
    {
        Clear();
    }

    void Push(T data)
    {
        Node<T>* newNode = new Node<T>;
        newNode->data = data;
        newNode->next = top;
        top = newNode;
        count++;
    }

    void Pop()
    {
        if (IsEmpty())
        {
            cout << "Stack is empty, nothing to pop." << endl;
            return;
        }
        Node<T>* temp = top;
        top = top->next;
        delete temp;
        count--;
    }

    T Peek() const
    {
        if (IsEmpty())
        {
            throw runtime_error("Stack is empty, nothing to peek.");
        }
        return top->data;
    }

    bool IsEmpty() const
    {
        return top == nullptr;
    }

    void Clear()
    {
        while (!IsEmpty())
        {
            Pop();
        }
    }

    int GetCount() const
    {
        return count;
    }
};

int main()
{
    Stack<char> stack;

    stack.Push('H');
    stack.Push('e');
    stack.Push('l');
    stack.Push('l');
    stack.Push('o');

    cout << "Top element of the stack: " << stack.Peek() << endl;
    cout << "Number of elements in the stack: " << stack.GetCount() << endl;

    stack.Pop();
    stack.Pop();
    cout << "Top element of the stack after popping: " << stack.Peek() << endl;
    cout << "Number of elements in the stack after popping: " << stack.GetCount() << endl;

    stack.Clear();
    cout << "Stack cleared. Is the stack empty? " << (stack.IsEmpty() ? "Yes" : "No") << endl;

    return 0;
}