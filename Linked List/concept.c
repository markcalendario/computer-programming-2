#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    struct node *link;
};

int main() {
    
    struct node 
            *head = NULL, 
            *current = NULL, 
            *tail = NULL;

    // ===========================
    // Head Node
    // ===========================
    // First node. It will act as a head and tail.
    
        // Allocate the memory.
        current = malloc(sizeof(struct node)); // new address
        
        current->num = 5; // assign a value
        
        // Set the current link as NULL
        // because it is the last (tail) node at this point.
        // We will assign a link to this node later (Refer to ALPHA)
        current->link = NULL;
        
        // Set the current node as a head and a tail.
        head = current;
        tail = current;
    
    
    // ===========================
    // Tail Node 1
    // ===========================
    // It will serve as a tail node.

        // Allocate the memory.
        current = malloc(sizeof(struct node));
        
        current->num = 10;
        
        // Set the current link as NULL 
        // Because it is the last (tail) node at this point.
        // We will assign a link to this node later (Refer to BETA)
        current->link = NULL;
        
        // ALPHA
        // Remember, the tail node is also the previous node (head) at this point.
        // Now, set that (the head which is also a tail) node's link to a current node so that the 
        // previous node will link the current's address.
        tail->link = current;
        
        // Then, set the current node as a new tail.
        tail = current;
        
        
    // ===========================
    // Tail Node 2
    // ===========================
    // It will serve as a new tail node.

        // Allocate the memory.
        current = malloc(sizeof(struct node));
        
        current->num = 15;
        
        // Set the link as NULL 
        // because it is the last (tail) node at this point. 
        // We will assign a link to this node later (Refer to CHARLIE)
        current->link = NULL;

        // BETA
        // Remember, the tail node is also the previous node (Tail Node 1) at this point.
        // Set that (Tail Node 1) node's link to a current node so that the 
        // previous node will link the current's address.
        tail->link = current;
        
        // Now, set the current node as a new tail.
        tail = current;
        
        
    // ===========================
    // Tail Node 3
    // ===========================
    // It will serve as a last tail node.
    
    // Allocate the memory.
        current = malloc(sizeof(struct node));
        
        current->num = 20;
        
        // Set the link as NULL 
        // Because it is the last and final (tail) node. 
        current->link = NULL;
        
        // CHARLIE
        // Remember, the tail node is also the previous node (Tail Node 2) at this point.
        // Set the tail (Tail Node 2) node's link to a current node so that the 
        // previous node will link the current's address.
        tail->link = current;
        
        // Now, set the current node as a new tail.
        tail = current;

  
    // END END END END END END END END 
    // END END END END END END END END 
  
    
    current = head; // Set the current node back to head

    // The condition inside while loop checks if the node's link is NULL
    // If it is NULL then it means that the current node is at the tail and no more follows.
    while (current != NULL) { 
        printf("%d\n", current->num);
        current = current->link;
    }
    
    return 0;
}
