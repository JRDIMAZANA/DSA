// Online C++ compiler to run C++ program online
#include <iostream>

using namespace std;

int MyArray[30];
int numElem = 0;
int maxElem = 20;

void traverseArray(){
    cout << "Showing elements in my array \n";
    for(int i = 0; i < maxElem; i++){
       cout << to_string(MyArray[i]) + " | ";
    }
    cout<< "\n";
}

string insertAttheEnd(int num){
    if(numElem != maxElem){
        MyArray[numElem] = num;
        numElem++;
        return "An element is sucessfully inserted at the end \n";
    }
    
    return "The array is full.\n";
}

string insertAttheBeginning(int num){
    if(numElem != maxElem){
        for(int i = numElem; i >= 0; i--){
            MyArray[i+1] = MyArray[i];
        }
        MyArray[0] = num;
        numElem++;
        return "An element is sucessfully inserted at the end \n";
  }
        return "The array is full.\n";
}
 string insertAttheGivePosition(int num, int ElementAfter){
    if(numElem != maxElem){
        int position;
        for(int i = 0; i <= maxElem; i++){
            if(MyArray[i] == ElementAfter){
                position = i;
                break;
            }
        }
        
        for(int i = numElem; i>=position; i--){
            MyArray[i+1] = MyArray[i];
        }
        MyArray[position + 1] = num;
        numElem++; 
        return "An element is sucessfully inserted at the end \n";
    }
    
    return "The array is full.\n";
} 
    
int main() {
    
    insertAttheBeginning(3);
    insertAttheEnd(7);
    insertAttheEnd(9);
    insertAttheBeginning(20);
    insertAttheGivePosition(37,7);
    insertAttheBeginning(256);
    insertAttheGivePosition(128,9);
    insertAttheBeginning(19);
    traverseArray();


    return 0;
}