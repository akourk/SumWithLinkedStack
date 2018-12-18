// Author       :   Alex Kourkoumelis
// Date         :   11/21/2017
// Title        :   Sum With LinkedStack
// Description  :   Creates 3 LinkedStacks, then receives number inputs from the user
//              :   stores each input in the first two LinkedStacks
//              :   adds the numbers together and stores in the third LinkedStack
//              :   outputs the last stack as it empties.

#include <iostream>
#include "LinkedStack.h"
using namespace std;

int main() {
    cout << "Hello, World!" << endl;

    //creating stacks
    LinkedStack<int> ls1;
    LinkedStack<int> ls2;
    LinkedStack<int> ls3;

    //creating input strings
    string s1;
    string s2;

    //getting input strings
    cout << "Enter a very large number: ";
    cin >> s1;
    cout << "Enter a very large number: ";
    cin >> s2;

    //comparing size of strings and adding extra 0's
    if (s1.length() > s2.length()) {
        int diff;
        for (diff = 0; diff < s1.length() - s2.length(); diff++) {
        }
        //for error tracking
        //cout << "s1 is " << diff << " larger than s2." << endl;
        for (int i = 0; i < diff; i++) {
            int z = 0;
            ls2.push(z);
        }
    } else if (s2.length() > s1.length()) {
        int diff;
        for (diff = 0; diff < s2.length() - s1.length(); diff++) {
        }
        //for error tracking
        //cout << "s2 is " << diff << " larger than s1." << endl;
        for (int i = 0; i < diff; i++) {
            int z = 0;
            ls1.push(z);
        }
    }

    //putting strings into linkedstacks
    int t;
    for (int i = 0; i < s1.length(); i++) {
        t = s1[i] - 48;
        ls1.push(t);
    }
    for (int i = 0; i < s2.length(); i++) {
        t = s2[i] - 48;
        ls2.push(t);
    }

    //for error reporting
//    //printing both linkedstacks (both numbers will be reversed)
//    while (!ls1.isEmpty()) {
//        cout << ls1.pop();
//    }
//    cout << endl;
//    while (!ls2.isEmpty()) {
//        cout << ls2.pop();
//    }

    //doing math wizardry
    //temp carries the 1
    int temp;
    int sum;
    while (!ls1.isEmpty() && !ls2.isEmpty()) {
        if (temp > 0) {
            sum = temp;
        } else {
            sum = 0;
        }
        temp = 0;
        //always adds sum- if a 1 was carried sum = 1, otherwise it defaults to 0
        sum = ls1.pop() + ls2.pop() + sum;
        if (sum > 9) {
            temp = 1;
            sum = sum - 10;
        }
        ls3.push(sum);
        //to carry last 1 (so case 500+500=000 instead of 500+500=1000)
        if(ls1.isEmpty() && ls2.isEmpty() && temp > 0) {
            ls3.push(temp);
        }
    }

    //printing out sum
    //lots of spaces to align numbers
    cout << "Sum is:                    ";
    while (!ls3.isEmpty()) {
        cout << ls3.pop();
    }

    return 0;
}