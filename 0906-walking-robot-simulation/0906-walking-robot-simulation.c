#include <stdio.h>
#include <stdlib.h>

#define MAX_OBSTACLES 1000

typedef struct {
    int x;
    int y;
} Position;

int comparePoints(const void* a, const void* b) {
    Position* p1 = (Position*)a;
    Position* p2 = (Position*)b;
    if (p1->x == p2->x) {
        return p1->y - p2->y;
    } else {
        return p1->x - p2->x;
    }
}

int robotSim(int* commands, int commandsSize, int** obstacles, int obstaclesSize, int* obstaclesColSize) {
    int x = 0, y = 0, d = 0;
    int direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int max_distance = 0;

    Position* obstacleSet = (Position*)malloc(obstaclesSize * sizeof(Position));
    for (int i = 0; i < obstaclesSize; i++) {
        obstacleSet[i].x = obstacles[i][0];
        obstacleSet[i].y = obstacles[i][1];
    }
    qsort(obstacleSet, obstaclesSize, sizeof(Position), comparePoints);

    // Process commands
    for (int i = 0; i < commandsSize; i++) {
        int cmd = commands[i];
        if (cmd == -1) {
            d = (d + 1) % 4; // Turn right
        } else if (cmd == -2) {
            d = (d - 1 + 4) % 4; // Turn left
        } else {
            for (int j = 0; j < cmd; j++) {
                int nx = x + direction[d][0];
                int ny = y + direction[d][1];

                Position new_pos = {nx, ny};
                if (bsearch(&new_pos, obstacleSet, obstaclesSize, sizeof(Position), comparePoints) == NULL) {
                    x = nx;
                    y = ny;
                    max_distance = (max_distance > (x * x + y * y)) ? max_distance : (x * x + y * y);
                } else {
                    break;
                }
                // // Check for obstacles
                // int hitObstacle = 0;
                // for (int k = 0; k < obstaclesSize; k++) {
                //     if (obstacles[k][0] == nx && obstacles[k][1] == ny) {
                //         hitObstacle = 1;
                //         break; // Stop moving if there's an obstacle
                //     }
                // }
                // if (hitObstacle) {
                //     break; // Stop moving if there's an obstacle
                // }
                // x = nx;
                // y = ny;
                // max_distance = (max_distance > (x * x + y * y)) ? max_distance : (x * x + y * y);
            }
        }
    }

    return max_distance;
}
