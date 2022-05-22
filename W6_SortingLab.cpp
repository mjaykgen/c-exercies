#include <iostream>
using namespace std;
void selectionSort(int [], int ); 
bool isEqual(const int[], const int[], int);
void merge(int[], int[],int ,int);
int binarySearch(int[], int,int);
void print(int[], int);
void exercise1();
void exercise2();
void exercise3();
int main() {
	exercise1(); //strictly equal
	exercise2(); //merge
	exercise3(); //binary search
    return 0;
}
//function to print an array
void print(int list[], int n) {
    cout << "\nArray elements are:";
    for (int i = 0; i < n; i++)
        cout << list[i] << " ";
}
//sort function
void selectionSort(int a[], int size) {
    int minPos, min;
    for (int i = 0; i < size - 1; i++) {
        minPos = i;
        min = a[i];
        for (int j = i + 1; j < size; j++)
            if (a[j] < min) {
                minPos = j;
                min = a[j];
            }
        swap(a[minPos], a[i]);
    }
}
//check if identical
bool isEqual(const int list1[], const int list2[], int size) {
    for (int i = 0; i < size; i++)
        if (list1[i] != list2[i])
            return false;
    return true;
}
void merge(int list1[], int list2[], int s1, int s2) {
    //copy elements from list2 to list1
    for (int i = 0, j = s1; i < s2; i++, j++)
        list1[j] = list2[i];
    //sort list 1 wchi has s1+s2 elements
    selectionSort(list1, s1 + s2);
}
int binarySearch(int list[],int size, int element) {
    //we can use this binary search only when the array is sorted
    int first = 0, last = size-1, mid;
    while (first < last) {
        mid = (last + first) / 2;
        if (list[mid] == element)
            return mid;
        else if (element < list[mid]) //search in the left part of the array
            last = mid - 1;
        else //search in the right part
            first = mid + 1;
    }
    return -1; //if loop finishes, it means we did not find the element.
}
void exercise1() {
    const int MAX = 20;
    int a[MAX], b[MAX];
    int s1, s2;
    do {
        cout << "Enter list 1 size followed by elements:";
        cin >> s1;
    } while (s1 < 0 || s1 > MAX);
    //fill list 1
    for (int i = 0; i < s1; i++)
        cin >> a[i];
    do {
        cout << "Enter list 2 size followed by elements:";
        cin >> s2;
    } while (s2 < 0 || s2 > MAX);
    //fill list 2
    for (int i = 0; i < s2; i++)
        cin >> b[i];
    //sort the arrays
    selectionSort(a, s1);
    selectionSort(b, s2);
    //check if equal
    if (s1 == s2)
        if (isEqual(a, b, s1))
            cout << "\nLists are identical";
        else cout << "\nList are not identical";
    else cout << "\nLists don't have the same size";
}
void exercise2() {
    const int MAX = 20;
    int s1,s2;
    int a[MAX * 2], b[MAX];//if we merge in a, a should have enough space
    do {
        cout << "\nEnter list 1 size:";
        cin >> s1;
    } while (s1 < 0 || s1 > MAX);
    do {
        cout << "\nEnter list 2 size:";
        cin >> s2;
    } while (s2 < 0 || s2 > MAX);
    //randomly fill a and b
    for (int i = 0; i < s1; i++)
        a[i] = rand() % 100 + 1;  
    for (int i = 0; i < s2; i++)
        b[i] = rand() % 100 + 1;
    print(a,s1);
    print(b,s2);
    merge(a, b, s1, s2);
    print(a,s1+s2);//print after merging
}
void exercise3() {
    //create an array
    const int SIZE = 7;
    int a[] = { 4,-2,8,34,2,1,6 };
    
    //ask the user to enter the element to search for
    int n;
    cout << "\nEnter an element to look for:";
    cin >> n;
    //to use the binary search, the array should be sorted
    selectionSort(a, SIZE);
    print(a, SIZE);
    int pos = binarySearch(a, SIZE, n);
    if (pos == -1)
        cout << "\nElement not found";
    else cout << endl<< n << " was found at position: " << pos;
}
