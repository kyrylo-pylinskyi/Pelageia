//
// Created by pylinskyi.k on 24/10/2023.
//

#ifndef PELAGEIA_IMMERSIVE_PLAYER_H
#define PELAGEIA_IMMERSIVE_PLAYER_H

#include "Character.h"
#include "Physics/Vector2D.h"
#include "Physics/RigidBody.h"
#include "Animation/Animation.h"
#include "Physics/Collider.h"
#include "Animation/SpriteAnimation.h"

#define FORWARD 1
#define BACKWARD -1
#define UPWARD -1
#define DOWNWARD 1
#define JUMP_TIME = 10
#define JUMP_FORCE = 10


class Player : public Character
{
public:
    Player(Properties* props);

    virtual void Draw() override;
    virtual void Update(float dt) override;
    virtual void Clean() override;
    virtual void HandleAnimation() override;

private:
    bool m_IsJumping = false;
    bool m_IsRolling = false;
    float m_Velocity = 0;
    int m_HorizontalAxis = 0;
    int m_VerticalAxis = 0;

    Vector2D* m_LastSafePosition = new Vector2D(m_Properties->X, m_Properties->Y);
    Collider* m_Collider = new Collider();
    RigidBody* m_RigidBody = new RigidBody();
    SpriteAnimation* m_Animation = new SpriteAnimation();
    SDL_RendererFlip m_PlayerFlip = SDL_FLIP_NONE;
};

#endif  // PELAGEIA_IMMERSIVE_PLAYER_H