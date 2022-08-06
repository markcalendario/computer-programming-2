#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};
int main() {
    struct node *head, *current, *tail, *newnode;

    for (int x = 0; x < 5; x++) {
      current = malloc(sizeof(struct node));
    
      printf("Enter a value for node %d: ", x + 1);
      scanf("%d", &current->value);
      
      current->next = NULL;
      
      if (x == 0) {
          head = current; 
      } else {
          tail->next = current;
      }
      tail = current;
        
    }

  // Set a new head node
  current = malloc(sizeof(struct node));
  printf("Enter a value for a new beginning node: ");
  scanf("%d", &current->value);
  current->next = head; // Link the current node to head
  head = current; // Set the current node as a new head
  // The current node now is the new head that points to a previous head.

  // Set a new tail node
  current = malloc(sizeof(struct node));
  printf("Enter a value for a new ending node: ");
  scanf("%d", &current->value);
  tail->next = current; // Link the tail node to a current
  tail = current; // Set the current node as a new tail
  // The current node now is the new tail pointing by the previous tail.
    
  printf("\n == RESULT ==\n");
  current = head;
  while(current != NULL) { 
    printf("%d\n", current->value);
    current = current->next;
  }
  
  return 0;
    
}
