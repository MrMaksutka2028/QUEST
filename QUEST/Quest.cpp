#include "Quest.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>

heroClass character = { 0, 0, 0 };

Stats heroStats = {100};

Hero player = { "Player", "Age", character, heroStats };

void showStats() {
	std::cout << "\n\n���:" << player.name << "\n\n";
	std::cout << "�������:" << player.age << "\n\n";
	std::cout << "����: " << character.power << "\n\n";
	std::cout << "����������: " << character.intellect << "\n\n";
	std::cout << "��������: " << character.agility << "\n\n";
	std::cout << "�������:" << heroStats.hunger << "\n\n";
}

void starving() {
	heroStats.hunger -= 7;
	if (heroStats.hunger < 20)
		character.power -= 1;
}

void QUEST() {
	crtCharacter();
	part1();
}

void crtCharacter() {
	std::cout << "\t\t\tMAGIC QUEST\n����������� ����, ��������!\n";
	std::cout << "������ ��� ��� -> ";
	std::cin >> player.name;
	std::cout << "\n�������, " << player.name << "!\n ������ ���� ������� -> ";
	std::cin >> player.age;
	std::cout << "\n������!\n �������� ���� �����: ����(1), ���(2) ��� ���������(3) -> ";
	chooseClass();
	std::cout << "������! ������ �� �����!\n�� �������� �����!\n\n...........................................................\n\n";
}

void chooseClass() {
	int clas;
	std::cin >> clas;
	switch (clas) {
	case 1: std::cout << "\n������ ���� ����� - ����\n\n";
		character.power = 3; break;
	case 2: std::cout << "\n������ ���� ����� - ���\n\n";
		character.intellect = 3; break;
	case 3: std::cout << "\n������ ���� ����� - ���������\n\n";
		character.agility = 3; break;
	default: std::cout << "������! ������� ����� ������ 1-3 -> ";  chooseClass(); break;
	}
}

void part1() {
	std::cout << "--�� ���������� � ����������� ����� ����. ����� � �����, �� ����������� ������\n\n"
		<< player.name << " - \" ��� ��� �? � ������ �� �����, ����� ������ �����. � ����� ����� �� �����. ��������, ��� ������� ���� �� ����. \"";  
	char g = _getch();
	if (g == 's')
		showStats();
	starving();
	std::cout << "\n\n--�� ����� �� ��������. ����� ������ ������, ���������� ����\n\n"
		<< player.name << " - \" � ���� ����������� ���������� ���(1), ���� ����� �� ������ �����.(2)\" ";
	int n;
	std::cin >> n;
	switch (n) {
	case 1: 
		if (character.power >= 3)
			std::cout << "--�� ���������� ������.\n\n" << player.name << " - \" ���! ����������! ������ ����� ��������. \"\n\n";
		heroStats.hunger -= 10;
		g = _getch();
		if (n == 's')
			showStats();
		starving();
		if (character.power < 3)
			std::cout << "--��� �� ������� ���.\n\n" << player.name << " - \" ������, ������� ����� �� ������ �����. \"\n\n";
		starving();
		g = _getch();
		if (n == 's')
			showStats();
		break;
	case 2: std::cout << player.name << " - \" ����� �� ������ �����. \"\n\n";
		starving(); 
		g = _getch();
		if (n == 's')
			showStats(); 
		break;
	}
	std::cout << "--�� ����� ������ � ����� � ����.\n\n" << player.name
	<< " - \" ����! ����� �� �������� ����, �� �� �������� �� ������.\n\n ";
	std::cout << "� ���� ����������� ������ ����� ����(1), ��� ����� ����� ������(2).\"\n\n";
	std::cin >> n;
	switch(n) {
	case 1: 
		if (character.agility >= 3){
			std::cout << "--�������� �� ���������� ����, ���� �� ����� �����������. \n�� �� �������� �������� � ����� ��������� ����� ����.\n";
			std::cout << "����� ����� ���� ��������, �� �� ��������� �� ������ ������.\n\n" << player.name << " - \"������ ����!";
			std::cout << " ��� �������. ������ � ���� ���� ������.\n\n";
			g = _getch();
			if (n == 's')
				showStats();
			starving();
			std::cout << "--�� ����� �� ��������.\n\n" << player.name << " - \" � ���� ����� ���� ������(1), ���� �������(2).\" ";
			std::cin >> n;
			switch (n) {
			case 1: 
				markus1();
				 break;
			case 2: 
				village1();
				break;
			}
			starving();
		}	
		if (character.agility < 3) {
			std::cout << "--������� �� �����, �� �������� � �� ����� � ����.\n\n" << player.name << " - \" � ���! \" ";
		}
		break;
	case 2: 
		village2(); break;
	}
}

