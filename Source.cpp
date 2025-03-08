#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <gl/glut.h>

static int WinWidth = 800;
static int WinHeight = 600;
static int action = 0;
static int state = 1;
static GLuint inner_mode = GL_SMOOTH;
static GLuint tex_state = GL_TRUE;
bool leftFoot = true;
bool floating = false;
bool MFirstStep = true;
bool MSecondStep = true;
float viewHorizontal = -45;
float viewVertical = 0;
float BIGGnum = 0;
bool BIGG = false;

float bodya = 0, bodyx = 0, bodyy = 0, bodyz = 0;
float necka = 0, neckx = 0, necky = 0, neckz = 0;
float rShouldera = 0, rShoulderx = 0, rShouldery = 0, rShoulderz = 0;
float rElbowa = 0, rElbowx = 0, rElbowy = 0, rElbowz = 0;
float rThigha = 0, rThighx = 0, rThighy = 0, rThighz = 0;
float rKneea = 0, rKneex = 0, rKneey = 0, rKneez = 0;
float lShouldera = 0, lShoulderx = 0, lShouldery = 0, lShoulderz = 0;
float lElbowa = 0, lElbowx = 0, lElbowy = 0, lElbowz = 0;
float lThigha = 0, lThighx = 0, lThighy = 0, lThighz = 0;
float lKneea = 0, lKneex = 0, lKneey = 0, lKneez = 0;
float rFingersa[3], rFingersx[3], rFingersy[3], rFingersz[3];
float lFingersa[3], lFingersx[3], lFingersy[3], lFingersz[3];
float morea = 0, morex = 0, morey = 0, morez = 0;
float more2a = 0, more2x = 0, more2y = 0, more2z = 0;
float more3a = 0, more3x = 0, more3y = 0, more3z = 0;
float more4a = 0, more4x = 0, more4y = 0, more4z = 0;
float bodya1 = 0, bodyx1 = 0, bodyy1 = 0, bodyz1 = 0;
float rElbowa1 = 0, rElbowx1 = 0, rElbowy1 = 0, rElbowz1 = 0;
float lElbowa1 = 0, lElbowx1 = 0, lElbowy1 = 0, lElbowz1 = 0;

float bodyMovex = 0, bodyMovey = 0, bodyMovez = 0;
float neckMovex = 0, neckMovey = 0, neckMovez = 0;
float rShoulderMovex = 0, rShoulderMovey = 0, rShoulderMovez = 0;
float rElbowMovex = 0, rElbowMovey = 0, rElbowMovez = 0;
float rThighMovex = 0, rThighMovey = 0, rThighMovez = 0;
float rKneeMovex = 0, rKneeMovey = 0, rKneeMovez = 0;
float lShoulderMovex = 0, lShoulderMovey = 0, lShoulderMovez = 0;
float lElbowMovex = 0, lElbowMovey = 0, lElbowMovez = 0;
float lThighMovex = 0, lThighMovey = 0, lThighMovez = 0;
float lKneeMovex = 0, lKneeMovey = 0, lKneeMovez = 0;

float floatValue = 90;
float scale = 1;
float delayScale = 0;
float delaySpeed = 0.01;
float alpha = 0;

void timerFunction(int value);

void init(void)
{
	GLfloat  ambientLight[] = { 1, 1, 1, 0.0f };
	GLfloat  diffuseLight[] = { 0, 0, 0, 1.0f };
	GLfloat  specular[] = { 0.8f, 0.8f, 0.8f, 1.0f };
	GLfloat  ambientLight2[] = { 0.9f, 0.1f, 0.1f, 1.0f };
	GLfloat  specular2[] = { 0.3f, 0.3f, 0.3f, 1.3f };
	GLfloat  specref[] = { 0.8f, 0.8f, 0.8f, 1.0f };
	GLfloat  pos[] = { 0.0f, 20.0f, -100.0f, 1.0f };
	GLfloat  dir[] = { 0.0f, 0.0f, -1.0f };

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glEnable(GL_NORMALIZE);
	glEnable(GL_LIGHTING);
	

	// Setup and enable light 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT1, GL_AMBIENT, ambientLight2);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, ambientLight2);
	glLightfv(GL_LIGHT1, GL_SPECULAR, specular2);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, dir);
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 60);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 100);
	glLightfv(GL_LIGHT1, GL_POSITION, pos);

	// Enable color tracking
	glEnable(GL_COLOR_MATERIAL);

	// Set Material properties to follow glColor values
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);

	// All materials hereafter have full specular reflectivity with a high shine
	glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
	glMateriali(GL_FRONT, GL_SHININESS, 128);

	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
}

void standby() 
{
	state = 1;
	scale = 1;

	delayScale = 0;
	alpha = 0;
	delaySpeed = 0.01;

	bodya = 0;	bodyx = 0;	bodyy = 0;	bodyz = 0;
	necka = 0;	neckx = 0;	necky = 0;	neckz = 0;
	rShouldera = 0;	rShoulderx = 0;	rShouldery = 0;	rShoulderz = 0;
	rElbowa = 0;	rElbowx = 0;	rElbowy = 0;	rElbowz = 0;
	rThigha = 0;	rThighx = 0;	rThighy = 0;	rThighz = 0;
	rKneea = 0;	rKneex = 0;	rKneey = 0;	rKneez = 0;
	lShouldera = 0;	lShoulderx = 0;	lShouldery = 0;	lShoulderz = 0;
	lElbowa = 0;	lElbowx = 0;	lElbowy = 0;	lElbowz = 0;
	lThigha = 0;	lThighx = 0;	lThighy = 0;	lThighz = 0;
	lKneea = 0;	lKneex = 0;	lKneey = 0;	lKneez = 0;
	bodya1 = 0;	bodyx1 = 0;	bodyy1 = 0;	bodyz1 = 0;
	rElbowa1 = 0;	rElbowx1 = 0;	rElbowy1 = 0;	rElbowz1 = 0;
	lElbowa1 = 0;	lElbowx1 = 0;	lElbowy1 = 0;	lElbowz1 = 0;

	bodyMovex = 0; bodyMovey = 0; bodyMovez = 0;
	neckMovex = 0; neckMovey = 0; neckMovez = 0;
	rShoulderMovex = 0; rShoulderMovey = 0; rShoulderMovez = 0;
	rElbowMovex = 0; rElbowMovey = 0; rElbowMovez = 0;
	rThighMovex = 0; rThighMovey = 0; rThighMovez = 0;
	rKneeMovex = 0; rKneeMovey = 0; rKneeMovez = 0;
	lShoulderMovex = 0; lShoulderMovey = 0; lShoulderMovez = 0;
	lElbowMovex = 0; lElbowMovey = 0; lElbowMovez = 0;
	lThighMovex = 0; lThighMovey = 0; lThighMovez = 0;
	lKneeMovex = 0; lKneeMovey = 0; lKneeMovez = 0;
	morea = 0; morex = 0; morey = 0; morez = 0;
	more2a = 0; more2x = 0; more2y = 0; more2z = 0;
	more3a = 0; more3x = 0; more3y = 0; more3z = 0;
	more4a = 0; more4x = 0; more4y = 0; more4z = 0;

	rFingersa[0] = 0; rFingersx[0] = 0; rFingersy[0] = 0; rFingersz[0] = 0;
	rFingersa[1] = 0; rFingersx[1] = 0; rFingersy[1] = 0; rFingersz[1] = 0;
	rFingersa[2] = 0; rFingersx[2] = 0; rFingersy[2] = 0; rFingersz[2] = 0;

	lFingersa[0] = 0; lFingersx[0] = 0; lFingersy[0] = 0; lFingersz[0] = 0;
	lFingersa[1] = 0; lFingersx[1] = 0; lFingersy[1] = 0; lFingersz[1] = 0;
	lFingersa[2] = 0; lFingersx[2] = 0; lFingersy[2] = 0; lFingersz[2] = 0;

	MFirstStep = true;
	MSecondStep = true;
	BIGG = false;
	BIGGnum = 0;
}

