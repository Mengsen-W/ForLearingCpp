/*
 * @Author: Mengsen.Wang
 * @Date: 2020-01-25 09:15:31
 * @Last Modified by: Mengsen.Wang
 * @Last Modified time: 2020-01-25 13:38:08
 */

#include <algorithm>
#define NOT_FOUND -1

template <typename Object>
class Vector {
public:
// 管理函数

    // 默认构造函数
    explicit Vector(int initSize = 0) : theSize{initSize}, theCapacity{initSize + SPARE_CAPACITY}
    {objects = new Object[theCapacity];}
    // 默认拷贝构造
    Vector(const Vector & rhs) : theSize{rhs.theSize}, theCapacity{rhs.theCapacity}, objects{nullptr}
    {
        objects = new Object [theCapacity];
        for(int i = 0; i < theSize; ++i){
            objects[i] = rhs.objects[i];
        }
    }

    // 拷贝赋值函数
    Vector & operator= (const Vector & rhs){
        Vector copy = rhs;
        std::swap(*this, copy);
        return *this;
    }

    // 析构函数
    ~Vector(){delete [] objects;}

    // 移动构造函数
    Vector(Vector && rhs) : theSize{rhs.size}, theCapacity{rhs.Capacity},objects{rhs.objects}
    {
        rhs.objects = nullptr;
        rhs.theSize = 0;
        rhs.theCapacity = 0;
    }

    // 的移动赋值函数
    Vector & operator= (Vector && rhs){
        std::swap(theSize,rhs.theSize);
        std::swap(theCapacity, rhs.theCapacity);
        std::swap(objects, rhs.objects);
        return *this;
    }

// 方法函数

    // 提供改变大小的方法
    void resize(int newSize){
        if(newSize > theCapacity)
            reserve(newSize * 2);
        theSize = newSize;
    }

    // 提供改变容量的方法
    void reserve(int newCapacity){
        if (newCapacity < theSize){
            return;
        }
         // 不是构造函数创建的变量要手动释放
        Object *newArray = new Object[newCapacity];
        for(int k = 0; k < theSize; ++k)
            newArray[k] = std::move(objects[k]);
        theCapacity = newCapacity;
        std::swap(objects, newArray);
        delete [] newArray;
    }

    // 重载下标运算符 [] 非常量版本
    Object & operator[] (int index){
        if (index < 0 && index > this.size() - 1)
            return NOT_FOUND;
        return objects[index];
        }

    // 重载小表运算符 [] 常量版本
    const Object & operator[] (int index) const {
        if (index < 0 && index > this.size() - 1)
            return NOT_FOUND;
        return objects[index];
    }

    // 判断是否为空方法
    bool empty() const {return size() == 0;}

    // 返回大小方法
    int size() const {return theSize;}

    // 返回容量方法
    int capacity () const {return theCapacity;}

    // 推入元素方法左值引用版本
    void push_back(const Object & x) {
        if(theSize == theCapacity)  //判断是否已满
            reserve(2 * theCapacity + 1);
        objects[theSize++] = x; //推入数组
    }

    //  推入元素方法的右值引用版本
    void push_back(Object && x){    //临时变量不能 const 传入
        if(theSize == theCapacity)  //判断是否已满
            reserve(2 * theCapacity + 1);
        objects[theSize++] = std::move(x); //推入数组
    }

    // 弹出元素
    void pop_back(){
        --theSize;
    }

    // 最后一个元素
    const Object & back() const {
        return objects[theSize - 1];
    }

// 迭代器定义
typedef Object * iterator;
typedef const Object * const_iterator;

    // 开始器指向第一个元素非常量版本
    iterator begin(){return & objects[0];}

    // 开始器指向第一个元素常量版本
    const_iterator begin() const {return & objects[0];}

    // 结束器指向尾元素非常量版本
    iterator end(){return & objects [size()];}

    // 结束器指向尾元素常量版本
    const_iterator end() const {return & objects [size()];}

    static const int SPARE_CAPACITY = 16;

private:
    int theSize;        //储存个数
    int theCapacity;    // 最大个数
    Object * objects;   // 储存指针
};

int main() {
    return 0;
}