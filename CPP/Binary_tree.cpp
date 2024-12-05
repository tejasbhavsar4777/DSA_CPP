#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;

    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

};

node* buildTree(node* root){

    cout<<"Enter the data: "<<endl;
    int data;
    cin>> data;
    root = new node(data);

    if (data == -1){
        return NULL;
    }

    cout<<"Enter the data for insering in left of "<< data <<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for inserting in right of: "<< data <<endl;
    root->right = buildTree(root->right);
    return root;

}
void levelOrderTraversal(node* root ){

    queue<node*> q;
    q.push(root);

    while(q.empty() == false){
        node* temp = q.front();
        cout<<temp->data<< " ";
        q.pop();

        if (temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }

        if(temp -> left){
            q.push(temp -> left);
        }

        if(temp->right){
            q.push(temp -> right);
        }
    }

}
int main(){
    node* root = NULL;

    root = buildTree(root);

    //level order
    cout<<"printing the level order tranvresal: "<<endl;
    levelOrderTraversal(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1


    return 0;

}
