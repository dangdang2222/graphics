#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <GL/glew.h>
#include <GL/freeglut.h>

#include "Shaders/LoadShaders.h"
GLuint h_ShaderProgram; // handle to shader program
GLint loc_ModelViewProjectionMatrix, loc_primitive_color; // indices of uniform variables

// include glm/*.hpp only if necessary
#include <glm/glm.hpp> 
#include <glm/gtc/matrix_transform.hpp> //translate, rotate, scale, ortho, etc.
glm::mat4 ModelViewProjectionMatrix;
glm::mat4 ViewMatrix, ProjectionMatrix, ViewProjectionMatrix;

#define TO_RADIAN 0.01745329252f  
#define TO_DEGREE 57.295779513f
#define BUFFER_OFFSET(offset) ((GLvoid *) (offset))

#define LOC_VERTEX 0

int win_width = 0, win_height = 0; 
float centerx = 0.0f, centery = 0.0f;

// 2D 물체 정의 부분은 objects.h 파일로 분리
// 새로운 물체 추가 시 prepare_scene() 함수에서 해당 물체에 대한 prepare_***() 함수를 수행함.
// (필수는 아니나 올바른 코딩을 위하여) cleanup() 함수에서 해당 resource를 free 시킴.
#include "objects.h"

unsigned int timestamp = 0;
void timer(int value) {
	timestamp = (timestamp + 1) % UINT_MAX;
	glutPostRedisplay();
	glutTimerFunc(10, timer, 0);
}

