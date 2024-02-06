#ifndef DATA_SET_H
#define DATA_SET_H

#include "DataDef.h"

class DataSet
{
public:
    DataSet();
    virtual ~DataSet();

    void DataInit();
    void SetDataValue(DataType type, int value);
    int GetDataValue(DataType type) const;

private:
    DataModelStruct dataArray[DataUpdateTypeMax];
};

#endif
