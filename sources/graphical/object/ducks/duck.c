/*
** Description:
** Duck's Interface class definition
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/DuckHunt
**
*/

#include <time.h>

#include "new.h"
#include "raise.h"
#include "array.h"

#include "duck.h"

static void Duck_updatePos(DuckClass *this)
{
    // UPDATE DUCK SPRITE MOVEMENT
    (this->image->offset < (2 * DUCK_IMSIZE)) ? (this->image->offset += DUCK_IMSIZE) : (this->image->offset = 0);
    setImageRect(this->image, ((sfIntRect){this->image->offset, 0, DUCK_IMSIZE, DUCK_IMSIZE}));

    // UPDATE POSITION
    sfVector2f newPos = getImagePosition(this->image);

    newPos.x += this->direction.x * this->speed;
    newPos.y += this->direction.y * this->speed;
    setImagePosition(this->image, newPos);
}

static void Duck_display(DuckClass *this, sfRenderWindow *window)
{
    displayImage(this->image, window);
}

static void Duck_ctor(DuckClass *this, va_list *args)
{
    // Initialize internal resources

    // Set Image
    this->image = va_arg(*args, ImageClass*);

   /* Intializes random number generator */
    time_t t;
    srand((unsigned) time(&t));

    // Set direction vector
    this->direction = (sfVector2f){rand()*2 - RAND_MAX, -rand()};
    this->speed = MINSPEED + (rand() % MAXSPEED);

    // Normalize direction vector
    double u = dabs((sqrt(pow(this->direction.x, 2) + pow(this->direction.y, 2))));
    this->direction.x = (u == 0) ? 1 : this->direction.x / u;
    this->direction.y = (u == 0) ? -1 : this->direction.y / u;

    // Set orientation
    float angle = radToDeg(atan(this->direction.y / this->direction.x));

    if (angle < 0)
        angle = (angle > -MINANGLE ) ? -MINANGLE : (angle < -MAXANGLE) ? -MAXANGLE : angle;
    else
        angle = (angle < MINANGLE ) ? MINANGLE : (angle > MAXANGLE) ? MAXANGLE : angle;
    setImageRotation(this->image, angle);
    if (this->direction.x < 0.)
        setImageScale(this->image, ((sfVector2f){-1, 1}));

    printf("Duck()\n");
}

static void Duck_dtor(DuckClass *this)
{
    // Release internal resources
    if (!this)
        return;
    delete(this->image);

    printf("~Duck()\n");
}

static const DuckClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(DuckClass),
        .__name__ = "Duck",
        .__ctor__ = (ctor_t)&Duck_ctor,
        .__dtor__ = (dtor_t)&Duck_dtor,
        .__str__ = NULL,
        .__add__ = NULL,
        .__sub__ = NULL,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .image = NULL,
    /* Methods definitions */
    .__display__ = &Duck_display,
    .__move__ = &Duck_updatePos,
};

const Class *Duck = (const Class *)&_description;