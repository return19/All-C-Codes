#include<bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node* next;
};

void insertBegin(node *&head,int val){
    node* newnode;
    newnode = (node*)malloc(sizeof(node));
    newnode ->val = val;
    newnode->next = NULL;

    if(!head){
        head = newnode;
        return;
    }

    newnode->next = head;
    head = newnode;
}

void insertEnd(node *&head,int val){
    node* newnode;
    newnode = (node*)malloc(sizeof(node));
    newnode ->val = val;
    newnode->next = NULL;

    if(!head){
        head = newnode;
        return;
    }

    node* temp = head;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = newnode;
}

void insertPos(node *&head,int val,int pos){
    node* newnode;
    newnode = (node*)malloc(sizeof(node));
    newnode ->val = val;
    newnode->next = NULL;

    if(pos==1)
    {
        insertBegin(head,val);
        return;
    }

    node* temp = head;

    for(int i=0;i<pos-2;i++){
        temp = temp->next;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

void deleteBegin(node* &head){
    if(head==NULL){
        return;
    }
    node* temp = head;
    head = head->next;
    free(temp);
}

void deleteEnd(node* &head){
    node* temp = head;

    if(head->next ==NULL)
    {
        head=NULL;
        free(temp);
        return;
    }

    while(temp->next->next)
        temp = temp->next;
    node* t = temp->next;
    temp->next = NULL;
    free(t);
    return;
}

void deletePos(node* &head,int pos){
    node* temp = head;
    if(pos==1){
        head= NULL;
        free(temp);
        return;
    }

    for(int i=0;i<pos-2;i++){
        temp = temp->next;
    }
    node* t = temp->next;
    temp->next = temp->next->next;
    free(t);
}

int main()
{
    int i,j,k;
    node* head = NULL;
    int choice;
    int val,pos;
    node* t;

    while(1){

        cout<<"1. Insert Beginning"<<endl;
        cout<<"2. Insert End"<<endl;
        cout<<"3. Insert at position"<<endl;
        cout<<"4. Delete Beginning"<<endl;
        cout<<"5. Delete End"<<endl;
        cout<<"6. Delete at position"<<endl;
        cout<<"7. Print list"<<endl;
        cout<<"0. Exit"<<endl;

        cout<<"Enter your choice : ";
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"Enter value : ";
                cin>>val;

                insertBegin(head,val);
            break;
            case 2:
                cout<<"Enter value : ";
                cin>>val;
                insertEnd(head,val);
            break;
            case 3:
                cout<<"Enter value and position : ";
                cin>>val>>pos;
                insertPos(head,val,pos);
            break;
            case 4:
                deleteBegin(head);
            break;
            case 5:
                deleteEnd(head);
            break;
            case 6:
                cout<<"Enter position : ";
                cin>>pos;
                deletePos(head,pos);
            break;
            case 7:
                t = head;
                while(t!=NULL){
                    cout<<t->val<<" ";
                    t= t->next;
                }
                cout<<endl;
                break;
            case 0:
            return 0;
            default:
                cout<<"Invalid input"<<endl;
        }
    }

    return 0;
}














