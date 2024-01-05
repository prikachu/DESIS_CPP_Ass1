#include <bits/stdc++.h>
using namespace std;

#include "ship.cpp"

class player
{
    char grid[11][11];
    int unattacked[5] = {0};     // stores the no of unattacked blocks for each ship
    pair<int, int> loc[5]; // stores the starting point location of each ship
    bool dir[5];           // stores orientation of ship (1-horizontal, 0-vertical)

public:
    player()
    {
        for (int i = 0; i < 11; i++)
        {
            for (int j = 0; j < 11; j++)
            {
                grid[i][j] = '.';
            }
        }
        grid[0][0] = ' ';

        for (int i = 1; i < 11; i++)
        {
            grid[i][0] = 48 + i;
            grid[0][i] = i + 'A' - 1;
        }
    }

    int *get_unattacked() { return unattacked; }
    pair<int, int> *get_loc() { return loc; }

    void const print_grid ()
    {
        for (int i = 0; i < 10; i++)
        {
            cout << ' ';
            for (int j = 0; j < 11; j++)
            {
                cout << grid[i][j] << "  ";
            }
            cout << endl;
        }
        cout << 10 << "  ";
        for (int i = 1; i < 11; i++)
        {
            cout << grid[10][i] << "  ";
        }
        cout << endl;
    }

    void const print_guessgrid()
    {
        for (int i = 0; i < 10; i++)
        {
            cout << ' ';
            for (int j = 0; j < 11; j++)
            {
                if (grid[i][j] < 'A' || grid[i][j] > 'E' || i == 0)
                    cout << grid[i][j] << "  ";
                else
                    cout << '.' << "  ";
            }
            cout << endl;
        }
        cout << 10 << "  ";
        for (int i = 1; i < 11; i++)
        {
            if (grid[10][i] < 'A' || grid[10][i] > 'E')
                cout << grid[10][i] << "  ";
            else
                cout << '.' << "  ";
        }
        cout << endl;
    }

    void add_ship(ship ship)
    {
        cout << "Name of ship    : " << ship.get_name() << endl;
        cout << "Spaces required : " << ship.get_length() << endl;
        string s, e;
        cout << "Enter starting block : ";
        cin >> s;
        cout << "Enter ending block   : ";
        cin >> e;
        
        if (s.size()<2 || s.size()>3 || e.size()<2 || e.size()>3){
            cout<<"####################################################"<<endl;
            cout << "ERROR : Invalid input" << endl;
            cout<<"####################################################"<<endl;
            add_ship(ship);
            return;
        }

        if (!(s[0] == e[0] || s[1] == e[1]))
        {   cout<<"####################################################"<<endl;
            cout << "ERROR : Can't place ship diagonally" << endl;
            cout<<"####################################################"<<endl;
            add_ship(ship);
            return;
        }

        if (s[0] < 'A' || s[0] > 'J' || e[0] < 'A' || e[0] > 'J')
        {
            
            cout<<"####################################################"<<endl;
            cout << "ERROR : Invalid input" << endl;
            cout<<"####################################################"<<endl;
            add_ship(ship);
            return;
        }

        // vertical placement of ship
        if (s[0] == e[0])
        {
            int s1, e1;
            if (s.size() == 2)
                s1 = s[1] - '0';
            else if (s[2] != '0')
            {   
                
            cout<<"####################################################"<<endl;
            cout << "ERROR : Invalid input" << endl;
            cout<<"####################################################"<<endl;
                add_ship(ship);
                return;
            }
            else
                s1 = 10;

            if (e.size() == 2)
                e1 = e[1] - '0';
            else if (e[2] != '0')
            {
            cout<<"####################################################"<<endl;
            cout << "ERROR : Invalid input" << endl;
            cout<<"####################################################"<<endl;
                add_ship(ship);
                return;
            }
            else
                e1 = 10;

            int col = s[0] - 'A' + 1; // col no in the matrix

            if (abs(s1 - e1) != ship.get_length() - 1)
            {
                
                cout<<"####################################################"<<endl;
            cout << "ERROR : Start-end point distance is not equal to ship length" << endl;
            cout<<"####################################################"<<endl;
                add_ship(ship);
                return;
            }

            for (int i = min(s1, e1); i <= max(s1, e1); i++)
            {
                if (grid[i][col] != '.')
                {   
                    cout<<"####################################################"<<endl;
            cout << "ERROR : Place already occupied" << endl;
            cout<<"####################################################"<<endl;
                    
                    add_ship(ship);
                    return;
                }
            }
            for (int i = min(s1, e1); i <= max(s1, e1); i++)
            {
                grid[i][col] = ship.get_id();
            }
            int ind = ship.get_id() - 'A';
            loc[ind] = {col, min(s1, e1)};
            dir[ind] = 0; // vertical
            unattacked[ind] = 5-ind; 
        }

        else
        {
            int s1 = s[0] - 'A' + 1;
            int e1 = e[0] - 'A' + 1;

            int k;
            if (s.size() == 2)
                k = s[1] - '0';
            else if (s[2] == '0')
                k = 10;
            else
            {   
                cout<<"####################################################"<<endl;
            cout << "ERROR : Invalid output" << endl;
            cout<<"####################################################"<<endl;
                
                add_ship(ship);
                return;
            }

            if (abs(s1 - e1) != ship.get_length() - 1)
            {   cout<<"####################################################"<<endl;
            cout << "ERROR : Start-end point distance is not equal to ship length" << endl;
            cout<<"####################################################"<<endl;
                
                add_ship(ship);
                return;
            }

            for (int i = min(s1, e1); i <= max(s1, e1); i++)
            {
                if (grid[k][i] != '.')
                {cout<<"####################################################"<<endl;
            cout << "ERROR : Place already occupied" << endl;
            cout<<"####################################################"<<endl;
                    
                    add_ship(ship);
                    return;
                }
            }

            for (int i = min(s1, e1); i <= max(s1, e1); i++)
            {
                grid[k][i] = ship.get_id();
            }
            
            int ind = ship.get_id() - 'A';
            unattacked[ind] = 5-ind; 
            loc[ind] = {min(s1, e1), k};
            dir[ind] = 1; // dir 1 signifies horizontal alignment
        }
    }

