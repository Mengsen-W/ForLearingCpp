/*
 * @Author: Mengsen.Wang
 * @Date: 2020-01-26 09:13:30
 * @Last Modified by: Mengsen.Wang
 * @Last Modified time: 2020-01-26 10:03:44
 */

#include <algorithm>

template <typename Object>
class Poly{
    // 多项式类

public:
    Poly(){}
    Ploy(const Poly & rhs) {}
    Poly & operator= (const Poly & rhs) {}
    Poly (Poly && rhs) {}
    Poly operator= (Poly && rhs) {}
    ~Poly (){}

private:
    struct PolyNode{
        Object coef; //系数
        Object expon; //指数
        PolyNode * link;  //指向下一节点的指针
        PolyNode(const Object & x = 0, PolyNode * l = nullptr)
            : coef{x}, expon{x}, link{l} {}
        PolyNode(const Object && x = 0, PolyNode * l = nullptr)
            : coef{std::move(x)}, expon{std::move(x)}, link{l} {}
    };
};