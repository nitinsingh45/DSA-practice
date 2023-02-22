#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};
void levelOrderTraversal(Node* root){
        queue<Node*>q;
        q.push(root);
        q.push(NULL);//for making space after root element
        while(!q.empty()){
            Node* temp=q.front();
           
            q.pop();
            if(temp==NULL){
                cout<<endl;
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                 cout<<temp->data<<" ";
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
        }
    }
Node *insertIntoBst(Node* root,int d){
    if(root==NULL){
        root=new Node(d);
        return root;
    }
    if(d>root->data){
        root->right=insertIntoBst(root->right,d);
    }
    else{
        root->left=insertIntoBst(root->left,d);
    }
    return root;
}
void takeInput(Node* root){
    int data;
    while(data!=-1){
        root=insertIntoBst(root,data);
        cin>>data;
    }
}
int main(){
    Node* root=NULL;
    cout<<"enter the data to create BST"<<endl;
    takeInput(root);
    cout<<"printing BST"<<endl;
    levelOrderTraversal(root);
    return 0;
}

