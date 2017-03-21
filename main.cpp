#include <iostream>
#include <unistd.h>
#include "rowgenerator.h"

using namespace std;

int main(int argc, char *argv[])
{
    if( argc != 5 )
    {
        std::cerr<<"Invalid param"<<std::endl;
        return 1;
    }

    char* fName;
    int rCount { 0 };

    int opt = 0;
    while ( ( opt = getopt( argc, argv, "f:c:" ) ) != -1 )
    {
        switch ( opt )
        {
            case 'f':
                fName = optarg;
            break;
            case 'c':
                rCount = atoi( optarg );
            break;
            case '?':
                printf("Error found !\n");
            break;
        };
    }
    //std::string fName ="C:\\Users\\User\\Documents\\build-RowSorter-Desktop_Qt_5_5_1_MinGW_32bit-Debug\\debug\\testRow1.txt";
    //int rCount { 10 };
    RowGenerator rowGenerator( fName );
    return !rowGenerator.exec( rCount );

}
