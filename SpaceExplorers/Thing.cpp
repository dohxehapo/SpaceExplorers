#include "stdafx.h"
#include "Thing.h"

#include "Engine.h"


ErrCode Thing::Draw(Doh3d::Sprite& pSprite, const D3DXVECTOR3& pOffset) const
{
	LOG("RealThing::Draw()");
	HRESULT hRes;

	hRes = pSprite.Get()->Draw(Doh3d::ResourceMan::GetTexture(m_prototype.Ti()).Get(),
							   &Doh3d::ResourceMan::GetTexture(m_prototype.Ti()).GetFrame(m_ac.GetCurrentFrame()),
							   0, &(m_position - pOffset), m_drawColor);
	if (hRes != S_OK)
	{
		echo("ERROR: Can't draw thing (type name: \"", m_prototype.TypeName(), "\").");
		return err_cantDrawThing;
	}

	return Entity::Draw(pSprite, pOffset);
}

ErrCode Thing::Load()
{
	ResetDrawColor();
	m_ac.SetAnimationSet(&m_prototype.AnimationSet());
	m_ac.PlayAnimation("Default", -1);
	return Doh3d::ITreeThing<ErrCode>::Load();
}

ErrCode Thing::Unload()
{
	return Doh3d::ITreeThing<ErrCode>::Unload();
}

ErrCode Thing::Update(float pDeltaTime)
{
	m_ac.Update(pDeltaTime);
	return Doh3d::ITreeThing<ErrCode>::Update(pDeltaTime);
}



bool Thing::IsPassable() const
{
	if (!m_prototype.IsPassable() &&
		!(IsDoor() && IsOpen()))
		return false;

	for (auto& child : m_childs)
	{
		Entity* pThing = dynamic_cast<Entity*>(child);
		if (pThing && !pThing->IsPassable())
			return false;
	}

	return true;
}

bool Thing::IsVentilated() const
{
	if (!m_prototype.IsVentilated() &&
		!(IsDoor() && IsOpen()))
		return false;

	for (auto& child : m_childs)
	{
		Entity* pThing = dynamic_cast<Entity*>(child);
		if (pThing && !pThing->IsVentilated())
			return false;
	}

	return true;
}


Entity* Thing::HitTest()
{
	Entity* pThing = Entity::HitTest();
	if (pThing != nullptr)
		return pThing;

	auto point = Engine::GetInstance()->GetScene().GetCursorAbsoluteCoords() - D3DXVECTOR2(m_position.x, m_position.y);
	return Doh3d::ResourceMan::GetTexture(m_prototype.Ti()).HitTest(point, m_ac.GetCurrentFrame()) ? this : nullptr;
}


ErrCode Thing::Interact()
{
	if (IsDoor())
	{
		if (IsOpen())
		{
			m_states.Remove(State::Open);
			m_ac.PlayAnimation("Close", 1);
		}
		else
		{
			m_states.Add(State::Open);
			m_ac.PlayAnimation("Open", 1);
		}
	}

	return err_noErr;
}
