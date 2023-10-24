#include <iostream>
#include <string>
#include <Windows.h>
#include <algorithm>
#include <random>

using namespace std;

class character{
private:
    string name;
    string race;
    string char_class;
    float exp;
    int level;

public:
    void setName(const string& newName)
    {
        name = newName;
    }

    string getName() const
    {
        return name;
    }

    void setRace(const string& newRace)
    {
        race = newRace;
    }

    string getRace() const
    {
        return race;
    }

    void setCharClass(const string& newCharClass)
    {
        char_class = newCharClass;
    }

    string getCharClass() const
    {
        return char_class;
    }
    void setCharLevel(const int& newCharLevel)
    {
        level = newCharLevel;
    }
    int getCharLevel() const
    {
        return level;
    }
};

class enemy{
private:
    string enemy_name;
    int enemy_level, baselevel;
    float enemy_damage,earned_xp,enemy_health;

public:
    void setEnemyName(const string& newEnemy_Name)
    {
        enemy_name = newEnemy_Name;
    }
    string getEnemyName() const
    {
        return enemy_name;
    }

    void setEnemyLevel(const int& newEnemy_Level)
    {
        enemy_level = newEnemy_Level;
    }
    int getEnemyLevel() const
    {
        return enemy_level;
    }

    void setEnemyDamage(const float& newEnemy_Damage)
    {
        enemy_damage = newEnemy_Damage;
    }
    float getEnemyDamage() const
    {
        return enemy_damage;
    }
    void setEnemyHealth(const float& newEnemy_Health)
    {
        enemy_health = newEnemy_Health;
    }
    float getEnemyHealth() const
    {
        return enemy_health;
    }
};

class weapon{
private:
    string weapon_name;
    float weapon_damage;

public:
    void setWeaponName (const string& NewWeaponName)
    {
        weapon_name = NewWeaponName;
    }
    string getWeaponName() const
    {
        return weapon_name;
    }
    void setWeaponDamage (const float& NewWeaponDamage)
    {
        weapon_damage = NewWeaponDamage;
    }
    float getWeaponDamage() const
    {
        return weapon_damage;
    }
};

int main()
{
    int dungeon_level,enemy_level;
    bool pass;
    string classlist[] = {"���", "����", "������"};
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    cout << "�� ������� � ���� ���� ���" << endl;
    cout << "����������� 'AsagiriXds'" << endl;
    string word;

k:
    do {
        cout << "�������� ����� ����:\n-������\n-���������\n-�����" << endl;
        cin >> word;

        if (word == "������") {
            cout << "�� ������� - ������" << endl;
            cout << "������� ���������? (��/���)" << endl;
            string answer;
            cin >> answer;

            if (answer == "��") {
                cout << "�������� �������������� ���������" << endl;
                character myCharacter;
                string name, race, charClass;

                cout << "������� ��� ���������: ";
                cin >> name;
                myCharacter.setName(name);

                cout << "������� ���� ���������: ";
                cin >> race;
                myCharacter.setRace(race);

                do {
                    cout << "�������� ����� ��������� (���, ����, ������): ";
                    cin >> charClass;
                    myCharacter.setCharClass(charClass);

                    if (find(classlist, classlist + 3, charClass) != classlist + 3) {
                        cout << "��� ���������: " << myCharacter.getName() << endl;
                        cout << "���� ���������: " << myCharacter.getRace() << endl;
                        cout << "����� ���������: " << myCharacter.getCharClass() << endl;
                        pass = true;
                        dungeon_level = 1;
                    }
                    else {
                        cout << "������������ ����� ���������" << endl;
                        pass = false;
                    }
                } while (!pass);
            }
            if (pass) {
                string action;
                float EnemyHealthFormula,WeaponDamageFormula;
                int level;
                WeaponDamageFormula = level + 3;
                EnemyHealthFormula = (enemy_level + dungeon_level);
                cout << "�� �� "<<dungeon_level<<" ����� ����������"<<endl;
                enemy newEnemy;
                string enemy_name[] = {"�����", "������", "�����"};
                int enemy_count = sizeof(enemy_name) / sizeof(enemy_name[0]);
                random_device rd;
                mt19937 generator(rd());
                uniform_int_distribution<int> distribution(0, enemy_count - 1);
                int random_index = distribution(generator);
                cout << "��� ��������� - " << enemy_name[random_index] << endl;
                newEnemy.setEnemyLevel(dungeon_level);
                cout << "��� ������� - " << newEnemy.getEnemyLevel() <<endl;
                newEnemy.setEnemyHealth(EnemyHealthFormula);
                cout << "���������� �� - "<<newEnemy.getEnemyHealth()<<endl;
                dungeon_level++;
                cin >> action;
                weapon MyWeapon;
                MyWeapon.setWeaponDamage(WeaponDamageFormula);
                if (action == "����")
                {
                    cout <<"��� ���� "<<MyWeapon.getWeaponDamage()<<endl;
                }
                else if (action == "�������")
                {
                    ::ExitProcess(0);
                }

            }
            else {
                cout << "Cheater" << endl;
        }
        }
        else if (word == "���������") {
            cout << "�� ������� - ���������" << endl;
            goto k;
        }
        else if (word == "�����") {
            break;
        }
        else if (word == "asagiri"){
            cout <<"� ����� �� ��� �������????"<<endl;
            goto k;
        }
        else {
            cout << "������������ �����" << endl;
        }
    } while (true);

    return 0;
}
