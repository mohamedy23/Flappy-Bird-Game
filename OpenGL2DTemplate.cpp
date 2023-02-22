










#include <iostream>
#include <random>
#include <stdio.h>
#include <string.h>
#include <glut.h>
#include<time.h>

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;
const int NUM_COLUMNS = 300;
const int RADNOM_HEIGHT_RANGE = 100;

float xSteps = 0.0f;
float randomHeightValues[NUM_COLUMNS];

bool jumping = false;

float playerPosition = 360;
float xPlayer = 200;

class Object
{
public:
	void ShowTriangle();
	void ShowSquare();
	void ShowPlayer();
	void CreateBarrier();
	float width, height;
	float x, y;
	float r, g, b;

	void SetPosition(float x, float y);
	void SetColor(float r, float g, float b);
	void SetWidthHeight(float width, float height);
};




void Object::ShowTriangle()
{
	glBegin(GL_TRIANGLES);
	glColor3f(r, g, b);
	glVertex3f(x, y, 0.0f);
	glVertex3f(x + width, y, 0.0f);
	glVertex3f(x + width / 2, y + height, 0.0f);
	glEnd();
}

void Object::ShowSquare()
{
	glBegin(GL_QUADS);
	glColor3f(r, g, b);
	glVertex3f(x, y, 0.0f);
	glVertex3f(x + width, y, 0.0f);
	glVertex3f(x + width, y + height, 0.0f);
	glVertex3f(x, y + height, 0.0f);
	glEnd();
}

void Object::ShowPlayer()
{
	glPushMatrix();

	//glTranslatef(0.0f, playerPosition, 0.0f);

	glBegin(GL_QUADS);
	glColor3f(r, g, b);
	glVertex3f(x, y, 0.0f);
	glVertex3f(x + width, y, 0.0f);
	glVertex3f(x + width, y + height, 0.0f);
	glVertex3f(x, y + height, 0.0f);
	glEnd();

	glLineWidth(5.0f);
	glBegin(GL_LINES);
	glColor3f(0.5 - r, g + 0.3f, b + 0.35f);
	glVertex3f(x + 10, y + 20, 0.0f);
	glVertex3f(x, y, 0.0f);
	glEnd();

	glLineWidth(5.0f);
	glBegin(GL_LINES);
	glColor3f(0.5 - r, g + 0.3f, b + 0.35f);
	glVertex3f(x + 40, y + 20, 0.0f);
	glVertex3f(x + 30, y, 0.0f);
	glEnd();

	glLineWidth(5.0f);
	glBegin(GL_TRIANGLES);
	glColor3f(0.2 - r, g + 0.6f, b + 0.6f);
	glVertex3f(x + width, y + height, 0.0f);
	glVertex3f(x + width - 10, y + height - 10, 0.0f);
	glVertex3f(x + width, y + height - 10, 0.0f);
	glEnd();

	glPopMatrix();
}

void Object::SetPosition(float x, float y)
{
	this->x = x;
	this->y = y;
}

void Object::SetColor(float r, float g, float b)
{
	this->r = r;
	this->g = g;
	this->b = b;
}

void Object::SetWidthHeight(float width, float height)
{
	this->width = width;
	this->height = height;
}

void Object::CreateBarrier()
{


}

float x_position = 500;
float y_positionUP = 0;
float y_positionDOWN = 360;
float set1y=400;
bool ff = false;
//GLboolean set2 = false;
float ySet1 = 100;
//float array1[18] = { (int)(y_positionUP + 75 * 1 + 50) % 360,(int)(y_positionUP + 75 * 2 + 50) % 360,(int)(y_positionUP + 75 * 3 + 50) % 360,
//((int)(y_positionDOWN + 1 * 50)) % 720 ,((int)(y_positionDOWN + 2 * 50)) % 720 ,((int)(y_positionDOWN + 3 * 50)) % 720,
//360 - ((4 - 3) * 25) ,360 - ((5 - 3) * 25) ,360 - ((6 - 3) * 25),
//720 - 4 * 50 ,720 - 5 * 50 ,720 - 6 * 50,
//400,550,200,300,360,450};
//array.push_back ((int)(y_positionUP + 75 * 1 + 50) % 360);

void print(int x, int y, char* string)
{
	int len, i;

	//set the position of the text in the window using the x and y coordinates
	glRasterPos2f(x, y);

	//get the length of the string to display
	len = (int)strlen(string);

	//loop to display character by character
	for (i = 0; i < len; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
	}
}


size_t i = 0;
int lives = 3;
int score = 0;

