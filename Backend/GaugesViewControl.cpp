#include "GaugesViewControl.h"

GaugesViewControl* GaugesViewControl::m_Instance = nullptr;

GaugesViewControl::GaugesViewControl()
    : m_Visible(false)
{}

GaugesViewControl::~GaugesViewControl()
{

}

void GaugesViewControl::SetVisible(bool isVisible)
{
    m_Visible = isVisible;
}

bool GaugesViewControl::IsVisible()
{
    return m_Visible;
}

void GaugesViewControl::Init()
{

}

void GaugesViewControl::Update(const DataModel &dataModel)
{
    if(dataModel.IsUpdate(SpeedValue))
    {
        setSpeedValue(dataModel.GetDataValue(SpeedValue));
    }
}

int GaugesViewControl::getSpeedValue() const
{
    return m_SpeedValue;
}

void GaugesViewControl::setSpeedValue(const int &speedValue)
{
    m_SpeedValue = speedValue;
    qDebug() << m_SpeedValue;
    emit SpeedValueChanged();
}

GaugesViewControl* GaugesViewControl::Instance()
{
    if (nullptr == m_Instance) {
        CreateInstance();
    }
    return m_Instance;
}

void GaugesViewControl::CreateInstance()
{
    m_Instance = new GaugesViewControl();
}

void GaugesViewControl::Destroy()
{
    if (nullptr != m_Instance) {
        delete m_Instance;
        m_Instance = nullptr;
    }
}
