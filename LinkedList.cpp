#include <iostream>
using namespace std;
struct node                                     //khai báo node
{
    int data;
    node* next;
};
node* newNode(int x)    {                       //tạo mới node
    node* temp = new node;
    temp->next = NULL;
    temp->data = x;
    return temp;
}
node* addElement(node*p, int x) {               //thêm phần tử vào DSLK khi con trỏ đang trỏ vào cuối
    node* temp = newNode(x);
    p->next = temp;
    return temp;
}
node* getNode(node* l, int k)   {               //lấy địa chỉ node thứ k
    node* p = l;
    for (int i = 0; i < k; i++)
    {
        p = p->next;
    }
    return p;    
}
int getData(node*l, int k)  {                   //lấy dữ liệu node thứ k
    node* p = l;
    for (int i = 0; i < k; i++)
    {
        p = p->next;
    }
    return p->data;   

}
node* addToHead(node*p, int x)  {               //thêm phần tử vào đầu
    node* temp = newNode(x);
    temp->next = p;
    return temp;
}
node* addToTail(node* p, int x) {               //thêm phần tử vào cuối
    node* temp = newNode(x);
    node* l = p;
    while (l->next!=NULL)  {
        l = l->next;
    }
    l->next = temp;
    return p;  
}
node* addAt(node*p, int k, int a)   {           //chèn phần tử vào vị trí k
    node* temp = new node;
    node* h = p;
    for (int i = 0; i < k - 1; i++)
    {
        h = h->next;
    }
    temp->data = a;
    temp->next = h->next;
    h->next = temp;
    return p;
}
node* removeHeadNode(node* l)   {               //xóa phần tử đầu tiên
    node* p = l->next;
    l = NULL;
    return p;
}
node* removeTailNode(node* l)   {               //xóa phần tử cuối cùng
    node* p = l;
    while (p->next->next!=NULL)
    {
        p = p->next;
    }
    p -> next = NULL;
    delete p->next;
    return l;
}
node* removeAt(node* l, int k)   {              //xóa phần tử thứ k, với k != 0, k != n - 1
    node* p = l;
    for (int i = 0; i < k - 1; i++)
    {
        p = p->next;
    }
    node* needToRemove = p->next;
    p->next = p->next->next;
    needToRemove = NULL;
    return l;
}
node* removeGeneral(node* l, int k, int n)  {   //xóa phần tử thứ k, với k có thể bằng 1 và bằng n - 1
    if (k == 0)
    {
        return removeHeadNode(l);
    }
    else if (k == n-1)
    {
        return removeTailNode(l);
    }
    else{
        return removeAt(l, k);
    } 
}
node* removeGeneral(node* l, int k) {           //như trên, nhưng chưa xác định n
    int n = 0;
    node*p = l;
    while (p!= NULL)
    {
        n++;
        p = p->next;
    }
    return removeGeneral(l, k, n);
}

// node* removeGreater(node* l, int a) {        //xóa phần tử thỏa mãn điều kiện nào đó
//     int k = 0;
//     node*p = l;
//     node* ans = new node;
//     while (p!=NULL)
//     {
//         if(!(điều kiện)  {
//             ans = newNode(p->data);
//             p=p->next;
//             break;
//         }
//         p = p->next;
//     }
//     while (p!=NULL) {
//         if(!(điều kiện))  {
//             ans = addToTail(ans, p->data);
//         }
//         p = p->next;
//     }
//     return ans;
// }
node* removeGreater(node* l, int a) {           //xóa phần tử có giá trị lớn hơn a (dựa vào hàm phía trên)
    int k = 0;
    node*p = l;
    node* ans = new node;
    while (p!=NULL)
    {
        if(!(p->data > a))  {
            ans = newNode(p->data);
            p=p->next;
            break;
        }
        p = p->next;
    }
    while (p!=NULL) {
        if(!(p->data > a))  {
            ans = addToTail(ans, p->data);
        }
        p = p->next;
    }
    return ans;
}
// void scanList(node* l)  {                    //quét từng phần tử
//     node* p = l;
//     while (p!= NULL)
//     {
//         lệnh để xử lí data
//         p=p->next;
//     }
// }
void printList(node* l)  {                      //xuất từng phần tử (dựa vào hàm phía trên)
    node* p = l;
    while (p!= NULL)
    {
        //1 lệnh bất kì để xử lí data
        cout<<p->data<<" ";
        p=p->next;
    }
}
void printNode(node* l, int k)  {               //xuất ra phần tử thứ k
    node* p = l;
    for (int i = 0; i < k; i++)
    {
        p=p->next;
    }
    cout<<p->data;    
}
void replaceNode(node* l, int a, int b) {       //thay thế phần tử giá trị a thành giá trị b
    node* p = l;
    while (p!= NULL)
    {
        if (p->data == a)   
        {
            p->data = b;
        }
        
        p=p->next;
    }
}
int main()  {
    int n, a;
    cin>>n>>a;
    node*j5tr = newNode(a);
    node*sol = j5tr;
    for (int i = 1; i < n; i++)
    {
        cin>>a;
        sol = addElement(sol, a);
    }
    //khai báo thế được rồi, giờ phần logic mày tự lo đi
    cin>>a;
    j5tr = removeGreater(j5tr, getData(j5tr, a));
    printList(j5tr);
}