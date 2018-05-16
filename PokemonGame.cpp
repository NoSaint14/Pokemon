#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
using namespace std;

class Base {
	public :
		string nama;
		int health, attack, defense, exp, damage;
		virtual void set_player(string,string,int,int,int) {}
		virtual void set_enemy(int,int,int) {}
};
class Player : public Base {
	public :
		string nama_player, weapon, armor, weapon_grade, armor_grade;
		int weapon_stats, armor_stats, level, expMax;
		void set_player(string name_player, string name, int darah, int atk, int def) {
			nama_player = name_player;
			nama = name;
			health = darah;
			attack = atk;
			defense = def;
			exp = 0;
			expMax=100;
			level = 99;
		}
};
class Enemy : public Base {
	public :
		int expUp;
		void set_enemy(int darah, int atk, int def) {
			int nama_monster;
			nama_monster = rand() % 10;
			switch(nama_monster) {
				case 0:
					nama = "Giant";
					break;
				case 1:
					nama = "Manticore";
					break;
				case 2:
					nama = "Harpy";
					break;
				case 3:
					nama = "Cerberus";
					break;
				case 4:
					nama = "Chimera";
					break;
				case 5:
					nama = "Apocalypse";
					break;
				case 6:
					nama = "Minotaur";
					break;
				case 7:
					nama = "Pithon";
					break;
				case 8:
					nama = "Siren";
					break;
				case 9:
					nama = "Scylla";
					break;
				case 10:
					nama = "Triton";
					break;
			}
			health = rand() % 300;
			attack = rand() % 75;
			defense = rand() % 75;
			exp = rand() % 100;
			expUp = exp;
		}
};
class Battle : public Player, Enemy {
	public :
		int count=0;
		void display(Player *player, Enemy *enemy) {
			cout << "Player Monster : " << player->nama << endl;
			cout << "Player Health  : " << player->health << endl;
			cout << "Player Attack  : " << player->attack << endl;
			cout << "Player Defense : " << player->defense << endl;
			cout << "Player Level   : " << player->level << endl;
			cout << "Player Exp     : " << player->exp << endl;
			cout << "Player Weapon  : " << player->weapon << " " << " Grade " << player->weapon_grade << "	Attack+" << player->weapon_stats << endl;
			cout << "Player Armor   : " << player->armor << " " << " Grade " << player->armor_grade << "	Defense+" << player->armor_stats << endl << endl;
		}
		void gameOver(Player *player, Enemy *enemy) {
			ofstream fo;
			cout << "Game Over" << endl;
			cout << "Nama Player    : " << player->nama_player << endl;
			cout << "Player Monster : " << player->nama << endl;
			cout << "Player Level   : " << player->level << endl;
			cout << "Player Exp     : " << player->exp << endl;
			cout << "Player Weapon  : " << player->weapon << " " << " Grade " << player->weapon_grade << "	Attack+" << player->weapon_stats << endl;
			cout << "Player Armor   : " << player->armor << " " << " Grade " << player->armor_grade << "	Defense+" << player->armor_stats << endl;
			cout << "Total Monster Killed : " << count << endl;
			if (count != 0) {
				fo.open("History.txt",ios::app);
				fo << "Nama Player    : " << player->nama_player << endl;
				fo << "Player Monster : " << player->nama << endl;
				fo << "Player Level   : " << player->level << endl;
				fo << "Player Exp     : " << player->exp << endl;
				fo << "Player Weapon  : " << player->weapon << " " << " Grade " << player->weapon_grade << "	Attack+" << player->weapon_stats << endl;
				fo << "Player Armor   : " << player->armor << " " << " Grade " << player->armor_grade << "	Defense+" << player->armor_stats << endl;
				fo << "Total Monster Killed : " << count << endl << endl;
				fo.close();
			}
		}
		void displayHistory() {
			ifstream fi;
			char sv_text;
			fi.open("History.txt",ios::app);
			if(!fi.fail()) {
              while (!fi.eof())
              {
                     fi.get(sv_text);
                     cout<<sv_text;
              }
              fi.close();
      		}
			else{
              cout<<"File tidak ditemukan"<<endl;
       		}
		}
		void getEquip(Player *player, Enemy *enemy) {
			string weapon_name, armor_name, weapon_grade, armor_grade;
			int rate_drop, drop_weapon, drop_armor, drop, weapon_stats, armor_stats;
			int choice;
			rate_drop = rand() % 100;
			if (rate_drop >= 0 && rate_drop < 41) {
				cout << "Player WIN" << endl;
				cout << "You get " << enemy->expUp << " exp from monster" << endl;
				cout << "You get drop from monster" << endl;
				drop = 1+rand() % 2;
				switch(drop) {
					case 1:
						drop_weapon = 1+rand() % 6;
						switch(drop_weapon) {
							case 1:
								weapon_name = "Mjolnir";
								weapon_stats = 75+rand() % 26;
								weapon_grade = "Legendary";
								cout << "Weapon : " << weapon_name << endl;
								cout << "Grade  : " << weapon_grade << endl;
								cout << "Stats  : " << "Attack +" << weapon_stats << endl;
								break;
							case 2:
								weapon_name = "Gungnir";
								weapon_stats = 50+rand() % 26;
								weapon_grade = "Rare";
								cout << "Weapon : " << weapon_name << endl;
								cout << "Grade  : " << weapon_grade << endl;
								cout << "Stats  : " << "Attack +" << weapon_stats << endl;
								break;
							case 3:
								weapon_name = "Excalibur";
								weapon_stats = 50+rand() % 26;
								weapon_grade = "Rare";
								cout << "Weapon : " << weapon_name << endl;
								cout << "Grade  : " << weapon_grade << endl;
								cout << "Stats  : " << "Attack +" << weapon_stats << endl;
								break;
							case 4:
								weapon_name = "Trident";
								weapon_stats = 25+rand() % 26;
								weapon_grade = "Common";
								cout << "Weapon : " << weapon_name << endl;
								cout << "Grade  : " << weapon_grade << endl;
								cout << "Stats  : " << "Attack +" << weapon_stats << endl;
								break;
							case 5:
								weapon_name = "Jingu Bang";
								weapon_stats = 25+rand() % 26;
								weapon_grade = "Common";
								cout << "Weapon : " << weapon_name << endl;
								cout << "Grade  : " << weapon_grade << endl;
								cout << "Stats  : " << "Attack +" << weapon_stats << endl;
								break;
							case 6:
								weapon_name = "Crescent Blade";
								weapon_stats = 25+rand() % 26;
								weapon_grade = "Common";
								cout << "Weapon : " << weapon_name << endl;
								cout << "Grade  : " << weapon_grade << endl;
								cout << "Stats  : " << "Attack +" << weapon_stats << endl;
								break;
						}
						cout << "Player Weapon  : " << player->weapon << " " << " Grade " << player->weapon_grade << "	Attack+" << player->weapon_stats << endl;
						cout << "Use Weapon?" << endl;
						cout << "1. Yes	2. No" << endl;
						cout << "Masukkan Pilihan : ";
						cin >> choice;
						if(choice == 1) {
							player->weapon = weapon_name;
							player->weapon_grade = weapon_grade;
							player->weapon_stats = weapon_stats;
							player->attack += weapon_stats;
							cout << "New Weapon Equipped" << endl;
						}
						else {
							cout << "New Weapon not Equipped" << endl;
						}
						break;
					case 2:
						drop_armor = 1+rand() % 6;
						switch(drop_armor) {
							case 1:
								armor_name = "Kamui";
								armor_stats = 75+rand() % 26;
								armor_grade = "Legendary";
								cout << "Armor  : " << armor_name << endl;
								cout << "Grade  : " << armor_grade << endl;
								cout << "Stats  : " << "Defense +" << armor_stats << endl;
								break;
							case 2:
								armor_name = "Assault Cuirass";
								armor_stats = 50+rand() % 26;
								armor_grade = "Rare";
								cout << "Armor  : " << armor_name << endl;
								cout << "Grade  : " << armor_grade << endl;
								cout << "Stats  : " << "Defense +" << armor_stats << endl;
								break;
							case 3:
								armor_name = "Shiva's Guard";
								armor_stats = 50+rand() % 26;
								armor_grade = "Rare";
								cout << "Armor  : " << armor_name << endl;
								cout << "Grade  : " << armor_grade << endl;
								cout << "Stats  : " << "Defense +" << armor_stats << endl;
								break;
							case 4:
								armor_name = "Blade Mail";
								armor_stats = 25+rand() % 26;
								armor_grade = "Common";
								cout << "Armor  : " << armor_name << endl;
								cout << "Grade  : " << armor_grade << endl;
								cout << "Stats  : " << "Defense +" << armor_stats << endl;
								break;
							case 5:
								armor_name = "Vanguard";
								armor_stats = 25+rand() % 26;
								armor_grade = "Common";
								cout << "Armor  : " << armor_name << endl;
								cout << "Grade  : " << armor_grade << endl;
								cout << "Stats  : " << "Defense +" << armor_stats << endl;
								break;
							case 6:
								armor_name = "Crimson Guard";
								armor_stats = 25+rand() % 26;
								armor_grade = "Common";
								cout << "Armor  : " << armor_name << endl;
								cout << "Grade  : " << armor_grade << endl;
								cout << "Stats  : " << "Defense +" << armor_stats << endl;
								break;
						}
						cout << "Player Armor   : " << player->armor << " " << " Grade " << player->armor_grade << "	Defense+" << player->armor_stats << endl;
						cout << "Use Armor?" << endl;
						cout << "1. Yes	2. No" << endl;
						cout << "Masukkan Pilihan : ";
						cin >> choice;
						if(choice == 1) {
							player->armor = armor_name;
							player->armor_grade = armor_grade;
							player->armor_stats = armor_stats;
							player->defense += armor_stats;
							cout << "New Armor Equipped" << endl;
						}
						else {
							cout << "New Armor not Equipped" << endl;
						}
						break;
				}
			}
			else {
				cout << "Player WIN" << endl;
				cout << "You only get " << enemy->expUp << " exp from monster" << endl;
				cout << "Press any key to continue" << endl;
				cin.ignore();cin.ignore();
			}
		}
		bool battle(Player *player, Enemy *enemy) {
			int turn = 1;
			int choice_battle, crit_atk;
			enemy->attack = enemy->attack * player->level;
			enemy->defense = enemy->defense * player->level;
			enemy->health = enemy->health * player->level;
			enemy->exp = enemy->exp * player->level;
			int tempHealth=player->health;
			while (enemy->health > 0 && player->health > 0) {
				system("CLS");
				cout << "Enemy Name   : " << enemy->nama << endl;
				cout << "Enemy Health : " << enemy->health << endl;
				cout << "Enemy Attack : " << enemy->attack << endl;
				cout << "Enemy Defense: " << enemy->defense << endl;
				cout << "1. Attack		2. Defense" << endl;
				cout << "Masukkan Pilihan : ";
				cin >> choice_battle;
				switch(choice_battle) {
					case 1:
						crit_atk = rand() % 100;
						if(crit_atk >= 25) {
							cout << "\nTurn " << turn << " Attack!!" << endl;
							if(player->attack < enemy->defense) {
								player->damage = 0;
								enemy->health = enemy->health;
							}
							else {
								player->damage = player->attack - enemy->defense;
								enemy->health = enemy->health - player->damage;
							}
							if(enemy->attack < player->defense) {
								enemy->damage = 0;
								player->health = player->health;
							}
							else {
								enemy->damage = enemy->attack - player->defense;
								player->health = player->health - enemy->damage;
							}
						}
						else {
							cout << "\nTurn " << turn << " Critical Attack!!" << endl;
							int tempCrit;
							tempCrit = player->attack;
							player->attack = player->attack * 2;
							if(player->attack < enemy->defense) {
								enemy->health = enemy->health;
							}
							else {
								player->damage = player->attack - enemy->defense;
								enemy->health = enemy->health - player->damage;
							}
							if(enemy->attack < player->defense) {
								player->health = player->health;
							}
							else {
								enemy->damage = enemy->attack - player->defense;
								player->health = player->health - enemy->damage;
							}
							player->attack = tempCrit;
						}
						cout << "Player Damage : " << player->damage << endl;
						cout << "Enemy Damage  : " << enemy->damage << endl;
						cout << "Turn " << turn << " Telah Selesai" << endl << endl;
						cout << "Current Stats" << endl;
						cout << "Player Health : " << player->health << endl;
						cout << "Player Attack : " << player->attack << endl;
						cout << "Player Defense: " << player->defense << endl << endl;
						cout << "Press any key to continue" << endl;
						cin.ignore();cin.ignore();
						turn++;
						break;
					case 2:
						cout << "Turn " << turn << " Defense!!" << endl;
						int tempAttack, tempDefense;
						tempAttack = player->attack;
						tempDefense = player->defense;
						player->attack = player->attack - rand() % 25;
						player->defense = player->defense + rand() %25;
						if(player->attack < enemy->defense) {
							enemy->health = enemy->health;
						}
						else {
							player->damage = player->attack - enemy->defense;
							enemy->health = enemy->health - player->damage;
						}
						if(enemy->attack < player->defense) {
							player->health = player->health;
						}
						else {
							enemy->damage = enemy->attack - player->defense;
							player->health = player->health - enemy->damage;
						}
						cout << "Player Damage : " << player->damage << endl;
						cout << "Enemy Damage  : " << enemy->damage << endl;
						cout << "Turn " << turn << " Telah Selesai" << endl << endl;
						player->attack = tempAttack;
						player->defense = tempDefense;
						cout << "Current Stats" << endl;
						cout << "Player Health : " << player->health << endl;
						cout << "Player Attack : " << player->attack << endl;
						cout << "Player Defense: " << player->defense << endl << endl;
						cout << "Press any key to continue" << endl;
						cin.ignore();cin.ignore();
						turn++;
						break;
						}
			}
			if (enemy->health <= 0) {
				count++;
				player->exp+=enemy->expUp;
				player->health=tempHealth;
				if(player->exp>=player->expMax){
					player->level++;
					player->attack +=25;
					player->health +=50;
					player->defense +=25;
					player->expMax+=100;
				}
				system("CLS");
				getEquip(player,enemy);
				system("CLS");
				display(player,enemy);
				cout << "Press any key to continue" << endl;
			}
			if (player->health <= 0) {
				cout << "Player LOSE" << endl;
				cin.ignore(); cin.ignore();
				system("CLS");
				gameOver(player,enemy);
				return true;
			}
			return false;
		}

};