    void del_ship(ship ship)
    {
        int s = ship.get_id() - 'A';
        if (dir[s])
        {
            for (int i = 0; i < ship.get_length(); i++)
            {
                grid[loc[s].second][loc[s].first + i] = '.';
            }
        }
        else
        {
            for (int i = 0; i < ship.get_length(); i++)
            {
                grid[loc[s].second + i][loc[s].first] = '.';
            }
        }
        loc[s] = {0, 0};
        unattacked[s] = 0;
    }

    void clr_grid()
    {
        for (int i = 1; i < 11; i++)
        {
            for (int j = 1; j < 11; j++)
            {
                grid[i][j] = '.';
            }
        }
        cout << "Grid Cleared" << endl;
        for (int i = 0;i<5;i++){
            loc[i] = {0,0};
            unattacked[i] = 0;
        }
    }

    void sunk(ship s)
    {
        cout << "Ship " << s.get_name() << " has sunk" << endl;
        int k = s.get_id() - 'A';
        for (int i = 0; i < s.get_length(); i++)
        {
            if (dir[5 - s.get_length()])
            {
                grid[loc[k].second][loc[k].first + i] = s.get_length() + '0';
            }
            else
            {
                grid[loc[k].second + i][loc[k].first] = s.get_length() + '0';
            }
        }
    }

    void guessbyopponent(string b)
    {
        if (b[0] < 'A' || b[0] > 'J' || b[1] < '1' || b[1] > '9' || b.size()>3 || b.size()<2)
        {   
            cout<<"######################################################"<<endl;
            cout << "Invalid input... Re-enter : ";
            cin >> b;
            guessbyopponent(b);
            return;
        }
        int r;
        
        if (b.size() == 2)
            r = b[1] - '0';
        else if (b[2]!='0'){
            cout<<"######################################################"<<endl;
            cout << "Invalid input... Re-enter : ";
            cin >> b;
            guessbyopponent(b);
            return;
        }
        else r = 10;
            

        int c = b[0] - 'A' + 1;

        if (grid[r][c] >= 'A' && grid[r][c] <= 'E')
        {

            cout << "It's a hit" << endl;

            int s = grid[r][c] - 'A';
            unattacked[s]--;
            grid[r][c] = 'H';

            if (unattacked[s] == 0)
            {
                sunk(h[s]);
            }
            return;
        }

        cout << "It's a miss" << endl;
        if (grid[r][c] == '.')
            grid[r][c] = '*'; // Handling the case of repeated guesses on one block.
    }
};