void drawDelay()
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glPushMatrix();
	glTranslatef(0, 90, 0);
	glScalef(delayScale, delayScale, delayScale);
	glColor4ub(0, 255, 255, alpha);
	glutSolidSphere(32.0, 30.0, 30.0);
	glColor4ub(0, 255, 255, alpha * 1.5);
	glutSolidSphere(35.0, 30.0, 30.0);
	glPopMatrix();
	glDisable(GL_BLEND);
}

void drawBody()
{
	GLUquadricObj *cone;
	glColor3ub(71, 121, 152);

	cone = gluNewQuadric();
	glTranslatef(bodyMovex, bodyMovey, bodyMovez);
	
	glRotatef(bodya, bodyx, bodyy, bodyz);
	glRotatef(bodya1, bodyx1, bodyy1, bodyz1);

	glPushMatrix();
	glRotatef(-90, 1, 0, 0);
	gluCylinder(cone, 10., 10., 35., 30, 30);
	glPopMatrix();

	glPushMatrix();
	glScalef(1, 0.7, 1);
	glutSolidSphere(10.0, 30.0, 30.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 35.0, 0.0);
	glPushMatrix();
	glScalef(1, 0.7, 1);
	glutSolidSphere(10.0, 30.0, 30.0);
	glPopMatrix();
	glPopMatrix();

	gluDeleteQuadric(cone);
}

void drawNeck()
{
	GLUquadricObj *cone;
	glColor3ub(247, 157, 101);

	cone = gluNewQuadric();
	glTranslatef(0.0, 40.5, 0.0);
	glRotatef(necka, neckx, necky, neckz);

	glPushMatrix();
	glRotatef(-90, 1, 0, 0);
	gluCylinder(cone, 2.5, 2.5, 7., 30, 30);
	glPopMatrix();

	glPushMatrix();
	glScalef(1, 0.7, 1);
	glutSolidSphere(2.5, 30.0, 30.0);
	glPopMatrix();

	glTranslatef(0.0, 7.0, 0.0);

	glPushMatrix();
	glScalef(1, 0.7, 1);
	glutSolidSphere(2.5, 30.0, 30.0);
	glPopMatrix();

	gluDeleteQuadric(cone);
}

void drawHead()
{
	glTranslatef(0, 10.0, 0.0);
	glScalef(1.0, 0.95, 1.0);
	glColor3ub(247, 178, 103);
	glutSolidSphere(11.0, 30.0, 30.0);

	glPushMatrix();
	glTranslatef(-4, 0, 10);
	glScalef(1.0, 1.414, 1.0);
	glColor3ub(0, 0, 0);
	glutSolidSphere(0.75, 30.0, 30.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(4, 0, 10);
	glScalef(1.0, 1.414, 1.0);
	glColor3ub(0, 0, 0);
	glutSolidSphere(0.75, 30.0, 30.0);
	glPopMatrix();

	glPushMatrix();
	GLUquadricObj *cone;
	glColor3ub(0, 0, 0);
	glTranslatef(0, 10.45, 0);
	cone = gluNewQuadric();

	glPushMatrix();
	glRotatef(-90, 1, 0, 0);
	gluCylinder(cone, 0.25, 0.25, 3., 30, 30);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 3, 0);
	glScalef(1, 1.7, 1);
	glutSolidSphere(0.25, 30.0, 30.0);
	glPopMatrix();

	glRotatef(15, 0, 0, 1);
	glTranslatef(-2, 0, 0);
	glPushMatrix();
	glRotatef(-90, 1, 0, 0);
	gluCylinder(cone, 0.25, 0.25, 3., 30, 30);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 3, 0);
	glScalef(1, 1.7, 1);
	glutSolidSphere(0.25, 30.0, 30.0);
	glPopMatrix();

	glRotatef(-30, 0, 0, 1);
	glTranslatef(4, 1, 0);
	glPushMatrix();
	glRotatef(-90, 1, 0, 0);
	gluCylinder(cone, 0.25, 0.25, 3., 30, 30);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 3, 0);
	glScalef(1, 1.7, 1);
	glutSolidSphere(0.25, 30.0, 30.0);
	glPopMatrix();

	gluDeleteQuadric(cone);
	glPopMatrix();
}

void drawRShoulder()
{
	glTranslatef(-13.0, 35.0, 0);
	glRotatef(more2a, more2x, more2y, more2z);
	glRotatef(morea, morex, morey, morez);
	glRotatef(rShouldera, rShoulderx, rShouldery, rShoulderz);
	glColor3ub(41, 31, 30);
	glutSolidSphere(3.0, 30.0, 30.0);
}

void drawRUArm()
{
	GLUquadricObj *cone;
	glColor3ub(147, 22, 33);

	cone = gluNewQuadric();
	glTranslatef(0.0, 0.0, 0.0);
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	gluCylinder(cone, 2., 2., 16., 30, 30);
	glPopMatrix();

	gluDeleteQuadric(cone);
}


