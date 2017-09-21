//  Copyright [2017] <Caio Cardoso>

#ifndef STRUCTURES_CIRCULAR_LIST_H
#define STRUCTURES_CIRCULAR_LIST_H

#include <cstdint>
#include <stdexcept>


namespace structures {

template<typename T>
/*! LISTA CIRCULAR SIMPLES
*    "O fim aponto pro inicio" 
*/
class CircularList {
 public:
/*! CONSTRUTOR
* Inicializa a lista.
*/
    CircularList();
/*! DESTRUTOR
*   Destroi a lista.
*/    
    ~CircularList();
/*! LIMPAR
* Limpa a lista e reinicia os elementos iniciais
*/ 
        void clear();
/*! INSERE NO FIM
* Insere um elemento no fim da fila
*/
    void push_back(const T& data);
/*! INSERE NO INICIO
* Insere um elemento no inicio da fila.
*/    
    void push_front(const T& data);
/*! INSERE NA POSIÇÃO
* Insere um elemento na posição desejada.
*/    
    void insert(const T& data, std::size_t index);
/*! INSERE EM ORDEM
* Insere oredenadamente.
*/    
    void insert_sorted(const T& data);
/*! RETIRA DA POSIÇÃO
* Retira da posição desejada da lista.
*/
    T pop(std::size_t index);
/*! RETIRA DO FIM
* Retira do fim da lista.
*/    
    T pop_back();
/*! RETIRA DO INICIO
* Retira do inicio da lista.
*/    
    T pop_front();
/*! RETIRA ESPECIFICO
* Retira um elemento especifico desejado
*/    
    void remove(const T& data);
/*! VAZIO
* Retorna se a lista esta vazia.
*/
    bool empty() const;
/*! CONTÉM
* Retorna se um elemanto esta contido na lista.
*/    
    bool contains(const T& data) const;
/*! ACESSO A UM ELEMENTO(CHECANDO LIMITES)
* Retorna o que está contido em um daterminado posição da lista.
*/
    T& at(std::size_t index);
/*! getter constante a um elemento
* Retorna o que está contido em um daterminado posição da lista.
*/    
    const T& at(std::size_t index) const;
/*! POSIÇÃO
* Retorna a posição de um certo elemento da lista
*/
    std::size_t find(const T& data) const;
/*! TAMANHO
* Retorna o tamanho da lista.
*/    
    std::size_t size() const;

 private:
    class Node {	 	  	 	     	    		     		      	   	 	
     public:
        explicit Node(const T& data):
          data_{data}
        {}
        Node(const T& data, Node* next):
         data_{data},
             next_{next}
       {}

        T& data() {  // getter: dado
            return data_;
        }

         const T& data() const {  // getter const: dado
            return data_;
        }
        Node* next() {  // getter: próximo
            return next_;
        }

        const Node* next() const {  // getter const: próximo
            return next_;
        }

        void next(Node* node) {  // setter: próximo
            next_ = node;
        }

