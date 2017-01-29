/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  test skiplist
 *
 *        Version:  1.0
 *        Created:  2017/01/30 01时39分47秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  shaolianbo, 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include "skiplist.h"


int main(int argc, char **argv) {
    zskiplist * zsl = zslCreate();    
    zslInsert(zsl, 5);
    zslInsert(zsl, 4);
    zslInsert(zsl, 4);
    zslInsert(zsl, 3);
    zslInsert(zsl, 2);
    zslInsert(zsl, 1);
    
    printf("init===\n");
    zslprintElements(zsl);
   
    printf("del 4\n");
    zslDelete(zsl, 4);
    zslprintElements(zsl);

    zskiplistNode * node = zslGetElementByRank(zsl, 2);
    printf("the second score:%f\n", node->score);

    zslFree(zsl);
}
