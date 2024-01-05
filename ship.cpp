#include <bits/stdc++.h>
using namespace std;

class ship
{
    string name = "prachithegreat";
    int length;
    char id;

public:
    ship(string n, int l, char i)
    {
        name = n;
        length = l;
        id = i;
    }
    string get_name() { return name; }
    int get_length() { return length; }
    char get_id() { return id; }
};

ship A = ship("Aircraft Carrier", 5, 'A');
ship B = ship("Battleship", 4, 'B');
ship C = ship("Destroyer", 3, 'C');
ship D = ship("Corvette", 2, 'D');
ship E = ship("Frigate", 1, 'E');

ship h[5] = {A, B, C, D, E};