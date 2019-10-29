#include<GL\glew.h>
#include<GL\glut.h>
#include <iostream>
#include<string.h>
#include<stdlib.h>
#include <string>

using namespace std;

int matrix[6][6];													//Matrix to store the cells occupied by players
int occupy_h[6][6];													//Stores the Horizontal Winning instances
int occupy_v[6][6];													//Stores the Vertical Winning instances
int occupy_d1[6][6];												//Stores the Diagonal and Forward Winning Instances
int occupy_d2[6][6];												//Stores the Diagonal and Backward Winning Instances
int flag, p1 = 0, p2 = 0, click_count = 0;							//Flag to change player's turn, p1,p2- Player Points Click_Count - Cont the mouse clicks
bool gameover=false;												//Boolean value to check whether the game is over or not
string player1 = " ", player2 = " ",Count=" ";						//Casted values of P1,p2, and Click_Count to display

void NewGame();
void reshape(int,int);
void Display();
void DrawString(void*, float, float,string);
void Interface();
void GameStart(int, int, int, int);
void WinInstance();
void symbols();

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(400, 100);								//Create the Window Position
	glutInitWindowSize(1010, 910);									//Defineing the Window Size
	glutCreateWindow("Tak Tik Tuk");								//Creat the Window of the Game

	NewGame();														//Calling the NewGame Function to Start a new Game

	glutMainLoop();													//Calling the display over and over again
	return 0;
}

void NewGame() {
	flag = 1;														//To make the turn for the player 1											
	for (int x = 0; x < 6; x++) {									//Loop to reset every value of the 5 matrices to 0 to start a new game
		for (int y = 0; y < 6; y++) {
			matrix[x][y] = 0;
			occupy_h[x][y] = 0;
			occupy_v[x][y] = 0;
			occupy_d1[x][y] = 0;
			occupy_d2[x][y] = 0;
		}
	}
	glutReshapeFunc(reshape);										//
	glutDisplayFunc(Display);										//Function to Display the Content
	glutMouseFunc(GameStart);										//Function to get Mouse Inputs and Start the Game
}

void reshape(int x, int y) {
	glLoadIdentity();
	glOrtho(0, x, y, 0, 0, 1);
	glMatrixMode(GL_MODELVIEW);
}

void Display(void) {
	glClear(GL_COLOR_BUFFER_BIT);									//Clears the Color 
	glClearColor(0.0, 0.0, 0.15, 1.0);								//Set the color for the window

	Interface();													//Function to add all the polygons displayed
	symbols();														//Funtion to add Crosses,Rounds with the when the Game started and Update the player points

	if (click_count == 36) {										//Game Ending Instance.
		gameover = true;
		glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 0.15);
		glVertex2f(305, 465);
		glVertex2f(930, 465);
		glVertex2f(930, 570);
		glVertex2f(305, 570);
		glEnd();


		glColor3f(1.0, 0.5, 0.0);
		if (p1 > p2) {
			DrawString(GLUT_BITMAP_TIMES_ROMAN_24, 535, 520, "Player 01 Wins !");
		}
		else if (p2 > p1) {
			DrawString(GLUT_BITMAP_TIMES_ROMAN_24, 535, 520, "Player 02 Wins !");
		}
		else if (p2 == p1) {
			DrawString(GLUT_BITMAP_TIMES_ROMAN_24, 555, 520, "Game Draw !");
		}

	}
	glutSwapBuffers();												//Swapping the layers of the window
}

void DrawString(void *font, float x, float y, string word) {		//Function to have Fonts
	int i;
	glRasterPos2f(x, y);
	for (i = 0; i < word.length(); i++)
		glutBitmapCharacter(font, word[i]);
}