void markus1() {
	int n;
	std::cout << "\n\n--�� ����� ������. ��� �� ������ �����, �� ������ � ��������� ������. ��� ��������� �������, �� ������� �������.\n\n";
	n = _getch();
	std::cout << player.name << " - \" ��, ����� ����� �����. \"\n\n�� ����� �� ����. ������� � �����, �� �����������.\n..............\n ";
	n = _getch();
	std::cout << "����� �� ������.\n\n" << player.name << " - \" ������, ������ ��� ����...\"\n\n ";
	n = _getch();
	std::cout << "\n\n--����������, ����� �����������.\n"
		<< "�� ������ ����� ������ � ������-����� ������ � � ������� � �����.\n\n" << "������ - \" ����������, ������! ��� ���� ������� �� ���?\"\n\n";
	n = _getch();
	std::cout << player.name << " - \" ������ ����! � ������� � ���� � ��  �����, ��� � � ��� ��� ��������. ��� ����� �� ����, ������ ����.\n"
		<< "��� ����� ������. \" \n\n";
	n = _getch();
	std::cout << "������ - \" ������. ������� � ���. \"\n\n "
		<< "--�� ������ ������ � ������.\n\n";
	n = _getch();
	std::cout << player.name << " - \" ���! ������� ������ ����...����� ������..�� �������? \" \n\n";
	n = _getch();
	std::cout << "������ - \" ��-��..� �� ������. � ���������. \" \n\n"
		<< player.name << " - \" ���! \"\n\n������ - \" �� ��, ������ ����� �������������. �� ��� - ������. � ��� ���� �����, ������? \"\n\n";
	n = _getch();
	std::cout << player.name << " - \" ���� ����� " << player.name << "  \" \n\n������ - \" ������. � �������� ������ ����. ";
	n = _getch();
	std::cout << "���� ����� ������� ������, �� ��� ����� ��������� ��������� �����.\n";
	n = _getch();
	std::cout << "��� ����������� ��� �����������:\n ���������� ���� -"
		<< " ����� � ���������� ����; \n";
	n = _getch();
	std::cout << "���� ������� ���� - ��� �������� � ������� ����; \n";
	n = _getch();
	std::cout << "������� - ���� - ������� ���� ������.\n\n";
	std::cout << "� ��� ���� �����, ����� �� ��� ��������������� � ����.\n\n";
	n = _getch();
	std::cout << "--�� �������� ����� � ����� �� �����.\n\n " << player.name << " - \" ������� � ����� � ���������� ����.\" \n\n";
	starving();
	n = _getch();
	std::cout << "--�� ����������� � ���������� ����. ����� � ��, �� ����� ��������� �� ����.\n\n";
	n = _getch();
	starving();
	std::cout << player.name << " - \" �, ������ ��� ��� ����� ����. ����� ���.\"\n\n�� ������� ����.\n\n ";
	n = _getch();
	starving();
	std::cout << player.name << " - \" 1-� ���������� ����. \"\n\n--�� ����������� � �������� ���.\n\n";
	n = _getch();
	starving();
	std::cout << player.name << " - \" ��� ����� �������. ������ �����. ������� ���� ����������.\n\n\"--�� ����������� � ������.\n\n";
	n = _getch();
	starving();
	std::cout << player.name << " - \" ��� � ������! � ���� ����������. �������� ����� �������. \"\n\n--�� ����� ������� � ����, �� �� ������ ���. �� �������� ��� � �����. ";
	n = _getch();
	starving();
	std::cout << player.name << " - \" ��! ������, �� ��������! ����� ������ ���� � �������! \"\n\n";
	n = _getch();
	starving();
	std::cout << "�� ����������� � ������. ����� � �������, �� ������ ��� ��� �����������.\n\n";
	n = _getch();
	std::cout << "������ - \" �������! ���, ���� ������ �������. ������, ����� ��� ���������. � � ���� ����� �����. \"\n\n ";
	n = _getch();
	std::cout << "--�� ������� ��������� � ��� ����� �����.\n\n������ ������� �������.....\n\n";
	n = _getch();
	std::cout << "������ - \" ����� �����! ����� ���. \"\n\n�� ������ �����.\n\n" << player.name << " - \" � ������ ���������.... \"\n\n.........";
	n = _getch();
	std::cout << "--�� ����������.\n\n" << player.name << " - \" ������, � �����. ������� � �������? \"\n\n������ - \" ��� ����. �� ���, �������� ���-������? \n\n ";
	n = _getch();
	std::cout << player.name << " - \" ���������...� ���� �� ������ - ClifBurg, �� ���� �� �����. ����� ������� �� ������ ����� � ����� �������� � ������. ��� ��, ��� � ��������. \" \n\n";
	n = _getch();
	std::cout << "������ - \" ����. ClifBurg - ��������� ������ �����. \n�� ���� �� ����� ������, �� ����� ��� ��� ����������� ����, ���� ����� ������� � �������, ��� ����� � ������ ���� ���������. \n���� ����������� ������� � ������.\n";
	n = _getch();
	std::cout << "���..������ ��� ���� ������. �����, ���� �� ���������� � ����� �����������. ������ � �������, � �����!. \" \n\n";
	std::cout << "--�� �������� ������ ���������� ������. ��� ���� �������������� ���������� �� 1.\n\n";
	character.power += 1;
	character.intellect += 1;
	character.agility += 1;
	n = _getch();
	std::cout << player.name << " - \" �������, ������! �� �������! \" \n\n";
	std::cout << "--����� ��������� � �������� �� ����������� � �������.";
	starving();
}

