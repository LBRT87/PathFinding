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
    int x,y;
    int g,h,f;
    int px,py;
} Node;

Node openList[10000];
int openCount = 0;

int closed[HEIGHT][WIDTH];
Node parent[HEIGHT][WIDTH];

void swap(Node *a, Node *b){
    Node temp = *a;
    *a = *b;
    *b = temp;
}

void push(Node n){
    openList[openCount] = n;
    int i = openCount++;

    while(i > 0){
        int p = (i-1)/2;
        if(openList[p].f <= openList[i].f) break;
        swap(&openList[p], &openList[i]);
        i = p;
    }
}

Node pop(){
    Node top = openList[0];
    openList[0] = openList[--openCount];

    int i = 0;
    while(1){
        int left = 2*i+1, right = 2*i+2, smallest = i;
        if(left < openCount && openList[left].f < openList[smallest].f) smallest = left;
        if(right < openCount && openList[right].f < openList[smallest].f) smallest = right;
        if(smallest == i) break;
        swap(&openList[i], &openList[smallest]);
        i = smallest;
    }

    return top;
}

int findGoal(int *gx, int *gy){
    for(int i=0;i<HEIGHT;i++){
        for(int j=0;j<WIDTH;j++){
            if(maze[i][j]=='$'){
                *gx = i; *gy = j;
                return 1;
            }
        }
    }
    return 0;
}

void viewMaze(){
    system("cls");
    for(int i=0;i<HEIGHT;i++){
        for(int j=0;j<WIDTH;j++){
            if(maze[i][j]=='$') printf(GREEN"%c"RESET,maze[i][j]);
            else if(maze[i][j]=='*') printf(RED"%c"RESET,maze[i][j]);
            else if(maze[i][j]=='E') printf(YELLOW"%c"RESET,maze[i][j]);
            else printf(MAGENTA"%c"RESET,maze[i][j]);
        }
        printf("\n");
    }
}
int Founded_X ;
int Founded_Y ;

void Astar(int sx, int sy){
    int gx, gy;
    if(!findGoal(&gx,&gy)){
        printf("Tidak Ditemukan\n");
        return;
    }

    Node start = {sx,sy,0,0,0,-1,-1};
    push(start);

    int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

    while(openCount){
        Node cur = pop();

        if(closed[cur.x][cur.y]) continue;
        closed[cur.x][cur.y] = 1;

        if(maze[cur.x][cur.y] != '$'){
        	Founded_X = cur.x ;
        	Founded_Y = cur.y ;
            maze[cur.x][cur.y] = 'E';
            viewMaze();
            Sleep(5);
        }

        if(cur.x==gx && cur.y==gy){
            int cx = gx, cy = gy;

            while(!(cx==sx && cy==sy)){
                maze[cx][cy] = '*';
                int tx = parent[cx][cy].px;
                int ty = parent[cx][cy].py;
                cx = tx; cy = ty;
            }
            return;
        }

        for(int i=0;i<4;i++){
            int nx = cur.x + dir[i][0];
            int ny = cur.y + dir[i][1];

            if(nx<1||ny<1||nx>=HEIGHT||ny>=WIDTH) continue;
            if(maze[nx][ny]=='#') continue;
            if(closed[nx][ny]) continue;

            int g = cur.g + 1;
            int h = abs(nx-gx) + abs(ny-gy);
            int f = g + h;

            Node next = {nx,ny,g,h,f,cur.x,cur.y};
            parent[nx][ny] = next;

            push(next);
        }
    }
}

int main(){
    Astar(1,1);
    viewMaze();
    printf(YELLOW"Cuan Cuan Cuan x = %d, y = %d\n"RESET,Founded_X,Founded_Y) ;
    return 0;
}
