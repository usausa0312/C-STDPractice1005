#pragma once
#include	<iostream>
#include	<functional>
#include	<vector>


using namespace std;

class GameObject
{
	//コピー禁止とかはめんどっちなので書きません(テヘペロ)
public:
	virtual ~GameObject() {};//デストラクタは仮想に
	virtual void Update() = 0;
protected:
	string m_name;

};

/// <summary>
/// /操作関数
/// </summary>
/// <param name="Hp">メンバ変数のHPアドレス</param>
void RitoAttack(int& Hp)  { cout << "Ritoが攻撃　"  << endl;    Hp -= 100; };
void ConomiAttack(int& Hp){ cout << "Conomiが攻撃" << endl;   Hp -= 500; };
void RyuseiAttack(int& Hp){ cout << "Ryuseiが攻撃" << endl;   Hp -=  Hp/10; };


class Rito:public GameObject
{
public:
	Rito() :m_HP(9000) {
		m_name = "Rito";
		cout << m_name << "　作成完了。初期HP:" << m_HP << endl;
	};
	~Rito() {
			cout << endl;
			cout << m_name <<"残りHP:" << m_HP <<endl;
			cout << m_name <<"削除" << endl;
		};
	void Update()override { 
		cout << endl;
		cout << m_name << ":Update開始" << endl;
		Damage(ConomiAttack);//一回目
		Damage(ConomiAttack);//二回目
		Damage(RyuseiAttack);//三回目
	};
private:
	void Damage(const std::function<void(int&)>& callback) {
		callback(m_HP);
		cout << m_name << "がダメージを受けた！現在のHPは:" << m_HP << endl;;
	};

	int m_HP;
};


class Conomi :public GameObject
{
public:
	Conomi() :m_HP(9500) { 
		m_name = "Conomi";
		cout << m_name << "作成完了。初期HP:" << m_HP << endl;
	};
	~Conomi() {
		cout << m_name << "残りHP:" << m_HP << endl;
		cout << m_name << "削除" << endl;
	};
	void Update()override {
		cout << endl;
		cout << m_name << ":Update開始" << endl;
		Damage(RyuseiAttack);//一回目
		Damage(RitoAttack);//二回目
		Damage(RyuseiAttack);//三回目
	};
private:
	void Damage(const std::function<void(int&)>& callback) {
		callback(m_HP);
		cout << m_name << "がダメージを受けた！現在のHPは:" << m_HP << endl;;
	};
	int m_HP;
};

class Ryusei :public GameObject
{
public:
	Ryusei() :m_HP(8000) {
		m_name = "Ryusei";
		cout << m_name << "作成完了。初期HP:" << m_HP << endl;
	};
	~Ryusei() {
		cout << m_name << "残りHP:" << m_HP << endl;
		cout << m_name << "削除" << endl;
	};
	void Update()override {
		cout << endl;
		cout << m_name << ":Update開始" << endl;
		Damage(RitoAttack);//一回目
		Damage(RitoAttack);//二回目
		Damage(ConomiAttack);//三回目
	};
private:
	void Damage(const std::function<void(int&)>& callback) {
		callback(m_HP);
		cout << m_name << "がダメージを受けた！現在のHPは:" << m_HP << endl;;
	};
	int m_HP;
};
