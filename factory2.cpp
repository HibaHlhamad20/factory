#include <windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <math.h>


#include "Camera.h"
#include "Texture.h"
#include "Point.h"
#include "Cuboid.h"
#include "Showroom.h"
#include "Door.h"

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")


HDC hDC;
HGLRC hRC;
Camera myCamera;
Texture skyTex;
Showroom* myShowroom;
Door* myDoor;
const float SKY_LIMIT = 50000.0f;

void initOpenGL(HWND hWnd) {
    PIXELFORMATDESCRIPTOR pfd = { sizeof(PIXELFORMATDESCRIPTOR), 1, PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER, PFD_TYPE_RGBA, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 24, 8, 0, PFD_MAIN_PLANE, 0, 0, 0, 0 };
    hDC = GetDC(hWnd);
    int pf = ChoosePixelFormat(hDC, &pfd);
    SetPixelFormat(hDC, pf, &pfd);
    hRC = wglCreateContext(hDC);
    wglMakeCurrent(hDC, hRC);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);

    skyTex.load("assets/skyy.png");

  
    myShowroom = new Showroom(6000.0f, 1500.0f, 6000.0f);
    myDoor = new Door(1500.0f * 0.7f, 3000.0f); // «·»«» ›Ì «·Ê«ÃÂ… «·√„«„Ì…

    myCamera.x = 0; myCamera.y = 150; myCamera.z = 5000.0f;
}

void render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    myCamera.render();

    // ≈÷«¡… »”Ìÿ… ··„‘Âœ
    GLfloat lightPos[] = { 0.0f, 1400.0f, 0.0f, 1.0f };
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

    // 1. «·”ﬂ«Ì »Êﬂ” )
    glDisable(GL_LIGHTING);
    skyTex.use();
    glColor3f(1, 1, 1);
    Cuboid sky(Point(0, 0, 0), SKY_LIMIT * 2, SKY_LIMIT * 2, SKY_LIMIT * 2);
    sky.draw();
    glEnable(GL_LIGHTING);

    // 2. «·„⁄—÷ )
    myShowroom->draw();

    // 3. «·»«»)
    myDoor->update(myCamera.x, myCamera.z);
    myDoor->draw();

    SwapBuffers(hDC);
}
//ÂÊ‰ ⁄‰œÌ „œÏ «·—ƒÌ…
void reshape(int w, int h) {
    if (h == 0) h = 1;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)w / h, 1.0, 150000.0); // „œÏ —ƒÌ… »⁄Ìœ Ãœ« ··”„«¡
    glMatrixMode(GL_MODELVIEW);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
    static int lastMouseX, lastMouseY;
    switch (msg) {
    case WM_CREATE: initOpenGL(hWnd); ShowCursor(FALSE); break;
    case WM_MOUSEMOVE: {
        int xPos = LOWORD(lp); int yPos = HIWORD(lp);
        myCamera.updateLookAt((float)xPos - lastMouseX, (float)yPos - lastMouseY);
        RECT rect; GetClientRect(hWnd, &rect);
        POINT pt = { (rect.right - rect.left) / 2, (rect.bottom - rect.top) / 2 };
        ClientToScreen(hWnd, &pt); SetCursorPos(pt.x, pt.y);
        lastMouseX = (rect.right - rect.left) / 2; lastMouseY = (rect.bottom - rect.top) / 2;
    } break;
    case WM_KEYDOWN: {
        float speed = 80.0f;
        if (wp == 'W' || wp == VK_UP) myCamera.moveForward(speed, SKY_LIMIT, SKY_LIMIT);
        if (wp == 'S' || wp == VK_DOWN) myCamera.moveForward(-speed, SKY_LIMIT, SKY_LIMIT);
        if (wp == 'A') myCamera.moveSide(-speed, SKY_LIMIT, SKY_LIMIT);
        if (wp == 'D') myCamera.moveSide(speed, SKY_LIMIT, SKY_LIMIT);
        if (wp == VK_ESCAPE) PostQuitMessage(0);
    } break;
    case WM_SIZE: reshape(LOWORD(lp), HIWORD(lp)); break;
    case WM_DESTROY:
        delete myShowroom;
        delete myDoor;
        PostQuitMessage(0);
        break;
    default: return DefWindowProc(hWnd, msg, wp, lp);
    }
    return 0;
}

int APIENTRY wWinMain(HINSTANCE hI, HINSTANCE hP, LPWSTR lp, int nC) {
    WNDCLASSEXW wcex = { sizeof(WNDCLASSEX), CS_HREDRAW | CS_VREDRAW, WndProc, 0, 0, hI, NULL, LoadCursor(nullptr, IDC_ARROW), NULL, NULL, L"ShowroomClass", NULL };
    RegisterClassExW(&wcex);
    HWND hWnd = CreateWindowW(L"ShowroomClass", L"CAR SHOWROOM - OOP MEGA SCALE", WS_OVERLAPPEDWINDOW, 0, 0, 1280, 720, nullptr, nullptr, hI, nullptr);
    ShowWindow(hWnd, nC);
    MSG msg;
    while (true) {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_QUIT) break;
            TranslateMessage(&msg); DispatchMessage(&msg);
        }
        else render();
    }
    return (int)msg.wParam;
}
