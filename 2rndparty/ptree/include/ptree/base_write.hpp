#ifndef BASE_WRITE_HPP
#define BASE_WRITE_HPP

#include <type_traits>

namespace ptree
{
    template <typename Traits>
    base_write<Traits>::base_write(typename Traits::node_ptr node) : node_(node) { }

    template <typename Traits>
    void base_write<Traits>::clear() { node_->clear(); }

    template <typename Traits>
    void base_write<Traits>::erase(const typename Traits::key_t& key) { node_->erase(key); }

    template <typename Traits>
    void base_write<Traits>::set_value(const typename Traits::value_t& value)
    {
        node_->set_value(value);
    }

    template <typename Traits>
    template <typename Value>
    base_write<Traits>& base_write<Traits>::operator=(const Value& value)
    {
        if (!node_->has_value() && node_->has_children())
        {
            node_->clear();
        }

        // operator=(const base_write<Traits>& )
        if constexpr(std::is_base_of_v<base_write<Traits>, Value>)
        {
            return operator =(static_cast<base_write<Traits>&>(value));
        }
        // operator=(const typename Traits::value_t&)
        else if constexpr(std::is_constructible_v<typename Traits::value_t, Value>)
        {
            this->set_value(value);
        }
        else
        {
            static_assert(!std::is_same_v<Value, Value>, "assignment works only for Value");
        }
        return *this;
    }
}

#endif // BASE_WRITE_HPP
