#include <iostream>

using namespace std;


//Задание
// 
//Создать функцию, ведущую поиск элемента в списке по его значению.
//Возвращать указатель на элемент, если он найден и nullptr, если не найден.



template<typename T>
class Node {
public:
    T data;
    Node<T>* next;

    Node(T value) {
        data = value;
        next = nullptr;
    }
};

template<typename T>
class LinkedList {
private:
    Node<T>* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void addElement(T value) {
        Node<T>* newNode = new Node<T>(value);

        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node<T>* temp = head;

            while (temp->next != nullptr) {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    Node<T>* findElement(T value) {
        Node<T>* temp = head;

        while (temp != nullptr) {
            if (temp->data == value) {
                return temp;
            }

            temp = temp->next;
        }

        return nullptr;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    LinkedList<int> myList;

    myList.addElement(5);
    myList.addElement(10);
    myList.addElement(15);
    myList.addElement(20);

    int searchValue = 15;
    Node<int>* foundElement = myList.findElement(searchValue);

    if (foundElement != nullptr) {
        cout << "Элемент " << searchValue << " найден в списке." << std::endl;
    }
    else {
        cout << "Элемент " << searchValue << " не найден в списке." << std::endl;
    }

    return 0;
}

