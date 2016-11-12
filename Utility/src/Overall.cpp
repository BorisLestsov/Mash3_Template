#include "Overall.h"

std::string LoadSource(const std::string& filename) {
    std::ifstream in(filename);

    std::string source((std::istreambuf_iterator<char>(in)),
                       std::istreambuf_iterator<char>());

    in.close();
    return source;
}
