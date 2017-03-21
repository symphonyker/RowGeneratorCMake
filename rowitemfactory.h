#ifndef ROWITEMFACTORY_H
#define ROWITEMFACTORY_H

#include "objectfactory.h"
#include "rowitem.h"


class RowItemFactory
{
public:

    inline
        void init()
        {
            _factory.add<SingleRowItem>( RowItemType::SingleItemType );
            _factory.add<MultiRowItem>( RowItemType::MultiItemType );
        }

    inline
       RowItem* create( const RowItemType& type )
        {
             return _factory.create( type );
        }
~RowItemFactory()
    { }
private:
       ObjectFactory<RowItem, RowItemType> _factory;

};



#endif // ROWITEMFACTORY_H
