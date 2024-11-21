#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "boolean.h"

const int MXN = 100;

int main() {
    int i, j, N;
    char arr[MXN][MXN];
    Queue q;
    int start_x, start_y, end_x, end_y, x, y, current, move_dir, new_x, new_y;
    ElType start, current_pos, next_pos;
    int visited[MXN][MXN], dist[MXN][MXN];
    int move_x[] = {1, -1, 0, 0};
    int move_y[] = {0, 0, 1, -1}; 

    CreateQueue(&q);
    scanf("%d", &N);
    
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            scanf(" %c", &arr[i][j]);
            if (arr[i][j] == 'A') {
                start_x = i;
                start_y = j;
            }
            if (arr[i][j] == 'B') {
                end_x = i;
                end_y = j;
            }
        }
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            visited[i][j] = 0;
            dist[i][j] = -1;
        }
    }

    start.row = start_x;
    start.col = start_y;
    enqueue(&q, start);
    visited[start_x][start_y] = 1;
    dist[start_x][start_y] = 0;
    while (!isEmpty(q)) {
        current_pos = HEAD(q);
        dequeue(&q, &current_pos);
        x = current_pos.row;
        y = current_pos.col;

        if (x == end_x && y == end_y) {
            printf("Ya\n");
            printf("%d\n", dist[x][y]);
            return 0;
        }
        for (move_dir = 0; move_dir < 4; move_dir++) {
            new_x = x + move_x[move_dir];
            new_y = y + move_y[move_dir];

            if (new_x >= 0 && new_x < N && new_y >= 0 && new_y < N && !visited[new_x][new_y] && arr[new_x][new_y] != '#') {
                visited[new_x][new_y] = 1;
                dist[new_x][new_y] = dist[x][y] + 1;
                next_pos.row = new_x;
                next_pos.col = new_y;
                enqueue(&q, next_pos);
            }
        }
    }
    printf("Tidak\n");
    return 0;
}