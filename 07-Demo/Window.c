#include <windows.h>
#include <mmsystem.h> // For PlaySound()

#include "Window.h"
#pragma comment(lib, "winmm.lib")

// Global Callback Declaration
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// Entry-point Function
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR LpszCmdLine, int iCmdShow) {
    WNDCLASSEX wndclass;
    HWND hwnd;
    MSG msg;
    TCHAR szClassName[] = TEXT("MyWindow_ARM");

    ZeroMemory((void*)&wndclass, sizeof(WNDCLASSEX));

    wndclass.cbSize = sizeof(WNDCLASSEX);
    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.cbClsExtra = 0;
    wndclass.cbWndExtra = 0;
    wndclass.lpfnWndProc = WndProc;
    wndclass.lpszClassName = szClassName;
    wndclass.lpszMenuName = NULL;
    //wndclass.hbrBackground = CreateSolidBrush(RGB(71, 171, 204));
    wndclass.hbrBackground = CreateSolidBrush(RGB(135, 206, 235));
    wndclass.hInstance = hInstance;
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(ARM_ICON));
    wndclass.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(ARM_ICON));

    RegisterClassEx(&wndclass);

    hwnd = CreateWindow(szClassName, TEXT("Win 32 Birthday"), WS_OVERLAPPEDWINDOW , CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

    ShowWindow(hwnd, SW_SHOWMAXIMIZED);
    UpdateWindow(hwnd);

    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}

