#ifndef ROWITEM_H
#define ROWITEM_H
#include <list>
#include <string>
#include <memory>

enum class RowItemType : short
{
    SingleItemType = 1,
    MultiItemType
};

class RowItem
{
protected:
    std::shared_ptr< RowItem > parent;
    RowItemType type;
    std::string mainIndex;
public:
    RowItem( const RowItemType& );
    virtual ~RowItem();
    void setParent( const std::shared_ptr< RowItem >& );
    std::shared_ptr<RowItem> getParent();
    RowItemType getType() const;
    virtual void print() = 0;
    virtual std::string toString() = 0;
    virtual std::string getMainIndex() const = 0;


};
class SingleRowItem : public RowItem
{
    private:
        std::string _value;
    public:
        void setValue( const std::string& );
        std::string getValue() const;
        SingleRowItem();
        void print() override;
        std::string toString() override;
        std::string getMainIndex() const override;
};

class MultiRowItem : public RowItem
{
    private:
        std::list< std::shared_ptr< RowItem > > _items;
    public:
        void addItem( const std::shared_ptr<RowItem>& );
        void addSortItem( const std::shared_ptr<RowItem>& );
        MultiRowItem();
        std::string getMainIndex() const override;
        void print() override;
        std::string toString() override;

};

#endif // ROWITES_H
