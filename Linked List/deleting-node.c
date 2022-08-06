#include <stdio.h>
#include <stdlib.h>

struct node {
  int value;
  struct node *link;
};

int main(void) {
  struct node 
    *head     =   NULL,
    *current  =   NULL,
    *tail     =   NULL;

  current = (struct node *)malloc(sizeof(struct node));
  current->link = NULL;
  current->value = 10;
  head = current;
  tail = current;

  current = (struct node *)malloc(sizeof(struct node));
  current->link = NULL;
  current->value = 20;
  tail->link = current;
  tail = current;
  
  current = (struct node *)malloc(sizeof(struct node));
  current->link = NULL;
  current->value = 30;
  tail->link = current;
  tail = current;


  current = head;
  while (current != NULL) {
    printf("%d ", current->value);
    current = current->link;
  }

  // Let's delete the head node.

  // current = head->link;
  // free(head);
  // head = current;

  // printf("\n");
  //  while (current != NULL) {
  //   printf("%d ", current->value);
  //   current = current->link;
  // }

  // Let's delete the middle node (node that has a 20 value)

  int pos = 2; // Suppose that we will delete the node that's in position 2

  current = head; 
  
  struct node *prev = current;
  
  for(int x = 0; x < 3; x++) {
    if (x == pos - 1 && pos != 1) {
      // If user selected any node that is not a head
      // Then the previous node link will be connected to a current node's link
      // Therefore, the current node will be left alone.
      prev->link = current->link;
      current->link = NULL;
      break;
    } else if (x == pos - 1 && pos == 1) {
      // If user selected a head
      // Then current node's link will be assigned to a head that will serve as a new head.
      head = current->link;
      current->link = NULL;
      break;
    }

    prev = current; // Record previous
    current = current->link; // Adjust to next node
  }

  free(current); // Free the deleted node.

  printf("\n");
  current = (struct node *)malloc(sizeof(struct node));  // Reallocate current as new and fresh node.
  current = head;
  while (current != NULL) {
    printf("%d ", current->value);
    current = current->link;
  }
  
  return 0;
}
