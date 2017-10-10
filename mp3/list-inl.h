/**
 * @file list.cpp
 * Doubly Linked List (MP 3).
 */

/**
 * Destroys the current List. This function should ensure that
 * memory does not leak on destruction of a list.
 */
 using namespace std;
 #include<iostream>

template <class T>
List<T>::~List() {
  /// @todo Graded in MP3.1
  clear();
}

/**
 * Destroys all dynamically allocated memory associated with the current
 * List class.
 */
template <class T>
void List<T>::clear() {
  /// @todo Graded in MP3.1
  ListNode* curr=head_;

  while(curr!=NULL){
    ListNode* clear=curr;
    curr=curr->next;
    delete clear;

  }

  }


/**
 * Inserts a new node at the front of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <class T>
void List<T>::insertFront(T const& ndata) {
  /// @todo Graded in MP3.1
  ListNode* node=new ListNode(ndata);

  if(length_==0){
    node->prev=NULL;
    node->next=NULL;
    tail_=node;
    head_=node;
  }
  else{

    node->next=head_;

    node->prev=NULL;
    head_->prev=node;
    head_=node;

  }
  length_++;

  }



/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <class T>
void List<T>::insertBack(const T& ndata) {
  /// @todo Graded in MP3.1
  ListNode* node=new ListNode(ndata);
  node->prev=tail_;
  node->next=NULL;
  if(length_==0){
    head_=node;
    tail_=node;
  }
  else{
    tail_->next=node;
    tail_=node;
  }
  length_++;

}


/**
 * Reverses the current List.
 */
template <class T>
void List<T>::reverse() {
  reverse(head_, tail_);
}

/**
 * Helper function to reverse a sequence of linked memory inside a List,
 * starting at startPoint and ending at endPoint. You are responsible for
 * updating startPoint and endPoint to point to the new starting and ending
 * points of the rearranged sequence of linked memory in question.
 *
 * @param startPoint A pointer reference to the first node in the sequence
 *  to be reversed.
 * @param endPoint A pointer reference to the last node in the sequence to
 *  be reversed.
 */
template <class T>
void List<T>::reverse(ListNode*& startPoint, ListNode*& endPoint) {
    /// @todo Graded in MP3.1
    if(startPoint == endPoint||startPoint == NULL || endPoint == NULL)
   	       return;
  	ListNode * start = startPoint;
  	ListNode * start_prev = startPoint->prev;
  	ListNode * end = endPoint;
  	ListNode * end_next = endPoint->next;
  	while(startPoint != endPoint)
  	{
  		ListNode * temp = startPoint->prev;
  		startPoint->prev = startPoint->next;
  		startPoint->next = temp;
  		startPoint = startPoint->prev;
  	}
  	ListNode * temp = startPoint->prev;
  	startPoint->prev = start_prev;
  	startPoint->next = temp;
  	endPoint = start;
  	endPoint->next = end_next;
  	if(start_prev == NULL)
  	//it starts from the head
  		head_= startPoint;
  	else
  		start_prev->next = startPoint;
  	if(end_next == NULL)
  	//it ends at the tail
  		tail_= endPoint;
  	else
  		end_next->prev = endPoint;


}



/**
 * Reverses blocks of size n in the current List. You should use your
 * reverse( ListNode * &, ListNode * & ) helper function in this method!
 *
 * @param n The size of the blocks in the List to be reversed.
 */
template <class T>
void List<T>::reverseNth(int n) {
  /// @todo Graded in MP3.1
    ListNode* startPoint;
    ListNode* endPoint;
    ListNode* temp;

    temp=head_;
  if(n>=length_){

    reverse();
  }
  else{

    startPoint=temp;

    for(int i=0;i<n-1;i++){
    endPoint=temp->next;
  temp=temp->next;
}
  reverse(startPoint,endPoint);

for(int count=0;count<length_/n;count++){
  if(endPoint!=tail_){
  temp=endPoint->next;
  startPoint=temp;
  for(int i=0;i<n-1;i++){
    if(temp->next==NULL){
      endPoint=temp;
      break;
    }
  endPoint=temp->next;
  temp=temp->next;
}}
else{
  return;
}

reverse(startPoint,endPoint);}

  }

}

/**
 * Modifies the List using the waterfall algorithm.
 * Every other node (starting from the second one) is removed from the
 * List, but appended at the back, becoming the new tail. This continues
 * until the next thing to be removed is either the tail (**not necessarily
 * the original tail!**) or NULL.  You may **NOT** allocate new ListNodes.
 * Note that since the tail should be continuously updated, some nodes will
 * be moved more than once.
 */
template <class T>
void List<T>::waterfall() {
  /// @todo Graded in MP3.1
  ListNode* curr=head_;
  ListNode* pre;
  ListNode* post;
  ListNode* temp;
  int i=0;
  while (curr!=tail_) {
    if(curr!=head_){
      pre=curr->prev;
      }
    post=curr->next;
    if(i%2!=0){

      pre->next=post;
      post->prev=pre;

      temp=curr;

      curr=curr->next;

    tail_->next=temp;
    temp->prev=tail_;
    temp->next=NULL;
    tail_=temp;}
    else{
      curr=curr->next;

    }
    i++;

    }
    /* code */
  }





