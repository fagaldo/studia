#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include<GL/gl.h>
#include<GL/glu.h>

class XYZ
{
public:
	GLfloat X;
	GLfloat Y;
	GLfloat Z;
	XYZ(GLfloat X, GLfloat Y, GLfloat Z)
	{
		this->X = X;
		this->Y = Y;
		this->Z = Z;
	}
};

class Vector
{
public:
	GLfloat X;
	GLfloat Y;
	GLfloat Z;
	Vector(XYZ origin, XYZ destination)
	{
		X = destination.X - origin.X;
		Y = destination.Y - origin.Y;
		Z = destination.Z - origin.Z;
	}
	Vector(Vector W1, Vector W2)
	{
		X = W1.Y * W2.Z - W2.Y * W1.Z;
		Y = W2.X * W1.Z - W1.X * W2.Z;
		Z = W1.X * W2.Y - W2.X * W1.Y;
	}
};

XYZ Observer(5.0f, 5.0f, 5.0f);

XYZ WALL1_P1(-3, 3, 3);
XYZ WALL1_P2(-3, -3, 3);
XYZ WALL1_P3(3, -3, 3);
XYZ WALL1_P4(3, 3, 3);
XYZ WALL1_CENTER(0, 0, 3);

Vector WALL1_W1(WALL1_P1, WALL1_P2);
Vector WALL1_W2(WALL1_P1, WALL1_P3);
Vector WALL1_N(WALL1_W1, WALL1_W2);


XYZ WALL2_P1(-3, -3, -3);
XYZ WALL2_P2(-3, 3, -3);
XYZ WALL2_P3(3, 3, -3);
XYZ WALL2_P4(3, -3, -3);
XYZ WALL2_CENTER(0, 0, -3);

Vector WALL2_W1(WALL2_P1, WALL2_P2);
Vector WALL2_W2(WALL2_P1, WALL2_P3);
Vector WALL2_N(WALL2_W1, WALL2_W2);



XYZ WALL3_P1(-3, -3, 3);
XYZ WALL3_P2(-3, -3, -3);
XYZ WALL3_P3(3, -3, -3);
XYZ WALL3_P4(3, -3, 3);
XYZ WALL3_CENTER(0, -3, 0);

Vector WALL3_W1(WALL3_P1, WALL3_P2);
Vector WALL3_W2(WALL3_P1, WALL3_P3);
Vector WALL3_N(WALL3_W1, WALL3_W2);



XYZ WALL4_P1(-3, 3, -3);
XYZ WALL4_P2(-3, 3, 3);
XYZ WALL4_P3(3, 3, 3);
XYZ WALL4_P4(3, 3, -3);
XYZ WALL4_CENTER(0, 3, 0);

Vector WALL4_W1(WALL4_P1, WALL4_P2);
Vector WALL4_W2(WALL4_P1, WALL4_P3);
Vector WALL4_N(WALL4_W1, WALL4_W2);


XYZ WALL5_P1(3, 3, -3);
XYZ WALL5_P2(3, 3, 3);
XYZ WALL5_P3(3, -3, 3);
XYZ WALL5_P4(3, -3, -3);
XYZ WALL5_CENTER(3, 0, 0);

Vector WALL5_W1(WALL5_P1, WALL5_P2);
Vector WALL5_W2(WALL5_P1, WALL5_P3);
Vector WALL5_N(WALL5_W1, WALL5_W2);




XYZ WALL6_P1(-3, 3, 3);
XYZ WALL6_P2(-3, 3, -3);
XYZ WALL6_P3(-3, -3, -3);
XYZ WALL6_P4(-3, -3, 3);
XYZ WALL6_CENTER(-3, 0, 0);

Vector WALL6_W1(WALL6_P1, WALL6_P2);
Vector WALL6_W2(WALL6_P1, WALL6_P3);
Vector WALL6_N(WALL6_W1, WALL6_W2);



bool isVisible(Vector N, Vector V)
{
	if (N.X * V.X + N.Y * V.Y + N.Z * V.Z >= 0)
		return true;
	return false;
}