int random = 0;
bool chosen = false;
bool powerUp = false;
bool set1Colored = false;
bool set2Colored = false;
bool set3Colored = false;
bool gameOver = false;
int ran;
int ran2;
int ran3;
void Display() {

	
	
	glClear(GL_COLOR_BUFFER_BIT);
	
	for (size_t i = 0; i < 10; i++)
	{
		
		int pos = 300;
		int j = 0;

		 if(i>=1 && i<4){

			if (i == 1 ) {
				glBegin(GL_QUADS);
				if (set1Colored == true)glColor3f(0, 1, 1);
				else glColor3f(0, 1, 0);
				glVertex3f(x_position + i * 300, 0, 0.0f);
				glVertex3f(x_position + 100 + i * 300, 0, 0.0f);
				glVertex3f(x_position + 100 + i * 300, 200, 0.0f);
				glVertex3f(x_position + i * 300, 200, 0.0f);
				glEnd();

				glBegin(GL_QUADS);
				if (set1Colored == true)glColor3f(0, 1, 1);
				else glColor3f(0, 1, 0);
				glVertex3f(x_position + i * 300, 300, 0.0f);
				glVertex3f(x_position + 100 + i * 300, 300, 0.0f);
				glVertex3f(x_position + 100 + i * 300,720, 0.0f);
				glVertex3f(x_position + i * 300, 720, 0.0f);
				glEnd();
				if (ran == 1) {
					glLineWidth(5.0f);
					glBegin(GL_LINES);
					glColor3f(1, 0, 0);
					glVertex3f(x_position + i * 300 + 50, 0, 0.0f);
					glVertex3f(x_position + i * 300 + 50, 200, 0.0f);
					glEnd();
					glLineWidth(5.0f);
					glBegin(GL_LINES);
					glColor3f(1, 0, 0);
					glVertex3f(x_position + i * 300 + 50, 300, 0.0f);
					glVertex3f(x_position + i * 300 + 50, 720, 0.0f);
					glEnd();
				}
				else if (ran == 2) {
					glBegin(GL_TRIANGLES);
					glColor3f(1, 0, 0);
					glVertex3f(x_position + i * 300, 200, 0.0f);
					glVertex3f(x_position + i * 300 + 50, 150, 0.0f);
					glVertex3f(x_position + i * 300 + 100, 200, 0.0f);
					glEnd();
					glBegin(GL_TRIANGLES);
					glColor3f(1, 0, 0);
					glVertex3f(x_position + i * 300, 300, 0.0f);
					glVertex3f(x_position + i * 300 + 50, 350, 0.0f);
					glVertex3f(x_position + i * 300 + 100, 300, 0.0f);
					glEnd();
				}
				else {
					glLineWidth(5.0f);
					glBegin(GL_LINES);
					glColor3f(1, 0, 0);
					glVertex3f(x_position + i * 300 , 100, 0.0f);
					glVertex3f(x_position + i * 300 + 100, 100, 0.0f);
					glEnd();
					glLineWidth(5.0f);
					glBegin(GL_LINES);
					glColor3f(1, 0, 0);
					glVertex3f(x_position + i * 300 , 510, 0.0f);
					glVertex3f(x_position + i * 300 + 100, 510, 0.0f);
					glEnd();
				}
				


				/*glBegin(GL_LINES);
				glColor3f(1,0,0);
				glVertex3f(0, y + 20, 0.0f);
				glVertex3f(x, y, 0.0f);
				glEnd();*/

				if(random==i){
					glBegin(GL_QUADS);
					glColor3f(0, 1, 0);
					glVertex3f(x_position + i * 300, 250, 0.0f);
					glVertex3f(x_position + 10 + i * 300, 250, 0.0f);
					glVertex3f(x_position + 10 + i * 300, 260, 0.0f);
					glVertex3f(x_position + i * 300, 260, 0.0f);
					glEnd();
					glLineWidth(2.0f);
					glBegin(GL_LINES);
					glColor3f(1, 0, 0);
					glVertex3f(x_position + i * 300 + 5, 250, 0.0f);
					glVertex3f(x_position + i * 300 + 5, 260, 0.0f);
					glEnd();
				}
				

		 }
			if (i == 2) {
				glBegin(GL_QUADS);
				if(set1Colored==true)glColor3f(0, 1, 1);
				else glColor3f(0, 1, 0);
				glVertex3f(x_position + i * 300, 0, 0.0f);
				glVertex3f(x_position + 100 + i * 300, 0, 0.0f);
				glVertex3f(x_position + 100 + i * 300, 350, 0.0f);
				glVertex3f(x_position + i * 300, 350, 0.0f);
				glEnd();

				glBegin(GL_QUADS);
				if (set1Colored == true)glColor3f(0, 1, 1);
				else glColor3f(0, 1, 0);
				glVertex3f(x_position + i * 300, 450, 0.0f);
				glVertex3f(x_position + 100 + i * 300, 450, 0.0f);
				glVertex3f(x_position + 100 + i * 300, 720, 0.0f);
				glVertex3f(x_position + i * 300, 720, 0.0f);
				glEnd();
                if(ran==1){
					glLineWidth(5.0f);
					glBegin(GL_LINES);
					glColor3f(1, 0, 0);
					glVertex3f(x_position + i * 300 + 50, 0, 0.0f);
					glVertex3f(x_position + i * 300 + 50, 350, 0.0f);
					glEnd(); glLineWidth(5.0f);
					glBegin(GL_LINES);
					glColor3f(1, 0, 0);
					glVertex3f(x_position + i * 300 + 50, 450, 0.0f);
					glVertex3f(x_position + i * 300 + 50, 720, 0.0f);
					glEnd();
				}
				else if(ran==2) {
					glBegin(GL_TRIANGLES);
					glColor3f(1, 0, 0);
					glVertex3f(x_position + i * 300, 350, 0.0f);
					glVertex3f(x_position + i * 300 + 50, 300, 0.0f);
					glVertex3f(x_position + i * 300 + 100, 350, 0.0f);
					glEnd();
					glBegin(GL_TRIANGLES);
					glColor3f(1, 0, 0);
					glVertex3f(x_position + i * 300, 450, 0.0f);
					glVertex3f(x_position + i * 300 + 50, 500, 0.0f);
					glVertex3f(x_position + i * 300 + 100, 450, 0.0f);
					glEnd();
				}
				else {
					glLineWidth(5.0f);
					glBegin(GL_LINES);
					glColor3f(1, 0, 0);
					glVertex3f(x_position + i * 300, 175, 0.0f);
					glVertex3f(x_position + i * 300 + 100, 175, 0.0f);
					glEnd();
					glLineWidth(5.0f);
					glBegin(GL_LINES);
					glColor3f(1, 0, 0);
					glVertex3f(x_position + i * 300, 510, 0.0f);
					glVertex3f(x_position + i * 300 + 100, 510, 0.0f);
					glEnd();
				}
				


				if (random == i) {
					glBegin(GL_QUADS);
					glColor3f(0, 1, 0);
					glVertex3f(x_position + i * 300, 400, 0.0f);
					glVertex3f(x_position + 10 + i * 300, 400, 0.0f);
					glVertex3f(x_position + 10 + i * 300, 410, 0.0f);
					glVertex3f(x_position + i * 300, 410, 0.0f);
					glEnd();
				}

			}
			if (i == 3) {
				glBegin(GL_QUADS);
				if (set1Colored == true)glColor3f(0, 1, 1);
				else glColor3f(0, 1, 0);
				glVertex3f(x_position + i * 300, 0, 0.0f);
				glVertex3f(x_position + 100 + i * 300, 0, 0.0f);
				glVertex3f(x_position + 100 + i * 300, 500, 0.0f);
				glVertex3f(x_position + i * 300, 500, 0.0f);
				glEnd();

				glBegin(GL_QUADS);
				if (set1Colored == true)glColor3f(0, 1, 1);
				else glColor3f(0, 1, 0);
				glVertex3f(x_position + i * 300, 600, 0.0f);
				glVertex3f(x_position + 100 + i * 300, 600, 0.0f);
				glVertex3f(x_position + 100 + i * 300, 720, 0.0f);
				glVertex3f(x_position + i * 300, 720, 0.0f);
				glEnd();
				if(ran==1){
					glLineWidth(5.0f);
					glBegin(GL_LINES);
					glColor3f(1, 0, 0);
					glVertex3f(x_position + i * 300 + 50, 0, 0.0f);
					glVertex3f(x_position + i * 300 + 50, 500, 0.0f);
					glEnd(); glLineWidth(5.0f);
					glBegin(GL_LINES);
					glColor3f(1, 0, 0);
					glVertex3f(x_position + i * 300 + 50, 600, 0.0f);
					glVertex3f(x_position + i * 300 + 50, 720, 0.0f);
					glEnd();
				}
				else if(ran==2) {
					glBegin(GL_TRIANGLES);
					glColor3f(1, 0, 0);
					glVertex3f(x_position + i * 300, 500, 0.0f);
					glVertex3f(x_position + i * 300 + 50, 450, 0.0f);
					glVertex3f(x_position + i * 300 + 100, 500, 0.0f);
					glEnd();
					glBegin(GL_TRIANGLES);
					glColor3f(1, 0, 0);
					glVertex3f(x_position + i * 300, 600, 0.0f);
					glVertex3f(x_position + i * 300 + 50, 650, 0.0f);
					glVertex3f(x_position + i * 300 + 100, 600, 0.0f);
					glEnd();
				}
				else {
					glLineWidth(5.0f);
					glBegin(GL_LINES);
					glColor3f(1, 0, 0);
					glVertex3f(x_position + i * 300, 250, 0.0f);
					glVertex3f(x_position + i * 300 + 100, 250, 0.0f);
					glEnd();
					glLineWidth(5.0f);
					glBegin(GL_LINES);
					glColor3f(1, 0, 0);
					glVertex3f(x_position + i * 300, 660, 0.0f);
					glVertex3f(x_position + i * 300 + 100, 660, 0.0f);
					glEnd();
				}
			    



				if (random == i) {
					glBegin(GL_QUADS);
					glColor3f(0, 1, 0);
					glVertex3f(x_position + i * 300, 550, 0.0f);
					glVertex3f(x_position + 10 + i * 300, 550, 0.0f);
					glVertex3f(x_position + 10 + i * 300, 560, 0.0f);
					glVertex3f(x_position + i * 300, 560, 0.0f);
					glEnd();
				}

			}


		/*glBegin(GL_QUADS);
		glColor3f(0, 1, 0);
		glVertex3f(x_position + i * 300, 0, 0.0f);
		glVertex3f(x_position + 100 + i * 300, 0, 0.0f);
		glVertex3f(x_position + 100 + i * 300,(int) (y_positionUP+75*i+50)%360, 0.0f);
		glVertex3f(x_position + i * 300, (int)(y_positionUP + 75 * i+50)%360, 0.0f);
		glEnd();
		

		glBegin(GL_QUADS);
		glColor3f(0, 1, 0);
		glVertex3f(x_position + i * 300, ( (int)(y_positionDOWN +i*50))%720, 0.0f);
		glVertex3f(x_position + 100 + i * 300, ((int)(y_positionDOWN + i * 50)) % 720, 0.0f);
		glVertex3f(x_position + 100 + i * 300, 720, 0.0f);
		glVertex3f(x_position + i * 300, 720, 0.0f);
		glEnd();*/

		//array[j++] = (int)(y_positionUP + 75 * i + 50) % 360;
	    //array[j++] = ((int)(y_positionDOWN + i * 50)) % 720;
		
		}
		
		 if (i > 3 && i <= 6) {
			
			 if (i == 4) {
				 glBegin(GL_QUADS);
				 if (set2Colored == true)glColor3f(0, 1, 1);
				 else glColor3f(0, 1, 0);
				 glVertex3f(x_position + i * 300, 0, 0.0f);
				 glVertex3f(x_position + 100 + i * 300, 0, 0.0f);
				 glVertex3f(x_position + 100 + i * 300, 450, 0.0f);
				 glVertex3f(x_position + i * 300, 450, 0.0f);
				 glEnd();

				 glBegin(GL_QUADS);
				 if (set2Colored == true)glColor3f(0, 1, 1);
				 else glColor3f(0, 1, 0);
				 glVertex3f(x_position + i * 300, 550, 0.0f);
				 glVertex3f(x_position + 100 + i * 300, 550, 0.0f);
				 glVertex3f(x_position + 100 + i * 300, 720, 0.0f);
				 glVertex3f(x_position + i * 300, 720, 0.0f);
				 glEnd();
				 if(ran==1){
					 glBegin(GL_TRIANGLES);
					 glColor3f(1, 0, 0);
					 glVertex3f(x_position + i * 300, 450, 0.0f);
					 glVertex3f(x_position + i * 300 + 50, 400, 0.0f);
					 glVertex3f(x_position + i * 300 + 100, 450, 0.0f);
					 glEnd();
					 glBegin(GL_TRIANGLES);
					 glColor3f(1, 0, 0);
					 glVertex3f(x_position + i * 300, 550, 0.0f);
					 glVertex3f(x_position + i * 300 + 50, 600, 0.0f);
					 glVertex3f(x_position + i * 300 + 100, 550, 0.0f);
					 glEnd();
					 
				 }
				 else if(ran==2) {
					 glLineWidth(5.0f);
					 glBegin(GL_LINES);
					 glColor3f(1, 0, 0);
					 glVertex3f(x_position + i * 300, 250, 0.0f);
					 glVertex3f(x_position + i * 300 + 100, 250, 0.0f);
					 glEnd();
					 glLineWidth(5.0f);
					 glBegin(GL_LINES);
					 glColor3f(1, 0, 0);
					 glVertex3f(x_position + i * 300, 660, 0.0f);
					 glVertex3f(x_position + i * 300 + 100, 660, 0.0f);
					 glEnd();
				 }
				 else {
					 glLineWidth(5.0f);
					 glBegin(GL_LINES);
					 glColor3f(1, 0, 0);
					 glVertex3f(x_position + i * 300 + 50, 0, 0.0f);
					 glVertex3f(x_position + i * 300 + 50, 450, 0.0f);
					 glEnd(); glLineWidth(5.0f);
					 glBegin(GL_LINES);
					 glColor3f(1, 0, 0);
					 glVertex3f(x_position + i * 300 + 50, 550, 0.0f);
					 glVertex3f(x_position + i * 300 + 50, 720, 0.0f);
					 glEnd();
				 }
				 

				 if (random == i) {
					 glBegin(GL_QUADS);
					 glColor3f(0, 1, 0);
					 glVertex3f(x_position + i * 300, 500, 0.0f);
					 glVertex3f(x_position + 10 + i * 300, 500, 0.0f);
					 glVertex3f(x_position + 10 + i * 300, 510, 0.0f);
					 glVertex3f(x_position + i * 300, 510, 0.0f);
					 glEnd();
					 glLineWidth(2.0f);
					 glBegin(GL_LINES);
					 glColor3f(1, 0, 0);
					 glVertex3f(x_position + i * 300 + 5, 500, 0.0f);
					 glVertex3f(x_position + i * 300 + 5, 510, 0.0f);
					 glEnd();
				 }
			 }
			 if (i == 5) {
				 glBegin(GL_QUADS);
				 if (set2Colored == true)glColor3f(0, 1, 1);
				 else glColor3f(0, 1, 0);
				 glVertex3f(x_position + i * 300, 0, 0.0f);
				 glVertex3f(x_position + 100 + i * 300, 0, 0.0f);
				 glVertex3f(x_position + 100 + i * 300, 350, 0.0f);
				 glVertex3f(x_position + i * 300, 350, 0.0f);
				 glEnd();

				 glBegin(GL_QUADS);
				 if (set2Colored == true)glColor3f(0, 1, 1);
				 else glColor3f(0, 1, 0);
				 glVertex3f(x_position + i * 300, 500, 0.0f);
				 glVertex3f(x_position + 100 + i * 300, 500, 0.0f);
				 glVertex3f(x_position + 100 + i * 300, 720, 0.0f);
				 glVertex3f(x_position + i * 300, 720, 0.0f);
				 glEnd();
				 if(ran==1){
					 glBegin(GL_TRIANGLES);
					 glColor3f(1, 0, 0);
					 glVertex3f(x_position + i * 300, 350, 0.0f);
					 glVertex3f(x_position + i * 300 + 50, 300, 0.0f);
					 glVertex3f(x_position + i * 300 + 100, 350, 0.0f);
					 glEnd();
					 glBegin(GL_TRIANGLES);
					 glColor3f(1, 0, 0);
					 glVertex3f(x_position + i * 300, 500, 0.0f);
					 glVertex3f(x_position + i * 300 + 50, 550, 0.0f);
					 glVertex3f(x_position + i * 300 + 100, 500, 0.0f);
					 glEnd();
					
				 }
				 else if(ran==2){
					 glLineWidth(5.0f);
					 glBegin(GL_LINES);
					 glColor3f(1, 0, 0);
					 glVertex3f(x_position + i * 300, 250, 0.0f);
					 glVertex3f(x_position + i * 300 + 100, 250, 0.0f);
					 glEnd();
					 glLineWidth(5.0f);
					 glBegin(GL_LINES);
					 glColor3f(1, 0, 0);
					 glVertex3f(x_position + i * 300, 660, 0.0f);
					 glVertex3f(x_position + i * 300 + 100, 660, 0.0f);
					 glEnd();
				 }
				 else {
					 glLineWidth(5.0f);
					 glBegin(GL_LINES);
					 glColor3f(1, 0, 0);
					 glVertex3f(x_position + i * 300 + 50, 0, 0.0f);
					 glVertex3f(x_position + i * 300 + 50, 350, 0.0f);
					 glEnd();
					 glLineWidth(5.0f);
					 glBegin(GL_LINES);
					 glColor3f(1, 0, 0);
					 glVertex3f(x_position + i * 300 + 50, 500, 0.0f);
					 glVertex3f(x_position + i * 300 + 50, 720, 0.0f);
					 glEnd();
				 }
				 

				 if (random == i) {
					 glBegin(GL_QUADS);
					 glColor3f(0, 1, 0);
					 glVertex3f(x_position + i * 300, 400, 0.0f);
					 glVertex3f(x_position + 10 + i * 300, 400, 0.0f);
					 glVertex3f(x_position + 10 + i * 300, 410, 0.0f);
					 glVertex3f(x_position + i * 300, 410, 0.0f);
					 glEnd();
				 }
			 }
			 if (i == 6) {
				 glBegin(GL_QUADS);
				 if (set2Colored == true)glColor3f(0, 1, 1);
				 else  glColor3f(0, 1, 0);
				 glVertex3f(x_position + i * 300, 0, 0.0f);
				 glVertex3f(x_position + 100 + i * 300, 0, 0.0f);
				 glVertex3f(x_position + 100 + i * 300, 200, 0.0f);
				 glVertex3f(x_position + i * 300, 200, 0.0f);
				 glEnd();

				 glBegin(GL_QUADS);
				 if (set2Colored == true)glColor3f(0, 1, 1);
				 else glColor3f(0, 1, 0);
				 glVertex3f(x_position + i * 300, 300, 0.0f);
				 glVertex3f(x_position + 100 + i * 300, 300, 0.0f);
				 glVertex3f(x_position + 100 + i * 300, 720, 0.0f);
				 glVertex3f(x_position + i * 300, 720, 0.0f);
				 glEnd();
				 if(ran==1){
					 glBegin(GL_TRIANGLES);
					 glColor3f(1, 0, 0);
					 glVertex3f(x_position + i * 300, 200, 0.0f);
					 glVertex3f(x_position + i * 300 + 50, 150, 0.0f);
					 glVertex3f(x_position + i * 300 + 100, 200, 0.0f);
					 glEnd();
					 glBegin(GL_TRIANGLES);
					 glColor3f(1, 0, 0);
					 glVertex3f(x_position + i * 300, 300, 0.0f);
					 glVertex3f(x_position + i * 300 + 50, 350, 0.0f);
					 glVertex3f(x_position + i * 300 + 100, 300, 0.0f);
					 glEnd();
					 
				 }
				 else if(ran==2) {
					 glLineWidth(5.0f);
					 glBegin(GL_LINES);
					 glColor3f(1, 0, 0);
					 glVertex3f(x_position + i * 300, 100, 0.0f);
					 glVertex3f(x_position + i * 300 + 100, 100, 0.0f);
					 glEnd();
					 glLineWidth(5.0f);
					 glBegin(GL_LINES);
					 glColor3f(1, 0, 0);
					 glVertex3f(x_position + i * 300, 660, 0.0f);
					 glVertex3f(x_position + i * 300 + 100, 660, 0.0f);
					 glEnd();
				 }
				 else {
					 glLineWidth(5.0f);
					 glBegin(GL_LINES);
					 glColor3f(1, 0, 0);
					 glVertex3f(x_position + i * 300 + 50, 0, 0.0f);
					 glVertex3f(x_position + i * 300 + 50, 200, 0.0f);
					 glEnd();
					 glLineWidth(5.0f);
					 glBegin(GL_LINES);
					 glColor3f(1, 0, 0);
					 glVertex3f(x_position + i * 300 + 50, 300, 0.0f);
					 glVertex3f(x_position + i * 300 + 50, 720, 0.0f);
					 glEnd();
				 }
				 
				 if (random == i) {
					 glBegin(GL_QUADS);
					 glColor3f(0, 1, 0);
					 glVertex3f(x_position + i * 300, 250, 0.0f);
					 glVertex3f(x_position + 10 + i * 300, 250, 0.0f);
					 glVertex3f(x_position + 10 + i * 300, 260, 0.0f);
					 glVertex3f(x_position + i * 300, 260, 0.0f);
					 glEnd();
				 }
			 }

			//increasing the height
			/*glBegin(GL_QUADS);
			glColor3f(0, 1, 0);
			glVertex3f(x_position + i * 300, 0, 0.0f);
			glVertex3f(x_position + 100 + i * 300, 0, 0.0f);
			glVertex3f(x_position + 100 + i * 300, 360-( (i-3)*25), 0.0f);
			glVertex3f(x_position + i * 300, 360 - ( (i-3) * 25), 0.0f);
			glEnd();

			glBegin(GL_QUADS);
			glColor3f(0, 1, 0);
			glVertex3f(x_position + i * 300, 720-i*50, 0.0f);
			glVertex3f(x_position + 100 + i * 300, 720 - i * 50, 0.0f);
			glVertex3f(x_position + 100 + i * 300, 720, 0.0f);
			glVertex3f(x_position + i * 300, 720, 0.0f);
			glEnd();*/

			//array[j++] = 360 - ((i - 3) * 25);
			//array[j++] = 720 - i * 50;

		}
		
		 if (i>6 && i<=9) {

			if (i == 7) {
				glBegin(GL_QUADS);
				if (set3Colored == true)glColor3f(0, 1, 1);
				else glColor3f(0, 1, 0);
				glVertex3f(x_position + i * 300, 0, 0.0f);
				glVertex3f(x_position + 100 + i * 300, 0, 0.0f);
				glVertex3f(x_position + 100 + i * 300, 400, 0.0f);
				glVertex3f(x_position + i * 300, 400, 0.0f);
				glEnd();

				glBegin(GL_QUADS);
				if (set3Colored == true)glColor3f(0, 1, 1);
				else glColor3f(0, 1, 0);
				glVertex3f(x_position + i * 300, 550, 0.0f);
				glVertex3f(x_position + 100 + i * 300, 550, 0.0f);
				glVertex3f(x_position + 100 + i * 300, 720, 0.0f);
				glVertex3f(x_position + i * 300, 720, 0.0f);
				glEnd();
				if (ran == 1) {
					glLineWidth(5.0f);
					glBegin(GL_LINES);
					glColor3f(1, 0, 0);
					glVertex3f(x_position + i * 300, 200, 0.0f);
					glVertex3f(x_position + i * 300 + 100, 200, 0.0f);
					glEnd();
					glLineWidth(5.0f);
					glBegin(GL_LINES);
					glColor3f(1, 0, 0);
					glVertex3f(x_position + i * 300, 660, 0.0f);
					glVertex3f(x_position + i * 300 + 100, 660, 0.0f);
					glEnd();
				}
				else if (ran == 2) {
					glLineWidth(5.0f);
					glBegin(GL_LINES);
					glColor3f(1, 0, 0);
					glVertex3f(x_position + i * 300 + 50, 0, 0.0f);
					glVertex3f(x_position + i * 300 + 50, 400, 0.0f);
					glEnd(); glLineWidth(5.0f);
					glBegin(GL_LINES);
					glColor3f(1, 0, 0);
					glVertex3f(x_position + i * 300 + 50, 550, 0.0f);
					glVertex3f(x_position + i * 300 + 50, 720, 0.0f);
					glEnd();
				}
				else {
					glBegin(GL_TRIANGLES);
					glColor3f(1, 0, 0);
					glVertex3f(x_position + i * 300, 400, 0.0f);
					glVertex3f(x_position + i * 300 + 50, 350, 0.0f);
					glVertex3f(x_position + i * 300 + 100, 400, 0.0f);
					glEnd();
					glBegin(GL_TRIANGLES);
					glColor3f(1, 0, 0);
					glVertex3f(x_position + i * 300, 550, 0.0f);
					glVertex3f(x_position + i * 300 + 50, 600, 0.0f);
					glVertex3f(x_position + i * 300 + 100, 550, 0.0f);
					glEnd();
				}
				

				if (random == i) {
					glBegin(GL_QUADS);
					glColor3f(0, 1, 0);
					glVertex3f(x_position + i * 300, 450, 0.0f);
					glVertex3f(x_position + 10 + i * 300, 450, 0.0f);
					glVertex3f(x_position + 10 + i * 300, 460, 0.0f);
					glVertex3f(x_position + i * 300, 460, 0.0f);
					glEnd();
					glLineWidth(2.0f);
					glBegin(GL_LINES);
					glColor3f(1, 0, 0);
					glVertex3f(x_position + i * 300 + 5, 450, 0.0f);
					glVertex3f(x_position + i * 300 + 5, 460, 0.0f);
					glEnd();
				}

				/*array[j++] = 400;
				array[j++] = 550;*/
			}
			else if (i == 8) {

				glBegin(GL_QUADS);
				if (set3Colored == true)glColor3f(0, 1, 1);
				else glColor3f(0, 1, 0);
				glVertex3f(x_position + i * 300, 0, 0.0f);
				glVertex3f(x_position + 100 + i * 300, 0, 0.0f);
				glVertex3f(x_position + 100 + i * 300, 200, 0.0f);
				glVertex3f(x_position + i * 300, 200, 0.0f);
				glEnd();

				glBegin(GL_QUADS);
				if (set3Colored == true)glColor3f(0, 1, 1);
				else glColor3f(0, 1, 0);
				glVertex3f(x_position + i * 300, 300, 0.0f);
				glVertex3f(x_position + 100 + i * 300, 300, 0.0f);
				glVertex3f(x_position + 100 + i * 300, 720, 0.0f);
				glVertex3f(x_position + i * 300, 720, 0.0f);
				glEnd();
				if (ran == 1) {
					glLineWidth(5.0f);
					glBegin(GL_LINES);
					glColor3f(1, 0, 0);
					glVertex3f(x_position + i * 300, 100, 0.0f);
					glVertex3f(x_position + i * 300 + 100, 100, 0.0f);
					glEnd();
					glLineWidth(5.0f);
					glBegin(GL_LINES);
					glColor3f(1, 0, 0);
					glVertex3f(x_position + i * 300, 660, 0.0f);
					glVertex3f(x_position + i * 300 + 100, 660, 0.0f);
					glEnd();
				}
				else if (ran == 2) {
					glLineWidth(5.0f);
					glBegin(GL_LINES);
					glColor3f(1, 0, 0);
					glVertex3f(x_position + i * 300 + 50, 0, 0.0f);
					glVertex3f(x_position + i * 300 + 50, 200, 0.0f);
					glEnd(); glLineWidth(5.0f);
					glBegin(GL_LINES);
					glColor3f(1, 0, 0);
					glVertex3f(x_position + i * 300 + 50, 300, 0.0f);
					glVertex3f(x_position + i * 300 + 50, 720, 0.0f);
					glEnd();
				}
				else {
					glBegin(GL_TRIANGLES);
					glColor3f(1, 0, 0);
					glVertex3f(x_position + i * 300, 200, 0.0f);
					glVertex3f(x_position + i * 300 + 50, 150, 0.0f);
					glVertex3f(x_position + i * 300 + 100, 200, 0.0f);
					glEnd();
					glBegin(GL_TRIANGLES);
					glColor3f(1, 0, 0);
					glVertex3f(x_position + i * 300, 300, 0.0f);
					glVertex3f(x_position + i * 300 + 50, 350, 0.0f);
					glVertex3f(x_position + i * 300 + 100, 300, 0.0f);
					glEnd();
				}
				
				if (random == i) {
					glBegin(GL_QUADS);
					glColor3f(0, 1, 0);
					glVertex3f(x_position + i * 300, 250, 0.0f);
					glVertex3f(x_position + 10 + i * 300, 250, 0.0f);
					glVertex3f(x_position + 10 + i * 300, 260, 0.0f);
					glVertex3f(x_position + i * 300, 260, 0.0f);
					glEnd();
				}

				/*array[j++] = 200;
				array[j++] = 300;*/
			}

			else {
				glBegin(GL_QUADS);
				if (set3Colored == true)glColor3f(0, 1, 1);
				else glColor3f(0, 1, 0);
				glVertex3f(x_position + i * 300, 0, 0.0f);
				glVertex3f(x_position + 100 + i * 300, 0, 0.0f);
				glVertex3f(x_position + 100 + i * 300, 360, 0.0f);
				glVertex3f(x_position + i * 300, 360, 0.0f);
				glEnd();

				glBegin(GL_QUADS);
				if (set3Colored == true)glColor3f(0, 1, 1);
				else glColor3f(0, 1, 0);
				glVertex3f(x_position + i * 300, 450, 0.0f);
				glVertex3f(x_position + 100 + i * 300, 450, 0.0f);
				glVertex3f(x_position + 100 + i * 300, 720, 0.0f);
				glVertex3f(x_position + i * 300, 720, 0.0f);
				glEnd();
				if (ran == 1) {
					glLineWidth(5.0f);
					glBegin(GL_LINES);
					glColor3f(1, 0, 0);
					glVertex3f(x_position + i * 300, 200, 0.0f);
					glVertex3f(x_position + i * 300 + 100, 200, 0.0f);
					glEnd();
					glLineWidth(5.0f);
					glBegin(GL_LINES);
					glColor3f(1, 0, 0);
					glVertex3f(x_position + i * 300, 660, 0.0f);
					glVertex3f(x_position + i * 300 + 100, 660, 0.0f);
					glEnd();
				}
				else if (ran == 2) {
					glLineWidth(5.0f);
					glBegin(GL_LINES);
					glColor3f(1, 0, 0);
					glVertex3f(x_position + i * 300 + 50, 0, 0.0f);
					glVertex3f(x_position + i * 300 + 50, 360, 0.0f);
					glEnd(); glLineWidth(5.0f);
					glBegin(GL_LINES);
					glColor3f(1, 0, 0);
					glVertex3f(x_position + i * 300 + 50, 450, 0.0f);
					glVertex3f(x_position + i * 300 + 50, 720, 0.0f);
					glEnd();
				}
				else {
					glBegin(GL_TRIANGLES);
					glColor3f(1, 0, 0);
					glVertex3f(x_position + i * 300, 360, 0.0f);
					glVertex3f(x_position + i * 300 + 50, 310, 0.0f);
					glVertex3f(x_position + i * 300 + 100, 360, 0.0f);
					glEnd();
					glBegin(GL_TRIANGLES);
					glColor3f(1, 0, 0);
					glVertex3f(x_position + i * 300, 450, 0.0f);
					glVertex3f(x_position + i * 300 + 50, 500, 0.0f);
					glVertex3f(x_position + i * 300 + 100, 450, 0.0f);
					glEnd();
				}
				
				if (random == i) {
					glBegin(GL_QUADS);
					glColor3f(0, 1, 0);
					glVertex3f(x_position + i * 300, 400, 0.0f);
					glVertex3f(x_position + 10 + i * 300, 400, 0.0f);
					glVertex3f(x_position + 10 + i * 300, 410, 0.0f);
					glVertex3f(x_position + i * 300, 410, 0.0f);
					glEnd();
				}

				/*array[j++] = 360;
				array[j++] = 450;*/

			}
			/*glBegin(GL_QUADS);
			glColor3f(0, 1, 0);
			glVertex3f(x_position + i * 300, 550, 0.0f);
			glVertex3f(x_position + 100 + i * 300, 550, 0.0f);
			glVertex3f(x_position + 100 + i * 300, 720, 0.0f);
			glVertex3f(x_position + i * 300, 720, 0.0f);
			glEnd();*/

		}
		 
		
		
		
		
		/*glBegin(GL_QUADS);
		glColor3f(0, 1, 0);
		glVertex3f(x_position + i * 300, 0, 0.0f);
		glVertex3f(x_position + 100 + i * 300, 0, 0.0f);
		glVertex3f(x_position + 100 + i * 300, 0 + 360, 0.0f);
		glVertex3f(x_position + i * 300, 0 + 360, 0.0f);
		glEnd();*/



		/*Object columnUp;
		columnUp.SetPosition((SCREEN_WIDTH / 10 + i * 300) - xSteps, SCREEN_HEIGHT / 2.0f + randomHeightValues[i]);
		columnUp.SetColor(0.15, 0.65, 0.15);
		columnUp.SetWidthHeight(100, 360);
		columnUp.ShowSquare();

		Object columnDown;
		columnDown.SetPosition((SCREEN_WIDTH / 10 + i * 300) - xSteps, -randomHeightValues[i]);
		columnDown.SetColor(0.15, 0.65, 0.15);
		columnDown.SetWidthHeight(100, 360);
		columnDown.ShowSquare();*/
	}
	glColor3f(1, 0, 0);
	char* p1s[20];
	sprintf((char*)p1s, "score: %d", score);
	print(750, 700, (char*)p1s);
	
	

	glColor3f(1, 0, 0);
	char* p0s[20];
	sprintf((char*)p0s, "lives: %d", lives);

	print(650, 700, (char*)p0s);

	if (lives == 0) {
		glColor3f(1, 0, 0);
		char* p2s[20];
		sprintf((char*)p2s, "Game Over: %d", score);
		print(650, 360, (char*)p2s);
	}
	if (xPlayer+25>x_position+100+9*300) {
		glColor3f(1, 0, 0);
		char* p2s[20];
		sprintf((char*)p2s, "Congartulation, You Win!!!!: %d", score);
		print(650, 360, (char*)p2s);
	}
	if (playerPosition+25>=720) {
		glColor3f(1, 0, 0);
		char* p3s[20];
		sprintf((char*)p3s, "You Lose!!!!: %d", score);
		print(650, 360, (char*)p3s);
	}
	if (playerPosition + 25 <= 0) {
		glColor3f(1, 0, 0);
		char* p4s[20];
		sprintf((char*)p4s, "You Lose!!!!: %d", score);
		print(650, 360, (char*)p4s);
	}



	Object player;
	player.SetPosition(xPlayer, playerPosition);
	player.SetColor(1, 1, 0);
	player.SetWidthHeight(25, 25);
	player.ShowPlayer();


	glFlush();
	glutPostRedisplay();
}

