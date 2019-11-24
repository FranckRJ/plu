#pragma once

#include <stdexcept>
#include <utility>

namespace plu
{
    template <class T>
    class IndexedIterator;

    template <class T>
    bool operator==(const IndexedIterator<T>& lhs, const IndexedIterator<T>& rhs);

    template <class T>
    bool operator!=(const IndexedIterator<T>& lhs, const IndexedIterator<T>& rhs);

    template <class T>
    class IndexedIterator
        : public std::iterator<std::output_iterator_tag, std::pair<decltype(*std::declval<T>()), const int>>
    {
    public:
        using ValueRef = decltype(*std::declval<T>());

        IndexedIterator(T ite, int idx);

        std::pair<ValueRef, const int> operator*() const;

        IndexedIterator& operator++();

        IndexedIterator operator++(int);

    private:
        T m_ite;
        int m_idx;

    public:
        friend bool operator==<T>(const IndexedIterator<T>& lhs, const IndexedIterator<T>& rhs);

        friend bool operator!=<T>(const IndexedIterator<T>& lhs, const IndexedIterator<T>& rhs);
    };
} // namespace plu

#include "private/indexediterator.hxx"