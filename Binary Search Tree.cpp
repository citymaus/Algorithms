/*
  Binary Search Tree
    http://bartoszmilewski.com/2013/11/25/functional-data-structures-in-c-trees/
    
    
*/

template<class T>
class Tree {
public:
    Tree(); // empty tree
    Tree(Tree const & lft, T val, Tree const & rgt)
};

struct Node
{
   Node(std::shared_ptr<const Node> const & lft
      , T val
      , std::shared_ptr<const Node> const & rgt)
   : _lft(lft), _val(val), _rgt(rgt)
   {}

   std::shared_ptr<const Node> _lft;
   T _val;
   std::shared_ptr<const Node> _rgt;
};
   
   
template<class T>
class Tree
{
    struct Node;
    explicit Tree(std::shared_ptr<const Node> const & node) 
    : _root(node) {} 
public:
    Tree() {}
    Tree(Tree const & lft, T val, Tree const & rgt)
      : _root(std::make_shared<const Node>(lft._root, val, rgt._root))
    {
        assert(lft.isEmpty() || lft.root() < val);
        assert(rgt.isEmpty() || val < rgt.root());       
    }
    bool isEmpty() const { return !_root; }
    T root() const {
        assert(!isEmpty());
        return _root->_val;
    }
    Tree left() const {
        assert(!isEmpty());
        return Tree(_root->_lft);
    }
    Tree right() const {
        assert(!isEmpty());
        return Tree(_root->_rgt);
    }
private:
    std::shared_ptr<const Node> _root;
};

Tree insert(T x) const {
    if (isEmpty())
        return Tree(Tree(), x, Tree());
    T y = root();
    if (x < y)
        return Tree(left().insert(x), y, right());
    else if (y < x)
        return Tree(left(), y, right().insert(x));
    else
        return *this; // no duplicates
}

bool member(T x) const {
    if (isEmpty())
        return false;
    T y = root();
    if (x < y)
        return left().member(x);
    else if (y < x)
        return right().member(x);
    else
        return true;
}

Tree t{ 50, 40, 30, 10, 20, 30, 100, 0, 45, 55, 25, 15 };

Tree(std::initializer_list<T> init) {
    Tree t;
    for (T v: init) {
        t = t.insert(v);
    }
    _root = t._root;
}