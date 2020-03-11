#include <stdlib.h>
#include <GL/glut.h>

#define EKRAN 720

/*
   ### CC BY-SA Lisansı ###
   http://ozgurlisanslar.org.tr/creative-commons/attribution-sharealike-cc-by-sa/
   Faruk Can tarafından geliştirildi.
   Hakları Saklıdır. ve Faruk Can'a aittir
   Lütfen alıntı yaptığınızı belirtiniz.
   omer@farukcan.net
*/

GLfloat p[4][2] = {
    {-0.9f,0}, // p0
    {0.1f,0.9f}, // p1
    {0.5,0.9f}, // p2
    {0.9f,0} // p3
}; // 4 adet bezier noktası

int hassasiyet = 5; // bezier eğirisinin kaç çizgiden oluşacağını belirler

// fonk - draw - görüntüyü çizer
void draw (void)
{

   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // önceki görüntüyü temizle

   bezierEgrisi(hassasiyet);
   bezierNoktalari();

   glFlush();

}//enddraw

// fonk - c - bezier noktalarını oluşturan formül c(t) = p0*(1-t)^3 + 3p1*t*(1-t)^2 + 3p2t^2(1-t) + p3t^3
GLfloat c (
    /* in */ GLfloat t,
    /* in */ int y)
{

    /*out*/ return p[0][y]*(1.0f-t)*(1.0f-t)*(1.0f-t) +
            3*p[1][y]*t*(1.0f-t)*(1.0f-t) +
            3*p[2][y]*t*t*(1.0f-t) +
            p[3][y]*t*t*t;
} //endc

// fonk - bezierEgrisi - bezir egrisi çizer
void bezierEgrisi (
   /* in */        int hassasiyet )
{
   /* cache */    int i;

   glColor3f(1.0, 1.0, 1.0); // beyaz renkte çiz

   glBegin(GL_LINE_STRIP);

    for(i = 0 ; i<=hassasiyet ; i++)
        glVertex3f(c(1.00f*i/hassasiyet,0),c(1.00f*i/hassasiyet,1),0.0f);

   glEnd();
}

// fonk - bezierNoktalari - bezir noktalarını çizer
void bezierNoktalari (
    /* - */ void)
{
   /* cache */ int i;

   glColor3f(1.0, 0.0, 0.0); // kırmızı renkte çiz
   glPointSize(5.0f); // 5kat büyük nokta
   glBegin(GL_POINTS);
    for (i = 0; i < 4; i++)
        glVertex3f(p[i][0],p[i][1],0.0f);
   glEnd();

}

// fonk - farkkare - iki nokta arası farkın karesidir
float farkkare(float x,float y,float m,float n){
    return (m-x)*(m-x) + (n-y)*(n-y);
}

// mouse ün koordinat düzlemini, opengl koordinat düzlemi çevirirler.
float ekran2koorx(float x){
    return (((float)x/(float)EKRAN))*2 -1;
}
float ekran2koory(float x){
    return (((float)x/(float)EKRAN))*-2 + 1;
}

// yeri değiştirmek üzere seçilen noktadır
int secili_nokta=0;
// fonk - mousea tıklandığında en yakın noktayı seçer
void bezir_noktasi_sec( int x, int y){
    float min=2.0f,d;
    int i;
    for (i = 0; i < 4; i++){
        d = farkkare(ekran2koorx(x),ekran2koory(y),p[i][0],p[i][y]);
        printf("fark nokta %f\n",d );

        if( d < min){
            min = d;
            secili_nokta = i;            
        }
    }
    printf("secili nokta %i\n",secili_nokta );
}

// fonk - seçili noktanın koordinatlarını değiştirir
void bezir_noktasi_degistir(int x, int y){
 p[secili_nokta][0] = ekran2koorx(x);
 p[secili_nokta][1] = ekran2koory(y);
}

void keyboard(unsigned char key, int x, int y){
    printf("%c %i | %i %i \n",key,key,x,y );
    if(key==43) hassasiyet+=1; // hassasiyeti arttır + tuşu
    if(key==45) hassasiyet-=1; // hassasiyeti azalt - tuşu
    if(key==104) printf("hassasiyet : %i\n",hassasiyet ); // h tuşu
}
void skeyboard(unsigned char key, int x, int y){
    printf("skey %i | %i %i \n",key,key,x,y );
}

void mouse(int buton,int durum,int x,int y){
    printf("mouse %i %i %i %i\n",buton,durum,x,y );
    if(buton==0 &amp;&amp; durum==0) bezir_noktasi_sec(x,y); // mouse tıklmasında en yakın nokta sec
    else if((buton==0 &amp;&amp; durum==1) ) bezir_noktasi_degistir(x,y); // en yakın noktayı değiştir
}

int main(int argc, char** argv)
{
   glutInit(&amp;argc, argv);
   glutInitDisplayMode (GLUT_ALPHA | GLUT_RGBA);

   glutInitWindowSize (EKRAN, EKRAN); //pencere boyutu
   glutInitWindowPosition (100, 100); // pencerenin ana konumu

   glutCreateWindow (argv[0]);

   glutIdleFunc(draw);
   glutKeyboardFunc(keyboard);
   glutSpecialFunc(skeyboard);
   glutMouseFunc(mouse);

   glutMainLoop();

   return 0;
}
