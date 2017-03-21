#include "rowgenerator.h"
#include "rowitemfactory.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

const int RowGenerator::_chCount = 26;
const double RowGenerator::_fading = 2.5;

RowGenerator::RowGenerator( const std::string &outFile )
    : _outFile( outFile ), _factory( new RowItemFactory )
{
    _outStream.open( outFile );
    _factory->init();
}

RowGenerator::~RowGenerator()
{
    _outStream.close();
}



bool RowGenerator::exec( const int count )
{
    if( !_outStream )
    {
        std::cerr<<"Can`t open output file"<<std::endl;
        return false;
    }
    if( count <= 0 )
    {
        std::cerr<<"Invalid row count"<<std::endl;
        return false;
    }
    srand( time( NULL ) );
    for( int i = 0; i < count; ++i )
       _outStream << _generate() <<"\n";
    std::cout<<"done\ngenerate in file: "<<_outFile<<std::endl;
    return true;
}

std::string RowGenerator::_generate()
{
    _fillSymbolPool();
    std::shared_ptr<MultiRowItem> parent{ ( MultiRowItem* ) _factory->create( RowItemType::MultiItemType ) };
    _genSubItem( parent, 20 );
    return parent->toString();
}

void RowGenerator::_genSubItem( const std::shared_ptr<MultiRowItem>& parent, const int  fCount )
{
    int rP {0};
    if( fCount == 0 )
        rP = 1;
    else
        rP = rand() % fCount + 1 ;
    RowItemType type;
    for( int i = 0; i < rP; ++i )
    {
        type = static_cast<RowItemType>( rand() % 2 + 1 );
        std::shared_ptr<RowItem> ptr { _factory->create( type ) };
        switch( type )
        {

            case RowItemType::MultiItemType:
                _genSubItem( std::dynamic_pointer_cast<MultiRowItem>( ptr ), fCount / _fading );
            break;
            case RowItemType::SingleItemType:
                    std::dynamic_pointer_cast<SingleRowItem>( ptr )->setValue( std::string( 1, _symbolPool[ rand() % _chCount + 1 ] ) );
            break;
        }
        parent->addItem( ptr );
    }
}


void RowGenerator::_fillSymbolPool()
{
    for( int i = 0; i < _chCount; ++i )
            _symbolPool.append( 1, ('A' + i ) );
}
