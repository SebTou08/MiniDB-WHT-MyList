#ifndef __NODE_H__
#define __NODE_H__

template <typename TypeGen>
class Node
{
public:
    TypeGen data;
    Node<TypeGen> *ChildLeft;
    Node<TypeGen> *ChildRight;


    Node(TypeGen data)
    {

		ChildLeft = ChildRight = nullptr;
        this->data = data;
    }
};

#endif // !__NODE_H__
