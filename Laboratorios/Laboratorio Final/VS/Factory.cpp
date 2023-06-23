#include "Factory.h"

//ISistema
Sistema * Factory::getSistema() {
    return Sistema::getInstancia();
}