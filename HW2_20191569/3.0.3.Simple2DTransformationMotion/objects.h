#pragma once
GLfloat axes[4][2];
GLfloat axes_color[3] = { 0.0f, 0.0f, 0.0f };
GLuint VBO_axes, VAO_axes;

void prepare_axes(void) { // Draw axes in their MC.
	/*axes[0][0] = -win_width / 2.5f ; axes[0][1] = 0.0f;
	axes[1][0] = win_width / 2.5f; axes[1][1] = 0.0f;*/
	axes[0][0] = 0.0f-200; axes[0][1] = -win_height / 2.5f;
	axes[1][0] = 0.0f-50; axes[1][1] = win_height / 2.5f;
	axes[2][0] = 0.0f+200; axes[2][1] = -win_height / 2.5f;
	axes[3][0] = 0.0f+50; axes[3][1] = win_height / 2.5f;
	// Initialize vertex buffer object.
	glGenBuffers(1, &VBO_axes);

	glBindBuffer(GL_ARRAY_BUFFER, VBO_axes);
	glBufferData(GL_ARRAY_BUFFER, sizeof(axes), axes, GL_STATIC_DRAW);

	// Initialize vertex array object.
	glGenVertexArrays(1, &VAO_axes);
	glBindVertexArray(VAO_axes);

	glBindBuffer(GL_ARRAY_BUFFER, VBO_axes);
	glVertexAttribPointer(LOC_VERTEX, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void update_axes(void) {
/*	axes[0][0] = -win_width / 2.5f; 
	axes[1][0] = win_width / 2.5f;*/
	axes[0][1] = -win_height / 2.5f;
	axes[1][1] = win_height / 2.5f;
	axes[2][1] = -win_height / 2.5f;
	axes[3][1] = win_height / 2.5f;
	
	glBindBuffer(GL_ARRAY_BUFFER, VBO_axes);
	glBufferData(GL_ARRAY_BUFFER, sizeof(axes), axes, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void draw_axes(void) {
	glUniform3fv(loc_primitive_color, 1, axes_color);
	glBindVertexArray(VAO_axes);
	glDrawArrays(GL_LINES, 0, 4);
	glBindVertexArray(0);
}


GLfloat axes2[4][2];
GLfloat axes_color2[3] = { 1.0f, 1.0f, 1.0f };
GLuint VBO_axes2, VAO_axes2;

void prepare_axes2(void) { // Draw axes in their MC.
	axes2[0][0] = -win_width / 2.5f; axes2[0][1] = 0.0f;
	axes2[1][0] = win_width / 2.5f; axes2[1][1] = 0.0f;
	axes2[2][0] = 0.0f; axes2[2][1] = -win_height / 2.5f;
	axes2[3][0] = 0.0f; axes2[3][1] = win_height / 2.5f;

	// Initialize vertex buffer object.
	glGenBuffers(1, &VBO_axes2);

	glBindBuffer(GL_ARRAY_BUFFER, VBO_axes2);
	glBufferData(GL_ARRAY_BUFFER, sizeof(axes2), axes2, GL_STATIC_DRAW);

	// Initialize vertex array object.
	glGenVertexArrays(1, &VAO_axes2);
	glBindVertexArray(VAO_axes2);

	glBindBuffer(GL_ARRAY_BUFFER, VBO_axes2);
	glVertexAttribPointer(LOC_VERTEX, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void update_axes2(void) {
	axes2[0][0] = -win_width / 2.25f; axes2[1][0] = win_width / 2.25f;
	axes2[2][1] = -win_height / 2.25f;
	axes2[3][1] = win_height / 2.25f;

	glBindBuffer(GL_ARRAY_BUFFER, VBO_axes2);
	glBufferData(GL_ARRAY_BUFFER, sizeof(axes2), axes2, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void draw_axes2(void) {
	glUniform3fv(loc_primitive_color, 1, axes_color2);
	glBindVertexArray(VAO_axes2);
	glDrawArrays(GL_LINES, 0, 4);
	glBindVertexArray(0);
}


#define AIRPLANE_BIG_WING 0
#define AIRPLANE_SMALL_WING 1
#define AIRPLANE_BODY 2
#define AIRPLANE_BACK 3
#define AIRPLANE_SIDEWINDER1 4
#define AIRPLANE_SIDEWINDER2 5
#define AIRPLANE_CENTER 6
GLfloat big_wing[6][2] = { { 0.0, 0.0 }, { -20.0, 15.0 }, { -20.0, 20.0 }, { 0.0, 23.0 }, { 20.0, 20.0 }, { 20.0, 15.0 } };
GLfloat small_wing[6][2] = { { 0.0, -18.0 }, { -11.0, -12.0 }, { -12.0, -7.0 }, { 0.0, -10.0 }, { 12.0, -7.0 }, { 11.0, -12.0 } };
GLfloat body[5][2] = { { 0.0, -25.0 }, { -6.0, 0.0 }, { -6.0, 22.0 }, { 6.0, 22.0 }, { 6.0, 0.0 } };
GLfloat back[5][2] = { { 0.0, 25.0 }, { -7.0, 24.0 }, { -7.0, 21.0 }, { 7.0, 21.0 }, { 7.0, 24.0 } };
GLfloat sidewinder1[5][2] = { { -20.0, 10.0 }, { -18.0, 3.0 }, { -16.0, 10.0 }, { -18.0, 20.0 }, { -20.0, 20.0 } };
GLfloat sidewinder2[5][2] = { { 20.0, 10.0 }, { 18.0, 3.0 }, { 16.0, 10.0 }, { 18.0, 20.0 }, { 20.0, 20.0 } };
GLfloat center[1][2] = { { 0.0, 0.0 } };
GLfloat airplane_color[7][3] = {
	{ 150 / 255.0f, 129 / 255.0f, 183 / 255.0f },  // big_wing
	{ 245 / 255.0f, 211 / 255.0f,   0 / 255.0f },  // small_wing
	{ 111 / 255.0f,  85 / 255.0f, 157 / 255.0f },  // body
	{ 150 / 255.0f, 129 / 255.0f, 183 / 255.0f },  // back
	{ 245 / 255.0f, 211 / 255.0f,   0 / 255.0f },  // sidewinder1
	{ 245 / 255.0f, 211 / 255.0f,   0 / 255.0f },  // sidewinder2
	{ 255 / 255.0f,   0 / 255.0f,   0 / 255.0f }   // center
};

GLuint VBO_airplane, VAO_airplane;

#define AIRPLANE_ROTATION_RADIUS 200.0f
float airplane_s_factor = 1.0f;

void prepare_airplane() {
	GLsizeiptr buffer_size = sizeof(big_wing) + sizeof(small_wing) + sizeof(body) + sizeof(back)
		+ sizeof(sidewinder1) + sizeof(sidewinder2) + sizeof(center);

	// Initialize vertex buffer object.
	glGenBuffers(1, &VBO_airplane);

	glBindBuffer(GL_ARRAY_BUFFER, VBO_airplane);
	glBufferData(GL_ARRAY_BUFFER, buffer_size, NULL, GL_STATIC_DRAW); // allocate buffer object memory

	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(big_wing), big_wing);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(big_wing), sizeof(small_wing), small_wing);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(big_wing) + sizeof(small_wing), sizeof(body), body);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(big_wing) + sizeof(small_wing) + sizeof(body), sizeof(back), back);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(big_wing) + sizeof(small_wing) + sizeof(body) + sizeof(back),
		sizeof(sidewinder1), sidewinder1);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(big_wing) + sizeof(small_wing) + sizeof(body) + sizeof(back)
		+ sizeof(sidewinder1), sizeof(sidewinder2), sidewinder2);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(big_wing) + sizeof(small_wing) + sizeof(body) + sizeof(back)
		+ sizeof(sidewinder1) + sizeof(sidewinder2), sizeof(center), center);

	// Initialize vertex array object.
	glGenVertexArrays(1, &VAO_airplane);
	glBindVertexArray(VAO_airplane);

	glBindBuffer(GL_ARRAY_BUFFER, VBO_airplane);
	glVertexAttribPointer(LOC_VERTEX, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void draw_airplane() { // Draw airplane in its MC.
	glBindVertexArray(VAO_airplane);

	glUniform3fv(loc_primitive_color, 1, airplane_color[AIRPLANE_BIG_WING]);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 6);

	glUniform3fv(loc_primitive_color, 1, airplane_color[AIRPLANE_SMALL_WING]);
	glDrawArrays(GL_TRIANGLE_FAN, 6, 6);

	glUniform3fv(loc_primitive_color, 1, airplane_color[AIRPLANE_BODY]);
	glDrawArrays(GL_TRIANGLE_FAN, 12, 5);

	glUniform3fv(loc_primitive_color, 1, airplane_color[AIRPLANE_BACK]);
	glDrawArrays(GL_TRIANGLE_FAN, 17, 5);

	glUniform3fv(loc_primitive_color, 1, airplane_color[AIRPLANE_SIDEWINDER1]);
	glDrawArrays(GL_TRIANGLE_FAN, 22, 5);

	glUniform3fv(loc_primitive_color, 1, airplane_color[AIRPLANE_SIDEWINDER2]);
	glDrawArrays(GL_TRIANGLE_FAN, 27, 5);

	glUniform3fv(loc_primitive_color, 1, airplane_color[AIRPLANE_CENTER]);
	glPointSize(5.0);
	glDrawArrays(GL_POINTS, 32, 1);
	glPointSize(1.0);
	glBindVertexArray(0);
}

//house
#define HOUSE_ROOF 0
#define HOUSE_BODY 1
#define HOUSE_CHIMNEY 2
#define HOUSE_DOOR 3
#define HOUSE_WINDOW 4

GLfloat roof[3][2] = { { -12.0, 0.0 },{ 0.0, 12.0 },{ 12.0, 0.0 } };
GLfloat house_body[4][2] = { { -12.0, -14.0 },{ -12.0, 0.0 },{ 12.0, 0.0 },{ 12.0, -14.0 } };
GLfloat chimney[4][2] = { { 6.0, 6.0 },{ 6.0, 14.0 },{ 10.0, 14.0 },{ 10.0, 2.0 } };
GLfloat door[4][2] = { { -8.0, -14.0 },{ -8.0, -8.0 },{ -4.0, -8.0 },{ -4.0, -14.0 } };
GLfloat window[4][2] = { { 4.0, -6.0 },{ 4.0, -2.0 },{ 8.0, -2.0 },{ 8.0, -6.0 } };

GLfloat house_color[5][3] = {
	{ 200 / 255.0f, 39 / 255.0f, 42 / 255.0f },
	{ 235 / 255.0f, 225 / 255.0f, 196 / 255.0f },
	{ 255 / 255.0f, 0 / 255.0f, 0 / 255.0f },
	{ 233 / 255.0f, 113 / 255.0f, 23 / 255.0f },
	{ 44 / 255.0f, 180 / 255.0f, 49 / 255.0f }
};

GLuint VBO_house, VAO_house;
void prepare_house() {
	GLsizeiptr buffer_size = sizeof(roof) + sizeof(house_body) + sizeof(chimney) + sizeof(door)
		+ sizeof(window);

	// Initialize vertex buffer object.
	glGenBuffers(1, &VBO_house);

	glBindBuffer(GL_ARRAY_BUFFER, VBO_house);
	glBufferData(GL_ARRAY_BUFFER, buffer_size, NULL, GL_STATIC_DRAW); // allocate buffer object memory

	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(roof), roof);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(roof), sizeof(house_body), house_body);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(roof) + sizeof(house_body), sizeof(chimney), chimney);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(roof) + sizeof(house_body) + sizeof(chimney), sizeof(door), door);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(roof) + sizeof(house_body) + sizeof(chimney) + sizeof(door),
		sizeof(window), window);

	// Initialize vertex array object.
	glGenVertexArrays(1, &VAO_house);
	glBindVertexArray(VAO_house);

	glBindBuffer(GL_ARRAY_BUFFER, VBO_house);
	glVertexAttribPointer(LOC_VERTEX, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void draw_house() {
	glBindVertexArray(VAO_house);

	glUniform3fv(loc_primitive_color, 1, house_color[HOUSE_ROOF]);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 3);

	glUniform3fv(loc_primitive_color, 1, house_color[HOUSE_BODY]);
	glDrawArrays(GL_TRIANGLE_FAN, 3, 4);

	glUniform3fv(loc_primitive_color, 1, house_color[HOUSE_CHIMNEY]);
	glDrawArrays(GL_TRIANGLE_FAN, 7, 4);

	glUniform3fv(loc_primitive_color, 1, house_color[HOUSE_DOOR]);
	glDrawArrays(GL_TRIANGLE_FAN, 11, 4);

	glUniform3fv(loc_primitive_color, 1, house_color[HOUSE_WINDOW]);
	glDrawArrays(GL_TRIANGLE_FAN, 15, 4);

	glBindVertexArray(0);
}


