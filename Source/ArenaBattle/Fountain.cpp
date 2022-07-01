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

	//���ҽ� �ҷ�����
	static ConstructorHelpers::FObjectFinder<UStaticMesh>
		SM_BODY(TEXT("/Game/InfinityBladeGrassLands/Environments/Plains/Env_Plains_Ruins/StaticMesh/SM_Plains_Castle_Fountain_01.SM_Plains_Castle_Fountain_01"));
	//������ �ҷ����µ� �����ߴٸ�
	if (SM_BODY.Succeeded()) {
		//�����ϴ� ������Ʈ�� Body�� �ٿ��ش�
		Body->SetStaticMesh(SM_BODY.Object);
	}
	//���ҽ� �ҷ�����
	static ConstructorHelpers::FObjectFinder<UStaticMesh>
		SM_WATER(TEXT("/Game/InfinityBladeGrassLands/Effects/FX_Meshes/Env/SM_Plains_Fountain_02.SM_Plains_Fountain_02"));
	//������ �ҷ����µ� �����ߴٸ�
	if (SM_WATER.Succeeded()) {
		//�����ϴ� ������Ʈ�� Body�� �ٿ��ش�
		Water->SetStaticMesh(SM_WATER.Object);
	}

	static ConstructorHelpers::FObjectFinder<UParticleSystem>
		SM_SPLASH(TEXT("/Game/InfinityBladeGrassLands/Effects/FX_Ambient/Water/P_Water_Fountain_Splash_Base_01.P_Water_Fountain_Splash_Base_01"));
	//������ �ҷ����µ� �����ߴٸ�
	if (SM_SPLASH.Succeeded()) {
		//�����ϴ� ������Ʈ�� Body�� �ٿ��ش�
		Splash->SetTemplate(SM_SPLASH.Object);
	}
	RotateSpeed = 30.f;
	//Deltatime�� �˾Ƽ� �����
	Movement->RotationRate = FRotator(0.f, RotateSpeed, 0.f);
}

// Called when the game starts or when spawned
void AFountain::BeginPlay()
{
	//Super= C++���� Java���� ����ϴ� ���
	//�θ� Ŭ������ �ൿ���� ������ ���� �� Ŭ������ ������ �ൿ�� ��
	Super::BeginPlay();

	//�α� �����
	ABLOG_S(Warning);
	ABLOG(Warning,TEXT("Actor Name : %s, ID : %d, Location X : %.3f"),*GetName(), ID, GetActorLocation().X);
}

void AFountain::EndPlay(const EEndPlayReason::Type EndPlayerReason)
{
	//�θ� �� �� ����
	Super::EndPlay(EndPlayerReason);
	ABLOG_S(Warning);

}

void AFountain::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	ABLOG_S(Warning);
}

// Called every frame
//������ ���� �ð� = DeltaTime
//������ �����Ӱ��� �ð��� �����Ͽ� Tick �Լ��� �����Ѵ�
//void AFountain::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//	//�ð��� �帣�鼭 ȸ����Ű��
//	//���ǵ常ŭ yawȸ��
//	AddActorLocalRotation(FRotator(0.f, RotateSpeed * DeltaTime, 0.f));
//	//�������� tick�� ������ �Ͽ��� �ǳ� ������ �������� ������Ʈ�� ��������
//}
