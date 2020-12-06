#include<bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node * left;
	node * right;
	
	node(int data){
		this->data = data;
		this->left= NULL;
		this->right = NULL;
	}
	node(){
		this->data = 0;
		this->left= NULL;
		this->right = NULL;	
	}
};

node * construct_tree(node * root){
	node * temp = root;
	temp->right = new node(22);
	temp->left = new node(8);
	temp = temp->left;
	temp->left = new node(4);
	temp->right = new node(12);
	temp = temp->right;
	temp->left = new node(10);
	temp->right = new node(14);
	return root;
}

node * find_node(node * root, int data){
	if(root == NULL) return NULL;
	if(root->data == data) return root;
	
	node * temp1;
	if(root->left != NULL) temp1 = find_node(root->left, data);
	node * temp2;
	if(root->right != NULL) temp2 = find_node(root->right, data);
	if(temp1) return temp1;
	else return temp2;
}


void print(node *root, int k)
{
    if(root==NULL || k<0)
        return;
    if(k==0)
    {
        cout<<root->data<<" ";
        return;
    }
    print(root->left,k-1);
    print(root->right,k-1);
}
 
int Solution(node * root, node * target , int k)
{
    if(root==NULL)
        return -1;
    if(root==target)
    {
        print(root,k);
        return 0;
    }
    
    int dl=Solution(root->left,target,k);
    
    if(dl!=-1)
    {
        if(dl+1==k)
            cout<<root->data<<" ";
        else
            print(root->right,k-dl-2);
        return dl+1;
    }
    
    int dr=Solution(root->right,target,k);
    
    if(dr!=-1)
    {
        if(dr+1==k)
            cout<<root->data<<" ";
        else
            print(root->left,k-dr-2);
        return dr+1;
    }
    return -1;
}

int main(){
	node * root = new node(20);
	construct_tree(root);
	int data;
	cout<<"enter the target data"<<endl;
	cin>>data;
	node * target = find_node(root, data);
	int k;	
	cout<<"enter the value of k"<<endl;
	cin>>k;
	Solution(root, target, k);
	return 0;
}
	
	

