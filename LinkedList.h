// Copyright David Grunheidt 2017
#ifndef STRUCTURES_LINKED_LIST_H
#define STRUCTURES_LINKED_LIST_H

#include <cstdint>  // std::size_t
#include <stdexcept>  // C++ exceptions


namespace structures {

    /*!
    * Começo da classe lista encadeada e declaração de suas funções.
    */
template<typename T>
class LinkedList {
 public:
    /*!
    * Construtor da lista encadeada, não possui tamanho maximo especifico.
    */ 
    LinkedList();

    /*!
    * Destrutor da lista encadeada.
    */ 
    ~LinkedList();

    /*!
    * Limpar lista.
    */ 
    void clear();

    /*!
    * Inserir no fim.
    */     
    void push_back(const T& data);

    /*!
    * Inserir no início.
    */     
    void push_front(const T& data);

    /*!
    * Inserir na posição.
    */     
    void insert(const T& data, std::size_t index);

    /*!
    * Inserir em ordem.
    */     
    void insert_sorted(const T& data);

    /*!
    * Acessar um elemento na posição index.
    */     
    T& at(std::size_t index);

    /*!
    * Retirar da posição.
    */     
    T pop(std::size_t index);

    /*!
    * Retirar do fim.
    */     
    T pop_back();

    /*!
    * Retirar do início.
    */     
    T pop_front();

    /*!
    * Remover específico.
    */     
    void remove(const T& data);

    /*!
    * Verifica se a lista esta vazia.
    */     
    bool empty() const;

    /*!
    * Verifica se a lista contem um elemento especifico.
    */     
    bool contains(const T& data) const;

    /*!
    * Retorna a posição do dado, se ele existir na lista.
    */     
    std::size_t find(const T& data) const;

    /*!
    * Retorna o tamanho atual da lista.
    */     
    std::size_t size() const;

 private:
    /*!
    * Começo da classe node (Elemento) e declaração de suas funções.
    */ 
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
        Node* next_{nullptr};
    };  // Fim da classe node.

    Node* end() {  // último nodo da lista
        auto it = head;
        for (auto i = 1u; i < size(); ++i) {
            it = it->next();
        }
        return it;
    }

