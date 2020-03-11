#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

// 16 adet bezier noktası
GLfloat k[4][4][3] = {
   {{-1.5, -1.5, 4.0}, {-0.5, -1.5, 2.0},
    {0.5, -1.5, -1.0}, {1.5, -1.5, 2.0}},
   {{-1.5, -0.5, 1.0}, {-0.5, -0.5, 1.0},
    {1.5, -0.5, 0.0}, {1.5, -0.5, -1.0}},
   {{-1.5, 0.5, 4.0}, {-1.5, 0.5, 0.0},
    {0.5, 0.5, 3.0}, {1.5, 0.5, 4.0}},
   {{-1.5, 1.5, -2.0}, {-0.5, 1.5, -2.0},
    {0.5, 1.5, 0.0}, {3.5, 1.5, -1.0}}
};

// Işık kaynağının kordinatı
GLfloat light[3] = {0.5f,1.5f,0.0f} ;

// bezier yüzeyinin gerçekçiliği
int hassasiyet = 30;

// Kamera yönü için dönüş açısı
float angle = 0.0f;
// Kameranın yönünü temsil eden asıl vektör
float lx=0.0f,lz=-1.0f;
// Kameranın XZ konumu
float x=0.0f, z=5.0f;
// tuş durumları. Bu değişkenler sıfır olacak
// Hiç tuş basımı olmadığında
float deltaAngle = 0.0f;
float deltaMove = 0;
int xOrigin = -1;

int faktoriyel(int s){
	if(s <= 1) return 1;
	return s * faktoriyel(s - 1);
}
int permutasyon(int n,int i){
	return faktoriyel(n)/(faktoriyel(i)*faktoriyel(n-i));
}
float ust(float x,int k){
	return (float)pow((double)x,(double)k);
}

// Bi,n(u) Bezierin için n.dereceden binom fonksiyonu
float B(int i,int n,float u){
	return ((float)permutasyon(n,i)) * ust(u,i) * ust((1.0f-u),(n-i));
}

// p(u,v) - Bezier noktasını veren fonksiyon
float p(float u,float v,int d/* d : dimesion boyut 0x 1y 2z */){
	int i,j; /* cache */
	float out=0; /* çıktı */

	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++){
			out = out + B(i,3,u) * B(j,3,v) * k[i][j][d];
		}
	return out;
}


/* 2 nokta arasındaki farkı bulur */
float d(float x1,float y1,float z1,float x2,float y2,float z2){
	return (float)(sqrt((double)(ust((x2-x1),2) + ust((y2-y1),2) + ust((z2-z1),2))));
}



void bezirYuzey(void){ // bu fonksiyon bezier yüzeyi oluşturur
int i,j,v;
float I,f,x[4],y[4],z[4],nx,ny,nz,nd,lx,ly,lz,ld,alfa,calfa,k=0.0000001f;

	// ışığın birim vektörünü hesaplayalım
	ld = d(0.0f,0.0f,0.0f,light[0],light[1],light[2]);
	lx = light[0]/ld;
	ly = light[1]/ld;
	lz = light[2]/ld;


   glPointSize(2.0);
      for (i = 0; i < hassasiyet; i++)
		for (j = 0; j < hassasiyet; j++) {
			// yüzeyin noktalarını hesapla
			x[0] = p(1.00f*i/hassasiyet,1.00f*j/hassasiyet,0);
			x[1] = p(1.00f*i/hassasiyet,1.00f*(j+1)/hassasiyet,0);
			x[2] = p(1.00f*(i+1)/hassasiyet,1.00f*(j+1)/hassasiyet,0);
			x[3] = p(1.00f*(i+1)/hassasiyet,1.00f*j/hassasiyet,0);
			y[0]= p(1.00f*i/hassasiyet,1.00f*j/hassasiyet,1);
			y[1]= p(1.00f*i/hassasiyet,1.00f*(j+1)/hassasiyet,1);
			y[2]= p(1.00f*(i+1)/hassasiyet,1.00f*(j+1)/hassasiyet,1);
			y[3]= p(1.00f*(i+1)/hassasiyet,1.00f*j/hassasiyet,1);
			z[0] = p(1.00f*i/hassasiyet,1.00f*j/hassasiyet,2);
			z[1] = p(1.00f*i/hassasiyet,1.00f*(j+1)/hassasiyet,2);
			z[2] = p(1.00f*(i+1)/hassasiyet,1.00f*(j+1)/hassasiyet,2);
			z[3] = p(1.00f*(i+1)/hassasiyet,1.00f*j/hassasiyet,2);

			// normal vektorü  hesaplayalım
			nx = ((y[1] - y[2]) * (z[2] - z[3])) - ((z[1] - z[2]) * (y[2] - y[3]));
			ny = ((z[1] - z[2]) * (x[2] - x[3])) - ((x[1] - x[2]) * (z[2] - z[3]));
			nz = ((x[1] - x[2]) * (y[2] - y[3])) - ((y[1] - y[2]) * (x[2] - x[3]));
			// normal vektörünün uzunluğu
			nd = d(0.0f,0.0f,0.0f,nx,ny,nz);
			// normal vektörünü, birim vektor haline getirelin
			nx /= nd;
			ny /= nd;
			nz /= nd;



			//alfa ; ışık vektörü ile normal vektörü arasındaki açıdır
			// <n,l> = |n|*|l|*cosALFA; n ve l nin uzunluğu 1dir
			alfa = (float)acos((double)((nx*lx) + (ny*ly) + (nz*lz)));

			// calfa = cos(alfa)'dır'
			calfa = (float)cos((double)alfa);

			// f : normal(orta nokta) ile ışık kaynağı arası mesafe
			f = d(light[0],light[1],light[2],p(1.00f*(i+0.5f)/hassasiyet,1.00f*(j+0.5f)/hassasiyet,0),p(1.00f*(i+0.5f)/hassasiyet,1.00f*(j+0.5f)/hassasiyet,1),p(1.00f*(i+0.5f)/hassasiyet,1.00f*(j+0.5f)/hassasiyet,2));

			// ışık şiddetini hesapla
			I = 1.0f*calfa / (f+k); // ışık fonksiyonu

   		   glColor3f(I*0.05f,I,I); // ışıklandırmaya göre yüze renk ver

		   glBegin(GL_QUADS); // yüzeyi çiz
			   for(v = 0; v< 4;v++ )
			         glVertex3f(x[v],y[v],z[v]);
		   glEnd();

		}

}



