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


// 메인 함수
int main(void)
{
    srand(static_cast<unsigned int>(time(nullptr))); // 난수 구현

    char name[20];
    bool hasSpace = true;
    int money = 0;

    Inventory inv;
    string item = "아이템";
    int price = 0;
    int count = 0;
    string itemType = "기타";

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

    string CharacterName = name; // 캐릭터 이름
    int CharacterLevel = 1; // 캐릭터 레벨
    int CharacterMaxhp = 300; // 캐릭터 최대 체력
    int CharacterHp = 300; // 캐릭터 현재 체력
    int CharacterPower = 50; // 캐릭터 공격력
    int CharacterDefence = 0;// 캐릭터 방어력
    int CharacterExp = 0; // 캐릭터 경험치
    string weapon = "없음";
    int weaponOption = 0;
    string ammor = "없음";
    int ammorOption = 0;

    // 행동 반복하기
    cout << "\n";
    string place = "마을";
    char actionChoice;

    // 몬스터 전투 구현
    int Monster_choice = 1 + rand() % 8; // 랜덤으로 몬스터를 조우

    Monster* monster = nullptr; // 몬스터

    bool game = true;

    while (game)
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
                string monsterName;
                int monsterMaxhp;
                int monsterHp;
                int monsterPower;
                string monsterCrying;

                Monster_choice = 1 + rand() % 8; // 랜덤으로 몬스터를 조우

                switch (Monster_choice)
                {
                case 1:
                    monster = new Goblin();
                    place = "마을 외곽";
                    monsterCrying = "\"키에엑!\"";
                    break;
                case 2:
                    monster = new Orc();
                    place = "마을 외곽";
                    monsterCrying = "\"꾸르륵..취익...?\"";
                    break;
                case 3:
                    monster = new Slime();
                    place = "마을 외곽";
                    monsterCrying = "\"스스스......\"";
                    break;
                case 4:
                    monster = new Troll();
                    place = "어두운 동굴";
                    monsterCrying = "\"크와아아악!!!\"";
                    break;
                case 5:
                    monster = new Drake();
                    place = "불타는 화산";
                    monsterCrying = "\"콰아아아아아아!!!!\"";
                    break;
                case 6:
                    monster = new Ghoul();
                    place = "어두운 동굴";
                    monsterCrying = "\"그오오오....\"";
                    break;
                case 7:                                                        
                    monster = new Hydra();
                    place = "불타는 화산";
                    monsterCrying = "\"끼에에....!...!...!\"";
                    break;
                case 8:
                    monster = new Skeleton();
                    place = "어두운 동굴";
                    monsterCrying = "\"가각...끼기긱...깍...!\"";
                    break;
                }

                monsterName = monster->getMonsterName(); // 몬스터 이름
                monsterMaxhp = (monster->getMonsterMaxHp()) + (CharacterLevel * 10); // 몬스터 최대 체력
                monsterHp = monsterMaxhp; // 몬스터 현재 체력
                monsterPower = ((monster->getMonsterPower()) + (CharacterLevel * 2)); // 몬스터 공격력

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

                cout << monsterName << "등장!!" << endl;
                


                while (battle)
                {
                    cout << "\n[ 무엇을 하시겠습니까? ] [ 현재 " << ++battleTurn << "턴 째 ] [ 현재 위치 : " << place << " ]" << endl;
                    cout << "\n[" << CharacterName << "HP : " << CharacterHp << "/" << CharacterMaxhp << "] [" << monsterName << "HP : " << monsterHp << "/" << monsterMaxhp << "]" << endl;
                    cout << "[1]공격 / [2]방어 / [3]인벤토리 / [4]도주" << endl;

                    cin >> battleAction;

                    switch (battleAction)
                    {
                        case 1 : // 공격
                        {
                            // 대미지 계산식 = 내 공격력의 -+10%
                            int sum = ((CharacterPower / 10) * 9) + rand() % (((CharacterPower / 10) * 11) - ((CharacterPower / 10) * 9));
                            cout << "적을 공격했다! / " << monsterName << "에게 " << sum << "의 대미지!" << endl;
                            monsterHp -= sum;
                            break;
                        }
                        case 2 : // 방어
                        {
                            cout << "방어태세에 돌입했다! / [ 이번턴 받는 대미지 감소 ]" << endl;;
                            if (ammor == "없음") // 갑옷이 없는 경우 방어력 조금 증가
                            {
                                CharacterDefence = 20;
                            }
                            else // 갑옷이 있는 경우 갑옷의 방어력 효율 두배
                            {
                                CharacterDefence *= 2;
                            }
                            guard = true;
                            break;
                        }
                        case 3 : // 인벤토리. / 인벤토리에서 하는 행동들은 턴을 소모하지 않는다.
                        {
                            int hpPotion = 0;
                            int atkPotion = 0;
                            battleChance = true;

                            tuple<int, int, string> hpInfo = inv.getItemInfo("체력포션"); // 체력포션이 있는지 체크
                            int sum1 = get<0>(hpInfo); // 수량
                            if (sum1 > 0) // 체력포션이 있는 경우에 체크
                            {
                                hpPotion = sum1;
                            }

                            tuple<int, int, string> atkInfo = inv.getItemInfo("힘의영약"); // 힘의영약이 있는지 체크
                            int sum2 = get<0>(atkInfo); // 수량                          
                            if (sum2 > 0) // 힘의영약이 있는 경우에 체크
                            {
                                atkPotion = sum2;
                            }

                            if (atkPotion == 0 && hpPotion == 0)
                            {
                                cout << "[ 사용할 수 있는 아이템이 없다! ]" << endl;
                            }
                            else
                            {
                                int j = 1;
                                cout << "가방을 열었다!" << endl; // 체력포션, 힘의영약 둘중 하나가 아예 없는 경우 해당 선택지를 표시하지 않는다.
                                if (hpPotion > 0)
                                {
                                    cout << "[" << j++ << "] 체력포션 사용 / ";
                                }
                                if (atkPotion > 0)
                                {
                                    cout << "[" << j++ << "] 힘의영약 사용 / ";
                                }
                                cout << "[" << j << "] 사용하지 않는다" << endl;   

                                cin >> battleAction;

                                if (battleAction == 1)
                                {
                                    if (hpPotion > 0)
                                    {
                                        cout << "[ 체력이 회복됩니다 ]" << endl;
                                        cout << "[ HP 300 회복! ]" << endl;
                                        CharacterHp += 300;
                                        inv.removeItem("체력포션", 1);

                                        if (CharacterHp > CharacterMaxhp) // 최대체력에 다다르면 초과분을 버리고 현재 체력을 최대체력에 맞춘다.
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
                                            cout << "[ 이미 힘이 넘치는 상태입니다 ]" << endl; //이미 힘의영약을 사용한 상태라면 다시 사용할 수 없다
                                        }
                                        else
                                        {
                                            CharacterPower += 50;
                                            cout << "[ 힘이 넘쳐 흐릅니다! ]" << endl;
                                            cout << "[ 공격력 50 증가! ] [ 현재 공격력 : " << CharacterPower << " ]" << endl;
                                            doping = true;
                                            inv.removeItem("힘의영약", 1);
                                        }
                                    }
                                }
                            }
                            break;                            
                        }
                        case 4:
                        {
                            cout << "[ 도주하였습니다! ]" << endl;
                            run = true;
                            break;
                        }
                    }



                    if (battleChance)
                    {
                        // 행동을 하지 않았기 때문에 다시 나의 턴이 된다. 턴도 흐르지 않는다.
                        battleTurn--;
                        battleChance = false;
                    }
                    else if (run)
                    {
                        battleWin = false; // 도주로 인한 패배. 사망하지는 않는다.
                        battle = false;
                        battleLose = true;
                    }
                    else
                    {
                        // 적의 턴
                        if (monsterHp >= 0) // 적이 이미 죽은 경우 공격은 생략한다.
                        {
                            int sum = ((monsterPower / 10) * 8) + rand() % (monsterPower - ((monsterPower / 10) * 8));
                            cout << "\n" << monsterName << "의 공격! / " << monsterCrying << endl;
                            damage = sum - CharacterDefence;

                            if (damage <= 0) // 내 방어력이 더 높은 경우
                            {
                                cout << monsterName << "의 공격은 별로 통하지 않았다!" << endl;
                                CharacterHp--; // 방어를 하지 않은 경우에는 적어도 체력이 1은 줄어듦
                            }
                            else 
                            {
                                cout << damage << "의 대미지를 받았다!" << endl;
                                CharacterHp -= damage;
                            }
                            
                            if (guard)
                            {
                                if (damage <= 0)
                                {
                                    cout << monsterName << "의 공격을 완벽하게 막아냈다!" << endl;
                                    CharacterHp++; // 방어를 한 경우 체력이 1도 줄지 않음. (위에서 줄어든 체력 다시 복구)
                                }
                                else
                                {
                                    cout << monsterName << "의 공격을 막아냈다!" << endl;
                                }
                                
                            }
                            
                        }

                        // 턴 종료시 계산
                        damage = 0;
                        battleAction = 0;

                        if (guard) // 방어 종료 및 방어력 복구
                        {
                            if (ammor == "없음")
                            {
                                CharacterDefence = 0;
                            }
                            else
                            {
                                CharacterDefence /= 2;
                            }
                            guard = false;
                        }

                        if (CharacterHp <= 0) // 전투 패배
                        {
                            battleWin = false;
                            cout << "[ 전투에서 패배했습니다...... ]" << endl;
                            battle = false;
                            battleLose = true;
                        }
                        if (monsterHp <= 0) // 전투 승리
                        {
                            cout << "[ 전투에서 승리하였습니다!!! ]" << endl;
                            battle = false;
                        }
                        
                    }
                    
                } // 전투 종료

                cout << "\n";

                if (battleWin)
                {
                    int itemLoot = 1 + rand() % 10;
                    if (itemLoot > 5 ) // 50%의 확률로 몬스터의 전리품을 드랍한다.
                    {
                        item = monster->Droptable("").front(); // 드랍테이블에서 아이템 이름을 받아온다
                        price = 100;
                        count = 1;
                        itemType = "기타";
                        inv.addItem(item, price, 1, itemType);
                        // 모든 몬스터 전리품은 상점에 판매시 개당 100원인 기타아이템이다.
                    }
                    else if (itemLoot > 3) // 40%의 확률로 상점에서 판매하는 것과 동일한 성능의 소모품을 드랍한다.
                    {
                        item = "체력포션";
                        price = 30;
                        count = 1;
                        itemType = "소모";
                        inv.addItem(item, price, 1, itemType);
                    }
                    else if (itemLoot > 1)
                    {
                        item = "힘의영약";
                        price = 60;
                        count = 1;
                        itemType = "소모";
                        inv.addItem(item, price, 1, itemType);
                    }
                    else // 아무것도 드랍이 되지 않은 경우.
                    {
                        item = "없음";
                    }

                    int Exp = 50; // 획득경험치 50 고정, 최대레벨인 경우 획득하지 않음.
                    int Gold = 100 + rand() % 101; // 획득 골드 100~200;
                    cout << "[ 전투 결과 ]" << endl;
                    if (CharacterLevel > 10)
                    {
                        cout << "획득 경험치 : " << Exp << endl;
                    }
                    cout << "획득 골드 : " << Gold << "G" << endl;
                    inv.addGold(Gold);

                    if (item != "없음")
                    {
                        cout << "획득 아이템 : " << item << endl;
                    }

                    CharacterExp += Exp;
                    
                }

                if (CharacterExp >= 100 && CharacterLevel < 10)
                {
                    cout << "\n[ 레벨업을 하였습니다! ] " << endl;

                    CharacterExp -= 100;

                    cout << "[ 레벨 : " << CharacterLevel++ << " -> " << CharacterLevel << " ]\n";
                    cout << "[ 최대 체력 : " << CharacterMaxhp << " -> ";
                    CharacterMaxhp = CharacterMaxhp + (CharacterLevel * 20);
                    cout << CharacterMaxhp << " ]\n";
                    cout << "[ 공격력 : " << CharacterPower << " -> ";
                    CharacterPower = (CharacterPower - weaponOption) + (CharacterLevel * 5);
                    cout << CharacterPower << " ]";
                    if (weaponOption != 0)
                    {
                        cout << "[+" << weaponOption << "]";
                    }
                    cout << "\n";
                }
                
                CharacterHp = CharacterMaxhp; // 전투 종료 후 체력 자동 회복

                delete monster;
                
                cout << "\n\n[ 몬스터 토벌을 종료합니다 ]" << endl;

                if (battleLose) // 패배하거나 도주한 경우 마을로 돌아간다.
                {
                    cout << "\n\n[ 마을로 돌아갑니다 ]" << endl;
                    battleLose = false;
                    actionChoice = 0;
                    break;
                }
                else
                {
                    cout << "\n[ 더 토벌하시겠습니까? ]" << endl;
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
                    bool notBuy = false;
                    cout << "[ 무엇을 구매하시겠습니까? ]" << endl;
                    cout << "\n[01][무기] 숏소드 | 200G | 공격력 50 증가" << endl;
                    cout << "[02][무기] 롱소드 | 800G | 공격력 90 증가" << endl;
                    cout << "[03][무기] 더블배럴샷건 | 2000G | 공격력 300 증가" << endl;
                    cout << "[04][갑옷] 천갑옷 | 100G | 방어력 20 증가" << endl;
                    cout << "[05][갑옷] 철갑옷 | 500G | 방어력 40 증가" << endl;
                    cout << "[06][갑옷] 방탄복 | 1200G | 방어력 100 증가" << endl;
                    cout << "[07][소모] 체력포션 | 50G | 전투중 체력 300 회복" << endl;
                    cout << "[08][소모] 힘의영약 | 100G | 전투중 공격력 50 증가" << endl;
                        
                    cin >> actionChoice;

                    switch (actionChoice)
                    {
                        case '1' :
                        {
                            item = "숏소드";
                            price = 200;
                            count = 1;
                            itemType = "무기";
                            break;
                        }
                        case '2':
                        {
                            item = "롱소드";
                            price = 800;
                            count = 1;
                            itemType = "무기";
                            break;
                        }
                        case '3':
                        {
                            item = "더블배럴샷건";
                            price = 2000;
                            count = 1;
                            itemType = "무기";
                            break;
                        }
                        case '4':
                        {
                            item = "천갑옷";
                            price = 100;
                            count = 1;
                            itemType = "갑옷";
                            break;
                        }
                        case '5':
                        {
                            item = "철갑옷";
                            price = 500;
                            count = 1;
                            itemType = "갑옷";
                            break;
                        }
                        case '6':
                        {
                            item = "방탄복";
                            price = 1500;
                            count = 1;
                            itemType = "갑옷";
                            break;
                        }
                        case '7':
                        {
                            item = "체력포션";
                            price = 50;
                            itemType = "소모";
                            break;
                        }
                        case '8':
                        {
                            item = "힘의영약";
                            price = 100;
                            itemType = "소모";
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
                        cout << "\"그런 물건은 안팝니다.\"" << endl;
                        break;
                    }
                    else
                    {
                        if (itemType == "소모") // 소모품인 경우 여러개 구매 가능
                        {
                            cout << "\"몇개를 구매하시겠습니까?\"" << endl;
                            cin >> count;

                            cout << "\n[ " << item << "을 개당 " << price << "G에" << count << "개를 구매하시겠습니까? ]" << endl;
                            cout << " [총 구매 가격 " << price * count << "G ]" << endl;
                            cout << "[1]네 / [2] 아니오" << endl;
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
                                    cout << "\n[ " << item << "을 " << count << "개 구매하였습니다 ]" << endl;
                                    inv.reduceGold(price*count);
                                }
                            }
                        }
                        else // 구매하는 물건이 소모품이 아닌 경우
                        {   
                            cout << "\n[ " << item << "을(를)" << price << "G에 구매하시겠습니까? ]" << endl;
                            cout << "[1]네 / [2] 아니오" << endl;
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
                                    cout << "\n[ " << item << "을(를) 구매하였습니다 ]" << endl;
                                    inv.reduceGold(price);
                                }
                            }
                        } 

                        if (notBuy) // 소지금이 부족한 경우
                        {
                            cout << "[ 소지금이 부족합니다... ]" << endl;
                            inv.showGold();
                        }
                        else
                        {
                            price = ((price / 10) * 6); // 나중에 아이템을 판매할 때는 60%의 가격으로 판매하기.
                            inv.addItem(item, price, count, itemType);

                            if (itemType != "소모")
                            {
                                cout << "[ 지금 장착하시겠습니까? ]" << endl;
                                cout << "[1] 네 / [2] 아니오" << endl;
                                cin >> actionChoice;

                                if (actionChoice == '1')
                                {
                                    cout << "[ ";

                                    if (itemType == "무기") // 무기 장착
                                    {
                                        if (weapon != "없음") // 이미 무기를 장착중이면 해제하고 인벤토리에 추가
                                        {
                                            cout << weapon << "을(를) 해제하고 ";
                                            CharacterPower -= weaponOption;
                                            
                                            // 장착중인 아이템의 판매가 확인
                                            if (weapon == "숏소드")
                                            {
                                                price = 120;
                                            }
                                            else if (weapon == "롱소드")
                                            {
                                                price = 480;
                                            }
                                            else // 더블배럴샷건
                                            {
                                                price = 1200;
                                            }
                                            inv.addItem(weapon, price, 1, itemType);
                                        }
                                        // 아이템 장착하기
                                        if (item == "숏소드")
                                        {
                                            weaponOption = 50;
                                        }
                                        else if (weapon == "롱소드")
                                        {
                                            weaponOption = 90;
                                        }
                                        else if (weapon == "더블배럴샷건")
                                        {
                                            weaponOption = 300;
                                        }
                                        CharacterPower += weaponOption;
                                        weapon = item;
                                        inv.removeItem(item, 1);

                                    } // 무기 장착 종료
                                    else if (itemType == "갑옷")// 갑옷 장착
                                    {
                                        if (ammor != "없음") // 이미 갑옷을 장착중
                                        {
                                            cout << ammor << "을(를) 해제하고 ";
                                            CharacterDefence -= ammorOption;

                                            // 장착중인 아이템의 판매가 확인
                                            if (ammor == "천갑옷")
                                            {
                                                price = 60;
                                            }
                                            else if (ammor == "철갑옷")
                                            {
                                                price = 300;
                                            }
                                            else // 방탄복
                                            {
                                                price = 720;
                                            }
                                            inv.addItem(ammor, price, 1, itemType);
                                        }
                                        // 아이템 장착하기
                                        if (item == "천갑옷")
                                        {
                                            ammorOption = 20;
                                        }
                                        else if (weapon == "철갑옷")
                                        {
                                            ammorOption = 40;
                                        }
                                        else if (weapon == "방탄복")
                                        {
                                            ammorOption = 100;
                                        }
                                        CharacterDefence += ammorOption;
                                        ammor = item;
                                        inv.removeItem(item, 1);
                                    } // 방어구 장착 종료

                                    cout << item << "을(를) 장착합니다 ]" << endl;
                                }// 장비 장착 종료
                            }

                            cout << "\n\"감사합니다\"\n" << endl;
                            inv.showGold();
                            cout << "\n\"또 필요한 것이 있으실까요?\"\n" << endl;
                            actionChoice = 0;
                            break;
                        }
                    } // 유효한 구매는 여기까지

                    break; // 구매 종료
                }
                case '2':
                {
                    
                    inv.showInventory();
                    string inputItem;

                    cout << "\n \" 무엇을 판매하시겠습니까?\"" << endl;
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
                    break;
                }

                }



            }
            break;
        }
        case '3': //캐릭터 상태창 확인
        {
            cout << "======= [ 상태창 ] =======" << endl;
            cout << "| 이름 : " << CharacterName << endl;
            cout << "| 레벨 : " << CharacterLevel;
            if (CharacterLevel == 10)
            {
                cout << " (Max)";
            }
            else
            {
                cout << " (Exp:" << CharacterExp << "/100)";
            }
            cout << endl;
            cout << "| 체력 : " << CharacterHp << " / " << CharacterMaxhp << endl;
            cout << "| 공격 : " << CharacterPower << endl;
            cout << "| 방어 : " << CharacterDefence << endl;
            cout << "| 장비 : 무기 [" << weapon << "]";
            if (weaponOption != 0)
            {
                cout << "[+" << weaponOption << "]";
            }
            cout << " 갑옷 [" << ammor << "]";
            if (ammorOption != 0)
            {
                cout << "[+" << ammorOption << "] " << endl;
            }
            cout << "\n";
            int k = 1;
            if (weapon != "없음")
            {
                cout << "[" << k++ << "] 무기해제 ";
            }
            if (ammor != "없음")
            {
                cout << "[" << k++ << "] 갑옷해제 ";
            }
            cout << "[" << k++ << "] 상태창닫기 ";
            
            cin >> actionChoice;

            switch (actionChoice)
            {
                case '1' :
                {
                    cout << "\n";
                    if (weapon != "없음")
                    {
                        cout << "[" << weapon << "을(를) 해제합니다]" << endl;

                        // 장착중인 아이템의 판매가 확인
                        if (weapon == "숏소드")
                        {
                            price = 120;
                        }
                        else if (weapon == "롱소드")
                        {
                            price = 480;
                        }
                        else // 더블배럴샷건
                        {
                            price = 1200;
                        }
                        inv.addItem(weapon, price, 1, "무기");
                        weapon = "없음";
                        CharacterPower -= weaponOption;
                        weaponOption = 0;
                    }
                    else if (ammor != "없음")
                    {
                        cout << "[" << ammor << "을(를) 해제합니다]" << endl;

                        // 장착중인 아이템의 판매가 확인
                        if (ammor == "천갑옷")
                        {
                            price = 60;
                        }
                        else if (ammor == "철갑옷")
                        {
                            price = 300;
                        }
                        else // 방탄복
                        {
                            price = 720;
                        }
                        inv.addItem(ammor, price, 1, "갑옷");
                        ammor = "없음";
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
                    if (ammor != "없음")
                    {
                        cout << "[" << ammor << "을(를) 해제합니다]" << endl;

                        // 장착중인 아이템의 판매가 확인
                        if (ammor == "천갑옷")
                        {
                            price = 60;
                        }
                        else if (ammor == "철갑옷")
                        {
                            price = 300;
                        }
                        else // 방탄복
                        {
                            price = 720;
                        }
                        inv.addItem(ammor, price, 1, "갑옷");
                        ammor = "없음";
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
        
        case '4': // 인벤토리 확인
        {
            inv.showInventory();
            inv.showGold();

            cout << "\n[1] 장비 장착 / [2] 인벤토리 닫기 \n";
            cin >> actionChoice;

            if (actionChoice == '1')
            {
                int k;
                cout << "\n[ 장착할 아이템의 번호를 입력해주세요 ]\n";
                cin >> k;

                auto info = inv.ItemInfoIndex(k);
                string sum1 = get<0>(info); // 아이템 이름

                cout << "\n[ ";

                if (sum1 == "숏소드" || sum1 == "롱소드" || sum1 == "더블배럴샷건")
                {
                    itemType = "무기";
                }
                else if (sum1 == "천갑옷" || sum1 == "철갑옷" || sum1 == "방탄복")
                {
                    itemType = "갑옷";
                }
                else if (sum1 != "")
                {
                    cout << "은(는) 장착할 수 없는 아이템입니다. ]" << endl;
                }
                else
                {
                    cout << "[ 에러가 발생했습니다!] \n\n\n";
                }

                item = sum1;

                if (itemType == "무기") // 무기 장착
                {
                    if (weapon != "없음") // 이미 무기를 장착중이면 해제하고 인벤토리에 추가
                    {
                        cout << weapon << "을(를) 해제하고 ";
                        CharacterPower -= weaponOption;

                        // 장착중인 아이템의 판매가 확인
                        if (weapon == "숏소드")
                        {
                            price = 120;
                        }
                        else if (weapon == "롱소드")
                        {
                            price = 480;
                        }
                        else // 더블배럴샷건
                        {
                            price = 1200;
                        }
                        inv.addItem(weapon, price, 1, itemType);
                    }
                    // 아이템 장착하기
                    if (item == "숏소드")
                    {
                        weaponOption = 50;
                    }
                    else if (weapon == "롱소드")
                    {
                        weaponOption = 90;
                    }
                    else if (weapon == "더블배럴샷건")
                    {
                        weaponOption = 300;
                    }
                    CharacterPower += weaponOption;
                    weapon = item;
                    inv.removeItem(item, 1);
                    cout << item << "을(를) 장착합니다 ]" << endl;
                } // 무기 장착 종료
                else if (itemType == "갑옷")// 갑옷 장착
                {
                    if (ammor != "없음") // 이미 갑옷을 장착중
                    {
                        cout << ammor << "을(를) 해제하고 ";
                        CharacterDefence -= ammorOption;

                        // 장착중인 아이템의 판매가 확인
                        if (ammor == "천갑옷")
                        {
                            price = 60;
                        }
                        else if (ammor == "철갑옷")
                        {
                            price = 300;
                        }
                        else // 방탄복
                        {
                            price = 720;
                        }
                        inv.addItem(ammor, price, 1, itemType);
                    }
                    // 아이템 장착하기
                    if (item == "천갑옷")
                    {
                        ammorOption = 20;
                    }
                    else if (weapon == "철갑옷")
                    {
                        ammorOption = 40;
                    }
                    else if (weapon == "방탄복")
                    {
                        ammorOption = 100;
                    }
                    CharacterDefence += ammorOption;
                    ammor = item;
                    inv.removeItem(item, 1);
                    cout << item << "을(를) 장착합니다 ]" << endl;
                } // 방어구 장착 종료

            }
            actionChoice = 0;
            break;
        }
        case '5':
        {
            cout << "[ 게임을 종료합니다 ]";
            game = false;
            break;
        }


        } // 행동 반복문 중단
     
    }
    
}