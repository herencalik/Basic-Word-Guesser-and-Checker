//H. Eren Çalýk
//21402338
//Section 1
//
#include "AVLNode.h"
#include <string>
//----------------------------------------------AVLTree.h
class AVLTree{
private:
	 AVLNode* root;
	 void singleRightRotate(AVLNode * & n);
    	 void doubleRightRotate(AVLNode * & n);
    	 void singleLeftRotate(AVLNode * & n);
    	 void doubleLeftRotate(AVLNode * & n);
	 void insert(const std::string & str, AVLNode * & node);
	 bool isThere( const std::string& str, AVLNode * & node);
	 bool isThereSub( const std::string& str, AVLNode * & node);
	 void findOthers(const std::string & str,AVLNode * & node);
    	 
public:	
	AVLTree();
	~AVLTree();
	void insert(const std::string & str);
	void findOthers(const std::string & str,int size);
	bool isThere(const std::string &str);
	bool isThereSub(const std::string &str,int size);
	int avlHeight (AVLNode * node);
	int max(int num1, int num2);
};