void drawRElbow()
{
	glTranslatef(0, -16, 0);
	glRotatef(rElbowa, rElbowx, rElbowy, rElbowz);
	glRotatef(rElbowa1, rElbowx1, rElbowy1, rElbowz1);
	glColor3ub(41, 31, 30);
	glutSolidSphere(3.0, 30.0, 30.0);
}

void drawRForearm()
{
	GLUquadricObj *cone;
	glColor3ub(254, 95, 85);

	cone = gluNewQuadric();
	glTranslatef(0.0, 0.0, 0.0);
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	gluCylinder(cone, 2., 2., 24., 30, 30);
	glPopMatrix();

	glTranslatef(0.0, -24.0,0.0);

	glPushMatrix();
	glScalef(1, 1.7, 1);
	glutSolidSphere(2.0, 30.0, 30.0);
	glPopMatrix();

	if (!MSecondStep)
	{
		glPushMatrix();
		glColor3ub(252, 219, 56);
		glRotatef(90, 1, 0, 0);
		glutSolidTorus(1, 7, 30, 30);
		glTranslatef(0, 0, 15);
		glutSolidTorus(1, 7, 30, 30);
		glTranslatef(0, 0, 15);
		glutSolidTorus(1, 7, 30, 30);
		glTranslatef(0, 0, 15);
		glutSolidTorus(1, 7, 30, 30);
		glTranslatef(0, 0, 15);
		glutSolidTorus(1, 7, 30, 30);
		glTranslatef(0, 0, 15);
		glutSolidTorus(1, 7, 30, 30);
		glTranslatef(0, 0, 15);
		glutSolidTorus(1, 7, 30, 30);
		glTranslatef(0, 0, 15);
		glutSolidTorus(1, 7, 30, 30);
		glTranslatef(0, 0, 15);
		glutSolidTorus(1, 7, 30, 30);
		glPopMatrix();
	}

	gluDeleteQuadric(cone);
}


void drawLShoulder()
{
	glTranslatef(13.0, 35.0, 0);
	glRotatef(more3a, more3x, more3y, more3z);
	glRotatef(more2a, more2x, more2y, more2z);
	glRotatef(morea, morex, morey, morez);
	glRotatef(lShouldera, lShoulderx, lShouldery, lShoulderz);
	glColor3ub(41, 31, 30);
	glutSolidSphere(3.0, 30.0, 30.0);
}

void drawLUArm()
{
	GLUquadricObj *cone;
	glColor3ub(147, 22, 33);

	cone = gluNewQuadric();
	glTranslatef(0.0, 0.0, 0.0);
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	gluCylinder(cone, 2., 2., 16., 30, 30);
	glPopMatrix();

	if (BIGG)
	{
		glPushMatrix();
		glTranslatef(0.0, -7.0, 0.0);
		glScaled(0.5 + BIGGnum, 1 + BIGGnum, 0.5 + BIGGnum); //BIGGnum<=1
		glRotatef(90, 1, 0, 0);
		gluSphere(cone, 4.f, 20, 20);
		glPopMatrix();
	}

	gluDeleteQuadric(cone);
}

void drawLElbow()
{
	glTranslatef(0, -16, 0);
	glRotatef(lElbowa, lElbowx, lElbowy, lElbowz);
	glRotatef(lElbowa1, lElbowx1, lElbowy1, lElbowz1);
	glColor3ub(41, 31, 30);
	glutSolidSphere(3.0, 30.0, 30.0);
}

void drawLForearm()
{
	GLUquadricObj *cone;
	glColor3ub(254, 95, 85);

	cone = gluNewQuadric();
	glTranslatef(0.0, 0.0, 0.0);
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	gluCylinder(cone, 2., 2., 24., 30, 30);
	glPopMatrix();

	glTranslatef(0.0, -24.0, 0.0);

	glPushMatrix();
	glScalef(1, 1.7, 1);
	glutSolidSphere(2.0, 30.0, 30.0);
	glPopMatrix();

	gluDeleteQuadric(cone);
}

void drawRThigh()
{
	GLUquadricObj *cone;
	glColor3ub(163, 51, 61);
	glTranslatef(-7.0, -5, 0);
	glRotatef(more4a, more4x, more4y, more4z);
	glRotatef(rThigha, rThighx, rThighy, rThighz);

	cone = gluNewQuadric();
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	gluCylinder(cone, 2.5, 2.5, 20., 30, 30);
	glPopMatrix();

	glPushMatrix();
	glScalef(1, 0.7, 1);
	glutSolidSphere(2.5, 30.0, 30.0);
	glPopMatrix();

	gluDeleteQuadric(cone);
}

void drawRKnee()
{
	glTranslatef(0, -20, 0);
	glRotatef(rKneea, rKneex, rKneey, rKneez);
	glColor3ub(41, 31, 30);
	glutSolidSphere(3.0, 30.0, 30.0);
}

void drawRCalf()
{
	GLUquadricObj *cone;
	glColor3ub(242, 97, 87);

	cone = gluNewQuadric();
	glTranslatef(0.0, 0.0, 0.0);
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	gluCylinder(cone, 2.5, 2.5, 20., 30, 30);
	glPopMatrix();

	glTranslatef(0.0, -20.0, 0.0);

	glPushMatrix();
	glScalef(1, 1.7, 1);
	glutSolidSphere(2.5, 30.0, 30.0);
	glPopMatrix();

	gluDeleteQuadric(cone);
}

void drawLThigh()
{
	GLUquadricObj *cone;
	glColor3ub(163, 51, 61);
	glTranslatef(7.0, -5, 0);
	glRotatef(lThigha, lThighx, lThighy, lThighz);

	cone = gluNewQuadric();
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	gluCylinder(cone, 2.5, 2.5, 20., 30, 30);
	glPopMatrix();

	glPushMatrix();
	glScalef(1, 0.7, 1);
	glutSolidSphere(2.5, 30.0, 30.0);
	glPopMatrix();

	gluDeleteQuadric(cone);
}

void drawLKnee()
{
	glTranslatef(0, -20, 0);
	glRotatef(lKneea, lKneex, lKneey, lKneez);
	glColor3ub(41, 31, 30);
	glutSolidSphere(3.0, 30.0, 30.0);
}

void drawLCalf()
{
	GLUquadricObj *cone;
	glColor3ub(242, 97, 87);

	cone = gluNewQuadric();
	glTranslatef(0.0, 0.0, 0.0);
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	gluCylinder(cone, 2.5, 2.5, 20., 30, 30);
	glPopMatrix();

	glTranslatef(0.0, -20.0, 0.0);

	glPushMatrix();
	glScalef(1, 1.7, 1);
	glutSolidSphere(2.5, 30.0, 30.0);
	glPopMatrix();

	gluDeleteQuadric(cone);
}

