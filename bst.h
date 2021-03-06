#ifndef BST_H
#define BST_H

#define F 0
#define T 1
#define MAXHEIGHT 100
#define MAX(x,y) ((x) > (y) ? (x):(y))

typedef struct Node {
	struct Node * p_Node_left;
	struct Node * p_Node_right;
	void * p_key;
	void * p_data;
} Node;

/*
 Recursive function to find a node holding given data
 @parameter p_Node_root: root at which to start search
 @parameter p_key: pointer to data looked for
 @parameter comp: function pointer that performs comparison
 @return Node pointer that has the associated key, or null if not found
*/
Node *
find(Node *p_Node_root, void * p_key, int (*comp)(void *, void *));

/*
 Returns a Node pointer that has the minimum key in the tree
*/
Node *
find_min(Node *p_Node_root, int (*comp)(void *, void *));

/*
 Returns a Node pointer that has the maximum key in the tree
*/
Node *
find_max(Node *p_Node_root, int (*comp)(void *, void *));

/*
 If p_NodeRoot is null, then create tree
 @param pp_Node_root: double pointer to the root node of tree (or null pointer if new tree)
 @param p_key: pointer to key to be inserted
 @param p_data: pointer to data to be inserted
 @param p_f_comp: pointer to comparator function (returns +ve if 1st arg greater than 2nd)
 @return pointer to root node of modified tree
*/
void 
insert(Node **pp_Node_root, void * p_key, void * p_data, int (*p_f_comp)(void *, void *));

/*
 Deletes the node with given key in a tree
 @parameter pp_Node_root: double pointer to root of tree
 @parameter p_key: pointer to key to be deleted from tree
 @parameter p_f_comp: function pointer comparing tree key elements
*/
void
delete(Node **pp_Node_root, void * p_key, int (*p_f_comp)(void *, void *));

int
get_height(Node * p_Node_root);

/* 
 Recursive printing of tree
 @parameter p_Node_root: root node of (sub)tree to be printed
 @parameter i_level: node's level in the tree being printed
 @parameter formatted_print: function pointer printing one Node
*/
void
print_tree(Node * p_Node_root, int i_level, void formatted_print(Node *p_Node));

#endif /* BST_H */