//knight
/*(#define HOUSE_ROOF 0
#define HOUSE_BODY 1
#define HOUSE_CHIMNEY 2
#define HOUSE_DOOR 3
#define HOUSE_WINDOW 4*/

GLfloat knighttop[6][2] = { {15.0,0.0},{20.0, 7.0},{20.0,50.0},{-20.0,50.0},{-20.0, 7.0},{-15.0,0.0} };
GLfloat knighthead[6][2] = { {15.0,50.0},{15.0, 70.0},{10.0,75.0},{-10.0,75.0},{-15.0, 70.0},{-15.0,50.0} };
GLfloat knightbottom[4][2] = { {15.0,0.0},{20.0,-30.0},{-20.0,-30.0},{-15.0,0.0}};
GLfloat knightrleg[4][2] = { {2.0,-30.0 },{ 15.0,-30.0 },{ 15.0, -100.0 },{2.0,-100.0} };
GLfloat knightlleg[4][2] = { {-2.0,-30.0 },{ -15.0,-30.0 },{ -15.0, -100.0 },{-2.0,-100.0} };
GLfloat kngihtrfoot[4][2] = { {2.0,-100.0},{27.0, -100.0},{27.0,-113.0},{2.0,-113.0} };
GLfloat kngihtlfoot[4][2] = { {-2.0,-100.0},{-27.0, -100.0},{-27.0,-113.0},{-2.0,-113.0} };
GLfloat knightrgurad[8][2] = { {2.0,-60.0},{6.0,-55.0},{11.0,-55.0},{15.0,-60.0},{15.0,-68.0},{11.0,-73.0},{6.0,-73.0},{2.0,-68.0} };
GLfloat knightlgurad[8][2] = { {-2.0,-60.0},{-6.0,-55.0},{-11.0,-55.0},{-15.0,-60.0},{-15.0,-68.0},{-11.0,-73.0},{-6.0,-73.0},{-2.0,-68.0} };
GLfloat knightfaceone[4][2] = { {2.0,66.0},{2.0,53.0},{-2.0,53.0},{-2.0, 66.0} };
GLfloat knightfacetwo[4][2] = { {7.0,53.0},{11.0,53.0},{11.0,66.0},{7.0,66.0} };
GLfloat knightfacethree[4][2] = { {-7.0,53.0},{-11.0,53.0},{-11.0,66.0},{-7.0,66.0} };
GLfloat knighttoprarm[4][2] = { {20.0,50.0},{30.0,50.0},{35.0,10.0},{25.0,10.0} };
GLfloat knighttoplarm[4][2] = { {-20.0,50.0},{-30.0,50.0},{-35.0,10.0},{-25.0,10.0} };
GLfloat knightbottomrarm[4][2] = { {1.0,-8.0},{9.0,-17.0},{35.0,10.0} ,{27.0,20.0}};
GLfloat knightbottomlarm[4][2] = { {-1.0,-8.0},{-9.0,-17.0},{-35.0,10.0},{-27.0,20.0} };
GLfloat knightrshoulder[8][2] = { {17.0,50.0},{21.0,55.0},{26.0,55.0},{30.0,50.0},{30.0,42.0},{26.0,37.0},{21.0,37.0},{17.0,42.0,} };
GLfloat knightlshoulder[8][2] = { {-17.0,50.0},{-21.0,55.0},{-26.0,55.0},{-30.0,50.0},{-30.0,42.0},{-26.0,37.0},{-21.0,37.0},{-17.0,42.0} };
GLfloat knighttriangle[3][2] = { {20.0,27.0},{0.0,46.0},{-20.0,27.0} };
GLfloat knightrectangleone[4][2] = { {20.0,25.0} ,{20.0,20.0},{-20.0,20.0} ,{-20.0,25.0} };
GLfloat knightrectangletwo[4][2] = { {20.0,11.0} ,{20.0,16.0},{-20.0,16.0} ,{-20.0,11.0} };

