#include "CollisionHandling.h"
#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <typeinfo>
#include <typeindex>
#include "Mulan.h"
#include "Friend.h"
#include "Bullet.h"
#include "SmartEnemy.h"
#include "StupidEnemy.h"
#include"KingGate.h"
#include"CityGate.h"
#include"Plaster.h"
#include"Medication.h"
#include"Key.h"
#include "JailGate.h"
#include"BaseEnemy.h"
#include"Level.h"
#include"Gun.h"
#include"LifeGift.h"
#include "Snow.h"
namespace // anonymous namespace the standard way to make function "static"
{

    // primary collision-processing functions
    void smartBullet(BaseObject& smart, BaseObject& bullet, Level& level)
    {

        // To get the actual types and use them:
        SmartEnemy& smartEnemy = dynamic_cast<SmartEnemy&>(smart);
        Bullet& bul = dynamic_cast<Bullet&>(bullet);
        smartEnemy.updateDead();
        level.updateBullet();

    }
    //----------------------------------------------------------------
    void stupidBullet(BaseObject& stupid, BaseObject& bullet, Level& level)
    {
        StupidEnemy& stupidEnemy = dynamic_cast<StupidEnemy&>(stupid);
        Bullet& bul = dynamic_cast<Bullet&>(bullet);
  
        stupidEnemy.updateDead();
        level.updateBullet();
    }
    //----------------------------------------------------------------
    void mulanKingGate(BaseObject& mulan, BaseObject& kingGate, Level& level)
    {
        Mulan& playerMulan = dynamic_cast<Mulan&>(mulan);
        KingGate& kingGateObject = dynamic_cast<KingGate&>(kingGate);
        playerMulan.setPosition(playerMulan.getPrevPosition());
    }
    //----------------------------------------------------------------
    void mulanCityGate(BaseObject& mulan, BaseObject& cityGateObj, Level& level)
    {
        Mulan& playerMulan = dynamic_cast<Mulan&>(mulan);
        CityGate& CityObject = dynamic_cast<CityGate&>(cityGateObj);
        playerMulan.setPosition(playerMulan.getPrevPosition());
    }
    //----------------------------------------------------------------
    void mulanPlaster(BaseObject& mulan, BaseObject& plasterObj, Level& level)
    {
        Mulan& playerMulan = dynamic_cast<Mulan&>(mulan);
        Plaster& plasterObject = dynamic_cast<Plaster&>(plasterObj);
        plasterObject.updateDead();
        level.missionDone(plasterObject.getColor());
        level.updateMission(plasterObject.getColor(), PlasterMission);
    }
    //----------------------------------------------------------------
    void mulanMedication(BaseObject& mulan, BaseObject& MedicationObj, Level& level)
    {
        Mulan& playerMulan = dynamic_cast<Mulan&>(mulan);
        Medication& MedicationObject = dynamic_cast<Medication&>(MedicationObj);
        MedicationObject.updateDead();
        level.missionDone(MedicationObject.getColor());
        level.updateMission(MedicationObject.getColor(), MedicationMission);
    }
    //----------------------------------------------------------------
    void mulanKey(BaseObject& mulan, BaseObject& KeyObj, Level& level)
    {
        Mulan& playerMulan = dynamic_cast<Mulan&>(mulan);
        Key& KeyObject = dynamic_cast<Key&>(KeyObj);
        KeyObject.updateDead();
        level.openCityGate(KeyObject.getColor());
        level.missionDone(KeyObject.getColor());
        level.updateMission(KeyObject.getColor(), keyMission);
    }
    //----------------------------------------------------------------
    void mulanJailGate(BaseObject& mulan, BaseObject& JailGateObj, Level& level)
    {
        Mulan& playerMulan = dynamic_cast<Mulan&>(mulan);
        JailGate& JailGateObject = dynamic_cast<JailGate&>(JailGateObj);
        // KeyObject.updateDead();
    }
    //----------------------------------------------------------------
    void mulanSmartEnemies(BaseObject& mulan, BaseObject& enemy, Level& level)
    {
        Mulan& playerMulan = dynamic_cast<Mulan&>(mulan);
        SmartEnemy& enemies = dynamic_cast<SmartEnemy&>(enemy);
        playerMulan.updateLive(-1);
        playerMulan.setToFirstPosition(); //set position to start
        enemies.setToFirstPosition();
    }
    //----------------------------------------------------------------
    void mulanStupidEnemies(BaseObject& mulan, BaseObject& enemy, Level& level)
    {
        Mulan& playerMulan = dynamic_cast<Mulan&>(mulan);
        StupidEnemy& enemies = dynamic_cast<StupidEnemy&>(enemy);
        playerMulan.updateLive(-1);
        playerMulan.setToFirstPosition(); //set position to start
        enemies.setToFirstPosition();
    }
    //----------------------------------------------------------------
    void StupidEnemiesMulan(BaseObject& enemy, BaseObject& mulan, Level& level)
    {
        mulanStupidEnemies( mulan, enemy, level);
    }
    //------------------------------------------------------
    void SmartEnemiesMulan(BaseObject& enemy, BaseObject& mulan, Level& level)
    {
        mulanSmartEnemies(mulan, enemy, level);
    }
    //----------------------------------------------------------------
    void mulanBullet(BaseObject& mulan, BaseObject& bullet, Level& level)
    {
        Mulan& playerMulan = dynamic_cast<Mulan&>(mulan);
        Bullet& bulletObj = dynamic_cast<Bullet&>(bullet);
        playerMulan.updateLive(-1);
    }
    //----------------------------------------------------------------
    void mulanGuns(BaseObject& mulan, BaseObject& gun, Level& level)
    {
        Mulan& playerMulan = dynamic_cast<Mulan&>(mulan);
        Gun& gunObj = dynamic_cast<Gun&>(gun);
        gunObj.updateDead();
        playerMulan.updateGuns(1);
    }
    //----------------------------------------------------------------
    void mulanSnow(BaseObject& mulan, BaseObject& snow, Level& level)
    {
        Mulan& playerMulan = dynamic_cast<Mulan&>(mulan);
        Snow& snowObj = dynamic_cast<Snow&>(snow);
        playerMulan.setPosition(playerMulan.getPrevPosition());
    }
    //--------------------------------------------------------------
    void snowMulan(BaseObject& snow, BaseObject&  mulan, Level& level)
    {
        mulanSnow(mulan, snow, level);
    }
    //----------------------------------------------------------------
    void mulanLifeGift(BaseObject& mulan, BaseObject& lifegift, Level& level)
    {
        Mulan& playerMulan = dynamic_cast<Mulan&>(mulan);
        LifeGift& GiftObject = dynamic_cast<LifeGift&>(lifegift);
        if(playerMulan.getLive()<TOTAL_LIVE)
            playerMulan.updateLive(1);
        GiftObject.updateDead();
    }
    //----------------------------------------------------------------
    void stupidSnow(BaseObject& stupid, BaseObject& snow, Level& level)
    {
        StupidEnemy& stupitEnemy = dynamic_cast<StupidEnemy&>(stupid);
        Snow& snowObj = dynamic_cast<Snow&>(snow);
        if (stupitEnemy.getFaceRight())
            stupitEnemy.setFaceRight(false);
        else
            stupitEnemy.setFaceRight(true);
    }
    //----------------------------------------------------------------
    void smartSnow(BaseObject& smart, BaseObject& snow, Level& level)
    {
        SmartEnemy& smartEnemy = dynamic_cast<SmartEnemy&>(smart);
        Snow& snowObj = dynamic_cast<Snow&>(snow);
        if (smartEnemy.getFaceRight())
            smartEnemy.setFaceRight(false);
        else
            smartEnemy.setFaceRight(true);
    }
    //----------------------------------------------------------------
    void mulanKing(BaseObject& mulan, BaseObject& king, Level& level)
    {
        Mulan& playerMulan = dynamic_cast<Mulan&>(mulan);
        Friend& kingObject = dynamic_cast<Friend&>(king);
        kingObject.updateDead();
        playerMulan.setToFirstPosition();
    }
}
namespace // anonymous namespace – the standard way to make function "static"
{
    // Forward declaration of Level parameter in collision functions
    void smartBullet(BaseObject& smart, BaseObject& bullet, Level& level);
    void stupidBullet(BaseObject& stupid, BaseObject& bullet, Level& level);
    void mulanKingGate(BaseObject& mulan, BaseObject& kingGate, Level& level);
    void mulanCityGate(BaseObject& mulan, BaseObject& cityGateObj, Level& level);
    void mulanPlaster(BaseObject& mulan, BaseObject& plasterObj, Level& level);
    void mulanMedication(BaseObject& mulan, BaseObject& MedicationObj, Level& level);
    void mulanKey(BaseObject& mulan, BaseObject& KeyObj, Level& level);
    void mulanJailGate(BaseObject& mulan, BaseObject& JailGateObj, Level& level);
    void mulanSmartEnemies(BaseObject& mulan, BaseObject& enemy, Level& level);
    void mulanStupidEnemies(BaseObject& mulan, BaseObject& enemy, Level& level);
    void mulanBullet(BaseObject& mulan, BaseObject& bullet, Level& level);
    void mulanGuns(BaseObject& mulan, BaseObject& gun, Level& level);
    void mulanSnow(BaseObject& mulan, BaseObject& snow, Level& level);
    void snowMulan(BaseObject& snow, BaseObject& mulan, Level& level);
    void mulanLifeGift(BaseObject& mulan, BaseObject& lifegift, Level& level);
    void stupidSnow(BaseObject& stupid, BaseObject& snow, Level& level);
    void smartSnow(BaseObject& smart, BaseObject& snow, Level& level);
    void mulanKing(BaseObject& mulan, BaseObject& king, Level& level);