     private:
        T data_;
        Node* next_;
    };
    Node* sentinela;
    Node* head;
    std::size_t size_;
};

template<typename T>
CircularList<T>::CircularList() {	 	  	 	     	    		     		      	   	 	
    sentinela = new Node(-100);
    head = sentinela;
    size_ = -1;
}

template<typename T>
CircularList<T>::~CircularList() {
    for (auto i = size(); i > 0; i--) {
        pop_back();
    }
    delete sentinela;
}

template<typename T>
void CircularList<T>::clear() {
    for (auto i = size(); i > 0; i--) {
        pop_back();
    }
    head = sentinela;
    size_ = -1;
}

template<typename T>
void CircularList<T>::push_back(const T& data) {
Node *newNode = new Node(data);
    if (empty()) {
        head -> next(newNode);
        size_ = size_ + 1;
    } else {
        Node *x = head;
        for (int i = 0; i <= size_; i++) {
            x = x -> next();
        }
        newNode -> next(head);
        x -> next(newNode);
        size_ = size_ + 1;
        }	 	  	 	     	    		     		      	   	 	
}

template<typename T>
void CircularList<T>::push_front(const T& data) {
    Node *newNode = new Node(data);
    if (empty()) {
        head -> next(newNode);
        newNode -> next(head);
        size_ = size_ + 1;
    } else {
        newNode -> next(head->next());
        head -> next(newNode);
        size_ = size_ +1;
    }
}

template<typename T>
void CircularList<T>::insert(const T& data, std::size_t index) {
    if (index < 0 || index > size_+1) {
        throw std::out_of_range("Invalid Index");
    } else {
        if (empty()) {
            push_front(data);
        } else {
            if (index == size_+1) {
                push_back(data);
            } else {
                if (index == 0) {
                    push_front(data);
                } else {
                auto *pointer = head;
                Node *last = head;
                Node *tmp = new Node(data);
                for (int i = 0; i <= index; i++) {
                    pointer = pointer ->next();
                    if (i == index) {	 	  	 	     	    		     		      	   	 	
                        tmp ->next(pointer);
                        size_ = size_+1;
                    }
                }
                for (int i = 0; i < index; i++) {
                    last = last ->next();
                    if (i == index-1) {
                        last -> next(tmp);
                    }
                  }
            }
        }
    }
  }
}

template<typename T>
void CircularList<T>::insert_sorted(const T& data) {
            Node *tmp = head->next();
    int i = 0;
    bool addSome = false;

    if (empty()) {
        push_front(data);
    } else {
        while ( i < size() && addSome == false ) {
            if (tmp->data() > data) {
                if (i == 0) {
                push_front(data);
                } else {
                        insert(data, i);
                    }
                addSome = true;
                } else {
                    if ( i == size_ ) {
                        push_back(data);
                        addSome = true;
                    }	 	  	 	     	    		     		      	   	 	
                }
            if (i != size_) {
            tmp = tmp ->next();}
            i++;
         }
        }
}

template<typename T>
T CircularList<T>::pop(std::size_t index) {
     auto *before = head, *dlt = head, *after = head;
    if (index < 0 || index > size_) {
        throw std::out_of_range("Invalid Index");
    } else {
        if (empty()) {
            throw std::out_of_range("List is empty");
        } else {
            if (index == 0) {
               return pop_front();
            } else {
                if (index == size_) {
                   return pop_back();
                } else {
                        for (int i = 0; i <= index; i++) {
                             dlt = dlt -> next();
                        }
                        for (int i = 0; i <= index-1; i++) {
                            before = before -> next();
                         }
                            before -> next(dlt -> next());
                         for (int i = 0; i <= index+1; i++) {
                            after = after -> next();
                        }
                            T returnData = dlt -> data();
                            delete dlt;
                            size_ = size_ - 1;
                            return returnData;
                }	 	  	 	     	    		     		      	   	 	
            }
        }
    }
}

template<typename T>
T CircularList<T>::pop_back() {
    Node* before = head;
    Node* dlt = head;

    if (empty()) {
        throw std::out_of_range("List is empty");
    } else {
        if (size_ == 0) {
            return pop_front();
        } else {
        for (int i = 0; i <= size_; i++) {
            dlt = dlt -> next();
        }
        for (int i = 0; i <= size_-1; i++) {
            before = before -> next();
        }
            before -> next(dlt->next());
            T returnData = dlt -> data();
            delete dlt;
            size_ = size_ - 1;
            return returnData;
        }
    }
}

template<typename T>
T CircularList<T>::pop_front() {
    if (empty()) {
        throw std::out_of_range("List is empty");
    } else {	 	  	 	     	    		     		      	   	 	
         Node *dlt = head->next();
        head -> next(dlt -> next());
        T returnData = dlt -> data();
        size_ = size_ - 1;
        delete dlt;
        return returnData;
    }
}

template<typename T>
void CircularList<T>::remove(const T& data) {
        Node *dlt = head->next();
        int i = 0;
        bool removeSome = false;
    if (empty()) {
        throw std::out_of_range("List is empty");
    } else {
        while (i < size() && removeSome == false) {
            if (dlt->data() == data) {
                pop(i);
                removeSome = true;
            } else {
                if (i == size_) {
                    throw std::out_of_range("Data do not exist");
                } else {
                    dlt = dlt -> next();
                }
            }
            i++;
        }
    }
}

template<typename T>
bool CircularList<T>::empty() const {
    return size_ == -1;
}	 	  	 	     	    		     		      	   	 	

template<typename T>
bool CircularList<T>::contains(const T& data) const {
auto *tmp = head;

    if (empty()) {
        throw std::out_of_range("List is empty");
    } else {
      for (int i = 0; i <= size_; i++) {
          tmp = tmp -> next();
          if (data == tmp->data()) {
              return true;
          }
      }
      return false;
    }
}

template<typename T>
T& CircularList<T>::at(std::size_t index) {
    Node *tmp = head;
    if (index < 0 || index > size_) {
        throw std::out_of_range("Invalid Index");
    } else {
        if (empty()) {
            throw std::out_of_range("List is empty");
        } else {
            for (int i = 0; i <= index; i++) {
                 tmp = tmp -> next();
          }
        T& receive = tmp -> data();
        return receive;
        }
    }
}

template<typename T>
const T& CircularList<T>::at(std::size_t index) const {	 	  	 	     	    		     		      	   	 	
    Node *tmp = head;
    if (index < 0 || index > size_) {
        throw std::out_of_range("Invalid Index");
    } else {
        if (empty()) {
            throw std::out_of_range("List is empty");
        } else {
            for (int i = 0; i <= index; i++) {
                 tmp = tmp -> next();
          }
        T& receive = tmp -> data();
        return receive;
        }
    }
}

template<typename T>
std::size_t CircularList<T>::find(const T& data) const {
    Node *tmp = head;
    if (empty()) {
        throw std::out_of_range("List is empty");
    } else {
      for (int i = 0; i <= size_; i++) {
        tmp = tmp -> next();
          if (data == tmp->data()) {
              return i;
          }
      }
      return 10;
    }
}

template<typename T>
std::size_t CircularList<T>::size() const {
    return size_ +1;
}	 	  	 	     	    		     		      	   	 	
}  // namespace structures

#endif
