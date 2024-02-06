#ifndef DATA_MODEL_H
#define DATA_MODEL_H

#include "DataDef.h"
#include "DataSet.h"

class DataModel{
public:
    DataModel();
    virtual ~DataModel();

    void DataInit();
    void SetDataValue(DataType type, int value);
    int GetDataValue(DataType type) const;

    bool IsUpdate(DataType type) const;
    void Reset();

    static DataModel* Instance();
    static void CreateInstance();
    static void Destroy();

private:
    static DataModel* m_pInstance;
    DataUpdateKinds dataUpdateKinds;
    DataSet m_cDataSet;
};

#endif
