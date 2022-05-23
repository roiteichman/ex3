//
// Created by teich on 23/05/2022.
//

#ifndef EX3_HEALTHPOINTS_H
#define EX3_HEALTHPOINTS_H
#include <ostream>
using std::ostream;
const int STARTING_HP = 100;

class HealthPoints {
public:
    /*
     * C'tor of HealthPoints class
     *
     * @param hp - the current and max hp.
     * @return
     *      A new instance of HealthPoints
    */
    explicit HealthPoints(int hp = STARTING_HP);



    /*
     * Operator + increase the argument passed to the amount of hp the player had
     *
     * @param int hp - the amount will increase to the hp
     * @return
     *      HealthPoints object after increasing
    */
    HealthPoints operator+(const int hp) const;

    /*
     * Operator - decrease the argument passed to the amount of hp the player had
     *
     * @param int hp - the amount will decrease from the hp
     * @return
     *      HealthPoints object after decreasing
    */
    HealthPoints operator-(const int hp) const;


    /*
     * Operator + increase the argument passed to the amount of hp the player had
     *
     * @param int hp - the amount will increase to the hp
     * @return
     *      this
    */
    HealthPoints& operator+=(const int hp);

    /*
    * Operator - decrease the argument passed to the amount of hp the player had
     *
     * @param int hp - the amount will decrease from the hp
     * @return
     *      this
    */
    HealthPoints& operator-=(const int hp) const;

    /*
     * Operator == compare between two HealthPoints
     *
     * @param HealthPoints
     * @return
     *      true - if this_hp == other_hp
     *      false - if this_hp != other_hp
     *
    */
    friend bool operator==(const HealthPoints other_hp) const;

    /*
     * Operator !=
     *
     * @param HealthPoints
     * @return
     *      true - if this_hp != other_hp
     *      false - if this_hp == other_hp
    */
    bool operator!=(const HealthPoints other_hp) const;

    /*
     * Operator <=
     *
     * @param HealthPoints
     * @return
     *      true - if this_hp <= other_hp
     *      false - if this_hp > other_hp
    */
    bool operator<=(const HealthPoints other_hp) const;

    /*
     * Operator <
     *
     * @param HealthPoints
     * @return
     *      true - if this_hp < other_hp
     *      false - if this_hp >= other_hp
    */
    bool operator<(const HealthPoints other_hp) const;

    /*
     * Operator >=
     *
     * @param HealthPoints
     * @return
     *      true - if this_hp >= other_hp
     *      false - if this_hp < other_hp
    */
    bool operator>=(const HealthPoints other_hp) const;


    /*
     * Operator >
     *
     * @param HealthPoints
     * @return
     *      true - if this_hp > other_hp
     *      false - if this_hp <= other_hp
    */
    bool operator>(const HealthPoints other_hp) const;


    /*
     * Operator << for ostream
     *
     * @param ostream type
     * @param hp - to send to ostream
     * @return
     *      ostream after changes
    */
    friend ostream& operator<<(std::ostream&, const HealthPoints& hp);

    class InvalidArgument {};

private:
    int m_hp;
    const int m_max_hp;
};

#endif //EX3_HEALTHPOINTS_H
