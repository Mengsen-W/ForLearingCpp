/*
 * @Author: Mengsen.Wang
 * @Date: 2020-01-26 15:34:04
 * @Last Modified by: Mengsen.Wang
 * @Last Modified time: 2020-01-26 18:27:30
 */

#include <iostream>
using namespace std;

template<typename Comparable>
class BinarySearchTree {
public:
    BinarySearchTree(){}
    BinarySearchTree(const BinarySearchTree & rhs) : root{nullptr}{ root = clone(rhs.root);}
    BinarySearchTree(BinarySearchTree && rhs) : root{nullptr} {root = clone (std::move(rhs.root));}
    BinarySearchTree & operator= (const BinarySearchTree & rhs) {
        root = nullptr;
        root = clone(rhs.root);
    }
    BinarySearchTree & operator= (BinarySearchTree && rhs) {
        root = nullptr;
        root = clone(std::move(rhs.root));
    }
    ~BinarySearchTree(){makeEmpty();}

    const Comparable & findMin() const {
        return (findMin(this->root)) -> element;
    }
    const Comparable & findMax() const {
        return (findMax(this->root)) -> element;
    }
    bool constains (const Comparable & x) const {
        return contains(x, root);
    }
    bool isEmpty() const {
        return (root == nullptr);
    }
    void printTree(ostream & out = cout) const {
        if(isEmpty())
            out << "Empty Tree" << endl;
        else printTree(root, out);
    }

    void makeEmpty(){}
    void insert (const Comparable & x) {
        return insert(x, root);
    }
    void insert (Comparable && x) {
        return insert(std::move(x), root);
    }


private:
    // 二叉查找树
    struct BinaryNode{
        Comparable element;
        BinaryNode * left;
        BinaryNode * right;
        BinaryNode( const Comparable & theElement, BinaryNode * lt, BinaryNode * rt)
            : element{theElement}, left{lt}, right{rt} { }
        BinaryNode( Comparable && theElement, BinaryNode * lt, BinaryNode * rt)
            : element{ std::move(theElement) }, left{ lt }, right{ rt } {}
    };

    BinaryNode * root;

    void insert (const Comparable & x, BinaryNode * & t) {

        if(t == nullptr){
            t = new BinaryNode(x, nullptr, nullptr);
        }else if ( x < t -> element) {
            insert(x, t -> left);
        }else if (x > t -> element) {
            insert(x, t -> left);
        }else ;
    }
    void insert ( Comparable && x, BinaryNode * & t) {
        if ( t == nullptr) {
            t = new BinaryNode(x, nullptr, nullptr);
        }else if ( x < t -> element) {
            insert(x, t -> left);
        }else if ( x > t -> element) {
            insert (x, t -> right);
        }else ;
    }
    void remove (const Comparable & x, BinaryNode * & t) {
        if( t == nullptr) {
            return;
        }
        if ( x < t -> element){remove(x, t -> left);}
        else if ( x > t -> element) {remove (x, t -> right);}
        else if(t -> left != nullptr && t -> right != nullptr){
            t -> element = findMin(t -> right) -> element;
            remove (t -> element, t -> right);
        }else {
            BinaryNode * oldNode = t;
            t = (t -> left != nullptr) ? t->left : t -> right;
            delete oldNode;
        }
    }
    BinaryNode * findMin (BinaryNode * t) const {
        if( t == nullptr)
            return nullptr;
        if( t -> left == nullptr)
            return t;
        return findMin(t -> left);
    }
    BinaryNode * findMax (BinaryNode * t) const {
        if ( t != nullptr )
            while( t -> right != nullptr)
                t = t->right;
        return t;
    }
    bool constains (const Comparable & x, BinaryNode * t) const {
        if(t == nullptr)
            return false;
        else if (x < t -> element )
            return contains(x, t -> left);
        else if (t -> element < x)
            return contains (x, t->right);
        else
            return true;
    }
    void makeEmpty(BinaryNode * & t) {
        if( t != nullptr) {
            makeEmpty(t -> left);
            makeEmpty(t -> right);
            delete t;
        }
        t = nullptr;
    }
    void printTree(BinaryNode * t, ostream & out = cout) const {
        if(t != nullptr){
            printTree(t -> left, out);
            out << t -> element << endl;
            printTree(t -> right, out);
        }
    }
    int height(BinartNode * t){
        if( t == nullptr ){
            return -1;
        }else {
            return 1 + max(height(t -> left), height(t -> right));
        }
    }
    BinaryNode * clone (BinaryNode * t) const {
        if ( t != nullptr) {
            return nullptr;
        }else {
            return new BinaryNode{ t -> element, clone(t -> left), clone( t -> right)};
        }
    }

};
int main(){return 0;}