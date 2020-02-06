/*
 * @Author: Mengsen.Wang
 * @Date: 2020-01-25 13:34:32
 * @Last Modified by:   Mengsen.Wang
 * @Last Modified time: 2020-01-25 22:05:32
 */

#include <algorithm>

template <typename Object>
class List
{
private:
    // 结点类
    struct Node
    {
        // 数据域
        Object data;
        // 前结点指针
        Node *prev;
        // 后节点指针
        Node *next;
        // 拷贝构造函数
        Node(const Object &d = Object{}, Node *p = nullptr, Node *n = nullptr)
            : data{d}, prev{p}, next{n} {}
        // 移动构造函数
        Node(Object &&d, Node *p = nullptr, Node *n = nullptr)
            : data{std::move(d)}, prev{p}, next{n} {}
    };

public:
    // 迭代器类常量版
    class const_iterator
    {
    public:
        // 默认构造函数
        const_iterator() : current(nullptr) {}
        // 重载解指针 * 符号
        const Object &operator*() const { return retrieve(); }
        // 重载 前置自增 符号
        const_iterator &operator++()
        {
            current = current->next;
            return this;
        }
        // 重载后置自增
        const_iterator &operator++(int)
        {
            const_iterator old = *this;
            ++(*this);
            return old;
        }
        // 重载 ==
        bool operator==(const const_iterator &rhs) const
        {
            return current == rhs.current;
        }
        // 重载 !=
        bool operator!=(const const_iterator &rhs) const
        {
            return !(*this == rhs); // 只有一个数据成员
        }

    protected:
        // 储存一个链表
        const List<Object> *theList;
        // 当前节点指针
        Node *current;
        // 取节点数据域
        Object &retrieve() const { return current->data; }
        // 默认构造函数
        const_iterator(Node *p) : current{p} {}
        // 带有链表的构造函数
        const_iterator(const List<Object> &lst, Node *p)
            : theList{&lst}, current{p} {}
        // 判断是否可插入
        void assertLsValid() const
        {
            if (theList == nullptr || current == nullptr || current == theList->head)
                throw;
        }
        // 友元声明
        friend class List<Object>;
    };
    // 迭代器类非常量版
    class iterator : public const_iterator
    {
    public:
        // 默认构造函数
        iterator() {}
        // 重载解指针 * 符号
        Object &operator*() { return const_iterator::retrieve(); }
        const Object &operator*() const { return const_iterator::operator*(); }

        // 重载 前置自增 符号
        iterator &operator++()
        {
            this->current = this->current->next;
            return this;
        }
        // 重载后置自增
        iterator &operator++(int)
        {
            const_iterator old = *this;
            ++(*this);
            return old;
        }

    protected:
        // 默认构造函数
        iterator(Node *p) : const_iterator{p} {}
        // 友元声明
        friend class List<Object>;
    };

public:
    // 管理函数

    // 默认构造函数
    List() { init(); }
    // 默认拷贝函数
    List(const List &rhs)
    {
        init();
        for (auto &x : rhs)
            push_back(x);
    }
    // 拷贝赋值函数
    List &operator=(const List &rhs)
    {
        List copy = rhs;
        std::swap(*this, copy);
        return *this;
    }
    // 移动拷贝函数
    List(List &&rhs) : theSize{rhs.theSize}, head{rhs.head}, tail{rhs.tail}
    {
        rhs.theSize = 0;
        rhs.head = nullptr;
        rhs.tail - nullptr;
    }
    // 移动赋值函数
    List &operator=(List &&rhs)
    {
        std::swap(theSize, rhs.theSize);
        std::swap(head, rhs.head);
        std::swap(tail, rhs.tail);
        return *this;
    }
    // 析构函数
    ~List()
    {
        clear();
        delete head;
        delete tail;
    }

    // 迭代器操作

    // 获取头节点非常量版本
    iterator begin() { return {head->next}; } // 返回一个构造函数
    // 获取头节点常量版本
    const_iterator begin() const
    {
        const_iterator itr { *this, head };
        return ++itr;
    }
    // 获取尾节点非常量版
    iterator end() { return {tail}; }
    // 获取尾节点常量版本
    const_iterator end() const { return {tail}; }
    // 迭代器插入拷贝版本
    iterator insert(iterator itr, const Object &x)
    {
        itr.assertIsValid();
        if (itr.theList != this)
            throw;
        Node *p = itr.current;
        ++theSize;
        return {p->prev = p->prev->next = new Node{x, p->prev, p}};
    }
    // 迭代器插入移动版本
    iterator insert(iterator itr, Object &&x)
    {
        Node *p = itr.current;
        ++theSize;
        return {p->prev = p->prev->next = new Node{std::move(x), p->prev, p}};
    }
    // 迭代器擦除全部节点
    iterator erase(iterator itr)
    {
        Node *p = itr.current;
        iterator retVal{p->next};
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
        --theSize;
        return retVal;
    }
    // 迭代器擦除范围节点
    iterator erase(iterator from, iterator to)
    {
        for (iterator itr = from; itr != to;)
            itr = erase(itr);
        return to;
    }
    // 类方法

    // 获取大小
    int size() const { return theSize; }
    // 判断是否为空
    bool empty() const { return size() == 0; }
    // 清空链表
    void clear()
    {
        while (!empty())
            pop_front();
    }
    // 获取头结点非常量版本
    Object &front() { return *begin(); }
    // 获取头节点常量版本
    const Object &front() const { return *begin(); }
    // 获取尾节点非常量版本
    Object &back() { return *(--end()); }
    // 获取尾节点常量版本
    const Object &back() const { return *(--end()); }
    // 头推入节点拷贝版本
    void push_front(const Object &x)
    {
        insert(begin(), x);
    }
    // 头推入节点移动版本
    void push_front(Object &&x)
    {
        intert(begin(), std::move(x));
    }
    // 尾推入节点拷贝版本
    void push_back(const Object &x)
    {
        insert(end(), x);
    }
    // 尾推入节点移动版本
    void push_back(Object &&x)
    {
        insert(end(), std::move(x));
    }
    // 头弹出节点
    void pop_front()
    {
        erase(begin());
    }
    // 尾弹出节点
    void pop_end()
    {
        eraser(--end());
    }

private:
    // 节点数目
    int theSize;
    // 头节点指针
    Node *head;
    // 尾节点指针
    Node *tail;

    // 初始化方法
    void init()
    {
        theSize = 0;
        head = new Node;
        tail = new Node;
        head->next = tail;
        tail->prev = head;
    }
};

int main() { return 0; }