#pragma once
#include <ostream>
#include <initializer_list>
#include <iterator>

    template <typename T>
    class ring_buffer
    {
        size_t capacity_, size_, read_pointer_, write_pointer_;
        T* data_;

    public:
        const static size_t default_capacity = 16;

        class myiterator: iterator<random_access_iterator_tag, >
        {
            const ring_buffer* ring_buffer_;
            size_t index_;
        public:
            using value_type = T;
            myiterator(const ring_buffer& ring_buffer, const size_t index) : ring_buffer_(&ring_buffer), index_(index)
            {
                if (index_ > ring_buffer.size())
                    throw std::invalid_argument("myiterator index out of container");
            }
            myiterator(const myiterator& it) = default;
            myiterator& operator=(const myiterator& it)
            {
                if (this == &it)
                    return *this;
                ring_buffer_ = it.ring_buffer_;
                index_ = it.index_;
                return *this;
            }

            myiterator operator++()
            {
                if (*this == ring_buffer_->end())
                    throw std::out_of_range("can't increment end container myiterator");
                return { *ring_buffer_, ++index_ };
            }
            myiterator operator--()
            {
                if (*this == ring_buffer_->begin())
                    throw std::out_of_range("can't decrement container myiterator before begin");
                return { *ring_buffer_, --index_ };
            }
            myiterator operator++(int)
            {
                if (*this == ring_buffer_->end())
                    throw std::out_of_range("can't increment end container myiterator");
                return { *ring_buffer_, index_++ };
            }
            myiterator operator--(int)
            {
                if (*this == ring_buffer_->begin())
                    throw std::out_of_range("can't decrement container myiterator before begin");
                return { *ring_buffer_, index_-- };
            }

            friend myiterator operator+(const myiterator& it, int n)
            {
                return { *it.ring_buffer_, it.index_ + n };
            }
            friend myiterator operator+(int n, const myiterator& it)
            {
                return it + n;
            }
            friend myiterator operator-(const myiterator& it, const int n)
            {
                return it + (-n);
            }
            friend myiterator operator-(int n, const myiterator& it)
            {
                return it - n;
            }

            myiterator operator+=(const int n)
            {
                return { *this->ring_buffer_, this->index_ += n };
            }
            myiterator operator-=(const int n)
            {
                return *this += -n;
            }

            friend int operator-(const myiterator& it1, const myiterator& it2)
            {
                return it1.index_ - it2.index_;
            }

            T const& operator *() const
            {
                if (*this == ring_buffer_->end())
                return (*ring_buffer_)[index_];
            }
            T& operator *()
            {
                if (*this == ring_buffer_->end())
                    throw std::runtime_error("cannot dereference end myiterator");
                return (*ring_buffer_)[index_];
            }
            T const* operator->() const
            {
                return &(*ring_buffer_)[index_];
            }
            T* operator->()
            {
                return &(*ring_buffer_)[index_];
            }

            friend bool operator==(const myiterator& it1, const myiterator& it2)
            {
                return it1.index_ == it2.index_;
            }
            friend bool operator<(const myiterator& it1, const myiterator& it2)
            {
                return it1.index_ < it2.index_;
            }
            friend bool operator!=(const myiterator& it1, const myiterator& it2)
            {
                return !(it1 == it2);
            }
            friend bool operator>(const myiterator& it1, const myiterator& it2)
            {
                return !(it1 < it2) && it1 != it2;
            }
            friend bool operator<=(const myiterator& it1, const myiterator& it2)
            {
                return it1 < it2 || it1 == it2;
            }
            friend bool operator>=(const myiterator& it1, const myiterator& it2)
            {
                return it1 > it2 || it1 == it2;
            }
        };

        explicit ring_buffer(const size_t capacity = default_capacity) :
                capacity_(capacity),
                size_(0),
                read_pointer_(0),
                write_pointer_(0),
                data_(new T[capacity])
        {

        }
        ring_buffer(const std::initializer_list<T>& list) : ring_buffer(list.size())
        {
            for (auto& i : list)
                push_back(i);
        }
        ring_buffer& operator=(const ring_buffer& rb)
        {
            clear();
            resize(rb.capacity());
            for (const auto& i : rb)
                push_back(i);
            return *this;
        }
        ring_buffer(const ring_buffer& rb) : ring_buffer(rb.capacity())
        {
            for (auto& i : rb)
                push_back(i);
        }
        ~ring_buffer()
        {
            delete[] data_;
        }

        myiterator begin() const
        {
            return { *this, 0 };
        }
        myiterator end() const
        {
            return { *this, size_ };
        }
        size_t size() const
        {
            return size_;
        }
        size_t capacity() const
        {
            return capacity_;
        }
        T& operator[](const size_t index) {
            if (index >= size_)
                throw std::out_of_range("index out of range");
            return data_[(read_pointer_ + index) % capacity_];
        }
        T& operator[](const size_t index) const
        {
            if (index >= size_)
                throw std::out_of_range("index out of range");
            return data_[(read_pointer_ + index) % capacity_];
        }

        void resize(const size_t new_capacity)
        {
            const size_t tmp_arr_size = std::min(new_capacity, size_);
            T* tmp_arr = new T[tmp_arr_size];
            for (size_t i = 0; i < tmp_arr_size; ++i)
                tmp_arr[i] = pop_front();
            capacity_ = new_capacity;
            clear();
            for (size_t i = 0; i < tmp_arr_size; ++i)
                push_back(tmp_arr[i]);
            delete[] tmp_arr;
        }
        void clear()
        {
            read_pointer_ = 0;
            write_pointer_ = 0;
            size_ = 0;
            delete[] data_;
            data_ = new T[capacity_];
        }

        void push_back(const T element)
        {
            if (write_pointer_ == read_pointer_ && size_ != 0)
                resize(capacity_ * 2);

            data_[write_pointer_++] = element;
            write_pointer_ %= capacity_;
            size_++;
        }
        void push_front(const T element)
        {
            if (write_pointer_ == read_pointer_ && size_ != 0)
                resize(capacity_ * 2);

            if (read_pointer_ == 0)
                read_pointer_ = capacity_ - 1;
            else
                read_pointer_ -= 1;
            data_[read_pointer_] = element;
            size_++;
        }

        T pop_back()
        {
            if (write_pointer_ == 0)
                write_pointer_ = capacity_ - 1;
            else
                write_pointer_ -= 1;
            size_--;
            return data_[write_pointer_];
        }
        T pop_front()
        {
            const size_t ret_index = read_pointer_++;
            read_pointer_ %= capacity_;
            size_--;
            return data_[ret_index];
        }

        void insert(myiterator&& it, T element)
        {
            if (it > end())
                throw std::invalid_argument("insert after end");
            push_back(*(end() - 1));
            for (auto i = end() - 2; i > it; --i)
                *i = *(i - 1);
            *it = element;
        }
        void erase(myiterator&& it)
        {
            if (it >= end())
                throw std::invalid_argument("erase end myiterator");
            for (auto i = it; i < end() - 1; ++i)
                *i = *(i + 1);
            pop_back();
        }

    };
    template <typename T> std::ostream& operator<<(std::ostream& st, ring_buffer<T>& rb)
    {
        for (auto& i : rb)
            st << i << ' ';
        return st;
    }