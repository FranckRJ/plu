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

        IndexedContainer(T beginIte, T endIte);

        Iterator begin() const;

        Iterator end() const;

    private:
        T m_beginIte;
        T m_endIte;
    };

    template <class T>
    IndexedContainer<T> makeIndexedContainer(T&& beginIte, T&& endIte);

    template <class T>
    IndexedContainer<typename T::const_iterator> makeIndexedContainer(const T& container);
} // namespace plu

#include "private/indexedcontainer.hxx"