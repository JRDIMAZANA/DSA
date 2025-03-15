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

string deleteAtEnd(Node *head){
    if(head == NULL){
        return "The linked list is empty \n";
    }

    if(head->link == NULL){
        delete head;
        return "The head has been removed \n"; 
    }

    Node *temp = new Node;
    temp = head;

    while(temp->link->link != NULL){
        temp = temp->link;
    }

    temp->link = NULL;

    return "A node has been deleted at the end \n";
}

Node *deleteFromBeginning(Node *head){
    if(head == NULL){
        cout << "The linked list is empty \n";
        return NULL;
    }

    if(head->link == NULL){
        delete head;
    }

    head = head->link;

    cout << "A node has been deleted from the beginning \n" << endl;

    return head;
}

Node *deleteFromGivenNode(string givenNode,Node *head){
    if(head == NULL){
        cout << "The linked is empty. \n" << endl;
        return NULL;
    }

    if(head->songName.compare(givenNode) == 0){
        head = deleteFromBeginning(head);
        cout << "The Node" + givenNode + "has been deleted. \n" << endl;
        return head;
    }

    Node *temp = new Node;
    Node *next = new Node;
    temp = head;
    next = temp->link;

    while(next->songName.compare(givenNode) != 0){
        if(temp == NULL){
            cout << "No such node exist. \n" << endl;
            return head;
        }
        next = next->link;
        temp = temp->link;
    }

    temp->link = next->link;
    cout << "The Node " + givenNode + " has been deleted \n" << endl;
    return head;

}


void traverse(Node *head){
    Node *temp = new Node;
    temp = head;

    cout << "My Playlist" << endl;
    while(temp != NULL){
        cout << temp->songName << "->"<< endl;
        if(temp->link == NULL){
            cout << head->songName << endl; // Coding Challenge No.2. By replacing "NULL" by "head->songName"
        }
        
        temp = temp->link;
    }
}


int main(){

    Node *head = createNode("Sanctuary by Joji");

    head = insertAtEnd("Sunday Morning by Maroon 5", head);
    head = insertAtEnd("APT. ROSÉ, Bruno Mars.", head);
    head = insertAtEnd("Die With A Smile. Lady Gaga, Bruno Mars", head);
    head = insertAtBeginning("Stronger by TheFatRat.", head);
    head = insertAtBeginning("Language of the Lost by Riproducer.", head);
    head = insertAtBeginning("The Drum by Alan Walker.", head);
    head = insertAtBeginning("Show by Ado.", head);

    string After = insertAfter("Show by Ado.", "Dilaw by Maki", head);
        cout << After << endl;
    string After1 = insertAfter("Show by Ado.", "Bughaw by Maki",head);
        cout << After1 << endl;
    string After2 = insertAfter("Show by Ado.", "Medyo Ako by Juan Karlos",head);
        cout << After2 << endl;

    deleteAtEnd(head);
    head = deleteFromBeginning(head);
    head = deleteFromGivenNode("Language of the Lost by Riproducer.",head);

    
    
    traverse(head);
  

   

    return 0;
}