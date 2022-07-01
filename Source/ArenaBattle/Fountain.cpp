// Fill out your copyright notice in the Description page of Project Settings.


#include "Fountain.h"
#include "ArenaBattle.h"

// Sets default values
AFountain::AFountain()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BODY"));
	Water = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WATER"));
	Light = CreateDefaultSubobject<UPointLightComponent>(TEXT("Light"));
	Splash = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Splash"));
	Movement = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("Movement"));


	RootComponent = Body;
	Water->SetupAttachment(Body);
	Light->SetupAttachment(Body);
	Splash->SetupAttachment(Body);


	Water->SetRelativeLocation(FVector(0.f, 0.f, 135.f));
	Light->SetRelativeLocation(FVector(0.f, 0.f, 195.f));
	Splash->SetRelativeLocation(FVector(0.f, 0.f, 195.f));

	//리소스 불러오기
	static ConstructorHelpers::FObjectFinder<UStaticMesh>
		SM_BODY(TEXT("/Game/InfinityBladeGrassLands/Environments/Plains/Env_Plains_Ruins/StaticMesh/SM_Plains_Castle_Fountain_01.SM_Plains_Castle_Fountain_01"));
	//에셋을 불러오는데 성공했다면
	if (SM_BODY.Succeeded()) {
		//실존하는 오브젝트를 Body에 붙여준다
		Body->SetStaticMesh(SM_BODY.Object);
	}
	//리소스 불러오기
	static ConstructorHelpers::FObjectFinder<UStaticMesh>
		SM_WATER(TEXT("/Game/InfinityBladeGrassLands/Effects/FX_Meshes/Env/SM_Plains_Fountain_02.SM_Plains_Fountain_02"));
	//에셋을 불러오는데 성공했다면
	if (SM_WATER.Succeeded()) {
		//실존하는 오브젝트를 Body에 붙여준다
		Water->SetStaticMesh(SM_WATER.Object);
	}

	static ConstructorHelpers::FObjectFinder<UParticleSystem>
		SM_SPLASH(TEXT("/Game/InfinityBladeGrassLands/Effects/FX_Ambient/Water/P_Water_Fountain_Splash_Base_01.P_Water_Fountain_Splash_Base_01"));
	//에셋을 불러오는데 성공했다면
	if (SM_SPLASH.Succeeded()) {
		//실존하는 오브젝트를 Body에 붙여준다
		Splash->SetTemplate(SM_SPLASH.Object);
	}
	RotateSpeed = 30.f;
	//Deltatime을 알아서 계산함
	Movement->RotationRate = FRotator(0.f, RotateSpeed, 0.f);
}

// Called when the game starts or when spawned
void AFountain::BeginPlay()
{
	//Super= C++보단 Java에서 사용하는 방식
	//부모 클래스의 행동부터 진행한 다음 내 클래스의 고유한 행동을 함
	Super::BeginPlay();

	//로그 남기기
	ABLOG_S(Warning);
	ABLOG(Warning,TEXT("Actor Name : %s, ID : %d, Location X : %.3f"),*GetName(), ID, GetActorLocation().X);
}

void AFountain::EndPlay(const EEndPlayReason::Type EndPlayerReason)
{
	//부모가 할 일 먼저
	Super::EndPlay(EndPlayerReason);
	ABLOG_S(Warning);

}

void AFountain::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	ABLOG_S(Warning);
}

// Called every frame
//프레임 간의 시간 = DeltaTime
//엔진이 프레임간의 시간을 측정하여 Tick 함수에 전달한다
//void AFountain::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//	//시간이 흐르면서 회전시키기
//	//스피드만큼 yaw회전
//	AddActorLocalRotation(FRotator(0.f, RotateSpeed * DeltaTime, 0.f));
//	//움직임을 tick에 구현을 하여도 되나 정교한 움직임은 컴포넌트로 구현하자
//}

