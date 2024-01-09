#include <iostream>
#include <stdio.h>
using namespace std;

class Array
{
private:
    int capacity;
    int lastIndex;
    int *ptr;

public:
    Array(int);
    ~Array();
    void create(int); // kitne capacity ka array bnaye woh
    bool isEmpty();
    void append(int);
    // append humesha end me hota he jo bhara he uske baad, sirf data btaye
    bool isFull();
    void insert(int, int); // index, data
    void edit(int, int);   // new data , index btaye
    int search(int); // data
};

Array::Array(int c)
{

    try
    {

        if (c < 1)
        {
            throw 1;
        }
        capacity = c;
        lastIndex = -1;
        ptr = new int[capacity];
    }

    catch (int e)
    {
        cout << "Invalid Capacity";

        ptr = NULL;
    }
}

bool Array::isEmpty()
{

    try
    {
        if (ptr == NULL)

        {
            throw 1;
        }
        return lastIndex == -1;
    }

    catch (int e)
    {
        cout << "Invalid Array";
    }
}

bool Array::isFull()
{
    if (ptr == NULL)

    {
        throw 1;
    }

    if (capacity == lastIndex)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Array::create(int c)
{
    if (ptr == NULL)
    {

        if (c < 1)
        {
            throw 1;
        }

        capacity = c;
        lastIndex = -1;
        ptr = new int[capacity];
    }

    else
    {

        if (c < 1)
        {
            throw 1;
        }
        delete ptr[]; // release memory of array

        capacity = c;
        lastIndex = -1;
        ptr = new int[capacity];
    }
}

void Array::append(int data)
{

    if (ptr == NULL)

    {
        throw 1;
    }

    if (isFull)
    {
        cout << "Overflow";
    }

    else
    {
        lastIndex++;
        ptr[lastIndex] = data;
    }
}

void Array::insert(int index, int data)
{
    if (ptr == NULL)

    {
        throw 1;
    }

    int i;

    if (index < 0 || index > lastIndex + 1)
    {
        cout << "Invalid Index";
    }
    else if (isFull())
    {
        cout << "Overflow";
    }
    else
    {
        for (i = lastIndex; i >= index; i--)
        {
            ptr[i + 1] = ptr[i];
        }
        ptr[index] = data;
        lastIndex++;
    }
}

void Array::edit(int newData)
{
    if (ptr == NULL)
    {
        throw 1;
    }

    if (index < 0 || index > lastIndex)
    {
        cout << "Invalid Index";
    }
    else
    {
        ptr[index] = newData;
    }
}

void Array::deleteData(int index)
{
    if (ptr == NULL)
    {
        throw 1;
    }

    if (index < 0 || index > lastIndex)
    {
        cout << "Invalid Index";
    }
    int i;

    else
    {
        for (i = index; i < lastIndex; i++)
        {
            ptr[i] = ptr[i + 1;]

                lastIndex--;
        }
    }
}

int Array::getData(int index)
{
    if (ptr == NULL)
    {
        throw 1;
    }

    if (lastIndex == -1)
    {
        throw 0; // empty array
    }

    if (index < 0 || index > lastIndex)
    {
        throw 1;
    }

    return ptr[index];
}

int Array::count()
{

    if (ptr == NULL)
    {
        throw 1;
    }

    return lastIndex + 1;
}

int Array::search(int data){
    if(isEmpty){
        return -1;
    }

    for(int i=0; i<lastIndex; i++){
        ptr[i] = data;
        return 1;
    }
    return -1;
}

Array::~Array()
{
    if (ptr != NULL)
    {
        delete ptr[];
    }
}

int main(){
    Array a(10);
    a.append(10);
    a.insert(0, 20);

    for(int i=0; i<a.count; i++){
        cout<<a.get(i) <<" ";
    }
}