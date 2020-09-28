#ifndef LAB7_CIRCULAR_BUFFER_H
#define LAB7_CIRCULAR_BUFFER_H

#include <iterator>

template <typename Type>
class  Circular_buffer{
public:
    class iterator: public std::iterator<std::random_access_iterator_tag, Type> {
    private:
        Type* ptr;
        size_t capacity, index;

    public:
        iterator* begin_b;
        iterator(): ptr(NULL), capacity(0), index(0), begin_b(nullptr) {}
        iterator(Type* p, size_t cap, size_t ind): ptr(p), capacity(cap), index(ind) {}

        iterator& operator++() {
            if (index + 1 == capacity){
                ptr = ptr - index;
                index = 0;
            }else {
                ptr++;
                index++;
            }
            return *this;
        }
        iterator operator++(int) {
            iterator tmp(*this);
            tmp.capacity = capacity;
            tmp.index = index;
            tmp.begin_b = begin_b;
            if (index + 1 == capacity){
                ptr = ptr - index;
                index = 0;
            } else{
                ptr++;
                index++;
            }
            return tmp;
        }
        iterator& operator--() {
            if (index == 0){
                index = capacity - 1;
                ptr = ptr + index;
            } else{
                ptr--;
                index--;
            }
            return *this;
        }
        iterator operator--(int) {
            iterator tmp(*this);
            tmp.capacity = capacity;
            tmp.index = index;
            tmp.begin_b = begin_b;
            if (index == 0){
                index = capacity - 1;
                ptr = ptr + index;
            } else{
                ptr--;
                index--;
            }
            return tmp;
        }

        void operator+=(const std::size_t& n) {
            if (n < 0){
                size_t inv_n = -n;
                if (index - inv_n < 0){
                    ptr = ptr - index;
                    index = capacity - (inv_n - index);
                    ptr = ptr + index;
                } else{
                    ptr -= inv_n;
                    index -= inv_n;
                }
                return;
            }
            if (index + n >= capacity){
                ptr = ptr - index;
                index = index + n - capacity;
                ptr = ptr + index;
            } else{
                ptr += n;
                index += n;
            }
        }
        void operator+=(const iterator& other) {
            ptr += other.ptr;
            index += other.ptr;
        }
        iterator operator+ (const std::size_t& n) {
            iterator tmp(*this);
            tmp.index = index;
            tmp.capacity = capacity;
            tmp.begin_b = begin_b;
            if (n < 0){
                tmp -= -n;
            }
            if (tmp.index + n >= tmp.capacity){
                tmp.ptr = tmp.ptr - tmp.index;
                tmp.index = tmp.index + n - tmp.capacity;
                tmp.ptr = tmp.ptr + tmp.index;
            } else{
                tmp.ptr += n;
                tmp.index += n;
            }
            return tmp;
        }
        iterator operator+ (const iterator& other) {
            iterator tmp(*this);
            tmp.capacity = capacity;
            tmp.index = index;
            tmp += other;
            tmp.begin_buf = begin_b;
            return tmp;
        }

        void operator-= (const std::size_t& n)  {
            if (n < 0){
                size_t inv_n = -n;
                if (index + inv_n >= capacity){
                    ptr = ptr - index;
                    index = index + inv_n - capacity;
                    ptr = ptr + index;
                } else{
                    ptr += inv_n;
                    index += inv_n;
                }
                return;
            }
            if (index - n < 0){
                ptr = ptr - index;
                index = capacity - (n - index);
                ptr = ptr + index;
            } else{
                ptr -= n;
                index -= n;
            }
        }
        void operator-= (const iterator& other) {
            ptr -= other.ptr;
            index -= other.index;
        }
        iterator operator- (const std::size_t& n)  {
            iterator tmp(*this);
            tmp.index = index;
            tmp.capacity = capacity;
            tmp.begin_b = begin_b;
            if (n < 0){
                size_t inv_n = n * (-1);
                if (tmp.index - n < 0){
                    tmp.ptr = tmp.ptr - tmp.index;
                    tmp.index = tmp.index - n + tmp.capacity;
                    tmp.ptr = tmp.ptr + tmp.index;
                } else{
                    ptr += n;
                    index += n;
                }
            }
            int abc = tmp.index - n;
            if (abc < 0){
                tmp.ptr = tmp.ptr - tmp.index;
                tmp.index = tmp.capacity - (n - tmp.index);
                tmp.ptr = tmp.ptr + tmp.index;
            } else{
                tmp.ptr -= n;
                tmp.index -= n;
            }
            return tmp;
        }
        std::size_t operator- (const iterator& other) {
            size_t index_ptr, index_ptr_other;
            if (index >= begin_b->get_index())
                index_ptr = index - begin_b->get_index();
            else
                index_ptr = capacity - begin_b->get_index() + index;
            if (other.index >= other.begin_b->get_index())
                index_ptr_other = other.index - other.begin_b->get_index();
            else
                index_ptr_other = other.capacity - other.begin_b->get_index() + other.index;
            return index_ptr - index_ptr_other;
        }

