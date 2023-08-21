// Задача 2. Проверка функций добавления и получения элементов из двусвязного списка
//

#include <iostream>
#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_session.hpp>
#include "catch2/matchers/catch_matchers.hpp"

struct ListNode
{
public:
    ListNode(int value, ListNode* prev = nullptr, ListNode* next = nullptr)
        : value(value), prev(prev), next(next)
    {
        if (prev != nullptr) prev->next = this;
        if (next != nullptr) next->prev = this;
    }

public:
    int value;
    ListNode* prev;
    ListNode* next;
};


class List
{
public:
    List()
        : m_head(new ListNode(static_cast<int>(0))), m_size(0),
        m_tail(new ListNode(0, m_head))
    {
    }

    virtual ~List()
    {
        Clear();
        delete m_head;
        delete m_tail;
    }

    bool Empty() { return m_size == 0; }

    unsigned long Size() { return m_size; }

    void PushFront(int value)
    {
        new ListNode(value, m_head, m_head->next);
        ++m_size;
    }

    void PushBack(int value)
    {
        new ListNode(value, m_tail->prev, m_tail);
        ++m_size;
    }

    int PopFront()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_head->next->next);
        int ret = node->value;
        delete node;
        return ret;
    }

    int PopBack()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_tail);
        int ret = node->value;
        delete node;
        return ret;
    }

    void Clear()
    {
        auto current = m_head->next;
        while (current != m_tail)
        {
            current = current->next;
            delete extractPrev(current);
        }
    }

private:
    ListNode* extractPrev(ListNode* node)
    {
        auto target = node->prev;
        target->prev->next = target->next;
        target->next->prev = target->prev;
        --m_size;
        return target;
    }

private:
    ListNode* m_head;
    ListNode* m_tail;
    unsigned long m_size;
};

TEST_CASE("Check PopFront/PopBack empty", "[test_2]") {
    List list;
    INFO("Check PopFront/PopBack empty");

    CHECK_THROWS_WITH(list.PopFront(), "list is empty");
    CHECK_THROWS_WITH(list.PopBack(), "list is empty");

}

TEST_CASE("Check PushFront / Pushback", "[test_2]") {
    List list;
    list.PushFront(1);
    list.PushBack(2);
    list.PushBack(3);
    int size = 3;
    INFO("Check PushFront / Pushback");
    CHECK(list.Empty() == 0);
    CHECK(list.Size() == size);
    CHECK(list.PopFront() == 1);
    CHECK(list.PopBack() == 3);
    CHECK(list.PopBack() == 2);
}


int main()
{
    return Catch::Session().run();
}