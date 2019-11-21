//Semestre 2017 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************											******//
//*************											******//
//************************************************************//
//************************************************************//

#include "texture.h"
#include "figuras.h"
#include "Camera.h"

#include "cmodel/CModel.h"

//Solo para Visual Studio 2015
#if (_MSC_VER >= 1900)
#   pragma comment( lib, "legacy_stdio_definitions.lib" )
#endif

CCamera objCamera; 
GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 

int font=(int)GLUT_BITMAP_HELVETICA_18;

GLfloat Diffuse[]= { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[]= { 0.0f, 27.0f, -5.0f, 0.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

GLfloat m_dif1[] = { 0.0f, 0.2f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat m_spec1[] = { 0.0, 0.0, 0.0, 1.0 };				// Specular Light Values
GLfloat m_amb1[] = { 0.0, 0.0, 0.0, 1.0 };				// Ambiental Light Values
GLfloat m_s1[] = {18};

CTexture text1;
CTexture text2;
CTexture text3;	//Flecha
CTexture text4;	//Pavimento
CTexture text5;	//Pasto01
CTexture text6;	//Casa01
CTexture text7;	//Casa01
CTexture text8;	//Casa01
CTexture text9;	//Casa01
CTexture text10;	//Casa01
CTexture text11;	//Casa01
CTexture text12;	//Casa01
CTexture text13;	//Casa01
CTexture text16;	//Casa01

CFiguras fig1;
CFiguras fig2;
CFiguras fig3;
CFiguras fig4;	//Pasto01
CFiguras fig5;	//Casa01
CFiguras fig6;

CFiguras fig7; //Para el monito

//Figuras de 3D Studio

CModel sofa;
CModel table1;
CModel table2;
CModel chair;
CModel desk;

//Animación del coche
float movKit = 0.0;
float rotKit = 0.0;
bool g_fanimacion = false;

			
void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo	

	glEnable(GL_TEXTURE_2D);

	glShadeModel (GL_SMOOTH);
	glLightfv(GL_LIGHT1, GL_POSITION, Position);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, Diffuse);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable ( GL_COLOR_MATERIAL );

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);

	/* setup blending */
	glEnable(GL_BLEND);			// Turn Blending On
    
    text1.LoadBMP("01.bmp");
	text1.BuildGLTexture();
	text1.ReleaseImage();

	text2.LoadBMP("tejado.bmp");
	text2.BuildGLTexture();
	text2.ReleaseImage();

	text3.LoadTGA("muros.tga");
	text3.BuildGLTexture();
	text3.ReleaseImage();

	text4.LoadBMP("pared1.bmp");
	text4.BuildGLTexture();
	text4.ReleaseImage();

	text5.LoadBMP("pared2.bmp");
	text5.BuildGLTexture();
	text5.ReleaseImage();

	text6.LoadBMP("piso.bmp");
	text6.BuildGLTexture();
	text6.ReleaseImage();


	text7.LoadBMP("door.bmp");
	text7.BuildGLTexture();
	text7.ReleaseImage();
	text16.LoadBMP("cesped.bmp");
	text16.BuildGLTexture();
	text16.ReleaseImage();
	



	

	
	
	sofa._3dsLoad("Koltuk.3ds");
	table1._3dsLoad("Wood_Table.3ds");
	table2._3dsLoad("table-01.3ds");
	chair._3dsLoad("Chair_Directors.3ds");
	desk._3dsLoad("StylishDesk.3ds");
	

	
	

	objCamera.Position_Camera(10, 2.5f, 13, 10, 2.5f, 10, 0, 1, 0);

}

void pintaTexto(float x, float y, float z, void *font,char *string)
{
  
  char *c;     //Almacena los caracteres a escribir
  glRasterPos3f(x, y, z);	//Posicion apartir del centro de la ventana
  //glWindowPos2i(150,100);
  for (c=string; *c != '\0'; c++) //Condicion de fin de cadena
  {
    glutBitmapCharacter(font, *c); //imprime
  }
}



