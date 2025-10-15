#include "queue.h"

void init(Queue &q)
{
    q.front = nullptr;
    q.rear = nullptr;
}

bool isEmpty(const Queue& q)
{
    return q.front == nullptr;
}

void push(Queue& q,std::string val)
{
    QNode* newNode = new QNode;
    newNode ->data = val;
    newNode->next = nullptr;

    if(isEmpty(q))
    {
        q.front = newNode;
        q.rear = newNode;
    }
    else
    {
        q.rear->next = newNode;
        q.rear = newNode;
    }
}

//удаление элемента из начала очереди
std::string pop(Queue &q) {
    if(isEmpty(q)) {
        return ""; // Возвращаем пустую строку
    }
    QNode* tmp = q.front;
    std::string value = tmp->data;

    q.front = q.front->next;
    delete tmp;

    if(q.front == nullptr) {
        q.rear = nullptr;
    }
    return value;
}

std::string peek(const Queue &q)
{
    if(isEmpty(q))
    {
        return "";
    }
    return q.front->data;
}

void clear(Queue &q)
{
    while(!isEmpty(q))
    {
        pop(q);
    }
}
void print(const Queue& q) {
    if (isEmpty(q)) {
        std::cout << "Очередь пуста." << std::endl;
        return;
    }
    std::cout << "Очередь (начало -> конец): ";
    for (QNode* curr = q.front; curr; curr = curr->next) {
        std::cout << "\"" << curr->data << "\" ";
    }
    std::cout << std::endl;
}