    Node* head{nullptr};
    Node* tail{nullptr};
    std::size_t size_;
};  // Fim da clsse LinkedList.

    template<typename T>
    LinkedList<T>::LinkedList() {
        size_ = 0;
    }

    template<typename T>
    LinkedList<T>::~LinkedList() {
        clear();
        delete head;
        delete tail;
    }

    template<typename T>
    void LinkedList<T>::clear() {
        while (!empty())
            pop_front();
    }

    template<typename T>
    void LinkedList<T>::push_back(const T& data) {
        Node* new_data_;
        new_data_ = new Node(data);
        if (new_data_ == NULL) {
            throw std::out_of_range("There's no memory available.");
        } else {
            if (empty()) {
                head = new_data_;
                tail = new_data_;
            } else {
                tail->next(new_data_);
                tail = new_data_;
            }
            size_++;
        }
    }

    template<typename T>
    void LinkedList<T>::push_front(const T& data) {
        Node* new_data_ = new Node(data);
        if (new_data_ == NULL) {
            throw std::out_of_range("There's no memory available.");
        } else {
            if (empty()) {
                head = new_data_;
                tail = new_data_;
            } else {
                new_data_->next(head);
                head = new_data_;
            }
            size_++;
        }
    }

    template<typename T>
    void LinkedList<T>::insert(const T& data, std::size_t index) {
        index++;
        if ((index > size_+1) || (index < 1)) {
            throw std::out_of_range("This index isn't available.");
        } else {
            if (index == 1) {
                return push_front(data);
            } else {
                if (index == size_+1) {
                    return push_back(data);
                } else {
                    Node* new_data_;
                    Node* previous_data_;
                    new_data_ = new Node(data);
                    if (new_data_ == NULL) {
                        throw std::out_of_range("There's no memory available.");
                    } else {
                        previous_data_ = head;
                        for (int i  = 1; i < index-1; i++) {
                            previous_data_ = previous_data_->next();
                        }
                        new_data_->next(previous_data_->next());
                        previous_data_->next(new_data_);
                        size_++;
                    }
                }
            }
        }
    }

    template<typename T>
    void LinkedList<T>::insert_sorted(const T& data) {
        if (empty()) {
            return push_front(data);
        } else {
            Node* aux_ = head;
            std::size_t index = 1;
            while ((aux_->next() != nullptr) && (data > aux_->data())) {
                aux_ = aux_->next();
                index++;
            }
            if (data > aux_->data())
                return push_back(data);
            else
                return insert(data, index-1);
        }
    }

    template<typename T>
    T& LinkedList<T>::at(std::size_t index) {
        index++;
        if ((index > size_) || (index < 1)) {
            throw std::out_of_range("This index is invalid");
        } else {
            Node* aux_ = head;
            for (std::size_t i = 1; i < index; i++)
                aux_ = aux_->next();
            return aux_->data();
        }
    }

    template<typename T>
    T LinkedList<T>::pop(std::size_t index) {
        index++;
        if ((index > size_) || (index < 1)) {
            throw std::out_of_range("This index isn't available.");
        } else {
            if (index == 1) {
                return pop_front();
            } else {
                if (index == size_) {
                    return pop_back();
                } else {
                    Node* previous_data_;
                    Node* out_;
                    T backup_;
                    previous_data_ = head;
                    for (int i = 1; i < index-1; i++)
                        previous_data_ = previous_data_->next();
                    out_ = previous_data_->next();
                    backup_ = out_->data();
                    previous_data_->next(out_->next());
                    delete out_;
                    size_--;
                    return backup_;
                }
            }
        }
    }

    template<typename T>
    T LinkedList<T>::pop_back() {
        if (empty()) {
            throw std::out_of_range("There's no data on your list to pop.");
        } else {
            if (size_ == 1) {
                return pop_front();
            } else {
                Node* out_ = tail;
                Node* aux_ = head;
                T backup_ = out_->data();
                for (std::size_t i = 1; i < size_-1; i++)
                    aux_ = aux_->next();

                tail = aux_;
                aux_ = aux_->next();
                if (out_->data() != aux_->data())
                    delete[] aux_;
                delete out_;
                size_--;
                return backup_;
            }
        }
    }

    template<typename T>
    T LinkedList<T>::pop_front() {
        if (empty()) {
             throw std::out_of_range("There's no data on your list to pop.");
        } else {
            Node* out_ = head;
            T backup_ = out_->data();
            if (size_ == 1) {
                tail = nullptr;
                head = nullptr;
            } else {
                head = out_->next();
            }
            size_--;
            delete out_;
            return backup_;
        }
    }

    template<typename T>
    void LinkedList<T>::remove(const T& data) {
        pop(find(data));
    }

    template<typename T>
    bool LinkedList<T>::empty() const {
        return size_ == 0;
    }

    template<typename T>
    bool LinkedList<T>::contains(const T& data) const {
        bool resp = true;
        try {
                find(data);
        } catch (...) {
                resp = false;
        }
        return resp;
    }

    template<typename T>
    std::size_t LinkedList<T>::find(const T& data) const {
        if (empty()) {
            throw std::out_of_range("There's no data on your list");
        } else {
            Node* aux_ = head;
            std::size_t index_at_ = 1;
            while ((aux_->data() != data) && (aux_->next() != nullptr)) {
                aux_ = aux_->next();
                index_at_++;
            }
                if ((index_at_ == size_) && (aux_->data() != data)) {
                    throw std::out_of_range("This data isn't on your list");
                } else {
                    return index_at_-1;
                }
        }
    }

    template<typename T>
    std::size_t LinkedList<T>::size() const {
        return size_;
    }
}  // Fim do namespace structures.

#endif