void display(void) {
	glm::mat4 ModelMatrix;
	
	glClear(GL_COLOR_BUFFER_BIT);
	
	ModelMatrix = glm::mat4(1.0f);
	ModelViewProjectionMatrix = ViewProjectionMatrix * ModelMatrix;
	glUniformMatrix4fv(loc_ModelViewProjectionMatrix, 1, GL_FALSE, &ModelViewProjectionMatrix[0][0]);
	//draw_axes();
//	draw_axes2();
	draw_road();


	int knight_clock = timestamp;
	ModelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 300.0f, 0.0f));
	if (timestamp < 50) {
	}
	else {
		if (timestamp < 600) {
			ModelMatrix = glm::scale(ModelMatrix, glm::vec3(timestamp * 0.0015, timestamp * 0.0015, 1.0f));
			ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, -knight_clock / 5, 0.0f));
		}
		else if (timestamp<610) {
			//int p = (timestamp - 590) / 10;

			ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, -200, 0.0f));
			ModelMatrix = glm::rotate(ModelMatrix, -10.0f * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));
			ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, 200, 0.0f));
			ModelMatrix = glm::scale(ModelMatrix, glm::vec3(600 * 0.0015, 600 * 0.0015, 1.0f));
			ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, -600 / 5, 0.0f));
		}
		else if (timestamp < 620) {
			ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, -200, 0.0f));
			ModelMatrix = glm::rotate(ModelMatrix, 10.0f * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));
			ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, 200, 0.0f));
			ModelMatrix = glm::scale(ModelMatrix, glm::vec3(600 * 0.0015, 600 * 0.0015, 1.0f));
			ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, -600 / 5, 0.0f));
		}
		else if (timestamp < 630) {
			ModelMatrix = glm::rotate(ModelMatrix, 10.0f * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));
			ModelMatrix = glm::scale(ModelMatrix, glm::vec3(600 * 0.0015, 600 * 0.0015, 1.0f));
			ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, -600 / 5, 0.0f));
		}
		else if (timestamp < 640) {
			ModelMatrix = glm::rotate(ModelMatrix, -20.0f * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));
			ModelMatrix = glm::scale(ModelMatrix, glm::vec3(600 * 0.0015, 600 * 0.0015, 1.0f));
			ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, -600 / 5, 0.0f));
		}
		else if (timestamp < 650) {
			ModelMatrix = glm::rotate(ModelMatrix, 10.0f * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));
			ModelMatrix = glm::scale(ModelMatrix, glm::vec3(600 * 0.0015, 600 * 0.0015, 1.0f));
			ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, -600 / 5, 0.0f));
		}
		else {
			if (timestamp < 730) {
				ModelMatrix = glm::scale(ModelMatrix, glm::vec3(timestamp * 0.0015, timestamp * 0.0015, 1.0f));
				ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, -knight_clock / 5, 0.0f));
				
				/*ModelMatrix = glm::scale(ModelMatrix, glm::vec3(700 * 0.0015, 700 * 0.0015, 1.0f));
				ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, -700 / 5, 0.0f));*/
			}
			else if (timestamp < 740) {
				//int p = (timestamp - 590) / 10;
				ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, -200, 0.0f));
				ModelMatrix = glm::rotate(ModelMatrix, -10.0f * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));
				ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, 200, 0.0f));
				ModelMatrix = glm::scale(ModelMatrix, glm::vec3(650 * 0.0015, 650 * 0.0015, 1.0f));
				ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, -650 / 5, 0.0f));
			}
			else if (timestamp < 750) {
				ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, -200, 0.0f));
				ModelMatrix = glm::rotate(ModelMatrix, 10.0f * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));
				ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, 200, 0.0f));
				ModelMatrix = glm::scale(ModelMatrix, glm::vec3(650 * 0.0015, 650 * 0.0015, 1.0f));
				ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, -650 / 5, 0.0f));
			}
			else if (timestamp < 760) {
				ModelMatrix = glm::rotate(ModelMatrix, 10.0f * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));
				ModelMatrix = glm::scale(ModelMatrix, glm::vec3(650 * 0.0015, 600 * 0.0015, 1.0f));
				ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, -650 / 5, 0.0f));
			}
			else if (timestamp < 770) {
				ModelMatrix = glm::rotate(ModelMatrix, -20.0f * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));
				ModelMatrix = glm::scale(ModelMatrix, glm::vec3(650 * 0.0015, 650 * 0.0015, 1.0f));
				ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, -650 / 5, 0.0f));
			}
			else if (timestamp < 780) {
				ModelMatrix = glm::rotate(ModelMatrix, 10.0f * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));
				ModelMatrix = glm::scale(ModelMatrix, glm::vec3(650 * 0.0015, 650 * 0.0015, 1.0f));
				ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, -650 / 5, 0.0f));
			}
			else if (timestamp < 900) {
				ModelMatrix = glm::scale(ModelMatrix, glm::vec3(timestamp * 0.0015, timestamp * 0.0015, 1.0f));
				ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, -knight_clock / 5, 0.0f));

				//ModelMatrix = glm::scale(ModelMatrix, glm::vec3(650 * 0.0015, 650 * 0.0015, 1.0f));
				//ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, -650 / 5, 0.0f));
			}
			else{
				ModelMatrix = glm::scale(ModelMatrix, glm::vec3(880 * 0.0015, 880 * 0.0015, 1.0f));
				ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, -880 / 5, 0.0f));

				int t = timestamp - 900;
				if (t < 300) {
					ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, t * 2.0 - 0.007 * t * t, 0.0f));
				}

			}
		}
		ModelViewProjectionMatrix = ViewProjectionMatrix * ModelMatrix;
		glUniformMatrix4fv(loc_ModelViewProjectionMatrix, 1, GL_FALSE, &ModelViewProjectionMatrix[0][0]);

		draw_knight();
	}

	int sword_clock = timestamp;
	int k = 0;
	float rotation_sword;
	int t = 0;
	if (timestamp < 50) {
		ModelMatrix = glm::scale(ModelMatrix, glm::vec3(3.0, 3.0, 1.0f));
	}
	else {
		ModelMatrix = glm::scale(ModelMatrix, glm::vec3(3.0, 3.0, 1.0f));
		if (timestamp > 900) {
			int t = timestamp - 900;
			if (t > 100) {
				if (t < 200) {
					ModelMatrix = glm::scale(ModelMatrix, glm::vec3(t * 0.01 * 1.05, t * 0.01 * 1.25, 1.0f));
					
				}
				else {
					ModelMatrix = glm::scale(ModelMatrix, glm::vec3(2 * 1.05, 2 * 1.25, 1.0f));
				}
			}
			if (t < 300) {
				if (t >= 125) {
					rotation_sword = 30 * TO_RADIAN;
					ModelMatrix = glm::rotate(ModelMatrix, rotation_sword, glm::vec3(0.0f, 0.0f, 1.0f));
					if (t >= 135) {
						rotation_sword = 30 * TO_RADIAN;
						ModelMatrix = glm::rotate(ModelMatrix, rotation_sword, glm::vec3(0.0f, 0.0f, 1.0f));
						if (t >= 145) {
							rotation_sword = 30 * TO_RADIAN;
							ModelMatrix = glm::rotate(ModelMatrix, rotation_sword, glm::vec3(0.0f, 0.0f, 1.0f));
							if (t >= 155) {
								rotation_sword = 30 * TO_RADIAN;
								ModelMatrix = glm::rotate(ModelMatrix, rotation_sword, glm::vec3(0.0f, 0.0f, 1.0f));
								if (t >= 165) {
									rotation_sword = 30 * TO_RADIAN;
									ModelMatrix = glm::rotate(ModelMatrix, rotation_sword, glm::vec3(0.0f, 0.0f, 1.0f));
									if (t >= 175) {
										rotation_sword = 30 * TO_RADIAN;
										ModelMatrix = glm::rotate(ModelMatrix, rotation_sword, glm::vec3(0.0f, 0.0f, 1.0f));
									}
								}
							}
						}
					}
				}
			}
			else{ 
				//ModelMatrix = glm::scale(ModelMatrix, glm::vec3(2 * 1.1, 2 * 1.5, 1.0f));
				rotation_sword = (180) * TO_RADIAN;
			    ModelMatrix = glm::rotate(ModelMatrix, rotation_sword, glm::vec3(0.0f, 0.0f, 1.0f));
			}
		
		}
		ModelViewProjectionMatrix = ViewProjectionMatrix * ModelMatrix;
		glUniformMatrix4fv(loc_ModelViewProjectionMatrix, 1, GL_FALSE, &ModelViewProjectionMatrix[0][0]);

		draw_sword();
	}

	
	int house_clock = timestamp; // -360 <= house_clock <= 360 


	ModelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(-200, 250, 0.0f));
	

	if (timestamp > 1300) {	
		if (timestamp < 1360) {
			int k = (timestamp - 1290) * 0.1;

			ModelMatrix = glm::rotate(ModelMatrix, k * 1.0f * 30 * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));
			//ModelMatrix = glm::translate(ModelMatrix, glm::vec3(-50.0f * 400 * 0.01 + 50.0f * 150 * 0.01, 0.0f, 0.0f));
		}
		else if (timestamp < 1370) {

			ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, -30.0f, 0.0f));
			ModelMatrix = glm::rotate(ModelMatrix, 20 * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));
			ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, 30.0f, 0.0f));

			ModelMatrix = glm::rotate(ModelMatrix, 6 * 1.0f * 30 * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));
		}
		else {
			int q = (timestamp - 1370) % 40;
			int x = (timestamp - 1360) * 0.1;

			ModelMatrix = glm::translate(ModelMatrix, glm::vec3(-x * 3, x * 3 / 8, 0.0f));

			if (q < 21) {
				ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, -30.0f, 0.0f));
				ModelMatrix = glm::rotate(ModelMatrix, q * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));
				ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, 30.0f, 0.0f));
				ModelMatrix = glm::scale(ModelMatrix, glm::vec3(1.5f, 1.5f, 1.5f));
			}
			else {
				q = q - 20;
				ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, -30.0f, 0.0f));
				ModelMatrix = glm::rotate(ModelMatrix, -q * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));
				ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, 30.0f, 0.0f));
			}

			ModelMatrix = glm::rotate(ModelMatrix, 6 * 1.0f * 30 * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));

		}
	}

	ModelMatrix = glm::scale(ModelMatrix, glm::vec3(1.5f, 1.5f, 1.0f));
	ModelViewProjectionMatrix = ViewProjectionMatrix * ModelMatrix;
	glUniformMatrix4fv(loc_ModelViewProjectionMatrix, 1, GL_FALSE, &ModelViewProjectionMatrix[0][0]);
	draw_house(); // in WC*/

	house_clock = timestamp; // -360 <= house_clock <= 360 
	
	ModelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(-220, 250, 0.0f)); if (timestamp > 1300) {
		if (timestamp < 1360) {
			int k = (timestamp - 1290) * 0.1;

			ModelMatrix = glm::rotate(ModelMatrix, k * 1.0f * 30 * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));
			//ModelMatrix = glm::translate(ModelMatrix, glm::vec3(-50.0f * 400 * 0.01 + 50.0f * 150 * 0.01, 0.0f, 0.0f));
		}
		else if (timestamp < 1370) {

			ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, -30.0f, 0.0f));
			ModelMatrix = glm::rotate(ModelMatrix, 20 * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));
			ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, 30.0f, 0.0f));

			ModelMatrix = glm::rotate(ModelMatrix, 6 * 1.0f * 30 * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));
		}
		else {
			int q = (timestamp - 1370) % 40;
			int x = (timestamp - 1360) * 0.1;

			ModelMatrix = glm::translate(ModelMatrix, glm::vec3(-x * 3, x * 3 / 8, 0.0f));

			if (q < 21) {
				
				ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, -30.0f, 0.0f));
				ModelMatrix = glm::rotate(ModelMatrix, q * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));
				ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, 30.0f, 0.0f));
				ModelMatrix = glm::scale(ModelMatrix, glm::vec3(1.5f, 1.5f, 1.5f));
			}
			else {
				q = q - 20;
				
				ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, -30.0f, 0.0f));
				ModelMatrix = glm::rotate(ModelMatrix, -q * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));
				ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, 30.0f, 0.0f));
			}

			ModelMatrix = glm::rotate(ModelMatrix, 6 * 1.0f * 30 * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));

		}
	}
	
	ModelMatrix = glm::scale(ModelMatrix, glm::vec3(1.5f, 2.5f, 1.0f));
	ModelViewProjectionMatrix = ViewProjectionMatrix * ModelMatrix;
	glUniformMatrix4fv(loc_ModelViewProjectionMatrix, 1, GL_FALSE, &ModelViewProjectionMatrix[0][0]);
	draw_house();

	house_clock = timestamp; // -360 <= house_clock <= 360 

	ModelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(-245, 250, 0.0f));

	if (timestamp > 1300) {
		if (timestamp < 1360) {
			int k = (timestamp - 1290) * 0.1;

			ModelMatrix = glm::rotate(ModelMatrix, k * 1.0f * 30 * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));
			//ModelMatrix = glm::translate(ModelMatrix, glm::vec3(-50.0f * 400 * 0.01 + 50.0f * 150 * 0.01, 0.0f, 0.0f));
		}
		else if (timestamp < 1370) {

			ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, -30.0f, 0.0f));
			ModelMatrix = glm::rotate(ModelMatrix, 20 * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));
			ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, 30.0f, 0.0f));

			ModelMatrix = glm::rotate(ModelMatrix, 6 * 1.0f * 30 * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));
		}
		else {
			int q = (timestamp - 1370) % 40;
			int x = (timestamp - 1360) * 0.1;

			ModelMatrix = glm::translate(ModelMatrix, glm::vec3(-x * 3, x * 3 / 8, 0.0f));

			if (q < 21) {
			
				ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, -30.0f, 0.0f));
				ModelMatrix = glm::rotate(ModelMatrix, q * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));
				ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, 30.0f, 0.0f));
				ModelMatrix = glm::scale(ModelMatrix, glm::vec3(1.5f, 1.5f, 1.5f));
			}
			else {
				q = q - 20;
		
				ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, -30.0f, 0.0f));
				ModelMatrix = glm::rotate(ModelMatrix, -q * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));
				ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, 30.0f, 0.0f));
			}

			ModelMatrix = glm::rotate(ModelMatrix, 6 * 1.0f * 30 * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));

		}
	}

	ModelMatrix = glm::scale(ModelMatrix, glm::vec3(2.5f, 2.0f, 1.0f));

	ModelViewProjectionMatrix = ViewProjectionMatrix * ModelMatrix;
	glUniformMatrix4fv(loc_ModelViewProjectionMatrix, 1, GL_FALSE, &ModelViewProjectionMatrix[0][0]);
	draw_house();


	ModelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(400, -250, 0.0f));

	if (timestamp > 1300) {
		if (timestamp < 1360) {
			int k = (timestamp - 1290) * 0.1;

			ModelMatrix = glm::rotate(ModelMatrix, k * 1.0f * 30 * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));
			//ModelMatrix = glm::translate(ModelMatrix, glm::vec3(-50.0f * 400 * 0.01 + 50.0f * 150 * 0.01, 0.0f, 0.0f));
		}
		else if (timestamp < 1370) {

			ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, -30.0f, 0.0f));
			ModelMatrix = glm::rotate(ModelMatrix, 20 * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));
			ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, 30.0f, 0.0f));

			ModelMatrix = glm::rotate(ModelMatrix, 6 * 1.0f * 30 * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));
		}
		else {
			int q = (timestamp - 1370) % 40;
			int x = (timestamp - 1360) * 0.1;

			ModelMatrix = glm::translate(ModelMatrix, glm::vec3(x * 3, -x * 3 * 5 / 8, 0.0f));

			if (q < 21) {
				ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, -30.0f, 0.0f));
				ModelMatrix = glm::rotate(ModelMatrix, q * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));
				ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, 30.0f, 0.0f));
				ModelMatrix = glm::scale(ModelMatrix, glm::vec3(1.5f, 1.5f, 1.5f));
			}
			else {
				q = q - 20;
				ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, -30.0f, 0.0f));
				ModelMatrix = glm::rotate(ModelMatrix, -q * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));
				ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, 30.0f, 0.0f));
				ModelMatrix = glm::scale(ModelMatrix, glm::vec3(1.0f, 1.0f, 1.0f));
			}
			ModelMatrix = glm::rotate(ModelMatrix, 6 * 1.0f * 30 * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));
		}
	}

	ModelMatrix = glm::scale(ModelMatrix, glm::vec3(5.0f, 5.0f, 1.0f));

	ModelViewProjectionMatrix = ViewProjectionMatrix * ModelMatrix;
	glUniformMatrix4fv(loc_ModelViewProjectionMatrix, 1, GL_FALSE, &ModelViewProjectionMatrix[0][0]);
	draw_house(); 


	int airplane_clock = timestamp ; // 0 <= airplane_clock <= 719 
	if (timestamp > 1200) {

		int p = (((timestamp - 1200) % 150)+100) * 0.05;
			for (int i = -1; i < 8; i++) {
				ModelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));

				ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, -100.0f, 0.0f));

				ModelMatrix = glm::rotate(ModelMatrix, -i * 30.0f * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));
				ModelMatrix = glm::translate(ModelMatrix, glm::vec3(100.0f + 10.0f * p, 0.0f, 0.0f));


				ModelMatrix = glm::rotate(ModelMatrix, (90.0f) * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));




				ModelViewProjectionMatrix = ViewProjectionMatrix * ModelMatrix;
				glUniformMatrix4fv(loc_ModelViewProjectionMatrix, 1, GL_FALSE, &ModelViewProjectionMatrix[0][0]);
				draw_airplane();

			}
			for (int i = -1; i < 8; i++) {
				ModelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));

				ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, -100.0f, 0.0f));

				ModelMatrix = glm::rotate(ModelMatrix, -i * 30.0f * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));
				ModelMatrix = glm::translate(ModelMatrix, glm::vec3(100.0f + 20.0f * p, 0.0f, 0.0f));


				ModelMatrix = glm::rotate(ModelMatrix, (90.0f) * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));




				ModelViewProjectionMatrix = ViewProjectionMatrix * ModelMatrix;
				glUniformMatrix4fv(loc_ModelViewProjectionMatrix, 1, GL_FALSE, &ModelViewProjectionMatrix[0][0]);
				draw_airplane();

			}
			for (int i = -1; i < 8; i++) {
				ModelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));

				ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, -100.0f, 0.0f));

				ModelMatrix = glm::rotate(ModelMatrix, -i * 30.0f * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));
				ModelMatrix = glm::translate(ModelMatrix, glm::vec3(100.0f + 30.0f * p, 0.0f, 0.0f));


				ModelMatrix = glm::rotate(ModelMatrix, (90.0f) * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));




				ModelViewProjectionMatrix = ViewProjectionMatrix * ModelMatrix;
				glUniformMatrix4fv(loc_ModelViewProjectionMatrix, 1, GL_FALSE, &ModelViewProjectionMatrix[0][0]);
				draw_airplane();

			}
			for (int i = -1; i < 8; i++) {
				ModelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));

				ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, -100.0f, 0.0f));

				ModelMatrix = glm::rotate(ModelMatrix, -i * 30.0f * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));
				ModelMatrix = glm::translate(ModelMatrix, glm::vec3(100.0f + 40.0f * p, 0.0f, 0.0f));


				ModelMatrix = glm::rotate(ModelMatrix, (90.0f) * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));




				ModelViewProjectionMatrix = ViewProjectionMatrix * ModelMatrix;
				glUniformMatrix4fv(loc_ModelViewProjectionMatrix, 1, GL_FALSE, &ModelViewProjectionMatrix[0][0]);
				draw_airplane();

			}
	}
	
	airplane_clock = timestamp; // 0 <= airplane_clock <= 719 
	if (timestamp > 1200) {

		int p = (((timestamp - 1200) % 150) + 100) * 0.05;
		for (int i = -1; i < 9; i++) {
			ModelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));

			ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, -100.0f, 0.0f));

			ModelMatrix = glm::rotate(ModelMatrix, ((-i * 30.0f)+15.0f) * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));
			ModelMatrix = glm::translate(ModelMatrix, glm::vec3(100.0f + 15.0f * p, 0.0f, 0.0f));


			ModelMatrix = glm::rotate(ModelMatrix, (90.0f) * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));


			ModelMatrix = glm::scale(ModelMatrix, glm::vec3(0.6f, 0.6f, 1.0f));

			ModelViewProjectionMatrix = ViewProjectionMatrix * ModelMatrix;
			glUniformMatrix4fv(loc_ModelViewProjectionMatrix, 1, GL_FALSE, &ModelViewProjectionMatrix[0][0]);
			draw_airplane();

		}
		for (int i = -1; i < 9; i++) {
			ModelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));

			ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, -100.0f, 0.0f));

			ModelMatrix = glm::rotate(ModelMatrix, ((-i * 30.0f) + 15.0f) * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));
			ModelMatrix = glm::translate(ModelMatrix, glm::vec3(100.0f + 25.0f * p, 0.0f, 0.0f));


			ModelMatrix = glm::rotate(ModelMatrix, (90.0f) * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));


			ModelMatrix = glm::scale(ModelMatrix, glm::vec3(0.6f, 0.6f, 1.0f));

			ModelViewProjectionMatrix = ViewProjectionMatrix * ModelMatrix;
			glUniformMatrix4fv(loc_ModelViewProjectionMatrix, 1, GL_FALSE, &ModelViewProjectionMatrix[0][0]);
			draw_airplane();

		}
		for (int i = -1; i < 9; i++) {
			ModelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));

			ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, -100.0f, 0.0f));

			ModelMatrix = glm::rotate(ModelMatrix, ((-i * 30.0f) + 15.0f) * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));
			ModelMatrix = glm::translate(ModelMatrix, glm::vec3(100.0f + 35.0f * p, 0.0f, 0.0f));


			ModelMatrix = glm::rotate(ModelMatrix, (90.0f) * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));


			ModelMatrix = glm::scale(ModelMatrix, glm::vec3(0.6f, 0.6f, 1.0f));

			ModelViewProjectionMatrix = ViewProjectionMatrix * ModelMatrix;
			glUniformMatrix4fv(loc_ModelViewProjectionMatrix, 1, GL_FALSE, &ModelViewProjectionMatrix[0][0]);
			draw_airplane();

		}
		for (int i = -1; i < 9; i++) {
			ModelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));

			ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, -100.0f, 0.0f));

			ModelMatrix = glm::rotate(ModelMatrix, ((-i * 30.0f) + 15.0f) * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));
			ModelMatrix = glm::translate(ModelMatrix, glm::vec3(100.0f + 45.0f * p, 0.0f, 0.0f));


			ModelMatrix = glm::rotate(ModelMatrix, (90.0f) * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));


			ModelMatrix = glm::scale(ModelMatrix, glm::vec3(0.6f, 0.6f, 1.0f));

			ModelViewProjectionMatrix = ViewProjectionMatrix * ModelMatrix;
			glUniformMatrix4fv(loc_ModelViewProjectionMatrix, 1, GL_FALSE, &ModelViewProjectionMatrix[0][0]);
			draw_airplane();

		}
	}

	int car2_clock = timestamp;
	if (timestamp > 100) {
		ModelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(500.0f, 300.0f, 0.0f));
		if (timestamp < 400) {

			ModelMatrix = glm::translate(ModelMatrix, glm::vec3(-50.0f * timestamp * 0.01, 0.0f, 0.0f));
		}
		else {
			if (timestamp < 430) {
				ModelMatrix = glm::translate(ModelMatrix, glm::vec3(-50.0f * 400 * 0.01, 0.0f, 0.0f));
			}
			else if (timestamp < 500) {
				ModelMatrix = glm::translate(ModelMatrix, glm::vec3(+50.0f * (timestamp - 400) * 0.01, 0.0f, 0.0f));
				ModelMatrix = glm::translate(ModelMatrix, glm::vec3(-50.0f * 400 * 0.01, 0.0f, 0.0f));
			}
			else if (timestamp < 1300) {
				ModelMatrix = glm::translate(ModelMatrix, glm::vec3(-50.0f * 400 * 0.01 + 50.0f * 100 * 0.01, 0.0f, 0.0f));
			}
			else if (timestamp < 1360) {
				int k = (timestamp - 1290) * 0.1;

				ModelMatrix = glm::rotate(ModelMatrix, k * 1.0f * 30 * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));
				//ModelMatrix = glm::translate(ModelMatrix, glm::vec3(-50.0f * 400 * 0.01 + 50.0f * 150 * 0.01, 0.0f, 0.0f));
			}
			else if(timestamp<1370) {
				
				ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, -30.0f, 0.0f));
				ModelMatrix = glm::rotate(ModelMatrix, 20 * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));
				ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, 30.0f , 0.0f));

				ModelMatrix = glm::rotate(ModelMatrix, 6 * 1.0f * 30 * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));
			}
			else {
				int q = (timestamp - 1370) % 40;


				if (q < 21) {
					ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, -30.0f, 0.0f));
					ModelMatrix = glm::rotate(ModelMatrix, q * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));
					ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, 30.0f, 0.0f));
				}
				else {
					q = q - 20;
					ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, -30.0f, 0.0f));
					ModelMatrix = glm::rotate(ModelMatrix, -q * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));
					ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, 30.0f, 0.0f));
				}
			

				ModelMatrix = glm::rotate(ModelMatrix, 6 * 1.0f * 30 * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));
			}

		}
		ModelMatrix = glm::scale(ModelMatrix, glm::vec3(4.0f, 4.0f, 0.0f));
		//ModelMatrix = glm::translate(ModelMatrix, glm::vec3(300.0f,100.0f,0.0f));
		ModelViewProjectionMatrix = ViewProjectionMatrix * ModelMatrix;
		glUniformMatrix4fv(loc_ModelViewProjectionMatrix, 1, GL_FALSE, &ModelViewProjectionMatrix[0][0]);
		draw_car2();
	}

	car2_clock = timestamp-200;
	if (car2_clock > 100) {
		ModelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(-600.0f, -60.0f, 0.0f));
		if (car2_clock < 400) {
			ModelMatrix = glm::translate(ModelMatrix, glm::vec3(+50.0f * car2_clock * 0.01, 0.0f, 0.0f));
		}
		else {
			if (car2_clock < 430) {
				ModelMatrix = glm::translate(ModelMatrix, glm::vec3(+50.0f * 400 * 0.01, 0.0f, 0.0f));
			}
			else if (car2_clock < 500) {
				ModelMatrix = glm::translate(ModelMatrix, glm::vec3(-50.0f * (car2_clock - 400) * 0.01, 0.0f, 0.0f));
				ModelMatrix = glm::translate(ModelMatrix, glm::vec3(+50.0f * 400 * 0.01, 0.0f, 0.0f));
			}
			else if (timestamp < 1300) {
				ModelMatrix = glm::translate(ModelMatrix, glm::vec3(+50.0f * 400 * 0.01 - 50.0f * 100 * 0.01, 0.0f, 0.0f));
			}
			else if (timestamp < 1360) {
				int k = (timestamp - 1290) * 0.1;

				ModelMatrix = glm::rotate(ModelMatrix, k * 1.0f * 30 * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));
			}
			else if (timestamp < 1370) {

				ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, -30.0f, 0.0f));
				ModelMatrix = glm::rotate(ModelMatrix, 20 * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));
				ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, 30.0f, 0.0f));

				ModelMatrix = glm::rotate(ModelMatrix, 6 * 1.0f * 30 * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));
			}
			else {
				int q = (timestamp - 1370) % 40;


				if (q < 21) {
					ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, -30.0f, 0.0f));
					ModelMatrix = glm::rotate(ModelMatrix, q * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));
					ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, 30.0f, 0.0f));
				}
				else {
					q = q - 20;
					ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, -30.0f, 0.0f));
					ModelMatrix = glm::rotate(ModelMatrix, -q * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));
					ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, 30.0f, 0.0f));
				}


				ModelMatrix = glm::rotate(ModelMatrix, 6 * 1.0f * 30 * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));
			}

		}
		ModelMatrix = glm::scale(ModelMatrix, glm::vec3(-4.0f, 4.0f, 0.0f));
		//ModelMatrix = glm::translate(ModelMatrix, glm::vec3(300.0f,100.0f,0.0f));
		ModelViewProjectionMatrix = ViewProjectionMatrix * ModelMatrix;
		glUniformMatrix4fv(loc_ModelViewProjectionMatrix, 1, GL_FALSE, &ModelViewProjectionMatrix[0][0]);
		draw_car2();
	}


	/*
	int house_clock = (timestamp % 1442) / 2 - 360; // -360 <= house_clock <= 360
	float rotation_angle_house = atanf(100.0f*TO_RADIAN*cosf(house_clock * TO_RADIAN));
	float scaling_factor_house = 5.0f*(1.0f - fabs(cosf(house_clock * TO_RADIAN)));

	ModelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(centerx, centery, 0.0f));
	ModelMatrix = glm::translate(ModelMatrix, glm::vec3((float)house_clock,
														100.0f * sinf(house_clock * TO_RADIAN), 0.0f));
	ModelMatrix = glm::scale(ModelMatrix, glm::vec3(scaling_factor_house, scaling_factor_house, 1.0f));
	ModelMatrix = glm::rotate(ModelMatrix, rotation_angle_house, glm::vec3(0.0f, 0.0f, 1.0f));
	ModelViewProjectionMatrix = ViewProjectionMatrix * ModelMatrix;
	glUniformMatrix4fv(loc_ModelViewProjectionMatrix, 1, GL_FALSE, &ModelViewProjectionMatrix[0][0]);
	draw_house(); // in WC*/

	int cake_clock = timestamp;


	ModelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(200.0f, 280.0f, 0.0f)); //얘한테는 200.0, 280.0이 중점이 됐다고 생각해보자

	if (timestamp < 4000) {
		if (timestamp < 400) {

		}
		else if (timestamp < 580) {
			int p = (cake_clock - 390) / 10;
			ModelMatrix = glm::translate(ModelMatrix, glm::vec3(-100.0f, 0.0f, 0.0f));
			ModelMatrix = glm::rotate(ModelMatrix, p * 10.0f * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));
			ModelMatrix = glm::translate(ModelMatrix, glm::vec3(100.0f, 0.0f, 0.0f));
		}
		else if (timestamp < 760) {
			int p = (cake_clock - 570) / 10;


			ModelMatrix = glm::translate(ModelMatrix, glm::vec3(-400.0f, 0.0f, 0.0f));
			ModelMatrix = glm::rotate(ModelMatrix, p * 10.0f * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));
			ModelMatrix = glm::translate(ModelMatrix, glm::vec3(200.0f, 0.0f, 0.0f));
		}
		else if (timestamp < 4000) {


			/*	int p = (timestamp - 760) % 360;

				if (p == 0)
			//	ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, -100.0f, 0.0f));


				ModelMatrix = glm::translate(ModelMatrix, glm::vec3(50, 0.0f, 0.0f));
				ModelMatrix = glm::rotate(ModelMatrix, p*TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));
				ModelMatrix = glm::translate(ModelMatrix, glm::vec3(50.0f, 0.0f, 0.0f));

				ModelMatrix = glm::translate(ModelMatrix, glm::vec3(-400.0f, 0.0f, 0.0f));
				ModelMatrix = glm::rotate(ModelMatrix, 18 * 10.0f * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));
				ModelMatrix = glm::translate(ModelMatrix, glm::vec3(200.0f, 0.0f, 0.0f));*/
			/*int p = (timestamp - 760) % 360;


			if (p == 0) {
				ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, -50.0f, 0.0f));
			}

			ModelMatrix = glm::translate(ModelMatrix, glm::vec3(-50.0f, 0.0f, 0.0f));
			ModelMatrix = glm::rotate(ModelMatrix, p * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));
			ModelMatrix = glm::translate(ModelMatrix, glm::vec3(50.0f, 0.0f, 0.0f));*/
			//ModelMatrix = glm::translate(ModelMatrix, glm::vec3(-600.0f, 0.0f, 0.0f));
			int p = (timestamp - 760) % 360;
			//int count = 0;
			//if (p == 0) count++;

			ModelMatrix = glm::translate(ModelMatrix, glm::vec3(-600.0f, -2.0*(timestamp-760), 0.0f));
			ModelMatrix = glm::rotate(ModelMatrix, 3*p * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));
			ModelMatrix = glm::translate(ModelMatrix, glm::vec3(50.0f, 0.0f, 0.0f));
		}

		ModelMatrix = glm::scale(ModelMatrix, glm::vec3(3.0f, 3.0f, 1.0f));

		ModelViewProjectionMatrix = ViewProjectionMatrix * ModelMatrix;
		glUniformMatrix4fv(loc_ModelViewProjectionMatrix, 1, GL_FALSE, &ModelViewProjectionMatrix[0][0]);
		draw_cake();
	}
	


	int cocktail_clock = timestamp;


	ModelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(-300.0f, -60.0f, 0.0f)); 

	if (timestamp < 4000) {
		if (timestamp < 600) {

		}
		else if (timestamp < 750) {
			int p = (cocktail_clock - 590) / 10;
			ModelMatrix = glm::translate(ModelMatrix, glm::vec3(150.0f, 0.0f, 0.0f));
			ModelMatrix = glm::rotate(ModelMatrix, -p * 10.0f * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));
			ModelMatrix = glm::translate(ModelMatrix, glm::vec3(-150.0f, 0.0f, 0.0f));
		}
		else if (timestamp < 1020) {
		
			int p = (timestamp - 750) % 360;
			

			ModelMatrix = glm::translate(ModelMatrix, glm::vec3(250.0f, 450.0f, 0.0f));
			ModelMatrix = glm::rotate(ModelMatrix, -p * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));
			ModelMatrix = glm::translate(ModelMatrix, glm::vec3(0.0f, -300.0f, 0.0f));
		}
		else if (timestamp < 4000) {
			int p = (timestamp - 1020) % 360;

			ModelMatrix = glm::translate(ModelMatrix, glm::vec3(550.0f + 0.8 * (timestamp - 760), 750-1.5* (timestamp - 760), 0.0f));
			ModelMatrix = glm::rotate(ModelMatrix, 3 * p * TO_RADIAN, glm::vec3(0.0f, 0.0f, 1.0f));
			ModelMatrix = glm::translate(ModelMatrix, glm::vec3(100.0f, 0.0f, 0.0f));
		}

		ModelMatrix = glm::scale(ModelMatrix, glm::vec3(3.0f, 3.0f, 1.0f));

		ModelViewProjectionMatrix = ViewProjectionMatrix * ModelMatrix;
		glUniformMatrix4fv(loc_ModelViewProjectionMatrix, 1, GL_FALSE, &ModelViewProjectionMatrix[0][0]);
		draw_cocktail();
	}
	
	glFlush();
}   

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 27: // ESC key
		glutLeaveMainLoop(); // Incur destuction callback for cleanups.
		break;
	}
}

