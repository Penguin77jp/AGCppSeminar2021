#include <iostream>
#include <vector>
#include <cmath>

#include "Enemy.h"
#include "Player.h"

void PrintAllStatus(std::ostream& cout, Player player, std::vector<Enemy> enemys);
bool EnemyEliminated(std::vector<Enemy>);

int main()
{
	HP playerHP(10);
	Player  player(playerHP);

	HP enemyHP(3);
	std::vector<Enemy> enemys{ Enemy(enemyHP),Enemy(enemyHP),Enemy(enemyHP) };
	Enemy enemy1(enemyHP);

	while (true)
	{
		PrintAllStatus(std::cout, player, enemys);
		if (player.GetHP() <= 0 || EnemyEliminated(enemys)) {
			break;
		}

		int targetEnemy;
		std::cout << "�ǂ̓G�ɍU�����܂����H" << std::endl
			<< "1~" << enemys.size() << "�͈̔͂œ��͂��ĉ������B";
		std::cin >> targetEnemy;


		//error target
		if (targetEnemy > enemys.size() || targetEnemy < 0) {
			std::cout << "�͈͊O���I������܂����B" << std::endl;
			continue;
		}
		if (enemys[targetEnemy-1].GetHP() <= 0) {
			std::cout << "���Ɏ���ł��܂��B" << std::endl;
			continue;
		}
		
		std::cout << "Enemy " << targetEnemy << "�ɍU���I" << std::endl;
		enemys[targetEnemy - 1].Damaged(1);

		for (int i = 0; i < 5; ++i) {
			std::cout << std::endl;
		}

	}
	std::cout << "   THE  END   " << std::endl;
	return 0;
}

//print status
void PrintAllStatus(std::ostream& cout, Player player, std::vector<Enemy> enemys) {
	std::cout << "My HP : " << player.GetHP() << std::endl;
	std::cout << std::endl << std::endl;
	for (int i = 0; i < enemys.size(); ++i) {
		std::cout << "Name : Enemy" << i+1 << "  ";
	}
	std::cout << std::endl;
	for (int i = 0; i < enemys.size(); ++i) {
		std::cout << "HP   :";
		int t_hp = enemys[i].GetHP();
		int spaceN = 0;
		if (t_hp <= 0) {
			spaceN = 5;
		}
		else {
			spaceN = 6 - std::log10(t_hp);
		}
		for (int n = 0; n <= spaceN; ++n) {
			std::cout << " ";
		}
		std::cout << t_hp << "  ";
	}
	std::cout << std::endl;
}

bool EnemyEliminated(std::vector<Enemy> enemys) {
	for (int i = 0; i < enemys.size(); ++i) {
		if (enemys[i].GetHP() > 0) {
			return false;
		}
	}
	return true;
}