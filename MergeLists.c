/*
  Merge two sorted lists A and B as one linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* MergeLists(Node *headA, Node* headB)
{
  // This is a "method-only" submission. 
  // You only need to complete this method 
    
    if(headA==NULL)
    {
        return headB;
    }
    if(headB==NULL)
    {
        return headA;
    }
    Node* t1 = headA;
    Node* t2= headB;
    
    Node* headMerged = t1;
    
    
    if(t2->data < t1->data)
    {
        headMerged = t2;
        t2=t2->next;
    }
    else
    {
        t1=t1->next;
    }
    
    Node* t3=headMerged;
    t3->next = NULL;
    while(t1!=NULL && t2!=NULL)
    {
        if(t1->data<=t2->data)
        {
            t3->next = t1;
            t1=t1->next;
        }
        else
        {
           t3->next = t2;
            t2=t2->next; 
        }
        t3=t3->next;
    }
    
    while(t1!=NULL)
    {
        t3->next = t1;
        t1=t1->next;
        t3=t3->next;
    }
    while(t2!=NULL)
    {
        t3->next = t2;
        t2=t2->next;
        t3=t3->next;
    }
    return headMerged;
    
}
