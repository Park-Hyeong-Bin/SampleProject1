#include <iostream>
using namespace std;
int main() {

	char userName[50];
	char charactorClass[50];
	char hardcoreinput;

	;



	//1.
	int level = 1;
	int hp = 100;
	int mp = 100;

	//스탯
	float strength = 50;
	float dexterity = 50;
	float vitality = 50;
	float energy = 50;


	float attackDamage = strength * 0.2;
	float attackSpeed = dexterity / 10.0;
	float movingSpeed = dexterity / 30;
	int fireResist = 0;
	int lightningResist = 0;
	int coldResist = 0;
	int poisonResist = 0;


	bool isHardcore = true;

	cin >> hardcoreinput;
	if (hardcoreinput == 1) {
		isHardcore = true;
	}
	else {
		isHardcore = false;
	}

	cout << "[ Character Creation ]\n";
	cout << "Input your name : ";
	cin >> userName;
	cout << "Input your Class : ";
	cin >> charactorClass;
	cout << "\n::::::::::::Welcom to the Sanctuary::::::::::::\n";
	cout << "UserName : [" << userName << "]\n";
	//2.변수에 저장된 데이터 출력
	cout << "----------------Character Status----------------\n";
	cout << "Class : " << charactorClass << "\n";
	cout << "Level" << level << "\n";
	cout << "HP : " << hp << "\n";
	cout << "MP : " << mp << "\n";
	cout << "Attack Speed : " << attackSpeed << "\n";
	cout << "Strength : " << strength << "\n";
	cout << "Dexterity : " << dexterity << "\n";
	cout << "Vitality : " << vitality << "\n";
	cout << "Energy : " << energy << "\n";
	cout << "Fire Resistance : " << fireResist << "%\n";
	cout << "Lightning Resistance : " << lightningResist << "%\n";
	cout << "Cold Resistance : " << coldResist << "%\n";
	cout << "Poison Resistance : " << poisonResist << "%\n";


	cout << "Hardcore Mode : " << isHardcore << "(1 : true, 0 : false)\n";
	cout << "--------------------------------------------------\n";

	//3 size of
	cout << "[Memory Check] int type size : " << sizeof(hp) << " bytes\n";
	cout << "[Memory Check] bool type size : " << sizeof(isHardcore) << " bytes\n";



	int goblinHP = 30;
	int action;

	cout << "\n[System] 고블린을 조우하였습니다!\n";

	while (goblinHP > 0 && hp > 0) {
		cout << "\n[고블린 체력 : " << goblinHP << " | 내 체력 : " << hp << " ]\n";
		cout << "1. Attack : ";
		cin >> action;

		if (action == 1) {
			//플레이어 공격
			goblinHP -= attackDamage;
			cout << "=> 당신은 고블린을 공격했습니다! ( - " << attackDamage << ")\n";

			//고블린 반격
			if (goblinHP > 0) {
				hp -= 30;
				cout << "=>고블린이 당신을 공격했습니다! (-30)\n";
			}
		}
		else {
			cout << "유효하지 않는 공격입니다.! 유효한 공격을 선택하세요\n";
			hp -= 30;
			cout << "이미친 (-30)\n";
		}
	}
	cout << "\n";
	if (hp <= 0) {
		cout << "[System] 유다희...\n";
	}
	else {
		cout << "[System] 당신이 고블린을 처치했습니다! \n";
	}



	return 0;

}