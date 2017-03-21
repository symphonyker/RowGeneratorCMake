#ifndef ABSTRACTCREATOR_H
#define ABSTRACTCREATOR_H



template <class Base>
class AbstractCreator
{
public:
    AbstractCreator()
    {
    }

    virtual ~AbstractCreator()
    {
    }

    virtual Base* create() const = 0;

private:
    AbstractCreator(const AbstractCreator&);
    AbstractCreator& operator = (const AbstractCreator&);
};


#endif // ABSTRACTCREATOR_H
