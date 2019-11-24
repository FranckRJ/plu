namespace plu
{
    template <class T>
    IndexedIterator<T>::IndexedIterator(T ite, int idx) : m_ite{std::move(ite)}, m_idx{idx}
    {
    }

    template <class T>
    std::pair<typename IndexedIterator<T>::ValueRef, const int> IndexedIterator<T>::operator*() const
    {
        if (m_idx < 0)
        {
            throw std::runtime_error{"Cannot dereference an IndexedIterator with a negative index"};
        }

        return std::pair<ValueRef, const int>{*m_ite, m_idx};
    }

    template <class T>
    IndexedIterator<T>& IndexedIterator<T>::operator++()
    {
        ++m_ite;
        ++m_idx;
        return *this;
    }

    template <class T>
    IndexedIterator<T> IndexedIterator<T>::operator++(int)
    {
        IndexedIterator cpy{m_ite, m_idx};
        ++(*this);
        return cpy;
    }

    template <class T>
    bool operator==(const IndexedIterator<T>& lhs, const IndexedIterator<T>& rhs)
    {
        return (lhs.m_ite == rhs.m_ite);
    }

    template <class T>
    bool operator!=(const IndexedIterator<T>& lhs, const IndexedIterator<T>& rhs)
    {
        return !(lhs == rhs);
    }
} // namespace plu