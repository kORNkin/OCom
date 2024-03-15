/*TASK:
LANG: C++
AUTHOR: Supphakon Yimi
CENTER: WU
*/
#include <bits/stdc++.h>
using namespace std;
#define endll "\n"
typedef unsigned long long ull;
typedef long long ll;
typedef double db;

struct Node
{
    int value;
    Node *next;
};

Node *getnode()
{
    Node *n;
    n = new Node;
    n->next = NULL;
    return n;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    Node *head = getnode();
    head->value = 999;

    int co=0;
    while(T--)
    {
        string s;
        cin >> s;
        if(s=="head")   
            co=0;
        else if(s=="next")
        {
            int x=0;
            Node *n = head;
            while(x!=co)
            {
                n = n->next;
                x++;
            }
            if(n->next != NULL)
                co++;
        }
        else if(s=="tail")
        {
            Node *n = head;
            co=0;
            while(n->next!=NULL)
            {
                n = n->next;
                co++;
            }
        }
        else if(s=="add")
        {
            int data,x=0; 
            cin >> data;
            Node *h = head;
            Node *n = getnode();
            n->value = data;
            while(x!=co)
            {
                h = h->next;
                x++;
            }
            if(h->next!=NULL)
            {
                n->next = h->next;
                h->next = n;
            }
            else h->next = n;
        }
        else if(s=="remove")
        {
            Node *n = head;
            int x=0;
            while(x!=co)
            {
                n = n->next;
                x++;
            }
            if(n->next!=NULL)
            {
                Node *tmp = n->next;
                n->next = tmp->next;
                delete tmp;
            }
        }
        else if(s=="call")
        {
            int x=0;
            Node *n = head;
            while(x!=co)
            {
                n = n->next;
                x++;
            }
            cout << n->value << endll;
        }
        else if(s=="list")
        {
            Node *n=head;
            int x=0;
            while(x!=co)
            {
                n = n->next;
                x++;
            }
            while(n->next!=NULL)
            {
                cout << n->value << " ";
                co++;
                n = n->next;
            }
            cout << n->value << " "; 
            cout << endll;
        }
    }

    return 0;

}