#include <iostream>
using namespace std;

typedef struct Node{
    string songName;
    Node *link;
}Node;

Node *createNode(string data){
    Node *newNode = new Node;
    newNode->songName = data;
    newNode->link = NULL;

    return newNode;
}

Node *insertAtEnd(string data, Node *head){
    if(head == NULL){
        Node *newNode = createNode(data);
        head = newNode;
        cout << "A new node has been inserted at the end \n" << endl;
        return head;
    }
    Node *temp = new Node;
    temp = head;

    while(temp->link != NULL){
    temp = temp->link;

    }   

    Node *newNode = createNode(data);
    temp->link = newNode;

    cout << "A new node has been inserted at the end \n" << endl;
    return head;
}

Node *insertAtBeginning(string data, Node *head){
        Node *newNode = createNode(data);
        newNode->link = head;

        head = newNode;

        cout << "A new node has been inserted at the beginning \n" << endl;

        return head;
    }

string insertAfter(string after,string data, Node *head){
    Node *temp = new Node;
    temp = head;

    while(temp->songName.compare(after) != 0){
        if(temp == NULL){
            return "No such song exist, please try again later.";
        }

        temp = temp->link;
    }
    Node *newNode = createNode(data);
    newNode->link = temp->link;
    temp->link = newNode;

    return "A new node has been added after." + after + "\n";
}


void traverse(Node *head){
    Node *temp = new Node;
    temp = head;

    cout << "My Playlist" << endl;
    while(temp != NULL){
        cout << temp->songName << "->"<< endl;
        if(temp->link == NULL){
            cout << "NULL" << endl;
        }
        
        temp = temp->link;
    }
}


int main(){

    Node *head = createNode("Sanctuary by Joji");

    head = insertAtEnd("Sunday Morning by Maroon 5", head);
    head = insertAtEnd("APT. ROSÉ, Bruno Mars.", head);
    head = insertAtEnd("Lose Control. Teddy Swims", head);
    head = insertAtEnd("Die With A Smile. Lady Gaga, Bruno Mars", head);
    head = insertAtBeginning("Stronger by TheFatRat.", head);
    head = insertAtBeginning("Language of the Lost by Riproducer.", head);
    head = insertAtBeginning("The Drum by Alan Walker.", head);
    head = insertAtBeginning("Show by Ado.", head);
    insertAfter("Show by Ado.", "Sunday", head);
    insertAfter("Language of the Lost by Riproducer.", "hahahka",head);
    insertAfter("The Drum by Alan Walker", "hehehehe",head);
    

    
    traverse(head);

   

    return 0;
}