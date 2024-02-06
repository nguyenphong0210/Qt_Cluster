#include "DataSet.h"


DataSet::DataSet()
{

}

DataSet::~DataSet()
{

}

void DataSet::DataInit()
{
    for (int i = DataInvalid; i<DataUpdateTypeMax;i++)
    {
        dataArray[i].DataValue = 0;
    }
}

void DataSet::SetDataValue(DataType type, int value)
{
    dataArray[type].DataValue = value;
}

int DataSet::GetDataValue(DataType type) const
{
    return dataArray[type].DataValue;
}
