#ifndef TRAITS_STUB_H
#define TRAITS_STUB_H

// gmock
#include <gmock/gmock.h>

// internal
#include <NotificationObject>

// std
#include <variant>
#include <optional>
#include <string>
#include <map>

// forward declaration
class node_mock;

class traits_stub
{
public:
    using node_t = node_mock;
    using node_ptr = node_t*;
    using key_t = std::string;
    using value_t = std::variant<std::monostate, std::int64_t, std::uint64_t, std::string, double, float>;
};

class node_mock
{
public:
    MOCK_CONST_METHOD0(has_children, bool());
    MOCK_CONST_METHOD1(exist, bool(const traits_stub::key_t&));
    MOCK_CONST_METHOD1(child, traits_stub::node_ptr(const traits_stub::key_t&));
    MOCK_METHOD1(add_child, traits_stub::node_ptr(const traits_stub::key_t&));
    MOCK_CONST_METHOD0(children, std::map<traits_stub::key_t, traits_stub::node_ptr>());
    MOCK_CONST_METHOD0(empty, bool());
    MOCK_CONST_METHOD0(has_value, bool());
    MOCK_CONST_METHOD0(key, traits_stub::key_t());
    // TODO:
    // MOCK_CONST_METHOD0(value, std::optional<traits_stub::value_t>());
    MOCK_METHOD0(clear, void());
    MOCK_METHOD1(erase, void(traits_stub::key_t));
    // TODO:
    // MOCK_METHOD1(set_value, bool(traits_stub::value_t));
    MOCK_METHOD0(child_added, notification_object<traits_stub::key_t>());
    MOCK_METHOD0(child_removed, notification_object<traits_stub::key_t>());
    MOCK_METHOD0(value_changed, notification_object<std::optional<traits_stub::value_t>>());
};

#endif // TRAITS_STUB_H