// Window Procedure
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM LParam) {
    static PAINTSTRUCT ps;
    static RECT rect;
    HDC hdc = NULL;
    TCHAR str[] = TEXT("Microsoft \nWindows");
    TCHAR win[] = TEXT("It’s often said that every error has its silver lining. From the familiar blue screens of Windows 3.1 to the refined alerts of Windows 11, each error message has been a stepping stone in the journey through the evolving landscape of Windows. \nAs we navigate these nostalgic glitches and graceful evolutions, we are reminded of the incredible journey Win32 has guided us through.\nIt’s with a heart full of appreciation to say : \nThank you, Win32, for being the backbone of our computing experiences and allowing developers build applications that increased the users. Your legacy has shaped our technology and made us smile. .\nHappy Birthday, and here’s to many more years of innovation and nostalgia! \nWith Due Respect by Akhilesh Ravindra Mali.\n Valudable Guidance Pradnya Gokhale Madam \nDedicated to my Guru Dr. Vijay D. Gokhale. ");
    static BOOL drawShapes = TRUE;
    static BOOL drawPop = FALSE;
    static BOOL drawThree = FALSE;
    static BOOL drawNine = FALSE;
    static BOOL drawX = FALSE;
    static BOOL drawSeven = FALSE;
    static BOOL drawEight = FALSE;
    static BOOL drawTen = FALSE;
    static BOOL drawText = FALSE;
    static BOOL closeTime = FALSE;

    TCHAR str3[255];
    
    switch (iMsg) {
    case WM_CREATE:
        ZeroMemory((void*)&rect, sizeof(RECT));
        ZeroMemory((void*)&ps, sizeof(PAINTSTRUCT));
        PlaySound(MAKEINTRESOURCE(ARM_MUSIC), GetModuleHandle(NULL), SND_ASYNC | SND_RESOURCE);
        SetTimer(hwnd, DISAPPEAR_TIMER, 5000, NULL); // Set timer to disappear shapes after 3 seconds
        break;

    case WM_PAINT:
        GetClientRect(hwnd, &rect);
        hdc = BeginPaint(hwnd, &ps);
        
        // Define brushes with different colors
        HBRUSH hBrush1 = CreateSolidBrush(RGB(0, 0, 0)); // Black
        HBRUSH hBrush2 = CreateSolidBrush(RGB(255, 0, 0)); // Red
        HBRUSH hBrush3 = CreateSolidBrush(RGB(0, 255, 0)); // Green
        HBRUSH hBrush4 = CreateSolidBrush(RGB(0, 0, 255)); // Blue
        HBRUSH hBrush5 = CreateSolidBrush(RGB(255, 255, 0)); // Yellow
        HBRUSH hGreyBrush = CreateSolidBrush(RGB(128, 128, 128)); // Grey
        HBRUSH hlGreyBrush = CreateSolidBrush(RGB(192, 192, 192)); // Grey
        HBRUSH hulGreyBrush = CreateSolidBrush(RGB(210, 210, 210)); // Grey

        HBRUSH hOldBrush;
        unsigned int x, y;
        HFONT hFont = CreateFont(
            96,            // Height of font (doubled from 48 to 96)
            0,             // Average character width (0 means use default)
            0,             // Angle of escapement
            0,             // Base-line orientation angle
            FW_NORMAL,     // Font weight
            FALSE,         // Italic
            FALSE,         // Underline
            FALSE,         // Strikeout
            ANSI_CHARSET,  // Character set identifier
            OUT_DEFAULT_PRECIS,  // Output precision
            CLIP_DEFAULT_PRECIS, // Clipping precision
            DEFAULT_QUALITY,     // Output quality
            DEFAULT_PITCH | FF_ROMAN, // Pitch and family
            TEXT("Times New Roman")); // Font name

        HFONT hFont2 = CreateFont(
            40,            // Height of font (doubled from 48 to 96)
            0,             // Average character width (0 means use default)
            0,             // Angle of escapement
            0,             // Base-line orientation angle
            FW_BOLD,     // Font weight
            FALSE,         // Italic
            FALSE,         // Underline
            FALSE,         // Strikeout
            ANSI_CHARSET,  // Character set identifier
            OUT_DEFAULT_PRECIS,  // Output precision
            CLIP_DEFAULT_PRECIS, // Clipping precision
            DEFAULT_QUALITY,     // Output quality
            DEFAULT_PITCH | FF_ROMAN, // Pitch and family
            TEXT("Times New Roman")); // Font name

        HFONT hFont8 = CreateFont(
            45,            // Height of font (doubled from 48 to 96)
            0,             // Average character width (0 means use default)
            0,             // Angle of escapement
            0,             // Base-line orientation angle
            FW_BOLD,     // Font weight
            FALSE,         // Italic
            FALSE,         // Underline
            FALSE,         // Strikeout
            ANSI_CHARSET,  // Character set identifier
            OUT_DEFAULT_PRECIS,  // Output precision
            CLIP_DEFAULT_PRECIS, // Clipping precision
            DEFAULT_QUALITY,     // Output quality
            DEFAULT_PITCH | FF_ROMAN, // Pitch and family
            TEXT("Times New Roman")); // Font name

        HFONT hOldFont = (HFONT)SelectObject(hdc, hFont);

        if (drawShapes) {

            // Draw the grey background rectangle
            hOldBrush = (HBRUSH)SelectObject(hdc, hGreyBrush);
            //Rectangle(hdc, 358, 67, 1200, 688); // Draw the grey background rectangle

            RECT bord;
            bord.left = 358;       // Direct x value
            bord.top = 67;         // Direct y value
            bord.right = 1200;     // Direct x value
            bord.bottom = 688;      // Direct y value
            FillRect(hdc, &bord, hGreyBrush);

            // Draw the larger Bézier curve shape
            hOldBrush = (HBRUSH)SelectObject(hdc, hBrush1);
            BeginPath(hdc);
            MoveToEx(hdc, 806, 133, NULL);
            //Bigger
            // Define the first Bézier curve
            PolyBezierTo(hdc, (POINT[]) {
                { 889, 80 },  // Control point 1
                { 1056, 80 }, // Control point 2
                { 1140, 133 },// End point
            }, 3);
            // Define the second Bézier curve
            PolyBezierTo(hdc, (POINT[]) {
                { 1140, 372 }, // Control point 1
                { 1140, 611 }, // Control point 2
                { 1140, 611 }, // End point
            }, 3);
            // Define the third Bézier curve
            PolyBezierTo(hdc, (POINT[]) {
                { 1056, 560 }, // Control point 1
                { 889, 560 },  // Control point 2
                { 806, 611 },  // End point
            }, 3);
            // Define the fourth Bézier curve
            PolyBezierTo(hdc, (POINT[]) {
                { 806, 372 },  // Control point 1
                { 806, 133 },  // Control point 2
                { 806, 133 },  // End point
            }, 3);
            EndPath(hdc);
            FillPath(hdc);

            //Small Rec1
            SelectObject(hdc, hBrush2);
            BeginPath(hdc);
            MoveToEx(hdc, 814, 195, NULL); // Start point adjusted

            // Define the first Bézier curve with x-coordinates shifted right by 10 units
            PolyBezierTo(hdc, (POINT[]) {
                { 841.75, 187.75 },  // Control point 1 adjusted
                { 897.25, 187.75 }, // Control point 2 adjusted
                { 925, 181 }, // End point adjusted
            }, 3);

            // Define the second Bézier curve with x-coordinates shifted right by 10 units
            PolyBezierTo(hdc, (POINT[]) {
                { 925, 256 }, // Control point 1 adjusted
                { 925, 331 }, // Control point 2 adjusted
                { 925, 331 }, // End point adjusted
            }, 3);

            // Define the third Bézier curve with x-coordinates shifted right by 10 units
            PolyBezierTo(hdc, (POINT[]) {
                { 897.25, 353.75 }, // Control point 1 adjusted
                { 841.75, 343.75 }, // Control point 2 adjusted
                { 814, 361 },  // End point adjusted
            }, 3);

            // Define the fourth Bézier curve with x-coordinates shifted right by 10 units
            PolyBezierTo(hdc, (POINT[]) {
                { 814, 284.5 },  // Control point 1 adjusted
                { 814, 195 },  // Control point 2 adjusted
                { 814, 195 },  // End point adjusted
            }, 3);

            EndPath(hdc);
            FillPath(hdc);

            //Small Rec2
            SelectObject(hdc, hBrush3);
            BeginPath(hdc);
            MoveToEx(hdc, 974, 175, NULL); // Start point adjusted

            // Define the first Bézier curve with y-coordinates shifted down by 20 units
            PolyBezierTo(hdc, (POINT[]) {
                { 1001.75, 167.75 },  // Control point 1 adjusted
                { 1057.25, 181.25 }, // Control point 2 adjusted
                { 1085, 189 }, // End point adjusted
            }, 3);

            // Define the second Bézier curve with y-coordinates shifted down by 20 units
            PolyBezierTo(hdc, (POINT[]) {
                { 1085, 236 }, // Control point 1 adjusted
                { 1085, 311 }, // Control point 2 adjusted
                { 1085, 345 }, // End point adjusted
            }, 3);

            // Define the third Bézier curve with y-coordinates shifted down by 20 units
            PolyBezierTo(hdc, (POINT[]) {
                { 1057.25, 343.75 }, // Control point 1 adjusted
                { 1001.75, 323.75 }, // Control point 2 adjusted
                { 974, 331 },  // End point adjusted
            }, 3);

            // Define the fourth Bézier curve with y-coordinates shifted down by 20 units
            PolyBezierTo(hdc, (POINT[]) {
                { 974, 264.5 },  // Control point 1 adjusted
                { 974, 175 },  // Control point 2 adjusted
                { 974, 175 },  // End point adjusted
            }, 3);

            EndPath(hdc);
            FillPath(hdc);

            //Small Rec3
            SelectObject(hdc, hBrush4);
            BeginPath(hdc);
            MoveToEx(hdc, 814, 385, NULL); // Start point adjusted

            // Define the first Bézier curve with y-coordinates shifted up by 190 units (150 + 30 + 10)
            PolyBezierTo(hdc, (POINT[]) {
                { 841.75, 376.75 },  // Control point 1 adjusted
                { 897.25, 376.75 }, // Control point 2 adjusted
                { 925, 371 }, // End point adjusted
            }, 3);

            // Define the second Bézier curve with y-coordinates shifted up by 190 units (150 + 30 + 10)
            PolyBezierTo(hdc, (POINT[]) {
                { 925, 436 }, // Control point 1 adjusted
                { 925, 511 }, // Control point 2 adjusted
                { 925, 511 }, // End point adjusted
            }, 3);

            // Define the third Bézier curve with y-coordinates shifted up by 190 units (150 + 30 + 10)
            PolyBezierTo(hdc, (POINT[]) {
                { 897.25, 523.75 }, // Control point 1 adjusted
                { 841.75, 523.75 }, // Control point 2 adjusted
                { 814, 541 },  // End point adjusted
            }, 3);

            // Define the fourth Bézier curve with y-coordinates shifted up by 190 units (150 + 30 + 10)
            PolyBezierTo(hdc, (POINT[]) {
                { 814, 464.5 },  // Control point 1 adjusted
                { 814, 385 },  // Control point 2 adjusted
                { 814, 385 },  // End point adjusted
            }, 3);

            EndPath(hdc);
            FillPath(hdc);

            //Small Rec4
            SelectObject(hdc, hBrush5);
            BeginPath(hdc);
            MoveToEx(hdc, 974, 365, NULL); // Start point adjusted

            //Change Define Point outside
            // Define the first Bézier curve with y-coordinates shifted up by 190 units (150 + 30 + 10)
            PolyBezierTo(hdc, (POINT[]) {
                { 1001.75, 370 },  // Control point 1 adjusted
                { 1057.25, 370 }, // Control point 2 adjusted
                { 1085, 379 }, // End point adjusted
            }, 3);

            // Define the second Bézier curve with y-coordinates shifted up by 190 units (150 + 30 + 10)
            PolyBezierTo(hdc, (POINT[]) {
                { 1085, 436 }, // Control point 1 adjusted
                { 1085, 511 }, // Control point 2 adjusted
                { 1085, 525 }, // End point adjusted
            }, 3);

            // Define the third Bézier curve with y-coordinates shifted up by 190 units (150 + 30 + 10)
            PolyBezierTo(hdc, (POINT[]) {
                { 1057.25, 523.75 }, // Control point 1 adjusted
                { 1001.75, 493.75 }, // Control point 2 adjusted
                { 974, 511 },  // End point adjusted
            }, 3);

            // Define the fourth Bézier curve with y-coordinates shifted up by 190 units (150 + 30 + 10)
            PolyBezierTo(hdc, (POINT[]) {
                { 974, 444.5 },  // Control point 1 adjusted
                { 974, 365 },  // Control point 2 adjusted
                { 974, 365 },  // End point adjusted
            }, 3);

            EndPath(hdc);
            FillPath(hdc);

            SelectObject(hdc, hBrush1);
            POINT rec1[4] = { {725,153},{795,133},{800,195},{730,210} };
            POINT rec2[4] = { {725, 230}, {795, 210}, {800, 272}, {730, 287} };
            POINT rec3[4] = { {725, 307}, {795, 287}, {800, 349}, {730, 364} };
            POINT rec4[4] = { {725, 384}, {795, 364}, {800, 426}, {730, 441} };
            POINT rec5[4] = { {725, 461}, {795, 441}, {800, 503}, {730, 518} };
            POINT rec6[4] = { {725, 538}, {795, 518}, {800, 580}, {730, 595} };

            Polygon(hdc, rec1, 4);
            Polygon(hdc, rec2, 4);
            Polygon(hdc, rec3, 4);
            Polygon(hdc, rec4, 4);
            Polygon(hdc, rec5, 4);
            Polygon(hdc, rec6, 4);

            POINT rec1_shifted[4] = { {635, 153}, {705, 133}, {710, 195}, {640, 210} };
            POINT rec2_shifted[4] = { {635, 230}, {705, 210}, {710, 272}, {640, 287} };
            POINT rec3_shifted[4] = { {635, 307}, {705, 287}, {710, 349}, {640, 364} };
            POINT rec4_shifted[4] = { {635, 384}, {705, 364}, {710, 426}, {640, 441} };
            POINT rec5_shifted[4] = { {635, 461}, {705, 441}, {710, 503}, {640, 518} };
            POINT rec6_shifted[4] = { {635, 538}, {705, 518}, {710, 580}, {640, 595} };

            Polygon(hdc, rec1_shifted, 4);
            Polygon(hdc, rec2_shifted, 4);
            Polygon(hdc, rec3_shifted, 4);
            Polygon(hdc, rec4_shifted, 4);
            Polygon(hdc, rec5_shifted, 4);
            Polygon(hdc, rec6_shifted, 4);

            POINT rec1_shifted_180[4] = { {545, 153}, {615, 133}, {620, 195}, {550, 210} };
            POINT rec2_shifted_180[4] = { {545, 230}, {615, 210}, {620, 272}, {550, 287} };
            POINT rec3_shifted_180[4] = { {545, 307}, {615, 287}, {620, 349}, {550, 364} };
            POINT rec4_shifted_180[4] = { {545, 384}, {615, 364}, {620, 426}, {550, 441} };
            POINT rec5_shifted_180[4] = { {545, 461}, {615, 441}, {620, 503}, {550, 518} };
            POINT rec6_shifted_180[4] = { {545, 538}, {615, 518}, {620, 580}, {550, 595} };

            Polygon(hdc, rec1_shifted_180, 4);
            Polygon(hdc, rec2_shifted_180, 4);
            Polygon(hdc, rec3_shifted_180, 4);
            Polygon(hdc, rec4_shifted_180, 4);
            Polygon(hdc, rec5_shifted_180, 4);
            Polygon(hdc, rec6_shifted_180, 4);

            POINT rec1_shortened[4] = { {485, 153}, {525, 133}, {530, 195}, {490, 210} };
            POINT rec2_shortened[4] = { {485, 230}, {525, 210}, {530, 272}, {490, 287} };
            POINT rec3_shortened[4] = { {485, 307}, {525, 287}, {530, 349}, {490, 364} };
            POINT rec4_shortened[4] = { {485, 384}, {525, 364}, {530, 426}, {490, 441} };
            POINT rec5_shortened[4] = { {485, 461}, {525, 441}, {530, 503}, {490, 518} };
            POINT rec6_shortened[4] = { {485, 538}, {525, 518}, {530, 580}, {490, 595} };

            Polygon(hdc, rec1_shortened, 4);
            Polygon(hdc, rec2_shortened, 4);
            Polygon(hdc, rec3_shortened, 4);
            Polygon(hdc, rec4_shortened, 4);
            Polygon(hdc, rec5_shortened, 4);
            Polygon(hdc, rec6_shortened, 4);

            // Define points with each x coordinate increased by 30
            POINT rec1_increased[4] = { {425, 153}, {465, 133}, {470, 195}, {430, 210} };
            POINT rec2_increased[4] = { {425, 230}, {465, 210}, {470, 272}, {430, 287} };
            POINT rec3_increased[4] = { {425, 307}, {465, 287}, {470, 349}, {430, 364} };
            POINT rec4_increased[4] = { {425, 384}, {465, 364}, {470, 426}, {430, 441} };
            POINT rec5_increased[4] = { {425, 461}, {465, 441}, {470, 503}, {430, 518} };
            POINT rec6_increased[4] = { {425, 538}, {465, 518}, {470, 580}, {430, 595} };

            // Draw polygons with updated coordinates
            Polygon(hdc, rec1_increased, 4);
            Polygon(hdc, rec2_increased, 4);
            Polygon(hdc, rec3_increased, 4);
            Polygon(hdc, rec4_increased, 4);
            Polygon(hdc, rec5_increased, 4);
            Polygon(hdc, rec6_increased, 4);


            RECT mic;
            mic.left = 576;       // Direct x value
            mic.top = 295;         // Direct y value
            mic.right = 950;     // Direct x value
            mic.bottom = 525;      // Direct y value

            HFONT tldFont = (HFONT)SelectObject(hdc, hFont);
            // Set text properties
            SetBkMode(hdc, TRANSPARENT); // Make text background transparent
            SetTextColor(hdc, RGB(255, 255, 255)); // Set text color to white
            DrawText(hdc, str, -1, &mic, DT_VCENTER | DT_CENTER | DT_WORDBREAK);
            
        }
        else if (drawPop)
        {
            // Brushes
            HBRUSH border_brush = CreateSolidBrush(RGB(255, 255, 255));
            HBRUSH title_brush = CreateSolidBrush(RGB(0, 0, 255));
            HBRUSH ntitle_brush = CreateSolidBrush(RGB(0, 0, 128));
            HBRUSH but = CreateSolidBrush(RGB(128, 128, 128));
            HBRUSH minim = CreateSolidBrush(RGB(0, 0, 0));
            HBRUSH poly = CreateSolidBrush(RGB(255, 0, 0));
            HBRUSH lRed = CreateSolidBrush(RGB(255, 91, 97));
            HBRUSH lBlue = CreateSolidBrush(RGB(135, 206, 235));
            HBRUSH eBlue = CreateSolidBrush(RGB(60, 126, 201));
            HBRUSH white_brush = CreateSolidBrush(RGB(255, 255, 255));

            // Select the white brush into the device context
            HBRUSH old_brush = (HBRUSH)SelectObject(hdc, white_brush);

            // Create a NULL pen to remove the border
            HPEN null_pen = CreatePen(PS_NULL, 1, RGB(0, 0, 0));

            // Select the NULL pen into the device context
            HPEN old_pen = (HPEN)SelectObject(hdc, null_pen);

            HFONT hFont = CreateFont(
                17,                         // Height of font
                10,                          // Width of font
                0,                          // Angle of escapement
                0,                          // Base-line orientation angle
                FW_SEMIBOLD,                   // Font weight
                FALSE,                       // Italic attribute option
                FALSE,                       // Underline attribute option
                FALSE,                       // Strikeout attribute option
                ANSI_CHARSET,                // Character set identifier
                OUT_DEFAULT_PRECIS,          // Output precision
                CLIP_DEFAULT_PRECIS,         // Clipping precision
                DEFAULT_QUALITY,             // Output quality
                DEFAULT_PITCH | FF_SWISS,    // Pitch and family
                TEXT("Times New Roman"));              // Font name

            HFONT hFont2 = CreateFont(
                25,                         // Height of font
                10,                          // Width of font
                0,                          // Angle of escapement
                0,                          // Base-line orientation angle
                FW_BOLD,                   // Font weight
                FALSE,                       // Italic attribute option
                FALSE,                       // Underline attribute option
                FALSE,                       // Strikeout attribute option
                ANSI_CHARSET,                // Character set identifier
                OUT_DEFAULT_PRECIS,          // Output precision
                CLIP_DEFAULT_PRECIS,         // Clipping precision
                DEFAULT_QUALITY,             // Output quality
                DEFAULT_PITCH | FF_SWISS,    // Pitch and family
                TEXT("Segoe"));              // Font name

            HFONT hFont3 = CreateFont(
                20,                         // Height of font
                8,                          // Width of font
                0,                          // Angle of escapement
                0,                          // Base-line orientation angle
                FW_BOLD,                   // Font weight
                FALSE,                       // Italic attribute option
                FALSE,                       // Underline attribute option 
                FALSE,                       // Strikeout attribute option
                ANSI_CHARSET,                // Character set identifier
                OUT_DEFAULT_PRECIS,          // Output precision
                CLIP_DEFAULT_PRECIS,         // Clipping precision
                DEFAULT_QUALITY,             // Output quality
                DEFAULT_PITCH | FF_SWISS,    // Pitch and family
                TEXT("Segoe"));              // Font name

            HFONT hFont4 = CreateFont(
                18,                         // Height of font
                0,                          // Width of font
                0,                          // Angle of escapement
                0,                          // Base-line orientation angle
                FW_THIN,                   // Font weight
                FALSE,                       // Italic attribute option
                FALSE,                       // Underline attribute option 
                FALSE,                       // Strikeout attribute option
                ANSI_CHARSET,                // Character set identifier
                OUT_DEFAULT_PRECIS,          // Output precision
                CLIP_DEFAULT_PRECIS,         // Clipping precision
                DEFAULT_QUALITY,             // Output quality
                DEFAULT_PITCH | FF_SWISS,    // Pitch and family
                TEXT("Arial"));              // Font name

            HFONT hFont5 = CreateFont(
                20,                         // Height of font
                0,                          // Width of font
                0,                          // Angle of escapement
                0,                          // Base-line orientation angle
                FW_BOLD,                   // Font weight
                FALSE,                       // Italic attribute option
                FALSE,                       // Underline attribute option 
                FALSE,                       // Strikeout attribute option
                ANSI_CHARSET,                // Character set identifier
                OUT_DEFAULT_PRECIS,          // Output precision
                CLIP_DEFAULT_PRECIS,         // Clipping precision
                DEFAULT_QUALITY,             // Output quality
                DEFAULT_PITCH | FF_SWISS,    // Pitch and family
                TEXT("Arial"));              // Font name

            HFONT hFont6 = CreateFont(
                60,                         // Height of font
                0,                          // Width of font
                0,                          // Angle of escapement
                0,                          // Base-line orientation angle
                FW_SEMIBOLD,                   // Font weight
                FALSE,                       // Italic attribute option
                FALSE,                       // Underline attribute option 
                FALSE,                       // Strikeout attribute option
                ANSI_CHARSET,                // Character set identifier
                OUT_DEFAULT_PRECIS,          // Output precision
                CLIP_DEFAULT_PRECIS,         // Clipping precision
                DEFAULT_QUALITY,             // Output quality
                DEFAULT_PITCH | FF_SWISS,    // Pitch and family
                TEXT("Arial"));              // Font name

            HFONT hFont7 = CreateFont(
                60,                         // Height of font
                0,                          // Width of font
                0,                          // Angle of escapement
                0,                          // Base-line orientation angle
                FW_BOLD,                   // Font weight
                FALSE,                       // Italic attribute option
                FALSE,                       // Underline attribute option 
                FALSE,                       // Strikeout attribute option
                ANSI_CHARSET,                // Character set identifier
                OUT_DEFAULT_PRECIS,          // Output precision
                CLIP_DEFAULT_PRECIS,         // Clipping precision
                DEFAULT_QUALITY,             // Output quality
                DEFAULT_PITCH | FF_SWISS,    // Pitch and family
                TEXT("Arial"));              // Font name

            //3.1
            if (drawThree) {
                // Title rectangle
                RECT title;
                title.left = 0.5;
                title.top = 15;
                title.right = 599.5;
                title.bottom = 195;
                FillRect(hdc, &title, title_brush);

                // Window rectangle
                RECT wind;
                wind.left = 4;
                wind.top = 40;
                wind.right = 594;
                wind.bottom = 190;
                FillRect(hdc, &wind, border_brush);

                // Button rectangle
                RECT butto;
                butto.left = 4;
                butto.top = 20;
                butto.right = 24;
                butto.bottom = 40;
                FillRect(hdc, &butto, but);

                // Mini rectangle
                RECT mini;
                mini.left = 8;
                mini.top = 28;
                mini.right = 20;
                mini.bottom = 32;

                // Draw the border around the mini rectangle in black
                FrameRect(hdc, &mini, minim);

                RECT ok;
                ok.left = 275;
                ok.top = 125;
                ok.right = 365;
                ok.bottom = 164;

                // Draw the border around the mini rectangle in black
                FrameRect(hdc, &ok, minim);

                RECT textRect;
                textRect.left = 92;
                textRect.top = 22;
                textRect.right = 509;
                textRect.bottom = 33;

                RECT textRect2;
                textRect2.left = 151;
                textRect2.top = 78;
                textRect2.right = 556;
                textRect2.bottom = 102;

                RECT hexa;
                hexa.left = 36;
                hexa.top = 83;
                hexa.right = 101;
                hexa.bottom = 101;

                FillRect(hdc, &ok, but);

                SelectObject(hdc, poly);
                POINT hexag[8] = { {53, 75}, {84, 75}, {101, 83}, {101,101}, {84,111},{53,111},{36,101},{36,83} };

                Polygon(hdc, hexag, 8);

                // Set the text color
                SetTextColor(hdc, RGB(255, 255, 255)); // Black color

                // Set the background mode to transparent
                SetBkMode(hdc, TRANSPARENT);

                // Select the font into the device context
                HFONT oldFont = (HFONT)SelectObject(hdc, hFont);

                // Draw the text
                DrawText(hdc, TEXT("Windows 3.1 NT Error Box"), -1, &textRect, DT_VCENTER | DT_CENTER | DT_SINGLELINE);
                DrawText(hdc, TEXT("STOP"), -1, &hexa, DT_VCENTER | DT_CENTER | DT_SINGLELINE);
                SetTextColor(hdc, RGB(0, 0, 0)); // Black color

                // Set the background mode to transparent
                SetBkMode(hdc, TRANSPARENT);

                // Select the font into the device context
                HFONT midFont = (HFONT)SelectObject(hdc, hFont2);

                DrawText(hdc, TEXT("Something went wrong. Try again."), -1, &textRect2, DT_CENTER | DT_SINGLELINE);
                DrawText(hdc, TEXT("OK"), -1, &ok, DT_VCENTER | DT_CENTER | DT_SINGLELINE);

            }


            //98
            if (drawNine) {
                // Title rectangle
                RECT ntitle;
                ntitle.left = 299.5;
                ntitle.top = 215;
                ntitle.right = 899;
                ntitle.bottom = 395;
                FillRect(hdc, &ntitle, ntitle_brush);

                // Window rectangle
                RECT nwind;
                nwind.left = 303;
                nwind.top = 240;
                nwind.right = 893;
                nwind.bottom = 390;
                FillRect(hdc, &nwind, hlGreyBrush);


                // Mini rectangle
                RECT nmini;
                nmini.left = 869;
                nmini.top = 220;
                nmini.right = 889;
                nmini.bottom = 235;
                FillRect(hdc, &nmini, but);

                //Cross

                SelectObject(hdc, minim);
                POINT nhexag[4] = { {872, 224}, {876, 222}, {885, 232}, {881,234} };
                POINT nhexag2[4] = { {881, 222}, {885, 224}, {876, 234}, {872,232} };

                Polygon(hdc, nhexag, 4);
                Polygon(hdc, nhexag2, 4);

                RECT nok;
                nok.left = 574;
                nok.top = 325;
                nok.right = 664;
                nok.bottom = 364;

                // Draw the border around the mini rectangle in black
                FrameRect(hdc, &nok, minim);

                RECT ntextRect;
                ntextRect.left = 300;
                ntextRect.top = 218;
                ntextRect.right = 808;
                ntextRect.bottom = 238;

                RECT ntextRect2;
                ntextRect2.left = 450;
                ntextRect2.top = 278;
                ntextRect2.right = 855;
                ntextRect2.bottom = 302;


                //Circle
                SelectObject(hdc, poly);
                Ellipse(hdc, 352, 271, 417, 328);


                //Cross
               /* SelectObject(hdc, border_brush);
                POINT ncirc[4] = { {366, 286}, {374, 281}, {405, 312}, {395,320} };
                POINT ncirc2[4] = { {395, 281}, {405, 286}, {374, 320}, {366,312} };
                Polygon(hdc, ncirc, 4);
                Polygon(hdc, ncirc2, 4);
                */

                RECT nxtextRect;
                nxtextRect.left = 352;
                nxtextRect.top = 271;
                nxtextRect.right = 417;
                nxtextRect.bottom = 328;

                FillRect(hdc, &nok, but);

                // Set the text color
                SetTextColor(hdc, RGB(255, 255, 255)); // Black color

                // Set the background mode to transparent
                SetBkMode(hdc, TRANSPARENT);

                // Select the font into the device context
                HFONT noldFont = (HFONT)SelectObject(hdc, hFont);

                // Draw the text
                DrawText(hdc, TEXT("Windows 98 Error Box"), -1, &ntextRect, DT_LEFT | DT_SINGLELINE);
                SetTextColor(hdc, RGB(0, 0, 0)); // Black color

                // Set the background mode to transparent
                SetBkMode(hdc, TRANSPARENT);

                // Select the font into the device context
                HFONT nmidFont = (HFONT)SelectObject(hdc, hFont2);

                DrawText(hdc, TEXT("Illegal Operation Performed"), -1, &ntextRect2, DT_CENTER | DT_SINGLELINE);
                DrawText(hdc, TEXT("OK"), -1, &nok, DT_VCENTER | DT_CENTER | DT_SINGLELINE);

                SetTextColor(hdc, RGB(255, 255, 255)); // Black color
                HFONT nxFont = (HFONT)SelectObject(hdc, hFont7);
                DrawText(hdc, TEXT("X"), -1, &nxtextRect, DT_VCENTER | DT_CENTER | DT_SINGLELINE);
            }

            //XP
            if (drawX)
            {
                SelectObject(hdc, title_brush);
                BeginPath(hdc);
                MoveToEx(hdc, 598.5, 440, NULL); // Start point adjusted
                // Define the first Bézier curve with y-coordinates shifted up by 190 units (150 + 30 + 10)
                PolyBezierTo(hdc, (POINT[]) {
                    { 600.5, 437 },  // Control point 1 adjusted
                    { 599, 418 }, // Control point 2 adjusted
                    { 601.5, 415 }, // End point adjusted
                }, 3);

                // Define the second Bézier curve with y-coordinates shifted up by 190 units (150 + 30 + 10)
                PolyBezierTo(hdc, (POINT[]) {
                    { 749.85, 415 }, // Control point 1 adjusted
                    { 1046.625, 415 }, // Control point 2 adjusted
                    { 1195, 415 }, // End point adjusted
                }, 3);

                // Define the third Bézier curve with y-coordinates shifted up by 190 units (150 + 30 + 10)
                PolyBezierTo(hdc, (POINT[]) {
                    { 1196, 420 }, // Control point 1 adjusted
                    { 1197, 435 }, // Control point 2 adjusted
                    { 1198, 440 },  // End point adjusted
                }, 3);

                // Define the fourth Bézier curve with y-coordinates shifted up by 190 units (150 + 30 + 10)
                PolyBezierTo(hdc, (POINT[]) {
                    { 1198, 517.5 },  // Control point 1 adjusted
                    { 1198, 595 },  // Control point 2 adjusted
                    { 1198, 595 },  // End point adjusted
                }, 3);

                PolyBezierTo(hdc, (POINT[]) {
                    { 749.85, 595 },  // Control point 1 adjusted
                    { 1046.625, 595 },  // Control point 2 adjusted
                    { 598.5, 595 },  // End point adjusted
                }, 3);

                PolyBezierTo(hdc, (POINT[]) {
                    { 598.5, 517.5 },  // Control point 1 adjusted
                    { 598.5, 440 },  // Control point 2 adjusted
                    { 598.5, 440 },  // End point adjusted
                }, 3);
                EndPath(hdc);
                FillPath(hdc);


                // Window rectangle
                RECT xwind;
                xwind.left = 602;
                xwind.top = 440;
                xwind.right = 1192;
                xwind.bottom = 590;
                FillRect(hdc, &xwind, hlGreyBrush);


                // Mini rectangle
                RECT xmini;
                xmini.left = 1168;
                xmini.top = 420;
                xmini.right = 1188;
                xmini.bottom = 435;
                FillRect(hdc, &xmini, lRed);

                //Cross


                SelectObject(hdc, border_brush);
                POINT xhexag[4] = { {1171, 424}, {1175, 422}, {1184, 432}, {1180, 434} };
                POINT xhexag2[4] = { {1180, 422}, {1184, 424}, {1175, 434}, {1171, 432} };

                Polygon(hdc, xhexag, 4);
                Polygon(hdc, xhexag2, 4);

                RECT xok;
                xok.left = 873;
                xok.top = 525;
                xok.right = 963;
                xok.bottom = 564;

                // Draw the border around the mini rectangle in black
                FrameRect(hdc, &xok, minim);

                RECT xtextRect;
                xtextRect.left = 599;
                xtextRect.top = 418;
                xtextRect.right = 1107;
                xtextRect.bottom = 438;

                RECT xtextRect2;
                xtextRect2.left = 749;
                xtextRect2.top = 478;
                xtextRect2.right = 1154;
                xtextRect2.bottom = 502;


                //Circle
                SelectObject(hdc, poly);
                Ellipse(hdc, 651, 471, 716, 528);

                //Cross

                SelectObject(hdc, border_brush);
                POINT xcirc[4] = { {665, 486}, {673, 481}, {704, 512}, {694, 520} };
                POINT xcirc2[4] = { {694, 481}, {704, 486}, {673, 520}, {665, 512} };
                Polygon(hdc, xcirc, 4);
                Polygon(hdc, xcirc2, 4);

                FrameRect(hdc, &xok, minim);

                // Set the text color
                SetTextColor(hdc, RGB(255, 255, 255)); // Black color

                // Set the background mode to transparent
                SetBkMode(hdc, TRANSPARENT);

                // Select the font into the device context
                HFONT xoldFont = (HFONT)SelectObject(hdc, hFont);

                // Draw the text
                DrawText(hdc, TEXT("Windows XP Error Box"), -1, &xtextRect, DT_LEFT | DT_SINGLELINE);
                SetTextColor(hdc, RGB(0, 0, 0)); // Black color

                // Set the background mode to transparent
                SetBkMode(hdc, TRANSPARENT);

                // Select the font into the device context
                HFONT xmidFont = (HFONT)SelectObject(hdc, hFont3);

                DrawText(hdc, TEXT("C:/WINDOW.EXE is not a valid Win32 application"), -1, &xtextRect2, DT_CENTER | DT_SINGLELINE);
                DrawText(hdc, TEXT("OK"), -1, &xok, DT_VCENTER | DT_CENTER | DT_SINGLELINE);
            }
            //7 *********
            if (drawSeven)
            {
                // Draw the path with a black border
                SelectObject(hdc, GetStockObject(BLACK_PEN)); // Select black pen for border
                BeginPath(hdc);
                MoveToEx(hdc, 897.5, 640, NULL); // Start point

                // Define the Bézier curves
                PolyBezierTo(hdc, (POINT[]) {
                    { 899.5, 637 },  // Control point 1
                    { 898, 618 },    // Control point 2
                    { 900.5, 615 },  // End point
                }, 3);

                PolyBezierTo(hdc, (POINT[]) {
                    { 1049.85, 615 },      // Control point 1
                    { 1345.625, 615 },     // Control point 2
                    { 1494, 615 },         // End point
                }, 3);

                PolyBezierTo(hdc, (POINT[]) {
                    { 1495, 620 },        // Control point 1
                    { 1496, 635 },        // Control point 2
                    { 1497, 640 },        // End point
                }, 3);

                PolyBezierTo(hdc, (POINT[]) {
                    { 1497, 717.5 },      // Control point 1
                    { 1497, 795 },        // Control point 2
                    { 1497, 795 },        // End point
                }, 3);

                PolyBezierTo(hdc, (POINT[]) {
                    { 1049.85, 795 },      // Control point 1
                    { 1345.625, 795 },     // Control point 2
                    { 897.5, 795 },        // End point
                }, 3);

                PolyBezierTo(hdc, (POINT[]) {
                    { 897.5, 717.5 },      // Control point 1
                    { 897.5, 640 },        // Control point 2
                    { 897.5, 640 },        // End point
                }, 3);

                EndPath(hdc);
                StrokePath(hdc); // Draw the path with the black pen (border
                SelectObject(hdc, NULL); // Select black pen for border

                // Window rectangle
                // Fill a large rectangle with a light gray brush
                RECT swind;
                swind.left = 901;       // 602 + 299
                swind.top = 640;        // 440 + 200
                swind.right = 1491;     // 1192 + 299
                swind.bottom = 790;     // 590 + 200
                FillRect(hdc, &swind, border_brush);

                RECT sback;
                sback.left = 901;       // 602 + 299
                sback.top = 738;        // 440 + 200
                sback.right = 1491;     // 1192 + 299
                sback.bottom = 790;     // 590 + 200
                FillRect(hdc, &sback, hulGreyBrush);

                // Fill a small rectangle with a red brush
                RECT smini;
                smini.left = 1467;      // 1168 + 299
                smini.top = 615;        // 420 + 200
                smini.right = 1491;     // 1188 + 299
                smini.bottom = 635;     // 435 + 200
                FillRect(hdc, &smini, lRed);

                // Draw a cross using two overlapping polygons
                SelectObject(hdc, border_brush);
                POINT shexag[4] = { {1470, 624}, {1474, 622}, {1483, 632}, {1479, 634} };
                POINT shexag2[4] = { {1479, 622}, {1483, 624}, {1474, 634}, {1470, 632} };
                Polygon(hdc, shexag, 4);
                Polygon(hdc, shexag2, 4);

                // Draw a border around a rectangle
                RECT sok;
                sok.left = 1372;        // 873 + 299
                sok.top = 749;         // 525 + 200
                sok.right = 1462;       // 963 + 299
                sok.bottom = 780;       // 564 + 200
                FrameRect(hdc, &sok, lBlue);

                int borderThickness = 3; // Adjust thickness as needed

                // Draw multiple rectangles to create a thicker border
                for (int i = 0; i < borderThickness; ++i) {
                    // Adjust the rectangle's size
                    RECT outerRect = sok;
                    outerRect.left -= 1;
                    outerRect.top -= 1;
                    outerRect.right += 1;
                    outerRect.bottom += 1;

                    // Draw the border rectangle
                    FrameRect(hdc, &outerRect, lBlue);

                    // Move to the next rectangle
                    sok = outerRect;
                }

                // Define text rectangles (text drawing not shown here)
                RECT stextRect;
                stextRect.left = 898;   // 599 + 299
                stextRect.top = 618;    // 418 + 200
                stextRect.right = 1406; // 1107 + 299
                stextRect.bottom = 638; // 438 + 200

                RECT stextRect2;
                stextRect2.left = 1048; // 749 + 299
                stextRect2.top = 678;   // 478 + 200
                stextRect2.right = 1453; // 1154 + 299
                stextRect2.bottom = 702; // 502 + 200

                //White Circle Border
                SelectObject(hdc, border_brush);
                Ellipse(hdc, 945, 666, 1020, 733); // Adjusted ellipse coordinates

                // Draw a circle
                SelectObject(hdc, poly);
                Ellipse(hdc, 950, 671, 1015, 728); // Adjusted ellipse coordinates

                // Draw a cross inside the circle
                SelectObject(hdc, border_brush);
                POINT scirc[4] = { {964, 686}, {972, 681}, {1003, 712}, {993, 720} };
                POINT scirc2[4] = { {993, 681}, {1003, 686}, {972, 720}, {964, 712} };
                Polygon(hdc, scirc, 4);
                Polygon(hdc, scirc2, 4);

                // Set the text color
                SetTextColor(hdc, RGB(0, 0, 0)); // Black color

                // Set the background mode to transparent
                SetBkMode(hdc, TRANSPARENT);

                // Select the font into the device context
                HFONT soldFont = (HFONT)SelectObject(hdc, hFont4);

                // Draw the text
                DrawText(hdc, TEXT("Windows 7 Error Box"), -1, &stextRect, DT_LEFT | DT_SINGLELINE);
                SetTextColor(hdc, RGB(0, 0, 0)); // Black color

                // Set the background mode to transparent
                SetBkMode(hdc, TRANSPARENT);

                // Select the font into the device context
               // HFONT smidFont = (HFONT)SelectObject(hdc, hFont4);

                DrawText(hdc, TEXT("C:/WINDOW.EXE is not a valid Win32 application"), -1, &stextRect2, DT_CENTER | DT_SINGLELINE);
                DrawText(hdc, TEXT("OK"), -1, &sok, DT_VCENTER | DT_CENTER | DT_SINGLELINE);

            }
            //8 *********
            if (drawEight)
            {
                // Draw the path with a black border
                BeginPath(hdc);
                MoveToEx(hdc, 917.5, 165, NULL); // Adjusted start point

                // Define the Bézier curves
                PolyBezierTo(hdc, (POINT[]) {
                    { 919.5, 162 },  // Adjusted Control point 1
                    { 918, 143 },    // Adjusted Control point 2
                    { 920.5, 140 },  // Adjusted End point
                }, 3);

                PolyBezierTo(hdc, (POINT[]) {
                    { 1069.85, 140 },      // Adjusted Control point 1
                    { 1365.625, 140 },     // Adjusted Control point 2
                    { 1514, 140 },         // Adjusted End point
                }, 3);

                PolyBezierTo(hdc, (POINT[]) {
                    { 1515, 145 },        // Adjusted Control point 1
                    { 1516, 160 },        // Adjusted Control point 2
                    { 1517, 165 },        // Adjusted End point
                }, 3);

                PolyBezierTo(hdc, (POINT[]) {
                    { 1517, 242.5 },      // Adjusted Control point 1
                    { 1517, 320 },        // Adjusted Control point 2
                    { 1517, 320 },        // Adjusted End point
                }, 3);

                PolyBezierTo(hdc, (POINT[]) {
                    { 1069.85, 320 },      // Adjusted Control point 1
                    { 1365.625, 320 },     // Adjusted Control point 2
                    { 917.5, 320 },        // Adjusted End point
                }, 3);

                PolyBezierTo(hdc, (POINT[]) {
                    { 917.5, 242.5 },      // Adjusted Control point 1
                    { 917.5, 165 },        // Adjusted Control point 2
                    { 917.5, 165 },        // Adjusted End point
                }, 3);

                EndPath(hdc);
                SelectObject(hdc, eBlue); // Select black pen for border
                // Fill the path
                FillPath(hdc);

                // Window rectangle
                // Fill a large rectangle with a light gray brush
                RECT ewind;
                ewind.left = 921;       // Adjusted left
                ewind.top = 165;        // Adjusted top
                ewind.right = 1511;     // Adjusted right
                ewind.bottom = 315;     // Adjusted bottom
                FillRect(hdc, &ewind, border_brush);

                RECT eback;
                eback.left = 921;       // Adjusted left
                eback.top = 263;        // Adjusted top
                eback.right = 1511;     // Adjusted right
                eback.bottom = 315;     // Adjusted bottom
                FillRect(hdc, &eback, hulGreyBrush);

                // Fill a small rectangle with a red brush
                RECT emini;
                emini.left = 1487;      // Adjusted left
                emini.top = 140;        // Adjusted top
                emini.right = 1511;     // Adjusted right
                emini.bottom = 160;     // Adjusted bottom
                FillRect(hdc, &emini, lRed);

                // Draw a cross using two overlapping polygons
                SelectObject(hdc, border_brush);
                POINT ehexag[4] = { {1490, 149}, {1494, 147}, {1503, 157}, {1499, 159} }; // Adjusted coordinates
                POINT ehexag2[4] = { {1499, 147}, {1503, 149}, {1494, 159}, {1490, 157} }; // Adjusted coordinates
                Polygon(hdc, ehexag, 4);
                Polygon(hdc, ehexag2, 4);


                // Draw a border around a rectangle
                RECT eok;
                eok.left = 1392;        // Adjusted left
                eok.top = 274;         // Adjusted top
                eok.right = 1482;       // Adjusted right
                eok.bottom = 305;       // Adjusted bottom
                FrameRect(hdc, &eok, lBlue);

                int eborderThickness = 3; // Adjust thickness as needed

                // Draw multiple rectangles to create a thicker border
                for (int i = 0; i < eborderThickness; ++i) {
                    // Adjust the rectangle's size
                    RECT outerRect = eok;
                    outerRect.left -= 1;
                    outerRect.top -= 1;
                    outerRect.right += 1;
                    outerRect.bottom += 1;

                    // Draw the border rectangle
                    FrameRect(hdc, &outerRect, lBlue);

                    // Move to the next rectangle
                    eok = outerRect;
                }

                // Define text rectangles (text drawing not shown here)
                RECT etextRect;
                etextRect.left = 918;   // Adjusted left
                etextRect.top = 143;    // Adjusted top
                etextRect.right = 1426; // Adjusted right
                etextRect.bottom = 163; // Adjusted bottom

                RECT etextRect2;
                etextRect2.left = 1068; // Adjusted left
                etextRect2.top = 203;   // Adjusted top
                etextRect2.right = 1473; // Adjusted right
                etextRect2.bottom = 227; // Adjusted bottom

                // White Circle Border
                SelectObject(hdc, border_brush);
                Ellipse(hdc, 965, 191, 1040, 258); // Adjusted ellipse coordinates

                // Draw a circle
                SelectObject(hdc, poly);
                Ellipse(hdc, 970, 196, 1035, 253); // Adjusted ellipse coordinates

                // Draw a cross inside the circle
                SelectObject(hdc, border_brush);
                POINT ecirc[4] = { {984, 211}, {992, 206}, {1023, 237}, {1013, 245} };
                POINT ecirc2[4] = { {1013, 206}, {1023, 211}, {992, 245}, {984, 237} };
                Polygon(hdc, ecirc, 4);
                Polygon(hdc, ecirc2, 4);

                // Set the text color
                SetTextColor(hdc, RGB(0, 0, 0)); // Black color

                // Set the background mode to transparent
                SetBkMode(hdc, TRANSPARENT);

                // Select the font into the device context
                HFONT eoldFont = (HFONT)SelectObject(hdc, hFont4);

                // Draw the text
                DrawText(hdc, TEXT("Windows 8 Error Box"), -1, &etextRect, DT_LEFT | DT_SINGLELINE);
                SetTextColor(hdc, RGB(0, 0, 0)); // Black color

                // Set the background mode to transparent
                SetBkMode(hdc, TRANSPARENT);

                // Draw the text
                DrawText(hdc, TEXT("C:/WINDOW.EXE is not a valid Win32 application"), -1, &etextRect2, DT_CENTER | DT_SINGLELINE);
                DrawText(hdc, TEXT("OK"), -1, &eok, DT_VCENTER | DT_CENTER | DT_SINGLELINE);
            }
            if (drawTen)
            {

                //10 *********
                // Define and draw the main window rectangle
                RECT towind;
                towind.left = 4;             // 897.5 - 890
                towind.top = 605;              // 440 + 200
                towind.right = 610;            // 1497 - 890
                towind.bottom = 795;           // 590 + 200
                FillRect(hdc, &towind, border_brush);

                // Define and draw the secondary window rectangle
                RECT twind;
                twind.left = 4;               // 901 - 890
                twind.top = 735;               // 440 + 200
                twind.right = 610;             // 1491 - 890
                twind.bottom = 795;            // 590 + 200
                FillRect(hdc, &twind, hulGreyBrush);

                //X
                RECT txtextRect;
                txtextRect.left = 579;             // 898 - 890
                txtextRect.top = 607;            // 418 + 200
                txtextRect.right = 607;          // 1406 - 890
                txtextRect.bottom = 625;         // 438 + 200

                // Define and draw the border rectangle
                RECT tok;
                tok.left = 470;                // 1372 - 890
                tok.top = 749;                 // 525 + 200
                tok.right = 560;               // 1462 - 890
                tok.bottom = 780;              // 564 + 200
                FrameRect(hdc, &tok, title_brush);

                // Draw multiple rectangles to create a thicker border
                int tborderThickness = 2; // Adjust thickness as needed
                for (int i = 0; i < tborderThickness; ++i) {
                    // Adjust the rectangle's size
                    RECT outerRect = tok;
                    outerRect.left -= 1;
                    outerRect.top -= 1;
                    outerRect.right += 1;
                    outerRect.bottom += 1;

                    // Draw the border rectangle
                    FrameRect(hdc, &outerRect, title_brush);

                    // Move to the next rectangle
                    tok = outerRect;
                }

                // Define and draw text rectangles
                RECT ttextRect;
                ttextRect.left = 8;             // 898 - 890
                ttextRect.top = 618;            // 418 + 200
                ttextRect.right = 516;          // 1406 - 890
                ttextRect.bottom = 638;         // 438 + 200

                RECT ttextRect2;
                ttextRect2.left = 158;          // 1048 - 890
                ttextRect2.top = 678;           // 478 + 200
                ttextRect2.right = 563;         // 1453 - 890
                ttextRect2.bottom = 702;        // 502 + 200

                RECT txtextRect2;
                txtextRect2.left = 60;          // 1048 - 890
                txtextRect2.top = 671;           // 478 + 200
                txtextRect2.right = 125;         // 1453 - 890
                txtextRect2.bottom = 728;        // 502 + 200

                // Draw the inner circle
                SelectObject(hdc, poly);
                Ellipse(hdc, 60, 671, 125, 728); // Adjusted ellipse coordinates

                /*// Draw a cross inside the circle
                SelectObject(hdc, border_brush);
                POINT tcirc[4] = { {74, 686}, {82, 681}, {113, 712}, {103, 720} };
                POINT tcirc2[4] = { {103, 681}, {113, 686}, {82, 720}, {74, 712} };
                Polygon(hdc, tcirc, 4);
                Polygon(hdc, tcirc2, 4);
                */
                // Set the text color
                SetTextColor(hdc, RGB(0, 0, 0)); // Black color

                // Set the background mode to transparent
                SetBkMode(hdc, TRANSPARENT);

                // Select the font into the device context
                HFONT toldFont = (HFONT)SelectObject(hdc, hFont4);

                // Draw the text
                DrawText(hdc, TEXT("Windows 10 Error Box"), -1, &ttextRect, DT_LEFT | DT_SINGLELINE);
                SetTextColor(hdc, RGB(0, 0, 0)); // Black color

                // Set the background mode to transparent
                SetBkMode(hdc, TRANSPARENT);

                // Draw additional text
                DrawText(hdc, TEXT("C:/WINDOW.EXE is not a valid Win32 application"), -1, &ttextRect2, DT_CENTER | DT_SINGLELINE);
                DrawText(hdc, TEXT("OK"), -1, &tok, DT_VCENTER | DT_CENTER | DT_SINGLELINE);

                HFONT txoldFont = (HFONT)SelectObject(hdc, hFont5);
                DrawText(hdc, TEXT("X"), -1, &txtextRect, DT_VCENTER | DT_CENTER | DT_SINGLELINE);

                SetTextColor(hdc, RGB(255, 255, 255)); // Black color
                HFONT txoldFont2 = (HFONT)SelectObject(hdc, hFont6);
                DrawText(hdc, TEXT("X"), -1, &txtextRect2, DT_VCENTER | DT_CENTER | DT_SINGLELINE);
            }
            
            // Clean up
            //SelectObject(hdc, oldFont);
            DeleteObject(hFont);
            DeleteObject(minim);
}
        else if (drawText) {
            /*RECT txtextRect;
            txtextRect.left = 525;             // 898 - 890
            txtextRect.top = 267;            // 418 + 200
            txtextRect.right = 1000;          // 1406 - 890
            txtextRect.bottom = 605;         // 438 + 200
            */
            HBRUSH border_brush = CreateSolidBrush(RGB(255, 255, 255));
            HBRUSH title_brush = CreateSolidBrush(RGB(0, 0, 255));
            HBRUSH but = CreateSolidBrush(RGB(128, 128, 128));

            RECT xtitle;
            xtitle.left = 100.5;
            xtitle.top = 65;
            xtitle.right = 1460; //699
            xtitle.bottom = 770; //405
            FillRect(hdc, &xtitle, title_brush);

            // Window rectangle
            RECT xwind;
            xwind.left = 104;
            xwind.top = 90;
            xwind.right = 1450; //694
            xwind.bottom = 760; //400

            FillRect(hdc, &xwind, border_brush);

            // Button rectangle
            RECT xbutto;
            xbutto.left = 100.5;
            xbutto.top = 65;
            xbutto.right = 124;
            xbutto.bottom = 90;
            FillRect(hdc, &xbutto, but);
            
            SetTextColor(hdc, RGB(0, 0, 0)); // Black color

            // Set the background mode to transparent
            SetBkMode(hdc, TRANSPARENT);

            // Select the font into the device context
            HFONT tldFont = (HFONT)SelectObject(hdc, hFont8);

            // Draw the text
            DrawText(hdc, TEXT("-"), -1, &xbutto, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

            // Set the text color
            SetTextColor(hdc, RGB(0, 0, 0)); // Black color

            // Set the background mode to transparent
            SetBkMode(hdc, TRANSPARENT);

            // Draw the text
            DrawText(hdc,win, -1, &xwind, DT_CENTER | DT_VCENTER | DT_WORDBREAK);
        }
        else if (closeTime) {
            SelectObject(hdc, hBrush1);
            //Fill our client area of our rectangle with the color of our selected brush
            FillRect(hdc, &rect, hBrush1);
        }
        
        // Restore the old font and clean up
        SelectObject(hdc, hOldFont);
        DeleteObject(hFont);

        // Clean up
        SelectObject(hdc, hOldBrush);
        DeleteObject(hBrush1);
        DeleteObject(hBrush2);
        DeleteObject(hBrush3);
        DeleteObject(hBrush4);
        DeleteObject(hBrush5);
        DeleteObject(hGreyBrush);
        EndPaint(hwnd, &ps);
        break;


    case WM_TIMER:
        if (wParam == DISAPPEAR_TIMER) {
            drawShapes = FALSE; // Hide the shapes after 3 seconds
            InvalidateRect(hwnd, NULL, TRUE); // Trigger repaint
            KillTimer(hwnd, DISAPPEAR_TIMER); // Stop the timer after it has triggered once
            SetTimer(hwnd, POP_TIMER, 15000, NULL);   
            SetTimer(hwnd, THREE_TIMER, 1000, NULL);
            drawPop = TRUE;
            drawThree = TRUE;
        }
        else if (wParam == THREE_TIMER)
        {
            //drawThree = FALSE;
            InvalidateRect(hwnd, NULL, TRUE);
            KillTimer(hwnd, THREE_TIMER);
            SetTimer(hwnd, NINE_TIMER, 1000, NULL);
            drawNine = TRUE;
        }
        else if (wParam == NINE_TIMER)
        {
            //drawNine = FALSE;
            InvalidateRect(hwnd, NULL, TRUE);
            KillTimer(hwnd, NINE_TIMER);
            SetTimer(hwnd, X_TIMER, 1000, NULL);
            drawX = TRUE;
        }
        else if (wParam == X_TIMER)
        {
            //drawX = FALSE;
            InvalidateRect(hwnd, NULL, TRUE);
            KillTimer(hwnd, X_TIMER);
            SetTimer(hwnd, SEVEN_TIMER, 1000, NULL);
            drawSeven = TRUE;
        }
        else if (wParam == SEVEN_TIMER)
        {
            //drawSeven = FALSE;
            InvalidateRect(hwnd, NULL, TRUE);
            KillTimer(hwnd, SEVEN_TIMER);
            SetTimer(hwnd, EIGHT_TIMER, 1000, NULL);
            drawEight = TRUE;
        }
        else if (wParam == EIGHT_TIMER)
        {
            //drawEight = FALSE;
            InvalidateRect(hwnd, NULL, TRUE);
            KillTimer(hwnd, TEN_TIMER);
            SetTimer(hwnd, TEN_TIMER, 3000, NULL);
            drawTen = TRUE;
        }
        else if (wParam == TEN_TIMER)
        {
            //drawTen = FALSE;
            InvalidateRect(hwnd, NULL, TRUE);
            KillTimer(hwnd, TEN_TIMER);
            
         }
        else if (wParam == POP_TIMER) {
            drawPop = FALSE;
            InvalidateRect(hwnd, NULL, TRUE); // Trigger repaint
            KillTimer(hwnd, POP_TIMER); // Stop the timer after it has triggered 
            SetTimer(hwnd, TEXT_TIMER, 36400, NULL);
            drawText = TRUE;
        }
        else if (wParam == TEXT_TIMER)
        {
            drawText = FALSE;
            KillTimer(hwnd, TEXT_TIMER); // Stop the timer after it has triggered 
            SetTimer(hwnd, CLOSE_TIMER, 10000, NULL);
            closeTime = TRUE;
        }
        
        break;

    case WM_LBUTTONDOWN:
        wsprintf(str, TEXT("Windows 11 Error"));
        MessageBox(NULL, str, TEXT("MESSAGE"), MB_ICONERROR);   
        break;

    case WM_DESTROY:
        PlaySound(NULL, 0, 0);
        PostQuitMessage(0);
        break;

    default:
        break;
    }
    //Calling default Window Procedure
    return DefWindowProc(hwnd, iMsg, wParam, LParam);
}