GLfloat knight_color[4][3] = {
	{ 171 / 255.0f, 171 / 255.0f, 171 / 255.0f }, //연회색
	{ 127 / 255.0f, 127 / 255.0f, 127 / 255.0f }, //회색
	{ 82 / 255.0f, 82 / 255.0f, 82 / 255.0f }, //진회색
	{ 1 / 255.0f, 1 / 255.0f, 1 / 255.0f } //검정
};

GLuint VBO_knight, VAO_knight;
void prepare_knight() {
	GLsizeiptr buffer_size = sizeof(knighttop) + sizeof(knighthead) + sizeof(knightbottom) + sizeof(knightrleg) + sizeof(knightlleg) + sizeof(kngihtrfoot) + sizeof(kngihtlfoot) + sizeof(knightrgurad) + sizeof(knightlgurad) + sizeof(knightrshoulder) + sizeof(knightlshoulder) + sizeof(knightfaceone) + sizeof(knightfacetwo) + sizeof(knightfacethree) +sizeof(knighttoprarm) + sizeof(knighttoplarm) + sizeof(knightbottomrarm) + sizeof(knightbottomlarm) + sizeof(knighttriangle) +sizeof(knightrectangleone) + sizeof(knightrectangletwo);

	// Initialize vertex buffer object.
	glGenBuffers(1, &VBO_knight);

	glBindBuffer(GL_ARRAY_BUFFER, VBO_knight);
	glBufferData(GL_ARRAY_BUFFER, buffer_size, NULL, GL_STATIC_DRAW); // allocate buffer object memory

	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(knighttop), knighttop);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(knighttop) , sizeof(knighthead), knighthead );
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(knighttop) + sizeof(knighthead) , sizeof(knightbottom) , knightbottom);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(knighttop) + sizeof(knighthead) + sizeof(knightbottom) , sizeof(knightrleg) , knightrleg);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(knighttop) + sizeof(knighthead) + sizeof(knightbottom) + sizeof(knightrleg) , sizeof(knightlleg) , knightlleg);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(knighttop) + sizeof(knighthead) + sizeof(knightbottom) + sizeof(knightrleg) + sizeof(knightlleg) , sizeof(kngihtrfoot) , kngihtrfoot);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(knighttop) + sizeof(knighthead) + sizeof(knightbottom) + sizeof(knightrleg) + sizeof(knightlleg) + sizeof(kngihtrfoot) , sizeof(kngihtlfoot) , kngihtlfoot);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(knighttop) + sizeof(knighthead) + sizeof(knightbottom) + sizeof(knightrleg) + sizeof(knightlleg) + sizeof(kngihtrfoot) +  sizeof(kngihtlfoot) , sizeof(knightrgurad) , knightrgurad);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(knighttop) + sizeof(knighthead) + sizeof(knightbottom) + sizeof(knightrleg) + sizeof(knightlleg) + sizeof(kngihtrfoot) + sizeof(kngihtlfoot) + sizeof(knightrgurad) , sizeof(knightlgurad) , knightlgurad);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(knighttop) + sizeof(knighthead) + sizeof(knightbottom) + sizeof(knightrleg) + sizeof(knightlleg) + sizeof(kngihtrfoot) + sizeof(kngihtlfoot) + sizeof(knightrgurad) + sizeof(knightlgurad) , sizeof(knightfaceone) , knightfaceone);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(knighttop) + sizeof(knighthead) + sizeof(knightbottom) + sizeof(knightrleg) + sizeof(knightlleg) + sizeof(kngihtrfoot) + sizeof(kngihtlfoot) + sizeof(knightrgurad) + sizeof(knightlgurad) + sizeof(knightfaceone) , sizeof(knightfacetwo) , knightfacetwo);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(knighttop) + sizeof(knighthead) + sizeof(knightbottom) + sizeof(knightrleg) + sizeof(knightlleg) + sizeof(kngihtrfoot) + sizeof(kngihtlfoot) + sizeof(knightrgurad) + sizeof(knightlgurad) + sizeof(knightfaceone) + sizeof(knightfacetwo) , sizeof(knightfacethree), knightfacethree);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(knighttop) + sizeof(knighthead) + sizeof(knightbottom) + sizeof(knightrleg) + sizeof(knightlleg) + sizeof(kngihtrfoot) + sizeof(kngihtlfoot) + sizeof(knightrgurad) + sizeof(knightlgurad) + sizeof(knightfaceone) + sizeof(knightfacetwo) + sizeof(knightfacethree) , sizeof(knighttoprarm) , knighttoprarm);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(knighttop) + sizeof(knighthead) + sizeof(knightbottom) + sizeof(knightrleg) + sizeof(knightlleg) + sizeof(kngihtrfoot) + sizeof(kngihtlfoot) + sizeof(knightrgurad) + sizeof(knightlgurad) + sizeof(knightfaceone) + sizeof(knightfacetwo) + sizeof(knightfacethree) + sizeof(knighttoprarm) , sizeof(knighttoplarm), knighttoplarm);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(knighttop) + sizeof(knighthead) + sizeof(knightbottom) + sizeof(knightrleg) + sizeof(knightlleg) + sizeof(kngihtrfoot) + sizeof(kngihtlfoot) + sizeof(knightrgurad) + sizeof(knightlgurad) + sizeof(knightfaceone) + sizeof(knightfacetwo) + sizeof(knightfacethree) + sizeof(knighttoprarm) + sizeof(knighttoplarm) , sizeof(knightbottomrarm) , knightbottomrarm);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(knighttop) + sizeof(knighthead) + sizeof(knightbottom) + sizeof(knightrleg) + sizeof(knightlleg) + sizeof(kngihtrfoot) + sizeof(kngihtlfoot) + sizeof(knightrgurad) + sizeof(knightlgurad) + sizeof(knightfaceone) + sizeof(knightfacetwo) + sizeof(knightfacethree) + sizeof(knighttoprarm) + sizeof(knighttoplarm) + sizeof(knightbottomrarm) , sizeof(knightbottomlarm), knightbottomlarm );

	glBufferSubData(GL_ARRAY_BUFFER, sizeof(knighttop) + sizeof(knighthead) + sizeof(knightbottom) + sizeof(knightrleg) + sizeof(knightlleg) + sizeof(kngihtrfoot) + sizeof(kngihtlfoot) + sizeof(knightrgurad) + sizeof(knightlgurad) + sizeof(knightfaceone) + sizeof(knightfacetwo) + sizeof(knightfacethree) + sizeof(knighttoprarm) + sizeof(knighttoplarm) + sizeof(knightbottomrarm) + sizeof(knightbottomlarm), sizeof(knightrshoulder), knightrshoulder);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(knighttop) + sizeof(knighthead) + sizeof(knightbottom) + sizeof(knightrleg) + sizeof(knightlleg) + sizeof(kngihtrfoot) + sizeof(kngihtlfoot) + sizeof(knightrgurad) + sizeof(knightlgurad) + sizeof(knightfaceone) + sizeof(knightfacetwo) + sizeof(knightfacethree) + sizeof(knighttoprarm) + sizeof(knighttoplarm) + sizeof(knightbottomrarm) + sizeof(knightbottomlarm) + sizeof(knightrshoulder), sizeof(knightlshoulder), knightlshoulder);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(knighttop) + sizeof(knighthead) + sizeof(knightbottom) + sizeof(knightrleg) + sizeof(knightlleg) + sizeof(kngihtrfoot) + sizeof(kngihtlfoot) + sizeof(knightrgurad) + sizeof(knightlgurad) + sizeof(knightrshoulder) + sizeof(knightlshoulder) + sizeof(knightfaceone) + sizeof(knightfacetwo) + sizeof(knightfacethree) + sizeof(knighttoprarm) + sizeof(knighttoplarm) + sizeof(knightbottomrarm) + sizeof(knightbottomlarm) , sizeof(knighttriangle), knighttriangle);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(knighttop) + sizeof(knighthead) + sizeof(knightbottom) + sizeof(knightrleg) + sizeof(knightlleg) + sizeof(kngihtrfoot) + sizeof(kngihtlfoot) + sizeof(knightrgurad) + sizeof(knightlgurad) + sizeof(knightrshoulder) + sizeof(knightlshoulder) + sizeof(knightfaceone) + sizeof(knightfacetwo) + sizeof(knightfacethree) + sizeof(knighttoprarm) + sizeof(knighttoplarm) + sizeof(knightbottomrarm) + sizeof(knightbottomlarm) + sizeof(knighttriangle) ,sizeof(knightrectangleone), knightrectangleone);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(knighttop) + sizeof(knighthead) + sizeof(knightbottom) + sizeof(knightrleg) + sizeof(knightlleg) + sizeof(kngihtrfoot) + sizeof(kngihtlfoot) + sizeof(knightrgurad) + sizeof(knightlgurad) + sizeof(knightrshoulder) + sizeof(knightlshoulder) + sizeof(knightfaceone) + sizeof(knightfacetwo) + sizeof(knightfacethree) + sizeof(knighttoprarm) + sizeof(knighttoplarm) + sizeof(knightbottomrarm) + sizeof(knightbottomlarm) + sizeof(knighttriangle) + sizeof(knightrectangleone) , sizeof(knightrectangletwo), knightrectangletwo);
	// Initialize vertex array object.
	glGenVertexArrays(1, &VAO_knight);
	glBindVertexArray(VAO_knight);

	glBindBuffer(GL_ARRAY_BUFFER, VBO_knight);
	glVertexAttribPointer(LOC_VERTEX, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void draw_knight() {
	glBindVertexArray(VAO_knight);

	glUniform3fv(loc_primitive_color, 1, knight_color[0]); //knighttop
	glDrawArrays(GL_TRIANGLE_FAN, 0, 6);

	glUniform3fv(loc_primitive_color, 1, knight_color[1]);
	glDrawArrays(GL_TRIANGLE_FAN, 6, 6);

	glUniform3fv(loc_primitive_color, 1, knight_color[0]);
	glDrawArrays(GL_TRIANGLE_FAN, 12, 4);

	glUniform3fv(loc_primitive_color, 1, knight_color[1]);//knighrtreg
	glDrawArrays(GL_TRIANGLE_FAN, 16, 4);

	glUniform3fv(loc_primitive_color, 1, knight_color[1]);
	glDrawArrays(GL_TRIANGLE_FAN, 20, 4);

	glUniform3fv(loc_primitive_color, 1, knight_color[3]); //knightrfoot
	glDrawArrays(GL_TRIANGLE_FAN, 24, 4);

	glUniform3fv(loc_primitive_color, 1, knight_color[3]);
	glDrawArrays(GL_TRIANGLE_FAN, 28, 4);

	glUniform3fv(loc_primitive_color, 1, knight_color[2]);//knightgurad
	glDrawArrays(GL_TRIANGLE_FAN, 32, 8);

	glUniform3fv(loc_primitive_color, 1, knight_color[2]);
	glDrawArrays(GL_TRIANGLE_FAN, 40, 8);

	glUniform3fv(loc_primitive_color, 1, knight_color[3]);//knightface
	glDrawArrays(GL_TRIANGLE_FAN, 48, 4);

	glUniform3fv(loc_primitive_color, 1, knight_color[3]);
	glDrawArrays(GL_TRIANGLE_FAN, 52, 4);

	glUniform3fv(loc_primitive_color, 1, knight_color[3]);
	glDrawArrays(GL_TRIANGLE_FAN, 56, 4);

	glUniform3fv(loc_primitive_color, 1, knight_color[1]);//knighttoprarm
	glDrawArrays(GL_TRIANGLE_FAN, 60, 4);

	glUniform3fv(loc_primitive_color, 1, knight_color[1]);
	glDrawArrays(GL_TRIANGLE_FAN, 64, 4);

	glUniform3fv(loc_primitive_color, 1, knight_color[1]);
	glDrawArrays(GL_TRIANGLE_FAN, 68, 4);

	glUniform3fv(loc_primitive_color, 1, knight_color[1]);
	glDrawArrays(GL_TRIANGLE_FAN, 72, 4);

	glUniform3fv(loc_primitive_color, 1, knight_color[2]);//knightrshoulder
	glDrawArrays(GL_TRIANGLE_FAN, 76, 8);

	glUniform3fv(loc_primitive_color, 1, knight_color[2]);
	glDrawArrays(GL_TRIANGLE_FAN, 84, 8);

	glUniform3fv(loc_primitive_color, 1, knight_color[2]); //knighttriangle
	glDrawArrays(GL_TRIANGLE_FAN, 92, 3);

	glUniform3fv(loc_primitive_color, 1, knight_color[1]);
	glDrawArrays(GL_TRIANGLE_FAN, 95, 4);

	glUniform3fv(loc_primitive_color, 1, knight_color[1]);
	glDrawArrays(GL_TRIANGLE_FAN, 99, 4);

	glBindVertexArray(0);
}

#define SWORD_BODY 0
#define SWORD_BODY2 1
#define SWORD_HEAD 2
#define SWORD_HEAD2 3
#define SWORD_IN 4
#define SWORD_DOWN 5
#define SWORD_BODY_IN 6

GLfloat sword_body[4][2] = { { -6.0, 0.0 },{ -6.0, -4.0 },{ 6.0, -4.0 },{ 6.0, 0.0 } };
GLfloat sword_body2[4][2] = { { -2.0, -4.0 },{ -2.0, -6.0 } ,{ 2.0, -6.0 },{ 2.0, -4.0 } };
GLfloat sword_head[4][2] = { { -2.0, 0.0 },{ -2.0, 16.0 } ,{ 2.0, 16.0 },{ 2.0, 0.0 } };
GLfloat sword_head2[3][2] = { { -2.0, 16.0 },{ 0.0, 19.46 } ,{ 2.0, 16.0 } };
GLfloat sword_in[4][2] = { { -0.3, 0.7 },{ -0.3, 15.3 } ,{ 0.3, 15.3 },{ 0.3, 0.7 } };
GLfloat sword_down[4][2] = { { -2.0, -6.0 } ,{ 2.0, -6.0 },{ 4.0, -8.0 },{ -4.0, -8.0 } };
GLfloat sword_body_in[4][2] = { { 0.0, -1.0 } ,{ 1.0, -2.732 },{ 0.0, -4.464 },{ -1.0, -2.732 } };

GLfloat sword_color[7][3] = {
	{ 139 / 255.0f, 69 / 255.0f, 19 / 255.0f },
{ 139 / 255.0f, 69 / 255.0f, 19 / 255.0f },
{ 155 / 255.0f, 155 / 255.0f, 155 / 255.0f },
{ 155 / 255.0f, 155 / 255.0f, 155 / 255.0f },
{ 0 / 255.0f, 0 / 255.0f, 0 / 255.0f },
{ 139 / 255.0f, 69 / 255.0f, 19 / 255.0f },
{ 255 / 255.0f, 0 / 255.0f, 0 / 255.0f }
};

GLuint VBO_sword, VAO_sword;

void prepare_sword() {
	GLsizeiptr buffer_size = sizeof(sword_body) + sizeof(sword_body2) + sizeof(sword_head) + sizeof(sword_head2) + sizeof(sword_in) + sizeof(sword_down) + sizeof(sword_body_in);

	// Initialize vertex buffer object.
	glGenBuffers(1, &VBO_sword);

	glBindBuffer(GL_ARRAY_BUFFER, VBO_sword);
	glBufferData(GL_ARRAY_BUFFER, buffer_size, NULL, GL_STATIC_DRAW); // allocate buffer object memory

	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(sword_body), sword_body);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(sword_body), sizeof(sword_body2), sword_body2);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(sword_body) + sizeof(sword_body2), sizeof(sword_head), sword_head);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(sword_body) + sizeof(sword_body2) + sizeof(sword_head), sizeof(sword_head2), sword_head2);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(sword_body) + sizeof(sword_body2) + sizeof(sword_head) + sizeof(sword_head2), sizeof(sword_in), sword_in);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(sword_body) + sizeof(sword_body2) + sizeof(sword_head) + sizeof(sword_head2) + sizeof(sword_in), sizeof(sword_down), sword_down);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(sword_body) + sizeof(sword_body2) + sizeof(sword_head) + sizeof(sword_head2) + sizeof(sword_in) + sizeof(sword_down), sizeof(sword_body_in), sword_body_in);

	// Initialize vertex array object.
	glGenVertexArrays(1, &VAO_sword);
	glBindVertexArray(VAO_sword);

	glBindBuffer(GL_ARRAY_BUFFER, VBO_sword);
	glVertexAttribPointer(LOC_VERTEX, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void draw_sword() {
	glBindVertexArray(VAO_sword);

	glUniform3fv(loc_primitive_color, 1, sword_color[SWORD_BODY]);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

	glUniform3fv(loc_primitive_color, 1, sword_color[SWORD_BODY2]);
	glDrawArrays(GL_TRIANGLE_FAN, 4, 4);

	glUniform3fv(loc_primitive_color, 1, sword_color[SWORD_HEAD]);
	glDrawArrays(GL_TRIANGLE_FAN, 8, 4);

	glUniform3fv(loc_primitive_color, 1, sword_color[SWORD_HEAD2]);
	glDrawArrays(GL_TRIANGLE_FAN, 12, 3);

	glUniform3fv(loc_primitive_color, 1, sword_color[SWORD_IN]);
	glDrawArrays(GL_TRIANGLE_FAN, 15, 4);

	glUniform3fv(loc_primitive_color, 1, sword_color[SWORD_DOWN]);
	glDrawArrays(GL_TRIANGLE_FAN, 19, 4);

	glUniform3fv(loc_primitive_color, 1, sword_color[SWORD_BODY_IN]);
	glDrawArrays(GL_TRIANGLE_FAN, 23, 4);

	glBindVertexArray(0);
}

#define CAR2_BODY 0
#define CAR2_FRONT_WINDOW 1
#define CAR2_BACK_WINDOW 2
#define CAR2_FRONT_WHEEL 3
#define CAR2_BACK_WHEEL 4
#define CAR2_LIGHT1 5
#define CAR2_LIGHT2 6

GLfloat car2_body[8][2] = { { -18.0, -7.0 },{ -18.0, 0.0 },{ -13.0, 0.0 },{ -10.0, 8.0 },{ 10.0, 8.0 },{ 13.0, 0.0 },{ 18.0, 0.0 },{ 18.0, -7.0 } };
GLfloat car2_front_window[4][2] = { { -10.0, 0.0 },{ -8.0, 6.0 },{ -2.0, 6.0 },{ -2.0, 0.0 } };
GLfloat car2_back_window[4][2] = { { 0.0, 0.0 },{ 0.0, 6.0 },{ 8.0, 6.0 },{ 10.0, 0.0 } };
GLfloat car2_front_wheel[8][2] = { { -11.0, -11.0 },{ -13.0, -8.0 },{ -13.0, -7.0 },{ -11.0, -4.0 },{ -7.0, -4.0 },{ -5.0, -7.0 },{ -5.0, -8.0 },{ -7.0, -11.0 } };
GLfloat car2_back_wheel[8][2] = { { 7.0, -11.0 },{ 5.0, -8.0 },{ 5.0, -7.0 },{ 7.0, -4.0 },{ 11.0, -4.0 },{ 13.0, -7.0 },{ 13.0, -8.0 },{ 11.0, -11.0 } };
GLfloat car2_light1[3][2] = { { -18.0, -1.0 },{ -17.0, -2.0 },{ -18.0, -3.0 } };
GLfloat car2_light2[3][2] = { { -18.0, -4.0 },{ -17.0, -5.0 },{ -18.0, -6.0 } };

GLfloat car2_color[7][3] = {
	{ 100 / 255.0f, 141 / 255.0f, 159 / 255.0f },
	{ 235 / 255.0f, 219 / 255.0f, 208 / 255.0f },
	{ 235 / 255.0f, 219 / 255.0f, 208 / 255.0f },
	{ 0 / 255.0f, 0 / 255.0f, 0 / 255.0f },
	{ 0 / 255.0f, 0 / 255.0f, 0 / 255.0f },
	{ 249 / 255.0f, 244 / 255.0f, 0 / 255.0f },
	{ 249 / 255.0f, 244 / 255.0f, 0 / 255.0f }
};

GLuint VBO_car2, VAO_car2;
void prepare_car2() {
	GLsizeiptr buffer_size = sizeof(car2_body) + sizeof(car2_front_window) + sizeof(car2_back_window) + sizeof(car2_front_wheel)
		+ sizeof(car2_back_wheel) + sizeof(car2_light1) + sizeof(car2_light2);

	// Initialize vertex buffer object.
	glGenBuffers(1, &VBO_car2);

	glBindBuffer(GL_ARRAY_BUFFER, VBO_car2);
	glBufferData(GL_ARRAY_BUFFER, buffer_size, NULL, GL_STATIC_DRAW); // allocate buffer object memory

	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(car2_body), car2_body);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(car2_body), sizeof(car2_front_window), car2_front_window);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(car2_body) + sizeof(car2_front_window), sizeof(car2_back_window), car2_back_window);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(car2_body) + sizeof(car2_front_window) + sizeof(car2_back_window), sizeof(car2_front_wheel), car2_front_wheel);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(car2_body) + sizeof(car2_front_window) + sizeof(car2_back_window) + sizeof(car2_front_wheel),
		sizeof(car2_back_wheel), car2_back_wheel);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(car2_body) + sizeof(car2_front_window) + sizeof(car2_back_window) + sizeof(car2_front_wheel)
		+ sizeof(car2_back_wheel), sizeof(car2_light1), car2_light1);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(car2_body) + sizeof(car2_front_window) + sizeof(car2_back_window) + sizeof(car2_front_wheel)
		+ sizeof(car2_back_wheel) + sizeof(car2_light1), sizeof(car2_light2), car2_light2);

	// Initialize vertex array object.
	glGenVertexArrays(1, &VAO_car2);
	glBindVertexArray(VAO_car2);

	glBindBuffer(GL_ARRAY_BUFFER, VBO_car2);
	glVertexAttribPointer(LOC_VERTEX, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void draw_car2() {
	glBindVertexArray(VAO_car2);

	glUniform3fv(loc_primitive_color, 1, car2_color[CAR2_BODY]);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 8);

	glUniform3fv(loc_primitive_color, 1, car2_color[CAR2_FRONT_WINDOW]);
	glDrawArrays(GL_TRIANGLE_FAN, 8, 4);

	glUniform3fv(loc_primitive_color, 1, car2_color[CAR2_BACK_WINDOW]);
	glDrawArrays(GL_TRIANGLE_FAN, 12, 4);

	glUniform3fv(loc_primitive_color, 1, car2_color[CAR2_FRONT_WHEEL]);
	glDrawArrays(GL_TRIANGLE_FAN, 16, 8);

	glUniform3fv(loc_primitive_color, 1, car2_color[CAR2_BACK_WHEEL]);
	glDrawArrays(GL_TRIANGLE_FAN, 24, 8);

	glUniform3fv(loc_primitive_color, 1, car2_color[CAR2_LIGHT1]);
	glDrawArrays(GL_TRIANGLE_FAN, 32, 3);

	glUniform3fv(loc_primitive_color, 1, car2_color[CAR2_LIGHT2]);
	glDrawArrays(GL_TRIANGLE_FAN, 35, 3);

	glBindVertexArray(0);
}

