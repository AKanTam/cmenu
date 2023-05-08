#include "cMenu.h"
#include "stdio.h"

int main(void)
{
    // 创建根目录
    cMenu *root = cMenu_CreatMenu();

    // 创建根目录节点
    cMenu *m_1 = cMenu_AddRootChild(root, "WLAN");
    cMenu *m_2 = cMenu_AddRootChild(root, "蓝牙");
    cMenu *m_3 = cMenu_AddRootChild(root, "移动网络");
    cMenu *m_4 = cMenu_AddRootChild(root, "更多连接");
    cMenu *m_5 = cMenu_AddRootChild(root, "设置");
    cMenu *m_6 = cMenu_AddRootChild(root, "照片");

    // 创建子节点
    cMenu *m_1_1 = cMenu_AddChild(m_1, "WLAN");
    cMenu *m_1_2 = cMenu_AddChild(m_1, "网络加速");
    cMenu *m_1_3 = cMenu_AddChild(m_1, "更多WLAN设置");
    cMenu *m_1_3_1 = cMenu_AddChild(m_1_3, "WLAN+");

    cMenu *m_2_1 = cMenu_AddChild(m_2, "蓝牙");
    cMenu *m_2_2 = cMenu_AddChild(m_2, "设备名称");
    cMenu *m_2_3 = cMenu_AddChild(m_2, "接受的文件");

    cMenu *m_3_1 = cMenu_AddChild(m_3, "飞行模式");
    cMenu *m_3_2 = cMenu_AddChild(m_3, "移动数据");
    cMenu *m_3_3 = cMenu_AddChild(m_3, "SIM卡管理");
    cMenu *m_3_4 = cMenu_AddChild(m_3, "个人热点");

    cMenu *m_4_1 = cMenu_AddChild(m_4, "华为分享");
    cMenu *m_4_2 = cMenu_AddChild(m_4, "NFC");
    cMenu *m_4_3 = cMenu_AddChild(m_4, "手机投屏");
    cMenu *m_4_4 = cMenu_AddChild(m_4, "VPN");

    // 设置菜单事件，一般有子节点的菜单不设置事件响应
    cMenu_SetEven(m_1_1, WLAN);
    cMenu_SetEven(m_1_2, NETSPEED);
    cMenu_SetEven(m_1_3_1, WLANPLUS);
    cMenu_SetEven(m_2_1, BLOOTH);
    cMenu_SetEven(m_2_2, NAMEOFDEVICE);
    cMenu_SetEven(m_2_3, DOCOFREC);
    cMenu_SetEven(m_3_1, FLY);
    cMenu_SetEven(m_3_2, MOBILEDATA);
    cMenu_SetEven(m_3_3, SIM);
    cMenu_SetEven(m_3_4, HOTSPOT);
    cMenu_SetEven(m_4_1, SHARE);
    cMenu_SetEven(m_4_2, NFC);
    cMenu_SetEven(m_4_3, PHONESCREEN);
    cMenu_SetEven(m_4_4, VPN);
    cMenu_SetEven(m_5, SETTING);
    cMenu_SetEven(m_6, PICTURE);

    // 创建菜单指针
    cMenuIter *iter = cMenu_CreatMenuIter(m_1);

    printf("input number 1 to next ,");
    printf("input number 2 to Prev ,");
    printf("input number 3 to Enter ,");
    printf("input number 4 to Quit \n");

    int order;
    printf("point now is %s \n", cMenu_GetIterString(iter));
    
    while (1)
    {
        // // 打印当前指针的前n个菜单的名字（刷新显示时使用）
        // printf("point 1 is %s \n", cMenu_GetIterStringNext(iter, 0));
        // printf("point 2 is %s \n", cMenu_GetIterStringNext(iter, 1));
        // printf("point 3 is %s \n", cMenu_GetIterStringNext(iter, 2));
        // printf("point 4 is %s \n", cMenu_GetIterStringNext(iter, 3));
        // printf("point 5 is %s \n", cMenu_GetIterStringNext(iter, 4));

        // 获取指针前后菜单的数量
        // printf("thie point has %d next point and %d prev point...\n", cMenu_GetNumNextNode(iter->node), cMenu_GetNumPrevNode(iter->node));

        // 如果一共只能展示3行
        size_t num_maxShow = 3;
        size_t num_prev = 0;
        size_t num_cout = 0;

        if (num_maxShow > cMenu_GetNumPrevNode(iter->node))
        {
            num_prev = cMenu_GetNumPrevNode(iter->node);
            for (; num_prev > 0; --num_prev, ++num_cout)
            {
                printf("%s \n", cMenu_GetIterStringPrev(iter, num_prev));
            }
            for (size_t i = 0; i < (num_maxShow - num_cout); ++i)
            {
                printf("%s \n", cMenu_GetIterStringNext(iter, i));
            }
        }
        else
        {
            num_prev = num_maxShow;
            for (; num_prev > 0; --num_prev)
            {
                printf("%s \n", cMenu_GetIterStringPrev(iter, (num_prev - 1)));
            }
        }

        scanf("%d", &order); // 获取指令
        switch (order)       // 操作指针
        {
        case 1:
            cMenu_IterNext(iter); // 下一个
            break;
        case 2:
            cMenu_IterPrev(iter); // 上一个
            break;
        case 3:
            cMenu_IterEnter(iter); // 进入下一级菜单
            break;
        case 4:
            cMenu_IterQuit(iter); // 回到上一级菜单
            break;
        default:
            break;
        }
        printf("point now is %s \n", cMenu_GetIterString(iter));

        switch (iter->node->type) // 处理指针变化后的事件响应，需自定义事件枚举
        {
        case SETTING:
            printf("Start to setting parma...... \n");
            break;
        case PICTURE:
            printf("Now show the picture...... \n");
            break;
        default:
            break;
        }
    }

    return 0;
}