void drawRFingers()
{
	GLUquadricObj *cone, *base;

	glColor3ub(50, 50, 50);
	cone = gluNewQuadric();
	base = gluNewQuadric();

	glPushMatrix();
	glTranslatef(0.0, -2, -1.5);
	glRotatef(rFingersa[0], rFingersx[0], rFingersy[0], rFingersz[0]);
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	gluCylinder(cone, 0.5, 0.5, 3, 30, 30);
	glTranslatef(0.0, 0.0, 3);
	gluDisk(base, 0., 0.5, 30, 1);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.3, -2, 0.75);
	glRotatef(rFingersa[1], rFingersx[1], rFingersy[1], rFingersz[1]);
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	gluCylinder(cone, 0.5, 0.5, 3, 30, 30);
	glTranslatef(0.0, 0.0, 3);
	gluDisk(base, 0., 0.5, 30, 1);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.3, -2, 0.75);
	glRotatef(rFingersa[2], rFingersx[2], rFingersy[2], rFingersz[2]);
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	gluCylinder(cone, 0.5, 0.5, 3, 30, 30);
	glTranslatef(0.0, 0.0, 3);
	gluDisk(base, 0., 0.5, 30, 1);
	glPopMatrix();
	glPopMatrix();

	gluDeleteQuadric(cone);
	gluDeleteQuadric(base);
}

void drawLFingers()
{
	GLUquadricObj *cone, *base;

	glColor3ub(50, 50, 50);
	cone = gluNewQuadric();
	base = gluNewQuadric();

	glPushMatrix();
	glTranslatef(0.0, -2, -1.5);
	glRotatef(lFingersa[0], lFingersx[0], lFingersy[0], lFingersz[0]);
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	gluCylinder(cone, 0.5, 0.5, 3, 30, 30);
	glTranslatef(0.0, 0.0, 3);
	gluDisk(base, 0., 0.5, 30, 1);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.3, -2, 0.75);
	glRotatef(lFingersa[1], lFingersx[1], lFingersy[1], lFingersz[1]);
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	gluCylinder(cone, 0.5, 0.5, 3, 30, 30);
	glTranslatef(0.0, 0.0, 3);
	gluDisk(base, 0., 0.5, 30, 1);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.3, -2, 0.75);
	glRotatef(lFingersa[2], lFingersx[2], lFingersy[2], lFingersz[2]);
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	gluCylinder(cone, 0.5, 0.5, 3, 30, 30);
	glTranslatef(0.0, 0.0, 3);
	gluDisk(base, 0., 0.5, 30, 1);
	glPopMatrix();
	glPopMatrix();

	gluDeleteQuadric(cone);
	gluDeleteQuadric(base);
}

void draw()
{
	glTranslatef(0.0, -15.0, -200.0);  
	glRotatef(viewHorizontal, 0, 1, 0);
	glRotatef(viewVertical, 1, 0, 0);
	glScalef(scale, scale, scale);
	glPushMatrix();
	drawBody();
	

	glPushMatrix();
	drawNeck();
	glPushMatrix();
	drawHead();
	glPushMatrix();
	drawDelay();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	drawRShoulder();
	glPushMatrix();
	drawRUArm();
	glPushMatrix();
	drawRElbow();
	glPushMatrix();
	drawRForearm();
	glPushMatrix();
	drawRFingers();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	drawLShoulder();
	glPushMatrix();
	drawLUArm();
	glPushMatrix();
	drawLElbow();
	glPushMatrix();
	drawLForearm();
	glPushMatrix();
	drawLFingers();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	drawRThigh();
	glPushMatrix();
	drawRKnee();
	glPushMatrix();
	drawRCalf();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	drawLThigh();
	glPushMatrix();
	drawLKnee();
	glPushMatrix();
	drawLCalf();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glShadeModel(inner_mode);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	draw();

	glutSwapBuffers();
}

void reshape(int w, int h)
{
	WinWidth = w;
	WinHeight = h;
	GLfloat aspect;
	aspect = (GLfloat)w / (GLfloat)h;

	if (aspect > 1.0f)
		glViewport((w - h) / 2.0f, 0, (GLsizei)h, (GLsizei)h);
	else
		glViewport(0, (h - w) / 2.0f, (GLsizei)w, (GLsizei)w);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, 1.0f, 1.0f, 500.0f);
	glMatrixMode(GL_MODELVIEW);
}

void keyin(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'd':
		viewHorizontal += 3;
		break;
	case 'a':
		viewHorizontal -= 3;
		break;
	case 'w':
		viewVertical -= 3;
		break;
	case 's':
		viewVertical += 3;
		break;
	case 'r':
		viewVertical = 0;
		viewHorizontal = -45;
		break;
	case 27:
		exit(0);
	}
	if (viewHorizontal >= 360)
		viewHorizontal -= 360;
	else if (viewHorizontal <= -360)
		viewHorizontal += 360;
}

void Delay()
{
	if (delayScale <= 2)
		delayScale += delaySpeed;
	else if (MFirstStep)
		MFirstStep = false;
}

void walk()
{
	state = 0;

	if (leftFoot)
	{
		lThighx = 1;
		lThighy = 0;
		lThighz = 0;
		if (lThigha >= -15)
			lThigha -= 0.3;

		rThighx = -1;
		rThighy = 0;
		rThighz = 0;
		if (rThigha >= -15)
			rThigha -= 0.3;

		lKneex = -1;
		lKneey = 0;
		lKneez = 0;
		if (lKneea >= -15)
			lKneea -= 0.3;

		rKneex = -1;
		rKneey = 0;
		rKneez = 0;
		if (rKneea >= -15)
			rKneea -= 0.3;

		rShoulderx = 1;
		rShouldery = 0;
		rShoulderz = 0;
		if (rShouldera >= -15)
			rShouldera -= 0.3;

		lShoulderx = -1;
		lShouldery = 0;
		lShoulderz = 0;
		if (lShouldera >= -15)
			lShouldera -= 0.3;

		if (lShouldera <= -15)
			leftFoot = false;
	}
	else
	{
		lThighx = 1;
		lThighy = 0;
		lThighz = 0;
		if (lThigha <= 15)
			lThigha += 0.3;

		rThighx = -1;
		rThighy = 0;
		rThighz = 0;
		if (rThigha <= 15)
			rThigha += 0.3;

		lKneex = -1;
		lKneey = 0;
		lKneez = 0;
		if (lKneea >= -15)
			lKneea -= 0.3;

		rKneex = -1;
		rKneey = 0;
		rKneez = 0;
		if (rKneea >= 15)
			rKneea -= 0.3;

		rShoulderx = 1;
		rShouldery = 0;
		rShoulderz = 0;
		if (rShouldera <= 15)
			rShouldera += 0.3;

		lShoulderx = -1;
		lShouldery = 0;
		lShoulderz = 0;
		if (lShouldera <= 15)
			lShouldera += 0.3;

		if (lShouldera >= 15)
			leftFoot = true;
	}
}

