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
        Node* checkNode;
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
            Node *checkNode = head;
            Node* newNode = new Node(value);
            if(checkNode == NULL){
                cout<<"you do not have a node"<<endl;
                return;
            }
            if(index <= 0){
                cout<<"pls input correct index"<<endl;
                return;
            }
            if(index == 1){
                head = newNode;
                newNode = checkNode;
                head->next = newNode;
                return;
            }
            if(counter == 1){
                current = head;
            }
            if(counter != index){
                counter++;
                previous = current;
                current = current->next;
            }
            if(counter == index){
                Node* newNode = new Node(value);
                previous->next = newNode;
                newNode->next = current;
                counter = 1;
                return;
            }
            if(previous->next == NULL){
                cout<<"you add big index"<<endl;
                counter = 1;
                return;
            }
            addPosition(value,index);
        }

        void deletePosition(int index){
            Node *tmp = head;
            if(tmp == NULL){
                cout<<"you do not have a node"<<endl;
                return;
            }
            if(index <= 0){
                cout<<"pls input correct index"<<endl;
                return;
            }
            if(index == 1){
                head = head->next;
            }
            if(counter == 1){
                current = head;
                if(current == NULL){
                    return;
                }
            }
            if(counter != index){
                previous = current;
                current = current->next;
                counter++;
            }
            if(current->next == NULL){
                counter = 1;
                return;
            }
            if(counter == index){
                previous->next = current->next;
                counter = 1;
                return;
            }
            deletePosition(index);
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
    cout<<"delete 0"<<endl;
    l.deletePosition(0);
    cout<<"delete 0"<<endl;
    cout<<"test 77 0"<<endl;
    l.addPosition(77,0);
    cout<<"Good test 77 0"<<endl;
    cout<<"+++++++++++++++++++++++++++"<<endl;
            cout<<"test 77 123123"<<endl;
    l.addPosition(77,123123123);
    cout<<"Good test 77 123123123"<<endl;
    cout<<"+++++++++++++++++++++++++++"<<endl;
    l.add(10);
    l.add(20);
    l.add(30);
    l.add(40);
    l.add(50);
    l.show(l.head);

    cout<<"test 77 1"<<endl;
    l.addPosition(77,1);
    cout<<"Good test 77 1"<<endl;
    cout<<"+++++++++++++++++++++++++++"<<endl;
    l.show(l.head);
    cout<<" test 99 100"<<endl;
    l.addPosition(99,100);
    cout<<"Good test 99 100"<<endl;
    cout<<"+++++++++++++++++++++++++++"<<endl;
    l.show(l.head);
    cout<<" test 99 7"<<endl;
    l.addPosition(99,6);
    cout<<"Good test 99 7"<<endl;
    cout<<"+++++++++++++++++++++++++++"<<endl;
        l.show(l.head);
    cout<<"+++++++++++++++++++++++++++"<<endl;

};
