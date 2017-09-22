// Copyright David Grunheidt 2017
#ifndef TRAFFICJAM_ARRAY_LIST_H
#define TRAFFICJAM_ARRAY_LIST_H

#include <cstdint>  // std::size_t
#include <stdexcept>  // C++ Exceptions

namespace structures {

    /*!
    * Classe fila e suas devidas funções.
    */
template<typename T>
class ArrayList {
 public:
    ArrayList();

    /*!
    * Construtor da lista com tamanho especificado.
    * /param max tamanho maximo pemitido da lista.
    */
    explicit ArrayList(std::size_t max_size);
    ~ArrayList();

    /*!
    * Documentação.
    */
    void clear();

    /*!
    * Documentação.
    */    
    void push_back(const T& data);

    /*!
    * Documentação.
    */  
    void push_front(const T& data);

    /*!
    * Documentação.
    */  
    void insert(const T& data, std::size_t index);

    /*!
    * Documentação.
    */  
    void insert_sorted(const T& data);

    /*!
    * Documentação.
    */  
    T pop(std::size_t index);

    /*!
    * Documentação.
    */  
    T pop_back();

    /*!
    * Documentação.
    */  
    T pop_front();

    /*!
    * Documentação.
    */  
    void remove(const T& data);

    /*!
    * Documentação.
    */  
    bool full() const;

    /*!
    * Documentação.
    */  
    bool empty() const;

    /*!
    * Documentação.
    */  
    bool contains(const T& data) const;

    /*!
    * Documentação.
    */  
    std::size_t find(const T& data) const;

    /*!
    * Documentação.
    */  
    std::size_t size() const;

    /*!
    * Documentação.
    */  
    std::size_t max_size() const;

    /*!
    * Documentação.
    */  
    T& at(std::size_t index);

    /*!
    * Documentação.
    */  
    T& operator[](std::size_t index);

    /*!
    * Documentação.
    */  
    const T& at(std::size_t index) const;

    /*!
    * Documentação.
    */  
    const T& operator[](std::size_t index) const;

 private:
    T* contents;
    std::size_t size_;
    std::size_t max_size_;

    static const auto DEFAULT_MAX = 10u;
};  // Fim da classe ArrayList

template<typename T>
ArrayList<T>::ArrayList() {
    ArrayList(DEFAULT_MAX);
}

template<typename T>
ArrayList<T>::ArrayList(std::size_t max) {
    max_size_ = max;
    size_ = -1;
    contents = new T[max_size_];
}

template<typename T>
ArrayList<T>::~ArrayList() {
    delete[] contents;
}

template<typename T>
void ArrayList<T>::clear() {
    if (empty())
        throw std::out_of_range("Your list is empty, there's nothing to clean");
    else
        size_ = -1;
}

template<typename T>
bool ArrayList<T>::full() const {
    return size_ == max_size_-1;
}

template<typename T>
bool ArrayList<T>::empty() const {
    return size_ == -1;
}

template<typename T>
void ArrayList<T>::push_back(const T& data) {
    insert(data, size_+1);
}	 	  	 	     	    		     		      	   	 	

template<typename T>
void ArrayList<T>::push_front(const T& data) {
    insert(data, 0);
}

template<typename T>
void ArrayList<T>::insert(const T& data, std::size_t index) {
    if (full()) {
        throw std::out_of_range("Your  list is full, can't insert this data!");
    } else {
        if ((index > size_+1) || (index < 0)) {
            throw std::out_of_range("This index is invalid");
        } else {
            if (index == size_+1) {
                contents[++size_] = data;
            } else {
                std::size_t aux = ++size_;
                while (aux > index) {
                    contents[aux] = contents[aux-1];
                    aux--;
                }
                contents[index] = data;
            }
        }
    }
}

template<typename T>
T ArrayList<T>::pop_back() {
    return pop(size_);
}

template<typename T>
T ArrayList<T>::pop_front() {
    return pop(0);
}	 	  	 	     	    		     		      	   	 	

template<typename T>
T ArrayList<T>::pop(std::size_t index) {
    if ((index > size_) || (index < 0)) {
        throw std::out_of_range("This index is invalid");
    } else {
        if (empty()) {
            throw std::out_of_range("There's nothing to pop on your list.");
        } else {
            if (index == size_) {
                return contents[size_--];
            } else {
                std::size_t aux; T value;
                size_--;
                value = contents[index];
                aux = index;
                while (aux <= size_) {
                    contents[aux] = contents[aux+1];
                    aux++;
                }
                return value;
            }
        }
    }
}

template<typename T>
void ArrayList<T>::insert_sorted(const T& data) {
    if (full()) {
        throw std::out_of_range("Your  list is full, can't insert this data!");
    } else {
        if (empty()) {
            push_back(data);
        } else {
            std::size_t aux = 0;
            while ((aux <= size_ ) && (data > contents[aux]))
                aux++;
            return insert (data, aux);
        }	 	  	 	     	    		     		      	   	 	
    }
}

template<typename T>
bool ArrayList<T>::contains(const T& data) const {
    bool resp = true;
    try {
        find(data);
    } catch (...) {
        resp = false;
    }
    return resp;
}

template<typename T>
std::size_t ArrayList<T>::find(const T& data) const {
    if (empty()) {
        throw std::out_of_range("Your list is empty, there's nothing to find!");
    } else {
        std::size_t aux = 0;
        while ((aux <= size_) && !(data == contents[aux]))
            aux++;
        if (aux > size_)
            throw std::out_of_range("This object isn't on your list");
        else
            return aux;
    }
}

template<typename T>
void ArrayList<T>::remove(const T& data) {
    if (empty()) {
        throw std::out_of_range("Your list is empty, nothing to remove!");
    } else {
        pop(find(data));
    }	 	  	 	     	    		     		      	   	 	
}

template<typename T>
std::size_t ArrayList<T>::size() const {
    return size_+1;
}

template<typename T>
std::size_t ArrayList<T>::max_size() const {
    return max_size_;
}

template<typename T>
T& ArrayList<T>::at(std::size_t index) {
    if ((index > size_) || (index < 0)) {
        throw std::out_of_range("This index is invalid");
    } else {
        if (empty())
            throw std::out_of_range("There's nothing on your list.");
        else
            return contents[index];
    }
}

template<typename T>
const T& ArrayList<T>::at(std::size_t index) const {
    return at(index);
}

template<typename T>
T& ArrayList<T>::operator[](std::size_t index) {
    return at(index);
}

template<typename T>
const T& ArrayList<T>::operator[](std::size_t index) const {	 	  	 	     	    		     		      	   	 	
    return operator[](index);
}

}  // Fim do namespace structures.

#endif