void changeSize(int w, int h) { //penceri boyutu değişirse
	// sıfırla bölmeyi önle.
	if (h == 0)
		h = 1;

	float ratio = w * 1.0 / h;

	// Projection Matrisini aktif et
	glMatrixMode(GL_PROJECTION);

	// Matrisi resetle
	glLoadIdentity();

	// viewport olarak tüm pencereyi set et
	glViewport(0, 0, w, h);

	// uygun perspektifi set et.
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);

	// Modelview’e geç
	glMatrixMode(GL_MODELVIEW);
}


void computePos(float deltaMove) { // kamere pozisyonu hesapla
	x += deltaMove * lx * 0.1f;
	z += deltaMove * lz * 0.1f;
}

void renderScene(void) {
	int i,j;
	if (deltaMove)
		computePos(deltaMove);

	// Color ve Depth Bufferları temizle
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// dönüşümleri Resetle

	glLoadIdentity();

	// kamerayı set et
	gluLookAt(
	x, 1.0f, z,
	x+lx, 1.0f, z+lz,
	0.0f, 1.0f, 0.0f);

	// bezier noktalarını çiz
   glPointSize(5.0);
   glColor3f(1.0, 0.0, 0.0);
   glBegin(GL_POINTS);
      for (i = 0; i < 4; i++)
	for (j = 0; j < 4; j++)
         glVertex3fv(&k[i][j][0]);
   glEnd();

   glPointSize(10.0);
   glColor3f(1.0, 1.0, 0.0);
   glBegin(GL_POINTS);
         glVertex3fv(&light[0]);
   glEnd();


   // bezier yüzeyini çız
   bezirYuzey();

   // bezier yüzeyin noktalarını hareket ver
   /*k[3][3][2] = k[3][3][2] + 0.01f;
   k[1][2][2] = k[1][2][2] - 0.01f;*/
   light[2] += 0.01f;
   light[1] -= 0.001f;

   glutSwapBuffers();
}

// -----------------------------------//
//KLAVYE
// -----------------------------------
void processNormalKeys(unsigned char key, int xx, int yy) {
	if (key == 27)
		exit(0);
}
void pressKey(int key, int xx, int yy) {
	switch (key) {
		case GLUT_KEY_UP : deltaMove = 0.5f; break;
		case GLUT_KEY_DOWN : deltaMove = -0.5f; break;
	}
}
void releaseKey(int key, int x, int y) {
	switch (key) {
		case GLUT_KEY_UP :
		case GLUT_KEY_DOWN : deltaMove = 0;break;
	}
}

// -----------------------------------
//
//FARE
// -----------------------------------
void mouseMove(int x, int y) {// Bu sadece, sol düğme basılı olduğu zaman doğru olacak
	if (xOrigin >= 0) {
		// deltaAngle’i güncelle
		deltaAngle = (x - xOrigin) * 0.001f;
		// kamera'nın yönünü güncelle
		lx = sin(angle + deltaAngle);
		lz = -cos(angle + deltaAngle);
	}
}
void mouseButton(int button, int state, int x, int y) {
	// Sadece eğer sol düğme basılırsa harekete başla
	if (button == GLUT_LEFT_BUTTON) {
		// Düğme bırakıldığı zaman
		if (state == GLUT_UP) {
			angle += deltaAngle;
			xOrigin = -1;
		}
		else {// state = GLUT_DOWN
			xOrigin = x;
		}
	}
}

// -----------------------------------
//
//MAIN
// -----------------------------------
int main(int argc, char **argv) {
	// GLUT’u ilkle ve pencereyi yarat
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(900,900);
	glutCreateWindow("Bezier Egrisi");
	// callbackleri kaydet
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);
	glutIgnoreKeyRepeat(1);
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(pressKey);
	glutSpecialUpFunc(releaseKey);
	// iki yeni fonksiyon burada
	glutMouseFunc(mouseButton);
	glutMotionFunc(mouseMove);
	// OpenGL ilklemeleri
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	// GLUT olay işleme döngüsüne gir
	glutMainLoop();
	return 0;
}
