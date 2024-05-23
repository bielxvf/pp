#include "subcmd.hpp"

const std::string red_bold("\033[1;31m");
const std::string reset("\033[0m");

const std::string err = red_bold + "[ERROR] " + reset;

int main(const int argc, const char** argv)
{
    subcmd::program pp("pp");
    pp.optionAdd(subcmd::option("help", "h", "help", "Print help message", ""));

    if (pp.optionIs("help")) {
        pp.printHelp();
        return 0;
    } else {
        if (argc > 1)  {
            std::cerr << err << "Unrecognised subcommand '" << argv[1] << "'" << std::endl;
        } else {
            std::cerr << err << "No subcommand given" << std::endl;
        }
        pp.printHelp();
        return 1;
    }
}
