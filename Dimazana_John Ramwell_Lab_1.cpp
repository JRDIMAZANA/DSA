
// Online C++ compiler to run C++ program online
#include <iostream>

using namespace std;

int MyArray[30];
int numElem = 0;
int maxElem = 20;

void bubbleSort(){
    int i, j;
    bool swapped;
    for(int i =0; i < numElem - 1; i++){
        swapped = false;
        for(j = 0; j < numElem - i -1; j++){
            if(MyArray[j] > MyArray[j+1]){
                swap(MyArray[j], MyArray[j+1]);
                swapped = true;
            }
        }
        if(swapped == false){
            break;
        }
    }
}

int binarySearch(int num, int lowest, int highest){
    while(lowest <= highest){
        int middle = lowest + (highest - lowest) /2;

        if(MyArray[middle] == num){
          return middle;  
        }
        if(MyArray[middle] < num){
            lowest = middle + 1;
        }else{
            highest = middle - 1;
        }
    }
     return -1;
}

void traverseArray(){
    cout << "Showing elements in my array \n";
    for(int i = 0; i < numElem; i++){
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

string insertAtSortedArray(int num){
    if(numElem != maxElem){
        bubbleSort();
        int position;
        for(int i = 0; i < numElem; i++){
            if(num < MyArray[i]){
                position = i;
                break;
            }
        }
        for(int i = numElem; i >= position; i--){
            MyArray[i+1] = MyArray[i];
        }
        MyArray[position] = num;
        numElem++;
        return "An element is sucessfully inserted at the sorted array \n";
    }
    return "The Array is full. \n";
}

string deleteFromtheEnd(){
    if(numElem != 0){
        numElem--;
        return "An element has been eleted from the end!";
    }
    return "The array is underflow!";
}

string deleteFromtheBeginning(){
    if(numElem != 0){
        for(int i = 0; i<= numElem; i++){
        MyArray[i] = MyArray[i+1];
        }
        numElem--;
        return "An element has been eleted from the end!";
    }
    return "The array is underflow!";
}

string deleteFromtheGivenElement(int element){
    if(numElem != 0){
        int index;
        for(int i = 0; i<= numElem; i++){
            if(MyArray[i] == element){
                index = i;
                break;
            }
        }
        for(int i = index; i <=numElem; i++){
            MyArray[i] = MyArray[i+1];
        }
        numElem--;
        return to_string(element) + "deleted from the end!";
    }
    return "The array is underflow!";
}






    
int main(){
    
    insertAttheBeginning(3);
     traverseArray();
    insertAttheEnd(7);
     traverseArray();
    insertAttheEnd(9);
     traverseArray();
    insertAttheBeginning(20);
     traverseArray();
    insertAttheGivePosition(37,7);
     traverseArray();
    insertAttheBeginning(256);
     traverseArray();
    insertAttheGivePosition(128,9);
     traverseArray();
    insertAttheBeginning(19);
     traverseArray();

    insertAtSortedArray(3);
    traverseArray();
    insertAtSortedArray(30);
    traverseArray();
    insertAtSortedArray(38);
    traverseArray();
    insertAtSortedArray(19);
    traverseArray();


    cout << binarySearch(20,0,numElem) << endl;
         traverseArray();
     cout << binarySearch(38,0,numElem) << endl;
        traverseArray();
   
   

  
   
    return 0;
}
