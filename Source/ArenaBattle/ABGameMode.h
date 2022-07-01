// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ArenaBattle.h" //EngineMinimal.h와 각종 매크로
#include "GameFramework/GameModeBase.h"
#include "ABGameMode.generated.h"

/**
 * 게임 플레이 버튼이 눌리면 게임모드에 의해서 다음과 같은 일들이 진행된다
 * 1. 플레이어 컨트롤러 생성
 * 2. 플레이어 폰 생성
 * 3. 플레이어 컨트롤러가 플레이어 폰에 빙의
 * 4. 게임 시작
 */
UCLASS()
class ARENABATTLE_API AABGameMode : public AGameModeBase
{
	GENERATED_BODY()
public :
	AABGameMode();
	//플레이어가 게임에 입장하는것은 로그인이라 한다
	//로그인 과정에 폰에 할당할 플레이어 컨트롤러 생성
	//로그인 완료시 PostLogin이라는 함수 생성
	//함수 내부에서 플레이어가 조종할 폰을 생성하고, 플레이어 컨트롤러가 빙의되는 작업이 거쳐진다
	virtual void PostLogin(APlayerController* NewPlayer) override;
};