    using HitFunctionPtr = std::function<void(BaseObject&, BaseObject&, Level&)>;
    using KeyValue = std::pair<std::type_index, std::type_index>;
    using HitMap = std::map<KeyValue, HitFunctionPtr>;

    HitMap initializeCollisionMap()
    {
        HitMap phm;
        phm[KeyValue(typeid(SmartEnemy), typeid(Bullet))] = &smartBullet;
        phm[KeyValue(typeid(StupidEnemy), typeid(Bullet))] = &stupidBullet;
        phm[KeyValue(typeid(Mulan), typeid(KingGate))] = &mulanKingGate;
        phm[KeyValue(typeid(Mulan), typeid(CityGate))] = &mulanCityGate;
        phm[KeyValue(typeid(Mulan), typeid(Plaster))] = &mulanPlaster;
        phm[KeyValue(typeid(Mulan), typeid(Medication))] = &mulanMedication;
        phm[KeyValue(typeid(Mulan), typeid(Key))] = &mulanKey;
        phm[KeyValue(typeid(Mulan), typeid(JailGate))] = &mulanJailGate;
        phm[KeyValue(typeid(Mulan), typeid(StupidEnemy))] = &mulanStupidEnemies;
        phm[KeyValue(typeid(Mulan), typeid(SmartEnemy))] = &mulanSmartEnemies;
        phm[KeyValue(typeid(StupidEnemy), typeid(Mulan))] = &StupidEnemiesMulan;
        phm[KeyValue(typeid(SmartEnemy), typeid(Mulan))] = &SmartEnemiesMulan;
        phm[KeyValue(typeid(Mulan), typeid(Bullet))] = &mulanBullet;
        phm[KeyValue(typeid(Mulan), typeid(Gun))] = &mulanGuns;
        phm[KeyValue(typeid(Mulan), typeid(Snow))] = &mulanSnow;
        phm[KeyValue(typeid(Snow), typeid(Mulan))] = &snowMulan;
        phm[KeyValue(typeid(Mulan), typeid(LifeGift))] = &mulanLifeGift;
        phm[KeyValue(typeid(StupidEnemy), typeid(Snow))] = &stupidSnow; 
        phm[KeyValue(typeid(SmartEnemy), typeid(Snow))] = &smartSnow;
        phm[KeyValue(typeid(Mulan), typeid(Friend))] = &mulanKing;
        return phm;
    }

    HitFunctionPtr lookup(const std::type_index& class1, const std::type_index& class2)
    {
        static HitMap collisionMap = initializeCollisionMap();
        auto mapEntry = collisionMap.find(std::make_pair(class1, class2));
        if (mapEntry == collisionMap.end())
        {
            return nullptr;
        }
        return mapEntry->second;
    }

} // end namespace

void processCollision(BaseObject& object1, BaseObject& object2, Level& level)
{
    auto phf = lookup(typeid(object1), typeid(object2));
    if (!phf)
    {
        throw UnknownCollision(object1, object2);
    }
    phf(object1, object2, level);
}