void village1() {
	int n;
	std::cout << "--�� ����� ������� � ������ � �������.";
	n = _getch();
	std::cout << "--����� � �������, ��� �������� �������� �������.";
	n = _getch();
	std::cout << "�������� - \" ����������� ����, ������! ��� ������ ���� � ����� �������! ���� �� � ��� �� ������? \"\n\n";
	n = _getch();
	std::cout << player.name << " - \" ��, � �� ����� ������������� �����, ����� ���������� � ����. ������ ���������� �����, ��� � ��� �� ����������? \"\n\n";
	n = _getch();
	std::cout << "�������� - \" �������! � ������ ���� � ���� �������.��� ������ ����� �������(������) � ��������� �� �� �����. \"\n\n";
	n = _getch();
	std::cout << "--�������� ����� ��� � ����.\n\n";
	n = _getch();
	std::cout << "�������� - \" ���. ����� �� ������ ����� ������. ����� �� ����������, ���� ����� ����� ��������� � ���� �� ��������. \"\n\n";
	n = _getch();
	std::cout << player.name << " - \" ��, � �����. �������! \"\n\n";
	n = _getch();
	std::cout << "--������ �� ������ ����� ������ � ���� �������.\n\n";
}

void village2() {
	int n;
	std::cout << player.name << " - \" ��������, ����� ����� ����� ������ \"";
	std::cout << "\n\n--�� ����� ����� ���� � ������ � �������.";
	n = _getch();
	std::cout << "--����� � �������, ��� �������� �������� �������.\n\n";
	n = _getch();
	std::cout << "�������� - \" ����������� ����, ������! ��� ������ ���� � ����� �������! ���� �� � ��� �� ������? \"\n\n";
	n = _getch();
	std::cout << player.name << " - \" ��, � �� ����� ������������� �����, ����� ���������� � ����. ������ ���������� �����, ��� � ��� �� ����������? \"\n\n";
	n = _getch();
	std::cout << "�������� - \" �������! � ������ ���� � ���� �������.��� ������ ����� �������(������) � ��������� �� �� �����. \"\n\n";
	n = _getch();
	std::cout << "--�������� ����� ��� � ����.\n\n";
	n = _getch();
	std::cout << "�������� - \" ���. ����� �� ������ ����� ������. ����� �� ����������, ���� ����� ����� ��������� � ���� �� ��������. \"\n\n";
	n = _getch();
	std::cout << player.name << " - \" ��, � �����. �������! \"\n\n";
	n = _getch();
	std::cout << "--������ �� ������ ����� ������ � ���� �������.\n\n";
}

void crtTasks() {
	std::string path = "quest1.txt";
	std::ofstream out;
	out.open(path, std::ios::out);
	if (out.is_open()) {
		std::string str = "������ � �������.\n-����� ����� � ������� � ������ ������� �������� 5 ����� � 3 �����.\n���������� -> 4 ������������, 4 ����, 0 ����������.\n������� - 250 �����.";
		out << str;
	}
	else
		std::cout << "������ �������� �����.";
	out.close();

	std::string path2 = "quest2.txt";
	out.open(path2, std::ios::out);
	if (out.is_open()) {
		std::string str = "������ �� �����.\n-����� ����� �� ����� � ������ ������� ������� ������.\n���������� -> 3 ������������, 0 ����, 0 ����������.\n������� - 150 �����";
		out << str;
	}
	else
		std::cout << "������ �������� �����.";
	out.close();
}