//unsigned char string[] = "The quick god jumps over the lazy brown fox.";
//int w;
//w = glutBitmapLength(GLUT_BITMAP_8_BY_13, string);


bool coll = false;


int arr[9] = {200,350,500,500,350,200,400,200,360};

void Time(int val)
{
	Object player;
	if (chosen == false) { 
		
		chosen = true;
	}
	//if (lives == 0)ff = true;
	/*if (playerPosition + 25 >= 720) {
		lives = 0;
	}*/
	
	if (lives>0 &&!(xPlayer + 25 > x_position + 100 + 9 * 300)&&!(playerPosition+25>=720)&&!(playerPosition + 25 <= 0)){
		//coll = false;
		//if (coll == true)score++;
		//coll = false;
		score++;
		std::cout << random << " ";
		glClearColor(0.2f, 0.5f, 0.8f, 0.0f);
		x_position -= 8.0f;
	}
	//check if powerUp is taken for set1
	if (random == 1) {
		if (x_position + 1 * 300 <= xPlayer + 25 && x_position + 100 + 1 * 300 >= xPlayer + 25) {
			if (playerPosition <= 250 && playerPosition + 25 >= 260) {
				//glClearColor(1, 0, 0, 0); 
				random = -1;
				set1Colored = true;
			}
		}
		//if (xPlayer + 25 > x_position + 100 + 3 * 300)set1Colored = false;
	}
	if (random == 4) {
		if (x_position + 4 * 300 <= xPlayer + 25 && x_position + 100 + 4 * 300 >= xPlayer + 25) {
			if (playerPosition <= 500 && playerPosition + 25 >= 510) {
				//glClearColor(1, 0, 0, 0); 
				random = -1;
				set2Colored = true;

			}
		}
	}
	if (random == 7) {
		if (x_position + 7 * 300 <= xPlayer + 25 && x_position + 100 + 7 * 300 >= xPlayer + 25) {
			if (playerPosition <= 450 && playerPosition + 25 >= 460) {
				//glClearColor(1, 0, 0, 0); 
				random = -1;
				set3Colored = true;

			}
		}
	}

	/*if (playerPosition+25==360) {
		lives = 0;
	}*/

	if (x_position + 1 * 300 <= xPlayer + 25 && x_position + 100 + 1 * 300 >= xPlayer + 25){
		if (playerPosition == 200) {
			if(set1Colored==false){
				ff = true;
				coll = true;
				lives--;
				playerPosition += 50;
				glClearColor(1, 0, 1, 0);
			}			
		}
		else if (playerPosition < 200) {
			if(set1Colored==false){
				ff = true;
				coll = true;
				lives--;
				playerPosition += (200 - playerPosition) + 50;
				glClearColor(1, 0, 1, 0);
			}		
		}
		else if (coll == false) {
			//score++; 
		}
	}
	else if (x_position + 2 * 300 <= xPlayer + 25 && x_position + 100 + 2 * 300 >= xPlayer + 25) {
		if (playerPosition == 350) {
			if(set1Colored==false){
				ff = true;
				coll = true;
				lives--;
				playerPosition += 50;
				glClearColor(1, 0, 1, 0);
			}		
		}
		else if (playerPosition < 350) {
			if(set1Colored==false){
				ff = true;
				coll = true;
				lives--;
				playerPosition += (350 - playerPosition) + 50;
				glClearColor(1, 0, 1, 0);
			}		
		}
		

	}
	else if (x_position + 3 * 300 <= xPlayer + 25 && x_position + 100 + 3 * 300 >= xPlayer + 25) {
		if (playerPosition == 500) {
			if(set1Colored==false){
				ff = true;
				coll = true;
				lives--;
				playerPosition += 50;
				glClearColor(1, 0, 1, 0);
			}	
		}
		else if (playerPosition < 500) {
			if(set1Colored==false){
				ff = true;
				coll = true;
				lives--;
				playerPosition += (500 - playerPosition) + 50;
				glClearColor(1, 0, 1, 0);
			}			
		}
		//else score++;

	}
	else if (x_position + 4 * 300 <= xPlayer + 25 && x_position + 100 + 4 * 300 >= xPlayer + 25) {
		if (playerPosition == 450) {
			if(set2Colored==false){
				ff = true;
				coll = true;
				lives--;
				playerPosition += 50;
				glClearColor(1, 0, 1, 0);
			}		
		}
		else if (playerPosition < 450) {
			if(set2Colored==false){
				ff = true;
				coll = true;
				lives--;
				playerPosition += (450 - playerPosition) + 50;
				glClearColor(1, 0, 1, 0);
			}
		}
		//else score++;

	}
	else if (x_position + 5 * 300 <= xPlayer + 25 && x_position + 100 + 5 * 300 >= xPlayer + 25) {
		if (playerPosition == 350) {
			if(set2Colored==false){
				ff = true;
				coll = true;
				lives--;
				playerPosition += 50;
				glClearColor(1, 0, 1, 0);
			}		
		}
		else if (playerPosition < 350) {
			if(set2Colored==false){
				ff = true;
				coll = true;
				lives--;
				playerPosition += (350 - playerPosition) + 50;
				glClearColor(1, 0, 1, 0);
			}
		}
		//else score++;

	}
	else if (x_position + 6 * 300 <= xPlayer + 25 && x_position + 100 + 6 * 300 >= xPlayer + 25) {
		if (playerPosition == 200) {
			if(set2Colored==false){
				ff = true;
				coll = true;
				lives--;
				playerPosition += 50;
				glClearColor(1, 0, 1, 0);
			}		
		}
		else if (playerPosition < 200) {
			if(set2Colored==false){
				ff = true;
				coll = true;
				lives--;
				playerPosition += (200 - playerPosition) + 50;
				glClearColor(1, 0, 1, 0);
			}	
		}
		//else score++;

	}
	else if (x_position + 7 * 300 <= xPlayer + 25 && x_position + 100 + 7 * 300 >= xPlayer + 25) {
		if (playerPosition == 400) {
			if(set3Colored==false){
				ff = true;
				coll = true;
				lives--;
				playerPosition += 50;
				glClearColor(1, 0, 1, 0);
			}	
		}
		else if (playerPosition < 400) {
			if(set3Colored==false){
				ff = true;
				coll = true;
				lives--;
				playerPosition += (400 - playerPosition) + 50;
				glClearColor(1, 0, 1, 0);
			}
		}
		//else score++;

	}
	else if (x_position + 8 * 300 <= xPlayer + 25 && x_position + 100 + 8 * 300 >= xPlayer + 25) {
		if (playerPosition == 200) {
			if(set3Colored==false){
				ff = true;
				coll = true;
				lives--;
				playerPosition += 50;
				glClearColor(1, 0, 1, 0);
			}	
		}
		else if (playerPosition < 200) {
			if(set3Colored==false){
				ff = true;
				coll = true;
				lives--;
				playerPosition += (200 - playerPosition) + 50;
				glClearColor(1, 0, 1, 0);
			}
		}
		//else score++;

	}
	else if (x_position + 9 * 300 <= xPlayer + 25 && x_position + 100 + 9 * 300 >= xPlayer + 25) {
		if (playerPosition == 360) {
			if(set3Colored==false){
				ff = true;
				coll = true;
				lives--;
				playerPosition += 50;
				glClearColor(1, 0, 1, 0);
			}	
		}
		else if (playerPosition < 360) {
			if(set3Colored==false){
				ff = true;
				coll = true;
				lives--;
				playerPosition += (360 - playerPosition) + 50;
				glClearColor(1, 0, 1, 0);
			}
		}
		//else score++;

	}
	//else score++;

	
	/*if (x_position + 1 * 300 == xPlayer + 25) {
		if (set1Colored == false) {
			ff = true;
			coll = true;
			lives--;
			playerPosition = 250;
			glClearColor(1, 0, 1, 0);
		}
	}*/

	if (x_position + 1 * 300 <= xPlayer + 25 && x_position + 100 + 1 * 300 >= xPlayer + 25 ) {
		//std::cout << playerPosition+25 << " ";
		if ((playerPosition + 30) >= 300) {
			if (set1Colored == false) {
				ff = true;
				coll = true;
				lives--;
				playerPosition =250;
				glClearColor(1, 0, 1, 0);
			}		
		}
		else if (playerPosition  > 300) {
			if(set1Colored==false){
				ff = true;
				coll = true;
				glClearColor(1, 0, 1, 0);
				//TimeDelay(100);
				lives--;
				playerPosition =250;
				glClearColor(1, 0, 1, 0);
			}		
		}
		/*else if (coll = false) {
			score++;
		}*/
		
	}	
	else if (x_position + 2 * 300 <= xPlayer + 25 && x_position + 100 + 2 * 300 >= xPlayer + 25) {
		//std::cout << playerPosition+25 << " ";
		if ((playerPosition + 25) >= 450) {
			if(set1Colored==false){
				ff = true;
				coll = true;
				lives--;
				playerPosition = 400;
				glClearColor(1, 0, 1, 0);
			}
		}
		else if (playerPosition  > 450) {
			if(set1Colored==false){
				ff = true;
				coll = true;
				glClearColor(1, 0, 1, 0);
				//TimeDelay(100);
				lives--;
				playerPosition =400;
				glClearColor(1, 0, 1, 0);
			}
			
		}
		//else score++;
		
	}
	else if (x_position + 3 * 300 <= xPlayer + 25 && x_position + 100 + 3 * 300 >= xPlayer + 25) {
		//std::cout << playerPosition + 25 << " ";
		if ((playerPosition + 25) >= 600) {
			if(set1Colored==false){
				ff = true;
				coll = true;
				lives--;
				playerPosition= 550;
				glClearColor(1, 0, 1, 0);
			}	
		}
		else if (playerPosition > 600) {
			if(set1Colored==false){
				ff = true;
				coll = true;
				glClearColor(1, 0, 1, 0);
				//TimeDelay(100);
				lives--;
				playerPosition =550;
				glClearColor(1, 0, 1, 0);
			}		
		}
		//else score++;

	}
	else if (x_position + 4 * 300 <= xPlayer + 25 && x_position + 100 + 4 * 300 >= xPlayer + 25) {
		//std::cout << playerPosition + 25 << " ";
		if ((playerPosition + 25) >= 550) {
			if(set2Colored==false){
				ff = true;
				coll = true;
				lives--;
				playerPosition =500;
				glClearColor(1, 0, 1, 0);
			}	
		}
		else if (playerPosition > 550) {
			if(set2Colored==false){
				ff = true;
				coll = true;
				glClearColor(1, 0, 1, 0);
				//TimeDelay(100);
				lives--;
				playerPosition =500;
				glClearColor(1, 0, 1, 0);
			}
		}
	//	else score++;

	}
	else if (x_position + 5 * 300 <= xPlayer + 25 && x_position + 100 + 5 * 300 >= xPlayer + 25) {
		//std::cout << playerPosition + 25 << " ";
		if ((playerPosition + 25) >= 500) {
			if(set2Colored==false){
				ff = true;
				coll = true;
				lives--;
				playerPosition =400;
				glClearColor(1, 0, 1, 0);
			}	
		}
		else if (playerPosition > 500) {
			if(set2Colored==false){
				ff = true;
				coll = true;
				glClearColor(1, 0, 1, 0);
				//TimeDelay(100);
				lives--;
				playerPosition =400;
				glClearColor(1, 0, 1, 0);
			}	
		}
		//else score++;

	}
	else if (x_position + 6 * 300 <= xPlayer + 25 && x_position + 100 + 6 * 300 >= xPlayer + 25) {
		//std::cout << playerPosition + 25 << " ";
		if ((playerPosition + 25) >= 300) {
			if(set2Colored==false){
				ff = true;
				coll = true;
				lives--;
				playerPosition =250;
				glClearColor(1, 0, 1, 0);
			}	
		}
		else if (playerPosition > 300) {
			if(set2Colored==false){
				ff = true;
				coll = true;
				glClearColor(1, 0, 1, 0);
				//TimeDelay(100);
				lives--;
				playerPosition =250;
				glClearColor(1, 0, 1, 0);
			}
		}
		//else score++;

	}
	else if (x_position + 7 * 300 <= xPlayer + 25 && x_position + 100 + 7 * 300 >= xPlayer + 25) {
		//std::cout << playerPosition + 25 << " ";
		if ((playerPosition + 25) >= 550) {
			if(set3Colored==false){
				ff = true;
				coll = true;
				lives--;
				playerPosition =450;
				glClearColor(1, 0, 1, 0);
			}
		}
		else if (playerPosition > 550) {
			if(set3Colored=false){
				ff = true;
				coll = true;
				glClearColor(1, 0, 1, 0);
				//TimeDelay(100);
				lives--;
				playerPosition =450;
				glClearColor(1, 0, 1, 0);
			}
		}
		//else score++;

	}
	else if (x_position + 8 * 300 <= xPlayer + 25 && x_position + 100 + 8 * 300 >= xPlayer + 25) {
		//std::cout << playerPosition + 25 << " ";
		if ((playerPosition + 25) >= 300) {
			if(set3Colored==false){
				ff = true;
				coll = true;
				lives--;
				playerPosition=250;
				glClearColor(1, 0, 1, 0);
			}	
		}
		else if (playerPosition > 300) {
			if(set3Colored==false){
				ff = true;
				coll = true;
				glClearColor(1, 0, 1, 0);
				//TimeDelay(100);
				lives--;
				playerPosition =250;
				glClearColor(1, 0, 1, 0);
			}
		}
		//else score++;

	}
	else if (x_position + 9 * 300 <= xPlayer + 25 && x_position + 100 + 9 * 300 >= xPlayer + 25) {
		//std::cout << playerPosition + 25 << " ";
		if ((playerPosition + 25) >= 450) {
			if(set3Colored==false){
				ff = true;
				coll = true;
				lives--;
				playerPosition =400;
				glClearColor(1, 0, 1, 0);
			}
		}
		else if (playerPosition > 450) {
			if(set3Colored==false){
				ff = true;
				coll = true;
				glClearColor(1, 0, 1, 0);
				//TimeDelay(100);
				lives--;
				playerPosition =400;
				glClearColor(1, 0, 1, 0);
			}
		}
		//else score++;

	}
	//else score++;

	

	set1y += 100;
	xSteps += 20.0f;
	if (!jumping&& lives > 0&&!(playerPosition+25>=720)&&!(xPlayer + 25 > x_position + 100 + 9 * 300))
		playerPosition -= 8.0f;
	glutTimerFunc(100, Time, 0);
}

