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
#pragma once

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

enum cMenu_Event
{
    DEFAULT = 1,
    SETTING,
    PICTURE,
    WLAN,
    NETSPEED,
    WLANPLUS,
    BLOOTH,
    NAMEOFDEVICE,
    DOCOFREC,
    FLY,
    MOBILEDATA,
    SIM,
    HOTSPOT,
    SHARE,
    NFC,
    PHONESCREEN,
    VPN
};

/* The cMenu structure: */
typedef struct cMenu
{
    struct cMenu *next;
    struct cMenu *prev;

    struct cMenu *father;
    struct cMenu *child;

    enum cMenu_Event type;

    char *string;
} cMenu;

typedef struct cMenuIter
{
    struct cMenu *node;
} cMenuIter;

cMenu *cMenu_CreatMenu(void);
cMenuIter *cMenu_CreatMenuIter(cMenu *_node);

bool *cMenu_SetNodeString(cMenu *_node, const char *_string);
char *cMenu_GetNodeString(cMenu *_node);
size_t cMenu_GetNumNextNode(cMenu *_node);
size_t cMenu_GetNumPrevNode(cMenu *_node);
bool cMenu_SetEven(cMenu *_node, enum cMenu_Event _event);

cMenu *cMenu_AddItem(cMenu *_node, const char *_string);
cMenu *cMenu_AddChild(cMenu *_cmenu, const char *_string);
cMenu *cMenu_AddRootChild(cMenu *_cmenu, const char *_string);

bool *cMenu_IterNext(cMenuIter *_iter);
bool *cMenu_IterPrev(cMenuIter *_iter);
bool *cMenu_IterEnter(cMenuIter *_iter);
bool *cMenu_IterQuit(cMenuIter *_iter);

char *cMenu_GetIterString(cMenuIter *_iter);
char *cMenu_GetIterStringNext(cMenuIter *_iter, size_t _num);
char *cMenu_GetIterStringPrev(cMenuIter *_iter, size_t _num);