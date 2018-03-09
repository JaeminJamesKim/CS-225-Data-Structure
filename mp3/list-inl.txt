/**
 * @file list.cpp
 * Doubly Linked List (MP 3).
 */

/**
 * Destroys the current List. This function should ensure that
 * memory does not leak on destruction of a list.
 */
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
  ListNode * del = this->head_;
	ListNode * next = NULL;
	while(del!=NULL){
		next = del->next;
		delete del;
		del = next;
		if(del==this->tail_){
			delete del;
			head_=NULL;
			tail_=NULL;
			del=NULL;
			length_ = 0;
		}
}
}

/**
 * Inserts a new node at the front of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <class T>
void List<T>::insertFront(T const & ndata) {
  /// @todo Graded in MP3.1
  ListNode* addition = new ListNode(ndata);
	if(length_==0){
		head_=addition;
		tail_=addition;
	}else{
		head_->prev = addition;
		addition->next = head_;
		head_ = addition;
		addition->prev=NULL;
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
void List<T>::insertBack(const T & ndata) {
  /// @todo Graded in MP3.1
  ListNode* addition = new ListNode(ndata);
	if(length_==0){
		head_=addition;
		tail_=addition;
	}else{
		tail_->next = addition;
		addition->prev = tail_;
		tail_ = addition;
		addition->next=NULL;
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
void List<T>::reverse(ListNode *& startPoint, ListNode *& endPoint) {
  /// @todo Graded in MP3.1
  if(length_==0||startPoint==endPoint){
		return;
	}
	int i = 0;
	ListNode* current = startPoint;
	ListNode* temp = NULL;
	ListNode* counter = startPoint;
	ListNode* prevstart=startPoint->prev;
	ListNode* start = startPoint;
	ListNode* endP = endPoint;
	while(counter!=endPoint->next){
		i++;
		counter=counter->next;
	}
	for(int n=0;n<i;n++){
		if ((n!=0)){
			temp=current->prev;
		}else{
			temp=endPoint->next;
		}
		current->prev=current->next;
		current->next=temp;
		current=current->prev;
	}
	if(startPoint==head_){
		head_=endP;
	}
	if(endPoint==tail_){
		tail_=start;
	}
	//temp=start;
	startPoint=endP;
	endPoint=start;
	if(endPoint->next!=NULL){
		endPoint->next->prev=endPoint;
	}
	startPoint->prev=prevstart;
	if(startPoint->prev!=NULL){
		startPoint->prev->next=startPoint;
	}
	temp = NULL;
current=NULL;
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
  if(length_==0)
		return;
	ListNode* hate1=head_;
	ListNode* hate2 = head_;
	for(int i=0;i<length_/n;i++){
		//cout<<"iterativenessman "<<i<<" out of "<<length/n<<endl;
		for(int j=1;j<n;j++){
			//cout<<"iteration number "<<j<<endl;
			hate1=hate1->next;
			//cout<<"iteration number "<<j<<endl;
		}
		//cout<<"iterativenessman "<<i<<endl;
		reverse(hate2,hate1);
		//ListNode* temp= hate1;  //why is this code here?
		hate2=hate1->next;
		//hate1=temp; //not sure why i did this
		hate1=hate1->next;
	}
	while((hate1!=tail_)&&(hate1!=NULL)){
		hate1=hate1->next;
	//	cout<<"hate1 isn't tail or NULL, weird"<<endl;
	}
reverse(hate2, hate1);
}

/**
 * Modifies the List using the waterfall algorithm.
 * Every other node (starting from the second one) is removed from the
 * List, but appended at the back, becoming the new tail_. This continues
 * until the next thing to be removed is either the tail_ (**not necessarily
 * the original tail_!**) or NULL.  You may **NOT** allocate new ListNodes.
 * Note that since the tail_ should be continuously updated, some nodes will
 * be moved more than once.
 */
template <class T>
void List<T>::waterfall() {
  /// @todo Graded in MP3.1
  if (length_==0){
		return;
	}
	ListNode* curr = head_->next;
	ListNode* temp = NULL;
	while(curr!=NULL&&curr->next!=NULL){
		curr->next->prev=curr->prev;
		curr->prev->next=curr->next;
		curr->prev=tail_;
		temp = curr->next->next;
		curr->next=NULL;
		tail_->next=curr;
		tail_ = curr;
		curr = temp;
}
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

  ListNode * secondHead = split(head_, splitPoint);

  int oldLength = length_;
  if (secondHead == head_)
  {
      // current list is going to be empty
      head_ = NULL;
      tail_ = NULL;
      length_ = 0;
  }
  else
  {
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
  if (ret.tail_ != NULL)
  {
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
 * This function **SHOULD NOT** create **ANY** new List or ListNode objects!
 *
 * @param start The node to start from.
 * @param splitPoint The number of steps to walk before splitting.
 * @return The starting node of the sequence that was split off.
 */
template <class T>
typename List<T>::ListNode * List<T>::split(ListNode * start, int splitPoint) {
  /// @todo Graded in MP3.2
  ListNode * temp = start;
   int count = splitPoint;
   while (count--){
       temp = temp->next;
   }
   if (temp->prev != NULL)
       temp->prev->next = NULL;
return temp;
}

/**
 * Merges the given sorted list into the current sorted list.
 *
 * @param otherList List to be merged into the current list.
 */
template <class T>
void List<T>::mergeWith(List<T> & otherList) {
    // set up the current list
    head_ = merge(head_, otherList.head_);
    tail_ = head_;

    // make sure there is a node in the new list
    if(tail_ != NULL)
    {
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
typename List<T>::ListNode * List<T>::merge(ListNode * first, ListNode* second) {
  /// @todo Graded in MP3.2
  ListNode* temp = NULL;
	ListNode* temp2 = NULL;
	ListNode* newstart = NULL;
	//ListNode* newend = NULL;
	if((second->data)<(first->data)){
		newstart=second;
		temp = second;
		temp2 = first;
	}
	else{ //if firstdata<=seconddata not sure what to do for equal though...
		temp = first;
		newstart = first;
		temp2 = second;
	}
/*	while(first->next!=NULL){
		first=first->next;
	}
	while(second->next!=NULL){
		second=second->next;
	}
	if(first->data<second->data)
		newend = second;
	else
		newend = first; */
	while((temp!=NULL)&&(temp2!=NULL)){//keep going to the end(cant stop this infinite loop sadface)
		while((temp->next!=NULL)&&(temp->next->data)<(temp2->data)){
			temp=temp->next;
		}
		if(temp->next==NULL){
			temp->next=temp2;
			temp2->prev=temp;
			break;
		}
		ListNode* temp3 = temp->next;
		temp->next->prev=NULL;
		temp->next = temp2;
		temp2->prev = temp;
		temp=temp2;
		temp2=temp3;
//		if ((temp == newend) || (temp2->next == newend))
//			break;
//		cout<<"infinite loop bitches"<<endl;
	}
return newstart;
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
 * @param chainlength_ Size of the chain to be sorted.
 * @return A pointer to the beginning of the now sorted chain.
 */
template <class T>
typename List<T>::ListNode* List<T>::mergesort(ListNode * start, int chainlength_) {
  /// @todo Graded in MP3.2
  if(chainlength_ <=1){
		return start;
	}
	ListNode* list2 = split(start,chainlength_/2);
	start = mergesort(start, chainlength_/2);
	list2 = mergesort(list2, chainlength_-chainlength_/2);
//	cout<<chainLength<<endl;

return merge(start,list2);
}
