/*
 * Assignment 10
 * Paolo Scattolin s1023775
 * Johan Urban s1024726
 * Answers follow the code.
 * */
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;
//int a [] = {2,14,30,29,42,31,112,1,4,45,11,-5,0,51};

vector<int> list = {15, 40, 42, -15, 30, 35, 5};

const int MAX = list.size();

void swap (vector<int>& list, int first,int second)
{
    //preconditions:
    assert(first >= 0 && first < MAX);
    assert(second >= 0 && second < MAX);
    //postconditions: this function swaps the 2 elements of the array/vector.

    int temp;

    temp = list[first];
    list[first] = list[second];
    list[second] = temp;
}

void push_up(vector<int>& list, int i)
{
    //preconditions:
    assert(i >= 0 && i < MAX);
    //postcondition: the elements is pushed to its highest position.

    while (list[i] > list[(i-1)/2])
    {
        swap (list, i , (i-1)/2);
        i = (i-1)/2;
    }
}

void build_heap(vector<int>& list)
{
    //preconditions:
    assert(true);
    //postconditions: the function calls push_up for each el. of the array.

    for (int i = 1 ; i < MAX ; i ++)
    {
        push_up(list,i);
    }
}

void push_down(vector<int>& list, int MAX_EL)
{
    // precondition:
    assert(MAX_EL >= 0);
    // postcondition:
    // A value is placed more and more toward the end of the vector being sorted,
    // until it is no longer larger than one of its children.
    while (MAX_EL > 0)
    {
        int i = 0;
        while (2*i+1 < MAX_EL)
        {
            if(2*i+2 < MAX_EL && (list[2*i+1] >= list[2*i+2]))
            {
                if (list[i] <= list[2*i+1])
                {
                    swap (list, i , 2*i + 1);
                    i = 2*i + 1;
                }
            }
            else if (2*i+2 < MAX_EL && (list[2*i+1] < list[2*i+2]))
            {
                if (list[i] <= list[2*i+2])
                {
                    swap (list, i , 2*i + 2);
                    i = 2*i + 2;
                }
            }
            else if (list[i] <= list[2*i+1])
            {
                swap (list, i , 2*i + 1);
                i = 2*i + 1;
            }
            i++;
        }
        for (int i = 0 ; i < MAX_EL; i++)
        {
            cout << list[i] << " ";
        }
        cout << endl ;

        MAX_EL--;
    }
}

void pick_heap(vector<int>& list)
{
    // precondition:
    assert(true);
    //postcondition:
    //the vector is being sorted by a cooperation of two implemented functions:
    // swap() and push_down().
    int MAX_EL = MAX;

    for (int i = 0; i < MAX ; i++)
    {
        swap (list ,0, MAX_EL-1);
        cout<<"swapped: "<<endl;
        for (int j = 0 ; j< MAX; j++)
        {
            cout << list[j] << " ";
        }
        cout << endl ;
        MAX_EL--;
        push_down(list ,MAX_EL);
    }
}

int main() {
    // precondition:
    assert(true);
    // postcondition:
    // initiates the sorting algorithm Heap Sort and gives
    // output in the console.
    build_heap(list);

    cout << "Heaped array: " << endl;

    for (int i = 0; i < MAX; i++) {
        cout << list[i] << " ";
    }
    cout << endl;

    pick_heap(list);

    cout << "Sorted array: " << endl;

    for (int i = 0; i < MAX; i++) {
        cout << list[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
 * Answers:
 *
 * Part 1:
 * a) O(1) - Does not contain any repetition.
 * b) O(sqrt(n)) - One repetition with an upper bound, which is limited by the square root function.
 *
 * Part 2:
 * a)   (displayed in console)
 * b)
 *      push_up: O(n) - a single loop with an upper bound.
 *      build_heap: O(n) - a single loop with an upper bound.
 *      push_down: O(n^2) - 2 (nested) loops dependant of the same input.
 *      pick_heap: O(n^2) - 2 (nested) loops dependant of the same input.
 *      Heap Sort: O(2n+(2n^2)) - Addition of the sub-functions.
 **/