int main() {
	bool kalah = false;
	srand(time(NULL));
	Player *player=new Player();
	Enemy *enemy=new Enemy();
	Battle btl;
	ofstream fo;
	ifstream fi;
	string name_player;
	int choice_awal, choice_menu;
	Awal :
	cout << "Turn Based Mini Game" << endl;
	cout << "Masukkan Nama Pemain : ";
	cin >> name_player;
	cout << "Pick Player Monster" << endl;
	cout << "1. Articuno	Health : 400 Attack : 75  Defense : 75" << endl;
	cout << "2. Moltres	Health : 400 Attack : 100 Defense : 50" << endl;
	cout << "3. Zapdos	Health : 400 Attack : 50  Defense : 100" << endl;
	cout << "Masukkan Pilihan : ";
	cin >> choice_awal;
	switch(choice_awal) {
		case 1:
			player->set_player(name_player,"Articuno",400,75,75);
			break;
		case 2:
			player->set_player(name_player,"Moltres",400,100,50);
			break;
		case 3:
			player->set_player(name_player,"Zapdos",400,50,100);
			break;
		default:
			cout << "Input anda salah!" << endl;
			cout << "Kembali" << endl;
			cin.ignore();
			system("CLS");
			goto Awal;
			break;
	}
	Menu :
	system("CLS");
	cout << "Turn Based Mini Game" << endl;
	cout << "1. Status Player Monster" << endl;
	cout << "2. Battle Start" << endl;
	cout << "3. Lihat History Game" << endl;
	cout << "4. Keluar Game" << endl;
	cout << "Masukkan Pilihan : ";
	cin >> choice_menu;
	switch(choice_menu) {
		case 1:
			system("CLS");
			btl.display(player,enemy);
			cout << "Press any key to continue" << endl;
			cin.ignore(); cin.ignore();
			goto Menu;
			break;
		case 2:
			system("CLS");
			enemy->set_enemy(50,100,50);
			kalah=btl.battle(player,enemy);
			cin.ignore(); cin.ignore();
			if(kalah==true){
				break;
			}
			goto Menu;
			break;
		case 3:
			system("CLS");
			btl.displayHistory();
			cin.ignore(); cin.ignore();
			goto Menu;
			break;
		case 4:
			system("CLS");
			btl.gameOver(player,enemy);
			break;
		default:
			cout << "Input Anda Salah" << endl << "Kembali ke Menu" << endl;
			cin.ignore();
			goto Menu;
			break;
	}
	return EXIT_SUCCESS;
}
