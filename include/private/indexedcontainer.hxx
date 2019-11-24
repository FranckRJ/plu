namespace plu
{
    template <class T>
    IndexedContainer<T>::IndexedContainer(T beginIte, T endIte)
        : m_beginIte{std::move(beginIte)}, m_endIte{std::move(endIte)}
    {
    }

    template <class T>
    typename IndexedContainer<T>::Iterator IndexedContainer<T>::begin() const
    {
        return Iterator{m_beginIte, 0};
    }

    template <class T>
    typename IndexedContainer<T>::Iterator IndexedContainer<T>::end() const
    {
        return Iterator{m_endIte, -1};
    }

    template <class T>
    IndexedContainer<T> makeIndexedContainer(T&& beginIte, T&& endIte)
    {
        return IndexedContainer<T>{std::forward<T>(beginIte), std::forward<T>(endIte)};
    }

    template <class T>
    IndexedContainer<typename T::const_iterator> makeIndexedContainer(const T& container)
    {
        using std::begin;
        using std::end;

        return IndexedContainer<typename T::const_iterator>{begin(container), end(container)};
    }
} // namespace plu