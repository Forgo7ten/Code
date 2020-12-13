#pragma once

#ifndef _STACK0_
#define _STACK0_

struct customer {
    char fullname[35];
    double payment;
};

typedef customer SKtype; // 栈的类型，可修改
const int SKSize = 20;  // 默认栈空间大小为20
class Stack {
    SKtype* space;
    int top;
    int size;
public:
    Stack(int Size = SKSize); //构造函数
    ~Stack();       //析构函数
    bool isfull() const;        //检测栈是否已满，若满则返回1，否则返回0
    bool isempty() const;       //检测栈是否为空，是返回1，否则返回0
    bool push(const SKtype& value);    //向栈中压入value，成功返回1，失败返回0
    bool pop(SKtype& value);     //出栈给value，成功返回1，失败返回0
    void show() const;          //将栈展示出来
};

#endif // !_STACK_
