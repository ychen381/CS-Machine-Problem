/**
 * @file avltree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */

template <class K, class V>
V AVLTree<K, V>::find(const K& key) const
{
    return find(root, key);
}

template <class K, class V>
V AVLTree<K, V>::find(Node* subtree, const K& key) const
{
    if (subtree == NULL)
        return V();
    else if (key == subtree->key)
        return subtree->value;
    else {
        if (key < subtree->key)
            return find(subtree->left, key);
        else
            return find(subtree->right, key);
    }
}

template <class K, class V>
void AVLTree<K, V>::rotateLeft(Node*& t)
{
    functionCalls.push_back("rotateLeft"); // Stores the rotation name (don't remove this)
    // your code here
    Node* temp = t -> right;
    t -> right = temp -> left;
    temp-> left = t;
    t -> height = max(heightOrNeg1(t -> left),heightOrNeg1(t -> right))+1;
    t = temp;
    t -> height = max(heightOrNeg1(t -> left),heightOrNeg1(t -> right))+1;
}

template <class K, class V>
void AVLTree<K, V>::rotateLeftRight(Node*& t)
{
    functionCalls.push_back("rotateLeftRight"); // Stores the rotation name (don't remove this)
    // Implemented for you:
    rotateLeft(t->left);
    rotateRight(t);
}

template <class K, class V>
void AVLTree<K, V>::rotateRight(Node*& t)
{
    functionCalls.push_back("rotateRight"); // Stores the rotation name (don't remove this)
    // your code here
    Node* temp = t -> left;
    t -> left = temp -> right;
    temp -> right = t;
    t -> height = max(heightOrNeg1(t->left),heightOrNeg1(t->right))+1;
    t = temp;
    t -> height = max(heightOrNeg1(t -> left), heightOrNeg1(t->right))+1;
}

template <class K, class V>
void AVLTree<K, V>::rotateRightLeft(Node*& t)
{
    functionCalls.push_back("rotateRightLeft"); // Stores the rotation name (don't remove this)
    // your code here
    rotateRight(t -> right);
    rotateLeft(t);
}

template <class K, class V>
void AVLTree<K, V>::rebalance(Node*& subtree)
{
    // your code here
    if(heightOrNeg1(subtree -> right) - heightOrNeg1(subtree -> left) == 2){
      if(heightOrNeg1(subtree -> right -> right) - heightOrNeg1(subtree -> right -> left)==1)
        rotateLeft(subtree);
      else
        rotateRightLeft(subtree);
    }
    else if(heightOrNeg1(subtree -> right) - heightOrNeg1(subtree -> left) == -2){
      if(heightOrNeg1(subtree -> left -> right) - heightOrNeg1(subtree -> left -> left) ==-1)
        rotateRight(subtree);
      else
        rotateLeftRight(subtree);
    }
    else
     subtree -> height = max(heightOrNeg1(subtree -> left),heightOrNeg1(subtree -> right))+1;
}

template <class K, class V>
void AVLTree<K, V>::insert(const K & key, const V & value)
{
    insert(root, key, value);
}

template <class K, class V>
void AVLTree<K, V>::insert(Node*& subtree, const K& key, const V& value)
{
    if(subtree == NULL){
      subtree = new Node(key,value);
    }
    else if(key < subtree -> key){
      insert(subtree -> left, key, value);
      rebalance(subtree);
    }
    else if(key > subtree -> key){
      insert(subtree -> right, key, value);
      rebalance(subtree);
    }
    subtree -> height = max(heightOrNeg1(subtree -> left), heightOrNeg1(subtree -> right)) + 1;
}

template <class K, class V>
void AVLTree<K, V>::remove(const K& key)
{
    remove(root, key);
}

template <class K, class V>
void AVLTree<K, V>::remove(Node*& subtree, const K& key)
{
    if (subtree == NULL)
        return;

    if (key < subtree->key) {
        // your code here
        remove(subtree -> left, key);
        rebalance(subtree);
    } else if (key > subtree->key) {
        // your code here
        remove(subtree -> right, key);
        rebalance(subtree);
    } else {
        if (subtree->left == NULL && subtree->right == NULL) {
            /* no-child remove */
            // your code here
            delete(subtree);
            subtree = NULL;
            //rebalance(subtree);
        } else if (subtree->left != NULL && subtree->right != NULL) {
            /* two-child remove */
            // your code here
            Node* temp = subtree -> left;
            while(temp -> right != NULL){
              temp = temp -> right;
            }
            swap(temp,subtree);
            remove(subtree -> left, temp -> key);
            //rebalance(subtree);
        } else {
            if(subtree -> left == NULL){
              Node* temp = subtree;
              subtree = subtree -> right;
              delete(temp);
            }
            else if(subtree -> right == NULL){
              Node* temp = subtree;
              subtree = subtree -> left;
              delete(temp);
            }

            /* one-child remove */
            // your code here
        }
        // your code here
        if(subtree!=NULL)
        rebalance(subtree);
    }
    return;
}
