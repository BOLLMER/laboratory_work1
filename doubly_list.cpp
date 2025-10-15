#include "doubly_list.h"

void initList(DList &list)
{
    list.head = nullptr;
    list.tail = nullptr;
}

//добавление элемента в начало
void addHead(DList &list, const string& val)
{
    //создаем новый узел и указываем на старую голову списка
    DNode* node = new DNode{val, list.head, nullptr};

    if(list.head) //если список не пустой
    {
        //указатель перемещает на новый узел (голова и хвост)
        list.head->prev = node;
    }
    else
        list.tail = node;

    list.head = node; //новая голова
}

//добавление элемента в хвост
void addDTail(DList &list, const string& val)
{
    DNode* node = new DNode{val, nullptr, list.tail};
    if(list.tail)
    //если список не пустой то хвост указывает на новый узел
        list.tail->next = node;
    else
        list.head = node;
    //указатель перемещаем на новый узел
    list.tail = node;
}

//вставка нового узла перед элементом
void addBefore(DList &list, const string& target, const string& val)
{
    if(!list.head)
    {
        cout << "Список пуст" << endl;
        return;
    }

    //создание нового узла
    for(DNode* curr = list.head; curr; curr=curr->next)
    {
        //связывание с предыдущим узлом
        if(curr->value == target)
        {
            DNode* node = new DNode{val, curr, curr->prev};
            if(curr->prev)
            {
                curr->prev->next = node;
            }//если вставляем перед головой списка
            else
                list.head = node;
                //связывание с текущим узлом
            curr->prev = node;
            cout << "Элемент добавлен перед " << target << endl;
            return;
        }
    }
    cout << "Элемент " << target << " не найден" << endl;
}

void addAfter(DList &list, const string& target, const string& val)
{
    if(!list.head)
    {
        cout << "Список пуст" << endl;
        return;
    }

    //вставка после элемента
    for(DNode* curr = list.head; curr; curr=curr->next)
    {
        if(curr->value == target)
        {
            //создание нового узла
            DNode* node = new DNode{val, curr->next, curr};
            if(curr->next)
            {
                //связывание со следующим узлом
                curr->next->prev = node;
            }
            else
                list.tail = node;
            //связывание с текущим (целевым узлом)
            curr->next = node;
            cout << "Элемент добавлен после " << target << endl;
            return;
        }
    }
    cout << "Элемент " << target << " не найден" << endl;
}

void delHead(DList &list)
{
    if(!list.head)
    {
        cout << "Список пуст" << endl;
        return;
    }
    DNode* tmp = list.head;
    list.head = list.head->next;

    if(list.head)
        list.head->prev = nullptr;
    else
        list.tail = nullptr;

    delete tmp;
    cout << "Первый элемент удалён" << endl;
}

void delTail(DList &list)
{
    if(!list.tail)
    {
        cout << "Список пуст" << endl;
        return;
    }

    DNode* tmp = list.tail; // Исправлено: работаем с хвостом
    list.tail = list.tail->prev;

    if(list.tail)
        list.tail->next = nullptr;
    else
        list.head = nullptr;

    delete tmp;
    cout << "Последний элемент удалён" << endl; // Исправлено сообщение
}

void delByVal(DList &list, const string& val) {
    if(!list.head) {
        cout << "Список пуст." << endl;
        return;
    }
    DNode* curr = list.head;
    while(curr && curr->value != val) {
        curr = curr->next;
    }

    if (!curr) {
        cout << "Элемент " << val << " не найден." << endl;
        return;
    }

    if (curr->prev)
        curr->prev->next = curr->next;
    else
        list.head = curr->next;

    if (curr->next)
        curr->next->prev = curr->prev;
    else
        list.tail = curr->prev;

    delete curr;
    cout << "Элемент \"" << val << "\" удален." << endl;
}

DNode* findValue(const DList &list, const string& val) {
    for(DNode* curr = list.head; curr; curr = curr->next) {
        if(curr->value == val) {
            return curr;
        }
    }
    return nullptr;
}

void readForward(const DList &list)
{
    if(!list.head)
    {
        cout << "Список пуст" << endl;
        return;
    }

    cout << "Список вперед: ";
    for(DNode* curr = list.head; curr; curr = curr->next)
        cout << curr->value << " ";
    cout << endl;
}

void readBackward(const DList &list)
{
    if(!list.tail)
    {
        cout << "Список пуст" << endl;
        return;
    }

    cout << "Список назад: ";
    for(DNode* curr = list.tail; curr; curr= curr->prev)
    {
        cout << curr->value << " ";
    }
    cout << endl;
}

void clearList(DList &list)
{
    while(list.head)
    {
        DNode* tmp = list.head;
        list.head = list.head ->next;
        delete tmp;
    }
    list.tail = nullptr;
}

void delAfterValue(DList &list, const string& val) {
    DNode* targetNode = findValue(list, val);
    if (!targetNode || !targetNode->next) {
        cout << "Элемент '" << val << "' не найден или он последний." << endl;
        return;
    }
    delByVal(list, targetNode->next->value);
}

void delBeforeValue(DList &list, const string& val) {
    DNode* targetNode = findValue(list, val);
    if (!targetNode || !targetNode->prev) {
        cout << "Элемент '" << val << "' не найден или он первый." << endl;
        return;
    }
    // Используем уже существующую функцию
    delByVal(list, targetNode->prev->value);
}
