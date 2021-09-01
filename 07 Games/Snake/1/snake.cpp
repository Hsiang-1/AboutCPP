#define _CRT_SECURE_NO_WARNINGS
#undef UNICODE
#undef _UNICODE

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <graphics.h>
#include <conio.h>

#define LENGTH 1020
#define WIDTH 760
#define PIX 20
#define SLEEPTIME 100

// The Data Structures

// 2-Dimension Point Coordinate 
typedef struct {
	int x;
	int y;
}PointCoordinate;

// Snake Attributes 
struct Snake {
	// this is a special linear list
	int length;													// length of snake
	PointCoordinate sections[(LENGTH / 10) * (WIDTH / 10)];		// coordinate of every section
	char direction;												// direction of snake head
};

// Food Attributes
struct Food
{
	PointCoordinate loc;			// food's location
	int score = 0;					// the score of eatting the food
};

// Enumeration of Directions
enum movDirection {
	right = 77,
	left = 75,
	down = 80,
	up = 72
};

// Declare the Snake & Food
Snake snake;
Food food;

// Handle of main window
HWND hwnd = NULL;

// Declare of functions
void initSnake();					// initialization of snake
void drawSnake();					// draw the snake
void moveSnake();					// move the snake
void keyStroke();					// keystroke handling
void initFood();					// initialization of food
void drawFood();					// draw the food
void eatFood();						// eat the food
void showScore();					// show the score
int touchWall();					// snake touch the wall & game over
int touchSelf();					// touch yourself & game over
void gameoverWindow();				// window of gameover

// Function: main function
int main(int argc, char** argv) {
	// random by time
	srand((unsigned int)time(NULL));

	// initialization of graphic window
	hwnd = initgraph(LENGTH, WIDTH);
	setbkcolor(WHITE);				// background color of the window
	cleardevice();					// reflash

	// init snake & food
	initSnake();
	initFood();

	while (1) {
		cleardevice();
		// eat food judge
		if (food.loc.x == snake.sections[snake.length - 1].x && \
			food.loc.y == snake.sections[snake.length - 1].y) {
			eatFood();
			initFood();
		}
		drawSnake();
		drawFood();
		showScore();
		moveSnake();
		while (_kbhit()) {			// monitor the keystroke
			keyStroke();
		}
		// game over judge
		if (touchWall() || touchSelf())
			break;
		Sleep(SLEEPTIME);
	}
	getchar();
	closegraph();
	return 0;
}

// Function: initialization of snake
void initSnake() {
	// init the snake struct
	
	// the init length is 3
	snake.length = 3;

	// initializate from the rear to the front
	// the sections[2] is the REAR of the snake, and sections[0] the the FRONT !!
	snake.sections[2].x = 0;
	snake.sections[2].y = 0;
	snake.sections[1].x = PIX;
	snake.sections[1].y = 0;
	snake.sections[0].x = PIX * 2;
	snake.sections[0].y = 0;

	// the init direction is right
	snake.direction = right;
}

// Function: draw the snake
void drawSnake() {
	for (int i = 0; i < snake.length; i++) {
		//setlinecolor(BLUE);					// rectangle border color
		//setfillcolor(LIGHTBLUE);			// rectangle filled color
		setlinecolor(WHITE);
		setfillcolor(RGB(rand() % 255, rand() % 255, rand() % 255));
		fillrectangle(snake.sections[i].x, snake.sections[i].y, \
			snake.sections[i].x + PIX, snake.sections[i].y + PIX);	// draw the section
	}
}

// Function: move the snake
void moveSnake() {
	// the first section is new, the others follow its prior
	for (int i = snake.length - 1; i > 0; i--) {
		snake.sections[i].x = snake.sections[i - 1].x;
		snake.sections[i].y = snake.sections[i - 1].y;
	}
	// the first section modify according to the key info
	switch (snake.direction) {
	case right:
		snake.sections[0].x += PIX;
		break;
	case left:
		snake.sections[0].x -= PIX;
		break;
	case up:
		snake.sections[0].y -= PIX;
		break;
	case down:
		snake.sections[0].y += PIX;
		break;
	default:
		break;
	}
}

// Functhon: user keystroke handling
void keyStroke() {
	char userkey = 0;

	// ´íÎó	C4996	'getch': The POSIX name for this item is deprecated.
	// Instead, use the ISO Cand C++ conformant name : _getch.See online help for details.snake_gra
	userkey = _getch();

	switch (userkey) {
	case right:
		if (snake.direction != left)
			snake.direction = right;
		break;
	case left:
		if (snake.direction != right)
			snake.direction = left;
		break;
	case up:
		if (snake.direction != down)
			snake.direction = up;
		break;
	case down:
		if (snake.direction != up)
			snake.direction = down;
		break;
	default:
		break;
	}
}

// Function: initialization of food
void initFood() {
	// the food's coordinate
	food.loc.x = rand() % (LENGTH / PIX) * PIX;
	food.loc.y = rand() % (WIDTH / PIX) * PIX;

	// superposition of snake and food
	for (int i = 0; i < snake.length; i++) {
		if (snake.sections[i].x == food.loc.x && snake.sections[i].y == food.loc.y)
			initFood();
	}
}

// Function: draw the food
void drawFood() {
	setlinecolor(RED);						// rectangle border color
	setfillcolor(LIGHTRED);					// rectangle filled color
	//setlinecolor(RGB(rand() % 255, rand() % 255, rand() % 255));
	//setfillcolor(RGB(rand() % 255, rand() % 255, rand() % 255));
	fillrectangle(food.loc.x, food.loc.y, food.loc.x + PIX, food.loc.y + PIX);		// draw the section
}

// Function: eat the food
void eatFood() {
	snake.length++;
	snake.sections[snake.length - 1].x = food.loc.x;
	snake.sections[snake.length - 1].y = food.loc.y;
	food.score += 10;
}

// show the score
void showScore() {
	char score[100] = "";
	sprintf(score, "%d", food.score);		// int to char[]
	setbkmode(TRANSPARENT);					// text backgrd
	settextcolor(BLACK);
	outtextxy(LENGTH - 100, 20, "Score:");
	outtextxy(LENGTH - 40, 20, score);
}

// snake touch the wall & game over
int touchWall() {
	if (snake.sections[0].x > LENGTH || snake.sections[0].x<0 || \
		snake.sections[0].y>WIDTH || snake.sections[0].y < 0){
		gameoverWindow();
		return 1;
	}
	return 0;
}

// touch yourself & game over
int touchSelf() {
	for (int i = 0; i < snake.length - 1; i++)
		if (snake.sections[i].x == snake.sections[snake.length - 1].x && \
			snake.sections[i].y == snake.sections[snake.length - 1].y) {
			gameoverWindow();
			return 1;
		}
	return 0;
}

// window of gameover
void gameoverWindow() {
	outtextxy(LENGTH / 2 - 20, WIDTH / 2, "GAME OVER!");
	MessageBox(hwnd, "Game Over!", "GAME OVER!", MB_OK);
}