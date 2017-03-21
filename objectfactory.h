#ifndef OBJECTFACTORY_H
#define OBJECTFACTORY_H
#include "creator.h"
#include <map>


template <class Base, class IdType>
class ObjectFactory
{

public:
    template <class C>
    void add(const IdType & id)
    {
        Creator<C, Base> *p = new Creator<C, Base>();
        registerClass(id, p);
    }
    Base * create(const IdType & id) const
    {
          typename std::map<IdType, AbstractCreator<Base>*>::const_iterator it = _factory.find(id);
          if (it != _factory.end())
                return it->second->create();
            else
                return 0;
    }
    ~ObjectFactory()
    {        
        for( typename std::map<IdType, AbstractCreator<Base>*>::iterator it = _factory.begin(); it != _factory.end(); ++it )
            delete it->second;

    }

private:
    std::map<IdType, AbstractCreator<Base>*> _factory;
    void registerClass(const IdType & id, AbstractCreator<Base> * p)
    {
        typename std::map<IdType, AbstractCreator<Base>*>::iterator it = _factory.find(id);
                if (it == _factory.end())
                    _factory[id] = p;
                else
                    delete p;
    }

};



#endif // OBJECTFACTORY_H
