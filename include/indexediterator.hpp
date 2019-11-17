#pragma once

#include <utility>
#include <stdexcept>

namespace plu
{
    template<class T>
    class IndexedIterator : public std::iterator<std::output_iterator_tag, std::pair<decltype(*std::declval<T>()), const int>>
    {
    public:
        using ValueRef = decltype(*std::declval<T>());

        IndexedIterator(T ite, int idx) : m_ite{ std::move(ite) }, m_idx{ idx } {}

        std::pair<ValueRef, const int> operator*() const
        {
            if (m_idx < 0)
            {
                throw std::runtime_error{ "Cannot dereference an IndexedIterator with a negative index" };
            }

            return std::pair<ValueRef, const int>{ *m_ite, m_idx };
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
}