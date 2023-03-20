#include "compile_control.h"
#ifdef SHORT_PATH

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <assert.h>

typedef struct {
    int x, y;
    int step;
} Node_t;

Node_t Node(int x, int y, int step) {
    Node_t instance;
    instance.x = x;
    instance.y = y;
    instance.step = step;
    return instance;
}

typedef struct {
    int size;
    int* map_array;
}Map_t;

Map_t Map(int size) {
    Map_t map;
    map.size = size;
    map.map_array = (int*)malloc(size * size * sizeof(int));
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++)
            scanf("%d", &map.map_array[i * size + j]);
        getchar();
    }

    return map;
}

int What_is(Node_t node, Map_t map) {
    if (node.x < 0 || node.x >= map.size || node.y < 0 || node.y >= map.size)
        return 0;

    if (map.map_array[node.y * map.size + node.x] == 0)
        return 1;
    else
        return 0;
}

//实现一个队列用于存放BFS过程中的节点
typedef Node_t Queue_Data_t;

typedef struct Queue_Element_t {
    Queue_Data_t val;
    struct Queue_Element_t* next;
} Queue_Element_t;

typedef struct {
    Queue_Element_t* head;
    Queue_Element_t* tail;
} Queue_t;

void Queue_Init(Queue_t* q) {

    q->tail = NULL;
    q->head = q->tail;
    return;
}

Queue_Data_t Queue_Get_Front(Queue_t* q) {

    return q->head->val;
}

void Queue_Push(Queue_t* q, Queue_Data_t node) {


    Queue_Element_t* new_element = (Queue_Element_t*)malloc(sizeof(Queue_Element_t));

    assert(new_element != NULL);

    new_element->next = NULL;
    new_element->val = node;

    if (q->tail == NULL) {
        assert(q->head == NULL);
        q->head = q->tail = new_element;
    }
    else {
        q->tail->next = new_element;
        q->tail = new_element;
    }

    return;
}

void Queue_Pop(Queue_t* q) {

    assert(q->head && q->tail);

    if (q->head->next == NULL) {
        free(q->head);
        q->head = q->tail = NULL;
    }
    else {
        Queue_Element_t* new_head = q->head->next;
        free(q->head);
        q->head = new_head;
    }

    return;
}

int Queue_Is_Empty(Queue_t* q) {

    return q->head == NULL;
}

void Queue_Destory(Queue_t* q) {


    Queue_Element_t* cur_node = q->head;
    while (cur_node) {
        Queue_Element_t* next = cur_node->next;
        free(cur_node);
        cur_node = next;
    }
    return;
}
/*------------------Type and Function End--------------------*/


/*---------------------Algorithm Part------------------------*/
Map_t map;
int visited[15][15];
Queue_t open_q;
Node_t start, end, cur;
int move[4][2] = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} };


int bfs() {
    start = Node(1, 1, 0);
    end = Node(map.size - 2, map.size - 2, 0);
    Queue_Init(&open_q);
    Queue_Push(&open_q, start);
    visited[start.x][start.y] = 1;

    while (!Queue_Is_Empty(&open_q)) {
        cur = Queue_Get_Front(&open_q);
        Queue_Pop(&open_q);
        if (cur.x == end.x && cur.y == end.y) return cur.step;
        int i;
        for (i = 0; i < 4; i++) {
            Node_t new_node = Node(cur.x + move[i][0], cur.y + move[i][1], cur.step + 1);
            if (What_is(new_node, map) && !visited[new_node.x][new_node.y]) {
                visited[new_node.x][new_node.y] = 1;
                Queue_Push(&open_q, new_node);
            }
        }
    }
    return -1;
}

int main() {
    int size;
    scanf("%d", &size);
    map = Map(size);

    int min_step = bfs();
    if (min_step == -1)
        printf("No solution");
    else
        printf("%d", min_step);
    return 0;
}

#endif