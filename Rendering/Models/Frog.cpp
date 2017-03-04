#include "Frog.h"
using namespace Rendering;
using namespace Models;

#define TORSO_HEIGHT 5.0
#define TORSO_RADIUS 1.3

#define HEAD_HEIGHT 1.7
#define HEAD_RADIUS 1.3

#define UPPER_ARM_HEIGHT 2.5
#define LOWER_ARM_HEIGHT 3.0

#define UPPER_ARM_RADIUS  0.65
#define LOWER_ARM_RADIUS  0.5

#define LOWER_LEG_HEIGHT 3.0
#define UPPER_LEG_HEIGHT 3.0

#define UPPER_LEG_RADIUS  0.65
#define LOWER_LEG_RADIUS  0.5

#define SHOULDER_RADIUS 0.85
#define JOINT_RADIUS 0.85

static GLfloat theta[13] = {90.0,0.0,0.0,65.0,0.0,-130.0,65.0,0.0,-130.0,180.0,0.0,180.0,0.0};
GLUquadricObj *t, *gl, *h, *lua, *lla, *rua, *rla, *lll, *rll, *rul, *lul;

void torso()
{
	glPushMatrix();
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluCylinder(t,TORSO_RADIUS, TORSO_RADIUS*1.5, TORSO_HEIGHT,10,10);	//(*obj, base, top, height, slices, stacks)
	glPopMatrix();
}

void head()
{
	glPushMatrix();
	glTranslatef(0.0, 0.5*HEAD_HEIGHT,0.0);
	glScalef(HEAD_RADIUS, HEAD_HEIGHT, HEAD_RADIUS);
	gluSphere(h,1.0,10,10);
	glPopMatrix();
}

void glass_bot()
{
	glPushMatrix();
	glTranslatef(0.0, 0.5*HEAD_HEIGHT,0.075);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluCylinder(gl,HEAD_RADIUS, HEAD_RADIUS, HEAD_HEIGHT/2,10,10);
	glPopMatrix();
}

void shoulder_joints()
{
	glPushMatrix();
	glScalef(SHOULDER_RADIUS, SHOULDER_RADIUS, SHOULDER_RADIUS);
	gluSphere(h,1.0,10,10);
	glPopMatrix();
}

void elbow_joints()
{
	glPushMatrix();
   	glScalef(SHOULDER_RADIUS/1.2, SHOULDER_RADIUS/1.2, SHOULDER_RADIUS/1.2);
   	gluSphere(h,1.0,10,10);
	glPopMatrix();
}

void palms()
{
	glPushMatrix();
   	glScalef(SHOULDER_RADIUS/1.3, SHOULDER_RADIUS/1.3, SHOULDER_RADIUS/1.3);
   	gluSphere(h,1.0,10,10);
	glPopMatrix();
}

void leg_joints()
{
	glPushMatrix();
   	glScalef(JOINT_RADIUS, JOINT_RADIUS, JOINT_RADIUS);
   	gluSphere(h,1.0,10,10);
	glPopMatrix();
}

void knee_joints()
{
	glPushMatrix();
   	glScalef(JOINT_RADIUS, JOINT_RADIUS, JOINT_RADIUS);
   	gluSphere(h,1.0,10,10);
	glPopMatrix();
}

void torso_disk()
{
	glPushMatrix();
   	glScalef(1.5*TORSO_RADIUS, 0.1, 1.5*TORSO_RADIUS);
   	gluSphere(h,1.0,10,10);
	glPopMatrix();
}

void left_upper_arm()
{
	glPushMatrix();
	gluCylinder(lua,UPPER_ARM_RADIUS*1.2, UPPER_ARM_RADIUS, UPPER_ARM_HEIGHT,10,10);
	glPopMatrix();
}

void left_lower_arm()
{
	glPushMatrix();
	gluCylinder(lla,LOWER_ARM_RADIUS*1.1, LOWER_ARM_RADIUS, LOWER_ARM_HEIGHT,10,10);
	glPopMatrix();
}

void right_upper_arm()
{
	glPushMatrix();
	gluCylinder(rua,UPPER_ARM_RADIUS*1.2, UPPER_ARM_RADIUS, UPPER_ARM_HEIGHT,10,10);
	glPopMatrix();
}