#define CAKE_FIRE 0
#define CAKE_CANDLE 1
#define CAKE_BODY 2
#define CAKE_BOTTOM 3
#define CAKE_DECORATE 4

GLfloat cake_fire[4][2] = { { -0.5, 14.0 },{ -0.5, 13.0 },{ 0.5, 13.0 },{ 0.5, 14.0 } };
GLfloat cake_candle[4][2] = { { -1.0, 8.0 } ,{ -1.0, 13.0 },{ 1.0, 13.0 },{ 1.0, 8.0 } };
GLfloat cake_body[4][2] = { { 8.0, 5.0 },{ -8.0, 5.0 } ,{ -8.0, 8.0 },{ 8.0, 8.0 } };
GLfloat cake_bottom[4][2] = { { -10.0, 1.0 },{ -10.0, 5.0 },{ 10.0, 5.0 },{ 10.0, 1.0 } };
GLfloat cake_decorate[4][2] = { { -10.0, 0.0 },{ -10.0, 1.0 },{ 10.0, 1.0 },{ 10.0, 0.0 } };

GLfloat cake_color[5][3] = {
	{ 255 / 255.0f, 0 / 255.0f, 0 / 255.0f },
{ 255 / 255.0f, 204 / 255.0f, 0 / 255.0f },
{ 255 / 255.0f, 102 / 255.0f, 255 / 255.0f },
{ 255 / 255.0f, 102 / 255.0f, 255 / 255.0f },
{ 102 / 255.0f, 51 / 255.0f, 0 / 255.0f }
};

