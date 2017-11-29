#include <iostream>

using namespace std;

class Node{
public:
    Node* prev;
    Node* next;
    int data;

    Node(int data){
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

class LinkedList{
    public:
        Node* firstNode = NULL;

        void add (int n, Node* node = NULL){
            if(node == NULL){
                node = new Node(n);
                return;
            }

            if(node->next != NULL){
                add(n, node->next);
            }

            Node* newNode = new Node(n);
            node->next = newNode;
        }

        void show(Node* n){
            cout<<n->data<<endl;
            if(n->next != NULL){
                show(n->next);
            }
        }
};

int main()
{

 LinkedList l;
    l.add(12, l.firstNode);
    l.add(23, l.firstNode);
    l.add(27, l.firstNode);

    l.show(l.firstNode);
}
