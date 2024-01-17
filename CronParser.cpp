#include "CronParser.hpp"
#include "common.hpp"


CronParser::CronParser(string expression){
    this->expression = expression;
    this->fields = {};
    this->command = "";
}

void CronParser::parseExpression(){

    vector<string> fieldStrings = Util::splitString(expression, " ");

    Util::printVector(fieldStrings);

    for(int i = 0; i < 5; i++){
        string fieldString = fieldStrings[i];
        string fieldName = FIELD_NAMES[i];

        CronField *cronField = new CronField(fieldString, fieldName);
        cronField->parse();

        fields.push_back(cronField);
    }

    this->command = fieldStrings[5];
}

string CronParser::formatAsTable(){
    stringstream ss;

    for (auto field : fields) {

        ss << left << setw(14) << field->getFieldName();

        for (int value : field->getValues()) {
            ss << value << ' ';
        }

        ss << endl;
    }

    ss << left << setw(14) << "command " << this->command << std::endl;

    return ss.str();
}

