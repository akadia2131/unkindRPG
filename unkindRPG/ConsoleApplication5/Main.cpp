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
#include "Character.h"


using namespace std;


// ���� �Լ�
int main(void)
{
    srand(static_cast<unsigned int>(time(nullptr))); // ���� ����

    char name[20];
    bool hasSpace = true;
    int money = 0;

    Inventory inv;
    string item;
    int price;
    int count;
    string itemType;

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

    // ĳ���� ����
    Character character(name); //ĳ����
    string CharaterName = character.getCharacterName(); // ĳ���� �̸�
    int CharaterLevel = character.getCharacterLevel(); // ĳ���� ����
    int CharaterMaxhp = character.getCharacterMaxHp(); // ĳ���� �ִ� ü��
    int CharaterHp = character.getCharacterHp(); // ĳ���� ���� ü��
    int CharaterPower = character.getCharacterPower(); // ĳ���� ���ݷ�
    int CharaterDefence = character.getCharacterDefence(); // ĳ���� ����
    int CharaterExp = character.getCharacterExp(); // ĳ���� ����ġ
    int CharaterGold = character.getCharacterGold(); // ĳ���� ������


    // �ൿ �ݺ��ϱ�
    cout << "\n";
    string place = "����";
    char actionChoice;

    // ���� ���� ����
    int Monster_choice = 1 + rand() % 8; // �������� ���͸� ����
    Monster* monster = nullptr; // ����

    monster = new Orc("Orc");
    string OrcName = monster->getMonsterName(); // ��ũ �̸�
    int OrcMaxhp = monster->getMonsterMaxHp(); // ��ũ �ִ� ü��
    int OrcHp = monster->getMonsterHp(); // ��ũ ���� ü��
    int OrcPower = monster->getMonsterPower(); // ��ũ ���ݷ�
    int OrcDefence = monster->getMonsterDefence(); // ��ũ ����
    delete monster;

    monster = new Troll("Troll");
    string TrollName = monster->getMonsterName(); // Ʈ�� �̸�
    int TrollMaxhp = monster->getMonsterMaxHp(); // Ʈ�� �ִ� ü��
    int TrollHp = monster->getMonsterHp(); // Ʈ�� ���� ü��
    int TrollPower = monster->getMonsterPower(); // Ʈ�� ���ݷ�
    int TrollDefence = monster->getMonsterDefence(); // Ʈ�� ����
    delete monster;

    monster = new Slime("Slime");
    string SlimeName = monster->getMonsterName(); // ������ �̸�
    int SlimeMaxhp = monster->getMonsterMaxHp(); // ������ �ִ� ü��
    int SlimeHp = monster->getMonsterHp(); // ������ ���� ü��
    int SlimePower = monster->getMonsterPower(); // ������ ���ݷ�
    int SlimeDefence = monster->getMonsterDefence(); // ������ ����
    delete monster;

    monster = new Skeleton("Skeleton");
    string SkeletonName = monster->getMonsterName(); // ���̷��� �̸�
    int SkeletonMaxhp = monster->getMonsterMaxHp(); // ���̷��� �ִ� ü��
    int SkeletonHp = monster->getMonsterHp(); // ���̷��� ���� ü��
    int SkeletonPower = monster->getMonsterPower(); // ���̷��� ���ݷ�
    int SkeletonDefence = monster->getMonsterDefence(); // ���̷��� ����
    delete monster;

    monster = new Hydra("Hydra");
    string HydraName = monster->getMonsterName(); // ����� �̸�
    int HydraMaxhp = monster->getMonsterMaxHp(); // ����� �ִ� ü��
    int HydraHp = monster->getMonsterHp(); // ����� ���� ü��
    int HydraPower = monster->getMonsterPower(); // ����� ���ݷ�
    int HydraDefence = monster->getMonsterDefence(); // ����� ����
    delete monster;

    monster = new Goblin("Goblin");
    string GoblinName = monster->getMonsterName(); // ��� �̸�
    int GoblinMaxhp = monster->getMonsterMaxHp(); // ��� �ִ� ü��
    int GoblinHp = monster->getMonsterHp(); // ��� ���� ü��
    int GoblinPower = monster->getMonsterPower(); // ��� ���ݷ�
    int GoblinDefence = monster->getMonsterDefence(); // ��� ����
    delete monster;

    monster = new Ghoul("Ghoul");
    string GhoulName = monster->getMonsterName(); // ���� �̸�
    int GhoulMaxhp = monster->getMonsterMaxHp(); // ���� �ִ� ü��
    int GhoulHp = monster->getMonsterHp(); // ���� ���� ü��
    int GhoulPower = monster->getMonsterPower(); // ���� ���ݷ�
    int GhoulDefence = monster->getMonsterDefence(); // ���� ����
    delete monster;

    monster = new Drake("Drake");
    string DrakeName = monster->getMonsterName(); // �巹��ũ �̸�
    int DrakeMaxhp = monster->getMonsterMaxHp(); // �巹��ũ �ִ� ü��
    int DrakeHp = monster->getMonsterHp(); // �巹��ũ ���� ü��
    int DrakePower = monster->getMonsterPower(); // �巹��ũ ���ݷ�
    int DrakeDefence = monster->getMonsterDefence(); // �巹��ũ  ����
    delete monster;

    while (true)
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
                place = "���� �ܰ�";

                cout << " <���� �ý���> " << endl;
                cout << "\n������ ���� ����!! " << endl;

                switch (Monster_choice)
                {
                case 1:
                    monster = new Goblin(name);
                    break;
                case 2:
                    monster = new Orc(name);
                    break;
                case 3:
                    monster = new Slime(name);
                    break;
                case 4:
                    monster = new Ghoul(name);
                    break;
                case 5:
                    monster = new Drake(name);
                    break;
                case 6:
                    monster = new Ghoul(name);
                    break;
                case 7:                                                        
                    monster = new Hydra(name);
                    break;
                case 8:
                    monster = new Skeleton(name);
                    break;
                }
                
                monster->printMonsterStatus();
            
                inv.addItem(monster->Droptable("").front(), 100, 1, "��Ÿ");

                int Exp = 50; // 50 ����ġ
                int Gold = 10 + rand() % 11; // 10 ~ 20 ��� 
                cout << "������ �����!! " << endl;
                cout << "����ġ : " << Exp << endl;
                cout << "��� : " << Gold << endl;

                delete monster;

           
                
                cout << "\n\n[ ���� ����� �����մϴ� ]" << endl;

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
                    cout << "[ �߰��� ������ �Է� ] (�ӽ�)" << endl;
                    cin >> item;
                    count = 1;
                    price = 1000;
                    itemType = "����";

                    inv.addItem(item, price, count, itemType);

                    cout << "\n" << item << "��(��) �����Ͽ����ϴ�." << endl;
                    cout << "\n\"�����մϴ�\"" << endl;
                    cout << "\"�� �ʿ��� ���� �����Ǳ��?\"\n" << endl;
                    break;
                }
                case '2':
                {
                    
                    inv.showInventory();
                    string inputItem;
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
                }

                }



            }
        }
        case '3': //ĳ���� ����â Ȯ��
        {
            character.printCharacterStatus(); 

            break;
        }
        
        case '4': // �κ��丮 Ȯ��
        {
            inv.showInventory();
        }

        } // �ൿ �ݺ��� �ߴ�
     
    }
    
}