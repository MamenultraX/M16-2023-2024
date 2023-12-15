#include <iostream>
#include<time.h>

using namespace std;


//character stats
int characterHP = 500;
int characterAtkSword;
int characterAtkMagic;
int characterAtkPunch;
int characterManaCounter = 3;
string characterName;
bool characterIsAlive = true;


//boss stats
int bossHP = 200;
int bossDamage;
string bossName = "Boss1";


//boss2 stats
int boss2HP = 200;
int boss2Damage;
string boss2Name = "Boss2";

//Funcion introduce name
void introCharacterName() {
    cout << "Escribe el nombre de tu heroe\n";
    cin >> characterName;
}

//Select boss to attack
int bossSelect;
int attackSelect;
int bosSelection() {
    int numberBoss;
    cout << "A quien atacas?\n1. " << bossName << "\n2. " << boss2Name << "\n";
    cin >> numberBoss;
    system("cls");
    return numberBoss;
}

//Boss attacks
void atkBoss1() {
    if (bossHP > 0 && characterIsAlive)
    {
        characterHP = characterHP - bossDamage;
        cout << bossName << " te esta atacando y te ha hecho " << bossDamage << " de daño\n";
        cout << "Te queda " << characterHP << " de vida.\n";

        if (characterHP < 0)
        {
            characterIsAlive = false;
        }

        system("pause");
        system("cls");
    }
}

void atkBoss2() {
    if (boss2HP > 0 && characterIsAlive)
    {
        characterHP = characterHP - boss2Damage;
        cout << boss2Name << " te esta atacando y te ha hecho " << boss2Damage << " de daño\n";
        cout << "Te queda " << characterHP << " de vida.\n";

        if (characterHP < 0)
        {
            characterIsAlive = false;
        }

        system("pause");
        system("cls");
    }
}

void attackSelection() {
    cout << "Elije tu ataque\n1. Espada\n2. Magia\n3. Puñetazo\n";
    cin >> attackSelect;
    system("cls");
    
}

int main() {

    srand(time(NULL));

    //enter your name
    introCharacterName();
    int critico;


    // system("pause");
    system("cls");



    while ((bossHP > 0 || boss2HP > 0) && characterHP > 0) {


        //attacks 
        characterAtkSword = rand() % 11 + 20;
        characterAtkMagic = rand() % 6 + 40;
        characterAtkPunch = rand() % 11 + 5;
        bossDamage = rand() % 21 + 15;
        boss2Damage = rand() % 16 + 20;

        

        bossSelect = bosSelection();


        system("cls");
        if (bossSelect == 1)
        {

            if (bossHP <= 0)
            {
                cout << "Este jefe ya esta muerto\n";

                system("cls");
            }

            else if (bossHP > 0)
            {

                attackSelection();

                if (attackSelect == 1)
                {
                    bossHP = bossHP - characterAtkSword;
                    cout << "Has usado espada y has hecho " << characterAtkSword << " a " << bossName << " le queda " << bossHP << " HP\n";
                    system("pause");
                    system("cls");
                }

                else if (attackSelect == 2 && characterManaCounter > 0)
                {
                    bossHP = bossHP - characterAtkMagic;
                    characterManaCounter = characterManaCounter - 1;
                    cout << "Has usado magia y has hecho " << characterAtkMagic << " a " << bossName << " le queda " << bossHP << " HP\n" << "Te queda " << characterManaCounter << " de mana\n";
                    system("pause");
                    system("cls");
                }

                else if (attackSelect == 3)
                {
                    bossHP = bossHP - characterAtkPunch;
                    cout << "has usado puñetazo y has hecho " << characterAtkPunch << " a " << bossName << " le queda " << bossHP << " HP\n";
                    system("pause");
                    system("cls");
                }

                else
                {
                    cout << "No tienes mana\n";
                    system("cls");
                }
            }


        }

        if (bossSelect == 2)
        {
            if (boss2HP <= 0)
            {
                cout << "Este jefe ya esta muerto\n";

                system("cls");
            }

            else if (boss2HP > 0)
            {
                attackSelection();

                if (attackSelect == 1)
                {
                    boss2HP = boss2HP - characterAtkSword;
                    cout << "Has usado espada y has hecho " << characterAtkSword << " a " << boss2Name << " le queda " << boss2HP << " HP\n";
                    system("pause");
                    system("cls");
                }

                else if (attackSelect == 2 && characterManaCounter > 0)
                {
                    boss2HP = boss2HP - characterAtkMagic;
                    characterManaCounter = characterManaCounter - 1;
                    cout << "Has usado magia y has hecho " << characterAtkMagic << " a " << boss2Name << " le queda " << boss2HP << " HP\n" << "Te queda " << characterManaCounter << " de mana\n";
                    system("pause");
                    system("cls");
                }

                else if (attackSelect == 3)
                {
                    boss2HP = boss2HP - characterAtkPunch;
                    cout << "has usado puñetazo y has hecho " << characterAtkPunch << " a " << boss2Name << " le queda " << boss2HP << " HP\n";
                    system("pause");
                    system("cls");
                }
            }
        }

        atkBoss1();

        atkBoss2();

    }
    if (characterHP > 0)
    {
        cout << "----> VICTORIA <----\n" << "Has derrotado a los enemigos";
    }
    else if (bossHP > 0 && boss2HP < 0)
    {
        cout << "----> DERROTA <----\n" << bossName << " te ha derrotado";
    }

    else if (boss2HP > 0 && bossHP < 0)
    {
        cout << "----> DERROTA <----\n" << boss2Name << " te ha derrotado";
    }

    else if (boss2HP > 0 && bossHP > 0)
    {
        cout << "----> DERROTA <----\n" << "Te han derrotado los dos, no has matao ni uno";
    }

}







