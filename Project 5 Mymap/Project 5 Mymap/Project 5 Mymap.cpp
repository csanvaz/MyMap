// Project 5 Mymap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "mymap.h"
#include <map>
#include <set>



int main()
{
    mymap<int, int> map;
    bool test = false;
    int n = 10;
    int arr[] = { 30, 15, 50, 8, 25, 70, 20, 28, 40, 60 };
    for (int i = 0; i < n; i++) {
        map.put(arr[i], arr[i]);
    }
    /*mymap <int, int> map;
    int n = 10;
    int arr[] = { 30, 15, 50, 20, 25, 70, 20, 28, 40, 30 };
    int arr2[] = { 32, 16, 51, 21, 26, 71, 22, 29, 2, 1 };
    for (int i = 0; i < n; i++) {
        map.put(arr[i], arr2[i]);
    }*/

    cout << "Map Contains: " << map.Size() << endl;

    //Testing for 3 loops
   /* int loop = 1;
    for (int i = 0; i < 3; i++) {
        test = map.contains(arr[i]);
        cout << loop << ". Bool Result: " << test << endl;
        loop++;
    }*/

    //Testing the whole array
    int loop2 = 1; 
    for (int i = 0; i < n; i++) {
        test = map.contains(arr[i]);
        cout << loop2 << ". Map Contains Variable: " << test << endl;
        loop2++;
    }

    //Testing get()
    cout << "Testing Get(): " << map.get(29) << endl;
    for (int i = 0; i < n; i++) {
        cout << map.get(arr[i]) << endl;
    }

    //Testing toString()
    cout << "Testing toString(): " << endl;
    cout << map.toString();
    cout << endl;
    
    //Testing operator[]
    int arr1 = { 30 };
    int arr2 = { 40 };
    int arr3 = { 55 };
    
    if (map[arr1] == 30) {
        cout << "Operator value: " << arr1 << endl;
    }

    if (map[arr2] == 40) {
        cout << "Operator value: " << arr2 << endl;
    }
    

    //Testing Begin Function
    map.begin();

    //Testing copy operator
    mymap<int, int> m;
    mymap<int, int> m2;

    int arr4[] = { 3, 7, 6, 9, 10 };
    int arr5[] = { 4, 2, 1, 5, 9 };

    string mOriginal = "key: 3 value: 3\nkey: 6 value: 6\nkey: 7 value: 7\nkey: 9 value: 9\nkey: 10 value: 10\n";

    for (int i = 0; i < 5; i++) {
        m.put(arr4[i], arr4[i]);
    }

    for (int j = 0; j < 5; j++) {
        m2.put(arr5[j], arr5[j]);
    }

    cout << "String before: " << m.toString();
    cout << "Other String: " << m2.toString();

    m = m2;

    cout << "String after: " << m.toString();

   //Testing Clear
   map.clear();


   return 0; 
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
