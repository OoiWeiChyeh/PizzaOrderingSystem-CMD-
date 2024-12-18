#ifndef _PIZZA_
#define _PIZZA_

#include <iostream>
#include <string>
#include <iomanip>
#include <ostream>

using namespace std;


// Pizza class to store details of a pizza
class Pizza {
public:
    string name;
    float smallPrice, mediumPrice, largePrice, extraLargePrice;

    
    Pizza(const string& name = "", float small = 0, float medium = 0, float large = 0, float xl = 0)
        : name(name), smallPrice(small), mediumPrice(medium), largePrice(large), extraLargePrice(xl) {}
     
	
};




class Order {
	public:
		string orderID;
		string pizzaName;
		int size;
		int quantity;
		float priceItem;
		
		Order(){}
		Order(string id, string pizza, int s, int qty, float price)
			: orderID(id), pizzaName(pizza), size(s), quantity(qty), priceItem(price) {}
			
};
	



// Queue implementation for order and kitchen queue management
template<typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
    };
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    bool isEmpty() const { return front == nullptr; }

    void enqueue(const T& item) {
        Node* newNode = new Node{item, nullptr};
        if (rear) {
            rear->next = newNode;
        } else {
            front = newNode;
        }
        rear = newNode;
    }

    void dequeue() {
        if (!isEmpty()) {
            Node* temp = front;
            front = front->next;
            delete temp;
            if (!front) rear = nullptr;
        }
    }

    T getFront() const {
        if (isEmpty()) throw "Queue is empty!";
        return front->data;
    }
    
    void printQueue() const{
	Node* current = front;
	while (current != nullptr){
		cout << current -> data << endl;
		current = current -> next;
	} 
	}
	
	void resetQueue(){
		while (!isEmpty())dequeue();
	}

    ~Queue() {
        resetQueue();
    }
};

#endif
