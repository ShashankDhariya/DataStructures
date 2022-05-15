#include<iostream>
#define MAX 10
using namespace std;

int enque(int arr[],int num,int rear)
{
    if(rear == MAX-1)
        cout<<"Queue is full"<<endl<<endl;
    else
    {
        arr[++rear] = num;
        cout<<"Element added successfully"<<endl<<endl;
    }
    return rear;
}

int deque(int arr[],int front,int rear)
{
    if(front == -1 || front == rear)
        cout<<"Queue is empty";
    else
    {
        cout<<"Deleted element : "<<arr[front++]<<endl;
        cout<<"Element deleted successfully";
    }
    cout<<endl<<endl;
    return front;
}

void display(int arr[],int front,int rear)
{
    if(front == -1)
        cout<<"Queue is empty";
    else
    {
        cout<<"Elements are : ";
        for(int i = front;i<=rear;i++)
            cout<<arr[i]<<" ";
    }
    cout<<endl<<endl;
}

int main()
{
    int front = -1;
    int rear = -1;
    int choice;
    int num;
    int arr[MAX];
    do{
        cout<<"Press 1 to add node"<<endl<<"Press 2 to delete node"<<endl<<"Press 3 to display"<<endl<<"Press 4 to exit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;

        switch(choice)
        {
            case 1 :cout<<"Enter number to be added : ";
                    cin>>num;
                    rear = enque(arr,num,rear);
                    if(rear == 0)
                        front = 0;
                    cout<<"front"<<front<<endl;
                    cout<<"rear"<<rear<<endl;
                    break;
            case 2 :front = deque(arr,front,rear);
                    if(front == -1)
                        rear = -1;
                    cout<<"front"<<front<<endl;
                    cout<<"rear"<<rear<<endl;
                    break;
            case 3 :display(arr,front,rear);
                    break;
            case 4 :cout<<"EXITING...";
                    break;
            default:cout<<"Enter valid choice"<<endl<<endl;
       }
    }while(choice != 4);
    return 0;
}
