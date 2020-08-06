//
// Created by chany on 6/14/20.
//

#include <stdio.h>
#include "2c_encapsulation_defs.h"

enum status_static {first ,after };
enum status_static _ZV5isone8thisFunc = first ;
enum status_static _ZV5isone8thatFunc = first ;

Box _ZVST8thatFunc5box88 ;
Box _ZVST8thisFunc5box99 ;
static Box _ZV8largeBox ;

void _Z8thisFunc()
{

    printf("\n--- thisFunc() ---\n\n");
    //static Box box99(99, 99, 99);
    if (_ZV5isone8thisFunc)
        _ZS3Box4ctorddd(&_ZVST8thisFunc5box99 ,99 ,99 ,99) ;
    //box99 *= 10;
    _ZS3Box2mld(&_ZVST8thisFunc5box99 , 10) ;
}

void _Z8thatFunc()
{
    printf("\n--- thatFunc() ---\n\n");
    //static Box box88;(88, 88, 88);
    if (_ZV5isone8thatFunc)
        _ZS3Box4ctorddd(&_ZVST8thatFunc5box88 ,88 ,88 ,88) ;
    //box88 *= 10;
    _ZS3Box2mld(&_ZVST8thatFunc5box88 ,10) ;
}

void _Z7doBoxesv()
{
    Box b1 , b2 ,b3 ,b4;
    printf("\n--- Start doBoxes() ---\n\n");

    //Box b1(3);
    _ZS3Box4ctord(&b1 , 3) ;
    //Box b2(4, 5, 6);

    _ZS3Box4ctorddd(&b2 ,4, 5, 6);

    //std::printf("b1 volume: %f\n", b1.getVolume());
    printf("b1 volume: %f\n", b1.width * b1.length * b1.height) ;
    //std::printf("b2 volume: %f\n", b2.getVolume());
    printf("b2 volume: %f\n", b2.width * b2.length * b2.height) ;

    //b1 *= 1.5;
    _ZS3Box2mld(&b1 , 1.5) ;
    //b2 *= 0.5;
    _ZS3Box2mld(&b2 , 0.5) ;

    printf("b1 volume: %f\n", b1.width * b1.length * b1.height) ;
    printf("b2 volume: %f\n", b2.width * b2.length * b2.height) ;

    //Box b3 = b2;
    b3 = b2;
    //Box b4 = 3 * b2;
    b4 = b2 ;
    _ZS3Box2mld(&b4 ,3);

    //std::printf("b3 %s b4\n", b3 == b4 ? "equals" : "does not equal");
    printf("b3 %s b4\n", b3.width == b4.width && b3.height == b4.height && b3.length == b4.length ? "equals" : "does not equal");

    //b3 *= 1.5;
    _ZS3Box2mld(&b3 , 1.5 ) ;
    //b4 *= 0.5;
    _ZS3Box2mld(&b4 ,0.5) ;
    //std::printf("b3 %s b4\n", b3 == b4 ? "equals" : "does not equal");
    printf("Now, b3 %s b4\n", b3.width == b4.width && b3.height == b4.height && b3.length == b4.length ? "equals" : "does not equal");

    printf("\n--- End doBoxes() ---\n\n");

    _ZS3Box4dtorv(&b4) ;
    _ZS3Box4dtorv(&b3) ;
    _ZS3Box4dtorv(&b2) ;
    _ZS3Box4dtorv(&b1) ;

}


void _Z9doShelvesv()
{
    Box aBox ;
    Shelf aShelf ;
    size_t i = 0 ;
    Box temp1 ;
    Box temp2 ;
    printf("\n--- start doShelves() ---\n\n");

    //Box aBox = 5;

    _ZS3Box4ctord(&aBox , 5) ;


    //Shelf aShelf;

    for (i = 0 ; i < Shelf_NUM_BOXES ; ++i)
        _ZS3Box4ctorv(&aShelf.boxes[i]) ;

    //aShelf.print();
    _ZS5Shelf5printv(&aShelf);
    //aShelf.setBox(1, largeBox);
    _ZS5Shelf6setBoxipc3Box(&aShelf , 1 , &_ZV8largeBox) ;
    //aShelf.setBox(0, aBox);
    _ZS5Shelf6setBoxipc3Box(&aShelf , 0 , &aBox) ;

    //aShelf.print();
    _ZS5Shelf5printv(&aShelf) ;
    //aShelf.setMessage("This is the total volume on the shelf:");
    _ZVS3Box7message = "This is the total volume on the shelf:" ;
    //aShelf.print();
    _ZS5Shelf5printv(&aShelf) ;
    //Shelf::setMessage("Shelf's volume:");
    _ZVS3Box7message = "Shelf's volume:" ;
    //aShelf.print();
    _ZS5Shelf5printv(&aShelf) ;

    //aShelf.setBox(1, Box(2, 4, 6)) ;
    _ZS3Box4ctorddd(&temp1 ,2 ,4 ,6) ;
    _ZS5Shelf6setBoxipc3Box(&aShelf ,1 ,&temp1) ;
    _ZS3Box4dtorv(&temp1) ;

    //aShelf.setBox(2, 2);
    _ZS3Box4ctord(&temp2 , 2) ;
    _ZS5Shelf6setBoxipc3Box(&aShelf , 2, &temp2);
    _ZS3Box4dtorv(&temp2) ;

    //aShelf.print();
    _ZS5Shelf5printv(&aShelf) ;

    printf("\n--- end doShelves() ---\n\n");

    for (i = Shelf_NUM_BOXES-1 ; i >= 0 ; --i)
        _ZS3Box4dtorv(&aShelf.boxes[i]) ;
    _ZS3Box4dtorv(&aBox) ;
}

int main()
{
    _ZS3Box4ctorddd(&_ZV8largeBox ,10, 20, 30);
    printf("\n--- Start main() ---\n\n");

    _Z7doBoxesv();

    _Z8thisFunc();
    _ZV5isone8thisFunc = after ;
    _Z8thisFunc();
    _ZV5isone8thisFunc = after ;
    _Z8thisFunc();
    _ZV5isone8thisFunc = after ;
    _Z8thatFunc();
    _ZV5isone8thatFunc = after ;
    _Z8thatFunc();
    _ZV5isone8thatFunc = after ;

    _Z9doShelvesv();

    printf("\n--- End main() ---\n\n");



    _ZS3Box4dtorv(&_ZVST8thatFunc5box88) ;
    _ZS3Box4dtorv(&_ZVST8thisFunc5box99) ;

    _ZS3Box4dtorv(&_ZV8largeBox) ;
    return 0;
}

