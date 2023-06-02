#include <iostream>

using namespace std;


struct avlNode {
	int val;
	int h; //height
	avlNode* left;
	avlNode* right;
	avlNode() : val(0), h(1), left(nullptr), right(nullptr) {}
	avlNode(int x) : val(x), h(1), left(nullptr), right(nullptr) {}
};


int height(avlNode* node) {
	return node ? node->h : 0;
}


int balanceFactor(avlNode* node) { // if bf == +2 : h(l)>h(r); 
								   // if bf == -2 : h(r)>h(l); 
	return height(node->right) - height(node->left);
}

void fixHeight(avlNode* node) {
	int hl = height(node->left);
	int hr = height(node->right);
	node->h = hl > hr ? hl + 1 : hr + 1;
}

avlNode* rotateLeft(avlNode* node) {
	avlNode* tmp = node->right;
	node->right = tmp->left;
	tmp->left = node;
	fixHeight(node);
	fixHeight(tmp);
	return tmp;
}

avlNode* rotateRight(avlNode* node) {
	avlNode* tmp = node->left;
	node->left = tmp->right;
	tmp->right = node;
	fixHeight(node);
	fixHeight(tmp);
	return tmp;
}

avlNode* balanceTree(avlNode* node) {
	fixHeight(node);
	if (balanceFactor(node) == 2) {
		if (balanceFactor(node->right) < 0)
			node->right = rotateRight(node->right);
		return rotateLeft(node);
	}
	if (balanceFactor(node) == -2) {
		if(balanceFactor(node->left) > 0)
			node->left = rotateLeft(node->left);
		return rotateRight(node);
	}
	return node;
}

avlNode* insertNode(avlNode* node, int val) {
	if (!node)
		return new avlNode(val);
	if (val < node->val) {
		node->left = insertNode(node->left, val);
	}
	else if (val > node->val) {
		node->right = insertNode(node->right, val);
	}
	return balanceTree(node);
}

//void deleteNode(avlNode** node, int val) {
//	if (!node)
//		return;
//	if (val < (*node)->val) {
//		(*node)->left = insertNode((*node)->left, val);
//	}
//	else if (val > (*node)->val) {
//		(*node)->right = insertNode((*node)->right, val);
//	}
//	balanceTree(*node);
//}

void printTree(avlNode* node, int level) {
	for (int i = 0; i < level; ++i)
		cout << "    ";
	if (node == nullptr) {
		cout << "null"<< endl;
		return;
	}
	cout << node->val << endl;
	printTree(node->left, level + 1);
	printTree(node->right, level + 1);

}


int main() {
	avlNode* root = nullptr;
	//avlNode* root = tree;
	for (int i = 1; i <= 10; ++i) {
		root = insertNode(root, i);
		printTree(root, 0);
		cout << "___________________________________"<<endl;
	}
	//root = insertNode(root, 1);
	//printTree(root, 0);

}
