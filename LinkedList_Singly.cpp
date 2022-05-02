#include<iostream>.
using namespace std;

struct node{
    int data;
    struct node *next;
};

struct node *addRight(struct node *head,int num)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;

    ptr->data = num;
    ptr->next = NULL;

    if(head == NULL)
        head = ptr;

    else
    {
        while(p->next != NULL)
            p = p->next;
        p->next = ptr;
    }
    cout<<"Node inserted successfully..."<<endl<<endl;
    return head;
}

struct node *addleft(struct node *head,int num)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = num;

    if(head == NULL)
    {
        ptr->next = NULL;
        head = ptr;
    }

    else
    {
        ptr->next = head;
        head = ptr;
    }
    cout<<"Node inserted successfully..."<<endl<<endl;
    return head;
}

struct node *deleteRight(struct node *head)
{
    struct node *p = head;
    if(p == NULL)
        cout<<"List is empty"<<endl<<endl;

    else if(p->next == NULL)
    {
        cout<<"Deleted node value : "<<p->data;
        free(p);
        head = NULL;
        cout<<endl<<"Node deleted successfully..."<<endl<<endl;
    }

    else
    {
        struct node *q = head->next;
        while(q->next != NULL)
        {
            p = p->next;
            q = q->next;
        }
        cout<<"Deleted node value : "<<q->data<<endl;
        p->next = q->next;
        free(q);
        cout<<"Node deleted successfully..."<<endl<<endl;
    }
    return head;
}

struct node *deleteleft(struct node *head)
{
    struct node *p = head;
    if(head == NULL)
        cout<<"List is empty"<<endl<<endl;

    else
    {
        cout<<"Deleted node value : "<<p->data;
        head = p->next;
        free(p);
        cout<<endl<<"Node deleted successfully..."<<endl<<endl;
    }

    return head;
}

void display(struct node *head)
{
    if(head == NULL)
        cout<<"List is empty";

    else
    {
        cout<<"List : ";
        while(head != NULL)
        {
            cout<<head->data<<" ";
            head = head->next;
        }
    }
    cout<<endl<<endl;
}

int main()
{
    int n;
    int num;
    int sub;
    struct node *head = NULL;
    do
    {
        cout<<"Press 1 to Add nodes"<<endl<<"Press 2 to Delete node"<<endl<<"Press 3 display"<<endl<<"Press 4 to Exit"<<endl<<endl;
        cout<<"Enter your choice : ";
        cin>>n;
        switch(n)
        {
            case 1 :cout<<"Press 1 to add node to right"<<endl<<"Press 2 to add node to left"<<endl;
                    cin>>sub;

                    cout<<"Enter element to be inserted : ";
                    cin>>num;

                    switch(sub)
                    {
                        case 1 :head = addRight(head,num);
                                break;
                        case 2 :head = addleft(head,num);
                                break;
                        default:cout<<"Enter valid choice"<<endl;
                    }
                    break;

            case 2 :cout<<"Press 1 to delete node from right"<<endl<<"Press 2 to delete node from left"<<endl;
                    cin>>sub;

                    switch(sub)
                    {
                        case 1 :head = deleteRight(head);
                                break;
                        case 2 :head = deleteleft(head);
                                break;
                        default:cout<<"Enter valid choice"<<endl;
                    }
                    break;

            case 3 :display(head);
                    break;

            case 4 :cout<<"EXTING..."<<endl;

            default:cout<<"Enter valid choice"<<endl;
        }
    }while(n != 4);
    return 0;
}
