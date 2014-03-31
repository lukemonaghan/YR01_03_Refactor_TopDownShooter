#include "Controllers/BulletController.h"

void cBulletController::Setup(){
	cBullet tmp;
	bullid = tmp.Create();
}
void cBulletController::CreateBullet(const Vector2 &Pos,float spd,float dir,float dt){
	Bullets.push_back(cBullet(bullid,Pos.x,Pos.y,dir,50,spd));
}
int cBulletController::GetSize(){
	return Bullets.size();
}
void cBulletController::Update(float dt,cMap1 *map,cEnemyController *enemycon){
	std::vector<cBullet>::iterator i = Bullets.begin();
	int did = 0;
	int tmp = 0;
	while (i!=Bullets.end()) {
       cBullet bul = *i;
		tmp = i->Update(dt,map);
		did = enemycon->Check(i->vect,8);
		if (tmp > 0){
			i = Bullets.erase(i);
		}else if (did > -1){
			i = Bullets.erase(i);
			enemycon->Health(did,50);
		}else{
		i++; 
		}
    }
}
void cBulletController::Draw(){
	std::vector<cBullet>::iterator i = Bullets.begin();
	int tid = 0;
	while (i!=Bullets.end()) {
		i->Draw();
		tid++;
		i++; 
    }
};

void cBulletController::Cleanup(){
	Bullets.clear();
}