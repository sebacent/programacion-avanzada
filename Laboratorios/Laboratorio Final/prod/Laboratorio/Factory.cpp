#include "Factory.h"

ISistema * Factory::getSistema() {
    return Sistema::getInstancia();
}