void run()
{
	state = 0;

	bodyx = -1;
	bodyy = 0;
	bodyz = 0;
	if (bodya >= -15)
		bodya -= 0.3;
	neckx = 1;
	necky = 0;
	neckz = 0;
	if (necka >= -15)
		necka -= 0.3;

	rFingersx[0] = -1;
	rFingersy[0] = 0;
	rFingersz[0] = 0;
	if (rFingersa[0] <= 30)
		rFingersa[0] += 0.6;

	rFingersx[1] = 1;
	rFingersy[1] = 0;
	rFingersz[1] = -1;
	if (rFingersa[1] <= 30)
		rFingersa[1] += 0.6;

	rFingersx[2] = 1;
	rFingersy[2] = 0;
	rFingersz[2] = 1;
	if (rFingersa[2] <= 30)
		rFingersa[2] += 0.6;

	lFingersx[0] = -1;
	lFingersy[0] = 0;
	lFingersz[0] = 0;
	if (lFingersa[0] <= 30)
		lFingersa[0] += 0.6;

	lFingersx[1] = 1;
	lFingersy[1] = 0;
	lFingersz[1] = -1;
	if (lFingersa[1] <= 30)
		lFingersa[1] += 0.6;

	lFingersx[2] = 1;
	lFingersy[2] = 0;
	lFingersz[2] = 1;
	if (lFingersa[2] <= 30)
		lFingersa[2] += 0.6;

	if (leftFoot)
	{
		lThighx = 1;
		lThighy = 0;
		lThighz = 0;
		if (lThigha >= -90)
			lThigha -= 1.8;

		rThighx = -1;
		rThighy = 0;
		rThighz = 0;
		if (rThigha >= -90)
			rThigha -= 1.8;

		lKneex = -1;
		lKneey = 0;
		lKneez = 0;
		if (lKneea >= -30)
			lKneea -= 0.6;

		rKneex = -1;
		rKneey = 0;
		rKneez = 0;
		if (rKneea >= -30)
			rKneea -= 0.6;

		rShoulderx = 1;
		rShouldery = 0;
		rShoulderz = 0;
		if (rShouldera >= -60)
			rShouldera -= 1.2;

		lShoulderx = -1;
		lShouldery = 0;
		lShoulderz = 0;
		if (lShouldera >= -60)
			lShouldera -= 1.2;

		rElbowx = 1;
		rElbowy = 0;
		rElbowz = 0;
		if (rElbowa >= -90)
			rElbowa -= 1.6;

		lElbowx = 1;
		lElbowy = 0;
		lElbowz = 0;
		if (lElbowa >= -90)
			lElbowa -= 1.6;

		if (rShouldera <= -45)
			leftFoot = false;
	}
	else
	{
		lThighx = 1;
		lThighy = 0;
		lThighz = 0;
		if (lThigha <= 90)
			lThigha += 1.8;

		rThighx = -1;
		rThighy = 0;
		rThighz = 0;
		if (rThigha <= 90)
			rThigha += 1.8;

		lKneex = -1;
		lKneey = 0;
		lKneez = 0;
		if (lKneea >= -30)
			lKneea -= 0.6;

		rKneex = -1;
		rKneey = 0;
		rKneez = 0;
		if (rKneea >= -30)
			rKneea -= 0.6;

		rShoulderx = 1;
		rShouldery = 0;
		rShoulderz = 0;
		if (rShouldera <= 60)
			rShouldera += 1.2;

		lShoulderx = -1;
		lShouldery = 0;
		lShoulderz = 0;
		if (lShouldera <= 60)
			lShouldera += 1.2;

		rElbowx = 1;
		rElbowy = 0;
		rElbowz = 0;
		if (rElbowa >= -90)
			rElbowa -= 1.6;

		lElbowx = 1;
		lElbowy = 0;
		lElbowz = 0;
		if (lElbowa >= -90)
			lElbowa -= 1.6;

		if (lThigha >= 90)
			leftFoot = true;
	}
}

void sit()
{
	state = 0;
	if (bodyMovey >= -42)
		bodyMovey -= 0.84;

	bodyx = 1;
	bodyy = 0;
	bodyz = 0;
	if (bodya >= -15)
		bodya -= 0.3;

	lShoulderx = -1;
	lShouldery = 0;
	lShoulderz = 0;
	if (lShouldera >= -30)
		lShouldera -= 0.6;

	rShoulderx = -1;
	rShouldery = 0;
	rShoulderz = 0;
	if (rShouldera >= -30)
		rShouldera -= 0.6;

	lThighx = 1;
	lThighy = 0;
	lThighz = 0;
	if (lThigha >= -105)
		lThigha -= 2.1;

	rThighx = 1;
	rThighy = 0;
	rThighz = 0;
	if (rThigha >= -105)
		rThigha -= 2.1;

	lKneex = 1;
	lKneey = 0;
	lKneez = 0;
	if (lKneea <= 60)
		lKneea += 1.2;

	rKneex = 1;
	rKneey = 0;
	rKneez = 0;
	if (rKneea <= 60)
		rKneea += 1.2;

	rFingersx[0] = 1;
	rFingersy[0] = 0;
	rFingersz[0] = 0;
	if (rFingersa[0] <= 60)
		rFingersa[0] += 1.2;

	rFingersx[1] = -1;
	rFingersy[1] = 0;
	rFingersz[1] = 1;
	if (rFingersa[1] <= 60)
		rFingersa[1] += 1.2;

	rFingersx[2] = -1;
	rFingersy[2] = 0;
	rFingersz[2] = -1;
	if (rFingersa[2] <= 60)
		rFingersa[2] += 1.2;

	lFingersx[0] = 1;
	lFingersy[0] = 0;
	lFingersz[0] = 0;
	if (lFingersa[0] <= 60)
		lFingersa[0] += 1.2;

	lFingersx[1] = -1;
	lFingersy[1] = 0;
	lFingersz[1] = 1;
	if (lFingersa[1] <= 60)
		lFingersa[1] += 1.2;

	lFingersx[2] = -1;
	lFingersy[2] = 0;
	lFingersz[2] = -1;
	if (lFingersa[2] <= 60)
		lFingersa[2] += 1.2;
}

