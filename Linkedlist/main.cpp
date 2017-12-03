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
private:
        Node* tail;
        Node* current;
        Node* previous;
        Node* tmp;
        int counter = 1;

    public:
        Node* head;
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
            else {
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
            counter = 1;
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

            void show(Node* head){
                cout<<head->data<<endl;
                if(head->next != NULL){
                    show(head->next);
                }
                return;
            }
};

int main(){
    LinkedList l;
    l.addPosition(0,0);
    l.add(10);
    l.add(20);
    l.add(30);
    l.add(40);
    l.add(60);
    l.add(70);
    l.add(80);
    l.add(90);
    l.add(100);
    l.show(l.head);
    cout<<"+++++++++++++++++++++++++++"<<endl;
    l.deletePosition(3);
    l.deletePosition(-90000000000);
    l.deletePosition(9090909090909090);
    l.show(l.head);
    cout<<"+++++++++++++++++++++++++++"<<endl;
    l.addPosition(45,3);
    l.addPosition(55,3);
    l.show(l.head);
};