void DrawScene(GLfloat xRot, GLfloat yRot) 
{
	int i;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
	glLoadIdentity();

    glRotatef(xRot, 1.0f, 0.0f, 0.0f);
    glRotatef(yRot, 0.0f, 1.0f, 0.0f);

	glBegin(GL_LINES);
		glColor3f(1,1,1);
		glVertex3f(10,0,0);
		glVertex3f(-10,0,0);
		glVertex3f(0,10,0);
		glVertex3f(0,-10,0);
		glVertex3f(0,0,10);
		glVertex3f(0,0,-10);
	glEnd();




	Vector WALL1_V(WALL1_CENTER, Observer);

	if (isVisible(WALL1_N, WALL1_V))
	{
		glBegin(GL_QUADS);
		glColor4f(0, 1.0, 0, 0.6);
		glVertex3f(WALL1_P1.X, WALL1_P1.Y, WALL1_P1.Z);
		glVertex3f(WALL1_P2.X, WALL1_P2.Y, WALL1_P2.Z);
		glVertex3f(WALL1_P3.X, WALL1_P3.Y, WALL1_P3.Z);
		glVertex3f(WALL1_P4.X, WALL1_P4.Y, WALL1_P4.Z);
		glEnd();
	}


	Vector WALL2_V(WALL2_CENTER, Observer);
	if (isVisible(WALL2_N, WALL2_V))
	{
		glBegin(GL_QUADS);
		glColor3f(1, 0, 0);
		glVertex3f(WALL2_P1.X, WALL2_P1.Y, WALL2_P1.Z);
		glVertex3f(WALL2_P2.X, WALL2_P2.Y, WALL2_P2.Z);
		glVertex3f(WALL2_P3.X, WALL2_P3.Y, WALL2_P3.Z);
		glVertex3f(WALL2_P4.X, WALL2_P4.Y, WALL2_P4.Z);
		glEnd();
	}


	Vector WALL3_V(WALL3_CENTER, Observer);
	if (isVisible(WALL3_N, WALL3_V))
	{
		glBegin(GL_QUADS);
		glColor3f(0, 0, 1);
		glVertex3f(WALL3_P1.X, WALL3_P1.Y, WALL3_P1.Z);
		glVertex3f(WALL3_P2.X, WALL3_P2.Y, WALL3_P2.Z);
		glVertex3f(WALL3_P3.X, WALL3_P3.Y, WALL3_P3.Z);
		glVertex3f(WALL3_P4.X, WALL3_P4.Y, WALL3_P4.Z);
		glEnd();
	}



	Vector WALL4_V(WALL4_CENTER, Observer);
	if (isVisible(WALL4_N, WALL4_V))
	{
		glBegin(GL_QUADS);
		glColor3f(0, 1, 1);
		glVertex3f(WALL4_P1.X, WALL4_P1.Y, WALL4_P1.Z);
		glVertex3f(WALL4_P2.X, WALL4_P2.Y, WALL4_P2.Z);
		glVertex3f(WALL4_P3.X, WALL4_P3.Y, WALL4_P3.Z);
		glVertex3f(WALL4_P4.X, WALL4_P4.Y, WALL4_P4.Z);
		glEnd();
	}


	Vector WALL5_V(WALL5_CENTER, Observer);
	if (isVisible(WALL5_N, WALL5_V))
	{
		glBegin(GL_QUADS);
		glColor3f(1, 0, 1);
		glVertex3f(WALL5_P1.X, WALL5_P1.Y, WALL5_P1.Z);
		glVertex3f(WALL5_P2.X, WALL5_P2.Y, WALL5_P2.Z);
		glVertex3f(WALL5_P3.X, WALL5_P3.Y, WALL5_P3.Z);
		glVertex3f(WALL5_P4.X, WALL5_P4.Y, WALL5_P4.Z);
		glEnd();
	}

	Vector WALL6_V(WALL6_CENTER, Observer);
	if (isVisible(WALL6_N, WALL6_V))
	{
		glBegin(GL_QUADS);
		glColor3f(0.7, 0.3, 0.4);
		glVertex3f(WALL6_P1.X, WALL6_P1.Y, WALL6_P1.Z);
		glVertex3f(WALL6_P2.X, WALL6_P2.Y, WALL6_P2.Z);
		glVertex3f(WALL6_P3.X, WALL6_P3.Y, WALL6_P3.Z);
		glVertex3f(WALL6_P4.X, WALL6_P4.Y, WALL6_P4.Z);
		glEnd();
	}



	glBegin(GL_LINES);
		glColor3f(1, 1, 0);
		glVertex3f(Observer.X, Observer.Y, Observer.Z);
		glVertex3f(WALL1_CENTER.X, WALL1_CENTER.Y, WALL1_CENTER.Z);

		glVertex3f(Observer.X, Observer.Y, Observer.Z);
		glVertex3f(WALL2_CENTER.X, WALL2_CENTER.Y, WALL2_CENTER.Z);

		glVertex3f(Observer.X, Observer.Y, Observer.Z);
		glVertex3f(WALL3_CENTER.X, WALL3_CENTER.Y, WALL3_CENTER.Z);

		glVertex3f(Observer.X, Observer.Y, Observer.Z);
		glVertex3f(WALL4_CENTER.X, WALL4_CENTER.Y, WALL4_CENTER.Z);

		glVertex3f(Observer.X, Observer.Y, Observer.Z);
		glVertex3f(WALL5_CENTER.X, WALL5_CENTER.Y, WALL5_CENTER.Z);

		glVertex3f(Observer.X, Observer.Y, Observer.Z);
		glVertex3f(WALL6_CENTER.X, WALL6_CENTER.Y, WALL6_CENTER.Z);

	glEnd();





	glFlush();

	glEnd();
	glFinish();
}

