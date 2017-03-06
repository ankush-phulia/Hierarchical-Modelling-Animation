#include "Frog.h"
#include <SOIL/SOIL.h>
//#include <glaux.h>

using namespace Rendering;
using namespace Models;

#define TORSO_HEIGHT 8.0
#define TORSO_RADIUS 1.3

#define HEAD_HEIGHT 1.7
#define HEAD_RADIUS 1.3

#define UPPER_ARM_HEIGHT 2.5
#define LOWER_ARM_HEIGHT 3.0

#define UPPER_ARM_RADIUS  0.65
#define LOWER_ARM_RADIUS  0.5

#define LOWER_LEG_HEIGHT 4.0
#define UPPER_LEG_HEIGHT 3.0

#define UPPER_LEG_RADIUS  0.65
#define LOWER_LEG_RADIUS  0.5

#define SHOULDER_RADIUS 0.85
#define JOINT_RADIUS 0.85

#define STILL 0
#define JUMPING 1

#define VEL 3.1      // Velocity = sqrt(2) x vel
#define PI 3.14159265


static GLfloat theta[10] = {0.0,75.0,-60.0,0.0,50.0,30.0,-100.0,20.0,30.0,150.0};
//{90.0,75.0,-60.0,0.0,50.0,30.0,-100.0,20.0,30.0,150.0}; start-end
//{0.0,30.0,-30.0,0.0,60.0,30.0,-20.0,160.0,0.0,10.0}; mid-air
//{0.0 in z direction 90.0 in x direction}
GLUquadricObj *t, *gl, *h, *ua, *la, *ll, *ul;



void torso()
{
	glPushMatrix();
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluCylinder(t,TORSO_RADIUS*1.5, TORSO_RADIUS, TORSO_HEIGHT,10,10);	//(*obj, base, top, height, slices, stacks)
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
   	glScalef(TORSO_RADIUS,0.1,TORSO_RADIUS);
   	gluSphere(h,1.0,10,10);
	glPopMatrix();
}

void left_upper_arm()
{
	glPushMatrix();
	gluCylinder(ua,UPPER_ARM_RADIUS*1.2, UPPER_ARM_RADIUS, UPPER_ARM_HEIGHT,10,10);
	glPopMatrix();
}

void left_lower_arm()
{
	glPushMatrix();
	gluCylinder(la,LOWER_ARM_RADIUS*1.1, LOWER_ARM_RADIUS, LOWER_ARM_HEIGHT,10,10);
	glPopMatrix();
}

void right_upper_arm()
{
	glPushMatrix();
	gluCylinder(ua,UPPER_ARM_RADIUS*1.2, UPPER_ARM_RADIUS, UPPER_ARM_HEIGHT,10,10);
	glPopMatrix();
}

void right_lower_arm()
{
	glPushMatrix();
	gluCylinder(la,LOWER_ARM_RADIUS*1.1, LOWER_ARM_RADIUS, LOWER_ARM_HEIGHT,10,10);
	glPopMatrix();
}

void left_upper_leg()
{
	glPushMatrix();
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluCylinder(ul,UPPER_LEG_RADIUS*1.2, UPPER_LEG_RADIUS, UPPER_LEG_HEIGHT,10,10);
	glPopMatrix();
}

void left_lower_leg()
{
	glPushMatrix();
	glTranslatef(0.0,-0.25,0.0);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluCylinder(ll,UPPER_LEG_RADIUS, LOWER_LEG_RADIUS, LOWER_LEG_HEIGHT,10,10);
	glPopMatrix();
}

void right_upper_leg()
{
	glPushMatrix();
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluCylinder(ul,UPPER_LEG_RADIUS*1.2, UPPER_LEG_RADIUS, UPPER_LEG_HEIGHT,10,10);
	glPopMatrix();
}

void right_lower_leg()
{
	glPushMatrix();
	glTranslatef(0.0,-0.25,0.0);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluCylinder(ll,UPPER_LEG_RADIUS, LOWER_LEG_RADIUS, LOWER_LEG_HEIGHT,10,10);
	glPopMatrix();
}

