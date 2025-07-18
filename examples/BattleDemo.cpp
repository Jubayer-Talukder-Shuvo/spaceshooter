/*
    author: S. M. Shahriar Nirjon
    last modified: August 8, 2008
*/
#include "iGraphics.h"

typedef enum
{
    IDLE,
    WALK,
    JUMP
} State;

typedef struct
{
    Image idle[4], walk[6], jump[8];
    Sprite sprite;
    State state;
    int direction; // 1 for right, -1 for left
} Monster;

Monster pinkMonster;

typedef struct
{
    Image idle[18], walk[25], jump[25];
    Sprite sprite;
    State state;
    int direction; // 1 for right, -1 for left
} Golem;

Golem golem;

void loadPinkMonster()
{
    iLoadFramesFromSheet(pinkMonster.idle, "assets/images/sprites/1 Pink_Monster/Pink_Monster_Idle_4.png", 1, 4);
    iLoadFramesFromSheet(pinkMonster.walk, "assets/images/sprites/1 Pink_Monster/Pink_Monster_Walk_6.png", 1, 6);
    iLoadFramesFromSheet(pinkMonster.jump, "assets/images/sprites/1 Pink_Monster/Pink_Monster_Jump_8.png", 1, 8);

<<<<<<< HEAD
    iInitSprite(&pinkMonster.sprite);
    iChangeSpriteFrames(&pinkMonster.sprite, pinkMonster.idle, 4);
    iSetSpritePosition(&pinkMonster.sprite, 250, 0);
=======
    iInitSprite(&pinkMonster.sprite, -1);
    iChangeSpriteFrames(&pinkMonster.sprite, pinkMonster.idle, 4);
    iSetSpritePosition(&pinkMonster.sprite, 200, 0);
>>>>>>> 95328ce8b4c17ad6b51c6f9217fc5463d054fb7d
    iScaleSprite(&pinkMonster.sprite, 3.0);
    pinkMonster.state = IDLE;
    pinkMonster.direction = 1; // 1 for right, -1 for left
}

void loadGolem()
{
    iLoadFramesFromFolder(golem.idle, "assets/images/sprites/Golem_2/Idle Blinking");
    iLoadFramesFromFolder(golem.walk, "assets/images/sprites/Golem_2/Walking");
    iLoadFramesFromFolder(golem.jump, "assets/images/sprites/Golem_2/Jump Start");

<<<<<<< HEAD
    iInitSprite(&golem.sprite);
    iChangeSpriteFrames(&golem.sprite, golem.idle, 18);
    iSetSpritePosition(&golem.sprite, 250, -75);
=======
    iInitSprite(&golem.sprite, -1);
    iChangeSpriteFrames(&golem.sprite, golem.idle, 18);
    iSetSpritePosition(&golem.sprite, 300, -75);
>>>>>>> 95328ce8b4c17ad6b51c6f9217fc5463d054fb7d
    iScaleSprite(&golem.sprite, 0.5);
    iMirrorSprite(&golem.sprite, HORIZONTAL);
    golem.state = IDLE;
    golem.direction = -1; // 1 for right, -1 for left
}

