#pragma once
#include	<iostream>
#include	<functional>
#include	<vector>


using namespace std;

class GameObject
{
	//�R�s�[�֎~�Ƃ��͂߂�ǂ����Ȃ̂ŏ����܂���(�e�w�y��)
public:
	virtual ~GameObject() {};//�f�X�g���N�^�͉��z��
	virtual void Update() = 0;
protected:
	string m_name;
};

/// <summary>
/// /HP����N���X
/// </summary>
/// <param name="Hp">�����o�ϐ���HP�A�h���X</param>

void RitoAttack(int& Hp) { cout << "Rito���U���@" << endl;    Hp -= 100; };
void ConomiAttack(int& Hp) { cout << "Conomi���U��" << endl;   Hp -= 500; };
void RyuseiAttack(int& Hp) { cout << "Ryusei���U��" << endl;   Hp -= Hp / 10; };
void BigHerbs(int& Hp) { cout << "��򑐂��g�p" << endl;   Hp += 100; };
void Herbs(int& Hp) { cout << "�򑐂��g�p" << endl;   Hp += 50; };
void MiniHerbs(int& Hp) { cout << "�~�j�򑐂��g�p" << endl;   Hp += 20; };



class Rito :public GameObject
{
public:
	Rito() :m_HP(9000) {
		m_name = "Rito";
		cout << m_name << "�@�쐬�����B����HP:" << m_HP << endl;
	};
	~Rito() {
		cout << endl;
		cout << m_name << "�c��HP:" << m_HP << endl;
		cout << m_name << "�폜" << endl;
	};
	void Update()override {
		cout << endl;
		cout << m_name << ":Update�J�n" << endl;
		Damage(ConomiAttack);//����
		Damage(ConomiAttack);//����
		Damage(RyuseiAttack);//�O���
		Recovery(BigHerbs);
	};
private:
	void Damage(const std::function<void(int&)>& callback) {
		callback(m_HP);
		cout << m_name << "���_���[�W���󂯂��I���݂�HP��:" << m_HP << endl;;
	};
	void Recovery(const std::function<void(int&)>& callback) {
		callback(m_HP);
		cout << m_name << "���_���[�W���񕜁I���݂�HP��:" << m_HP << endl;;
	};
private:
	int m_HP;
};


class Conomi :public GameObject
{
public:
	Conomi() :m_HP(9500) {
		m_name = "Conomi";
		cout << m_name << "�쐬�����B����HP:" << m_HP << endl;
	};
	~Conomi() {
		cout << m_name << "�c��HP:" << m_HP << endl;
		cout << m_name << "�폜" << endl;
	};
	void Update()override {
		cout << endl;
		cout << m_name << ":Update�J�n" << endl;
		Damage(RyuseiAttack);//����
		Damage(RitoAttack);//����
		Damage(RyuseiAttack);//�O���
		Recovery(Herbs);
	};
private:
	void Damage(const std::function<void(int&)>& callback) {
		callback(m_HP);
		cout << m_name << "���_���[�W���󂯂��I���݂�HP��:" << m_HP << endl;;
	};
	void Recovery(const std::function<void(int&)>& callback) {
		callback(m_HP);
		cout << m_name << "���_���[�W���񕜁I���݂�HP��:" << m_HP << endl;;
	};
private:
	int m_HP;
};

class Ryusei :public GameObject
{
public:
	Ryusei() :m_HP(8000) {
		m_name = "Ryusei";
		cout << m_name << "�쐬�����B����HP:" << m_HP << endl;
	};
	~Ryusei() {
		cout << m_name << "�c��HP:" << m_HP << endl;
		cout << m_name << "�폜" << endl;
	};
	void Update()override {
		cout << endl;
		cout << m_name << ":Update�J�n" << endl;
		Damage(RitoAttack);//����
		Damage(RitoAttack);//����
		Damage(ConomiAttack);//�O���
		Recovery(MiniHerbs);
	};
private:
	void Damage(const std::function<void(int&)>& callback) {
		callback(m_HP);
		cout << m_name << "���_���[�W���󂯂��I���݂�HP��:" << m_HP << endl;;
	};
	void Recovery(const std::function<void(int&)>& callback) {
		callback(m_HP);
		cout << m_name << "���_���[�W���񕜁I���݂�HP��:" << m_HP << endl;;
	};
private:
	int m_HP;
};
