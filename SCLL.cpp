#include <iostream>
using namespace std;
struct node {
    int data;
    node* next;
};
node* createNode(int x) {
    node *temp = new node;
    temp->data = x;
    temp->next = temp;
    return temp;
}
node *addElement(node *l, int x)    {
    node *temp = createNode(x);
    temp->next = l->next;
    l->next = temp;
    return temp;
}
node* changeHeadTo(node* l, int k) {
    for (int i = 0; i < k; i++)
    {
        l = l->next;
    }
}
node *addToHead(node* l, int x) {
    node* p = l;
    while(p->next != l)   {
        p=p->next;
    }
    p = addElement(p, x);
    return p;
}
node *addToTail(node* l, int x) {
    node* p = l;
    while(p->next != l)   {
        p=p->next;
    }
    p = addElement(p, x);
    return l;
}
node* addAt(node* l, int k, int x)    {
    node* p = l;
    for (int i = 0; i < k-1; i++)
    {
        p=p->next;
    }
    node *needToAdd = createNode(k);
    needToAdd->next = p->next;
    p->next = needToAdd->next;
    return l;
}

node *deleteHead(node*l) {
    node* p = l;
    p = changeHeadTo(p, 1);
    return deleteTail(p);
}
node *deleteTail(node*l) {
    node *p = l;
    while(p->next->next != l) {
        p = p->next;
    }
    temp = p->next;
    p->next = l;
    temp = NULL;
    delete temp;
    return l;
}
node *deleteAt(node* l, int k)  {
    node *p = l;
    for (int i = 0; i < k - 1; i++)
    {
        p=p->next;
    }
    node* temp = p->next;
    p->next = p->next->next;
    temp = NULL;
    delete temp;
}
// void scanList(node* l)    {
//     node* p = l;
//     while(p->next != l) {
//         //Lệnh xử lí p
//         p=p->next;
//     }
//     //Lệnh xử lí p
// }
// void scanFrom(node* l, int k)  {
//     node* p = l;
//     for (int i = 0; i < k; i++)
//     {
//         p=p->next;
//     }
//     scanList(p);    
// }
void printList(node* l)    {
    node* p = l;
    while(p->next != l) {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<p->data<<" ";
}
void printFrom(node* l, int k)  {
    node* p = l;
    for (int i = 0; i < k; i++)
    {
        p=p->next;
    }
    printList(p);    
}
int main()  {
    int n, a;
    cin>>n>>a;
    node* l = createNode(a);
    node* p = l;
    for (int i = 0; i < n-1; i++)
    {
        cin>>a;
        p = addElement(p, a);
    }
    cin>>a;
    printFrom(l, a);
    return 0;    
}