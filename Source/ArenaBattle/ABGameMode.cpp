// Fill out your copyright notice in the Description page of Project Settings.


#include "ABGameMode.h"
#include "ABPawn.h"
#include "ABPlayerController.h"


//���� ����� ������ = ������ �⺻ ���̳�, ���µ�, �÷��̾� ��Ʈ�ѷ� ������ ����
AABGameMode::AABGameMode()
{
	//�⺻ �� ����
	DefaultPawnClass = AABPawn::StaticClass();
	//�⺻ �÷��̾���Ʈ�ѷ� ����
	PlayerControllerClass = AABPlayerController::StaticClass();
}

void AABGameMode::PostLogin(APlayerController* NewPlayer)
{
	ABLOG(Warning, TEXT("PostLogin Begin"));
	Super::PostLogin(NewPlayer);
	ABLOG(Warning, TEXT("PostLogin End"));

}