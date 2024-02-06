#include "DataModel.h"

DataModel* DataModel::m_pInstance = nullptr;


DataModel::DataModel()
{

}

DataModel::~DataModel()
{

}

void DataModel::DataInit()
{

}

void DataModel::SetDataValue(DataType type, int value)
{
    if (m_cDataSet.GetDataValue(type) != value) {
        m_cDataSet.SetDataValue(type, value);
        dataUpdateKinds.set(type);
    }
}

int DataModel::GetDataValue(DataType type) const
{
    return m_cDataSet.GetDataValue(type);
}

bool DataModel::IsUpdate(DataType type) const
{
    return dataUpdateKinds.test(type);
}

void DataModel::Reset()
{
    dataUpdateKinds.reset();
}

DataModel* DataModel::Instance()
{
    if(nullptr == m_pInstance) {
        CreateInstance();
    }
    return m_pInstance;
}

void DataModel::CreateInstance()
{
    m_pInstance = new DataModel();
}

void DataModel::Destroy()
{
    if (nullptr != m_pInstance) {
        delete m_pInstance;
        m_pInstance = nullptr;
    }
}



