#include "Date.h"

Date::Date(int _dia,int  _mes, int _anio){
    this->dia = _dia;
    this->mes = _mes;
    this->anio = _anio;
};

Date::~Date(){};

int Date::getDia(){
    return this->dia;
};

int Date::getMes(){
    return this->mes;
};

int Date::getAnio(){
    return this->anio;
};

void Date::setDia(int _dia){
    this->dia = _dia;
};

void Date::setMes(int _mes){
    this->mes = _mes;
};

void Date::setAnio(int _anio){
    this->anio = _anio;
};

bool Date::operator<(Date* _fecha){
    if(this->anio < _fecha->getAnio()){
        return true;
    }else if(this->anio == _fecha->getAnio()){
        if(this->mes < _fecha->getMes()){
            return true;
        }else if(this->mes == _fecha->getMes()){
            if(this->dia < _fecha->getDia()){
                return true;
            }
        }
    }
    return false;
};

bool Date::operator>(Date* _fecha){
    if(this->anio > _fecha->getAnio()){
        return true;
    }else if(this->anio == _fecha->getAnio()){
        if(this->mes > _fecha->getMes()){
            return true;
        }else if(this->mes == _fecha->getMes()){
            if(this->dia > _fecha->getDia()){
                return true;
            }
        }
    }
    return false;
};

bool Date::operator==(Date* _fecha){
    if(this->anio == _fecha->getAnio() && this->mes == _fecha->getMes() && this->dia == _fecha->getDia()){
        return true;
    }
    return false;
};

bool Date::operator!=(Date* _fecha){
    if(this->anio != _fecha->getAnio() || this->mes != _fecha->getMes() || this->dia != _fecha->getDia()){
        return true;
    }
    return false;
};

bool Date::operator<=(Date* _fecha){
    if(this->anio < _fecha->getAnio()){
        return true;
    }else if(this->anio == _fecha->getAnio()){
        if(this->mes < _fecha->getMes()){
            return true;
        }else if(this->mes == _fecha->getMes()){
            if(this->dia <= _fecha->getDia()){
                return true;
            }
        }
    }
    return false;
};

bool Date::operator>=(Date* _fecha){
    if(this->anio > _fecha->getAnio()){
        return true;
    }else if(this->anio == _fecha->getAnio()){
        if(this->mes > _fecha->getMes()){
            return true;
        }else if(this->mes == _fecha->getMes()){
            if(this->dia >= _fecha->getDia()){
                return true;
            }
        }
    }
    return false;
};

