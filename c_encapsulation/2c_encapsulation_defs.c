//
// Created by chany on 6/14/20.
//

#include <stdio.h>
#include "2c_encapsulation_defs.h"

//// Box ////////////
void _ZS3Box4ctorv(Box *this)
{
    _ZS3Box4ctord(this , 1) ;
}
void _ZS3Box4ctord(Box *this , double dim)
{
    this->length = this->width = this->height = dim ;
    _ZS3Box5printv(this) ;
}

void _ZS3Box4ctorddd(Box *this , double l, double w, double h)
{
    this->length = l ;
    this->width = w ;
    this->height = h ;
    _ZS3Box5printv(this) ;
}

void _ZS3Box4dtorv(Box *this)
{
    printf("Box destructor, %f x %f x %f\n", this->width, this->height, this->length);
}

Box* _ZS3Box2mld(Box *this , double mult)
{
    this->width *= mult;
    this->height *= mult;
    this->length *= mult;

    return this;
}

void _ZS3Box5printv(const Box *this)
{
printf("Box: %f x %f x %f\n", this->length, this->width, this->height);
}


//// Shelf ////////////


const char* _ZVS3Box7message = Shelf_DEF_MSG ;

void _ZS5Shelf6setBoxipc3Box(Shelf *this , int index, const Box *dims)
{
    this->boxes[index] = *dims;
}

double _ZS5Shelf9getVolumev(const Shelf *this)
{
    double vol = 0;
    size_t  i = 0 ;
    for ( i = 0; i < Shelf_NUM_BOXES; ++i)
        vol += (this->boxes[i].length * this->boxes[i].height * this->boxes[i].width) ;

    return vol;
}

void _ZS5Shelf5printv(const Shelf *this)
{
    printf("%s %f\n", _ZVS3Box7message, _ZS5Shelf9getVolumev(this));
}


