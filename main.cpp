#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>


#include "arr.h"
#include "doubly_list.h"
#include "list.h"
#include "queue.h"
#include "stack.h"
#include "tree.h"

using namespace std;

void saveData(const MyArr& arr)
{
    ofstream file("array.txt");
    for(int i=0; i< arr.size; i++)
    {
        file << arr.data[i] << endl;
    }
}

void saveData(const MyList& list)
{
    ofstream file("slist.txt");
    for(Node* curr = list.head; curr; curr = curr ->next)
    {
        file << curr ->value << endl;
    }
}
void saveData(const DList& list)
{
    ofstream file("dlist.txt");
    for(DNode* curr = list.head; curr; curr = curr->next)
    {
        file << curr ->value << endl;
    }
}

void saveData(const Queue& q)
{
    ofstream file("queue.txt");
    for(QNode* curr = q.front; curr; curr = curr->next)
    {
        file << curr->data << endl;
    }
}

void saveData(const Stack& stack)
{
    ofstream file("stack.txt");
    for(SNode* curr = stack.top; curr; curr = curr->next)
    {
        file << curr->value << endl;
    }
}

void saveTreeNodes(TreeNode* node, ofstream& file) {
    if (!node) return;
    file << node->data << endl;
    saveTreeNodes(node->left, file);
    saveTreeNodes(node->right, file);
}

void saveData(const CompleteBinaryTree* tree)
{
    ofstream file("tree.txt");
    if (tree) {
        saveTreeNodes(tree->root, file);
    }
}

void loadData(MyArr& arr)
{
    ifstream file("array.txt");
    string val;
    while(file >> val)
    {
        addEnd(arr,val);
    }
}

void loadData(MyList& list)
{
    ifstream file ("slist.txt");
    string val;
    while(file >> val)
    {
        addTail(list,val);
    }
}

void loadData(DList& list)
{
    ifstream file("dlist.txt");
    string val;
    while(file >> val)
    {
        addDTail(list,val);
    }
}

void loadData(Queue& q)
{
    ifstream file("queue.txt");
    string val;
    while(file >> val)
    {
        push(q,val);
    }
}

void loadData(Stack& stack) {
    ifstream file("stack.txt");
    string val;
    string full_content;
    while(getline(file, val)) {
        full_content = val + "\n" + full_content;
    }
    stringstream ss(full_content);
    while(getline(ss, val)) {
        if (!val.empty()) {
           push(stack, val);
        }
    }
}

void loadData(CompleteBinaryTree* tree)
{
    ifstream file("tree.txt");
    int val;
    while(file >> val)
    {
        insertCBT(tree, val);
    }
}

void showComm() {
    cout << "--- ОБЩИЕ КОМАНДЫ ---\n"
         << "PRINT    - Показать содержимое структуры\n"
         << "HELP     - Показать это сообщение\n"
         << "EXIT     - Выйти из программы\n\n"
         << "--- МАССИВ (M) ---\n"
         << "M_PUSH_END   - Добавить в конец массива\n"
         << "M_PUSH_AT    - Добавить по индексу\n"
         << "M_DEL_AT     - Удалить по индексу\n"
         << "M_GET_AT     - Получить по индексу\n"
         << "M_REPLACE_AT - Заменить по индексу\n"
         << "M_LENGTH     - Узнать длину массива\n\n"
         << "--- СПИСКИ (F - односвязный, L - двусвязный) ---\n"
         << "F_PUSH_HEAD / L_PUSH_HEAD - Добавить в начало\n"
         << "F_PUSH_TAIL / L_PUSH_TAIL - Добавить в конец\n"
         << "F_PUSH_AFTER / L_PUSH_AFTER - Добавить после значения\n"
         << "F_PUSH_BEFORE / L_PUSH_BEFORE - Добавить до значения\n"
         << "F_DEL_HEAD / L_DEL_HEAD - Удалить первый элемент\n"
         << "F_DEL_TAIL / L_DEL_TAIL - Удалить последний элемент\n"
         << "F_DEL_VAL / L_DEL_VAL - Удалить по значению\n"
         << "F_GET_VAL / L_GET_VAL - Найти по значению\n\n"
         << "--- ОЧЕРЕДЬ (Q) ---\n"
         << "Q_PUSH   - Добавить в очередь\n"
         << "Q_POP    - Извлечь из очереди\n"
         << "Q_GET    - Прочитать первый элемент\n\n"
         << "--- СТЕК (S) ---\n"
         << "S_PUSH   - Добавить в стек\n"
         << "S_POP    - Извлечь из стека\n"
         << "S_GET    - Прочитать верхний элемент\n\n"
         << "--- ДЕРЕВО (T) ---\n"
         << "T_INSERT      - Вставить число в дерево (как в BST)\n"
         << "T_SEARCH      - Найти число в дереве\n"
         << "T_DEL         - Удалить число из дерева\n"
         << "T_IS_COMPLETE - Проверить, является ли дерево полным\n"
         << "T_ISEMPTY     - Проверить, пусто ли дерево\n"
         << "T_CLEAR       - Очистить дерево\n"
         << "VISUALIZE     - Визуализировать дерево\n"
         << "-----------------------\n";
}