/**
 * Splits the given list into two parts by dividing it at the splitPoint.
 *
 * @param splitPoint Point at which the list should be split into two.
 * @return The second list created from the split.
 */
template <class T>
List<T> List<T>::split(int splitPoint) {
    if (splitPoint > length_)
        return List<T>();

    if (splitPoint < 0)
        splitPoint = 0;

    ListNode* secondHead = split(head_, splitPoint);

    int oldLength = length_;
    if (secondHead == head_) {
        // current list is going to be empty
        head_ = NULL;
        tail_ = NULL;
        length_ = 0;
    } else {
        // set up current list
        tail_ = head_;
        while (tail_->next != NULL)
            tail_ = tail_->next;
        length_ = splitPoint;
    }

    // set up the returned list
    List<T> ret;
    ret.head_ = secondHead;
    ret.tail_ = secondHead;
    if (ret.tail_ != NULL) {
        while (ret.tail_->next != NULL)
            ret.tail_ = ret.tail_->next;
    }
    ret.length_ = oldLength - splitPoint;
    return ret;
}

/**
 * Helper function to split a sequence of linked memory at the node
 * splitPoint steps **after** start. In other words, it should disconnect
 * the sequence of linked memory after the given number of nodes, and
 * return a pointer to the starting node of the new sequence of linked
 * memory.
 *
 * This function **SHOULD NOT** create **ANY** new List objects!
 *
 * @param start The node to start from.
 * @param splitPoint The number of steps to walk before splitting.
 * @return The starting node of the sequence that was split off.
 */
template <class T>
typename List<T>::ListNode* List<T>::split(ListNode* start, int splitPoint) {
    /// @todo Graded in MP3.2
    if(start==NULL){

      return NULL;
    }
    else if (splitPoint==0){

      return start;
    }
    else{ListNode* temp=start;
        ListNode* split;
        for (int i=0;i<splitPoint-1;i++){

            temp=temp->next;

          }
    split=temp->next;

    temp->next=NULL;

    this->tail_=temp;
    split->prev=NULL;
    return split;
  }
}

/**
 * Merges the given sorted list into the current sorted list.
 *
 * @param otherList List to be merged into the current list.
 */
template <class T>
void List<T>::mergeWith(List<T>& otherList) {
    // set up the current list
    head_ = merge(head_, otherList.head_);
    tail_ = head_;

    // make sure there is a node in the new list
    if (tail_ != NULL) {
        while (tail_->next != NULL)
            tail_ = tail_->next;
    }
    length_ = length_ + otherList.length_;

    // empty out the parameter list
    otherList.head_ = NULL;
    otherList.tail_ = NULL;
    otherList.length_ = 0;
}

/**
 * Helper function to merge two **sorted** and **independent** sequences of
 * linked memory. The result should be a single sequence that is itself
 * sorted.
 *
 * This function **SHOULD NOT** create **ANY** new List objects.
 *
 * @param first The starting node of the first sequence.
 * @param second The starting node of the second sequence.
 * @return The starting node of the resulting, sorted sequence.
 */
template <class T>
typename List<T>::ListNode* List<T>::merge(ListNode* first, ListNode* second) {
  /// @todo Graded in MP3.2
  if(NULL == first) return first;
     if(NULL == second) return second;

     ListNode* head=NULL;    // head of the list to return

     // find first element (can use dummy node to put this part inside of the loop)
     if(first->data < second->data)       { head = first; first = first->next; }
     else                        { head = second; second = second->next; }

     ListNode* p = head;     // pointer to form new list

     // I use && to remove extra IF from the loop
     while(first && second){
         if(first->data < second->data)   { p->next = first; first = first->next; }
         else                    { p->next = second; second = second->next; }
         p=p->next;
     }

     // add the rest of the tail, done!
     if(first)  p->next=first;
     else    p->next=second;

     return head;

}

/**
 * Sorts the current list by applying the Mergesort algorithm.
 */
template <class T>
void List<T>::sort() {
    if (empty())
        return;
    head_ = mergesort(head_, length_);
    tail_ = head_;
    while (tail_->next != NULL)
        tail_ = tail_->next;
}

/**
 * Sorts a chain of linked memory given a start node and a size.
 * This is the recursive helper for the Mergesort algorithm (i.e., this is
 * the divide-and-conquer step).
 *
 * @param start Starting point of the chain.
 * @param chainLength Size of the chain to be sorted.
 * @return A pointer to the beginning of the now sorted chain.
 */
template <class T>
typename List<T>::ListNode* List<T>::mergesort(ListNode* start, int chainLength) {
    /// @todo Graded in MP3.2
    if (chainLength==1){return start;}
    ListNode* temp=split(start,chainLength/2);
    return merge(mergesort(start,chainLength/2),mergesort(temp,chainLength-chainLength/2));



}
