//
// Created by chany on 6/14/20.
//

#ifndef C___UNDER_THE_HOOD_2C_ENCAPSULATION_DEFS_H
#define C___UNDER_THE_HOOD_2C_ENCAPSULATION_DEFS_H


#define Shelf_NUM_BOXES 3
#define Shelf_DEF_MSG "The total volume held on the shelf is"


//// Box ////////////

typedef struct {

    double length;
    double width;
    double height;
}Box;


//Box::Box(double dim = 1);
void _ZS3Box4ctorv( Box *this ) ;
void _ZS3Box4ctord( Box *this , double dim) ;
//Box::Box(double l, double w, double h) ;
void _ZS3Box4ctorddd( Box *this , double l , double w , double h) ;
//Box::~Box() ;
void _ZS3Box4dtorv(Box *this) ;
//Box& Box::operator*=(double mult) ;
Box* _ZS3Box2mld(Box *this , double mult) ;
//void Box::print() const ;
void _ZS3Box5printv(const Box *this) ;



//// Shelf ////////////
typedef struct {
    Box boxes[Shelf_NUM_BOXES];
} Shelf;


const char *_ZVS3Box7message ;

//void Shelf::setBox(int index, const Box& dims)
void _ZS5Shelf6setBoxipc3Box(Shelf *this , int index , const Box *dims) ;
//double Shelf::getVolume() const
double _ZS5Shelf9getVolumev(const Shelf *this) ;
//void Shelf::print() const
void _ZS5Shelf5printv(const Shelf *this) ;


#endif //C___UNDER_THE_HOOD_2C_ENCAPSULATION_DEFS_H
