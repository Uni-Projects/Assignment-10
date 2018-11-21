#include <iostream>
#include <cassert>


using namespace std;
int a [] = {2,14,30,29,42,30,11,-5,0,51};
const int MAX = sizeof(a)/sizeof(a[0]);

void swap (int a[], int first,int second)
{
    //preconditions:
    assert(first >= 0 && first < MAX);
    assert(second >= 0 && second < MAX);
    //postconditions: this function swaps the 2 elements of the array/vector.

    int temp;

    temp = a[first];
    a[first] = a [second];
    a[second] = temp;
}

void push_up(int a[], int i)
{
    //preconditions:
    assert(i >= 0 && i < MAX);
    //postcondition: the elements is pushed to its highest position.

    while (a[i] > a[(i-1)/2])
    {
        swap (a, i , (i-1)/2);
        i = (i-1)/2;
    }
}

void build_heap(int a[])
{
    //preconditions:
    assert(true);
    //postconditions: the function calls push_up for each el. of the array.

    for (int i = 1 ; i < MAX ; i ++)
    {
        push_up(a,i);
    }
}

void push_down(int a[], int MAX_EL)
{
    while (MAX_EL > 0)
    {
      int i = 0;
      while (2*i+1 < MAX_EL)
      {
          if (a[i] < a[2*i+1])
          {
              swap (a, i , 2*i + 1);
              i = 2*i + 1;
          }
          else if (a[i] < a[2*i+2] && 2*i+2 < MAX_EL)
          {
              swap (a, i , 2*i + 2);
              i = 2*i + 2;
          }
          else
            i++;
       }
       MAX_EL--;
    }
}

void pick_heap(int a[])
{
    int MAX_EL = MAX;

    for (int i = 0; i < MAX ; i++)
    {
        swap (a,0, MAX_EL-1);
        MAX_EL--;
        push_down(a,MAX_EL);
    }
}

int main()
{
    build_heap(a);

    cout << "Heaped array: " << endl ;

    for (int i = 0 ; i < MAX ; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl ;

    cout << "Sorted array: " << endl ;

    pick_heap(a);

    for (int i = 0 ; i < MAX ; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl ;

    return 0;
}
