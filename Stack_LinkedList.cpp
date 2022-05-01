#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
};

struct node *push(struct node *top,int a)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = a;

    if(top == NULL)
    {
        top = ptr;
        ptr->next = NULL;
    }
    else
    {
        ptr->next = top;
        top = ptr;
    }
    cout<<"Element pushed successfully..."<<endl<<endl;
    return top;
}

struct node *pop(struct node *top)
{
    if(top == NULL)
        cout<<"Stack is empty"<<endl<<endl;
    else
    {
        struct node *p = top;
        cout<<"Deleted element : "<<p->data<<endl;
        top = p->next;
        free(p);
        cout<<"Element popped successfully..."<<endl<<endl;
    }
    return top;
}

void display(struct node *top)
{
    if(top != NULL)
    {
        cout<<"Elements are : ";
        struct node *p = top;
        while(p != NULL)
        {
            cout<<p->data<<" ";
            p = p->next;
        }
    }
    else
        cout<<"Stack is empty";
    cout<<endl<<endl;
}

int main()
{
    int n;
    int element;
    struct node *top = NULL;
    do
    {
        cout<<"Press 1 for PUSH\nPress 2 for POP\nPress 3 for DISPLAY\nPress 4 for EXIT\nEnter your choice : ";
        cin>>n;
        switch(n)
        {
            case 1 :cout<<"Enter element to be inserted : ";
                    cin>>element;
                    top = push(top,element);
                    break;
            case 2 :top = pop(top);
                    break;
            case 3 :display(top);
                    break;
            case 4 :cout<<"EXITING..."<<endl;
                    break;
            default:cout<<"Enter valid input"<<endl<<endl;
        }
    }while(n != 4);
    return 0;
}
