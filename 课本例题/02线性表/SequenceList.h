//
// Created by roguelxx on 19-3-15.
//

#ifndef SEQUENCELIST_H
#define SEQUENCELIST_H

// 宏定义
#include "../01绪论/Status.h"

#define LIST_INIT_SIZE  100 // 顺序表初始分配空间
#define LIST_INCEMENT   10  // 顺序表分配增量

// 顺序表类型定义
#ifndef LELEMTYPE_SQ
#define LELEMTYPE_SQ
typedef int ElemType_Sq;
#endif

typedef struct SqList
{
    ElemType_Sq *elem;     // 存储空间基址（指向第一个结点的指针）
    int length;             // 当前顺序表长度
    int listsize;               // 当前分配的存储容量
}SqList;

/* 顺序表函数列表 *//*
Status InitList_Sq(SqList L);
*//*━━━━━━━━━━━━━━━┓
┃(01)算法2.3：初始化空顺序表L。┃
┗━━━━━━━━━━━━━━━*//*

void ClearList_Sq(SqList L);
*//*━━━━━━━━━┓
┃(02)清空顺序表L。 ┃
┗━━━━━━━━━*//*

void DestroyList_Sq(SqList L);
*//*━━━━━━━━━┓
┃(03)销毁顺序表L。 ┃
┗━━━━━━━━━*//*

Status ListEmpty_Sq(SqList L);
*//*━━━━━━━━━━━━━┓
┃(04)判断顺序表L是否为空。 ┃
┗━━━━━━━━━━━━━*//*

int ListLength_Sq(SqList L);
*//*━━━━━━━━━━━━━━┓
┃(05)返回顺序表L中元素个数。 ┃
┗━━━━━━━━━━━━━━*//*

Status GetElem_Sq(SqList L, int i, ElemType_Sq *e);
*//*━━━━━━━━━━━━━━━━┓
┃(06)用e接收顺序表L中第i个元素。 ┃
┗━━━━━━━━━━━━━━━━*//*

int LocateElem_Sq(SqList L, ElemType_Sq e, Status(Compare)(ElemType_Sq, ElemType_Sq));
*//*━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(07)算法2.6：返回顺序表L中首个与e满足Compare关系的元素位序。┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━*//*

Status PriorElem_Sq(SqList L, ElemType_Sq cur_e, ElemType_Sq *pre_e);
*//*━━━━━━━━━━━━━━━━━┓
┃(08)用pre_e接收cur_e的前驱。      ┃
┗━━━━━━━━━━━━━━━━━*//*

Status NextElem_Sq(SqList L, ElemType_Sq cur_e, ElemType_Sq *next_e);
*//*━━━━━━━━━━━━━━━━━┓
┃(09)用next_e接收cur_e的后继。     ┃
┗━━━━━━━━━━━━━━━━━*//*

Status ListInsert_Sq(SqList *L, int i, ElemType_Sq e);
*//*━━━━━━━━━━━━━━━━━━━━━┓
┃(10)算法2.4：在顺序表L的第i个位置上插入e。┃
┗━━━━━━━━━━━━━━━━━━━━━*//*

Status ListDelete_Sq(SqList L, int i, ElemType_Sq *e);
*//*━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(11)算法2.5：删除顺序表L上第i个位置的元素，并用e返回。┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━*//*

Status ListTraverse_Sq(SqList L, void (Visit)(ElemType_Sq));
*//*━━━━━━━━━━━━━━┓
┃(12)用visit函数访问顺序表L。┃
┗━━━━━━━━━━━━━━*/

#endif //SEQUENCELIST_H
