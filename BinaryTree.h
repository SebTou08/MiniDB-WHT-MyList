#ifndef __TREE_H__
#define __TREE_H__

#include <iostream>
#include <string>
#include <functional>
#include <fstream>
#include <sstream>
#include <ctime>
#include <stdlib.h>
#include <algorithm>

using namespace std;

template <typename TypeGen>
class BinaryTree;

template <typename TypeGen>
class Nodein
{
private:
	TypeGen data;
	Nodein<TypeGen> *ChildLeft;
	Nodein<TypeGen> *ChildRight;
	friend class BinaryTree<TypeGen>;

public:
	Nodein() {}
	Nodein(TypeGen data)
	{
		ChildLeft = ChildRight = nullptr;
		this->data = data;
	}
};

template <typename TypeGen>
class BinaryTree
{
private:
	Nodein<TypeGen> *root;

	void _add(Nodein<TypeGen> *&node, TypeGen data)
	{
		int a = rand() % 2;
		if (node == nullptr)
			node = new Nodein<TypeGen>(data);

		else if (a == 0)
		{
			_add(node->ChildLeft, data);
		}
		else if (a == 1)
		{
			_add(node->ChildRight, data);
		}
	}

	void add(Nodein<TypeGen> *&node, TypeGen data, function<bool(TypeGen)> AddCritery)
	{
		if (node == nullptr)
		{
			node = new Nodein<TypeGen>(data);
		}
		else
		{
			if (AddCritery(data))
				add(node->ChildRight, data, AddCritery);
			else
				add(node->ChildLeft, data, AddCritery);
		}
	}

	//Ways
	//to
	//print
	//------------------------------------------------------------------------------------
	void inorder(Nodein<TypeGen> *node, function<void(TypeGen)> PrintCritery)
	{
		if (node == nullptr)
		{
			return;
		}
		else
		{
			inorder(node->ChildLeft, PrintCritery);
			PrintCritery(node->data);
			inorder(node->ChildRight, PrintCritery);
		}
	}

	void printthrown(Nodein<TypeGen> *bt, int spaces, function<void(TypeGen)> PrintCritery)
	{
		if (bt != NULL)
		{
			printthrown(bt->ChildRight, spaces + 5, PrintCritery);
			for (int i = 0; i < spaces; i++)
				cout << ' ';
			PrintCritery(bt->data); //cout << "   " << bt->g << endl;
			printthrown(bt->ChildLeft, spaces + 5, PrintCritery);
		}
	}

	void printBT(const std::string &prefix, const Nodein<TypeGen> *node, bool isLeft, function<void(TypeGen)> PrintCritery)
	{
		if (node != nullptr)
		{
			std::cout << prefix;

			std::cout << (isLeft ? "├──" : "└──");

			// print the value of the node
			PrintCritery(node->data); //std::cout << node->data << std::endl;

			// enter the next tree level - left and right branch
			printBT(prefix + (isLeft ? "│   " : "    "), node->ChildLeft, true, PrintCritery);
			printBT(prefix + (isLeft ? "│   " : "    "), node->ChildRight, false, PrintCritery);
		}
	}

	void printBT(const Nodein<TypeGen> *node, function<void(TypeGen)> PrintCritery)
	{
		printBT("", node, false, PrintCritery);
	}

	void printleft(Nodein<TypeGen> *node, function<void(TypeGen)> PrintCritery)
	{
		if (node == nullptr)
		{
			return;
		}
		else
		{
			printleft(node->ChildLeft, PrintCritery);
			PrintCritery(node->data);
		}
	}

public:
	BinaryTree() { root = nullptr; }
	void Add(TypeGen data, function<bool(TypeGen)> AddCritery) { add(root, data, AddCritery); }
	void InOrder(function<void(TypeGen)> PrintCritery) { inorder(root, PrintCritery); }
	void PrintLeft(function<void(TypeGen)> PrintCritery) { printleft(root, PrintCritery); }
	void PrintThrown(function<void(TypeGen)> PrintCritery) { printthrown(root, 1, PrintCritery); }
	void PrintAsTree(function<void(TypeGen)> PrintCritery) { printBT(root, PrintCritery); }
};

#endif