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


// 메인 함수
int main(void)
{
    srand(static_cast<unsigned int>(time(nullptr))); // 난수 구현

    char name[20];
    bool hasSpace = true;
    int money = 0;

    Inventory inv;
    string item;
    int price;
    int count;
    string itemType;

    cout << "------[unkindRPG]------" << endl;
    cout << "\n[ 당신의 이름을 입력해주세요 ]" << endl;

    while (hasSpace) // 입력받은 이름에 공백이 있는지 체크
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

        if (strlen(name) == 0) // 아무것도 입력하지 않은 것도 진행 할 수 없음
        {
            hasSpace = true;
        }

        if (hasSpace)
        {
            cout << "\n다시 입력해주세요";
            cout << "\n!!!이름에는 공백이 들어갈 수 없습니다!!!" << endl;
        }
        else
        {
            cout << "\n반갑습니다 " << name << "님!" << endl;

        }
    } // 이름 설정 종료

    // 캐릭터 설정
    Character character(name); //캐릭터
    string CharaterName = character.getCharacterName(); // 캐릭터 이름
    int CharaterLevel = character.getCharacterLevel(); // 캐릭터 레벨
    int CharaterMaxhp = character.getCharacterMaxHp(); // 캐릭터 최대 체력
    int CharaterHp = character.getCharacterHp(); // 캐릭터 현재 체력
    int CharaterPower = character.getCharacterPower(); // 캐릭터 공격력
    int CharaterDefence = character.getCharacterDefence(); // 캐릭터 방어력
    int CharaterExp = character.getCharacterExp(); // 캐릭터 경험치
    int CharaterGold = character.getCharacterGold(); // 캐릭터 소지금


    // 행동 반복하기
    cout << "\n";
    string place = "마을";
    char actionChoice;

    // 몬스터 전투 구현
    int Monster_choice = 1 + rand() % 8; // 랜덤으로 몬스터를 조우
    Monster* monster = nullptr; // 몬스터

    monster = new Orc("Orc");
    string OrcName = monster->getMonsterName(); // 오크 이름
    int OrcMaxhp = monster->getMonsterMaxHp(); // 오크 최대 체력
    int OrcHp = monster->getMonsterHp(); // 오크 현재 체력
    int OrcPower = monster->getMonsterPower(); // 오크 공격력
    int OrcDefence = monster->getMonsterDefence(); // 오크 방어력
    delete monster;

    monster = new Troll("Troll");
    string TrollName = monster->getMonsterName(); // 트롤 이름
    int TrollMaxhp = monster->getMonsterMaxHp(); // 트롤 최대 체력
    int TrollHp = monster->getMonsterHp(); // 트롤 현재 체력
    int TrollPower = monster->getMonsterPower(); // 트롤 공격력
    int TrollDefence = monster->getMonsterDefence(); // 트롤 방어력
    delete monster;

    monster = new Slime("Slime");
    string SlimeName = monster->getMonsterName(); // 슬라임 이름
    int SlimeMaxhp = monster->getMonsterMaxHp(); // 슬라임 최대 체력
    int SlimeHp = monster->getMonsterHp(); // 슬라임 현재 체력
    int SlimePower = monster->getMonsterPower(); // 슬라임 공격력
    int SlimeDefence = monster->getMonsterDefence(); // 슬라임 방어력
    delete monster;

    monster = new Skeleton("Skeleton");
    string SkeletonName = monster->getMonsterName(); // 스켈레톤 이름
    int SkeletonMaxhp = monster->getMonsterMaxHp(); // 스켈레톤 최대 체력
    int SkeletonHp = monster->getMonsterHp(); // 스켈레톤 현재 체력
    int SkeletonPower = monster->getMonsterPower(); // 스켈레톤 공격력
    int SkeletonDefence = monster->getMonsterDefence(); // 스켈레톤 방어력
    delete monster;

    monster = new Hydra("Hydra");
    string HydraName = monster->getMonsterName(); // 히드라 이름
    int HydraMaxhp = monster->getMonsterMaxHp(); // 히드라 최대 체력
    int HydraHp = monster->getMonsterHp(); // 히드라 현재 체력
    int HydraPower = monster->getMonsterPower(); // 히드라 공격력
    int HydraDefence = monster->getMonsterDefence(); // 히드라 방어력
    delete monster;

    monster = new Goblin("Goblin");
    string GoblinName = monster->getMonsterName(); // 고블린 이름
    int GoblinMaxhp = monster->getMonsterMaxHp(); // 고블린 최대 체력
    int GoblinHp = monster->getMonsterHp(); // 고블린 현재 체력
    int GoblinPower = monster->getMonsterPower(); // 고블린 공격력
    int GoblinDefence = monster->getMonsterDefence(); // 고블린 방어력
    delete monster;

    monster = new Ghoul("Ghoul");
    string GhoulName = monster->getMonsterName(); // 구울 이름
    int GhoulMaxhp = monster->getMonsterMaxHp(); // 구울 최대 체력
    int GhoulHp = monster->getMonsterHp(); // 구울 현재 체력
    int GhoulPower = monster->getMonsterPower(); // 구울 공격력
    int GhoulDefence = monster->getMonsterDefence(); // 구울 방어력
    delete monster;

    monster = new Drake("Drake");
    string DrakeName = monster->getMonsterName(); // 드레이크 이름
    int DrakeMaxhp = monster->getMonsterMaxHp(); // 드레이크 최대 체력
    int DrakeHp = monster->getMonsterHp(); // 드레이크 현재 체력
    int DrakePower = monster->getMonsterPower(); // 드레이크 공격력
    int DrakeDefence = monster->getMonsterDefence(); // 드레이크  방어력
    delete monster;

    while (true)
    {
        cout << "\n\n<무엇을 하시겠습니까?>" << endl;
        cout << "\n[ 현재 위치 : " << place << " ]" << endl;
        cout << "\n[1] 몬스터 토벌" << endl;
        cout << "[2] 상점 이동" << endl;
        cout << "[3] 나의 상태 확인" << endl;
        cout << "[4] 인벤토리 확인" << endl;
        cout << "[5] 게임 종료 \n" << endl;
        cin >> actionChoice;

        cout << "\n\n";


        switch (actionChoice)
        {
        case '1':
        {
            while (actionChoice == '1') // 연속전투시 반복
            {
                place = "마을 외곽";

                cout << " <몬스터 시스템> " << endl;
                cout << "\n무작위 몬스터 등장!! " << endl;

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
            
                inv.addItem(monster->Droptable("").front(), 100, 1, "기타");

                int Exp = 50; // 50 경험치
                int Gold = 10 + rand() % 11; // 10 ~ 20 골드 
                cout << "보상을 얻었다!! " << endl;
                cout << "경험치 : " << Exp << endl;
                cout << "골드 : " << Gold << endl;

                delete monster;

           
                
                cout << "\n\n[ 몬스터 토벌을 종료합니다 ]" << endl;

                cout << "\n[ 더 사냥하시겠습니까? ]" << endl;
                cout << "[1] 네 / [2] 아니오" << endl;
                cin >> actionChoice;

                switch (actionChoice)
                {
                case '1':
                {
                    cout << "\n\n[ 이어서 전투합니다 ]" << endl;
                    Monster_choice = 1 + rand() % 8; // 랜덤으로 몬스터를 조우
                    break;
                }
                case '2':
                {
                    cout << "\n\n[ 마을로 돌아갑니다 ]" << endl;
                    actionChoice = 0;
                    break;
                }
                default:
                {
                    cout << "[ 잘못입력하셨습니다 ] " << endl;
                    cout << "[ 마을로 돌아갑니다 ] " << endl;
                    actionChoice = 0;
                    break;
                }
                }
            }

            place = "마을";
            break;
        } // 몬스터 토벌 종료

        case '2': // 상점 이동
        {
            cout << "\"반갑습니다, 어서오세요!\"";

            while (actionChoice)
            {

                cout << "\n\n[1] 아이템 구매\n[2] 아이템 판매\n[3] 상점 나가기" << endl;
                cin >> actionChoice;
                cout << "\n";

                switch (actionChoice)
                {
                case '1':
                {
                    cout << "[ 추가할 아이템 입력 ] (임시)" << endl;
                    cin >> item;
                    count = 1;
                    price = 1000;
                    itemType = "무기";

                    inv.addItem(item, price, count, itemType);

                    cout << "\n" << item << "을(를) 구매하였습니다." << endl;
                    cout << "\n\"감사합니다\"" << endl;
                    cout << "\"또 필요한 것이 있으실까요?\"\n" << endl;
                    break;
                }
                case '2':
                {
                    
                    inv.showInventory();
                    string inputItem;
                    cout << "\n[ 판매할 아이템 이름 또는 번호 입력 ]" << endl;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    getline(cin, inputItem);

                    bool isNumber = true; // 이름으로 입력했는지 번호로 입력했는지 체크
                    for (char c : inputItem)
                    {
                        if (!isdigit(static_cast<unsigned char>(c)))
                        {
                            isNumber = false;
                            break;
                        }
                    }



                    if (isNumber && inputItem.length() < 3)
                    {   // 아이템번호로 입력 받은 경우
                        int itemNumber = stoi(inputItem);
                        auto info = inv.ItemInfoIndex(itemNumber);
                        string sum1 = get<0>(info); // 이름
                        int sum2 = get<1>(info); // 수량
                        int sum3 = get<2>(info); // 가격

                        if (sum1 == "")
                        {
                            cout << "\n[ 존재하지 않는 아이템입니다 ]" << endl;
                            break;
                        }
                        else
                        {
                            cout << "[ 몇개를 판매하시겠습니까? ]" << endl;
                            cin >> count;

                            if (count > sum2)
                            {
                                cout << "\n[ " << sum1 << "의 보유 수량이 판매하려는 수량보다 적습니다 ]" << endl;
                                cout << "[ 현재 보유중인 " << sum1 << "수량 : " << sum2 << "개 ]";
                                break;
                            }
                            else
                            {
                                cout << "\n[ 현재 보유중인 " << sum1 << "수량 : " << sum2 << "개 ]" << endl;
                                cout << "[ " << sum1 << " 개당 판매 가격 : " << sum3 << "G ]" << endl;
                                cout << "\n" << sum1 << "을(를) " << count << "개 판매하시겠습니까?" << endl;
                                cout << "[1] 네 / [2] 아니오" << endl;

                                cin >> actionChoice;

                                switch (actionChoice)
                                {
                                case '1':
                                {
                                    cout << "\n" << item << "을(를) " << count << "개 판매하였습니다." << endl;
                                    auto result = inv.sellItemIndex(itemNumber, count);
                                    cout << "[ 판매한 개수 : " << result.first << "개 ]" << endl;
                                    cout << "[ 총 판매 가격 : " << result.second << "G ]" << endl;

                                    cout << "\n\"감사합니다!\"" << endl;
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
                        // 아이템이름으로 입력 받은 경우
                        tuple<int, int, string> info = inv.getItemInfo(item); // 아이템의 이름을 입력시 정보만 호출
                        int sum1 = get<0>(info); // 수량
                        int sum2 = get<1>(info); // 가격
                        string sum3 = get<2>(info); // 타입
                        
                        if (sum1 == 0)
                        {
                            cout << "\n[ 존재하지 않는 아이템입니다 ]" << endl;
                            break;
                        }
                        else
                        {
                            cout << "[ 몇개를 판매하시겠습니까? ]" << endl;
                            cin >> count;

                            if (count > sum1)
                            {
                                cout << "\n[ " << item << "의 보유 수량이 판매하려는 수량보다 적습니다 ]" << endl;
                                cout << "[ 현재 보유중인 " << item << "수량 : " << sum1 << "개 ]";
                                break;
                            }
                            else
                            {
                                cout << "\n[ 현재 보유중인 " << item << "수량 : " << sum1 << "개 ]" << endl;
                                cout << "[ " << item << " 개당 판매 가격 : " << sum2 << "G ]" << endl;
                                cout << "\n" << item << "을(를) " << count << "개 판매하시겠습니까?" << endl;
                                cout << "[1] 네 / [2] 아니오" << endl;

                                cin >> actionChoice;

                                switch (actionChoice)
                                {
                                case '1':
                                {
                                    cout << "\n" << item << "을(를) " << count << "개 판매하였습니다." << endl;
                                    auto result = inv.sellItem(item, count);
                                    cout << "[ 판매한 개수 : " << result.first << "개 ]" << endl;
                                    cout << "[ 총 판매 가격 : " << result.second << "G ]" << endl;

                                    cout << "\n\"감사합니다!\"" << endl;
                                    inv.showGold();
                                    break;
                                }
                                default:
                                {
                                    break;
                                }
                            }

                            }
                        }// 판매 반복문 종료
                    }

                    cout << "\"또 필요한 것이 있으실까요?\"\n" << endl;
                    break;

                }
                case '3':
                {
                    cout << "\"감사합니다, 또 오세요!\"" << endl;
                    actionChoice = 0;
                    break;
                }
                default:
                {
                    cout << "다시 입력해주세요" << endl;
                }

                }



            }
        }
        case '3': //캐릭터 상태창 확인
        {
            character.printCharacterStatus(); 

            break;
        }
        
        case '4': // 인벤토리 확인
        {
            inv.showInventory();
        }

        } // 행동 반복문 중단
     
    }
    
}