void Frog::Draw()
{ 	glEnable ( GL_TEXTURE_2D );
	glBindTexture(GL_TEXTURE_2D, texture);

	glTranslatef(Position.x,Position.y,Position.z);

	glTranslatef(0,-3.0,0);
	glRotatef(theta[0], 0.0, 1.0, 0.0);
	glRotatef(theta[1], 1.0, 0.0, 0.0);
	torso();

	glPushMatrix();
	glTranslatef(0.0, TORSO_HEIGHT+0.5*HEAD_HEIGHT, 0.0);
	glRotatef(theta[2], 1.0, 0.0, 0.0);
	glRotatef(theta[3], 0.0, 1.0, 0.0);
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
	glTranslatef(TORSO_RADIUS, 0.9*TORSO_HEIGHT, 0.0);
	shoulder_joints();

	glTranslatef(-2.0*TORSO_RADIUS, 0.0, 0.0);
	shoulder_joints();
	glPopMatrix();

	//leg_joints
	glPushMatrix();
	glTranslatef(1.5*TORSO_RADIUS, 0.0, 0.0);
	leg_joints();

	glTranslatef(-3.0*TORSO_RADIUS, 0.0, 0.0);
	leg_joints();
	glPopMatrix();

	//right arm
	glPushMatrix();
	glTranslatef(-(TORSO_RADIUS), 0.9*TORSO_HEIGHT, 0.0);
	glRotatef(theta[4], 1.0, 0.0, 0.0);
	glRotatef(-theta[5], 0.0, 1.0, 0.0);
	right_upper_arm();

	glTranslatef(0.0, 0.0, UPPER_ARM_HEIGHT);
	elbow_joints();
	glRotatef(theta[6], 1.0, 0.0, 0.0);
	right_lower_arm();

	glTranslatef(0.0, 0.0, LOWER_ARM_HEIGHT);
	palms(); //right hand
	glPopMatrix();

	//left arm
	glPushMatrix();
	glTranslatef(TORSO_RADIUS, 0.9*TORSO_HEIGHT, 0.0);
	glRotatef(theta[4], 1.0, 0.0, 0.0);
	glRotatef(theta[5], 0.0, 1.0, 0.0);
	left_upper_arm();

	glTranslatef(0.0, 0.0, UPPER_ARM_HEIGHT);
	elbow_joints();
	glRotatef(theta[6], 1.0, 0.0, 0.0);
	left_lower_arm();

	glTranslatef(0.0, 0.0,LOWER_ARM_HEIGHT);
	palms(); //left hand

	glPopMatrix();

	glPushMatrix();
	glTranslatef(-(TORSO_RADIUS*1.5), 0.1*UPPER_LEG_HEIGHT, 0.0);
	glRotatef(theta[7], 1.0, 0.0, 0.0);
	glRotatef(theta[8], 0.0, 0.0, 1.0);
	left_upper_leg();

	glTranslatef(0.0, UPPER_LEG_HEIGHT, 0.0);
	knee_joints();

	glRotatef(theta[9], 1.0, 0.0, 0.0);
	glRotatef(theta[8], 0.0, 0.0, 1.0);
	left_lower_leg();
	glTranslatef(0.0, LOWER_LEG_HEIGHT,0.0);
	palms();
	glPopMatrix();

	glPushMatrix();
	//glTranslatef(TORSO_RADIUS+UPPER_LEG_RADIUS, 0.1*UPPER_LEG_HEIGHT, 0.0);
	glTranslatef((TORSO_RADIUS*1.5), 0.1*UPPER_LEG_HEIGHT, 0.0);
	glRotatef(theta[7], 1.0, 0.0, 0.0);
	glRotatef(-theta[8], 0.0, 0.0, 1.0);
	right_upper_leg();

	glTranslatef(0.0, UPPER_LEG_HEIGHT, 0.0);
	knee_joints();

	glRotatef(theta[9], 1.0, 0.0, 0.0);
	glRotatef(-theta[8], 0.0, 0.0, 1.0);
	right_lower_leg();
	glTranslatef(0.0,LOWER_LEG_HEIGHT,0.0);
	palms();
	glPopMatrix();

	//glFlush();
	//glutSwapBuffers();
   glDisable(GL_TEXTURE_2D);
}


Frog::Frog(){

}

Frog::~Frog(){

}

void Frog::Create(glm::vec3 p){

	glEnable ( GL_TEXTURE_2D );
                                      // Create Storage Space For The Texture
     Position = p;
	/*texture = SOIL_load_OGL_texture
	(
		"frog_skin.jpg",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);
	*/
	int width, height, channels;
	unsigned char *ht_map = SOIL_load_image("frog_skin.jpg",&width, &height, &channels,SOIL_LOAD_RGB); 
	if(ht_map == NULL) 
		std::cout << "NULL "<<SOIL_last_result()<<" \n";
  
	glGenTextures(1, &texture);                                 // Create The Texture
 
        // Typical Texture Generation Using Data From The Bitmap
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, width,height, 0, GL_RGB, GL_UNSIGNED_BYTE, ht_map);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	SOIL_free_image_data( ht_map );

	h=gluNewQuadric();
	gluQuadricDrawStyle(h, GLU_FILL);
	gluQuadricNormals(h, GLU_SMOOTH);
	gluQuadricTexture(h, GL_TRUE);

	t=gluNewQuadric();
	gluQuadricDrawStyle(t, GLU_FILL);
	gluQuadricNormals(t, GLU_SMOOTH);
	gluQuadricTexture(t, GL_TRUE);

	gl=gluNewQuadric();
	gluQuadricDrawStyle(gl, GLU_FILL);
	gluQuadricNormals(gl, GLU_SMOOTH);
	gluQuadricTexture(gl, GL_TRUE);

	ua=gluNewQuadric();
	gluQuadricDrawStyle(ua, GLU_FILL);
	gluQuadricNormals(ua, GLU_SMOOTH);
	gluQuadricTexture(ua, GL_TRUE);

	la=gluNewQuadric();
	gluQuadricDrawStyle(la, GLU_FILL);
	gluQuadricNormals(la, GLU_SMOOTH);
	gluQuadricTexture(la, GL_TRUE);

	ul=gluNewQuadric();
	gluQuadricDrawStyle(ul, GLU_FILL);
	gluQuadricNormals(ul, GLU_SMOOTH);
	gluQuadricTexture(ul, GL_TRUE);

	ll=gluNewQuadric();
	gluQuadricDrawStyle(ll, GLU_FILL);
	gluQuadricNormals(ll, GLU_SMOOTH);
	gluQuadricTexture(ll, GL_TRUE);

}

void Frog::Update(glm::vec3 ins){

}


