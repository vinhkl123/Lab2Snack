#include "global.h"

#include "C:\Users\DELL\Desktop\Lab2Snack\Dependencies\SDL\SDL.h"
#define SNAKE_MAXLEN 100 /* chiều dài tối đa của rắn */
#define SNAKE_INITLEN 4 /* chiều dài ban đầu của rắn */
typedef struct snake {
    COORD coords[SNAKE_MAXLEN]; /* rắn là một danh sách các tọa độ 2D */
    int len; /* độ dài hiện thời của rắn */
    Uint32 color;
} SNAKE;
typedef struct fruit {
    COORD loc; /* vị trí của mồi */
    Uint32 color; /* màu sắc */
} FRUIT;
/* vẽ một ô của thân rắn hoặc đầu rắn */
void snakeCell(COORD c, SDL_bool head);
/* khởi tạo rắn */
void snakeInit(SNAKE* s);
/* vẽ rắn */
void snakeDraw(const SNAKE* s);
/* cập nhật trạng thái của rắn */
void snakeUpdate(SNAKE* s);
/* phát sinh mồi */
void fruitGen(FRUIT* f, const SNAKE* s);
/* vẽ mồi */
void fruitDraw(const FRUIT* f);
void snakeCell(COORD c, SDL_bool head)
{
    int color = head ? CR_SNAKE_HEAD : CR_SNAKE_BODY;
    rectDraw(c.x * BOARD_CELL, c.y * BOARD_CELL, BOARD_CELL, BOARD_CELL, color);
}
void snakeInit(SNAKE* s)
{
    s->coords[0].x = (BOARD_HORZ >> 1);
    s->coords[0].y = (BOARD_VERT >> 1);
    s->len = SNAKE_INITLEN;
    for (int i = 1; i < s->len; i++) {
        s->coords[i].x = s->coords[i - 1].x;
        s->coords[i].y = (BOARD_VERT >> 1) + i;
    }
}
void snakeDraw(const SNAKE* s)
{
    snakeCell(s->coords[0], SDL_TRUE);
    for (int i = 1; i < s->len; i++) {
        snakeCell(s->coords[i], SDL_FALSE);
    }
    
  
}
void snakeUpdate(SNAKE* s)
{
    for (int i = s->len; i > 0; i--)
    {
        s->coords[i] = s->coords[i - 1];
        s->color = rand() % 14 + 1;
     
    }
   

}
void fruitGen(FRUIT* f, const SNAKE* s)
{
    SDL_bool ok = SDL_FALSE;
    int i;
    while (!ok) {
        f->loc.x = rand() % BOARD_HORZ;
        f->loc.y = rand() % BOARD_VERT;
        for (i = 0; i < s->len; i++) {
            if (f->loc.x != s->coords[i].x &&
                f->loc.y != s->coords[i].y)
                continue;
        }
        if (i == s->len)
            ok = SDL_TRUE;
    }
    f->color = rand() % 14 + 1;
}
void fruitDraw(const FRUIT* f)
{
    rectDraw(f->loc.x * BOARD_CELL, f->loc.y * BOARD_CELL,
        BOARD_CELL, BOARD_CELL, f->color);
}