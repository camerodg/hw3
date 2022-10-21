#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
	//i.e. 4,7,2,1. pivot 6
	if(head == NULL)
	{
		//set every pointer equal to NULL
		smaller = NULL;
		larger = NULL;
		head = NULL;
		return;
	}
	
	//if the val is less than the pivot 
  if(head->val < pivot)
	{
		smaller = head;
		Node* temp = head->next;
		llpivot(temp,smaller->next,larger,pivot);
	}

	//if val is greater than the pivot
	else if(head->val > pivot)
	{
		larger = head;
		Node* temp2 = head->next;
		llpivot(temp2,smaller,larger->next,pivot);
	}
}