void Interface() {
	//Topic Box
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.5, 0.15);
	glVertex2f(60, 45);
	glVertex2f(60, 145);
	glVertex2f(945, 145);
	glVertex2f(945, 45);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(75, 60);
	glVertex2f(75, 130);
	glVertex2f(930, 130);
	glVertex2f(930, 60);
	glEnd();

	glColor3f(1.0, 0.5, 0.15);
	DrawString(GLUT_BITMAP_TIMES_ROMAN_24, 450, 105, "Tak Tik Tuk");

	//Large box
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(290, 190);
	glVertex2f(945, 190);
	glVertex2f(945, 845);
	glVertex2f(290, 845);
	glEnd();


	glColor3f(0.0, 0.3, 0.6);
	
	//First Row 
	glBegin(GL_POLYGON);
	glVertex2f(305, 205);
	glVertex2f(405, 205);
	glVertex2f(405, 305);
	glVertex2f(305, 305);
	glEnd();
	
	glBegin(GL_POLYGON);
	glVertex2f(410, 205);
	glVertex2f(510, 205);
	glVertex2f(510, 305);
	glVertex2f(410, 305);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(515, 205);
	glVertex2f(615, 205);
	glVertex2f(615, 305);
	glVertex2f(515, 305);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(620, 205);
	glVertex2f(720, 205);
	glVertex2f(720, 305);
	glVertex2f(620, 305);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(725, 205);
	glVertex2f(825, 205);
	glVertex2f(825, 305);
	glVertex2f(725, 305);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(830, 205);
	glVertex2f(930, 205);
	glVertex2f(930, 305);
	glVertex2f(830, 305);
	glEnd();


	//Second Row
	glBegin(GL_POLYGON);
	glVertex2f(305, 310);
	glVertex2f(405, 310);
	glVertex2f(405, 410);
	glVertex2f(305, 410);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(410, 310);
	glVertex2f(510, 310);
	glVertex2f(510, 410);
	glVertex2f(410, 410);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(515, 310);
	glVertex2f(615, 310);
	glVertex2f(615, 410);
	glVertex2f(515, 410);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(620, 310);
	glVertex2f(720, 310);
	glVertex2f(720, 410);
	glVertex2f(620, 410);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(725, 310);
	glVertex2f(825, 310);
	glVertex2f(825, 410);
	glVertex2f(725, 410);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(830, 310);
	glVertex2f(930, 310);
	glVertex2f(930, 410);
	glVertex2f(830, 410);
	glEnd();


	//Third Row
	glBegin(GL_POLYGON);
	glVertex2f(305, 415);
	glVertex2f(405, 415);
	glVertex2f(405, 515);
	glVertex2f(305, 515);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(410, 415);
	glVertex2f(510, 415);
	glVertex2f(510, 515);
	glVertex2f(410, 515);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(515, 415);
	glVertex2f(615, 415);
	glVertex2f(615, 515);
	glVertex2f(515, 515);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(620, 415);
	glVertex2f(720, 415);
	glVertex2f(720, 515);
	glVertex2f(620, 515);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(725, 415);
	glVertex2f(825, 415);
	glVertex2f(825, 515);
	glVertex2f(725, 515);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(830, 415);
	glVertex2f(930, 415);
	glVertex2f(930, 515);
	glVertex2f(830, 515);
	glEnd();


	//Forth Row
	glBegin(GL_POLYGON);
	glVertex2f(305, 520);
	glVertex2f(405, 520);
	glVertex2f(405, 620);
	glVertex2f(305, 620);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(410, 520);
	glVertex2f(510, 520);
	glVertex2f(510, 620);
	glVertex2f(410, 620);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(515, 520);
	glVertex2f(615, 520);
	glVertex2f(615, 620);
	glVertex2f(515, 620);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(620, 520);
	glVertex2f(720, 520);
	glVertex2f(720, 620);
	glVertex2f(620, 620);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(725, 520);
	glVertex2f(825, 520);
	glVertex2f(825, 620);
	glVertex2f(725, 620);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(830, 520);
	glVertex2f(930, 520);
	glVertex2f(930, 620);
	glVertex2f(830, 620);
	glEnd();


	//Fifth Row
	glBegin(GL_POLYGON);
	glVertex2f(305, 625);
	glVertex2f(405, 625);
	glVertex2f(405, 725);
	glVertex2f(305, 725);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(410, 625);
	glVertex2f(510, 625);
	glVertex2f(510, 725);
	glVertex2f(410, 725);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(515, 625);
	glVertex2f(615, 625);
	glVertex2f(615, 725);
	glVertex2f(515, 725);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(620, 625);
	glVertex2f(720, 625);
	glVertex2f(720, 725);
	glVertex2f(620, 725);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(725, 625);
	glVertex2f(825, 625);
	glVertex2f(825, 725);
	glVertex2f(725, 725);
	glEnd();


	glBegin(GL_POLYGON);
	glVertex2f(830, 625);
	glVertex2f(930, 625);
	glVertex2f(930, 725);
	glVertex2f(830, 725);
	glEnd();


	//Sixth Row
	glBegin(GL_POLYGON);
	glVertex2f(305, 730);
	glVertex2f(405, 730);
	glVertex2f(405, 830);
	glVertex2f(305, 830);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(410, 730);
	glVertex2f(510, 730);
	glVertex2f(510, 830);
	glVertex2f(410, 830);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(515, 730);
	glVertex2f(615, 730);
	glVertex2f(615, 830);
	glVertex2f(515, 830);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(620, 730);
	glVertex2f(720, 730);
	glVertex2f(720, 830);
	glVertex2f(620, 830);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(725, 730);
	glVertex2f(825, 730);
	glVertex2f(825, 830);
	glVertex2f(725, 830);
	glEnd();


	glBegin(GL_POLYGON);
	glVertex2f(830, 730);
	glVertex2f(930, 730);
	glVertex2f(930, 830);
	glVertex2f(830, 830);
	glEnd();

	//Moves Remaining Box
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.5, 0.0);
	glVertex2f(59, 269);
	glVertex2f(261, 269);
	glVertex2f(261, 361);
	glVertex2f(59, 361);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(60, 270);
	glVertex2f(260, 270);
	glVertex2f(260, 360);
	glVertex2f(60, 360);
	glEnd();

	glColor3f(1.0, 0.5, 0.0);
	DrawString(GLUT_BITMAP_HELVETICA_18, 85, 295, "Moves Remaining");


	//Player Box 1
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.5, 0.0);
	glVertex2f(59, 419);
	glVertex2f(261, 419);
	glVertex2f(261, 491);
	glVertex2f(59, 491);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(60, 420);
	glVertex2f(260, 420);
	glVertex2f(260, 490);
	glVertex2f(60, 490);
	glEnd();

	glColor3f(1.0, 0.5, 0.0);
	DrawString(GLUT_BITMAP_HELVETICA_18, 120, 442, "Player 01");


	//Player box 2
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.5, 0.0);
	glVertex2f(59, 539);
	glVertex2f(261, 539);
	glVertex2f(261, 611);
	glVertex2f(59, 611);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0 ,0.0);
	glVertex2f(60, 540);
	glVertex2f(260, 540);
	glVertex2f(260, 610);
	glVertex2f(60, 610);
	glEnd();

	glColor3f(1.0, 0.5, 0.0);
	DrawString(GLUT_BITMAP_HELVETICA_18, 120, 562, "Player 02");

	//New Game
	
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.3, 0.9);
	glVertex2f(57, 657);
	glVertex2f(263, 657);
	glVertex2f(263, 703);
	glVertex2f(57, 703);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(60, 660);
	glVertex2f(260, 660);
	glVertex2f(260, 700);
	glVertex2f(60, 700);
	glEnd();
	glColor3f(0.0, 0.3, 0.9);
	DrawString(GLUT_BITMAP_HELVETICA_18, 115, 685, "New Game");

}