        bool operator< (const iterator& other) {
            return (ptr - other.ptr) < 0;
        }
        bool operator<= (const iterator& other) {
            return (ptr - other.ptr) <= 0;
        }
        bool operator> (const iterator& other) {
            return (ptr - other.ptr) > 0;
        }
        bool operator>= (const iterator& other) {
            return (ptr - other.ptr) >= 0;
        }
        bool operator== (const iterator& other) {
            return ptr == other.ptr;
        }
        bool operator!= (const iterator& other) {
            return ptr != other.ptr;
        }

        Type& operator[](const int& n) {
            return *(ptr + n);
        }
        Type& operator*() {
            return *ptr;
        }
        Type* operator->(){
            return  ptr;
        }
        size_t get_index(){
            return index;
        };
    };

private:
    Type* data;
    size_t capacity;
    iterator begin_buf;
    iterator end_buf;

public:
    iterator begin(){
        return begin_buf;
    }
    iterator end(){
        return end_buf;
    }
    Type& operator[](size_t index){
        return *(begin_buf + index);
    }
    void put_in_begin(Type value){
        begin_buf--;
        if (begin_buf == end_buf)
            begin_buf++;
        *begin_buf = value;
    }
    void delete_begin(){
        if (begin_buf == end_buf)
            return;
        begin_buf++;
    }
    void put_in_end(Type value){
        *end_buf = value;
        ++end_buf;
        if (end_buf == begin_buf)
            begin_buf++;
    }
    void delete_end(){
        if (end_buf == begin_buf)
            return;
        end_buf--;
    }
    void put_in(iterator it, Type value){
        if (begin_buf - end_buf != -capacity)
            end_buf++;
        else{
            end_buf++;
            begin_buf++;
        }
        iterator cur_it = end_buf - 1;
        while (cur_it.get_index() != it.get_index()){
            *cur_it = *(cur_it - 1);
            cur_it--;
        }
        *it = value;
    }
    void delete_in(iterator it){
        while (it != end_buf){
            *it = *(it + 1);
            it++;
        }
        end_buf--;
    }

    void change_capacity(size_t value){
        Type* new_data = new Type[value + 1];
        iterator new_beg_buf = iterator(new_data, value + 1, 0);
        new_beg_buf.begin_b = &new_beg_buf;
        size_t new_index;
        if (end_buf < begin_buf){
            new_index = (capacity + 1) - begin_buf.get_index() + end_buf.get_index();
        } else{
            new_index = end_buf.get_index() - begin_buf.get_index();
        }
        if (new_index > capacity){
            std::cerr << "Buffer is bigger than new capacity";
            exit(1);
        }
        iterator new_end_buf = iterator(new_data + new_index, value + 1, new_index);
        new_end_buf.begin_b = &new_end_buf;
        size_t index = 0;
        while(begin_buf != end_buf) {
            new_data[index] = *begin_buf;
            index++;
            begin_buf++;
        }
        data = new_data;
        begin_buf = new_beg_buf;
        end_buf = new_end_buf;
        this->capacity = value;
    }

    Circular_buffer(){
        capacity = 0;
        begin_buf = iterator(data, capacity, 0);
        begin_buf.begin_b = &begin_buf;
        end_buf = iterator(data, capacity, 0);
        end_buf.begin_b = &begin_buf;
    };
    Circular_buffer(size_t capacity){
        this->capacity = capacity;
        data = new Type[capacity + 1];
        begin_buf = iterator(data, capacity + 1, 0);
        begin_buf.begin_b = &begin_buf;
        end_buf = iterator(data, capacity + 1, 0);
        end_buf.begin_b = &begin_buf;
    };
};

#endif //LAB7_CIRCULAR_BUFFER_H
