/**
 * @file cMenu.h
 * @author Tam (821239820@qq.com)
 * @brief
 * @version 0.1
 * @date 2023-01-30
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "cMenu.h"

cMenu *cMenu_CreatMenu(void)
{
    cMenu *node = malloc(sizeof(cMenu));
    if (node)
    {
        memset(node, '\0', sizeof(cMenu));
    }

    return node;
}

cMenuIter *cMenu_CreatMenuIter(cMenu *_node)
{
    cMenuIter *iter = malloc(sizeof(cMenuIter));
    if (iter)
    {
        iter->node = _node;
    }

    return iter;
}

bool *cMenu_SetNodeString(cMenu *_node, const char *_string)
{
    if (_node != NULL)
    {
        _node->string =(char *) _string;
        return true;
    }

    return false;
}

char *cMenu_GetNodeString(cMenu *_node)
{
    if (_node != NULL)
    {
        return _node->string;
    }

    return NULL;
}

size_t cMenu_GetNumNextNode(cMenu *_node)
{
    if (_node != NULL)
    {
        size_t num = 0;
        while (_node->next != NULL)
        {
            _node = _node->next;
            ++num;
        }
        return num;
    }
    return 0;
}

size_t cMenu_GetNumPrevNode(cMenu *_node)
{
    if (_node != NULL)
    {
        size_t num = 0;
        while (_node->prev != NULL)
        {
            _node = _node->prev;
            ++num;
        }
        return num;
    }
    return 0;
}

bool cMenu_SetEven(cMenu *_node, enum cMenu_Event _event)
{
    if (_node != NULL)
    {
        _node->type = _event;
        return true;
    }

    return false;
}

cMenu *cMenu_AddItem(cMenu *_node, const char *_string)
{
    cMenu *new_node = cMenu_CreatMenu();
    if (new_node != NULL)
    {
        if (cMenu_SetNodeString(new_node, _string))
        {
            cMenu *node = _node;
            while (node->next != NULL)
            {
                node = node->next;
            }

            new_node->prev = node;
            node->next = new_node;
            return new_node;
        }
        else
        {
            return NULL;
        }
    }
    else
    {
        return NULL;
    }
}

cMenu *cMenu_AddChild(cMenu *_cmenu, const char *_string)
{
    cMenu *new_node = cMenu_CreatMenu();
    if (new_node != NULL)
    {
        if (cMenu_SetNodeString(new_node, _string))
        {
            new_node->father = _cmenu;
            if (_cmenu->child == NULL)
            {
                _cmenu->child = new_node;
            }
            else
            {
                cMenu *child = _cmenu->child;
                cMenu *node = child;
                while (node->next != NULL)
                {
                    node = node->next;
                }

                new_node->prev = node;
                node->next = new_node;
            }
            return new_node;
        }
        else
        {
            return NULL;
        }
    }
    else
    {
        return NULL;
    }
}

cMenu *cMenu_AddRootChild(cMenu *_cmenu, const char *_string)
{
    cMenu *new_node = cMenu_CreatMenu();
    if (new_node != NULL)
    {
        if (cMenu_SetNodeString(new_node, _string))
        {
            if (_cmenu->child == NULL)
            {
                _cmenu->child = new_node;
            }
            else
            {
                cMenu *child = _cmenu->child;
                cMenu *node = child;
                while (node->next != NULL)
                {
                    node = node->next;
                }

                new_node->prev = node;
                node->next = new_node;
            }
            return new_node;
        }
        else
        {
            return NULL;
        }
    }
    else
    {
        return NULL;
    }
}

bool *cMenu_IterNext(cMenuIter *_iter)
{
    if (_iter != NULL)
    {
        if (_iter->node != NULL)
        {
            if (_iter->node->next != NULL)
            {
                _iter->node = _iter->node->next;
                return true;
            }
        }
    }
    return false;
}

bool *cMenu_IterPrev(cMenuIter *_iter)
{
    if (_iter != NULL)
    {
        if (_iter->node != NULL)
        {
            if (_iter->node->prev != NULL)
            {
                _iter->node = _iter->node->prev;
                return true;
            }
        }
    }
    return false;
}

bool *cMenu_IterEnter(cMenuIter *_iter)
{
    if (_iter != NULL)
    {
        _iter->type = _iter->node->type;
        if (_iter->node != NULL)
        {
            if (_iter->node->child != NULL)
            {
                _iter->node = _iter->node->child;
                return true;
            }
        }
    }
    return false;
}

bool *cMenu_IterQuit(cMenuIter *_iter)
{
    if (_iter != NULL)
    {
        _iter->type = DEFAULT;
        if (_iter->node != NULL)
        {
            if (_iter->node->father != NULL)
            {
                _iter->node = _iter->node->father;
                return true;
            }
        }
    }
    return false;
}

char *cMenu_GetIterString(cMenuIter *_iter)
{
    if (_iter != NULL)
    {
        if (_iter->node != NULL)
        {
            return _iter->node->string;
        }
    }
    return NULL;
}

char *cMenu_GetIterStringNext(cMenuIter *_iter, size_t _num)
{
    cMenu *node = _iter->node;
    for (size_t i = 0; i < _num; ++i)
    {
        if (node->next != NULL)
        {
            node = node->next;
        }
    }
    return node->string;
}

char *cMenu_GetIterStringPrev(cMenuIter *_iter, size_t _num)
{
    cMenu *node = _iter->node;
    for (size_t i = 0; i < _num; ++i)
    {
        if (node->prev != NULL)
        {
            node = node->prev;
        }
    }
    return node->string;
}
