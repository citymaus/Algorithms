#include <cstdio>
#include <cstdlib>

struct tree {
	int item;					/* data item */
	struct tree *parent;		/* pointer to parent */
	struct tree *left;			/* pointer to left child */
	struct tree *right;			/* pointer to right child */
};

tree *search_tree(tree *t, int x)
{
	if (t == NULL) return (NULL);
	
	if (t->item == x) return (t);
	
	if (x < t->item)
		return (search_tree(t->left, x));
	else
		return (search_tree(t->right, x));
}

tree *find_minimum(tree *t)
{
	tree *min;
	
	if (t == NULL) return (NULL);
	
	min = t;
	while (min->left != NULL)
		min = min->left;
	return(min);
}

void traverse_tree(tree *t)
{
	if (t != NULL)
	{
		traverse_tree(t->left);
		process_item(t->item);
		traverse_tree(t->right);
	}
}

void insert_node(tree **t, int x, tree *parent)
{
	tree *p;
	
	if (*t == NULL)
	{
		p = (tree*)malloc(sizeof(tree));
		p->item = x;
		p->left = p->right = NULL;
		p->parent = parent;
		*t = p;
		return;
	}
	
	if (x < (*t)->item)
		insert_node(&((*t)->left), x, *t);
	else
		insert_node(&((*t)->right), x, *t);
}

void delete_tree(tree **t, int x, tree *parent)
{
	if ((*t)->left == NULL && (*t)->right == NULL)
	{
		/* Node is a leaf, no children */
		free(*t);
		//(*t) = NULL;
	}
	else
	{
		if ((*t)->left == NULL)
		{
			/* Node has one child */
			tree *child = (*t)->right;
			insert_node(t, child->item, parent);
			free(*t);
		}
		else if ((*t)->right == NULL)
		{
			/* Node has one child */
			tree *child = (*t)->left;
			insert_node(t, child->item, parent);
			free(*t);
		}
		else
		{
			/* Node has two children */
			/* 
				Relabel this node with the key of its immediate successor in sorted order.
				This successor must be the smallest value in the right subtree, 
				specifically the leftmost descendant in the right subtree.
			*/
		}
	}
}