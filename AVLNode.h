//H. Eren Çalýk
//21402338
//Section 1
//
#include <string>
//---------------------------------------------AVLNode.h
class AVLNode {
private:
    std::string item;
    int height;
    AVLNode *left, *right;
    int avlHeight (AVLNode * h);
    AVLNode(const std::string &str, AVLNode* lf, AVLNode* rg, int h){item = str; left = lf;  right = rg; height = h;};
    
    friend class AVLTree;

};