int leftbuttonpressed = 0;
void mouse(int button, int state, int x, int y) {
	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN))
		leftbuttonpressed = 1;
	else if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_UP))
		leftbuttonpressed = 0;
}

void motion(int x, int y) {
	if (leftbuttonpressed) {
		centerx =  x - win_width/2.0f, centery = (win_height - y) - win_height/2.0f;
		glutPostRedisplay();
	}
} 
	
void reshape(int width, int height) {
	win_width = width, win_height = height;
	
  	glViewport(0, 0, win_width, win_height);
	ProjectionMatrix = glm::ortho(-win_width / 2.0, win_width / 2.0, 
		-win_height / 2.0, win_height / 2.0, -1000.0, 1000.0);
	ViewProjectionMatrix = ProjectionMatrix * ViewMatrix;

	update_axes();
	update_axes2();
	glutPostRedisplay();
}

void cleanup(void) {
	glDeleteVertexArrays(1, &VAO_axes);
	glDeleteBuffers(1, &VBO_axes);

	glDeleteVertexArrays(1, &VAO_axes2);
	glDeleteBuffers(1, &VBO_axes2);

	glDeleteVertexArrays(1, &VAO_airplane);
	glDeleteBuffers(1, &VBO_airplane);

	glDeleteVertexArrays(1, &VAO_house);
	glDeleteBuffers(1, &VBO_house);

	glDeleteVertexArrays(1, &VAO_knight);
	glDeleteBuffers(1, &VBO_knight);

	glDeleteVertexArrays(1, &VAO_sword);
	glDeleteBuffers(1, &VBO_sword);

	glDeleteVertexArrays(1, &VAO_cake);
	glDeleteBuffers(1, &VBO_cake);
}

