#include "common.hpp"

class CronField{

private:

    string fieldString;
    vector<int> values;
    string fieldName;

    int getMin();
    int getMax();

public:

    CronField(string fieldString, string fieldName);

    string getFieldName();

    vector<int> getValues();

    void parse();
    
};
