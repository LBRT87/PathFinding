#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>

#define HEIGHT 14
#define WIDTH 51
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[033m"
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

void gotoxy (int x,int y) {
	COORD coord ;
	coord.X = x ;
	coord.Y = y ;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord) ;
}

void viewMaze () {

	for (int i=0 ; i<HEIGHT ; i++) {
		for (int j=0 ; j<WIDTH ; j++) {
		
			if (maze[i][j] == '$') {
				printf(GREEN"%c"RESET,maze[i][j]) ;
				
			} else if (maze[i][j] == '*') {
				printf(RED"%c"RESET,maze[i][j]) ;
			} else if (maze [i][j] == 'E') {
				printf(YELLOW"%c"RESET,maze[i][j]) ;
			} 
			else {
				printf(MAGENTA"%c"RESET,maze[i][j]) ;
			}
		}
		printf("\n") ;
	} 

}

int found = 0 ;
int Founded_X ;
int Founded_Y ;

void move (int x,int y) {
	
	if (found) return ;
	if (x<1 || y<1 || x>=HEIGHT || y>=WIDTH) return ;
	if (maze[x][y] == '#' || maze[x][y] == 'E') return ;
	if (maze[x][y] == '$') {
		Founded_X = x ;
		Founded_Y = y ;
		found = 1 ; ;
		return ;
	}  
	
	maze[x][y] = 'E' ;
	viewMaze() ;
	Sleep(1) ;
	system("cls") ;

	move(x,y+1) ; // GO RIGHT
	move(x+1,y) ; // GO DOWN
	move(x,y-1) ; // GO LEFT
	move(x-1,y) ; // GO UP
	
	if (found) {
		maze[x][y] = '*' ;
	} else {
		maze [x][y] = ' ' ;
	}
		
}



int main() {

	int x_start = 1;
	int y_start = 1;
	move(x_start,y_start) ;
	viewMaze() ;
	
	gotoxy(0,HEIGHT+2) ;
	
	printf(YELLOW"Cuan Cuan Cuan at x = %d, y = %d\n",Founded_X,Founded_Y) ;

	
	
	
	
	
	
	
	
	
	return 0 ;
}