void GameStart(int button, int state, int x, int y) {									//Starts the game with identifying the mouse clicks, Stops when the gomeover becomes true
	if (gameover == false && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		if (flag == 1) {
			if (x > 305 && x<930 && y>205 && y<830 && matrix[(x - 305) / 105][(y - 205) / 105] == 0) {
				matrix[(x - 305) / 105][(y - 205) / 105] = 1;
				flag = 2;
				click_count++;
				WinInstance();
			}
		}

		else if (flag == 2) {
			if (x > 305 && x<930 && y>205 && y<830 && matrix[(x - 305) / 105][(y - 205) / 105] == 0) {
				matrix[(x - 305) / 105][(y - 205) / 105] = 2;
				flag = 1;
				click_count++;
				WinInstance();
			}
		}
		if (x<260 && x>60 && y < 700 && y>660) {
			NewGame();
			p1 = 0;
			p2 = 0;
			click_count = 0;
		}
	}
	if (gameover == true && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		NewGame();
		p1 = 0;
		p2 = 0;
		click_count = 0;
		gameover = false;
	}

}

void symbols() {																
	for (int x = 0; x <= 5; x++) {
		for (int y = 0; y <= 5; y++) {
			if (matrix[x][y] == 1) {
				glBegin(GL_POLYGON);
				glColor3f(0.0, 0.0, 0.0);
				glVertex2f(320 + x * 105, 220 + y * 105);
				glVertex2f(390 + x * 105, 220 + y * 105);
				glVertex2f(390 + x * 105, 290 + y * 105);
				glVertex2f(320 + x * 105, 290 + y * 105);
				glEnd();

				glBegin(GL_POLYGON);
				glColor3f(0.0, 0.3, 0.6);
				glVertex2f(326 + x * 105, 226 + y * 105);
				glVertex2f(384 + x * 105, 226 + y * 105);
				glVertex2f(384 + x * 105, 284 + y * 105);
				glVertex2f(326 + x * 105, 284 + y * 105);
				glEnd();

			}
			else if (matrix[x][y] == 2) {
				glBegin(GL_POLYGON);
				glColor3f(0.0, 0.0, 0.0);
				glVertex2f(320 + x * 105, 226 + y * 105);
				glVertex2f(326 + x * 105, 220 + y * 105);
				glVertex2f(390 + x * 105, 284 + y * 105);
				glVertex2f(384 + x * 105, 290 + y * 105);
				glEnd();

				glBegin(GL_POLYGON);
				glColor3f(0.0, 0.0, 0.0);
				glVertex2f(320 + x * 105, 284 + y * 105);
				glVertex2f(326 + x * 105, 290 + y * 105);
				glVertex2f(390 + x * 105, 226 + y * 105);
				glVertex2f(384 + x * 105, 220 + y * 105);
				glEnd();
			}
		}

		glColor3f(1.0, 0.5, 0.0);
		Count = to_string(36 - click_count);
		DrawString(GLUT_BITMAP_TIMES_ROMAN_24, 150, 335,Count);


		if (p1 == 0) {
			DrawString(GLUT_BITMAP_TIMES_ROMAN_24, 150, 475, "00");
		}
		else {
			player1 = to_string(p1);
			DrawString(GLUT_BITMAP_TIMES_ROMAN_24, 150, 475, player1);
		}


		if (p2 == 0) {
			DrawString(GLUT_BITMAP_TIMES_ROMAN_24, 150, 595, "00");
		}
		else {
			player2 = to_string(p2);
			DrawString(GLUT_BITMAP_TIMES_ROMAN_24, 150, 595,player2);
		}
		
		if (flag == 1) {
			DrawString(GLUT_BITMAP_TIMES_ROMAN_24, 80, 745,"Player 01's Turn");
		}
		else {
			DrawString(GLUT_BITMAP_TIMES_ROMAN_24, 80, 745, "Player 02's Turn");
		}
		
	}
}

