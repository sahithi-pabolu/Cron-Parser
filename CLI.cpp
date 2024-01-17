#include "CLI.hpp"
#include "common.hpp"
#include "CronParser.hpp"

CLI::CLI(string expression){
    Util::setMapping();
    this->expression = expression;
}

void CLI::initialise(){
    CronParser *parser = new CronParser(expression);
    parser->parseExpression();
    string output = parser->formatAsTable();
    cout << output << endl;
}
