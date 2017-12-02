#include <iostream>

using namespace std;

class Node{
    public:

    Node* next;
    int data;

    Node(int data){
    this->data = data;
    next = NULL;
    }

};

class LinkedList{
    public:
        Node* head;
        Node* tail;
        Node* current;
        Node* previous;
        int length = 0;
        int counter = 1;
        LinkedList(){
            head = NULL;
            tail = NULL;
        };

        void add(int value){
            Node* newNode = new Node(value);
            if(head == NULL){
                head = newNode;
                tail = newNode;
                return;
            }
            else{
                tail->next = newNode;
                tail = newNode;
                return;
            }
        }

        void addPosition(int value,int index){
            if(counter == 1){
                current = head;
            }
            if(counter != index){
                counter++;
                previous = current;
                current = current->next;
                addPosition(value,index);
            }
            Node* newNode = new Node(value);
            previous->next = newNode;
            newNode->next = current;
        }

        void deletePosition(int index){
            if(counter == 1){
                current = head;
            }
            if(counter != index){
                counter++;
                previous = current;
                current=current->next;
                deletePosition(index);
            }
            previous->next = current->next;
            counter = 1;
        }

            void show(Node* n){
                cout<<n->data<<endl;
                if(n->next != NULL){
                    show(n->next);
                }
                return;
            }
};

int main(){
    LinkedList l;
    l.add(10);
    l.add(20);
    l.add(30);
    l.add(40);
    l.add(50);
    l.show(l.head);
    cout<<"+++++++++++++++++++++++++++"<<endl;
    l.deletePosition(3);
    l.show(l.head);
    cout<<"+++++++++++++++++++++++++++"<<endl;
    l.addPosition(45,3);
    l.show(l.head);
};
