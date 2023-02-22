#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    node(int d){   //constructor
        this->data=d;   
        this->left=NULL;
        this->right=NULL;
    }
};
node* buildTree(node* root){
    cout<<"enter the data"<<endl;
    int data;
    cin>>data;
    root=new node(data);  // to allocate memory in heap
    if(data==-1){
        return NULL;
    }
    cout<<"enter the data for inserting in left"<<endl;
    root->left=buildTree(root->left);
    cout<<"enter the data for insterting in right"<<endl;
    root->right=buildTree(root->right);
    return root;   
}
void levelOrderTraversal(node* root){
        queue<node*>q;
        q.push(root);
        q.push(NULL);//for making space after root element
        while(!q.empty()){
            node* temp=q.front();
           
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
int main(){
    node* root=NULL;
    //creating a tree
    root=buildTree(root);
    cout<<"printing the level order traversal"<<endl;
    levelOrderTraversal(root);
    
    return 0;
}
