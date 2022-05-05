#include "binary_trees.h"

/**
 * find_insert_node - finds the node to insert the child in
 * @root: the root of the tree
 * @height: the current node height
 * @maxheight: the max tree height
 * Return: the node to enter the child in
 */

binary_tree_t *find_insert_node(binary_tree_t *root, int height, int maxheight)
{
	binary_tree_t *x;
	binary_tree_t *y;

	if ((root->left) && !(root->right))
		return (root);
	if (!(root->left || root->right))
	{
		if (height == maxheight)
			return (NULL);
		else
			return (root);
	}

	x = find_insert_node(root->left, height + 1, maxheight);
	y = find_insert_node(root->right, height + 1, maxheight);
	if (x)
		return (x);
	else
		return (y);
}


/**
 * change_attributes - swaps all three attributes on two nodes.
 * @node1: the first node
 * @node2: the second node
 */

void change_attributes(binary_tree_t *node1, binary_tree_t *node2)
{
	binary_tree_t *temp;

	temp = node2->parent;
	node2->parent = node1->parent;
	node1->parent = temp;

	temp = node2->left;
	node2->left = node1->left;
	node1->left = temp;

	temp = node2->right;
	node2->right = node1->right;
	node1->right = temp;
}


/**
 * change - change an item with its parent
 * @item: the item
 * @parent: the parent
 */
void change(binary_tree_t *item, binary_tree_t *parent)
{
	change_attributes(item, parent);
	parent->parent = item;
	if (item->left == item)
	{
		item->left = parent;
		if (item->right)
			item->right->parent = item;
	}
	if (item->right == item)
	{
		item->right = parent;
		if (item->left)
			item->left->parent = item;
	}

	if (item->parent)
	{
		if (item->parent->left == parent)
			item->parent->left = item;
		if (item->parent->right == parent)
			item->parent->right = item;
	}

	if (parent->left)
		if (parent->left->parent == item)
			parent->left->parent = parent;

	if (parent->right)
		if (parent->right->parent == item)
			parent->right->parent = parent;
}



/**
 * max_heapify - turn heap into heap
 * @x: the current bubble-up node
 * Return: the root of the heapified tree
 */

heap_t *max_heapify(binary_tree_t *x)
{
	binary_tree_t *max;

	max = x;
	while (max->parent && max->n > max->parent->n)
		change(max, max->parent);
	while (max->parent)
		max = max->parent;
	return ((heap_t *)max);
}

/**
 * heapt_t *heap_insert -inserts value into Max Binary Heap
 * @root: double pointer to the root node of the Heap
 * @value: the value to put in the inserted node
 * Return: a pointer to the new node, or NULL on failure
 */

heap_t *heap_insert(heap_t **root, int value)
{
	binary_tree_t *n;
	binary_tree_t *new;
	binary_tree_t *temp;
	int i = 0;

	n = binary_tree_node(NULL, value);
	if (!(*root))
	{
		*root = n;
		return (n);
	}
	if (!root)
		return (NULL);
	if (n == NULL)
		return (NULL);

	temp = *root;
	while (temp->left)
	{
		temp = temp->left;
		i += 1;
	}
	new = find_insert_node(*root, 0, i);
	if (!new)
	{
		new = *root;
		while (new->left)
			new = new->left;
	}
	if (new->left)
		new->right = n;
	else
		new->left = n;
	n->parent = new;
	*root = max_heapify(n);
	return (n);
}
