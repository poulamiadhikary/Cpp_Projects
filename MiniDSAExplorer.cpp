#include<iostream>
#include<vector>
using namespace std;

class Array{
public:

    int size = 0;
    int arr[10];
    int orgArr[10];

    void addArray(){
        cout<<"Enter the size of the array: ";
        cin>>size;
        arr[size];
        orgArr[size];
        cout<<"Enter array elements: ";
        for(int i=0; i<size; i++){
            cin>>arr[i];
            orgArr[i] = arr[i];
        }
        cout<<"ARRAY CREATED !"<<endl;
    }

    void displayArray(){

        if(size==0){
            cout<<"ARRAY IS EMPTY !"<<endl;
            return;
        }

        cout<<"Array Elements: ";
        for(int i=0; i<size; i++){
            cout<<orgArr[i]<<" ";
        }
        cout<<endl;
    }

    void reverseArray(){
        int start = 0, end = size-1;

        cout<<"Original array elements: ";
        for(int i=0; i<size; i++){
            cout<<orgArr[i]<<" ";
        }
        cout<<endl;

        while(start<end){
            swap(arr[start], arr[end]);
            start++;
            end--;
        }

        cout<<"Array Elements after reverse: ";
        for(int i=0; i<size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;

        for(int i=0; i<size; i++){
            arr[i] = orgArr[i];
        }
    }

    void arrayAlternateSwap(){

        cout<<"Original array elements: ";
        for(int i=0; i<size; i++){
            cout<<orgArr[i]<<" ";
        }
        cout<<endl;

        for(int i=0; i<size; i+=2){
            if(i+1<size){
                swap(arr[i], arr[i+1]);
            }
        }

        cout<<"Array Elements after alternate swap: ";
        for(int i=0; i<size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void arrayMiddleElement(){
        int midIndex, midElement;

        if(size/2!=0){
            midIndex = size/2;
            midElement = orgArr[midIndex];
            cout<<"Middle element is: "<<midElement<<endl;
        }
        else{
            midIndex = (size/2) -1;
            int midIndex2 = size/2;
            cout<<"Middle elements are: "<<orgArr[midIndex]<<" and "<<orgArr[midIndex2]<<endl;
        }
    }

    void arrayMinimumElement(){
        int minElement = orgArr[0];

        for(int i=0; i<size-1; i++){
            if(orgArr[i]<minElement){
                minElement = arr[i];
            }
        }

        cout<<"Minimum element is: "<<minElement<<endl;
    }

    void arrayMaximumElement(){
        int maxElement = orgArr[0];

        for(int i=0; i<size; i++){
            if(orgArr[i]>maxElement){
                maxElement = orgArr[i];
            }
        }

        cout<<"Minimum element is: "<<maxElement<<endl;
    }
};

class Node{
public:
    int data;
    Node *next;

    Node(int d){
        data = d;
        next = NULL;
    }
};

class LinkedList{
public: 
    Node *head = NULL;

    void insertNodeAtBeginning(){
        int val;
        cout<<"Enter node value: ";
        cin>>val;

        if(head==NULL){
            head = new Node(val);
            head->next = NULL;
            cout<<"NODE ADDED !"<<endl;
        }
        else{
            Node *temp = new Node(val);
            temp->next = head;
            head = temp;
            cout<<"NODE INSERTED AT BEGINNING !"<<endl;
        }

    }

    void insertNodeAtEnd(){
        int val;
        cout<<"Enter node value: ";
        cin>>val;

        if(head==NULL){
            head = new Node(val);
            head->next = NULL;
            cout<<"NODE ADDED !"<<endl;
        }
        else{
            Node *temp = head;
            while(temp->next!=NULL){
                temp = temp->next;
            }
            temp->next = new Node(val);
            cout<<"NODE INSERTED AT END ! "<<endl;
        }
    }

    void deleteNodeAtBeginning(){

        if(head == NULL){
            cout<<"LINKED LIST IS EMPTY !"<<endl;
            return;
        }
        else{
            Node *temp = head;
            head = head->next;
            delete temp;
            cout<<"NODE DELETED FROM BEGINNING !"<<endl;
        }
    }

    void deleteNodeAtEnd(){

        if(head == NULL){
            cout<<"LINKED LIST IS EMPTY !"<<endl;
            return;
        }
        else{
            Node *temp = head;
            while(temp->next->next != NULL){
                temp = temp->next;
            }
            delete temp->next;
            temp->next = NULL;
            cout<<"NODE DELETED FROM END !"<<endl;
        }
    }

    void displayList(){

        if(head==NULL){
            cout<<"LINKED LIST IS EMPTY !"<<endl;
            return;
        }
        Node *temp = head;
        while(temp!=NULL){
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

class Search : public Array{
public:
    void linearSearch(){
        int elem;
        char choice;
        int newSize;
        bool found = false;

        cout<<"Enter the element you want to search in the array: ";
        cin>>elem;

        if(size==0){
            cout<<"ARRAY IS EMPTY: ";
            cout<<"Do you want to add elements in array ? (y - yes | n - no): ";
            cin>>choice;
            if(choice == 'y' || choice =='Y'){
                cout<<"Enter size of the array: ";
                cin>>newSize;
                size = newSize;
                orgArr[newSize];

                cout<<"Enter array elements: ";
                for(int i=0; i<newSize; i++){
                    cin>>orgArr[i];
                    arr[i] = orgArr[i];
                }
                cout<<"ARRAY CREATED ! "<<endl;
            }
            return;
        }
        else{
            for(int i=0; i<size; i++){
                if(orgArr[i]==elem){
                    found = true;
                    cout<<"Element found at index "<<i<<" by linear search"<<endl;
                    break;
                }
            }
            if(!found){
                cout<<"Element not found !"<<endl;
            }
        }

    }

    void binarySearch(){
        int start = 0, end = size - 1;
        int mid, elem, choice, newSize;
        bool found = false;

        cout<<"Enter the element you want to search in the array: ";
        cin>>elem;

        if(size==0){
            cout<<"ARRAY IS EMPTY: ";
            cout<<"Do you want to add elements in array ? (y - yes | n - no): ";
            cin>>choice;
            if(choice == 'y' || choice =='Y'){
                cout<<"Enter size of the array: ";
                cin>>newSize;
                size = newSize;
                orgArr[newSize];
                for(int i=0; i<newSize; i++){
                    cin>>orgArr[i];
                    arr[i] = orgArr[i];
                }
                cout<<"ARRAY CREATED ! "<<endl;
            }
            return;
        }
        else{
            while(start<=end){
                mid = start+(end-start)/2;

                if(orgArr[mid]==elem){
                    cout<<"Element found at index "<<mid<<" by binary search"<<endl;
                    found = true;
                    break;
                }
                else if(elem>orgArr[mid]){
                    start = mid+1;
                }
                else{
                    end = mid-1;
                }
            }
            if(!found){
                cout<<"Element not found !"<<endl;
            }
        }
    }
};

class Sort : public Array{
public:
    
    void bubbleSort(){
        
        char choice;
        int newSize = size;

        if(newSize == 0){
            cout<<"ARRAY IS EMPTY ! "<<endl;
            cout<<"Do you want to add elements in array ? (y - yes | n - no): ";
            cin>>choice;

            if(choice =='y' || choice=='Y'){
                addArray();
                newSize = size;
            }
            else{
                return;
            }
           
        }

        cout<<"Original array: ";
        for(int i=0; i<newSize; i++){
            cout<<orgArr[i]<<" ";
        }
        cout<<endl;

            for(int i=0; i<size; i++){
                for(int j=0; j<size-1; j++){
                    if(orgArr[j]>orgArr[j+1]){
                        swap(orgArr[j], orgArr[j+1]);
                    }
                }
            }

            cout<<"Array after bubble sort: ";
            for(int i=0; i<size; i++){
                cout<<orgArr[i]<<" ";
            }
        cout<<endl;
    }

    void insertionSort(){
        char choice;
        int newSize = size;

        if(newSize == 0){
            cout<<"ARRAY IS EMPTY ! "<<endl;
            cout<<"Do you want to add elements in array ? (y - yes | n - no): ";
            cin>>choice;

            if(choice =='y' || choice=='Y'){
                addArray();
                newSize = size;
            }
            else{
                return;
            }
        
        }

        cout<<"Original array: ";
            for(int i=0; i<newSize; i++){
                cout<<orgArr[i]<<" ";
            }
            cout<<endl;

            for(int i=1; i<size; i++){
                for(int j=i; j>0; j--){
                    if(orgArr[j]<orgArr[j-1]){
                        swap(orgArr[j], orgArr[j-1]);
                    }
                }
            }

            cout<<"Array after insertion sort: ";
            for(int i=0; i<size; i++){
                cout<<orgArr[i]<<" ";
            }
            cout<<endl;
        
    }

    void selectionSort(){
        char choice;
        int newSize = size;

        if(newSize == 0){
            cout<<"ARRAY IS EMPTY ! "<<endl;
            cout<<"Do you want to add elements in array ? (y - yes | n - no): ";
            cin>>choice;

            if(choice =='y' || choice=='Y'){
                addArray();
                newSize = size;
            }
            else{
                return;
            }
            
          
        }
        
        cout<<"Original array: ";
            for(int i=0; i<newSize; i++){
                cout<<orgArr[i]<<" ";
            }
            cout<<endl;

        for(int i=0; i<size-1; i++){
                int min = i;
                for(int j=i+1; j<size; j++){
                    if(orgArr[j]<orgArr[min]){
                        min = j;
                    }
                }
                swap(orgArr[i], orgArr[min]);
            }

            cout<<"Array after selection sort: ";
            for(int i=0; i<size; i++){
                cout<<orgArr[i]<<" ";
            }
            cout<<endl;
    }

    void mergeSort2(int start, int end){
        if(start < end){
            int mid = start + (end - start) / 2;
            mergeSort2(start, mid);
            mergeSort2(mid + 1, end);
            merge(start, mid, end);
        }
    }

    void merge(int start, int mid, int end){
    
    int temp[end-start+1];
    int left = start;
    int right = mid+1;
    int index = 0;
    
    while(left<=mid && right<=end){
        if(orgArr[left]<orgArr[right]){
            temp[index] = orgArr[left];
            index++;
            left++;
        }
        else{
            temp[index]=orgArr[right];
            index++;
            right++;
        }
    }
    while(left<=mid){
        temp[index]=orgArr[left];
        index++;
        left++;
    }
    while(right<=end){
        temp[index]=orgArr[right];
        index++;
        right++;
    }
    
    index = 0;
    for(int i=start; i<=end; i++){
        orgArr[i]=temp[index];
        index++;
    }
    
    }

    void mergeSort(){
        char choice;
        int newSize = size;

        if(newSize == 0){
            cout<<"ARRAY IS EMPTY ! "<<endl;
            cout<<"Do you want to add elements in array ? (y - yes | n - no): ";
            cin>>choice;

            if(choice =='y' || choice=='Y'){
                addArray();
                newSize = size;
            }
            else{
                return;
            }
            
        }
        

            cout<<"Original array: ";
            for(int i=0; i<newSize; i++){
                cout<<orgArr[i]<<" ";
            }
            cout<<endl;

            mergeSort2(0, size-1);
            
            cout<<"Array after merge sort: ";
            for(int i=0; i<size; i++){
                cout<<orgArr[i]<<" ";
            }
            cout<<endl;

    }
};

class Stack{
public: 
    int size = 10, top = -1;
    int arrStack[100];
    int elem;

    void pushElement(){
        arrStack[size];
        cout<<"Enter element to push: ";
        cin>>elem;

        if(top == size-1){
            cout<<"STACK OVERFLOW ! CANNOT PUSH"<<endl;
            return;
        }

        top++;
        arrStack[top]=elem;
        cout<<"ELEMENT "<<elem<<" PUSHED IN STACK !"<<endl; 
    }

    void popElement(){
        if(isEmpty()){
            cout<<"STACK IS EMPTY ! CANNOT POP"<<endl;
            return;
        }
        
        cout<<"ELEMENT "<<elem<<" POPPED FROM STACK !"<<endl;
        top--;
    }

    void viewTopElement(){
        if(isEmpty()){
            cout<<"STACK IS EMPTY ! "<<endl;
            return;
        }

        cout<<"Top element: "<<arrStack[top]<<endl;
    }

    bool isEmpty(){
        return top == -1;
    }

    void displayStack(){
        if(isEmpty()){
            cout<<"STACK IS EMPTY !"<<endl;
            return;
        }

        vector<int>s;
        int tempTop = top;

        while(tempTop != -1){
            s.push_back(arrStack[tempTop]);
            tempTop--;
        }
        
        cout<<"Stack elemnts: "<<endl;
        for(int i=s.size()-1; i>=0; i--){
            cout<<s[i]<<endl;
        }
        cout<<endl;

    }
};

class Queue{
public:
    int size, elem, count = 0, front = 0, rear = -1;
    int arr[100]; 
    int capacity = size;

    bool isFull(){
        return count==capacity;
    }

    bool isEmpty(){
        return count==0;
    }

    void enqueue(){
        if(isFull()){
            cout<<"QUEUE IS FULL ! "<<endl;
            return;
        }
        
        cout<<"Enter the element you want to insert: ";
        cin>>elem;

        rear++;

        arr[rear] = elem;
        cout<<"ELEMENT INSERTED !"<<endl;
        count++;
    }

    void dequeue(){
        if(isEmpty()){
            cout<<"STACK IS EMPTY ! "<<endl;
            return;
        }
        
        cout<<"ELEMENT "<<arr[front]<<" DEQUEUED FROM QUEUE!"<<endl;
        front = (front+1) % capacity;
        count--;
    }

    int getFront(){
        return arr[front];
    }

    int getRear(){
        return arr[rear];
    }

    void displayQueue(){
        if(isEmpty()){
            cout<<"QUEUE IS EMPTY !"<<endl;
            return;
        }

        cout<<"Queue elements: "<<endl;
        int index = front;
        for(int i=0; i<count; i++){
            cout<<arr[index]<<endl;
            index = (index+1) % capacity;
        }
        cout<<endl;
    }
};

int main(){
    
    Array arr;
    LinkedList list;
    Search search;
    Sort sort;
    Stack st;
    Queue q;
    int choice, choice2;

    do{
        cout<<"WELCOME TO MINI DSA EXPLORER !"<<endl;
        cout<<"1.ARRAY     2.LINKED LIST    3.SEARCHING    4.SORTING    5.STACK     6.QUEUE     7.EXIT"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;

        switch(choice){
            case 1:
            do{
                cout<<"1.ADD ARRAY     2.DISPLAY ARRAY     3.REVERSE ARRAY     4.ALTERNATE SWAP      5.MIDDLE ELEMENT      6.MINIMUM ELEMENT       7.MAXIMUM ELEMENT    8.EXIT"<<endl;
                cout<<"Enter your choice: ";
                cin>>choice2;

                switch(choice2){
                    case 1:
                    arr.addArray();
                    break;

                    case 2:
                    arr.displayArray();
                    break;

                    case 3:
                    arr.reverseArray();
                    break;

                    case 4:
                    arr.arrayAlternateSwap();
                    break;

                    case 5:
                    arr.arrayMiddleElement();
                    break;

                    case 6:
                    arr.arrayMinimumElement();
                    break;

                    case 7:
                    arr.arrayMaximumElement();
                    break;

                    case 8:
                    cout<<"EXITING..."<<endl;
                    break;

                    default:
                    cout<<"INVALID CHOICE ! "<<endl;
                }
            }
            while(choice2 != 8);
            break;

            case 2:
            do{
                cout<<"1.INSERT NODE AT BEGINNING     2.INSERT NODE AT END     3.DISPLAY LIST     4.DELETE NODE AT BEGINNING      5.DELETE NODE AT END    6.EXIT"<<endl;
                cout<<"Enter your choice: ";
                cin>>choice2;

                switch(choice2){
                    case 1:
                    list.insertNodeAtBeginning();
                    break;

                    case 2:
                    list.insertNodeAtEnd();
                    break;

                    case 3:
                    list.displayList();
                    break;

                    case 4:
                    list.deleteNodeAtBeginning();
                    break;

                    case 5:
                    list.deleteNodeAtEnd();
                    break;

                    case 6:
                    cout<<"EXITING..."<<endl;
                    break;

                    default:
                    cout<<"INVALID CHOICE !"<<endl;
                }
            }
            while(choice2!=6);
            break;

            case 3:
            do{
                cout<<"1.LINEAR SEARCH     2.BINARY SEARCH    3.EXIT"<<endl;
                cout<<"Enter your choice: ";
                cin>>choice2;

                switch(choice2){
                    case 1:
                    search.linearSearch();
                    break;

                    case 2:
                    search.binarySearch();
                    break;

                    case 3:
                    cout<<"EXITING..."<<endl;
                    break;

                    default:
                    cout<<"INVALID CHOICE !"<<endl;
                }
            }
            while(choice2!=3);
            break;

            case 4:
            do{
                cout<<"1.BUBBLE SORT     2.INSERTION SORT    3.SELECTION SORT   4.MERGE SORT    5.EXIT"<<endl;
                cout<<"Enter your choice: ";
                cin>>choice2;

                switch(choice2){
                    case 1:
                    sort.bubbleSort();
                    break;

                    case 2:
                    sort.insertionSort();
                    break;

                    case 3:
                    sort.selectionSort();
                    break;

                    case 4:
                    sort.mergeSort();
                    break;

                    case 5:
                    cout<<"EXITING..."<<endl;
                    break;

                    default:
                    cout<<"INVALID CHOICE !"<<endl;
                }
            }
            while(choice2!=5);
            break;

            case 5:
            do{
                cout<<"1.DISPLAY STACK     2.PUSH ELEMENT    3.POP ELEMENT   4.VIEW TOP ELEMENT    5.EXIT"<<endl;
                cout<<"Enter your choice: ";
                cin>>choice2;

                switch(choice2){
                    case 1:
                    st.displayStack();
                    break;

                    case 2:
                    st.pushElement();
                    break;

                    case 3:
                    st.popElement();
                    break;

                    case 4:
                    st.viewTopElement();
                    break;

                    case 5:
                    cout<<"EXITING..."<<endl;
                    break;

                    default:
                    cout<<"INVALID CHOICE !"<<endl;
                }
            }
            while(choice2!=5);
            break;

            case 6:
            do{
                cout<<"1.ENQUEUE     2.DEQUEUE    3.DISPLAY QUEUE    4.EXIT"<<endl;
                cout<<"Enter your choice: ";
                cin>>choice2;

                switch(choice2){
                    case 1:
                    q.enqueue();
                    break;

                    case 2:
                    q.dequeue();
                    break;

                    case 3:
                    q.displayQueue();
                    break;

                    case 4:
                    cout<<"EXITING..."<<endl;
                    break;

                    default:
                    cout<<"INVALID CHOICE !"<<endl;
                }
            }
            while(choice2!=4);
            break;

            case 7:
            cout<<"EXITING FROM PROGRAM ! "<<endl;
            break;

            default:
            cout<<"INVALID CHOICE !"<<endl;

        }
    }
    while(choice!=7);

}