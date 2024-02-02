#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <unordered_map>
using namespace std;

const string ANY_VALUE = "*";
const string LIST_SEPARATOR = ",";
const string VALUE_RANGE = "-";
const string INCREMENT_VALUES = "/";
const vector<string> FIELD_NAMES = {"minute", "hour", "day of month", "month", "day of week"};
const vector<int> minimums = {0, 0, 1, 1, 0};
const vector<int> maximums = {59, 23, 31, 12, 6};

extern unordered_map<string, vector<int>> rangeMapping;

class Util{

public:

    static void setMapping(){
        int total = FIELD_NAMES.size();

        for(int i = 0; i < total; i++){
            rangeMapping[FIELD_NAMES[i]] = {minimums[i], maximums[i]};
        }
    }

    static void printVector(vector<string> values){

        for(auto value: values){
            cout << value << " ";
        }

        cout << endl;
    }

    static vector<string> splitString(string inputString, string delimiter){
        vector<string> tokens;

        size_t start = 0;
        size_t end = inputString.find(delimiter);

        while (end != string::npos) {
            tokens.push_back(inputString.substr(start, end - start));
            start = end + 1;
            end = inputString.find(delimiter, start);
        }

        // Add the last token
        tokens.push_back(inputString.substr(start));

        return tokens;
    }   

    static vector<int> getRangeValues(int min, int max, int step = 1){
        vector<int> result;

        for(int i = min; i <= max; i = i + step){
            result.push_back(i);
        }

        return result;
    }

    static vector<int> getRanges(int min, int max, string fieldName, int step = 1){
        vector<int> result;
        
        int minActual = rangeMapping[fieldName][0];
        int maxActual = rangeMapping[fieldName][1];

        vector<int> res1 = getRangeValues(min, maxActual, step);
        vector<int> res2 = getRangeValues(minActual, max, step);

        result.insert(result.end(), res1.begin(), res1.end());
        result.insert(result.end(), res2.begin(), res2.end());

        return result;
    }

    static vector<int> getRangeValues(int min, int max, string fieldName){
        vector<int> result;

        if(min > max){
            result = getRanges(min, max, fieldName);
        }
        else{
            for(int i = min; i <= max; i++){
                result.push_back(i);
            }
        }

        return result;
    }

    static vector<int> getStepValues(string& stepPart, int minV, int maxV) {
        int step = stoi(stepPart);
        vector<int> values;

        for (int i = minV; i <= maxV; i += step) {
            values.push_back(i);
        }

        return values;
    }

    static vector<int> getStepValues(string& stepPart, int minV, int maxV, string fieldName) {
        int step = stoi(stepPart);
        vector<int> values;

        if(minV > maxV){
             values = getRanges(minV, maxV, fieldName, step);
        }
        else{
            for (int i = minV; i <= maxV; i += step) {
                values.push_back(i);
            }
        }

        return values;
    }


    static bool containsToken(string& str, string token) {
        return str.find(token) != string::npos;
    }
};