void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	glPushMatrix();
		glRotatef(g_lookupdown, 1.0f, 0, 0);
		gluLookAt(objCamera.mPos.x, objCamera.mPos.y, objCamera.mPos.z,
			objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,
			objCamera.mUp.x, objCamera.mUp.y, objCamera.mUp.z);
		glPushMatrix();
			glPushMatrix(); //Creamos cielo
				glDisable(GL_LIGHTING);
				glTranslatef(0, 60, 0);
				fig1.skybox(900.0, 900.0, 900.0, text1.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();
		glPushMatrix();

		

				//Para que el comando glColor funcione con iluminacion
				glEnable(GL_COLOR_MATERIAL);

				glTranslatef(-100.0, -0.2, -80.0);
				glScalef(240, 0.1, 180);
				glDisable(GL_LIGHTING);
				fig4.prisma2(text16.GLindex, text16.GLindex);
				glEnable(GL_LIGHTING);
				glPopMatrix();
			
	
				
				glPushMatrix(); //Casa01
					glScalef(1.0,1.0,1.0);
					glDisable(GL_LIGHTING);
					fig5.piso(text3.GLindex, text4.GLindex, text5.GLindex, text6.GLindex, text7.GLindex);
					glEnable(GL_LIGHTING);
				glPopMatrix();

				//SOFA
				glPushMatrix();
				glTranslatef(2.0f, 0.17, -10.5); //FRONTAL DERECHA
				sofa.GLrender(NULL, _SHADED, 1.0);
				glPopMatrix();
				
				//mesa
				glPushMatrix();
				glTranslatef(2.0f, 0.0, -8.5); //FRONTAL DERECHA
				table1.GLrender(NULL, _SHADED, 1.0);
				glPopMatrix();

				//chair
				glPushMatrix();
				glScalef(0.02f, 0.02f, 0.02f);
				glTranslatef(2.0f, 0.0, -6.5); //FRONTAL DERECHA
				chair.GLrender(NULL, _SHADED, 1.0);
				
				glPopMatrix();
						glPushMatrix(); //Casa01
					glScalef(1.0,1.0,1.0);
					glDisable(GL_LIGHTING);
					fig5.piso(text3.GLindex, text4.GLindex, text5.GLindex, text6.GLindex, text7.GLindex);
					glEnable(GL_LIGHTING);
				glPopMatrix();

				//SOFA
				glPushMatrix();
				glTranslatef(2.0f, 0.17, -10.5); //FRONTAL DERECHA
				sofa.GLrender(NULL, _SHADED, 1.0);
				glPopMatrix();
				
				//mesa
				glPushMatrix();
				glTranslatef(2.0f, 0.0, -8.5); //FRONTAL DERECHA
				table1.GLrender(NULL, _SHADED, 1.0);
				glPopMatrix();

				//chair
				glPushMatrix();
				glScalef(0.02f, 0.02f, 0.02f);
				glTranslatef(2.0f, 0.0, -6.5); //FRONTAL DERECHA
				chair.GLrender(NULL, _SHADED, 1.0);
				
				glPopMatrix();



				glPushMatrix(); //Casa01
				glTranslatef(0.0f, 4.001f, 0.0);
					glPushMatrix(); //Casa01
					glScalef(1.0, 1.0, 1.0);
					glDisable(GL_LIGHTING);
					fig5.piso(text3.GLindex, text4.GLindex, text5.GLindex, text6.GLindex, text7.GLindex);
					glEnable(GL_LIGHTING);
					glPopMatrix();

					//SOFA
					glPushMatrix();
					glTranslatef(0.0f, 3.999f, 0.0);
					glTranslatef(2.0f, 0.17, -10.5); //FRONTAL DERECHA
					sofa.GLrender(NULL, _SHADED, 1.0);
					glPopMatrix();

					//mesa
					glPushMatrix();
					glTranslatef(0.0f, 3.999f, 0.0);
					glTranslatef(2.0f, 0.0, -8.5); //FRONTAL DERECHA
					table1.GLrender(NULL, _SHADED, 1.0);
					glPopMatrix();

					//chair
					glPushMatrix();
					//glTranslatef(0.0f, 3.999f, 0.0);
					glScalef(0.02f, 0.02f, 0.02f);
					glTranslatef(2.0f, 0.0, -6.5); //FRONTAL DERECHA
					chair.GLrender(NULL, _SHADED, 1.0);

					glPopMatrix();
				glPopMatrix();



				//glPushMatrix(); //Casa01
				//glTranslatef(0.0f, 8.002f, 0.0);
				//glPushMatrix(); //Casa01
				//glScalef(1.0, 1.0, 1.0);
				//glDisable(GL_LIGHTING);
				//fig5.piso(text3.GLindex, text4.GLindex, text5.GLindex, text6.GLindex, text7.GLindex);
				//glEnable(GL_LIGHTING);
				//glPopMatrix();

				////SOFA
				//glPushMatrix();
				//
				//glTranslatef(2.0f, 0.17, -10.5); //FRONTAL DERECHA
				//sofa.GLrender(NULL, _SHADED, 1.0);
				//glPopMatrix();

				////mesa
				//glPushMatrix();
				//
				//glTranslatef(2.0f, 0.0, -8.5); //FRONTAL DERECHA
				//table1.GLrender(NULL, _SHADED, 1.0);
				//glPopMatrix();

				////chair
				//glPushMatrix();
				//
				//glScalef(0.02f, 0.02f, 0.02f);
				//glTranslatef(2.0f, 0.0, -6.5); //FRONTAL DERECHA
				//chair.GLrender(NULL, _SHADED, 1.0);

				//glPopMatrix();
				//glPopMatrix();





	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
		glColor3f(1.0,0.0,0.0);
		pintaTexto(-12,12.0,-14.0,(void *)font,"Proyecto Oficinas");
		
		glColor3f(1.0,1.0,1.0);
	glEnable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);

	glutSwapBuffers ( );

}

