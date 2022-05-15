#include <iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
};

struct node *enque(struct node *head,int num)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));

    ptr->data = num;
    ptr->next = NULL;

    if(head == NULL)
        head = ptr;

    else
    {
        struct node *p = head;
        while(p->next != NULL)
            p = p->next;
        p->next = ptr;
    }
    cout<<"Element added successfully"<<endl<<endl;
    return head;
}

struct node *deque(struct node *head)
{
    struct node *p = head;

    if(head == NULL)
        cout<<"Queue is empty"<<endl<<endl;

    else
    {
        cout<<"Deleted element : "<<p->data<<endl;
        head = p->next;
        free(p);
        cout<<"Element deleted successfully"<<endl<<endl;
    }
    return head;
}

void display(struct node *head)
{
    struct node *p = head;

    if(head == NULL)
        cout<<"Queue is empty";

    else
    {
        cout<<"Elements are : ";
        while(p !=  NULL)
        {
            cout<<p->data<<" ";
            p = p->next;
        }
    }
    cout<<endl<<endl;
}

int main()
{
    struct node *head = NULL;
    int choice;
    int num;

    do{
        cout<<"Press 1 to add node"<<endl<<"Press 2 to delete node"<<endl<<"Press 3 to display"<<endl<<"Press 4 to exit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;

        switch(choice)
        {
            case 1 :cout<<"Enter number to be added : ";
                    cin>>num;
                    head = enque(head,num);
                    break;
            case 2 :head = deque(head);
                    break;
            case 3 :display(head);
                    break;
            case 4 :cout<<"EXITING...";
                    break;
       }
    }while(choice != 4);
    return 0;
}