void WinInstance() {
	int x, y;

	//Winning Vertically
	for (x = 0; x<6; x++) {
		for (y = 0; y <= 3; y++) {
			if (matrix[x][y] == matrix[x][y + 1] && matrix[x][y] == matrix[x][y + 2] && matrix[x][y] != 0 && occupy_v[x][y] != 1 && occupy_v[x][y + 1] != 1 && occupy_v[x][y + 2] != 1) {
				occupy_v[x][y] = 1;
				occupy_v[x][y + 1] = 1;
				occupy_v[x][y + 2] = 1;

				if (flag == 1) {
					p2 = p2 + 10;
					printf("Verticle(%d,%d) : p2 = %d \n", x, y, p2);

				}
				else if (flag == 2) {
					p1 = p1 + 10;
					printf("Verticle(%d,%d) : p1 = %d \n", x, y, p1);
				}
			}
			else {
				continue;
			}
		}
	}

	//Winning Horizontally
	for (y = 0; y<6; y++) {
		for (x = 0; x <= 3; x++) {
			if (matrix[x][y] == matrix[x + 1][y] && matrix[x][y] == matrix[x + 2][y] && matrix[x][y] != 0 && occupy_h[x][y] != 2 && occupy_h[x + 1][y] != 2 && occupy_h[x + 2][y] != 2) {
				occupy_h[x][y] = 2;
				occupy_h[x + 1][y] = 2;
				occupy_h[x + 2][y] = 2;

				if (flag == 1) {
					p2 = p2 + 10;
					printf("Horizontal(%d,%d) : p2 = %d \n", x, y, p2);
				}
				else if (flag == 2) {
					p1 = p1 + 10;
					printf("Horizontal(%d,%d) : p1 = %d \n", x, y, p1);
				}
			}
			else {
				continue;
			}
		}
	}

	//Win Diagonally
	for (x = 0; x<4; x++) {
		for (y = 0; y<4; y++) {
			if (matrix[x][y] != 0 && matrix[x][y] == matrix[x + 1][y + 1] && matrix[x][y] == matrix[x + 2][y + 2] && occupy_d1[x][y] != 1 && occupy_d1[x + 1][y + 1] != 1 && occupy_d1[x + 2][y + 2] != 1) {
				occupy_d1[x][y] = 1;
				occupy_d1[x + 1][y + 1] = 1;
				occupy_d1[x + 2][y + 2] = 1;

				if (flag == 1) {
					p2 = p2 + 10;
					printf("diagonal forward(%d,%d) : p2 = %d \n", x, y, p2);

				}
				else if (flag == 2) {
					p1 = p1 + 10;
					printf("diagonal forward(%d,%d) : p1 = %d \n", x, y, p1);
				}
			}
			else {
				continue;
			}
		}
	}
	for (x = 2; x<6; x++) {
		for (y = 0; y<4; y++) {
			if (matrix[x][y] != 0 && matrix[x][y] == matrix[x - 1][y + 1] && matrix[x][y] == matrix[x - 2][y + 2] && occupy_d2[x][y] != 3 && occupy_d2[x - 1][y + 1] != 3 && occupy_d2[x - 2][y + 2] != 3) {
				occupy_d2[x][y] = 3;
				occupy_d2[x - 1][y + 1] = 3;
				occupy_d2[x - 2][y + 2] = 3;

				if (flag == 1) {
					p2 = p2 + 10;
					printf("diagonal backward(%d,%d) : p2 = %d \n", x, y, p2);
					
				}
				else if (flag == 2) {
					p1 = p1 + 10;
					printf("diagonal backward(%d,%d) : p1 = %d \n", x, y, p1);

				}
			}

			else {
				continue;
			}
		}
	}
}