void iAnim()
{
    switch (pinkMonster.state)
    {
    case IDLE:
        break;
    case WALK:
        if (!isSpecialKeyPressed(GLUT_KEY_LEFT) &&
            !isSpecialKeyPressed(GLUT_KEY_RIGHT))
        {
            pinkMonster.state = IDLE;
            iChangeSpriteFrames(&pinkMonster.sprite, pinkMonster.idle, 4);
        }
        break;
    case JUMP:
        if (!isSpecialKeyPressed(GLUT_KEY_UP))
        {
            pinkMonster.state = IDLE;
            iChangeSpriteFrames(&pinkMonster.sprite, pinkMonster.idle, 4);
        }
        break;
    }
    iAnimateSprite(&pinkMonster.sprite);
    iAnimateSprite(&golem.sprite);
}
/*
    function iDraw() is called again and again by the system.
*/
void iDraw()
{
    // place your drawing codes here
    iClear();
<<<<<<< HEAD
    iSetColor(255, 255, 255);
    iFilledRectangle(0, 0, 800, 400);
    iShowSprite(&golem.sprite);
    iShowSprite(&pinkMonster.sprite);

    int count = iCheckCollision(&golem.sprite, &pinkMonster.sprite);
    int visibleCount = iGetVisiblePixelsCount(&pinkMonster.sprite);

    if (count / (1.0 * visibleCount) > 0.01) // 1% collision threshold // or we can just use count > 0
=======
    iShowSprite(&golem.sprite);
    iShowSprite(&pinkMonster.sprite);

    if (iCheckCollision(&golem.sprite, &pinkMonster.sprite))
>>>>>>> 95328ce8b4c17ad6b51c6f9217fc5463d054fb7d
    {
        iSetColor(255, 0, 0);
        iText(100, 300, "Collision Detected", GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(255, 255, 255);
    }
    // iShowBMP(pic_x, pic_y, "wheel.bmp");
}

/*
function iMouseMove() is called when the user moves the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
    // place your codes here
}

/*
function iMouseDrag() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouseDrag(int mx, int my)
{
    // place your codes here
}

/*
function iMouseWheel() is called when the user scrolls the mouse wheel.
dir = 1 for up, -1 for down.
*/
void iMouseWheel(int dir, int mx, int my)
{
    // place your code here
}

/*
    function iMouse() is called when the user presses/releases the mouse.
    (mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        // place your codes here
    }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        // place your codes here
    }
}

/*
    function iKeyboard() is called whenever the user hits a key in keyboard.
    key- holds the ASCII value of the key pressed.
*/
<<<<<<< HEAD
void iKeyboard(unsigned char key, int state)
=======
void iKeyboard(unsigned char key)
>>>>>>> 95328ce8b4c17ad6b51c6f9217fc5463d054fb7d
{
    if (key == 'x')
    {
        // do something with 'x'
        exit(0);
    }
    // place your codes for other keys here
}

/*
    function iSpecialKeyboard() is called whenver user hits special keys like-
    function keys, home, end, pg up, pg down, arraows etc. you have to use
    appropriate constants to detect them. A list is:
    GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
    GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
    GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
    GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
<<<<<<< HEAD
void iSpecialKeyboard(unsigned char key, int state)
=======
void iSpecialKeyboard(unsigned char key)
>>>>>>> 95328ce8b4c17ad6b51c6f9217fc5463d054fb7d
{

    if (key == GLUT_KEY_END)
    {
        exit(0);
    }
    if (key == GLUT_KEY_LEFT)
    {
        if (pinkMonster.direction == 1)
        {
            iMirrorSprite(&pinkMonster.sprite, HORIZONTAL);
            pinkMonster.direction = -1;
        }
        else
        {
            pinkMonster.sprite.x--;
            if (pinkMonster.state != WALK)
            {
                pinkMonster.state = WALK;
                iChangeSpriteFrames(&pinkMonster.sprite, pinkMonster.walk, 6);
            }
        }
    }
    if (key == GLUT_KEY_RIGHT)
    {
        if (pinkMonster.direction == -1)
        {
            iMirrorSprite(&pinkMonster.sprite, HORIZONTAL);
            pinkMonster.direction = 1;
        }
        else
        {
            pinkMonster.sprite.x++;
            if (pinkMonster.state != WALK)
            {
                pinkMonster.state = WALK;
                iChangeSpriteFrames(&pinkMonster.sprite, pinkMonster.walk, 6);
            }
        }
    }
    if (key == GLUT_KEY_UP)
    {
        pinkMonster.sprite.y++;
        if (pinkMonster.state != JUMP)
        {
            pinkMonster.state = JUMP;
            iChangeSpriteFrames(&pinkMonster.sprite, pinkMonster.jump, 8);
        }
    }
    if (key == GLUT_KEY_DOWN)
    {
        pinkMonster.sprite.y--;
    }
    // place your codes for other keys here
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
<<<<<<< HEAD
    iSetTimer(100, iAnim);
    loadPinkMonster();
    loadGolem();
    iOpenWindow(800, 400, "SpriteDemo");
=======
    // place your own initialization codes here.
    loadPinkMonster();
    loadGolem();
    iSetTimer(100, iAnim);
    iInitialize(800, 400, "SpriteDemo");
>>>>>>> 95328ce8b4c17ad6b51c6f9217fc5463d054fb7d
    return 0;
}
