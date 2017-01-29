/*
 * =====================================================================================
 *
 *       Filename:  skiplist.h
 *
 *    Description:  从redis-3.2.6源码src/server.h里摘出的跳表的定义
 *
 *        Version:  1.0
 *        Created:  2017/01/30 00时28分29秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  shaolianbo, 
 *   Organization:  
 *
 * =====================================================================================
 */


/* ZSETs use a specialized version of Skiplists */
typedef struct zskiplistNode {
    //robj *obj;
    double score;
    struct zskiplistNode *backward;
    struct zskiplistLevel {
        struct zskiplistNode *forward;
        unsigned int span;
    } level[];
} zskiplistNode;

typedef struct zskiplist {
    struct zskiplistNode *header, *tail;
    unsigned long length;
    int level;
} zskiplist;

zskiplist *zslCreate(void);
void zslFree(zskiplist *zsl);
zskiplistNode *zslInsert(zskiplist *zsl, double score);
int zslDelete(zskiplist *zsl, double score);
zskiplistNode *zslGetElementByRank(zskiplist *zsl, unsigned long rank);
void zslprintElements(zskiplist *zsl);
