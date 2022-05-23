//
// Created by teich on 23/05/2022.
//

#include "HealthPoints.h"

HealthPoints::HealthPoints(int hp):
m_hp(hp),
m_max_hp(hp)
{
    if(hp<=0){
        throw InvalidArgument();
    }
}

HealthPoints& HealthPoints::operator+=(const int hp)
{
    if (m_hp+hp<=m_max_hp){
        m_hp+=hp;
    }
    else{
        m_hp=m_max_hp;
    }
    return *this;
}


HealthPoints HealthPoints::operator+(const int hp) const
{
    if (m_hp+hp <= m_max_hp){
        HealthPoints result(*this);
        return  (result += hp);
    }
    else{
        return HealthPoints(m_max_hp);
    }
}

HealthPoints& HealthPoints::operator-=(const int hp)
{
    if (m_hp-hp>0){
        m_hp-=hp;
    }
    else{
        m_hp=0;
    }
    return *this;
}

HealthPoints HealthPoints::operator-(const int hp) const
{
    if (m_hp-hp > 0){
        HealthPoints result(*this);
        return  (result -= hp);
    }
    else{
        return HealthPoints(0);
    }
}

bool HealthPoints::operator>=(const HealthPoints other_hp) const
{
    return other_hp <= *this;
}

bool HealthPoints::operator>(const HealthPoints other_hp) const
{
    return *this<other_hp;
}

bool operator==(const HealthPoints hp, const HealthPoints other_hp)
{
    return hp.m_hp==other_hp.m_hp;
}

bool operator<(const HealthPoints hp, const HealthPoints other_hp)
{
    return hp.m_hp<other_hp.m_hp;
}

ostream& operator<<(std::ostream& os, const HealthPoints& hp)
{
    os << hp.m_hp << "(" << hp.m_max_hp<< ")"<< std::endl;
}

bool HealthPoints::operator!=(const HealthPoints other_hp) const
{
    return !(*this == other_hp);
}

bool HealthPoints::operator<=(const HealthPoints other_hp) const
{
    return !(other_hp < *this);
}



