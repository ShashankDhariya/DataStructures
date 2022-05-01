#include<iostream>
#define MAX 10
using namespace std;

int push(int arr[],int top,int a)
{
    if(top == MAX-1)
        cout<<"Stack is full"<<endl<<endl;
    else
    {
        arr[++top] = a;
        cout<<"Element pushed successfully..."<<endl<<endl;
    }
    return top;
}

int pop(int arr[],int top)
{
    if(top != -1)
    {
        cout<<"Deleted element : "<<arr[top--]<<endl;
        cout<<"Element popped successfully..."<<endl<<endl;
    }
    else
        cout<<"Stack is empty"<<endl<<endl;

    return top;
}

void display(int arr[],int top)
{
    if(top != -1)
    {
        cout<<"Elements are : ";
        while(top > -1)
            cout<<arr[top--]<<" ";
    }
    else
        cout<<"Stack is empty";
    cout<<endl<<endl;
}

int main()
{
    int arr[MAX];
    int n;
    int element;
    int top = -1;
    do
    {
        cout<<"Press 1 for PUSH\nPress 2 for POP\nPress 3 for DISPLAY\nPress 4 for EXIT\nEnter your choice : ";
        cin>>n;
        switch(n)
        {
            case 1 :cout<<"Enter element to be inserted : ";
                    cin>>element;
                    top = push(arr,top,element);
                    break;
            case 2 :top = pop(arr,top);
                    break;
            case 3 :display(arr,top);
                    break;
            case 4 :cout<<"EXITING..."<<endl;
                    break;
            default:cout<<"Enter valid input"<<endl<<endl;
        }
    }while(n != 4);
}
