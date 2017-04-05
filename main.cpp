//H. Eren Çalýk
//21402338
//Section 1
//

#include <iostream>
#include "AVLTree.h"
#include <string>
#include <fstream>

using namespace std;
//-----------------------------------------------AVLTree.cpp
AVLTree::AVLTree(){
	root=NULL;
}

AVLTree::~AVLTree(){
}

void AVLTree::singleRightRotate(AVLNode * & node) 
{
    AVLNode * temp;
    temp = node->right;
    node->right = temp->left;
    temp->left = node;
    node->height = max(avlHeight(node->left),avlHeight(node->right)) + 1;
    node = temp;
    temp->height = max(node->height,avlHeight(temp->right)) + 1;
}

void AVLTree::singleLeftRotate(AVLNode * & node)
{
    AVLNode * temp;
    temp = node->left;
    node->left = temp->right;
    temp->right = node;
    node->height = max(avlHeight(node->left),avlHeight(node->right)) + 1;
    node = temp;
    temp->height = max(avlHeight(temp->left),node->height) + 1;
}

void AVLTree::doubleRightRotate(AVLNode * & node)
{
    singleLeftRotate(node->right);
    singleRightRotate(node);
}

void AVLTree::doubleLeftRotate(AVLNode * & node)
{
    singleRightRotate(node->left);
    singleLeftRotate(node);
}

int AVLTree::max(int num1, int num2)
{
    return ((num1 > num2) ? num1 : num2);
}

int AVLTree::avlHeight(AVLNode * node) //height finder to check if subtrees are balanced
{
    int num;
    if( node == NULL)
    {
        return -1;
    }
    else
    {
        num = node->height;
        return num;
    }

}

bool AVLTree::isThere(const string& str, AVLNode *& node) //checks if the string is the key of a node
{
    if(node == NULL)
    {
        return false;
    }

    if(str > node->item )
    {
        return isThere(str, node->right);
    }

    if(str < node->item)
    {
        return isThere(str, node->left);
    }
    
    return true;
}

bool AVLTree::isThere(const string &str)
{
    return isThere(str, root);
}


void AVLTree::insert(const string & str, AVLNode* & node) //insertion 
{
    if (node == NULL)
    {
        node = new AVLNode(str , NULL, NULL, 0);
    }
    else
    {
        if (str > node->item)
        {
            insert(str, node->right);  
		
            if ((avlHeight(node->right) - avlHeight(node->left))==2) //rotations if not balanced
            {
                if (str > node->right->item)
                {
                    singleRightRotate(node);
                }
                else
                {
                    doubleRightRotate(node);
                }
            }
        }
     	else if (str < node->item) 
        {
            insert(str, node->left);  

            if ((avlHeight(node->left) - avlHeight(node->right))==2) //rotations if not balanced
            {
                if (str < node->left->item)
                {
                    singleLeftRotate(node);
                }
                else
                {
                    doubleLeftRotate(node);
                }
            }
        }
        else
        {
            ;
        }
    }
    //updating the heights of nodes
    int num1,num2,maxNum;
    num1 = avlHeight(node->left);
    num2 = avlHeight(node->right);
    maxNum = max(num1,num2);
    node->height = maxNum + 1;
}

void AVLTree::insert(const string & str){
	insert(str,root);
}

void AVLTree::findOthers(const string& str, AVLNode *& node) //method that prints the items of the node if the given string
{							     //is a substring of the item
    if(node == NULL)
    {
        return;
    }

    if(str > node->item.substr(0,str.length()))
    {
        findOthers(str, node->right);
    }

    if(str < node->item.substr(0,str.length()))
    {
        findOthers(str, node->left);
    }
    if(str==node->item.substr(0,str.length()))
    {
	findOthers(str, node->left);
	cout<<node->item<<" ";
	findOthers(str, node->right);
	
    }
}
    

void AVLTree::findOthers(const string & str,int size){
	string temp = str.substr(0,size);
	findOthers(temp,root);
}

bool AVLTree::isThereSub(const string& str, AVLNode *& node) //method that checks if the given string is a substring of
{							     //the item of the node
	if(node == NULL)
    {
        return false;
    }

    if(str > node->item.substr(0,str.length()))
    {
        return isThereSub(str, node->right);
    }

    if(str < node->item.substr(0,str.length()))
    {
        return isThereSub(str, node->left);
    }
    if(str==node->item.substr(0,str.length()))
	return true;
    return false;
}

bool AVLTree::isThereSub(const string &str,int size)
{
    string temp = str.substr(0,size);
    return isThereSub(temp, root);
}

int main(){
	bool loopCont = true;
	AVLTree dictionary;
	fstream in;
 
   
	in.open("dictionary.txt");
    
	if (in.is_open()) {
  
	
        string x;
 
	        while (in >> x) {
		        dictionary.insert(x);
 
		}
        
		in.close();
    
	}
	
		cout << "Welcome to Dothraki Vocabulary! \n";
		cout << "This vocabulary contanins 378 words.\n";
		string str;

	while(loopCont){ //the loop to interact with user
		cout<<endl;
		cout<<"Enter a word: ";
		cin >> str;
		cout<<endl;
		if(str=="quit"||str=="QUIT"||str=="Quit")
			break;
		if(dictionary.isThere(str))
			cout<<"Found! The word is in vocabulary."<<endl;//if found, do nothing
		else{
			cout<<"Not Found!"<<endl;
			int length=str.length();
			if(length%2==0)
				length=length/2;
			else length=length/2+1;
			
			if(dictionary.isThereSub(str,length)){ //if not found, check if there will be suggestions
				cout<<"Some suggestions: ";
				dictionary.findOthers(str,length);
				cout<<endl;
			}
			else cout<<"There are no suggestions."<<endl;
		}
	}
	cout<<"Goodbye!";
}













