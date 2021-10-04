#include	"main.h"

int main(void)
{
	vector<unique_ptr<GameObject>> gameobjects;
	gameobjects.emplace_back( make_unique<Rito>());
	gameobjects.emplace_back( make_unique<Conomi>());
	gameobjects.emplace_back( make_unique<Ryusei>());

	for (const auto& v : gameobjects)
	{
		v->Update();
	}

	return 1;
}