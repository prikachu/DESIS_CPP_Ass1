#include <bits/stdc++.h>
using namespace std;
#include "player.cpp"

void place_ship(player &p)
{
    p.print_grid();
    cout << "Choose ship to add" << endl;
    pair<int, int> *loc = p.get_loc();
    bool flag = false;
    for (int i = 0; i < 5; i++)
    {
        if (loc[i].first == 0)
        {flag = true;
            cout << h[i].get_id() - 'A' + 1 << ". " << h[i].get_name() << '(' << h[i].get_length() << " spaces)" << endl;
        }
    }
    if (!flag){
        cout<<"ERROR : No ship to add"<<endl;return;
    }
    string ch;
    cin >> ch;
    if (ch < "1" || ch > "5")
    {   
        cout<<"###################################################"<<endl;
        cout << "Invalid input" << endl;
        cout<<"###################################################"<<endl;
        place_ship(p);
        return;
    }
    int s = stoi(ch);
    if (loc[s - 1].first != 0)
    {   cout<<"###################################################"<<endl;
        cout << "Ship not available for adding!" << endl;
        cout<<"###################################################"<<endl;
        place_ship(p);
        return;
    }
    p.add_ship(h[s - 1]);
    p.print_grid();
    cout << "Ship added successfully" << endl;
}

void remove_ship(player &p)
{
    p.print_grid();
    cout << "Choose ship to remove" << endl;
    pair<int, int> *loc = p.get_loc();
    bool flag = false;
    for (int i = 0; i < 5; i++)
    {
        if (loc[i].first != 0)
        {   flag = true;
            cout << h[i].get_id() - 'A' + 1 << ". " << h[i].get_name() << '(' << h[i].get_length() << " spaces)" << endl;
        }
    }
    if (!flag){cout<<"ERROR : No ship to remove"<<endl;return;}
    string s;
    cin >> s;

    if (s < "1" || s > "5")
    {   cout<<"###################################################"<<endl;
        cout << "Invalid input" << endl;
        cout<<"###################################################"<<endl;
        remove_ship(p);
        return;
    }
    int s1 = stoi(s);
    if (loc[s1 - 1].first == 0)
    {   cout<<"###################################################"<<endl;
        cout << "Ship not available for deletion!" << endl;
        cout<<"###################################################"<<endl;
        return;
    }
    p.del_ship(h[s1 - 1]);
    p.print_grid();
    cout << "Ship deleted successfully" << endl;
    cout<<"____________________________________________________________"<<endl;
}

void planning_phase(player &p1)
{
    
    while (true)
    {   cout<<endl;
        cout << "--------------------------------------------------------------" << endl;
        cout<<"++++CHOOSE ACTION++++"<<endl;
        cout << "1. Place a ship" << endl;
        cout << "2. Remove a ship" << endl;
        cout << "3. Delete all ships" << endl;
        cout << "4. End planning phase" << endl;
        cout << "Enter choice: ";
        string ch;cin >> ch;

        if (ch == "1")
        {
            place_ship(p1);
            continue;
        }
        else if (ch == "2")
        {
            remove_ship(p1);
            continue;
        }
        else if (ch == "3")
        {
            p1.clr_grid();
            continue;
        }
        else if (ch == "4")
        {
            pair<int, int> *loc = p1.get_loc();
            bool flag = false;
            for (int i = 0; i < 5; i++)
            {
                if (loc[i].first == 0)
                {
                    flag = true;
                    break;
                }
            }
            if (flag)
            {
                cout << "You have not placed all ships. Are you sure you want to end planning phase?" << endl;
                cout << "(Press 1 for yes; anything else for no) : ";
                string a;
                cin >> a;
                if (a == "1")
                {
                    break;
                }
                else
                {
                    continue;
                }
            }
            else
            {
                continue;
            }
        }

        else
        {   cout<<"*********************************"<<endl;
            cout << "Please enter valid choice" << endl;
            cout<<"*********************************"<<endl;
            continue;
        }
    }

    cout << "--------------------------------------------------------------" << endl;
    cout << "Your grid after placing all 5 ships is --" << endl;
    p1.print_grid();
    cout << "--------------------------------------------------------------" << endl;
}

