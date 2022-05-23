//
// Created by teich on 23/05/2022.
//

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

}






bool operator<(const HealthPoints hp) const
{
    return m_hp>other_hp.
}