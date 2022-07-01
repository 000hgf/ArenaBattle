// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"
#include "GameFramework/RotatingMovementComponent.h"
#include "GameFramework/Actor.h"
#include "Fountain.generated.h"

UCLASS()
class ARENABATTLE_API AFountain : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFountain();

protected:
	// Called when the game starts or when spawned
	//플레이를 시작하는데는 어떤 사유가 굳이 필요없다
	virtual void BeginPlay() override;
	//플레이를 끝내는 이유는 다양하다.
	//엔진의 기준에서는 오류가 나서나 플레이어가 종료하거나...
	virtual void EndPlay(const EEndPlayReason::Type EndPlayerReason) override;
	//엑터에 속한 모든 컴포넌트의 세팅이 완료된 경우 호출하는 함수
	virtual void PostInitializeComponents() override;
public:	
	// Called every frame
	//virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* Body;

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* Water;

	UPROPERTY(VisibleAnywhere)
		UPointLightComponent* Light;

	UPROPERTY(VisibleAnywhere)
		UParticleSystemComponent* Splash;

	//중력의 영향을 받지않는 타입
	//FloatingPawnMovement
	//지정한 속도대로 회전하는 타입
	//RotatingMovement
	//지정한 위치로 액터를 이동시키는 타입
	//InterpMovement
	//액터의 중력의 영향을 받아서 포물선을 그리는 투사체의 움직임을 제공하는 타입
	//ProjectileMovement
	UPROPERTY(VisibleAnywhere)
	URotatingMovementComponent* Movement;

	UPROPERTY(EditAnywhere, Category=ID)
	int32 ID;

private : 
	//AllowPrivateAccess
	//코드상에선 private 에디터에선 수정 가능
	//메타데이터를 true로 주자
	UPROPERTY(EditAnywhere, Category = Stat, Meta=(AllowPrivateAccess = true))
	float RotateSpeed;
};
