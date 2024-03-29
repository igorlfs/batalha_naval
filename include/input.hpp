#ifndef HANDLE_INPUT_H
#define HANDLE_INPUT_H
#include <string>
namespace Input {
struct interrupt {};
struct emptyLine {};
struct invalidDirectionFormat {
    std::string str;
};
struct invalidDirection {
    std::string str;
};
struct invalidPositionFormat {
    std::string str;
};
struct shipOutOfBounds {};
struct shipOverlap {};
struct attackOutOfBounds {};
struct attackRepeated {};
} // namespace Input
#endif
