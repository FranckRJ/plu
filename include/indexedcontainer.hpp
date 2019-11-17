#pragma once

#include <utility>

#include "indexediterator.hpp"

namespace plu
{
    template <class T>
    class IndexedContainer
    {
    public:
        using Iterator = IndexedIterator<T>;

        IndexedContainer(T beginIte, T endIte) : m_beginIte{std::move(beginIte)}, m_endIte{std::move(endIte)}
        {
        }

        Iterator begin() const
        {
            return Iterator{m_beginIte, 0};
        }

        Iterator end() const
        {
            return Iterator{m_endIte, -1};
        }

    private:
        T m_beginIte;
        T m_endIte;
    };

    template <class T>
    IndexedContainer<T> makeIndexedContainer(T&& beginIte, T&& endIte)
    {
        return IndexedContainer<T>{std::forward<T>(beginIte), std::forward<T>(endIte)};
    }

    template <class T>
    IndexedContainer<typename T::iterator> makeIndexedContainer(T& container)
    {
        using std::begin;
        using std::end;

        return IndexedContainer<typename T::iterator>{begin(container), end(container)};
    }
} // namespace plu