#include <iostream>
#include <cstring>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include "Inventory.h"
#include "Monster.h"
#include "Goblin.h"
#include "Orc.h"
#include "Slime.h"
#include "Troll.h"
#include "Drake.h"
#include "Ghoul.h"
#include "Hydra.h"
#include "Skeleton.h"

using namespace std;


// ���� �Լ�
int main(void)
{
    srand(static_cast<unsigned int>(time(nullptr))); // ���� ����

    char name[20];
    bool hasSpace = true;
    int money = 0;

    Inventory inv;
    string item = "������";
    int price = 0;
    int count = 0;
    string itemType = "��Ÿ";

    cout << "------[unkindRPG]------" << endl;
    cout << "\n[ ����� �̸��� �Է����ּ��� ]" << endl;

    while (hasSpace) // �Է¹��� �̸��� ������ �ִ��� üũ
    {
        cin.getline(name, 20);
        int namelen = strlen(name);

        for (int i = namelen; i >= 0; i--)
        {
            if (name[i] == ' ')
            {
                hasSpace = true;
                break;
            }
            else
            {
                hasSpace = false;
            }
        }

        if (strlen(name) == 0) // �ƹ��͵� �Է����� ���� �͵� ���� �� �� ����
        {
            hasSpace = true;
        }

        if (hasSpace)
        {
            cout << "\n�ٽ� �Է����ּ���";
            cout << "\n!!!�̸����� ������ �� �� �����ϴ�!!!" << endl;
        }
        else
        {
            cout << "\n�ݰ����ϴ� " << name << "��!" << endl;

        }
    } // �̸� ���� ����

    string CharacterName = name; // ĳ���� �̸�
    int CharacterLevel = 1; // ĳ���� ����
    int CharacterMaxhp = 300; // ĳ���� �ִ� ü��
    int CharacterHp = 300; // ĳ���� ���� ü��
    int CharacterPower = 50; // ĳ���� ���ݷ�
    int CharacterDefence = 0;// ĳ���� ����
    int CharacterExp = 0; // ĳ���� ����ġ
    string weapon = "����";
    int weaponOption = 0;
    string ammor = "����";
    int ammorOption = 0;

    // �ൿ �ݺ��ϱ�
    cout << "\n";
    string place = "����";
    char actionChoice;

    // ���� ���� ����
    int Monster_choice = 1 + rand() % 8; // �������� ���͸� ����

    Monster* monster = nullptr; // ����

    bool game = true;

    while (game)
    {
        cout << "\n\n<������ �Ͻðڽ��ϱ�?>" << endl;
        cout << "\n[ ���� ��ġ : " << place << " ]" << endl;
        cout << "\n[1] ���� ���" << endl;
        cout << "[2] ���� �̵�" << endl;
        cout << "[3] ���� ���� Ȯ��" << endl;
        cout << "[4] �κ��丮 Ȯ��" << endl;
        cout << "[5] ���� ���� \n" << endl;
        cin >> actionChoice;

        cout << "\n\n";


        switch (actionChoice)
        {
        case '1':
        {
            while (actionChoice == '1') // ���������� �ݺ�
            {
                string monsterName;
                int monsterMaxhp;
                int monsterHp;
                int monsterPower;
                string monsterCrying;

                Monster_choice = 1 + rand() % 8; // �������� ���͸� ����

                switch (Monster_choice)
                {
                case 1:
                    monster = new Goblin();
                    place = "���� �ܰ�";
                    monsterCrying = "\"Ű����!\"";
                    break;
                case 2:
                    monster = new Orc();
                    place = "���� �ܰ�";
                    monsterCrying = "\"�ٸ���..����...?\"";
                    break;
                case 3:
                    monster = new Slime();
                    place = "���� �ܰ�";
                    monsterCrying = "\"������......\"";
                    break;
                case 4:
                    monster = new Troll();
                    place = "��ο� ����";
                    monsterCrying = "\"ũ�;ƾƾ�!!!\"";
                    break;
                case 5:
                    monster = new Drake();
                    place = "��Ÿ�� ȭ��";
                    monsterCrying = "\"��ƾƾƾƾƾ�!!!!\"";
                    break;
                case 6:
                    monster = new Ghoul();
                    place = "��ο� ����";
                    monsterCrying = "\"�׿�����....\"";
                    break;
                case 7:                                                        
                    monster = new Hydra();
                    place = "��Ÿ�� ȭ��";
                    monsterCrying = "\"������....!...!...!\"";
                    break;
                case 8:
                    monster = new Skeleton();
                    place = "��ο� ����";
                    monsterCrying = "\"����...�����...��...!\"";
                    break;
                }

                monsterName = monster->getMonsterName(); // ���� �̸�
                monsterMaxhp = (monster->getMonsterMaxHp()) + (CharacterLevel * 10); // ���� �ִ� ü��
                monsterHp = monsterMaxhp; // ���� ���� ü��
                monsterPower = ((monster->getMonsterPower()) + (CharacterLevel * 2)); // ���� ���ݷ�

                int battleAction;
                bool battle = true;
                bool battleWin = true;
                bool battleLose = false;
                bool guard = false;
                bool battleChance = false;
                bool doping = false;
                int damage = 0;
                bool run = false;
                int battleTurn = 0;

                cout << monsterName << "����!!" << endl;
                


                while (battle)
                {
                    cout << "\n[ ������ �Ͻðڽ��ϱ�? ] [ ���� " << ++battleTurn << "�� ° ] [ ���� ��ġ : " << place << " ]" << endl;
                    cout << "\n[" << CharacterName << "HP : " << CharacterHp << "/" << CharacterMaxhp << "] [" << monsterName << "HP : " << monsterHp << "/" << monsterMaxhp << "]" << endl;
                    cout << "[1]���� / [2]��� / [3]�κ��丮 / [4]����" << endl;

                    cin >> battleAction;

                    switch (battleAction)
                    {
                        case 1 : // ����
                        {
                            // ����� ���� = �� ���ݷ��� -+10%
                            int sum = ((CharacterPower / 10) * 9) + rand() % (((CharacterPower / 10) * 11) - ((CharacterPower / 10) * 9));
                            cout << "���� �����ߴ�! / " << monsterName << "���� " << sum << "�� �����!" << endl;
                            monsterHp -= sum;
                            break;
                        }
                        case 2 : // ���
                        {
                            cout << "����¼��� �����ߴ�! / [ �̹��� �޴� ����� ���� ]" << endl;;
                            if (ammor == "����") // ������ ���� ��� ���� ���� ����
                            {
                                CharacterDefence = 20;
                            }
                            else // ������ �ִ� ��� ������ ���� ȿ�� �ι�
                            {
                                CharacterDefence *= 2;
                            }
                            guard = true;
                            break;
                        }
                        case 3 : // �κ��丮. / �κ��丮���� �ϴ� �ൿ���� ���� �Ҹ����� �ʴ´�.
                        {
                            int hpPotion = 0;
                            int atkPotion = 0;
                            battleChance = true;

                            tuple<int, int, string> hpInfo = inv.getItemInfo("ü������"); // ü�������� �ִ��� üũ
                            int sum1 = get<0>(hpInfo); // ����
                            if (sum1 > 0) // ü�������� �ִ� ��쿡 üũ
                            {
                                hpPotion = sum1;
                            }

                            tuple<int, int, string> atkInfo = inv.getItemInfo("���ǿ���"); // ���ǿ����� �ִ��� üũ
                            int sum2 = get<0>(atkInfo); // ����                          
                            if (sum2 > 0) // ���ǿ����� �ִ� ��쿡 üũ
                            {
                                atkPotion = sum2;
                            }

                            if (atkPotion == 0 && hpPotion == 0)
                            {
                                cout << "[ ����� �� �ִ� �������� ����! ]" << endl;
                            }
                            else
                            {
                                int j = 1;
                                cout << "������ ������!" << endl; // ü������, ���ǿ��� ���� �ϳ��� �ƿ� ���� ��� �ش� �������� ǥ������ �ʴ´�.
                                if (hpPotion > 0)
                                {
                                    cout << "[" << j++ << "] ü������ ��� / ";
                                }
                                if (atkPotion > 0)
                                {
                                    cout << "[" << j++ << "] ���ǿ��� ��� / ";
                                }
                                cout << "[" << j << "] ������� �ʴ´�" << endl;   

                                cin >> battleAction;

                                if (battleAction == 1)
                                {
                                    if (hpPotion > 0)
                                    {
                                        cout << "[ ü���� ȸ���˴ϴ� ]" << endl;
                                        cout << "[ HP 300 ȸ��! ]" << endl;
                                        CharacterHp += 300;
                                        inv.removeItem("ü������", 1);

                                        if (CharacterHp > CharacterMaxhp) // �ִ�ü�¿� �ٴٸ��� �ʰ����� ������ ���� ü���� �ִ�ü�¿� �����.
                                        {
                                            CharacterHp = CharacterMaxhp;
                                        }
                                        break;
                                    }
                                    else if (atkPotion > 0)
                                    {
                                        battleAction = 2;
                                    }
                                        
                                }
                                if (battleAction == 2)
                                {
                                    if (atkPotion > 0)
                                    {
                                        if (doping)
                                        {
                                            cout << "[ �̹� ���� ��ġ�� �����Դϴ� ]" << endl; //�̹� ���ǿ����� ����� ���¶�� �ٽ� ����� �� ����
                                        }
                                        else
                                        {
                                            CharacterPower += 50;
                                            cout << "[ ���� ���� �帨�ϴ�! ]" << endl;
                                            cout << "[ ���ݷ� 50 ����! ] [ ���� ���ݷ� : " << CharacterPower << " ]" << endl;
                                            doping = true;
                                            inv.removeItem("���ǿ���", 1);
                                        }
                                    }
                                }
                            }
                            break;                            
                        }
                        case 4:
                        {
                            cout << "[ �����Ͽ����ϴ�! ]" << endl;
                            run = true;
                            break;
                        }
                    }



                    if (battleChance)
                    {
                        // �ൿ�� ���� �ʾұ� ������ �ٽ� ���� ���� �ȴ�. �ϵ� �帣�� �ʴ´�.
                        battleTurn--;
                        battleChance = false;
                    }
                    else if (run)
                    {
                        battleWin = false; // ���ַ� ���� �й�. ��������� �ʴ´�.
                        battle = false;
                        battleLose = true;
                    }
                    else
                    {
                        // ���� ��
                        if (monsterHp >= 0) // ���� �̹� ���� ��� ������ �����Ѵ�.
                        {
                            int sum = ((monsterPower / 10) * 8) + rand() % (monsterPower - ((monsterPower / 10) * 8));
                            cout << "\n" << monsterName << "�� ����! / " << monsterCrying << endl;
                            damage = sum - CharacterDefence;

                            if (damage <= 0) // �� ������ �� ���� ���
                            {
                                cout << monsterName << "�� ������ ���� ������ �ʾҴ�!" << endl;
                                CharacterHp--; // �� ���� ���� ��쿡�� ��� ü���� 1�� �پ��
                            }
                            else 
                            {
                                cout << damage << "�� ������� �޾Ҵ�!" << endl;
                                CharacterHp -= damage;
                            }
                            
                            if (guard)
                            {
                                if (damage <= 0)
                                {
                                    cout << monsterName << "�� ������ �Ϻ��ϰ� ���Ƴ´�!" << endl;
                                    CharacterHp++; // �� �� ��� ü���� 1�� ���� ����. (������ �پ�� ü�� �ٽ� ����)
                                }
                                else
                                {
                                    cout << monsterName << "�� ������ ���Ƴ´�!" << endl;
                                }
                                
                            }
                            
                        }

                        // �� ����� ���
                        damage = 0;
                        battleAction = 0;

                        if (guard) // ��� ���� �� ���� ����
                        {
                            if (ammor == "����")
                            {
                                CharacterDefence = 0;
                            }
                            else
                            {
                                CharacterDefence /= 2;
                            }
                            guard = false;
                        }

                        if (CharacterHp <= 0) // ���� �й�
                        {
                            battleWin = false;
                            cout << "[ �������� �й��߽��ϴ�...... ]" << endl;
                            battle = false;
                            battleLose = true;
                        }
                        if (monsterHp <= 0) // ���� �¸�
                        {
                            cout << "[ �������� �¸��Ͽ����ϴ�!!! ]" << endl;
                            battle = false;
                        }
                        
                    }
                    
                } // ���� ����

                cout << "\n";

                if (battleWin)
                {
                    int itemLoot = 1 + rand() % 10;
                    if (itemLoot > 5 ) // 50%�� Ȯ���� ������ ����ǰ�� ����Ѵ�.
                    {
                        item = monster->Droptable("").front(); // ������̺��� ������ �̸��� �޾ƿ´�
                        price = 100;
                        count = 1;
                        itemType = "��Ÿ";
                        inv.addItem(item, price, 1, itemType);
                        // ��� ���� ����ǰ�� ������ �ǸŽ� ���� 100���� ��Ÿ�������̴�.
                    }
                    else if (itemLoot > 3) // 40%�� Ȯ���� �������� �Ǹ��ϴ� �Ͱ� ������ ������ �Ҹ�ǰ�� ����Ѵ�.
                    {
                        item = "ü������";
                        price = 30;
                        count = 1;
                        itemType = "�Ҹ�";
                        inv.addItem(item, price, 1, itemType);
                    }
                    else if (itemLoot > 1)
                    {
                        item = "���ǿ���";
                        price = 60;
                        count = 1;
                        itemType = "�Ҹ�";
                        inv.addItem(item, price, 1, itemType);
                    }
                    else // �ƹ��͵� ����� ���� ���� ���.
                    {
                        item = "����";
                    }

                    int Exp = 50; // ȹ�����ġ 50 ����, �ִ뷹���� ��� ȹ������ ����.
                    int Gold = 100 + rand() % 101; // ȹ�� ��� 100~200;
                    cout << "[ ���� ��� ]" << endl;
                    if (CharacterLevel > 10)
                    {
                        cout << "ȹ�� ����ġ : " << Exp << endl;
                    }
                    cout << "ȹ�� ��� : " << Gold << "G" << endl;
                    inv.addGold(Gold);

                    if (item != "����")
                    {
                        cout << "ȹ�� ������ : " << item << endl;
                    }

                    CharacterExp += Exp;
                    
                }

                if (CharacterExp >= 100 && CharacterLevel < 10)
                {
                    cout << "\n[ �������� �Ͽ����ϴ�! ] " << endl;

                    CharacterExp -= 100;

                    cout << "[ ���� : " << CharacterLevel++ << " -> " << CharacterLevel << " ]\n";
                    cout << "[ �ִ� ü�� : " << CharacterMaxhp << " -> ";
                    CharacterMaxhp = CharacterMaxhp + (CharacterLevel * 20);
                    cout << CharacterMaxhp << " ]\n";
                    cout << "[ ���ݷ� : " << CharacterPower << " -> ";
                    CharacterPower = (CharacterPower - weaponOption) + (CharacterLevel * 5);
                    cout << CharacterPower << " ]";
                    if (weaponOption != 0)
                    {
                        cout << "[+" << weaponOption << "]";
                    }
                    cout << "\n";
                }
                
                CharacterHp = CharacterMaxhp; // ���� ���� �� ü�� �ڵ� ȸ��

                delete monster;
                
                cout << "\n\n[ ���� ����� �����մϴ� ]" << endl;

                if (battleLose) // �й��ϰų� ������ ��� ������ ���ư���.
                {
                    cout << "\n\n[ ������ ���ư��ϴ� ]" << endl;
                    battleLose = false;
                    actionChoice = 0;
                    break;
                }
                else
                {
                    cout << "\n[ �� ����Ͻðڽ��ϱ�? ]" << endl;
                    cout << "[1] �� / [2] �ƴϿ�" << endl;
                    cin >> actionChoice;

                    switch (actionChoice)
                    {
                    case '1':
                    {
                        cout << "\n\n[ �̾ �����մϴ� ]" << endl;
                        Monster_choice = 1 + rand() % 8; // �������� ���͸� ����
                        break;
                    }
                    case '2':
                    {
                        cout << "\n\n[ ������ ���ư��ϴ� ]" << endl;
                        actionChoice = 0;
                        break;
                    }
                    default:
                    {
                        cout << "[ �߸��Է��ϼ̽��ϴ� ] " << endl;
                        cout << "[ ������ ���ư��ϴ� ] " << endl;
                        actionChoice = 0;
                        break;
                    }
                    }
                }
            }

            place = "����";
            break;

        } // ���� ��� ����

        case '2': // ���� �̵�
        {
            cout << "\"�ݰ����ϴ�, �������!\"";

            while (actionChoice)
            {

                cout << "\n\n[1] ������ ����\n[2] ������ �Ǹ�\n[3] ���� ������" << endl;
                cin >> actionChoice;
                cout << "\n";

                switch (actionChoice)
                {
                case '1':
                {
                    bool notBuy = false;
                    cout << "[ ������ �����Ͻðڽ��ϱ�? ]" << endl;
                    cout << "\n[01][����] ���ҵ� | 200G | ���ݷ� 50 ����" << endl;
                    cout << "[02][����] �ռҵ� | 800G | ���ݷ� 90 ����" << endl;
                    cout << "[03][����] ����跲���� | 2000G | ���ݷ� 300 ����" << endl;
                    cout << "[04][����] õ���� | 100G | ���� 20 ����" << endl;
                    cout << "[05][����] ö���� | 500G | ���� 40 ����" << endl;
                    cout << "[06][����] ��ź�� | 1200G | ���� 100 ����" << endl;
                    cout << "[07][�Ҹ�] ü������ | 50G | ������ ü�� 300 ȸ��" << endl;
                    cout << "[08][�Ҹ�] ���ǿ��� | 100G | ������ ���ݷ� 50 ����" << endl;
                        
                    cin >> actionChoice;

                    switch (actionChoice)
                    {
                        case '1' :
                        {
                            item = "���ҵ�";
                            price = 200;
                            count = 1;
                            itemType = "����";
                            break;
                        }
                        case '2':
                        {
                            item = "�ռҵ�";
                            price = 800;
                            count = 1;
                            itemType = "����";
                            break;
                        }
                        case '3':
                        {
                            item = "����跲����";
                            price = 2000;
                            count = 1;
                            itemType = "����";
                            break;
                        }
                        case '4':
                        {
                            item = "õ����";
                            price = 100;
                            count = 1;
                            itemType = "����";
                            break;
                        }
                        case '5':
                        {
                            item = "ö����";
                            price = 500;
                            count = 1;
                            itemType = "����";
                            break;
                        }
                        case '6':
                        {
                            item = "��ź��";
                            price = 1500;
                            count = 1;
                            itemType = "����";
                            break;
                        }
                        case '7':
                        {
                            item = "ü������";
                            price = 50;
                            itemType = "�Ҹ�";
                            break;
                        }
                        case '8':
                        {
                            item = "���ǿ���";
                            price = 100;
                            itemType = "�Ҹ�";
                            break;
                        }
                        default :
                        {
                            notBuy = true;
                            break;
                        }

                    }

                    if (notBuy)
                    {
                        cout << "\"�׷� ������ ���˴ϴ�.\"" << endl;
                        break;
                    }
                    else
                    {
                        if (itemType == "�Ҹ�") // �Ҹ�ǰ�� ��� ������ ���� ����
                        {
                            cout << "\"��� �����Ͻðڽ��ϱ�?\"" << endl;
                            cin >> count;

                            cout << "\n[ " << item << "�� ���� " << price << "G��" << count << "���� �����Ͻðڽ��ϱ�? ]" << endl;
                            cout << " [�� ���� ���� " << price * count << "G ]" << endl;
                            cout << "[1]�� / [2] �ƴϿ�" << endl;
                            cin >> actionChoice;

                            if (actionChoice == '1')
                            {
                                int gold = inv.showGold(0);
                                if (gold < (price * count))
                                {
                                    notBuy = true;
                                }
                                else
                                {
                                    cout << "\n[ " << item << "�� " << count << "�� �����Ͽ����ϴ� ]" << endl;
                                    inv.reduceGold(price*count);
                                }
                            }
                        }
                        else // �����ϴ� ������ �Ҹ�ǰ�� �ƴ� ���
                        {   
                            cout << "\n[ " << item << "��(��)" << price << "G�� �����Ͻðڽ��ϱ�? ]" << endl;
                            cout << "[1]�� / [2] �ƴϿ�" << endl;
                            cin >> actionChoice;

                            if (actionChoice == '1')
                            {
                                int gold = inv.showGold(0);
                                if (gold < (price))
                                {
                                    notBuy = true;
                                }
                                else
                                {
                                    cout << "\n[ " << item << "��(��) �����Ͽ����ϴ� ]" << endl;
                                    inv.reduceGold(price);
                                }
                            }
                        } 

                        if (notBuy) // �������� ������ ���
                        {
                            cout << "[ �������� �����մϴ�... ]" << endl;
                            inv.showGold();
                        }
                        else
                        {
                            price = ((price / 10) * 6); // ���߿� �������� �Ǹ��� ���� 60%�� �������� �Ǹ��ϱ�.
                            inv.addItem(item, price, count, itemType);

                            if (itemType != "�Ҹ�")
                            {
                                cout << "[ ���� �����Ͻðڽ��ϱ�? ]" << endl;
                                cout << "[1] �� / [2] �ƴϿ�" << endl;
                                cin >> actionChoice;

                                if (actionChoice == '1')
                                {
                                    cout << "[ ";

                                    if (itemType == "����") // ���� ����
                                    {
                                        if (weapon != "����") // �̹� ���⸦ �������̸� �����ϰ� �κ��丮�� �߰�
                                        {
                                            cout << weapon << "��(��) �����ϰ� ";
                                            CharacterPower -= weaponOption;
                                            
                                            // �������� �������� �ǸŰ� Ȯ��
                                            if (weapon == "���ҵ�")
                                            {
                                                price = 120;
                                            }
                                            else if (weapon == "�ռҵ�")
                                            {
                                                price = 480;
                                            }
                                            else // ����跲����
                                            {
                                                price = 1200;
                                            }
                                            inv.addItem(weapon, price, 1, itemType);
                                        }
                                        // ������ �����ϱ�
                                        if (item == "���ҵ�")
                                        {
                                            weaponOption = 50;
                                        }
                                        else if (weapon == "�ռҵ�")
                                        {
                                            weaponOption = 90;
                                        }
                                        else if (weapon == "����跲����")
                                        {
                                            weaponOption = 300;
                                        }
                                        CharacterPower += weaponOption;
                                        weapon = item;
                                        inv.removeItem(item, 1);

                                    } // ���� ���� ����
                                    else if (itemType == "����")// ���� ����
                                    {
                                        if (ammor != "����") // �̹� ������ ������
                                        {
                                            cout << ammor << "��(��) �����ϰ� ";
                                            CharacterDefence -= ammorOption;

                                            // �������� �������� �ǸŰ� Ȯ��
                                            if (ammor == "õ����")
                                            {
                                                price = 60;
                                            }
                                            else if (ammor == "ö����")
                                            {
                                                price = 300;
                                            }
                                            else // ��ź��
                                            {
                                                price = 720;
                                            }
                                            inv.addItem(ammor, price, 1, itemType);
                                        }
                                        // ������ �����ϱ�
                                        if (item == "õ����")
                                        {
                                            ammorOption = 20;
                                        }
                                        else if (weapon == "ö����")
                                        {
                                            ammorOption = 40;
                                        }
                                        else if (weapon == "��ź��")
                                        {
                                            ammorOption = 100;
                                        }
                                        CharacterDefence += ammorOption;
                                        ammor = item;
                                        inv.removeItem(item, 1);
                                    } // �� ���� ����

                                    cout << item << "��(��) �����մϴ� ]" << endl;
                                }// ��� ���� ����
                            }

                            cout << "\n\"�����մϴ�\"\n" << endl;
                            inv.showGold();
                            cout << "\n\"�� �ʿ��� ���� �����Ǳ��?\"\n" << endl;
                            actionChoice = 0;
                            break;
                        }
                    } // ��ȿ�� ���Ŵ� �������

                    break; // ���� ����
                }
                case '2':
                {
                    
                    inv.showInventory();
                    string inputItem;

                    cout << "\n \" ������ �Ǹ��Ͻðڽ��ϱ�?\"" << endl;
                    cout << "\n[ �Ǹ��� ������ �̸� �Ǵ� ��ȣ �Է� ]" << endl;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    getline(cin, inputItem);

                    bool isNumber = true; // �̸����� �Է��ߴ��� ��ȣ�� �Է��ߴ��� üũ
                    for (char c : inputItem)
                    {
                        if (!isdigit(static_cast<unsigned char>(c)))
                        {
                            isNumber = false;
                            break;
                        }
                    }

                    if (isNumber && inputItem.length() < 3)
                    {   // �����۹�ȣ�� �Է� ���� ���
                        int itemNumber = stoi(inputItem);
                        auto info = inv.ItemInfoIndex(itemNumber);
                        string sum1 = get<0>(info); // �̸�
                        int sum2 = get<1>(info); // ����
                        int sum3 = get<2>(info); // ����

                        if (sum1 == "")
                        {
                            cout << "\n[ �������� �ʴ� �������Դϴ� ]" << endl;
                            break;
                        }
                        else
                        {
                            cout << "[ ��� �Ǹ��Ͻðڽ��ϱ�? ]" << endl;
                            cin >> count;

                            if (count > sum2)
                            {
                                cout << "\n[ " << sum1 << "�� ���� ������ �Ǹ��Ϸ��� �������� �����ϴ� ]" << endl;
                                cout << "[ ���� �������� " << sum1 << "���� : " << sum2 << "�� ]";
                                break;
                            }
                            else
                            {
                                cout << "\n[ ���� �������� " << sum1 << "���� : " << sum2 << "�� ]" << endl;
                                cout << "[ " << sum1 << " ���� �Ǹ� ���� : " << sum3 << "G ]" << endl;
                                cout << "\n" << sum1 << "��(��) " << count << "�� �Ǹ��Ͻðڽ��ϱ�?" << endl;
                                cout << "[1] �� / [2] �ƴϿ�" << endl;

                                cin >> actionChoice;

                                switch (actionChoice)
                                {
                                case '1':
                                {
                                    cout << "\n" << item << "��(��) " << count << "�� �Ǹ��Ͽ����ϴ�." << endl;
                                    auto result = inv.sellItemIndex(itemNumber, count);
                                    cout << "[ �Ǹ��� ���� : " << result.first << "�� ]" << endl;
                                    cout << "[ �� �Ǹ� ���� : " << result.second << "G ]" << endl;

                                    cout << "\n\"�����մϴ�!\"" << endl;
                                    inv.showGold();
                                    break;
                                }
                                default:
                                {
                                    break;
                                }

                                }
                            }
                        }
                    }
                    else
                    {
                        item = inputItem;
                        // �������̸����� �Է� ���� ���
                        tuple<int, int, string> info = inv.getItemInfo(item); // �������� �̸��� �Է½� ������ ȣ��
                        int sum1 = get<0>(info); // ����
                        int sum2 = get<1>(info); // ����
                        string sum3 = get<2>(info); // Ÿ��
                        
                        if (sum1 == 0)
                        {
                            cout << "\n[ �������� �ʴ� �������Դϴ� ]" << endl;
                            break;
                        }
                        else
                        {
                            cout << "[ ��� �Ǹ��Ͻðڽ��ϱ�? ]" << endl;
                            cin >> count;

                            if (count > sum1)
                            {
                                cout << "\n[ " << item << "�� ���� ������ �Ǹ��Ϸ��� �������� �����ϴ� ]" << endl;
                                cout << "[ ���� �������� " << item << "���� : " << sum1 << "�� ]";
                                break;
                            }
                            else
                            {
                                cout << "\n[ ���� �������� " << item << "���� : " << sum1 << "�� ]" << endl;
                                cout << "[ " << item << " ���� �Ǹ� ���� : " << sum2 << "G ]" << endl;
                                cout << "\n" << item << "��(��) " << count << "�� �Ǹ��Ͻðڽ��ϱ�?" << endl;
                                cout << "[1] �� / [2] �ƴϿ�" << endl;

                                cin >> actionChoice;

                                switch (actionChoice)
                                {
                                case '1':
                                {
                                    cout << "\n" << item << "��(��) " << count << "�� �Ǹ��Ͽ����ϴ�." << endl;
                                    auto result = inv.sellItem(item, count);
                                    cout << "[ �Ǹ��� ���� : " << result.first << "�� ]" << endl;
                                    cout << "[ �� �Ǹ� ���� : " << result.second << "G ]" << endl;

                                    cout << "\n\"�����մϴ�!\"" << endl;
                                    inv.showGold();
                                    break;
                                }
                                default:
                                {
                                    break;
                                }
                            }

                            }
                        }// �Ǹ� �ݺ��� ����
                    }

                    cout << "\"�� �ʿ��� ���� �����Ǳ��?\"\n" << endl;
                    break;

                }
                case '3':
                {
                    cout << "\"�����մϴ�, �� ������!\"" << endl;
                    actionChoice = 0;
                    break;
                }
                default:
                {
                    cout << "�ٽ� �Է����ּ���" << endl;
                    break;
                }

                }



            }
            break;
        }
        case '3': //ĳ���� ����â Ȯ��
        {
            cout << "======= [ ����â ] =======" << endl;
            cout << "| �̸� : " << CharacterName << endl;
            cout << "| ���� : " << CharacterLevel;
            if (CharacterLevel == 10)
            {
                cout << " (Max)";
            }
            else
            {
                cout << " (Exp:" << CharacterExp << "/100)";
            }
            cout << endl;
            cout << "| ü�� : " << CharacterHp << " / " << CharacterMaxhp << endl;
            cout << "| ���� : " << CharacterPower << endl;
            cout << "| ��� : " << CharacterDefence << endl;
            cout << "| ��� : ���� [" << weapon << "]";
            if (weaponOption != 0)
            {
                cout << "[+" << weaponOption << "]";
            }
            cout << " ���� [" << ammor << "]";
            if (ammorOption != 0)
            {
                cout << "[+" << ammorOption << "] " << endl;
            }
            cout << "\n";
            int k = 1;
            if (weapon != "����")
            {
                cout << "[" << k++ << "] �������� ";
            }
            if (ammor != "����")
            {
                cout << "[" << k++ << "] �������� ";
            }
            cout << "[" << k++ << "] ����â�ݱ� ";
            
            cin >> actionChoice;

            switch (actionChoice)
            {
                case '1' :
                {
                    cout << "\n";
                    if (weapon != "����")
                    {
                        cout << "[" << weapon << "��(��) �����մϴ�]" << endl;

                        // �������� �������� �ǸŰ� Ȯ��
                        if (weapon == "���ҵ�")
                        {
                            price = 120;
                        }
                        else if (weapon == "�ռҵ�")
                        {
                            price = 480;
                        }
                        else // ����跲����
                        {
                            price = 1200;
                        }
                        inv.addItem(weapon, price, 1, "����");
                        weapon = "����";
                        CharacterPower -= weaponOption;
                        weaponOption = 0;
                    }
                    else if (ammor != "����")
                    {
                        cout << "[" << ammor << "��(��) �����մϴ�]" << endl;

                        // �������� �������� �ǸŰ� Ȯ��
                        if (ammor == "õ����")
                        {
                            price = 60;
                        }
                        else if (ammor == "ö����")
                        {
                            price = 300;
                        }
                        else // ��ź��
                        {
                            price = 720;
                        }
                        inv.addItem(ammor, price, 1, "����");
                        ammor = "����";
                        CharacterDefence -= ammorOption;
                        ammorOption = 0;
                    }
                    else
                    {
                        break;
                    }
                }
                case '2' :
                {
                    if (ammor != "����")
                    {
                        cout << "[" << ammor << "��(��) �����մϴ�]" << endl;

                        // �������� �������� �ǸŰ� Ȯ��
                        if (ammor == "õ����")
                        {
                            price = 60;
                        }
                        else if (ammor == "ö����")
                        {
                            price = 300;
                        }
                        else // ��ź��
                        {
                            price = 720;
                        }
                        inv.addItem(ammor, price, 1, "����");
                        ammor = "����";
                        CharacterDefence -= ammorOption;
                        ammorOption = 0;
                    }
                    else
                    {
                        break;
                    }
                }
                default :
                {
                    break;
                }
            }

            break;
        }
        
        case '4': // �κ��丮 Ȯ��
        {
            inv.showInventory();
            inv.showGold();

            cout << "\n[1] ��� ���� / [2] �κ��丮 �ݱ� \n";
            cin >> actionChoice;

            if (actionChoice == '1')
            {
                int k;
                cout << "\n[ ������ �������� ��ȣ�� �Է����ּ��� ]\n";
                cin >> k;

                auto info = inv.ItemInfoIndex(k);
                string sum1 = get<0>(info); // ������ �̸�

                cout << "\n[ ";

                if (sum1 == "���ҵ�" || sum1 == "�ռҵ�" || sum1 == "����跲����")
                {
                    itemType = "����";
                }
                else if (sum1 == "õ����" || sum1 == "ö����" || sum1 == "��ź��")
                {
                    itemType = "����";
                }
                else if (sum1 != "")
                {
                    cout << "��(��) ������ �� ���� �������Դϴ�. ]" << endl;
                }
                else
                {
                    cout << "[ ������ �߻��߽��ϴ�!] \n\n\n";
                }

                item = sum1;

                if (itemType == "����") // ���� ����
                {
                    if (weapon != "����") // �̹� ���⸦ �������̸� �����ϰ� �κ��丮�� �߰�
                    {
                        cout << weapon << "��(��) �����ϰ� ";
                        CharacterPower -= weaponOption;

                        // �������� �������� �ǸŰ� Ȯ��
                        if (weapon == "���ҵ�")
                        {
                            price = 120;
                        }
                        else if (weapon == "�ռҵ�")
                        {
                            price = 480;
                        }
                        else // ����跲����
                        {
                            price = 1200;
                        }
                        inv.addItem(weapon, price, 1, itemType);
                    }
                    // ������ �����ϱ�
                    if (item == "���ҵ�")
                    {
                        weaponOption = 50;
                    }
                    else if (weapon == "�ռҵ�")
                    {
                        weaponOption = 90;
                    }
                    else if (weapon == "����跲����")
                    {
                        weaponOption = 300;
                    }
                    CharacterPower += weaponOption;
                    weapon = item;
                    inv.removeItem(item, 1);
                    cout << item << "��(��) �����մϴ� ]" << endl;
                } // ���� ���� ����
                else if (itemType == "����")// ���� ����
                {
                    if (ammor != "����") // �̹� ������ ������
                    {
                        cout << ammor << "��(��) �����ϰ� ";
                        CharacterDefence -= ammorOption;

                        // �������� �������� �ǸŰ� Ȯ��
                        if (ammor == "õ����")
                        {
                            price = 60;
                        }
                        else if (ammor == "ö����")
                        {
                            price = 300;
                        }
                        else // ��ź��
                        {
                            price = 720;
                        }
                        inv.addItem(ammor, price, 1, itemType);
                    }
                    // ������ �����ϱ�
                    if (item == "õ����")
                    {
                        ammorOption = 20;
                    }
                    else if (weapon == "ö����")
                    {
                        ammorOption = 40;
                    }
                    else if (weapon == "��ź��")
                    {
                        ammorOption = 100;
                    }
                    CharacterDefence += ammorOption;
                    ammor = item;
                    inv.removeItem(item, 1);
                    cout << item << "��(��) �����մϴ� ]" << endl;
                } // �� ���� ����

            }
            actionChoice = 0;
            break;
        }
        case '5':
        {
            cout << "[ ������ �����մϴ� ]";
            game = false;
            break;
        }


        } // �ൿ �ݺ��� �ߴ�
     
    }
    
}