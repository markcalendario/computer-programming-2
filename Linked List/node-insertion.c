// Insert node to a defined position

#include <stdio.h>
#include <stdlib.h>

int MAX_NODE = 3;

struct node
{
    int value;
    struct node *next;
};

void printNodes(struct node *current, struct node *head) {
  current = head;
  int count = 0;
  while(current != NULL) {
    count++;
    printf("==============================================\n");
    printf("Node Address:\t%x\n", current);
    printf("Node Name:\t\tNode %d\n", count);
    printf("Node Value:\t\t%d\n", current->value);
    printf("Points To:\t\t%x\n", current->next);
    current = current->next;
  }
}

int main() {
  struct node *head, *current, *tail, *newnode, *temp;
  hell:;
  printf("How many nodes do you want?: ");
  scanf("%d", &MAX_NODE);
  if (MAX_NODE <= 0) {
    printf("Invalid node count!\n");
    goto hell;
  }
  
    for (int x = 0; x < MAX_NODE; x++) {
        
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
    
  printf("\n=================== RESULT ===================\n");
  printNodes(current, head);

  // Inserting node from a user defined position
  int position;
  
  alpha:;
  printf("\nEnter a position you want to add a new node: ");
  scanf("%d", &position);

  if (position > MAX_NODE || position < 1) {
    printf("Out of bounds!\n");
    goto alpha;
  }
  
  newnode = malloc(sizeof(struct node));
  printf("Enter a value for a new node: ");
  scanf("%d", &newnode->value);
  newnode->next = NULL;
  
  current = head;
  struct node *prev = current; // Initialize the previous node to current.

  for (int x = 0; x < MAX_NODE; x++) {
    if (position == 1 && x == 0) { 
      // Visualization:
      // Before: Head->Current
      // Then: NewNode->Current(Head)
      // After: NewNode(Head)->Current
      
      // If user selected the head, then
      // Then link the newnode to a current (head)
      newnode->next = current;
      // Set the newnode as a head 
      head = newnode;
      break;
    } 
    else if(x == position - 1 && x != 0) {
      // Visualization:
      // Before: Previous->Current
      // After: Previous->NewNode->Current
      
      // If user selected a node that is not a head, then
      // Link the newnode to a current node
      newnode->next = current;
      // Link the previous node to a newnode
      prev->next = newnode;
      break;
    }

    prev = current;
    current = current->next;
  }

  printf("\n================= NEW RESULT =================\n");
  printNodes(current, head);
  
  return 0;
    
}