void Float()
{
	bodyMovey = 4 * cos(floatValue);
	floatValue += 0.04;
	if (floatValue == 360)
		floatValue = 0;
}

void Makankosappo()
{
	state = 0;
	rFingersx[0] = -1;
	rFingersy[0] = 0;
	rFingersz[0] = 0;
	if (rFingersa[0] <= 30)
		rFingersa[0] += 0.6;

	rFingersx[1] = 0;
	rFingersy[1] = 0;
	rFingersz[1] = -1;
	if (rFingersa[1] <= 15)
		rFingersa[1] += 0.3;

	rFingersx[2] = 0;
	rFingersy[2] = 0;
	rFingersz[2] = 1;
	if (rFingersa[2] <= 15)
		rFingersa[2] += 0.3;

	lFingersx[0] = -1;
	lFingersy[0] = 0;
	lFingersz[0] = 0;
	if (lFingersa[0] <= 30)
		lFingersa[0] += 0.6;

	lFingersx[1] = 1;
	lFingersy[1] = 0;
	lFingersz[1] = -1;
	if (lFingersa[1] <= 30)
		lFingersa[1] += 0.6;

	lFingersx[2] = 1;
	lFingersy[2] = 0;
	lFingersz[2] = 1;
	if (lFingersa[2] <= 30)
		lFingersa[2] += 0.6;
	if (MFirstStep)
	{
		lShoulderx = 1;
		lShouldery = 0;
		lShoulderz = 2;
		if (lShouldera <= 45)
			lShouldera += 0.9;

		rShoulderx = 1;
		rShouldery = 0;
		rShoulderz = 0;
		if (rShouldera >= -105)
			rShouldera -= 2.1;

		lElbowx = 1;
		lElbowy = 0;
		lElbowz = 0;
		if (lElbowa >= -90)
			lElbowa -= 1.8;

		rElbowx = 0.8;
		rElbowy = -0.5;
		rElbowz = 0;
		if (rElbowa >= -100)
			rElbowa -= 2;

		lThighx = 1;
		lThighy = -0.7;
		lThighz = 0;
		if (lThigha >= -75)
			lThigha -= 1.5;

		rThighx = 1;
		rThighy = 0.7;
		rThighz = 0;
		if (rThigha >= -75)
			rThigha -= 1.5;

		lKneex = 1;
		lKneey = -0.7;
		lKneez = 0;
		if (lKneea <= 75)
			lKneea += 1.5;

		rKneex = 1;
		rKneey = 0.7;
		rKneez = 0;
		if (rKneea <= 75)
			rKneea += 1.5;

		if (rKneea >= 75)
		{
			if (bodyMovey >= 0)
				bodyMovey -= 0.5;
			else if (bodyMovey <= 0)
				bodyMovey += 0.5;
			Delay();
		}
	}
	else
	{
		delayScale = 0;
		rShoulderx = 1;
		rShouldery = 0;
		rShoulderz = 0;
		if (rShouldera <= -90)
			rShouldera += 0.3;

		rElbowx = 1;
		rElbowy = -0.7;
		rElbowz = 0;
		if (rElbowa <= 0)
			rElbowa += 2.1;

		if (rElbowa >= 0)
			MSecondStep = false;
	}
}

void Spin()
{
	state = 0;
	bodyx = 0;
	bodyy = 1;
	bodyz = 0;
	bodya += 3.6;
	if (bodya >= 360)
		bodya = 0;

	lShoulderx = 0;
	lShouldery = 0;
	lShoulderz = 1;
	if (lShouldera <= 150)
		lShouldera += 3;

	rShoulderx = 0;
	rShouldery = 0;
	rShoulderz = 1;
	if (rShouldera >= -150)
		rShouldera -= 3;

	lElbowx = 0;
	lElbowy = 0;
	lElbowz = 1;
	if (lElbowa <= 60)
		lElbowa += 1.2;

	rElbowx = 0;
	rElbowy = 0;
	rElbowz = 1;
	if (rElbowa >= -60)
		rElbowa -= 1.2;

	rThighx = 0;
	rThighy = 0;
	rThighz = 1;
	if (rThigha >= -45)
		rThigha -= 0.9;

	rKneex = 0;
	rKneey = 0;
	rKneez = 1;
	if (rKneea <= 90)
		rKneea += 1.8;

	rFingersx[0] = -1;
	rFingersy[0] = 0;
	rFingersz[0] = 0;
	if (rFingersa[0] <= 30)
		rFingersa[0] += 0.6;

	rFingersx[1] = 1;
	rFingersy[1] = 0;
	rFingersz[1] = -1;
	if (rFingersa[1] <= 30)
		rFingersa[1] += 0.6;

	rFingersx[2] = 1;
	rFingersy[2] = 0;
	rFingersz[2] = 1;
	if (rFingersa[2] <= 30)
		rFingersa[2] += 0.6;

	lFingersx[0] = -1;
	lFingersy[0] = 0;
	lFingersz[0] = 0;
	if (lFingersa[0] <= 30)
		lFingersa[0] += 0.6;

	lFingersx[1] = 1;
	lFingersy[1] = 0;
	lFingersz[1] = -1;
	if (lFingersa[1] <= 30)
		lFingersa[1] += 0.6;

	lFingersx[2] = 1;
	lFingersy[2] = 0;
	lFingersz[2] = 1;
	if (lFingersa[2] <= 30)
		lFingersa[2] += 0.6;
}

