#include<iostream>
#include<queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void inorder(Node* root){
    if (root == NULL){
        return ;
    }
    inorder(root->left);
    cout<<root->data<< " ";
    inorder(root->right);
}
void preorder(Node* root){
    if (root == NULL){
        return ;

    }
    cout<<root->data<< " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node* root){


    if (root == NULL){
        return ;

    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<< " ";

}


bool SearchingOfBST(Node* root, int X){
    // Base Case.
    if (root == NULL){
        return false;
    }

    if (root->data == X){
        return true;
    }
    if (root->data > X){
         //root->left = (root->left, data);
        return SearchingOfBST(root->left, X);

    } else{

        return SearchingOfBST(root->right, X);
    }
    //return root;
}



void levelOrderTraversal(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout << temp->data << " ";
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

Node* insertIntoBST(Node* &root, int data) {
    if (root == NULL) {
        root = new Node(data);
        return root;
    }
    if (data > root->data) {
        root->right = insertIntoBST(root->right, data);
    } else {
        root->left = insertIntoBST(root->left, data);
    }
    return root;
}
Node* minval (Node* root){
    Node* temp = root;// start with root node of BST.

    while(temp->left != NULL){//initilaize  the  temp pointer to point to the root
        temp = temp->left;// move left repeatedly (temp = temp->left) until the
        //leftmost node is reached to the node with (node->left == NULL).
    }

    return temp;//temp which holds the minimum value.
}
Node* maxval (Node* root){
    Node* temp = root;

    while(temp->right != NULL){
        temp = temp->right;
    }

    return temp;
}  //with algorithm and convert it into the maximum


void takeInput(Node* &root) {
    int data;
    cin >> data;

    while (data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

Node* deleteNode(Node* root, int key){
    if (root == NULL){
        return root; //Base root.
    }

    if (key > root->data){
        root->right = deleteNode(root->right, key);

    }  else if (key< root->data){
        root->left = deleteNode(root->left, key);
    }  else{

        if (root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;

        }

        Node* temp = minval(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}
int main() {
    Node* root = NULL;

    cout << "Enter data to create BST (-1 to stop):" << endl;
    takeInput(root);

    cout<<"Searching of BST: "<<endl;
    int X = 2;
    if(SearchingOfBST(root, X)){
        cout<<"Found" <<endl;
    }
    else{
        cout<<"Not Found"<<endl;
    }
    //SearchingOfBST(root, 27);

    cout<<"Minimum value: " << minval(root)->data<<"\n";

    cout<<"Maximum value: " << maxval(root)->data<<"\n";

    cout<<"deletion of value; "<<deleteNode(root, 27)<<"\n";

    cout << "Printing the BST:" << endl;
    levelOrderTraversal(root);

    cout<<"Printing inorder" <<endl;
    inorder(root);

    cout<<endl<<"Printing preorder" <<endl;
    preorder(root);

    cout<<endl<<"Printing postorder" <<endl;
    postorder(root);

    //cout<<"Printing inorder" <<end;
    //inorder(root);

// 10 8 21 7 27 5 4 3 -1
    return 0;
}
