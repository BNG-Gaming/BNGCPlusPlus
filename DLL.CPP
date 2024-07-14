#include<iostream>
using namespace std;

struct node                                     //khai báo node
{
    int data;
    node* next;
    node* previous;
};
struct douList  {                               //khai báo dslk đôi
    node*head;
    node*tail;
};
douList *createList(int x)  {                   //tạo một node trong dslk đôi l
    douList* l= new douList;
    l->head = new node;
    l->head->data = x;
    l->head->previous = NULL;
    l->head->next = NULL;
    l->tail = l->head;
    return l;
}
douList *addToHead(douList *l, int x)   {       //thêm node vào đầu
    node* temp = new node;
    temp->data = x;
    temp->previous = NULL;
    temp->next = l->head;
    l->head->previous = temp;
    l->head = temp;
    return l;
}
douList *addToTail(douList *l, int x)   {       //thêm node vào cuối
    node*temp = new node;
    temp->data = x;
    temp->next = NULL;
    temp->previous = l->tail;
    l->tail->next = temp;
    l->tail = temp;
    return l;
}
douList *addAt(douList* l, int k, int a)    {
    node* p = l->head;
    node* temp = new node;
    temp->data = a;
    for (int i = 0; i < k-1; i++)
    {
        p=p->next;
    }
    node*h = p->next;
    p->next = temp;
    temp->next = h;
    h->previous = temp;
    temp->previous = p;    
    return l;
}
douList *addGeneral(douList* l, int k, int a, int n)    {
    if (k == 0)
    {
        return addToHead(l, a);
    }
    else if (k == n)
    {
        return addToTail(l, a);
    }
    else{
        return addAt(l, k, a);
    }
}
douList *removeHeadNode(douList* l) {
    douList* p = l;
    node* temp = p->head;
    p->head = p->head->next;
    temp = NULL;
    delete temp;
    return p;
}
douList *removeTailNode(douList *l){
	node *p = l->tail->previous;
	node *temp = l->tail;
	p->next = NULL;
	l->tail = p;
	delete(temp);
	return l;
}
douList *removeAt(douList* l, int k)    {
    node* p = l->head;
    for (int i = 0; i < k-1; i++)
    {
        p=p->next;
    }
    node* needToRemove = p->next;
    p->next = needToRemove->next;
    needToRemove->next->previous=p;
    needToRemove = NULL;
    delete needToRemove;    
    return l;
}
douList *removeGeneral(douList *l, int k, int n)    {
    if (k == 0)
    {
        return removeHeadNode(l);
    }
    else if (k == n - 1)
    {
        return removeTailNode(l);
    }
    else    {
        return removeAt(l, k);
    }
}
douList *removeGeneral(douList* l, int k)   {
    int n = 0;
    node* p = l->head;
    while (p!=NULL)
    {
        n++;
    }
    return removeGeneral(l, k, n);  
}
// void scanFromHead(douList * l)  {
//     node* p = l-> head;
//     while(p != NULL)    {
//         Lệnh xử lí data
//         p = p->next;
//     }
// }
// void scanFromTail(douList * l)  {
//     node* p = l-> tail;
//     while(p != NULL)    {
//         Lệnh xử lí data
//         p = p->previous;
//     }
// }
void printList(douList *l)  {
    node* p = l-> head;
    while(p != NULL)    {
        cout<<p->data<<" ";
        p = p->next;
    }
}
int main()  {
    //lần này khác lần trước nha mày, tự xử hết
    int n, a;
    cin>>n>>a;
    douList *l = createList(a);
    for (int i = 1; i < n; i++)
    {
        cin>>a;
        l = addToTail(l, a);
    }
    int k;
    cin>>k;
    l = removeGeneral(l, k, n);
    printList(l);    
}


