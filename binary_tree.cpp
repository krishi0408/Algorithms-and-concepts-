#include<iostream>
#include<queue>
using namespace std;
//Input = 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1

class Node{

public:
    int data;
    Node* left;
    Node* right;

    Node(int d)
    {
        data=d;
        left=right=NULL;
    }
};

// functional approach 
Node* buildTree(){
    int d;
    cin>>d;
    if(d==-1)
    {
        return NULL;
    }
    Node* n = new Node(d);
    n->left = buildTree();
    n->right=buildTree();
    return n;

}
void printPreorder(Node *root)
{
    if(root == NULL) return;
    cout<<root->data<<" ";
    printPreorder(root->left);
    printPreorder(root->right);

}

void printInorder(Node *root)
{
if(root==NULL) return;
printInorder(root->left);
cout<<root->data<<" ";
printInorder(root->right);
}
void printPostorder(Node *root)
{
    if(root==NULL) return;
    printPostorder(root->left);
    printPostorder(root->right);
    cout<<root->data<<" ";
}

void printLevelOrder(Node *root)
{
   queue<Node*> q;
   q.push(root);
   q.push(NULL);
   while(!q.empty())
   {
    Node* temp = q.front();
    if(temp==NULL)
    {
        cout<<endl;
        q.pop();
        if(!q.empty())
        {
            q.push(NULL);
        }
    }
        else{
            q.pop();
            cout<<temp->data<<" ";
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
        }
    }
   }
   // pointer to the node
Node* levelorderBuild(){
    int d;
    cin>>d;
    Node* root = new Node(d);
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    { 
        Node* current = q.front();
        q.pop();
        int c1,c2;
        cin>>c1>>c2;
        if(c1!=-1)
        {
            current->left=new Node(c1);
            q.push(current->left);
        }
        if(c2!=-1)
        {
            current->right=new Node(c2);
            q.push(current->right);
        }
        
    }

    return root;

}
//helper function 
int height(Node* root)
{
 if(root==NULL)
 {
    return 0;
 }   
 int h1 = height(root->left);
 int h2 = height(root->left);

 return 1+ max(h1,h2)
}
int main()
{
Node *root = levelorderBuild();
// printPreorder(root);
// printInorder(root);
// printPostorder(root);
printLevelOrder(root);
}