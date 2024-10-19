#include "../include/output.h"

static const char* getColorCode(enum Colors color) {
    switch (color) {
    case Black:   return BLACK;
    case Red:     return RED;
    case Green:   return GREEN;
    case Yellow:  return YELLOW;
    case Blue:    return BLUE;
    case Magenta: return MAGENTA;
    case Cyan:    return CYAN;
    case White:   return WHITE;
    default:      return RESET; // Fallback to reset if unknown
    }
}

namespace Output {
    void info(std::string message)
    {
        std::cout << CYAN << "[INFO] :: " << message << RESET << std::endl;
    }

    /*
     * It's not recomended to use this function because it is mostly used by the engine!
     */
    void error(std::string message)
    {
        std::cout << RED << "[ERROR] :: " << message << RESET << std::endl;
    }
    void custom(Colors color, std::string header, std::string message)
    {
        std::cout << getColorCode(color) << "[[ " << header << " ]] ::" << message << RESET << std::endl;
    }
}