void print_filler()
{
    cout << "Maharishi Vedvyas  was the first priest who recited the great Mahabharat.It is said that Bhagwan Shri Ganesha wrote the whole thing under the premise that Maharishi Vedvyas must continually repeat the shlokas which need to be transcribed without pausing for a moment." << endl
         << "It was said that Ganesha needed to write the Mahabharata in a way explaining all the meanings of the slokas, which was time-consuming, so the priest Ved Vyas had time to pause while reciting the shlokas while Ganesha wrote the whole thing." << endl
         << "It is said that the Mahabharata is seven times longer than that of the odyssey and the Iliad. It has over 2,00,000 verses written throughout the Mahabharata poem." << endl
         << "The story mentions the battle of both the families in a place called Kurukshetra, which is situated in north Delhi, Haryana." << endl
         << "The Mahabharata mentions the birth of Lord Vishnu in a human form named Krishna, who led the Pandavas to their victory." << endl
         << "Kunti was given a wish of being granted a child when she wished for it by any god, after serving in taking care of the rishi, Durvasa." << endl
         << "The epic of Mahabharata is told in the ancient tongue of India called Sanskrit, which makes it even more historical and intrinsic to the culture of India." << endl
         << "Shri Krishna didn't fight in the war. Instead, he was a part of both sides." << endl
         << "The kuru side of the family took the Narayani troops of Krishna, and Krishna himself was part of the other family, the Pandavas." << endl
         << "Krishna was cursed by the queen Gandhari as she thought that Krishna was responsible for the great war between the families." << endl
         << "Yudhistira, the elder of the Pandavas side, mentioned if any of the kuru brothers may side with them in the war and only one brother out of the 100 took the Pandavas side." << endl
         << "Arjuna was a eunuch as per the tales as he was cursed by Urvashi. Later in the epic, Arjuna used that to his advantage." << endl
         << "Gandhari wasn't blind and decided to cover her eyes because of her husband, who was blind." << endl
         << "The decision to remain blind helped her gain the power of using her sight to make anyone impenetrable." << endl
         << "Gandhari's son was asked to come naked, so the eyesight would make the whole body impenetrable, but he wore a cloth around his pelvis, which remained vulnerable throughout his fight with Bheema." << endl
         << "The kuru side had 100 brothers and only one sister. She was married to a man named Jayadratha, who was killed by Arjuna." << endl
         << "Karna, who was a son of Kunti, was cursed by the rishi parshuram because he hid his actual identity." << endl
         << "The kingdom of Hastinapura was famous for its large number of elephant armies, so it was called Hastinapura." << endl
         << "With the help of a weapon gifted by Indra, Karna killed Gathotkatch." << endl
         << "Sahadev was an astrologer who had knowledge of the future but was cursed that if he revealed the future, he would die." << endl
         << "Karna was abandoned by his birth mother, Kunti, and he was born with armour and earrings attached to him." << endl
         << "The Pandavas were in hiding for about 13years." << endl
         << "Pandavas started their journey to heaven after the death of Krishna." << endl
         << "After Pandavas went to heaven, the son of Abhimanyu was king of the empire." << endl
         << "Abhimanyu was the birth son of Arjuna, who was killed in the great war." << endl
         << endl
         << "Text taken from unacademy.com" << endl;
}

void play(player p1, player p2)
{
    cout << "Player 1 : Your planning phase starts!!" << endl;
    planning_phase(p1);

    cout << "Player 1 : Your planning phase has ended!!" << endl;

    // In order to hide players' grid we will print some text
    print_filler();

    cout << "==============================================================" << endl;

    cout << "Player 2 : Your planning phase starts!!" << endl;
    planning_phase(p2);
    cout << "Player 2 : Your planning phase has ended!!" << endl;

    print_filler();

    cout << "==============================================================" << endl;

    cout << "Now let's begin guessing!!" << endl;
    cout << "Enter your guesses in the following format" << endl;
    cout << "A1 | J10" << endl;

    while (true)
    {
        cout << "Player 1's guess : ";
        string g;
        cin >> g;
        p2.guessbyopponent(g);
        p2.print_guessgrid();
        if (count(p2.get_unattacked(), p2.get_unattacked() + 5, 0) == 5)
        {
            cout << "All ships of player 2 sunk." << endl;
            cout << "Player 1 wins!!" << endl;
            cout << "Game over" << endl;
            break;
        }

        cout << "Player 2's guess : ";
        cin >> g;
        p1.guessbyopponent(g);
        p1.print_guessgrid();
        if (count(p1.get_unattacked(), p1.get_unattacked() + 5, 0) == 5)
        {
            cout << "All ships of player 1 sunk." << endl;
            cout << "Player 2 wins!!" << endl;
            cout << "Game over" << endl;
            break;
        }
    }
}

int main()
{
    cout << "Welcome to game Battleship" << endl;
    cout << "--------------------------------------------------------------" << endl;

    player p1;
    player p2;
    p1 = player();
    p2 = player();

    while (true)
    {
        
        play(p1, p2);
        cout << "________________________________________________________________" << endl;
        cout << "Enter\n1 - Play again\nAnything else - Exit" << endl;
        string n;
        cin >> n;
        if (n == "1")
            continue;
        else
        {
            cout << "Thank you for playing the game!!" << endl;
            break;
        }
    }
}