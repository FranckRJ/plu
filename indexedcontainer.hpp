#pragma once

#include <utility>
#include <stdexcept>

namespace plu
{
    template<class T>
    class IndexedIterator : public std::iterator<std::output_iterator_tag, std::pair<decltype(*std::declval<T>()), int>>
    {
    public:
        using ValueRef = decltype(*std::declval<T>());

        IndexedIterator(T ite, int idx) : m_ite{ std::move(ite) }, m_idx{ idx } {}

        std::pair<ValueRef, int> operator*() const
        {
            if (m_idx < 0)
            {
                throw std::runtime_error{ "Cannot dereference a IndexedIterator with a negative index" };
            }

            return std::pair<ValueRef, int>{ *m_ite, m_idx };
        }

        IndexedIterator& operator++()
        {
            ++m_ite;
            ++m_idx;
            return *this;
        }

        IndexedIterator operator++(int)
        {
            IndexedIterator cpy{ m_ite, m_idx };
            ++(*this);
            return cpy;
        }

    private:
        T m_ite;
        int m_idx;

    public:
        friend bool operator==(const IndexedIterator& lhs, const IndexedIterator& rhs)
        {
            return (lhs.m_ite == rhs.m_ite);
        }

        friend bool operator!=(const IndexedIterator<T>& lhs, const IndexedIterator<T>& rhs)
        {
            return !(lhs == rhs);
        }
    };

    template<class T>
    class IndexedContainer
    {
    public:
        using Iterator = IndexedIterator<T>;

        IndexedContainer(T beginIte, T endIte) : m_beginIte{ std::move(beginIte) }, m_endIte{ std::move(endIte) } {}

        Iterator begin() const
        {
            return Iterator{ m_beginIte, 0 };
        }

        Iterator end() const
        {
            return Iterator{ m_endIte, -1 };
        }

    private:
        T m_beginIte;
        T m_endIte;
    };

    template<class T>
    IndexedContainer<T> makeIndexedContainer(T&& beginIte, T&& endIte)
    {
        return IndexedContainer<T>{ std::forward<T>(beginIte), std::forward<T>(endIte) };
    }

    template<class T>
    IndexedContainer<typename T::iterator> makeIndexedContainer(T& container)
    {
        using std::begin;
        using std::end;

        return IndexedContainer<typename T::iterator>{ begin(container), end(container) };
    }
}