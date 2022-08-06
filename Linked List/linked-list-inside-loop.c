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
        
        // Get user input
        printf("Enter a value for node %d: ", x + 1);
        scanf("%d", &current->value);
        
        // Nullify the next node
        // The current is a tail at the moment
        current->next = NULL;
        
        if (x == 0) { 
            // If first rotation of loop then assign the current node as head.
            head = current; 
        } else {
            // If not, then link the previous node to a current node.
            tail->next = current;
        }
        
        // Set the current node as a tail.
        tail = current;
        
    }

    
  printf("\n == RESULT ==\n");
  current = head;

  while(current != NULL) {
    printf("%d\n", current->value);
    current = current->next;
  }
  
  return 0;
    
}
