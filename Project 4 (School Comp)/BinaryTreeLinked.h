#pragma once

template<class T>
class BinaryTreeLinked
{
protected:
	
	struct node;
	typedef node* nodePtr;
	struct node
	{
		T data;
		nodePtr left, right;
	};
	nodePtr root;// the anchor of the tree
public:
	int counts[];
	BinaryTreeLinked();
	BinaryTreeLinked(const BinaryTreeLinked &btl);
	~BinaryTreeLinked(); // ?? no arguments. can't use it recursively
	BinaryTreeLinked<T>& operator = (const BinaryTreeLinked &btl);
	T sumOfNodes() const;
	void deleteTree();
	void insert(T elt);
	void displayTreeInOrder() const;
	void displayTreeInReverseOrder() const;
	void walkTree();
	//NEW FUNCTIONS TO IMPLEMENT
	void printInOrder() const;

	void countNodesPerLevel(int counts[], int &levels, int arraySize) const;

	void countParentTypes(int counts[]) const;

private:
	void traverse(nodePtr root);
	void deleteTree(nodePtr &root);
	void recursiveInsert(T elt, nodePtr &curr);
	void recursiveInOrderPrint(nodePtr curr) const;
	void recursiveReverseOrderPrint(nodePtr curr) const;
	void recursiveDuplicateTree(nodePtr curr);
};


template<class T>
void BinaryTreeLinked<T>::displayTreeInOrder() const
{
	recursiveInOrderPrint(root);
}

template<class T>
void BinaryTreeLinked<T>::recursiveInOrderPrint(nodePtr curr) const
{
	if (curr != nullptr)
	{
		recursiveInOrderPrint(curr->left);
		cout << curr->data << endl;
		recursiveInOrderPrint(curr->right);
	}
}
template<class T>
void BinaryTreeLinked<T>::displayTreeInReverseOrder() const
{
	recursiveReverseOrderPrint(root);
}

template<class T>
void BinaryTreeLinked<T>::recursiveReverseOrderPrint(nodePtr curr) const
{
	if (curr != nullptr)
	{
		recursiveReverseOrderPrint(curr->right);
		cout << curr->data << endl;
		recursiveReverseOrderPrint(curr->left);
	}
}

template<class T>
void BinaryTreeLinked<T>::insert(T elt)
{
	recursiveInsert(elt, root);
}

template<class T>
void BinaryTreeLinked<T>::recursiveInsert(T elt, nodePtr &curr)
{
	if (curr == nullptr)
	{
		curr = new node;
		curr->data = elt;
		curr->left = curr->right = nullptr;
	}
	else if (elt < curr->data)
		recursiveInsert(elt, curr->left);
	else
		recursiveInsert(elt, curr->right);
}

template<class T>
T BinaryTreeLinked<T>::sumOfNodes() const
{
	T sum = 0;
	sum += root->data;
	return sum;
}

template<class T>
BinaryTreeLinked<T>::BinaryTreeLinked()
{
	root = nullptr;
}

template<class T>
BinaryTreeLinked<T>::BinaryTreeLinked(const BinaryTreeLinked &btl)
{
	root = nullptr;
	recursiveDuplicateTree(btl.root);
}

template<class T>
BinaryTreeLinked<T>& BinaryTreeLinked<T>::operator = (const BinaryTreeLinked &btl)
{
	if (this == &btl)
		return *this;
	deleteTree(); // sets *this->root to nullptr for us.
	recursiveDuplicateTree(btl.root);
	return *this;
}

template<class T>
void BinaryTreeLinked<T>::recursiveDuplicateTree(nodePtr curr)
{
	if (curr != nullptr)
	{
		insert(curr->data);
		recursiveDuplicateTree(curr->left);
		recursiveDuplicateTree(curr->right);
	}
}

template<class T>
BinaryTreeLinked<T>::~BinaryTreeLinked()
{
	deleteTree(root);
}

template<class T>
void BinaryTreeLinked<T>::deleteTree()
{
	deleteTree(root);
	root = nullptr;
}

template<class T>
void BinaryTreeLinked<T>::deleteTree(nodePtr &root)
{
	if (root != nullptr)
	{
		deleteTree(root->left);
		deleteTree(root->right);
		delete root;
	}
}

//NEW FUNCTIONS TO IMPLEMENT
template<class T>
void BinaryTreeLinked<T>::printInOrder() const {
	recursiveInOrderPrint(root);

	cout << "Root: " << root;

}

template<class T>
void BinaryTreeLinked<T>::countNodesPerLevel(int counts[], int &levels, int arraySize) const {

}

template<class T>
void BinaryTreeLinked<T>::countParentTypes(int counts[]) const {
	nodePtr temp;
	temp = root;
	

	traverse(temp)

	if (temp.left != null) {
		countParentTypes
	}
	//while (temp != nullptr)
	//{
	//	if (temp->left != nullptr && temp->right != nullptr) {
	//		counts[2]++;
	//		return;
	//	}

	//	else if (temp->left != nullptr && temp->right == nullptr) {
	//		counts[1]++;
	//		return;
	//	}

	//	else if (temp->left == nullptr && temp->right != nullptr) {
	//		counts[1]++;
	//		return;
	//	}

	//	else {
	//		counts[0]++;
	//		return;
	//	}
	//}

	cout << "counts[0]: " << counts[0] << endl;
	cout << "counts[1]: " << counts[1] << endl;
	cout << "counts[2]: " << counts[2] << endl;
}

template<class T>
void BinaryTreeLinked<T>::traverse(nodePtr root) {
	if (root->left != nullptr && root->right != nullptr) {
		cout << "In 3" << endl;
		this->counts[2]++;
		
	}

	else if (root->left != nullptr && root->right == nullptr) {
		cout << "In 2" << endl;
		this->counts[1]++;
		
	}

	else if (root->left == nullptr && root->right != nullptr) {
		cout << "In 1" << endl;
		this->counts[1]++;
		
	}

	else {
		cout << "In 0" << endl;
		this->counts[0]++;
		
	}

	if (root->left != nullptr)
	{
		traverse(root->left);
	}
	cout << root->data << endl;
	if (root->right != nullptr)
	{
		traverse(root->right);
	}

	cout << "counts[0]: " << counts[0] << endl;
	cout << "counts[1]: " << counts[1] << endl;
	cout << "counts[2]: " << counts[2] << endl;
}

//template<class T>
//void BinaryTreeLinked<T>::countPTypes(nodePtr root) {
//	if (root->left != nullptr)
//	{
//		traverse(root->left);
//	}
//	cout << root->data;
//	if (root->right != nullptr)
//	{
//		traverse(root->right);
//	}
//}

template<class T>
void BinaryTreeLinked<T>::walkTree() {
	traverse(this->root);
}