#ifndef ROWGENERATOR_H
#define ROWGENERATOR_H
#include <fstream>
#include <memory>

class RowItemFactory;
class MultiRowItem;

class RowGenerator
{
private:
    std::ofstream _outStream;
    std::string _outFile;
    std::string _symbolPool;
    std::unique_ptr<RowItemFactory> _factory;
    static const int _chCount;
    static const double _fading;

    std::string _generate();
    void _fillSymbolPool();
    void _genSubItem( const std::shared_ptr<MultiRowItem>&, const int );


public:
    RowGenerator( const std::string& outFile );
    bool exec( const int count );
    ~RowGenerator();
};

#endif // ROWGENERATOR_H
