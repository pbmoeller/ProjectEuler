#include "math/io.hpp"

#include <fstream>

namespace pe {

std::string readFile(const std::string &filename)
{
    // Open file.
    std::ifstream ifs(filename);
    if(!ifs.is_open()) {
        throw std::runtime_error("Cannot read file: " + filename);
    }

    // Read file content
    std::string fileContent;
    ifs.seekg(0, ifs.end);
    fileContent.reserve(static_cast<size_t>(ifs.tellg()));
    ifs.seekg(0, ifs.beg);
    fileContent.assign((std::istreambuf_iterator<char>(ifs)),
                       std::istreambuf_iterator<char>());
    ifs.close();

    return fileContent;
}

} // namespace pe
