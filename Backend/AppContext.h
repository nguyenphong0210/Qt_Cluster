#ifndef APPCONTEXT_H
#define APPCONTEXT_H

#include "GaugesViewControl.h"

class AppContext {
public:
    static AppContext& instance() {
        static AppContext instance;
        return instance;
    }

    GaugesViewControl* getMyGaugeViewControlInstance() {
        return m_GaugesViewControl_Instance;
    }

private:
    AppContext() {
        m_GaugesViewControl_Instance = GaugesViewControl::Instance();
    }

    GaugesViewControl* m_GaugesViewControl_Instance;
};

#endif // APPCONTEXT_H