GLuint VBO_cake, VAO_cake;

void prepare_cake() {
	int size = sizeof(cake_fire);
	GLsizeiptr buffer_size = sizeof(cake_fire) * 5;

	// Initialize vertex buffer object.
	glGenBuffers(1, &VBO_cake);

	glBindBuffer(GL_ARRAY_BUFFER, VBO_cake);
	glBufferData(GL_ARRAY_BUFFER, buffer_size, NULL, GL_STATIC_DRAW); // allocate buffer object memory

	glBufferSubData(GL_ARRAY_BUFFER, 0, size, cake_fire);
	glBufferSubData(GL_ARRAY_BUFFER, size, size, cake_candle);
	glBufferSubData(GL_ARRAY_BUFFER, size * 2, size, cake_body);
	glBufferSubData(GL_ARRAY_BUFFER, size * 3, size, cake_bottom);
	glBufferSubData(GL_ARRAY_BUFFER, size * 4, size, cake_decorate);

	// Initialize vertex array object.
	glGenVertexArrays(1, &VAO_cake);
	glBindVertexArray(VAO_cake);

	glBindBuffer(GL_ARRAY_BUFFER, VBO_cake);
	glVertexAttribPointer(LOC_VERTEX, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void draw_cake() {
	glBindVertexArray(VAO_cake);

	glUniform3fv(loc_primitive_color, 1, cake_color[CAKE_FIRE]);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

	glUniform3fv(loc_primitive_color, 1, cake_color[CAKE_CANDLE]);
	glDrawArrays(GL_TRIANGLE_FAN, 4, 4);

	glUniform3fv(loc_primitive_color, 1, cake_color[CAKE_BODY]);
	glDrawArrays(GL_TRIANGLE_FAN, 8, 4);

	glUniform3fv(loc_primitive_color, 1, cake_color[CAKE_BOTTOM]);
	glDrawArrays(GL_TRIANGLE_FAN, 12, 4);

	glUniform3fv(loc_primitive_color, 1, cake_color[CAKE_DECORATE]);
	glDrawArrays(GL_TRIANGLE_FAN, 16, 4);

	glBindVertexArray(0);
}

GLfloat road[4][2] = { {-50.0, 400 },{50.0, 400},{200.0, -400},{-200.0,-400} };
GLfloat road_color[1][3] = {
	{200 / 255.0f, 170 / 255.0f, 122 / 255.0f}
};
GLuint VBO_road, VAO_road;
void prepare_road() {
	int size = sizeof(road);
	GLsizeiptr buffer_size = sizeof(road) * 5;

	// Initialize vertex buffer object.
	glGenBuffers(1, &VBO_road);

	glBindBuffer(GL_ARRAY_BUFFER, VBO_road);
	glBufferData(GL_ARRAY_BUFFER, buffer_size, NULL, GL_STATIC_DRAW); // allocate buffer object memory

	glBufferSubData(GL_ARRAY_BUFFER, 0, size, road);

	// Initialize vertex array object.
	glGenVertexArrays(1, &VAO_road);
	glBindVertexArray(VAO_road);

	glBindBuffer(GL_ARRAY_BUFFER, VBO_road);
	glVertexAttribPointer(LOC_VERTEX, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}
void draw_road() {
	glBindVertexArray(VAO_road);

	glUniform3fv(loc_primitive_color, 1, road_color[0]);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

	glBindVertexArray(0);
}
#define COCKTAIL_NECK 0
#define COCKTAIL_LIQUID 1
#define COCKTAIL_REMAIN 2
#define COCKTAIL_STRAW 3
#define COCKTAIL_DECO 4

GLfloat neck[6][2] = { { -6.0, -12.0 },{ -6.0, -11.0 },{ -1.0, 0.0 },{ 1.0, 0.0 },{ 6.0, -11.0 },{ 6.0, -12.0 } };
GLfloat liquid[6][2] = { { -1.0, 0.0 },{ -9.0, 4.0 },{ -12.0, 7.0 },{ 12.0, 7.0 },{ 9.0, 4.0 },{ 1.0, 0.0 } };
GLfloat remain[4][2] = { { -12.0, 7.0 },{ -12.0, 10.0 },{ 12.0, 10.0 },{ 12.0, 7.0 } };
GLfloat straw[4][2] = { { 7.0, 7.0 },{ 12.0, 12.0 },{ 14.0, 12.0 },{ 9.0, 7.0 } };
GLfloat deco[8][2] = { { 12.0, 12.0 },{ 10.0, 14.0 },{ 10.0, 16.0 },{ 12.0, 18.0 },{ 14.0, 18.0 },{ 16.0, 16.0 },{ 16.0, 14.0 },{ 14.0, 12.0 } };

GLfloat cocktail_color[5][3] = {
	{ 235 / 255.0f, 225 / 255.0f, 196 / 255.0f },
	{ 0 / 255.0f, 63 / 255.0f, 122 / 255.0f },
	{ 235 / 255.0f, 225 / 255.0f, 196 / 255.0f },
	{ 191 / 255.0f, 255 / 255.0f, 0 / 255.0f },
	{ 218 / 255.0f, 165 / 255.0f, 32 / 255.0f }
};

GLuint VBO_cocktail, VAO_cocktail;
void prepare_cocktail() {
	GLsizeiptr buffer_size = sizeof(neck) + sizeof(liquid) + sizeof(remain) + sizeof(straw)
		+ sizeof(deco);

	// Initialize vertex buffer object.
	glGenBuffers(1, &VBO_cocktail);

	glBindBuffer(GL_ARRAY_BUFFER, VBO_cocktail);
	glBufferData(GL_ARRAY_BUFFER, buffer_size, NULL, GL_STATIC_DRAW); // allocate buffer object memory

	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(neck), neck);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(neck), sizeof(liquid), liquid);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(neck) + sizeof(liquid), sizeof(remain), remain);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(neck) + sizeof(liquid) + sizeof(remain), sizeof(straw), straw);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(neck) + sizeof(liquid) + sizeof(remain) + sizeof(straw),
		sizeof(deco), deco);

	// Initialize vertex array object.
	glGenVertexArrays(1, &VAO_cocktail);
	glBindVertexArray(VAO_cocktail);

	glBindBuffer(GL_ARRAY_BUFFER, VBO_cocktail);
	glVertexAttribPointer(LOC_VERTEX, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void draw_cocktail() {
	glBindVertexArray(VAO_cocktail);

	glUniform3fv(loc_primitive_color, 1, cocktail_color[COCKTAIL_NECK]);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 6);

	glUniform3fv(loc_primitive_color, 1, cocktail_color[COCKTAIL_LIQUID]);
	glDrawArrays(GL_TRIANGLE_FAN, 6, 6);

	glUniform3fv(loc_primitive_color, 1, cocktail_color[COCKTAIL_REMAIN]);
	glDrawArrays(GL_TRIANGLE_FAN, 12, 4);

	glUniform3fv(loc_primitive_color, 1, cocktail_color[COCKTAIL_STRAW]);
	glDrawArrays(GL_TRIANGLE_FAN, 16, 4);

	glUniform3fv(loc_primitive_color, 1, cocktail_color[COCKTAIL_DECO]);
	glDrawArrays(GL_TRIANGLE_FAN, 20, 8);

	glBindVertexArray(0);
}