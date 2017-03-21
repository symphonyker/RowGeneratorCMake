#ifndef CREATOR_H
#define CREATOR_H
#include "abstractcreator.h"



template <class C, class Base>
class Creator : public AbstractCreator<Base>
{
public:
    Creator() { }
    ~Creator()	{ }
    Base * create() const { return new C(); }
};



#endif // CREATOR_H
