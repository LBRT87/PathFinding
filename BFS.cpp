#include<stdio.h>
#include<windows.h>
#include<stdlib.h>

#define HEIGHT 14
#define WIDTH 51

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define MAGENTA "\033[35m"
#define RESET "\033[0m"

char maze[HEIGHT][WIDTH] = {
    "##################################################",
    "#                                                #",
    "################ ########### # ####### ##### ## ##",
    "#              # #  #   #    # #######    ## ## ##",
    "## ###########   ##   #   ####   ##     # ##  # ##",
    "## ############# ########## #### ## # ### ### # ##",
    "## #                # # # # #### ## # ####### # ##",
    "##   ##########   ### # # # #              ## # ##",
    "#### ##########               ## ############   ##",
    "# ##          # ############# ##              ####",
    "# ## #### ##### ##     $      ## ### ## ### # ####",
    "#    ####          ####  ####    ### ## ##  #    #",
    "# ####### ########            ################## #",
    "##################################################"
};

typedef struct {
    int x, y;
} Node;

typedef struct {
    int x, y;
    int px, py;     // parent koordinat
} Parent;

Parent parent[HEIGHT][WIDTH];
int visited[HEIGHT][WIDTH];

void viewMaze(){
    system("cls");
    for(int i=0;i<HEIGHT;i++){
        for(int j=0;j<WIDTH;j++){
            if(maze[i][j]=='$') printf(GREEN"%c"RESET, maze[i][j]);
            else if(maze[i][j]=='*') printf(RED"%c"RESET, maze[i][j]);
            else if(maze[i][j]=='E') printf(YELLOW"%c"RESET, maze[i][j]);
            else printf(MAGENTA"%c"RESET, maze[i][j]);
        }
        printf("\n");
    }
}

int Founded_X ;
int Founded_Y ;

void BFS(int sx, int sy){
    Node queue[10000];
    int front = 0, back = 0;

    queue[back++] = (Node){sx, sy};
    visited[sx][sy] = 1;
    parent[sx][sy] = (Parent){-1,-1,-1,-1};

    int found = 0;
    int fx, fy;

    int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

    while(front < back){
        Node now = queue[front++];
        int x = now.x, y = now.y;

        if(maze[x][y] == '$'){
            found = 1;
            fx = x; fy = y;
            Founded_X = x ;
            Founded_Y = y ;
            break;
        }

        maze[x][y] = 'E';
        viewMaze();
        Sleep(5);

        for(int i=0;i<4;i++){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];

            if(nx<1 || ny<1 || nx>=HEIGHT || ny>=WIDTH) continue;
            if(maze[nx][ny]=='#') continue;
            if(visited[nx][ny]) continue;

            visited[nx][ny] = 1;
            parent[nx][ny] = (Parent){nx,ny,x,y};
            queue[back++] = (Node){nx,ny};
        }
    }

    if(found){
        int cx = fx, cy = fy;

        while(parent[cx][cy].px != -1){
            maze[cx][cy] = '*';
            int tx = parent[cx][cy].px;
            int ty = parent[cx][cy].py;
            cx = tx; cy = ty;
        }
    }
}

int main(){
    BFS(1,1);
    viewMaze();
    printf(YELLOW"Cuan Cuan Cuan at x = %d, y = %d\n"RESET,Founded_X,Founded_Y) ;
    return 0;
}
