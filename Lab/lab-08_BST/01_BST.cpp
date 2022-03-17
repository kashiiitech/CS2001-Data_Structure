#include<iostream>
// #include<list>
#include <queue>
using namespace std;

class Tree {
    public:
    int data;
    Tree *left, *right;

    Tree() {
        left = right = NULL;
    }
};

Tree* newNode(int data) {
   Tree *temp = new Tree;
   temp->data = data;
   temp->left = temp->right = NULL;
   return temp;
}


Tree* insert(Tree* n, int val) {
    if( n== NULL) {
        n = new Tree;
        n->data = val;

        n->left = n->right = NULL;
    }


    else if(val < n->data) {
        n->left = insert(n->left, val);
    }

    else if(val > n->data) {
        n->right = insert(n->right, val);
    }

    return n;
}


// Searching

// void Search(Tree *node, int val) {
//     if(node == NULL || node->data == val) {
//         cout<<"Value found"<<endl;
//     }

//     else if(val < node->data) 
//     Search(node->left, val);

//     else if(val > node->data)
//     Search(node->right, val);
// }


// Inorder traversal
void InOrder(Tree* node) {
    if(node == NULL) {
        return;
    }
    InOrder(node->left);
    cout<<node->data<<" ";
    InOrder(node->right);
}

// Postorder Traversal

void PostOrder(Tree *node) {
    if(node == NULL) 
    {
        return;
    }

    PostOrder(node->left);
    PostOrder(node->right);
    cout<<node->data<<" ";
}

// PreOrder traversal

void PreOrder(Tree *node) {
    if(node == NULL ){
        return;
    }

    cout<<node->data<<" ";

    PreOrder(node->left);
    PreOrder(node->right);
}


// Height of the Tree

int Height( Tree *node) {
    if(node == NULL ) {
        return -1;
    }

    else {
        int h_left = Height(node->left);
        int h_right = Height(node->right);

        if(h_left > h_right) {
            return (h_left+1);
        }
        else
        return (h_right+1);
    }
}


// Minimum

int min(Tree *node) {
    if(node == NULL) {
        return 0;
    }
    else if(node->left==NULL) {
        return node->data;
    }

    else
    return min(node->left);
}


// Maximum

Tree* max(Tree *node) {
    if(node == NULL) {
        return 0;
    }
    else if(node->right==NULL) {
        return node;
    }

    else
    return max(node);
}


// Finding Predecessor

Tree* Predecessor(Tree *node) {
    if(node->left != NULL) {
        return max(node->left);
    }
    return NULL;

}


int main() {

//     Tree *root = newNode(1);
//    root->left = newNode(2);
//    root->right = newNode(3);
//    root->left->left = newNode(4);
//    root->left->right = newNode(5);
   cout << "Level Order traversal of binary tree is \n";
    // cout<<"Hello wordl";

    Tree *root = newNode(34);
    root = insert(root, 29);
    root = insert(root, 65);
    root = insert(root, 21);
    root = insert(root, 31);
    root = insert(root, 43);
    root = insert(root, 87);
    root = insert(root, 28);
    // root = insert(root, 28);
    root = insert(root, 30);
    root = insert(root, 56);
    // root = insert(root, 2);


    // for (int i = 0; i <= 5; i++)
    // {
    //     root = insert(root, i);
    // }
    
    // cout<<"PreOrder"<<endl;
    // PreOrder(root);
    // cout<<endl;

    // cout<<"InOrder"<<endl;
    // InOrder(root);
    // cout<<endl;

    // cout<<"PostOrder"<<endl;
    // PostOrder(root);
    // cout<<endl;

    // cout<<"Height of the Tree is: "<<endl;
    // cout<<Height(root)<<endl;

    // cout<<"Finding Minimum ..."<<endl;
    // cout<<min(root)<<endl;

    queue<Tree *> q;
   q.push(root);
   while (q.empty() == false) {
      Tree *node = q.front();
    //   cout << node->data << " ";
      q.pop();
      if (node->left != NULL)
      {
        //   int min = 1000;
        //  q.push(node->left);
        // //  cout<<"hello"<<node->left->data<<endl;
        // if(node->left->data < min){
        //     min = node->left->data;
        //     cout<<min<<" ";
        //     cout<<endl;
        // }

        //  if(q.front())

    //   cout<<endl;
        // int max = -1000;
      if (node->right != NULL){
          int max = -1000;
         q.push(node->right);
        //  cout<<"hello"<<node->right->data<<endl;
        while(node->right->data > max){
            max = node->right->data;
            cout<<max<<" ";
            cout<<endl;
            }

      }
      }
   }




    // cout<<"Finding Maximum ..."<<endl;
    // cout<<max(root)<<endl;


    // cout<<"Predecessor value ..."<<endl;
    // Predecessor(root);

    
    // cout<<"Searching ... "<<endl;
    // cout<<Search(root, 2);


//     queue<Tree *> q;
//    q.push(root);
//    while (q.empty() == false) {
//       Tree *node = q.front();
//       cout << node->data << " ";
//       q.pop();
//       if (node->left != NULL)
//          q.push(node->left);
//       if (node->right != NULL)
//          q.push(node->right);
//    }
    return 0;
}






