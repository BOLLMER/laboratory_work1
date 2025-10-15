#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>

struct QNode {
    std::string data;
    QNode* next;
};

struct Queue {
    QNode* front;
    QNode* rear;
};

void init(Queue &q);
bool isEmpty(const Queue& q);
void push(Queue& q, std::string val);
std::string pop(Queue &q);
std::string peek(const Queue &q);
void clear(Queue &q);
void print(const Queue& q);

#endif