void register_callbacks(void) {
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutMotionFunc(motion);
	glutReshapeFunc(reshape);
	glutTimerFunc(10, timer, 0);
	glutCloseFunc(cleanup);
}

void prepare_shader_program(void) {
	ShaderInfo shader_info[3] = {
		{ GL_VERTEX_SHADER, "Shaders/simple.vert" },
		{ GL_FRAGMENT_SHADER, "Shaders/simple.frag" },
		{ GL_NONE, NULL }
	};

	h_ShaderProgram = LoadShaders(shader_info);
	glUseProgram(h_ShaderProgram);

	loc_ModelViewProjectionMatrix = glGetUniformLocation(h_ShaderProgram, "u_ModelViewProjectionMatrix");
	loc_primitive_color = glGetUniformLocation(h_ShaderProgram, "u_primitive_color");
}

void initialize_OpenGL(void) {
	glEnable(GL_MULTISAMPLE); 
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	
	glClearColor(44 / 255.0f, 180 / 255.0f, 49 / 255.0f, 1.0f);
	ViewMatrix = glm::mat4(1.0f);
}

void prepare_scene(void) {
	prepare_axes();
	prepare_axes2();
	prepare_road();
	prepare_airplane();
	prepare_house();
	prepare_knight();
	prepare_sword();
	prepare_car2();
	prepare_cake();
	prepare_cocktail();
}

