#ifndef GAUGESVIEWCONTROL_H
#define GAUGESVIEWCONTROL_H

#include "BaseViewControl.h"

class GaugesViewControl : public BaseViewControl
{
    Q_OBJECT
    Q_PROPERTY(int SpeedValue READ getSpeedValue WRITE setSpeedValue NOTIFY SpeedValueChanged)
public:
    GaugesViewControl();
    ~GaugesViewControl();

    static GaugesViewControl* Instance();
    static void CreateInstance();
    static void Destroy();

    virtual void SetVisible(bool isVisible) override;
    virtual bool IsVisible() override;
    virtual void Init() override;
    virtual void Update(const DataModel &dataModel) override;

    int getSpeedValue() const;
    void setSpeedValue(const int &speedValue);

signals:
    void SpeedValueChanged();

private:
    static GaugesViewControl* m_Instance;
    bool m_Visible;
    int m_SpeedValue = 0;
};

#endif // GAUGESVIEWCONTROL_H
