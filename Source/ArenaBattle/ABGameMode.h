// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ArenaBattle.h" //EngineMinimal.h�� ���� ��ũ��
#include "GameFramework/GameModeBase.h"
#include "ABGameMode.generated.h"

/**
 * ���� �÷��� ��ư�� ������ ���Ӹ�忡 ���ؼ� ������ ���� �ϵ��� ����ȴ�
 * 1. �÷��̾� ��Ʈ�ѷ� ����
 * 2. �÷��̾� �� ����
 * 3. �÷��̾� ��Ʈ�ѷ��� �÷��̾� ���� ����
 * 4. ���� ����
 */
UCLASS()
class ARENABATTLE_API AABGameMode : public AGameModeBase
{
	GENERATED_BODY()
public :
	AABGameMode();
	//�÷��̾ ���ӿ� �����ϴ°��� �α����̶� �Ѵ�
	//�α��� ������ ���� �Ҵ��� �÷��̾� ��Ʈ�ѷ� ����
	//�α��� �Ϸ�� PostLogin�̶�� �Լ� ����
	//�Լ� ���ο��� �÷��̾ ������ ���� �����ϰ�, �÷��̾� ��Ʈ�ѷ��� ���ǵǴ� �۾��� ��������
	virtual void PostLogin(APlayerController* NewPlayer) override;
};
