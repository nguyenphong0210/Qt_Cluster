#ifndef VIEW_CONTROL_IF_H
#define VIEW_CONTROL_IF_H
#include <QObject>
#include "DataModel/DataModel.h"
#include <memory>

class ViewControlIF : public QObject
{
public:
    virtual ~ViewControlIF() {}
    virtual void SetVisible(bool isVisible) = 0;
    virtual bool IsVisible() = 0;
    virtual void Init() = 0;
    virtual void Update(const DataModel &dataModel) = 0;
};

typedef std::shared_ptr<ViewControlIF> SpViewControl;

#endif
