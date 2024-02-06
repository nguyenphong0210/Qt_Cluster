#ifndef BASEVIEWCONTROL_H
#define BASEVIEWCONTROL_H

#include "ViewControlIF.h"
#include <QDebug>

class BaseViewControl : public ViewControlIF
{
public:
    BaseViewControl();
    ~BaseViewControl();

    virtual void SetVisible(bool isVisible);
    virtual bool IsVisible();
    virtual void Init();
    virtual void Update(const DataModel &dataModel);
};

#endif
