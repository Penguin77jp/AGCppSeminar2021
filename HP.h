#pragma once

class HP {
private:
    int hitpoint;
public:
    HP() : hitpoint(0) {}
    HP(int hitpoint) : hitpoint(hitpoint) {}
    HP(const HP& hp) {
        hitpoint = hp.hitpoint;
    }
    int Damaged(int damage) {
        hitpoint -= damage;
        return hitpoint;
    }
    //getter
    int GetHP() const { return hitpoint; }


};