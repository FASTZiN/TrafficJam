// Copyright David Grunheidt 2017
#ifndef STRUCTURES_LINKED_QUEUE_H
#define STRUCTURES_LINKED_QUEUE_H

#include "./linked_list.h"  // Classe a ser herdada (Pilha herda lista)

namespace structures {

    /*!
    * Começo da classe lista encadeada e declaração de suas funções.
    */    
template<typename T>
class LinkedQueue {
 public:
    /*!
    * Construtor da fila encadeada, não possui tamanho maximo especifico.
    */ 
    LinkedQueue();

    /*!
    * Destrutor da fila encadeada.
    */ 
    ~LinkedQueue();

    /*!
    * Limpar fila.
    */ 
    void clear();

    /*!
    * Inserir elemento no fim da fila.
    */ 
    void enqueue(const T& data);

    /*!
    * Retirar elemento do inicio da fila.
    */    
    T dequeue();

    /*!
    * Acessa o elemento no inicio da fila.
    */   
    T& front();

    /*!
    * Acessa o elemento no fim da fila.
    */    
    T& back();

    /*!
    * Acessa o elemento no inicio da fila (SOBRECARGA DE OPERADORES).
    */   
    T& front() const;

    /*!
    * Acessa o elemento no fim da fila (SOBRECARGA DE OPERADORES).
    */    
    T& back() const;

    /*!
    * Verifica se esta vazia.
    */     
    bool empty() const;

    /*!
    * Informa o tamanho da  fila.
    */
    std::size_t size() const;

    /*!
    * Instanciação da lista (a fila possui uma lista);
    */ 
    structures::LinkedList<T> list{};
};  // Fim da classe LinkedQueue.

    template<typename T>
    LinkedQueue<T>::LinkedQueue() {	 	  	 	     	    		     		      	   	 	
    }

    template<typename T>
    LinkedQueue<T>::~LinkedQueue() {
        list.~LinkedList();
    }

    template<typename T>
    void LinkedQueue<T>::clear() {
        list.clear();
    }

    template<typename T>
    void LinkedQueue<T>::enqueue(const T& data) {
        list.push_back(data);
    }

    template<typename T>
    T LinkedQueue<T>::dequeue() {
        return list.pop_front();
    }

    template<typename T>
    T& LinkedQueue<T>::front() {
        return list.at(0);
    }

    template<typename T>
    T& LinkedQueue<T>::back() {
        return list.at(list.size()-1);
    }

    template<typename T>
    T& LinkedQueue<T>::front() const {
        return front();
    }	 	  	 	     	    		     		      	   	 	

    template<typename T>
    T& LinkedQueue<T>::back() const {
        return back();
    }

    template<typename T>
    bool LinkedQueue<T>::empty() const {
        return list.empty();
    }

    template<typename T>
    std::size_t LinkedQueue<T>::size() const {
        return list.size();
    }
}  // Fim do namespace structures.

#endif
