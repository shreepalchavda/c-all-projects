#include<iostream>
using namespace std;

void printArray(int numbers[], int value)
{
    for(int i=0; i<value; i++)
    {
        cout<<numbers[i]<<" ";
    }
}

void BubbleSort(int numbers[], int value)
{
    int size = 1;

    while(size < value)
    {
        for(int i=0; i<value-1; i++)
        {
            if(numbers[i] > numbers[i+1])
            {
                int temp = numbers[i];
                numbers[i] = numbers[i+1];
                numbers[i+1] = temp;
            }
        }
        size++;
    }
}

void InsertionSort(int numbers[], int value)
{
    for(int i = 1; i<value; i++)
    {
        int key = numbers[i];
        int j = i-1;

        while(j>=0 && key < numbers[j])
        {
            numbers[j+1] = numbers[j];
            j--;
        }
        numbers[j+1] = key;
    }
}

void SelectionSort(int numbers[], int value)
{
    for(int i=0; i<value-1; i++)
    {
        int index = i;
        for(int j=i+1; j<value; j++)
        {
            if(numbers[j] < numbers[index])
            {
                index = j;
            }
        }

        int temp = numbers[index];
        numbers[index] = numbers[i];
        numbers[i] = temp;
    }
}

int main()
{
    int value;
    cout<<"Enter the size of array: ";
    cin>>value;
    cout<<endl;

    int numbers[value]; 

    for(int i=0; i<value; i++)
    {
        cout<<"enter value at index "<<i<<": ";
        cin>>numbers[i];
    }

    cout<<endl<<"original Array :-  ";
    printArray(numbers, value);
    cout<<endl;

    int choice;
    
    cout<<endl<<"1 bubble sort ";
    cout<<endl<<"2 insertion sort ";
    cout<<endl<<"3 selection sort ";
    
    cout<<endl<<endl<<"select anyone you like : ";
    cin>>choice;
    
    switch (choice)
    {
    case 1:
        BubbleSort(numbers, value);
        cout<<endl<<"\tArray Sorted using Bubble sort : ";
        break;
    case 2:
        InsertionSort(numbers, value);
        cout<<endl<<"\tArray Sorted using Insertion sort : ";
        break;
    case 3:
        SelectionSort(numbers, value);
        cout<<endl<<"\tArray Sorted using Selection sort : ";
        break;
    default:
        cout<<"Invalid Choice!";
        return 0;
    }

    printArray(numbers, value);

    return 0;
}