int main()
{
    MyArr arr;
    initArray(arr);
    MyList slist;
    initList(slist);
    DList dlist;
    initList(dlist);
    Queue queue;
    init(queue);
    Stack stack;
    initStack(stack);
    CompleteBinaryTree* tree = createCBT();

    loadData(arr);
    loadData(slist);
    loadData(dlist);
    loadData(queue);
    loadData(stack);
    loadData(tree);

    cout << "Данные загружены. Введите 'HELP' для списка команд.\n";

    string cmd;
    while (true) {
        cout << "> ";
        cin >> cmd;
        transform(cmd.begin(), cmd.end(), cmd.begin(), ::toupper);

        if (cmd == "EXIT" || cmd == "BACK") break;
        if (cmd == "HELP")
        {
            showComm();
            continue;
        }

        string v, target;
        int i, v_int;

        if (cmd == "M_PUSH_END") {
            cout << "Строка для добавления: ";
            cin >> v;
            addEnd(arr, v);
            saveData(arr);
        } else if (cmd == "M_PUSH_AT") {
            cout << "Индекс: ";
            cin >> i;
            cout << "Строка: ";
            cin >> v;
            addAt(arr, i, v);
            saveData(arr);
        } else if (cmd == "M_DEL_AT") {
            cout << "Индекс: ";
            cin >> i;
            delAt(arr, i);
            saveData(arr);
        } else if (cmd == "M_GET_AT") {
            cout << "Индекс: ";
            cin >> i;
            getAt(arr, i);
        } else if (cmd == "M_REPLACE_AT") {
            cout << "Индекс: ";
            cin >> i;
            cout << "Новая строка: ";
            cin >> v;
            repArr(arr, i, v);
            saveData(arr);
        } else if (cmd == "M_LENGTH") {
            cout << "Длина массива: " << lenArr(arr) << endl;
        }

        else if (cmd == "F_PUSH_HEAD") {
            cout << "Строка: ";
            cin >> v;
            addHead(slist, v);
            saveData(slist);
        } else if (cmd == "F_PUSH_TAIL") {
            cout << "Строка: ";
            cin >> v;
            addTail(slist, v);
            saveData(slist);
        } else if (cmd == "F_PUSH_AFTER") {
            cout << "Значение, после которого добавить: ";
            cin >> target;
            cout << "Новая строка: ";
            cin >> v;
            addAfter(slist, target, v);
            saveData(slist);
        } else if (cmd == "F_PUSH_BEFORE") {
            cout << "Значение, перед которым добавить: ";
            cin >> target;
            cout << "Новая строка: ";
            cin >> v;
            addBefore(slist, target, v);
            saveData(slist);
        } else if (cmd == "F_DEL_HEAD") {
            delHead(slist);
            saveData(slist);
        } else if (cmd == "F_DEL_TAIL") {
            delTail(slist);
            saveData(slist);
        } else if (cmd == "F_DEL_VAL") {
            cout << "Строка для удаления: ";
            cin >> v;
            delByValue(slist, v);
            saveData(slist);
        } else if (cmd == "F_GET_VAL") {
            cout << "Строка для поиска: ";
            cin >> v;
            findValue(slist, v);
        }

        else if (cmd == "L_PUSH_HEAD") {
            cout << "Строка: ";
            cin >> v;
            addHead(dlist, v);
            saveData(dlist);
        } else if (cmd == "L_PUSH_TAIL") {
            cout << "Строка: ";
            cin >> v;
            addDTail(dlist, v);
            saveData(dlist);
        } else if (cmd == "L_PUSH_AFTER") {
            cout << "Значение, после которого вставить: ";
            cin >> target;
            cout << "Новая строка: ";
            cin >> v;
            addAfter(dlist, target, v);
            saveData(dlist);
        } else if (cmd == "L_PUSH_BEFORE") {
            cout << "Значение, перед которым вставить: ";
            cin >> target;
            cout << "Новая строка: ";
            cin >> v;
            addBefore(dlist, target, v);
            saveData(dlist);
        } else if (cmd == "L_DEL_HEAD") {
            delHead(dlist);
            saveData(dlist);
        } else if (cmd == "L_DEL_TAIL") {
            delTail(dlist);
            saveData(dlist);
        } else if (cmd == "L_DEL_VAL") {
            cout << "Строка для удаления: ";
            cin >> v;
            delByVal(dlist, v);
            saveData(dlist);
        } else if (cmd == "L_GET_VAL") {
            cout << "Строка для поиска: ";
            cin >> v;
            if(findValue(dlist,v))
                cout << "Элемент найден\n";
            else
                cout << "Элемент не найден\n";
        }

        else if (cmd == "Q_PUSH") {
            cout << "Строка: ";
            cin >> v;
            push(queue, v);
            saveData(queue);
        } else if (cmd == "Q_POP") {
            cout << "Удален элемент: " << pop(queue) << endl;
            saveData(queue);
        } else if (cmd == "Q_GET") {
            if(!isEmpty(queue))
                cout << "Первый элемент: \"" << peek(queue) << "\"" << endl;
            else
                cout << "Очередь пуста\n";
        }

        else if (cmd == "S_PUSH") {
            cout << "Строка: ";
            cin >> v;
            push(stack, v);
            saveData(stack);
        } else if (cmd == "S_POP") {
            cout << "Удален элемент: \"" << pop(stack) << "\"" << endl;
            saveData(stack);
        } else if (cmd == "S_GET") {
            if(stack.top)
                cout << "Верхний элемент: \"" << peek(stack) << "\"" << endl;
            else
                cout << "Стек пуст\n";
        }

        else if (cmd == "T_INSERT") {
            cout << "Число для вставки: ";
            cin >> v_int;
            insertCBT(tree, v_int);
            saveData(tree);
        } else if (cmd == "T_SEARCH") {
            cout << "Число для поиска: ";
            cin >> v_int;
            if(searchCBT(tree, v_int)) {
                cout << "Элемент " << v_int << " найден." << endl;
            } else {
                cout << "Элемент " << v_int << " не найден." << endl;
            }
        } else if (cmd == "T_DEL") {
            cout << "Число для удаления: ";
            cin >> v_int;
            deleteNodeCBT(tree, v_int);
            saveData(tree);
        } else if (cmd == "VISUALIZE") {
            printTreeCBT(tree);
        } else if (cmd == "T_ISEMPTY") {
            if (isEmptyCBT(tree)) {
                cout << "Дерево пустое." << endl;
            } else {
                cout << "Дерево не пустое." << endl;
            }
        } else if (cmd == "T_CLEAR") {
            clearCBT(tree);
            saveData(tree);
        }
        else if (cmd == "T_IS_COMPLETE") {
            isComplete(tree);
        }

        else if (cmd == "PRINT") {
             string type;
             cout << "Какую структуру напечатать? (M, F, L, Q, S): ";
             cin >> type;
             transform(type.begin(), type.end(), type.begin(), ::toupper);
             if (type == "M") readArray(arr);
             else if (type == "F") readForward(slist);
             else if (type == "L") readForward(dlist);
             else if (type == "Q") print(queue);
             else if (type == "S") readStack(stack);
        }
        else {
            cout << "Неизвестная команда. Введите HELP для помощи.\n";
        }
    }

    freeArr(arr);
    freeList(slist);
    clearList(dlist);
    clear(queue);
    clearStack(stack);
    deleteCBT(tree);

    cout << "Программа завершена." << endl;
    return 0;
}