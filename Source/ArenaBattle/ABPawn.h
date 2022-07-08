// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ArenaBattle.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "ABPawn.generated.h"

//폰의 요소 : 

UCLASS()
class ARENABATTLE_API AABPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AABPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void PostInitializeComponents() override;
	//폰이 플레이어 컨트롤러에 빙의된 시점
	virtual void PossessedBy(AController* aController) override;
public:
	//시각적 요소 -> 애니메이션(스켈레탈 매쉬)
	UPROPERTY(VisibleAnywhere, Category = Visual)
	USkeletalMeshComponent* Mesh;
	//충돌 (인간형 : 캡슐)
	UPROPERTY(VisibleAnywhere, Category = Collision)
	UCapsuleComponent* Capsule;
	//움직임 요소
	UPROPERTY(VisibleAnywhere, Category = Movement)
	UFloatingPawnMovement* Movement;
	//네비게이션(AI길찾기, 장판 깔아서 위에서 최소거리를 찾아 돌아다니는 A* 알고리즘 이용)

	//카메라
	UPROPERTY(VisibleAnywhere, Category = Camera)
	USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere, Category = Camera)
	UCameraComponent* Camera;
private:
	void UpDown(float NewAxisValue);
	void LeftRight(float NewAxisValue);
};
