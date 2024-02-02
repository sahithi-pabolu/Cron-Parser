#include "CronParser.hpp"
#include "common.hpp"

CronParser::CronParser(string expression){
    this->expression = expression;
    this->fields = {};
    this->command = "";
}

void CronParser::parseExpression(){
    // Split the string by spaces and it will have 6 parts. First five represpenting time, last one command.

    vector<string> fieldStrings = Util::splitString(expression, " ");

    Util::printVector(fieldStrings);

    for(int i = 0; i < 5; i++){
        string fieldString = fieldStrings[i];
        string fieldName = FIELD_NAMES[i];

        CronField *cronField = new CronField(fieldString, fieldName);
        cronField->parse();

        fields.push_back(cronField);
    }

    for(int i = 5; i < fieldStrings.size(); i++){
        this->command += fieldStrings[i];
        if(i != fieldStrings.size()-1){
             this->command += " ";
        }
    }
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

    // Add the command to the output at last.
    ss << left << setw(14) << "command " << this->command << std::endl;

    return ss.str();
}