void right_lower_arm()
{
	glPushMatrix();
	gluCylinder(rla,LOWER_ARM_RADIUS*1.1, LOWER_ARM_RADIUS, LOWER_ARM_HEIGHT,10,10);
	glPopMatrix();
}

void left_upper_leg()
{
	glColor3f(1.0,0.0,1.0);
	glPushMatrix();
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluCylinder(lul,UPPER_LEG_RADIUS*1.2, UPPER_LEG_RADIUS, UPPER_LEG_HEIGHT,10,10);
	glPopMatrix();
}

void left_lower_leg()
{
	glColor3f(1.0,0.0,0.0);
	glPushMatrix();
	glTranslatef(0.0,-0.25,0.0);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluCylinder(lll,LOWER_LEG_RADIUS, LOWER_LEG_RADIUS*1.5, LOWER_LEG_HEIGHT,10,10);
	glPopMatrix();
}

void right_upper_leg()
{
	glColor3f(1.0f,0.0f,1.0f);
	glPushMatrix();
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluCylinder(rul,UPPER_LEG_RADIUS*1.2, UPPER_LEG_RADIUS, UPPER_LEG_HEIGHT,10,10);
	glPopMatrix();
}

void right_lower_leg()
{
	glColor3f(1.0,0.0,0.0);
	glPushMatrix();
	glTranslatef(0.0,-0.25,0.0);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluCylinder(rll,LOWER_LEG_RADIUS, LOWER_LEG_RADIUS*1.5, LOWER_LEG_HEIGHT,10,10);
	glPopMatrix();
}

void Frog::Draw()
{ 	glTranslatef(-3.5,-3.0,0);
	glRotatef(theta[0], 0.0, 1.0, 0.0);
	torso();

	glPushMatrix();
	glTranslatef(0.0, TORSO_HEIGHT+0.5*HEAD_HEIGHT, 0.0);
	glRotatef(theta[1], 1.0, 0.0, 0.0);
	glRotatef(theta[2], 0.0, 1.0, 0.0);
	glTranslatef(0.0, -0.5*HEAD_HEIGHT, 0.0);
	head();
	glass_bot();
	glPopMatrix();

	//torso_disk
	glPushMatrix();
	glTranslatef(0.0, TORSO_HEIGHT, 0.0);
	torso_disk();
	glPopMatrix();

	//shoulder_joints
	glPushMatrix();
	glTranslatef(1.5*TORSO_RADIUS, 0.9*TORSO_HEIGHT, 0.0);
	shoulder_joints();

	glTranslatef(-3.0*TORSO_RADIUS, 0.0, 0.0);
	shoulder_joints();
	glPopMatrix();

	//leg_joints
	glPushMatrix();
	glTranslatef(1.1*TORSO_RADIUS, 0.0, 0.0);
	leg_joints();

	glTranslatef(-2.2*TORSO_RADIUS, 0.0, 0.0);
	shoulder_joints();
	glPopMatrix();

	//right arm
	glPushMatrix();
	glTranslatef(-(TORSO_RADIUS+UPPER_ARM_RADIUS), 0.9*TORSO_HEIGHT, 0.0);
	glRotatef(theta[6], 1.0, 0.0, 0.0);
	glRotatef(theta[7], 0.0, 1.0, 0.0);
	right_upper_arm();

	glTranslatef(0.0, 0.0, UPPER_ARM_HEIGHT);
	elbow_joints();
	glRotatef(theta[8], 1.0, 0.0, 0.0);
	right_lower_arm();

	glTranslatef(0.0, 0.0, LOWER_ARM_HEIGHT);
	palms(); //right hand
	glPopMatrix();

	//left arm
	glPushMatrix();
	glTranslatef(TORSO_RADIUS+UPPER_ARM_RADIUS, 0.9*TORSO_HEIGHT, 0.0);
	glRotatef(theta[3], 1.0, 0.0, 0.0);
	glRotatef(theta[4], 0.0, 1.0, 0.0);
	left_upper_arm();

	glTranslatef(0.0, 0.0, UPPER_ARM_HEIGHT);
	elbow_joints();
	glRotatef(theta[5], 1.0, 0.0, 0.0);
	glColor3f(1.0,1.0,1.0);
	left_lower_arm();

	glTranslatef(0.0, 0.0,LOWER_ARM_HEIGHT);
	palms(); //left hand

	glPopMatrix();

	glPushMatrix();
	glTranslatef(-(TORSO_RADIUS), 0.1*UPPER_LEG_HEIGHT, 0.0);
	glRotatef(theta[9], 1.0, 0.0, 0.0);
	left_upper_leg();

	glTranslatef(0.0, UPPER_LEG_HEIGHT, 0.0);
	knee_joints();

	glRotatef(theta[10], 1.0, 0.0, 0.0);
	left_lower_leg();
	glPopMatrix();

	glPushMatrix();
	//glTranslatef(TORSO_RADIUS+UPPER_LEG_RADIUS, 0.1*UPPER_LEG_HEIGHT, 0.0);
	glTranslatef((TORSO_RADIUS), 0.1*UPPER_LEG_HEIGHT, 0.0);
	glRotatef(theta[11], 1.0, 0.0, 0.0);
	right_upper_leg();

	glTranslatef(0.0, UPPER_LEG_HEIGHT, 0.0);
	knee_joints();

	glRotatef(theta[12], 1.0, 0.0, 0.0);
	right_lower_leg();
	glPopMatrix();

	//glFlush();
	//glutSwapBuffers();
   //glDisable(GL_TEXTURE_2D);
}


