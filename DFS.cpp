#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#include<vector>


using namespace std ;

#define HEIGHT 14
#define WIDTH 50
#define INF 9999999

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[033m"
#define MAGENTA "\033[35m"
#define RESET "\033[0m"

struct Node {
	char value ;
	int x,y ;
	int cost ;
	bool isVisited ;

	Node* prev ;
} ; 

void buildMap (char maze[HEIGHT][WIDTH+1],Node map[HEIGHT][WIDTH]) {
	for (int i=0 ; i<HEIGHT ; i++) {
		for (int j=0 ; j<WIDTH ; j++) {
			Node* node = &map[i][j] ;
			node->value = maze[i][j] ;
			node->x = j ;
			node->y = i ;
			node->isVisited = false ;
			node->cost = (node->value == '#' ? INF : 1) ;
			node->prev = NULL ;
		}
	}
}

void printMap (Node map[HEIGHT][WIDTH]) {
	system("cls") ;
	for (int i=0 ; i<HEIGHT ; i++) {
		for (int j=0 ; j<WIDTH ; j++) {
			if (map[i][j].value == '#') {
				printf(YELLOW"%c"RESET,map[i][j].value) ;
			} else if (map[i][j].value == '*') {
				printf(RED"%c"RESET,map[i][j].value) ;
			} else {
				printf(GREEN"%c"RESET,map[i][j].value) ;
			}
		}
		puts("") ;
	}
}

bool isValidNode (Node* node) {
	return !node->isVisited && node->cost != INF ;
}

Node* dfs (Node map[HEIGHT][WIDTH]) {
	vector<Node*> list ;
	list.push_back(&map[1][1]) ;

	while (!list.empty()) {
		Node* curr = list.back() ;
		list.pop_back() ;
		if (curr->value == '$') return curr ;

		if (curr->cost == INF || curr->isVisited) continue ;

		curr->isVisited = true ;
		curr->value = '*' ;
		printMap(map) ;
		

		int moveX [] = {0,1,0,-1} ;
		int moveY [] = {1,0,-1,0} ;

		for (int i=0 ; i<4 ; i++) {
			int newX = curr->x + moveX [i] ;
			int newY = curr->y + moveY [i] ;

			Node* next = &map [newY][newX] ;
			if (isValidNode(next)) {
				next->prev = curr ;
				list.push_back(next) ;
			}
		}

	}
	return NULL ;
}

int main() {
	char maze[HEIGHT][WIDTH+1] = {
		"##################################################",
		"#                                                #",
		"######  ######## ########### # ####### ##### ## ##",
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
	Node map [HEIGHT][WIDTH] ;

	buildMap (maze,map) ;

	printMap(map) ;

	Node* node = dfs(map) ;
	
	if (node == NULL) {
		printf(MAGENTA"Not Found\n"RESET) ;
	} else {
		printf(GREEN"Found at coordinate X = %d , Y = %d"RESET,node->x,node->y) ;
	}

	return 0 ;
}
