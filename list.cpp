#include <iostream>

//структура для элемента списка
struct Node {
    int data;
    Node* next;//указатель на следующий элемент списка
};

//класс для управления списком
class LinkedList {
private:
    Node* head;//начало списка
public:

    LinkedList() {
        head = nullptr;
    }

    //функция для вставки элемента в начало
    void insertAtBeginning(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = head;
        head = newNode;
    }
    //функция для вставки элемента в конец
    void insertAtEnd(int val)
    {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = nullptr;
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        Node* tmp = head;
        while (tmp->next != nullptr)
        {
            tmp = tmp->next;
        }
        tmp->next = newNode;
    }
    //Вставка элемента по индексу
    void insertAtIndex(int val, int index) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = nullptr;

        if (index == 0) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* tmp = head;
        for (size_t i = 0; i < index - 1; i++)
        {
            if (tmp == nullptr) {
                std::cout << "index out of range" << std::endl;
                return;
            }
            tmp = tmp->next;
        }
        if (tmp == nullptr) {
            std::cout << "Index out of range" << std::endl;
            return;
        }
        newNode->next = tmp->next;
        tmp->next = newNode;
    }

    //Удаление элемента из начала списка
    void deleteFromBegin() {
        if (head == nullptr) {
            std::cout << "List is empty" << std::endl;
            return;
        }
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
    //удаление элемента из конца списка
    void deleteFromEnd() {
        if (head == nullptr)
        {
            std::cout << "List is empty" << std::endl;
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* tmp = head;
        while (tmp->next->next != nullptr) {
            tmp = tmp->next;
        }
        delete tmp->next;
        tmp->next = nullptr;
    }
    //Удаление элемента по индексу
    void deleteAtIndex(int index) {
        if (head == nullptr) {
            std::cout << "List id empty" << std::endl;
            return;
        }
        if (index == 0)
        {
            Node* tmp = head;
            head = head->next;
            delete tmp;
            return;
        }
        Node* tmp = head;
        Node* pred = nullptr;
        for (size_t i = 0; i <= index; i++)
        {
            pred = tmp;
            tmp; tmp->next;
            if (tmp == nullptr) {
                std::cout << "index out of bounds" << std::endl;
                return;
            }
        }
        pred->next = tmp->next;
        delete tmp;
    }

    //Поиск элемента по индексу
    int search(int index) {
        Node* tmp = head;
        for (int i = 0; i < index; i++)
        {
            if (tmp == nullptr)
            {
                std::cout << "index out of range" << std::endl;
                return -1;
            }
            tmp = tmp->next;
        }
        return tmp->data;
    }

    //вывод списка
    void display() {
        Node* tmp = head;
        while (tmp != nullptr)
        {
            std::cout << tmp->data << " ";
            tmp = tmp->next;
        }
        std::cout << std::endl;
    }
};
int main() {
    LinkedList MyList;
    MyList.insertAtBeginning(1);
    MyList.insertAtBeginning(5);
    MyList.display();
    MyList.insertAtEnd(6);
    MyList.display();
    MyList.insertAtIndex(20, 4);
    MyList.display();
    MyList.insertAtIndex(20, 3);
    MyList.display();
    MyList.deleteFromBegin();
    MyList.display();
}