Frog::Frog(){

}

Frog::~Frog(){

}

void Frog::Create(){

	h=gluNewQuadric();
	gluQuadricDrawStyle(h, GLU_FILL);
	gluQuadricNormals(h, GLU_SMOOTH);

	t=gluNewQuadric();
	gluQuadricDrawStyle(t, GLU_FILL);
	gluQuadricNormals(t, GLU_SMOOTH);

	gl=gluNewQuadric();
	gluQuadricDrawStyle(gl, GLU_FILL);
	gluQuadricNormals(gl, GLU_SMOOTH);

	lua=gluNewQuadric();
	gluQuadricDrawStyle(lua, GLU_FILL);
	gluQuadricNormals(lua, GLU_SMOOTH);

	lla=gluNewQuadric();
	gluQuadricDrawStyle(lla, GLU_FILL);
	gluQuadricNormals(lla, GLU_SMOOTH);

	rua=gluNewQuadric();
	gluQuadricDrawStyle(rua, GLU_FILL);
	gluQuadricNormals(rua, GLU_SMOOTH);

	rla=gluNewQuadric();
	gluQuadricDrawStyle(rla, GLU_FILL);
	gluQuadricNormals(rla, GLU_SMOOTH);

	lul=gluNewQuadric();
	gluQuadricDrawStyle(lul, GLU_FILL);
	gluQuadricNormals(lul, GLU_SMOOTH);

	lll=gluNewQuadric();
	gluQuadricDrawStyle(lll, GLU_FILL);
	gluQuadricNormals(lll, GLU_SMOOTH);

	rul=gluNewQuadric();
	gluQuadricDrawStyle(rul, GLU_FILL);
	gluQuadricNormals(rul, GLU_SMOOTH);

	rll=gluNewQuadric();
	gluQuadricDrawStyle(rll, GLU_FILL);
	/*GLuint vao;
	GLuint vbo;

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	std::vector<VertexFormat> vertices;

	vertices.push_back(VertexFormat(glm::vec3(-0.25, 0.5, 0.0),
		glm::vec4(1, 0, 0, 1)));
	vertices.push_back(VertexFormat(glm::vec3(-0.25, 0.75, 0.0),
		glm::vec4(0, 0, 0, 1)));
	vertices.push_back(VertexFormat(glm::vec3(0.25, 0.5, 0.0),
		glm::vec4(0, 1, 0, 1)));

	vertices.push_back(VertexFormat(glm::vec3(0.25, 0.75, 0.0),
		glm::vec4(0, 0, 1, 1)));


	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(VertexFormat) * 4, &vertices[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(offsetof(VertexFormat, VertexFormat::color)));
	glBindVertexArray(0);
	this->vao = vao;
	this->vbos.push_back(vbo);
  */
}

void Frog::Update(){

}

/*void Draw(){
	glUseProgram(program);
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
}
*/
