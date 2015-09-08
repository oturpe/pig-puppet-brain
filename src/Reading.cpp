#include "config.h"

#include "Reading.h"

Reading::Reading() : supported(0) {
}

Reading::~Reading() {
}

bool Reading::operator ==(Reading & that) {
    return left==that.left && right==that.right;
}

void Reading::support() {
    supported++;
}

bool Reading::isValid() {
    return supported >= READING_VALIDITY_MINIMUM;
}