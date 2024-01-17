 #include "CLI.hpp"
 #include "common.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <cron_expression>\n";
        return 1;
    }

    std::string expression(argv[1]);
    CLI cli(expression);
    cli.initialise();

    return 0;
}
