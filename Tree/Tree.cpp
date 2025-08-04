#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int info;
    Node* left;
    Node* right;
    int height;
};

void init(Node*& root) {
    root = nullptr;
}

//int height(Node* root) {
//    return root == nullptr ? 0 : root->height;
//}
//int balanceFactor(Node* root) {
//    return root == nullptr ? 0 : height(root->left) - height(root->right);
//}
//
//Node* leftRotate(Node*& p) {
//    Node* q = p->right;
//    Node* r = q->left;
//    
//    p->right = r;
//    q->left = p;
//    p->height = max(height(p->left),height(p->right)) + 1;
//    q->height = max(height(q->left),height(q->right)) + 1;
//    return q;
//}
//
//Node* rightRotate(Node*& p) {
//    Node* q = p->left;
//    Node* r = q->right;
//
//    p->left = r;
//    q->right = p;
//    p->height = max(height(p->left), height(p->right)) + 1;
//    q->height = max(height(q->left), height(q->right)) + 1;
//    return q;
//
//}

//Node* balancing(Node*& p, int x) {
//    int balance = balanceFactor(p);
//    if (balance > 1 && x < p->left->info) {
//        return rightRotate(p);
//    }
//    if (balance < -1 && x > p->right->info) {
//        return leftRotate(p);
//    }
//    if (balance > 1 && x > p->left->info) {
//        p->left = leftRotate(p->left);
//
//        return rightRotate(p);
//    }
//    if (balance < -1 && x < p->right->info) {
//        p->right = rightRotate(p->right);
//        return leftRotate(p);
//    }
//}

Node* createNode(int x) {
    Node* p = new Node();
    p->info = x;
    p->left = nullptr;
    p->right = nullptr;
    p->height = 1;
    return p;
}

//b
void addNode(Node*& root, int x) {
    if (root == nullptr) {
        root = createNode(x);
        return;
    }
    else if(x < root->info){
        addNode(root->left, x);
    }
    else {
        addNode(root->right, x);
    }

}

//c
void LNR(Node* root) {
    if (root != nullptr) {
        LNR(root->left);
        cout << root->info << " ";
        LNR(root->right);
    }
}

//d
void delNode(Node*& root,int x) {
    if (root != NULL) {
        if (x > root->info) {
            delNode(root->right, x);
        }
        else if (x < root->info) {
            delNode(root->left,x);
        }
        else {
            if (root->left == nullptr && root->right == nullptr) {
                Node* p = root;
                root = nullptr;
                delete p;
                return;
            }
            
            else if (root->left != nullptr && root->right != nullptr) {
                Node* p = root->right;
                while (p->left != nullptr) {
                    p = p->left;
                }
                root->info = p->info;
                delNode(root->right, p->info);
            }
            else  {
                Node* p = root;
                if (root->left == nullptr) {
                    root = root->right;
                }
                else if (root->right == nullptr) {
                    root = root->left;
                }
                delete p;
                return;
            }


        }

    }
}

//Node* addAVL(Node*& p,int x) {
//    addNode(p,x);
//    p->height = max(height(p->left), height(p->right)) + 1;
//    return balancing(p, x);
//}
//
//Node* delAVL(Node* &p, int x) {
//    delNode(p,x);
//    if (p != nullptr) {
//        p->height = max(height(p->left), height(p->right)) + 1;
//        return balancing(p,x);
//    }
//
//}
int countLa(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    if (root->right == nullptr && root->left == nullptr) {
        return (countLa(root->left) + countLa(root->right))+1;
    }
    return countLa(root->left) + countLa(root->right);
}
int countSL(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    return (countSL(root->left) + countSL(root->right)) + 1;
}

int countIf(Node* root,int x) {
    if (root == nullptr) {
        return 0;
    }
    if (root->info >= x) {
        return (countIf(root->left,x) + countIf(root->right,x)) + 1;
    }
    return countIf(root->left, x) + countIf(root->right, x);
}
int height2(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    return max(height2(root->right),height2(root->left)) + 1;
}

void xuatMuc(Node* root, int k, int i = 0) {
    if (root != nullptr) {
        if (i == k) {
            cout << root->info << " ";
            i++;
            xuatMuc(root->left,k,i);
            xuatMuc(root->right, k, i);
        }
        i++;
        xuatMuc(root->left, k, i);
        xuatMuc(root->right, k, i);
    }


}


void LNRSTACK(Node* root) {
    stack<Node*> s;
    Node* tmp = root;
    while (tmp != nullptr || !empty(s)) {
        while (tmp != nullptr) {
            s.push(tmp);
            tmp = tmp->left;
        }
        tmp = s.top();
        s.pop();
        cout << tmp->info << " ";
        tmp = tmp->right;
    }
    
}

void clearNode(Node*& root) {
    if (root != nullptr) {
        while (root != nullptr) {
            delNode(root, root->info);
        }
    } 
}





int main()
{
    Node* root;
    init(root);
    addNode(root, 30);
    addNode(root, 20);
    addNode(root, 50);
    addNode(root, 60);
    addNode(root, 25);
  
    
    LNRSTACK(root);
    cout << endl;
    
    cout << countLa(root) << endl;
    cout << countSL(root) << endl;
    cout << countIf(root, 60) << endl;
    cout << height2(root) << endl;
    xuatMuc(root,1);
    cout << endl;
    clearNode(root);
    if (root == nullptr) {
        cout << "Rong \n";
    }

    return 0;
}

