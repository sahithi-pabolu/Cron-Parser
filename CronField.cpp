#include "CronField.hpp"
#include "common.hpp"

unordered_map<string, vector<int>> rangeMapping;

int CronField::getMin() {
    return rangeMapping[this->fieldName][0];
}

int CronField::getMax(){
    return rangeMapping[this->fieldName][1];
}


CronField::CronField(string fieldString, string fieldName){
    this->fieldName = fieldName;
    this->fieldString = fieldString;
}

string CronField::getFieldName(){
    return this->fieldName;
}

vector<int> CronField::getValues(){
    return this->values;
}

/*
    55-10 0 1,15 * 1-5 /usr/bin/find

    55-max
    min-10
*/

void CronField::parse(){
    // ANY VALUE
    if (this->fieldString == ANY_VALUE){
        int min = rangeMapping[this->fieldName][0];
        int max = rangeMapping[this->fieldName][1];

        this->values = Util::getRangeValues(min, max);
    }
    // LIST OF VALUES SEPARATED BY A COMMA
    else if(Util::containsToken(this->fieldString, LIST_SEPARATOR)){
        vector<string> parts = Util::splitString(this->fieldString, LIST_SEPARATOR);
        vector<int> additionalValues = {};

        // Each range in the output can again be value range or increment values.
        for(auto part: parts){
            if(part == ANY_VALUE){
                continue;
            }
            else if(Util::containsToken(part, INCREMENT_VALUES)){

                vector<string> stepParts = Util::splitString(part, INCREMENT_VALUES);

                if(Util::containsToken(stepParts[0], VALUE_RANGE)){
                    vector<string> ranges = Util::splitString(stepParts[0], VALUE_RANGE);

                    int min = stoi(ranges[0]);
                    int max = stoi(ranges[1]);

                    additionalValues = Util::getStepValues(stepParts[1], min, max);
                    this->values.insert(this->values.end(), additionalValues.begin(), additionalValues.end());
                }
                
            }
            else if(Util::containsToken(part, VALUE_RANGE)){
                vector<string> ranges = Util::splitString(this->fieldString, VALUE_RANGE);

                int min = stoi(ranges[0]);
                int max = stoi(ranges[1]);

                additionalValues = Util::getRangeValues(min, max);
                this->values.insert(this->values.end(), additionalValues.begin(), additionalValues.end());
            }
            else{
                this->values.push_back(stoi(part));
            }
        }

    }
    // CASE WITH INCREMENT VALUES
    else if(Util::containsToken(this->fieldString, INCREMENT_VALUES)){
        vector<string> stepParts = Util::splitString(fieldString, INCREMENT_VALUES);
        int minV =0;
        int maxV = 0;

        if(Util::containsToken(stepParts[0], VALUE_RANGE)){
            vector<string> ranges = Util::splitString(stepParts[0], VALUE_RANGE);

            minV = stoi(ranges[0]);
            maxV = stoi(ranges[1]);
        }
        else{
            maxV = this->getMax();
        }

        this->values = Util::getStepValues(stepParts[1], minV, maxV, this->fieldName);
    }
    // CASE WITH RANGES
    else if(Util::containsToken(this->fieldString, VALUE_RANGE)){
        vector<string> ranges = Util::splitString(this->fieldString, VALUE_RANGE);

        int min = stoi(ranges[0]);
        int max = stoi(ranges[1]);

        this->values = Util::getRangeValues(min, max, this->fieldName);
    }
    // CASE WITH JUST A NUMBER
    else{
        this->values.push_back(stoi(this->fieldString));
    }
}
