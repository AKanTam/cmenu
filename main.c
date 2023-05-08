#include "cMenu.h"
#include "stdio.h"

int main(void)
{
    // ������Ŀ¼
    cMenu *root = cMenu_CreatMenu();

    // ������Ŀ¼�ڵ�
    cMenu *m_1 = cMenu_AddRootChild(root, "WLAN");
    cMenu *m_2 = cMenu_AddRootChild(root, "����");
    cMenu *m_3 = cMenu_AddRootChild(root, "�ƶ�����");
    cMenu *m_4 = cMenu_AddRootChild(root, "��������");
    cMenu *m_5 = cMenu_AddRootChild(root, "����");
    cMenu *m_6 = cMenu_AddRootChild(root, "��Ƭ");

    // �����ӽڵ�
    cMenu *m_1_1 = cMenu_AddChild(m_1, "WLAN");
    cMenu *m_1_2 = cMenu_AddChild(m_1, "�������");
    cMenu *m_1_3 = cMenu_AddChild(m_1, "����WLAN����");
    cMenu *m_1_3_1 = cMenu_AddChild(m_1_3, "WLAN+");

    cMenu *m_2_1 = cMenu_AddChild(m_2, "����");
    cMenu *m_2_2 = cMenu_AddChild(m_2, "�豸����");
    cMenu *m_2_3 = cMenu_AddChild(m_2, "���ܵ��ļ�");

    cMenu *m_3_1 = cMenu_AddChild(m_3, "����ģʽ");
    cMenu *m_3_2 = cMenu_AddChild(m_3, "�ƶ�����");
    cMenu *m_3_3 = cMenu_AddChild(m_3, "SIM������");
    cMenu *m_3_4 = cMenu_AddChild(m_3, "�����ȵ�");

    cMenu *m_4_1 = cMenu_AddChild(m_4, "��Ϊ����");
    cMenu *m_4_2 = cMenu_AddChild(m_4, "NFC");
    cMenu *m_4_3 = cMenu_AddChild(m_4, "�ֻ�Ͷ��");
    cMenu *m_4_4 = cMenu_AddChild(m_4, "VPN");

    // ���ò˵��¼���һ�����ӽڵ�Ĳ˵��������¼���Ӧ
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

    // �����˵�ָ��
    cMenuIter *iter = cMenu_CreatMenuIter(m_1);

    printf("input number 1 to next ,");
    printf("input number 2 to Prev ,");
    printf("input number 3 to Enter ,");
    printf("input number 4 to Quit \n");

    int order;
    printf("point now is %s \n", cMenu_GetIterString(iter));
    
    while (1)
    {
        // // ��ӡ��ǰָ���ǰn���˵������֣�ˢ����ʾʱʹ�ã�
        // printf("point 1 is %s \n", cMenu_GetIterStringNext(iter, 0));
        // printf("point 2 is %s \n", cMenu_GetIterStringNext(iter, 1));
        // printf("point 3 is %s \n", cMenu_GetIterStringNext(iter, 2));
        // printf("point 4 is %s \n", cMenu_GetIterStringNext(iter, 3));
        // printf("point 5 is %s \n", cMenu_GetIterStringNext(iter, 4));

        // ��ȡָ��ǰ��˵�������
        // printf("thie point has %d next point and %d prev point...\n", cMenu_GetNumNextNode(iter->node), cMenu_GetNumPrevNode(iter->node));

        // ���һ��ֻ��չʾ3��
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

        scanf("%d", &order); // ��ȡָ��
        switch (order)       // ����ָ��
        {
        case 1:
            cMenu_IterNext(iter); // ��һ��
            break;
        case 2:
            cMenu_IterPrev(iter); // ��һ��
            break;
        case 3:
            cMenu_IterEnter(iter); // ������һ���˵�
            break;
        case 4:
            cMenu_IterQuit(iter); // �ص���һ���˵�
            break;
        default:
            break;
        }
        printf("point now is %s \n", cMenu_GetIterString(iter));

        switch (iter->node->type) // ����ָ��仯����¼���Ӧ�����Զ����¼�ö��
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