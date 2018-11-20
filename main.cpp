#include <iostream>
#include <cassert>


using namespace std;
const int MAX = 10 ;

void swapfiets (int (&a)[MAX], int i)
{
    //preconditions:
    assert((i-1)/2 >= 0 && (i-1)/2 < MAX);
    //postconditions: this function swap the parent with its children.

    int temp = 0;
    temp = a[i];

    a [i] = a[(i-1)/2];
    a[(i-1)/2] = temp;
}

void push_up(int (&a)[MAX], int i)
{
    //preconditions:
    assert(i >= 0 && i < MAX);
    //postcondition: the elements is pushed to its highest position.

    while (a[i] > a[(i-1)/2])
    {
        swapfiets (a, i);
        i = (i-1)/2;
    }
}

void build_heap(int (&a)[MAX])
{
    //preconditions:
    assert(true);
    //postconditions: the function calls push_up for each el. of the array.

    for (int i = 1 ; i < MAX ; i ++)
    {
        push_up(a,i);
    }

}

void swap (int (&a)[MAX], int first,int second)
{
    int temp;

    temp = a[first];

    a[first] = a [second];

    a[second] = temp;
}

void push_down(int (&a)[MAX], int i,int& counter)
{
    swap (a , 0 , MAX - 1 - counter );
    cout <<counter << " last element: " << a[ MAX - 1 - counter] << endl;
    counter ++ ;


    while ((2*i+1 <(MAX - counter )) && (a[i] < a[2*i+1] || a[i] < a[2*i+2]) )
    {
        if (a[i] < a[2*i+1])
        {
            swap (a, i , 2*i + 1);
            i = 2*i + 1;
        }
        else
        {
            swap (a, i , 2*i + 2);
            i = 2*i + 2;
        }
    }

}

void pick_heap(int (&a)[MAX])
{
    int counter = 0 ;
    for (int i = 0 ; i < MAX - counter ; i = i)
    {
        push_down(a,i, counter);
    }
}

int main()
{
    int a [MAX] = {2,14,30,29,42,30,11,-5,0,51};
    build_heap(a);

    for (int i = 0 ; i < MAX ; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl ;

    pick_heap(a);

    for (int i = 0 ; i < MAX ; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl ;

    return 0;
}
