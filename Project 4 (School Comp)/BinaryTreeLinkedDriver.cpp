#include<iostream>
#include<string>
#include<ctime>
#include"BinaryTreeLinked.h"
using namespace std;

template <class T>
void testCopyConstructor(BinaryTreeLinked<T> tree);

int main()
{
	BinaryTreeLinked<int> intBT, intBT2;
	BinaryTreeLinked<double> dblBT;
	srand(unsigned(time(NULL)));
	for (int i = 0; i < 5; i++)
		intBT.insert(rand() % 100);
	intBT.displayTreeInOrder();
	cout << endl;
	intBT = intBT;
	intBT.displayTreeInOrder();
	cout << "Walk it out";
	intBT.walkTree();
	//testCopyConstructor(intBT);
	//intBT.displayTreeInOrder();
	cout << endl;
	exit(0);
	}

template <class T>
void testCopyConstructor(BinaryTreeLinked<T> tree)
{
	tree.deleteTree();
	cout << "in function:\n";
	tree.displayTreeInOrder();
	cout << "end of function\n";
}
