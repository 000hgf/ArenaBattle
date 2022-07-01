// Fill out your copyright notice in the Description page of Project Settings.


#include "ABGameMode.h"
#include "ABPawn.h"
#include "ABPlayerController.h"


//게임 모드의 생성자 = 게임의 기본 폰이나, 상태도, 플레이어 컨트롤러 설정을 해줌
AABGameMode::AABGameMode()
{
	//기본 폰 정의
	DefaultPawnClass = AABPawn::StaticClass();
	//기본 플레이어컨트롤러 정의
	PlayerControllerClass = AABPlayerController::StaticClass();
}

void AABGameMode::PostLogin(APlayerController* NewPlayer)
{
	ABLOG(Warning, TEXT("PostLogin Begin"));
	Super::PostLogin(NewPlayer);
	ABLOG(Warning, TEXT("PostLogin End"));

}