void Genkidama()
{
	state = 0;
	lShoulderx = 0;
	lShouldery = 0;
	lShoulderz = 1;
	if (lShouldera <= 165)
		lShouldera += 3.3;

	rShoulderx = 0;
	rShouldery = 0;
	rShoulderz = 1;
	if (rShouldera >= -165)
		rShouldera -= 3.3;
	lThighx = 0;
	lThighy = 0;
	lThighz = 1;
	if (lThigha <= 15)
		lThigha += 0.3;

	rThighx = 0;
	rThighy = 0;
	rThighz = 1;
	if (rThigha >= -15)
		rThigha -= 0.3;

	rFingersx[0] = 1;
	rFingersy[0] = 0;
	rFingersz[0] = 0;
	if (rFingersa[0] <= 60)
		rFingersa[0] += 1.2;

	rFingersx[1] = -1;
	rFingersy[1] = 0;
	rFingersz[1] = 1;
	if (rFingersa[1] <= 60)
		rFingersa[1] += 1.2;

	rFingersx[2] = -1;
	rFingersy[2] = 0;
	rFingersz[2] = -1;
	if (rFingersa[2] <= 60)
		rFingersa[2] += 1.2;

	lFingersx[0] = 1;
	lFingersy[0] = 0;
	lFingersz[0] = 0;
	if (lFingersa[0] <= 60)
		lFingersa[0] += 1.2;

	lFingersx[1] = -1;
	lFingersy[1] = 0;
	lFingersz[1] = 1;
	if (lFingersa[1] <= 60)
		lFingersa[1] += 1.2;

	lFingersx[2] = -1;
	lFingersy[2] = 0;
	lFingersz[2] = -1;
	if (lFingersa[2] <= 60)
		lFingersa[2] += 1.2;
	if (rShouldera <= -165)
	{
		delaySpeed = 0.002;
		alpha = 30;
		Delay();
	}
	if (scale >= 0.7)
		scale -= 0.0009;
}

void Fusion()
{
	lShoulderx = 1.1;
	lShouldery = 1;
	lShoulderz = -0.25;
	if (lShouldera >= -150)
		lShouldera -= 3;

	rShoulderx = 1.1;
	rShouldery = 1;
	rShoulderz = -0.25;
	if (rShouldera >= -150)
		rShouldera -= 3;

	if (lShouldera <= -135)
		action = 8;
}

void Fusion_2()
{
	morex = 0;
	morey = 0;
	morez = 1;
	if (morea >= -180)
		morea -= 0.9;

	lThighx = 0;
	lThighy = 0;
	lThighz = 1;
	if (lThigha <= 45)
		lThigha += 0.9;

	rThighx = 0;
	rThighy = 0;
	rThighz = 1;
	if (rThigha >= -45)
		rThigha -= 0.9;

	lKneex = 0;
	lKneey = 0;
	lKneez = 1;
	if (lKneea >= -45)
		lKneea -= 0.9;

	rKneex = 0;
	rKneey = 0;
	rKneez = 1;
	if (rKneea <= 45)
		rKneea += 0.9;

	if (leftFoot)
	{
		bodyx = 0;
		bodyy = 0;
		bodyz = 1;
		if (bodya >= -2.5)
			bodya -= 0.25;
		else
			leftFoot = false;
	}	
	else
	{
		bodyx = 0;
		bodyy = 0;
		bodyz = 1;
		if (bodya <= 2.5)
			bodya += 0.25;
		else
			leftFoot = true;
	}

	if (lElbowa >= 0)
	{
		Delay();
		if (delayScale >= 2)
		{
			action = 9;
			delayScale = 0;
		}
	}
}

void Fusion_3()
{
	more2x = 0;
	more2y = 1;
	more2z = 0;
	if (more2a >= -90)
		more2a -= 1.8;

	bodyx = 0;
	bodyy = 0;
	bodyz = 1;
	if (bodya >= 0)
		bodya -= 0.05;
	else if (bodya <= 0)
		bodya += 0.05;

	more4x = 0;
	more4y = 1;
	more4z = 0;
	if (more4a >= -15)
		more4a -= 0.3;

	lThighx = 0;
	lThighy = 0;
	lThighz = 1;
	if (lThigha >= 0)
		lThigha -= 0.9;

	rThighx = 0;
	rThighy = 0;
	rThighz = 1;
	if (rThigha <= 50)
		rThigha += 1.9;

	lKneex = 0;
	lKneey = 0;
	lKneez = 1;
	if (lKneea <= 0)
		lKneea += 0.9;

	rKneex = 0;
	rKneey = 0;
	rKneez = 1;
	if (rKneea >= -90)
		rKneea -= 2.7;

	rFingersx[0] = -1;
	rFingersy[0] = 0;
	rFingersz[0] = 0;
	if (rFingersa[0] <= 30)
		rFingersa[0] += 0.6;

	rFingersx[1] = 1;
	rFingersy[1] = 0;
	rFingersz[1] = -1;
	if (rFingersa[1] <= 30)
		rFingersa[1] += 0.6;

	rFingersx[2] = 1;
	rFingersy[2] = 0;
	rFingersz[2] = 1;
	if (rFingersa[2] <= 30)
		rFingersa[2] += 0.6;

	lFingersx[0] = -1;
	lFingersy[0] = 0;
	lFingersz[0] = 0;
	if (lFingersa[0] <= 30)
		lFingersa[0] += 0.6;

	lFingersx[1] = 1;
	lFingersy[1] = 0;
	lFingersz[1] = -1;
	if (lFingersa[1] <= 30)
		lFingersa[1] += 0.6;

	lFingersx[2] = 1;
	lFingersy[2] = 0;
	lFingersz[2] = 1;
	if (lFingersa[2] <= 30)
		lFingersa[2] += 0.6;

	if (more2a <= -90)
	{
		Delay();
		if (delayScale >= 2)
		{
			action = 10;
			delayScale = 0;
		}
	}
}

void Fusion_4()
{
	state = 0;

	bodyx = 0;
	bodyy = 0;
	bodyz = 1;
	if (bodya >= -45)
		bodya -= 0.9;

	more3x = 1;
	more3y = 0;
	more3z = 0;
	if (more3a <= 180)
		more3a += 3.6;

	lShoulderx = 1.1;
	lShouldery = 1;
	lShoulderz = -0.25;
	if (lShouldera <= 0)
		lShouldera += 3;

	rShoulderx = 1.1;
	rShouldery = 1;
	rShoulderz = -0.25;
	if (rShouldera <= 0)
		rShouldera += 3;

	lElbowx = 1;
	lElbowy = 0;
	lElbowz = 0;
	if (lElbowa <= 165)
		lElbowa += 3.3;

	lThighx = 0;
	lThighy = 0;
	lThighz = 1;
	if (lThigha <= 120)
		lThigha += 2.4;

	rThighx = 0;
	rThighy = 0;
	rThighz = 1;
	if (rThigha >= 0)
		rThigha -= 1;

	lKneex = 0;
	lKneey = 0;
	lKneez = 1;
	if (lKneea >= -120)
		lKneea -= 2.4;

	rKneex = 0;
	rKneey = 0;
	rKneez = 1;
	if (rKneea <= 0)
		rKneea += 1.8;

	rFingersx[0] = -1;
	rFingersy[0] = 0;
	rFingersz[0] = 0;
	if (rFingersa[0] >= 0)
		rFingersa[0] -= 0.6;

	lFingersx[0] = -1;
	lFingersy[0] = 0;
	lFingersz[0] = 0;
	if (lFingersa[0] >= 0)
		lFingersa[0] -= 0.6;
}

