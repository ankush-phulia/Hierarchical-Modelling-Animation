#include "Scene_Manager.h"
#include <SOIL/SOIL.h>
using namespace Managers;

int font = (int)GLUT_BITMAP_8_BY_13;

void setOrthographicProjection() {
    // switch to projection mode
    glMatrixMode(GL_PROJECTION);
    // save previous matrix which contains the
    // settings for the perspective projection
    glPushMatrix();
    // reset matrix
    glLoadIdentity();
    // set a 2D orthographic projection
    gluOrtho2D(0, 640, 0, 360);
    // invert the y axis, down is positive
    glScalef(1, -1, 1);
    // mover the origin from the bottom left corner
    // to the upper left corner
    glTranslatef(0, -360, 0);
    glMatrixMode(GL_MODELVIEW);
}

void resetPerspectiveProjection() {
    // set the current matrix to GL_PROJECTION
    glMatrixMode(GL_PROJECTION);
    // restore previous settings
    glPopMatrix();
    // get back to GL_MODELVIEW matrix
    glMatrixMode(GL_MODELVIEW);
}

void renderBitmapString(float x, float y, void *font, char *string) {
    char *c;
    // set position to start drawing fonts
    glRasterPos2f(x, y);
    // loop all the characters in the string
    for (c = string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}

void Lighting() {
    GLfloat mat_ambient[] = {0.5, 0.5, 0.5, 0.5};
    GLfloat mat_diffuse[] = {0.7, 0.7, 0.7, 0.7};
    GLfloat mat_specular[] = {0.8, 0.8, 0.8, 0.8};
    GLfloat mat_shininess[] = {50.0};
    glShadeModel(GL_SMOOTH);

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_BACK, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_BACK, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_BACK, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_BACK, GL_SHININESS, mat_shininess);

    GLfloat light_position[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat light_ambient[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat light_specular[] = {1.0, 1.0, 1.0, 1.0};

    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}

Scene_Manager::Scene_Manager() {
    models_manager = new Models_Manager();
    insect = glm::vec3(0.0, 0.0, -100.0f);
    Lighting();
    glEnable(GL_DEPTH_TEST);
}

Scene_Manager::~Scene_Manager() { delete models_manager; }

void Scene_Manager::NotifyBeginFrame() { models_manager->Update(insect); }

void groundandinsect(glm::vec3 insect) {
    glPushMatrix();
    // glEnable ( GL_TEXTURE_2D );
    // glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    GLUquadricObj *g;

    // GLuint texture;
    // int width, height, channels;
    // unsigned char *ht_map = SOIL_load_image("bg.jpg",&width, &height,
    // &channels,SOIL_LOAD_RGB); if(ht_map == NULL) 	std::cout << "NULL
    // "<<SOIL_last_result()<<" \n"; glGenTextures(1, &texture);
    //    glBindTexture(GL_TEXTURE_2D, texture);
    //    glTexImage2D(GL_TEXTURE_2D, 0, 3, width,height, 0, GL_RGB,
    //    GL_UNSIGNED_BYTE, ht_map);
    //    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    // glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    // SOIL_free_image_data( ht_map );

    g = gluNewQuadric();
    gluQuadricDrawStyle(g, GLU_FILL);
    gluQuadricNormals(g, GLU_SMOOTH);
    // gluQuadricTexture(g, GL_TRUE);
    glColor3f(0.0, 1.0, 0.0);
    glTranslatef(0, -2.0f, 100.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    // glRotatef(-60.0, 0.0, 1.0, 0.0);
    // glRotatef(180.0, 0.0, 0.0, 1.0);
    gluCylinder(g, 1000.0f, 1000.0f, 100000.0f, 10,
                10);  //(*obj, base, top, height, slices, stacks)
    glPopMatrix();

    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    // glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    GLUquadricObj *i;
    i = gluNewQuadric();
    gluQuadricDrawStyle(i, GLU_FILL);
    gluQuadricNormals(i, GLU_SMOOTH);
    // gluQuadricTexture(g, GL_TRUE);
    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(insect.x, -1.0f, insect.z);
    gluSphere(i, 0.25, 10, 10);
    glPopMatrix();
}

void Scene_Manager::NotifyDisplayFrame() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Set the viewport to be the entire window
    glViewport(0, 0, window.width, window.height);
    float ratio = 1.0f * window.width / window.height;
    // Set the clipping volume
    gluPerspective(45, ratio, 0.1, 1000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0f, 0.0f, 25.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

    glPushMatrix();
    groundandinsect(insect);
    models_manager->Draw();
    glPopMatrix();
    setOrthographicProjection();
    glPushMatrix();
    glLoadIdentity();
    glColor3f(0.0f, 1.0f, 1.0f);
    renderBitmapString(30, 15, (void *)font, "3D Frog Simulation");
    renderBitmapString(30, 55, (void *)font, "Use w,s,a,d to direct the FROG");
    glPopMatrix();
    resetPerspectiveProjection();
}

void Scene_Manager::NotifyEndFrame() {}

void Scene_Manager::NotifyReshape(int width, int height, int previos_width,
                                  int previous_height) {}
