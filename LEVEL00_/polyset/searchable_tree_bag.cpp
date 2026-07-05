#include "searchable_tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag(): tree_bag(){}

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag &other): tree_bag(other){}

searchable_tree_bag::~searchable_tree_bag(){}

searchable_tree_bag &searchable_tree_bag::operator=(const searchable_tree_bag &other)
{
	node *new_tree = copy_tree(other.tree);
	set_tree(new_tree);
	return *this;
}

tree_bag::node *searchable_tree_bag::copy_tree(node *root) const
{
	if (root == nullptr)
		return nullptr;

	node *new_node = new node;
	new_node->value = root->value;
	new_node->l = copy_tree(root->l);
	new_node->r = copy_tree(root->r);
	return new_node;
}

bool searchable_tree_bag::has(int n) const
{
	node *tmp = tree;

	while (tmp)
	{
		if (n == tmp->value)
			return true;
		else if (n < tmp->value)
			tmp = tmp->l;
		else
			tmp = tmp->r;
	}
	return false;
}

