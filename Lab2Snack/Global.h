
#pragma once
#include "C:\Users\DELL\Desktop\Lab2Snack\Dependencies\SDL\SDL.h"
#include"Global.h"
#include <stdlib.h>
#include <time.h>


#define BOARD_CELL 16 /* kích thước của 1 ô, nên là lũy thừa của 2 */
#define BOARD_HORZ 48 /* số lượng ô theo chiều ngang */
#define BOARD_VERT 30 /* số lượng ô theo chiều dọc */
/* 18 màu sắc có thể sử dụng được trong trò chơi */
#define CR_BLACK 0
#define CR_BLUE 1
#define CR_GREEN 2
#define CR_CYAN 3
#define CR_RED 4
#define CR_MAGENTA 5
#define CR_BROWN 6
#define CR_GRAY 7
#define CR_DKGRAY 8
#define CR_BRBLUE 9
#define CR_BRGREEN 10
#define CR_BRCYAN 11
#define CR_BRRED 12
#define CR_BRMAGENTA 13
#define CR_YELLOW 14
#define CR_WHITE 15
#define CR_SNAKE_HEAD 16
#define CR_SNAKE_BODY 17
/* tổng số màu có thể sử dụng, bao gồm 16 màu EGA chuẩn và 2 màu dành cho rắn */
#define CR_MAX_COLORS 18
/* các hướng di chuyển có thể */
typedef enum direction { DOWN, LEFT, RIGHT, UP } DIRECTION;
/* cấu trúc lưu trữ tọa độ 2D */
typedef struct coord {
    int x, y;
} COORD;
/* các biến ngoại biên */
extern SDL_Window* g_window; /* SDL window */
extern SDL_Renderer* g_renderer; /* SDL renderer */
/* bảng giá trị các màu sắc có thể sử dụng được */
extern unsigned long GAME_PALETTE[CR_MAX_COLORS];
/* thiết lập giá trị màu hiện thời, sử dụng bảng màu đã cho */
void setColor(int c);
/* vẽ một hình chữ nhật */
void rectDraw(int x, int y, int w, int h, unsigned long color);
SDL_Window* g_window;
SDL_Renderer* g_renderer;
/* liệt kê các giá trị màu */
unsigned long GAME_PALETTE[CR_MAX_COLORS] =
{ 0x000000, 0x0000AA, 0x00AA00, 0x00AAAA,
0xAA0000, 0xAA00AA, 0xAA5500, 0xAAAAAA,
0x555555, 0x5555FF, 0x55FF55, 0x55FFFF,
 0xFF5555, 0xFF55FF, 0xFFFF55, 0xFFFFFF,
 0x95A7C4, 0x5D6B82 };
void setColor(int c)
{
    Uint32 color = GAME_PALETTE[c];
    SDL_SetRenderDrawColor(g_renderer,
        (color >> 16), /* tách thành phần R */
        (color >> 8) & 0xFF, /* tách thành phần G */
        color & 0xFF, /* tách thành phần B */
        0xFF);
}
void rectDraw(int x, int y, int w, int h, unsigned long color)
{
    SDL_Rect rc = { x, y, w, h };
    setColor(color);
    SDL_RenderFillRect(g_renderer, &rc);
}