void initialize_renderer(void) {
	register_callbacks();
	prepare_shader_program(); 
	initialize_OpenGL();
	prepare_scene();
}

void initialize_glew(void) {
	GLenum error;

	glewExperimental = GL_TRUE;

    error = glewInit();
	if (error != GLEW_OK) { 
		fprintf(stderr, "Error: %s\n", glewGetErrorString(error));
		exit(-1);
	}
	fprintf(stdout, "*********************************************************\n");
	fprintf(stdout, " - GLEW version supported: %s\n", glewGetString(GLEW_VERSION));
	fprintf(stdout, " - OpenGL renderer: %s\n", glGetString(GL_RENDERER));
	fprintf(stdout, " - OpenGL version supported: %s\n", glGetString(GL_VERSION));
	fprintf(stdout, "*********************************************************\n\n");
}

void greetings(char *program_name, char messages[][256], int n_message_lines) {
	fprintf(stdout, "**************************************************************\n\n");
	fprintf(stdout, "  PROGRAM NAME: %s\n\n", program_name);
	fprintf(stdout, "    This program was coded for CSE4170 students\n");
	fprintf(stdout, "      of Dept. of Comp. Sci. & Eng., Sogang University.\n\n");

	for (int i = 0; i < n_message_lines; i++)
		fprintf(stdout, "%s\n", messages[i]);
	fprintf(stdout, "\n**************************************************************\n\n");

	initialize_glew();
}

#define N_MESSAGE_LINES 2
int main(int argc, char *argv[]) {
	char program_name[64] = "Sogang CSE4170 Simple2DTransformationMotion_GLSL_3.0.3";
	char messages[N_MESSAGE_LINES][256] = {
		"    - Keys used: 'ESC'"
	};

	glutInit (&argc, argv);
 	glutInitDisplayMode(GLUT_RGBA | GLUT_MULTISAMPLE);
	glutInitWindowSize (1200, 800);
	glutInitContextVersion(3, 3);
	glutInitContextProfile(GLUT_CORE_PROFILE);
	glutCreateWindow(program_name);

	greetings(program_name, messages, N_MESSAGE_LINES);
	initialize_renderer();

	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	glutMainLoop();
}


