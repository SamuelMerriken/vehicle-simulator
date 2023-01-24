#include <iostream>
#include <bullet/btBulletDynamicsCommon.h>

class Vehicle {
public:
    Vehicle(btDynamicsWorld* world, const btVector3& position) : world_(world) {
        // create the chassis
        btCollisionShape* chassisShape = new btBoxShape(btVector3(1, 0.5, 2));
        btCompoundShape* compound = new btCompoundShape();
        btTransform localTrans;
        localTrans.setIdentity();
        localTrans.setOrigin(btVector3(0, 1, 0));
        compound->addChildShape(localTrans, chassisShape);

        btDefaultMotionState* chassisMotionState = new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), position));
        btRigidBody::btRigidBodyConstructionInfo chassisRigidBodyCI(800, chassisMotionState, compound, btVector3(0, 0, 0));
        chassis_ = new btRigidBody(chassisRigidBodyCI);
        world_->addRigidBody(chassis_);

        // create the wheels
        btCollisionShape* wheelShape = new btCylinderShapeX(btVector3(0.4, 0.2, 0.4));

        btTransform wheelTransform;
        btVector3 wheelPosition[4] = {
            btVector3(-0.9, -0.4, 1.2),
            btVector3(-0.9, -0.4, -1.2),
            btVector3(0.9, -0.4, 1.2),
            btVector3(0.9, -0.4
