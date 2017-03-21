#include "rowitem.h"
#include <iostream>
#include <algorithm>
#include <cstring>

RowItem::RowItem( const RowItemType& type_ )
    :type( type_ )
{

}

RowItem::~RowItem()
{

}


void RowItem::setParent( const std::shared_ptr<RowItem> & p )
{
    parent = p;
}


RowItemType RowItem::getType() const
{
    return type;
}

std::shared_ptr<RowItem> RowItem::getParent()
{
    return parent;
}

std::string RowItem::getMainIndex() const
{
    return mainIndex;
}

SingleRowItem::SingleRowItem()
    : RowItem( RowItemType::SingleItemType )
{

}

void SingleRowItem::setValue( const std::string &v )
{
    _value = v;
}

std::string SingleRowItem::getValue() const
{
    return _value;
}

void SingleRowItem::print()
{
    std::cout<<toString();
}

std::string SingleRowItem::getMainIndex() const
{
    return _value;
}

std::string SingleRowItem::toString()
{
    return _value;
}



MultiRowItem::MultiRowItem()
    :RowItem( RowItemType::MultiItemType )
{

}


void MultiRowItem::addItem( const std::shared_ptr<RowItem> & item )
{
    _items.push_back( item );
}

void MultiRowItem::addSortItem( const std::shared_ptr<RowItem> & item )
{
    if( _items.empty() )
        addItem( item );
    else
    {
        auto index = std::upper_bound( _items.begin(), _items.end(), item, []( const std::shared_ptr<RowItem>& item1, const std::shared_ptr<RowItem>& item2 )->bool
        {
            return  item1->getMainIndex() < item2->getMainIndex();
        });
        _items.insert( index, item );
    }

}

std::string MultiRowItem::getMainIndex() const
{
    auto it = _items.begin();
    return (*it)->getMainIndex();
}


void MultiRowItem::print()
{

    std::cout<<toString();
}

std::string MultiRowItem::toString()
{
    std::string out;
    out.append( "(" );
    int index = 0;
    int size = _items.size();;
    for( const std::shared_ptr<RowItem>& item : _items )
    {
        if( ( index != 0 ) && ( index != size  ) )
            out.append( "+" );
        out.append( item->toString() );
        ++index;
    }

   out.append( ")" );
   return out;
}

