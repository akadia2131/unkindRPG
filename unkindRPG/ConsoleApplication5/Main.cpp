#include <iostream>
#include <cstring>
#include <ctime>
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

// �ݿ���?
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

    // �ൿ �ݺ��ϱ�
    cout << "\n";
    string place = "����";
    char actionChoice;

    // ���� ���� ����
    int Monster_choice = 1 + rand() % 8; // �������� ���͸� ����
    Monster* monster = nullptr;


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

                int Exp = 50; // 50 ����ġ
                int Gold = 10 + rand() % 11; // 10 ~ 20 ��� 
                cout << "������ �����!! " << endl;
                cout << "����ġ : " << Exp << endl;
                cout << "��� : " << Gold << endl;

                for (const string& d : monster->Droptable()) //��� ���̺�
                    cout << "��� ������ : " << d << endl; // ��� ���̺�
                //// �۾��ؾߵǴ� �κ�
                // 1. ���� óġ�� ������̺� �ִ� ������ �� 1������ string �Ǵ� char Ÿ������ ���� ��
                // 2. ������ ��� Ȯ���� ���� �� ��.
                // -> 1) �������� ����ƴ°�? (y/n)
                // -> 2) �Һ������ �Ǵ� ����ǰ �� 1���� �������� ���� (����)
                // -> 3) ���� ����������� ���������� �κ��丮�� ���� ��.
                
                delete monster;

                cout << "\n\n[ ���� ����� �����մϴ� ]" << endl;
                
                // �ӽ� ������ ���

                item = "���ķ�";
                count = 1;
                price = 100;
                itemType = "�Ҹ�";
                inv.addItem(item, price, count, itemType);

                cout << item << "��(��) ������ϴ�!" << endl;

                



                cout << "\n[ �� ����Ͻðڽ��ϱ�? ]" << endl;
                cout << "[1] �� / [2] �ƴϿ�" << endl;
                cin >> actionChoice;

                switch (actionChoice)
                {
                    case '1':
                    {
                        cout << "\n\n[ �̾ �����մϴ� ]" << endl;
                        break;
                    }
                    case '2':
                    {
                        cout << "\n\n[ ������ ���ư��ϴ� ]" << endl;
                        actionChoice = 0;
                        break;
                    }
                    default :
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
            cout << "\"�ݰ����ϴ�, �������!\"" << endl;

            while (actionChoice)
            {
                
                cout << "[1] ������ ����\n[2] ������ �Ǹ�\n[3] ���� ������" << endl;
                cin >> actionChoice;
                cout << "\n";

                switch (actionChoice)
                {
                    case '1' :
                    {
                        cout << "[ �߰��� ������ �Է� ] (�ӽ�)" << endl;
                        cin >> item;
                        count = 1;
                        price = 1000;
                        //price *= 100;
                        //price %= 160;
                        itemType = "����";

                        inv.addItem(item, price, count, itemType);

                        cout << "\n" << item << "��(��) �����Ͽ����ϴ�." << endl;
                        cout << "\n\"�����մϴ�\"" << endl;
                        cout << "\"�� �ʿ��� ���� �����Ǳ��?\"\n" << endl;
                        break;
                    }
                    case '2' :
                    {
                        cout << "[ �Ǹ��� ������ �Է� ] (�ӽ�)" << endl;
                        cin >> item;
                        cout << "[ ��� �Ǹ��Ͻðڽ��ϱ�? ]" << endl;
                        cin >> count;
                        
                        tuple<int, int, string> info = inv.getItemInfo(item); // �������� �̸��� �Է½� ������ ȣ��
                        int sum1 = get<0>(info); // ����
                        int sum2 = get<1>(info); // ����
                        string sum3 = get<2>(info); // Ÿ��

                        cout << "\n[ ���� �������� " << item << "�� ���� : " << sum1 << "�� ]" << endl;
                        cout << "[ " << item << " ���� �Ǹ� ���� : " << sum2 << "G ]" << endl;
                        cout << "\n" << item << "��(��) " << count << "�� �Ǹ��Ͻðڽ��ϱ�?" << endl;
                        cout << "[1] �� / [2] �ƴϿ�" << endl;

                        cin >> actionChoice;

                        switch (actionChoice)
                        {
                            case '1' :
                            {
                                cout << "\n" << item << "��(��) " << count << "�� �Ǹ��Ͽ����ϴ�." << endl;
                                auto result = inv.sellItem(item, count);
                                cout << "[ �Ǹ��� ���� : " << result.first << "�� ]" << endl;
                                cout << "[ �� �Ǹ� ���� : " << result.second << "G ]" << endl;

                                cout << "\n\"�����մϴ�!\"" << endl;
                                inv.showGold();
                                break;
                            }
                            default :
                            {
                                break;
                            }

                        }

                        cout << "\"�� �ʿ��� ���� �����Ǳ��?\"\n" << endl;
                        break;

                    }
                    case '3' :
                    {
                        cout << "\"�����մϴ�, �� ������!\"" <<endl;
                        actionChoice = 0;
                        break;
                    }
                    default :
                    {
                        cout << "�ٽ� �Է����ּ���" << endl;
                    }

                }
                

                
            }
             
            break;

        } // ���� ������
        case '3' :
        {
            
        }
        case '4' : // �κ��丮 Ȯ��
        {
            cout << "=======[ �κ��丮 ]=======" << endl;
            inv.showInventory();
            
        }

        } // �ൿ �ݺ��� �ߴ�

}
    
    return 0;
    }