void animacion()
{
	fig3.text_izq-= 0.001;
	fig3.text_der-= 0.001;
	if(fig3.text_izq<-1)
		fig3.text_izq=0;
	if(fig3.text_der<0)
		fig3.text_der=1;


	if(g_fanimacion)
	{
		movKit +=1.0;
	}

	if (g_fanimacion)
	{
		rotKit += 1.0;
	}

	glutPostRedisplay();
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 870.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {




		case 'w':   //Movimientos de camara
		case 'W':
			objCamera.Move_Camera( CAMERASPEED+1.0 );
			break;

		case 's':
		case 'S':
			objCamera.Move_Camera(-(CAMERASPEED+1.0));
			break;

		case 'a':
		case 'A':
			objCamera.Strafe_Camera(-(CAMERASPEED+1.0));
			break;

		case 'd':
		case 'D':
			objCamera.Strafe_Camera( CAMERASPEED+1.0 );
			break;

		case 't':   //Movimientos de camara
		case 'T':
			objCamera.Move_Camera(CAMERASPEED + 0.2);
			break;

		case 'g':
		case 'G':
			objCamera.Move_Camera(-(CAMERASPEED + 0.2));
			break;

		case 'f':
		case 'F':
			objCamera.Strafe_Camera(-(CAMERASPEED + 0.2));
			break;

		case 'h':
		case 'H':
			objCamera.Strafe_Camera(CAMERASPEED + 0.2);
			break;

		case ' ':		//Poner algo en movimiento
			g_fanimacion^= true; //Activamos/desactivamos la animacíon
			break;

		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
			break;        
		default:        // Cualquier otra
			break;
  }

  glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
	case GLUT_KEY_PAGE_UP:
		objCamera.UpDown_Camera(CAMERASPEED*.7);
		break;

	case GLUT_KEY_PAGE_DOWN:
		objCamera.UpDown_Camera(-CAMERASPEED*.7);
		break;

    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		g_lookupdown -= 1.0f;
		break;

    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		g_lookupdown += 1.0f;
		break;

	case GLUT_KEY_LEFT:
		objCamera.Rotate_View(-CAMERASPEED);
		break;

	case GLUT_KEY_RIGHT:
		objCamera.Rotate_View( CAMERASPEED);
		break;

    default:
		break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (800, 800);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 10"); // Nombre de la Ventana
  //glutFullScreen     ( );         // Full Screen
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );
  glutMainLoop        ( );          // 

  return 0;
}