void TimeDelay(int val)
{
	jumping = false;
	glutTimerFunc(500, TimeDelay, 0);
}


void Keyboard(unsigned char key, int x, int y)
{
	if (key == 'w'&& lives > 0 &&!(xPlayer + 25 > x_position + 100 + 9 * 300))
	{
		playerPosition += 20.0f;
		jumping = true;
	}
}

void text() {
	std::cout << lives << " ";
}

void main(int argc, char** argr) {
	glutInit(&argc, argr);

	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutInitWindowPosition(150, 150);

	glutCreateWindow("Falppy Bird" );
	//glutSetWindowTitle((const char*)lives);
	glutDisplayFunc(Display);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glClearColor(0.2f, 0.5f, 0.8f, 0.0f);
	

	glutTimerFunc(100, Time, 0);
	glutTimerFunc(500, TimeDelay, 0);
	glutKeyboardFunc(Keyboard);

	srand(time(0));
    random = 1+(rand()%9);
	if (random >= 1 && random <= 3) { random = 1; }
	if (random >= 4 && random <= 6)random = 4;
	if (random >= 7 && random <= 9)random = 7;

	srand(time(0));
	ran = 1+(rand() % 3);

	srand(time(0));
	ran2 = 1 + (rand() % 2);

	for (size_t i = 0; i < NUM_COLUMNS; i++)
		randomHeightValues[i] = (rand() % RADNOM_HEIGHT_RANGE) + 50.0f;
	//std::cout << array << " ";
	gluOrtho2D(0.0, SCREEN_WIDTH, 0.0, SCREEN_HEIGHT);
	glutMainLoop();
}


