#include "BlockHandler.h"
#include <exception>

bool BlockHandler::IsTransparent(const Block&, const Block&) const {
    throw std::runtime_error("Cannot call non described virtual function IsTransparent");
    return false;
}