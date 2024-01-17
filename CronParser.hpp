#include "common.hpp"
#include "CronField.hpp"

class CronParser{

private:

    string expression;
    vector<CronField*> fields;
    string command;

public:

    CronParser(string expression);

    void parseExpression();

    string formatAsTable();
};