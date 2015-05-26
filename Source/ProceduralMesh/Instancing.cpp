// Fill out your copyright notice in the Description page of Project Settings.

#include "ProceduralMesh.h"
#include "Instancing.h"


// Sets default values
AInstancing::AInstancing()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AInstancing::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInstancing::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

