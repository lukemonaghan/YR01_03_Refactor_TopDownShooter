#include "Controllers/EnemyController.h"

void cEnemyController::Setup(int Enemies){
	iEnemies = Enemies;
	cEnemy tmp;
	texID = tmp.Create();
}
void cEnemyController::CreateEnemy(){
	Enemies.push_back(cEnemy(texID,(rand()%2048)-1024,(rand()%2048)-1024));
}
int cEnemyController::GetSize(){
	return Enemies.size();
}
void cEnemyController::Update(cPlayer *Plr,cMap1 *map,cPickupController *PickCon,float dt){
	if (GetSize() < iEnemies){
		CreateEnemy();
	}
	std::vector<cEnemy>::iterator i = Enemies.begin();
	bool temp = false;
	while (i!=Enemies.end()) {
		temp = i->Update(*Plr,map,dt);
		if (temp){
			int chance = rand()%10;
			if (chance == 1){
				PickCon->CreatePickup(i->vect);
			}
			i = Enemies.erase(i);
			iEnemies++;
		}else{
		i++; 
		}
    }
}

int cEnemyController::Check(Vector2 vect,float rad){
	std::vector<cEnemy>::iterator i = Enemies.begin();
	int tid = 0;
	while (i!=Enemies.end()) {
		//Collisions
		if (CheckCircle(vect,i->vect,rad)){
			return tid;
		} else {
			tid++;
			i++; 
		}
    }
	return -1;
};

void cEnemyController::Draw(){
	std::vector<cEnemy>::iterator i = Enemies.begin();
	while (i!=Enemies.end()) {
		i->Draw();
		i++; 
    }
};

void cEnemyController::Health(int tid, int damage){
	Enemies.at(tid).Health -= damage;
}

void cEnemyController::Cleanup(){
	iEnemies = 5;
	Enemies.clear();
}