#include "Header1.h"
#include <iostream>
#include <stdio.h>
using namespace std;

Tree::Tree() : m_root(nullptr), m_size(0U) {
}

Tree::~Tree()
{
    while (m_root != nullptr)
    {
        Remove(m_root);
    }
}

Node* Tree::GetRoot() const {
    return m_root;
}

void Tree::Insert(Node* newNode)
{
    newNode->m_left = nullptr;
    newNode->m_right = nullptr;

    Node* node = m_root;
    Node* temp = nullptr;

    while (node != nullptr)
    {
        temp = node;

        if (strcmp(newNode->m_english, node->m_english) < 0)
        {
            node = node->m_left;

        }
        else
        {
            node = node->m_right;
        }
    }

    newNode->m_parent = temp;

    if (temp == nullptr)
    {
        m_root = newNode;
    }
    else if (strcmp(newNode->m_english, temp->m_english) < 0)
    {
        temp->m_left = newNode;
    }
    else
    {
        temp->m_right = newNode;
    }

    ++m_size;
}

Node* Tree::Max(Node* node) const
{
    if (node != nullptr)
    {
        while (node->m_right != nullptr)
        {
            node = node->m_right;
        }
    }
    return node;
}

Node* Tree::Min(Node* node) const
{
    if (node != nullptr)
    {
        while (node->m_left != nullptr)
        {
            node = node->m_left;
        }
    }

    return node;
}

Node* Tree::Next(const Node* node) const
{
    Node* next = nullptr;

    if (node != nullptr)
    {
        if (node->m_right != nullptr)
        {
            next = Min(node->m_right);
        }
        else
        {
            next = node->m_parent;
            while (next != nullptr && node == next->m_right)
            {
                node = next;
                next = next->m_parent;
            }
        }
    }

    return next;
}

Node* Tree::Previous(const Node* node) const
{
    Node* previous = nullptr;

    if (node != nullptr)
    {
        if (node->m_left != nullptr)
        {
            previous = Max(node->m_left);
        }
        else
        {
            previous = node->m_parent;

            while (previous != nullptr && node == previous->m_left)
            {
                node = previous;
                previous = previous->m_parent;
            }
        }
    }

    return previous;
}

void Tree::Print(const Node* node) const
{
    if (node != nullptr)
    {
        Print(node->m_left);

        cout << node->m_english << '\t' << node->m_russian << endl;

        Print(node->m_right);
    }
}

void Tree::Remove(Node* removeNode)
{
    if (removeNode != nullptr)
    {
        Node* node = nullptr;
        Node* temp = nullptr;

        if (removeNode->m_left == nullptr || removeNode->m_right == nullptr)
        {
            temp = removeNode;
        }
        else
        {
            temp = Next(removeNode);
        }

        if (temp->m_left != nullptr)
        {
            node = temp->m_left;
        }
        else
        {
            node = temp->m_right;
        }

        if (node != nullptr)
        {
            node->m_parent = temp->m_parent;
        }

        if (temp->m_parent == nullptr)
        {
            m_root = node;
        }
        else if (temp == temp->m_parent->m_left)
        {
            temp->m_parent->m_left = node;
        }
        else
        {
            temp->m_parent->m_right = node;
        }

        if (temp != removeNode)
        {
            strcpy_s(removeNode->m_english, 15U, temp->m_english);
            strcpy_s(removeNode->m_russian, 15U, temp->m_russian);
        }

        delete temp;

        --m_size;
    }
}

Node* Tree::Search(Node* node, const char* key) const
{
    while (node != nullptr && strcmp(key, node->m_english) != 0)
    {
        if (strcmp(key, node->m_english) < 0)
        {
            node = node->m_left;
        }
        else
        {
            node = node->m_right;
        }
    }

    return node;
}

Node* Tree::Edit(Node* node) {
    Node* temp = m_root;

    if (strcmp(node->m_english, temp->m_english) < 0) {
        temp = temp->m_left;
    }
    else if (strcmp(node->m_english, temp->m_english) > 0) {
        temp = temp->m_right;
    }

    if (node != nullptr) {
        strcpy_s(temp->m_english, 15U, node->m_english);
        strcpy_s(temp->m_russian, 15U, node->m_russian);
    }
    return node;
}