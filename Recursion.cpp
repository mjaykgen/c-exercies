/******************************************************************************
Recursion
Ex1: count number of even digits in an integer
Ex2: display a string in reverse
Ex3: validate the scores in an array

*******************************************************************************/

#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
//Ex1
int evenCount(int value) {
    if (value == 0)
        return 0;
    int d = value % 10;
    if (d % 2 == 0)
        return 1 + evenCount(value / 10);
    return evenCount(value / 10);
}
//Ex2
void reverseDisplay(string s, int high) {
    if (high == -1)
        return;
    cout << s[high];
    reverseDisplay(s, high - 1);

}
//Ex3
bool validate(int scores[], int size) {
    if (size == -1)
        return true;
    if (scores[size] < 0 || scores[size] > 100)
        return false;
    return validate(scores, size - 1);
}
int main()
{
    char ch;
    int choice, n, min, max;
    string s;
    do {
        cout << "Enter \n1- to count number of even digits in an integer"
            << "\n2- to display a string in reverse"
            << "\n3- to validate scores in an array of 5 scores:";
        cin >> choice;
        if (choice == 1) {
            cout << "Enter an integer:";
            cin >> n;
            cout << "Number of even digits:" << evenCount(n);
        }
        else if (choice == 2) {
            cout << "Enter a string:";
            cin >> s;
            cout << "String in reverse:";
            reverseDisplay(s, s.length() - 1);
        }
        else if (choice == 3) {
            srand(time(0));
            const int SIZE = 5;
            cout << "Enter min and max range for random numbers:";
            cin >> min >> max;
            if (min > max) {
                int tmp = min;
                min = max;
                max = tmp;
            }
            int scores[SIZE];
            max = max - min + 1;
            cout << "Scores generated:";
            for (int i = 0; i < SIZE; i++) {
                scores[i] = min + rand() % max;
                cout << scores[i] << " ";
            }
            if (validate(scores, SIZE - 1))
                cout << "\nAll scores are valid";
            else cout << "\nAt least one score is invalid";
        }
        else
            cout << "Invalid choice";
        cout << "\nWould you like to continue?(y/n):";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    return 0;
}