void BigGG()
{
	state = 0;

	lShoulderx = 0;
	lShouldery = 0;
	lShoulderz = 1;
	if (lShouldera <= 90)
		lShouldera += 3;

	lElbowx = 0;
	lElbowy = 0;
	lElbowz = 1;
	if (lElbowa <= 90)
		lElbowa += 1.2;
	if (lElbowa <= 90 && BIGGnum <= 1.1)
	{
		BIGG = true;
		BIGGnum += 0.01;
	}
}

void GG()
{
	state = 0;

	bodyx = 1;
	bodyz = 0;
	bodyy = 0;
	if (bodya <= 90)
		bodya += 1.8;
	lKneex = 1;
	lKneey = 0;
	lKneez = 0;
	if (lKneea <= 90)
		lKneea += 1.8;

	rKneex = 1;
	rKneey = 0;
	rKneez = 0;
	if (rKneea <= 90)
		rKneea += 1.8;

	if (bodyMovey >= -30)
		bodyMovey -= 0.6;

	lShoulderx = 1;
	lShouldery = 0;
	lShoulderz = 0;
	if (lShouldera >= -90)
		lShouldera -= 1.8;

	rShoulderx = 1;
	rShouldery = 0;
	rShoulderz = 0;
	if (rShouldera >= -90)
		rShouldera -= 1.8;

	lThighx = 1;
	lThighy = 0;
	lThighz = 0;
	if (lThigha >= -90)
		lThigha -= 1.8;

	rThighx = 1;
	rThighy = 0;
	rThighz = 0;
	if (rThigha >= -90)
		rThigha -= 1.8;

	rElbowx = 1;
	rElbowy = 0;
	rElbowz = 0;
	if (rElbowa >= -90)
		rElbowa -= 1.8;

	lElbowx = 1;
	lElbowy = 0;
	lElbowz = 0;
	if (lElbowa >= -90)
		lElbowa -= 1.8;
}

void NobodyLikeMe()
{
	state = 0;

	bodyx = 1;
	bodyy = 0;
	bodyz = 0;

	if (bodya <= 90)
		bodya += 2;

	bodyx1 = 0;
	bodyy1 = 1;
	bodyz1 = 0;

	if (bodya1 <= 90)
		bodya1 += 2;

	neckx = 1;
	necky = 0;
	neckz = 0;
	if (necka <= 15)
		necka += 0.3;




	rShoulderx = 1;
	rShouldery = 0;
	rShoulderz = 0;
	if (rShouldera >= -90)
		rShouldera -= 1.2;

	lShoulderx = 1;
	lShouldery = 0;
	lShoulderz = 0;
	if (lShouldera >= -90)
		lShouldera -= 1.2;

	rElbowx = 1;
	rElbowy = 0;
	rElbowz = 0;
	if (rElbowa >= -85)
		rElbowa -= 1.6;

	rElbowx1 = 0;
	rElbowy1 = 0;
	rElbowz1 = 1;
	if (rElbowa1 <= 26)
		rElbowa1 += 1.6;


	lElbowx = 1;
	lElbowy = 0;
	lElbowz = 0;
	if (lElbowa >= -85)
		lElbowa -= 1.6;

	lElbowx1 = 0;
	lElbowy1 = 0;
	lElbowz1 = 1;
	if (lElbowa1 >= -26)
		lElbowa1 -= 1.6;

	if (rShouldera <= -45)
		leftFoot = false;

	lThighx = 1;
	lThighy = 0;
	lThighz = 0;
	if (lThigha >= -120)
		lThigha -= 2.5;

	rThighx = 1;
	rThighy = 0;
	rThighz = 0;
	if (rThigha >= -120)
		rThigha -= 2.5;

	lKneex = -1;
	lKneey = 0;
	lKneez = 0;
	if (lKneea >= -100)
		lKneea -= 2.3;

	rKneex = -1;
	rKneey = 0;
	rKneez = 0;
	if (rKneea >= -100)
		rKneea -= 2.3;

}

void timerFunction(int value)
{
	switch (action)
	{
	case -1:
		Delay();
	case 0:
		standby();
		break;
	case 1:
		walk();
		break;
	case 2:
		run();
		break;
	case 3:
		sit();
		break;
	case 4:
		Makankosappo();
		break;
	case 5:
		Spin();
		break;
	case 6:
		Genkidama();
		break;
	case 7:
		Fusion();
		break;
	case 8:
		Fusion_2();
		break;
	case 9:
		Fusion_3();
		break;
	case 10:
		Fusion_4();
		break;
	case 11:
		BigGG();
		break;
	case 12:
		GG();
		break;
	case 13:
		NobodyLikeMe();
		break;
	case 50:
		state = 0;
		floating = true;
		break;
	case 51:
		floating = false;
		break;
	}
	if (floating)
		Float();
	glutPostRedisplay();
	glutTimerFunc(5, timerFunction, 1);
}

void menu(int selection)
{
	if (state != 1) {
		action = 0;
		standby();
	}
	action = selection;
}

int main(int argc, char** argv)
{
	int main_menu, action_menu, count_menu;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

	glutInitWindowSize(WinWidth, WinHeight);	//< Single view

	glutInitWindowPosition(0, 0);
	glutCreateWindow("G8Project1");

	init();
	standby();

	glutKeyboardFunc(keyin);
	glutCreateMenu(menu);
	glutAddMenuEntry("Stand", 0);
	glutAddMenuEntry("Walk", 1);
	glutAddMenuEntry("Run", 2);
	glutAddMenuEntry("Sit", 3);
	glutAddMenuEntry("Spin", 5);
	glutAddMenuEntry("Makankosappo", 4);
	glutAddMenuEntry("Genki dama", 6);
	glutAddMenuEntry("Fusion", 7);
	glutAddMenuEntry("bigger", 11);
	glutAddMenuEntry("OTZ", 12);
	glutAddMenuEntry("NoBodyLikeMe", 13);
	glutAddMenuEntry("-----------", 87);
	glutAddMenuEntry("Floating", 50);
	glutAddMenuEntry("NoFloating", 51);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutTimerFunc(5, timerFunction, 1);
	glutMainLoop();
	return 0;
}