void SetMyPixelFormat(HDC hdc) 
{
	PIXELFORMATDESCRIPTOR pfd;
	ZeroMemory(&pfd, sizeof(pfd));
	pfd.nSize = sizeof(pfd);
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 32;
	pfd.cDepthBits = 16;
	pfd.iLayerType = PFD_MAIN_PLANE;

	int nPixelFormat = ChoosePixelFormat(hdc, &pfd);
	SetPixelFormat(hdc, nPixelFormat, &pfd);
}
void ResizeWindow(int width, int height)
{
	if (height*width==0) return;
	glViewport(0,0,width,height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-10, 10, -10, 10, -10, 10);
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
	glEnable(GL_DEPTH_TEST);
	
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);// set the blend mode
  	//glEnable(GL_BLEND); //obligatory for blending and transparencies
	glEnable(GL_LINE_SMOOTH);

	//glEnable(GL_CULL_FACE);
	
	glShadeModel(GL_FLAT);
	//glShadeModel(GL_SMOOTH);
}
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	static HGLRC hrc;
	static GLfloat xRot = 0.0f;
	static GLfloat yRot = 0.0f;

	switch (message) 
	{
	case WM_SIZE: 
		ResizeWindow(LOWORD(lParam),HIWORD(lParam));
		break;
	case WM_CREATE:
		hdc = GetDC(hWnd);
		SetMyPixelFormat(hdc);
		hrc = wglCreateContext(hdc);
		wglMakeCurrent(hdc, hrc);
		ReleaseDC(hWnd, hdc);
		break;
	case WM_KEYDOWN:
		if(wParam==VK_UP) xRot-= 5.0f;
		if(wParam==VK_DOWN) xRot += 5.0f;
		if(wParam==VK_LEFT) yRot -= 5.0f;
		if(wParam==VK_RIGHT) yRot += 5.0f;
		if (wParam == 0x41) Observer.X -= 0.1f; //A
		if (wParam == 0x44) Observer.X += 0.1f; //D
		if (wParam == 0x57) Observer.Y += 0.1f; //W
		if (wParam == 0x53) Observer.Y -= 0.1f; //S
		if (wParam == 0x51) Observer.Z -= 0.1f; //Q
		if (wParam == 0x45) Observer.Z += 0.1f; //E




		if(xRot > 356.0f) xRot = 0.0f;
		if(xRot < -1.0f) xRot = 355.0f;
		if(yRot > 356.0f) yRot = 0.0f;
		if(yRot < -1.0f) yRot = 355.0f;
		
		InvalidateRect(hWnd,NULL,FALSE);
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		DrawScene(xRot, yRot);
		SwapBuffers(hdc);
		EndPaint(hWnd, &ps);		
		break;
	case WM_ERASEBKGND:
		return 1;
		break;
	case WM_DESTROY:
		wglMakeCurrent(NULL, NULL);
		wglDeleteContext(hrc);
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX); 
	wcex.style			= CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wcex.lpfnWndProc	= (WNDPROC)WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= NULL;
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= NULL;
	wcex.lpszClassName	= "Primitives";
	wcex.hIconSm		= NULL;
	return RegisterClassEx(&wcex);
}
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;
   hWnd = CreateWindow("Primitives", "OGL color lab", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);
   if (!hWnd) return FALSE;
   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);
   return TRUE;
}
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	MSG msg;
	MyRegisterClass(hInstance);
	if (!InitInstance(hInstance, nCmdShow)) return FALSE;
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (int) msg.wParam;
}