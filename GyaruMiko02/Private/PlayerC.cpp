// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerC.h"
#include "GameFramework/Controller.h"
#include "Components/InputComponent.h"


// Sets default values
APlayerC::APlayerC()//constructor
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}







// Called when the game starts or when spawned
void APlayerC::BeginPlay()
{
	

	
}

// Called every frame
void APlayerC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Super::BeginPlay();

	//*if move button was pressed 
	if (bIsMoveFwdPress || bIsMoveBackPress || bIsMoveRightPress || bIsLeftPress) {

		bIsMoving = true;

	}


	if (bIsStartMoveEnd) {//*input direction value to idle->run (animBP) state first then input to run state (animBP) 

		inputStartMoveDirection = DirectionCal();
		inputDirection = DirectionCal();

	}
	else {

		inputDirection = DirectionCal();

	}

}

// Called to bind functionality to input
void APlayerC::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	

}

//*find Dirction input Function ,Return Value for Blend animation (run&idle->run)
float APlayerC::DirectionCal()
{

	int outPutDirection;

	if (bIsMoving) {
	
		//sum value from fwd n bwd key // fwd = 1 , bwd = -1 , not pressing = 0 
		int sumMoveFwd = (int)bIsMoveFwdPress +((int)bIsMoveBackPress*-1) ;
		//sum value from right n left key // right = 1 , left = -1 , not pressing = 0 
		int sumMoveSide = (int)bIsMoveRightPress + ((int)bIsLeftPress*-1);
		//
		float Sidemultipiler;
		//get current controller rotation(3rd cam)
		FRotator Rotation = Controller->GetControlRotation();
		float outPutDirection = Rotation.Yaw;
		//get current actor rotation (root bone)
		FRotator ActorRotation = GetActorRotation();
		
		
		//create multipiler for side move  
		if (sumMoveFwd != 0) {// if fwd bwd are not pressed with side move
		
			Sidemultipiler = 1;
		
		}
		else { // if fwd bwd are pressed with side-move key  , avarage degree 
		      
			Sidemultipiler = 0.5;
		 }
		
		
		
		if (sumMoveFwd==-1){//move fwd

			outPutDirection = outPutDirection + 180;
			Sidemultipiler = Sidemultipiler*-1;
			
		}
		
		if (sumMoveFwd == 1){//move back
		
			outPutDirection = outPutDirection;
		
			
		}
		
		if (sumMoveSide == 1) {//moveside Right
		
			float mulValue = outPutDirection + (Sidemultipiler * 90);
			//set outPutDirection by Delta rotation between actor and controller(3rd camera) 
			outPutDirection = DeltaRotator(mulValue, ActorRotation).Yaw;
			
		
		}

		if (sumMoveSide==-1){//move Left

			float mulValue  = outPutDirection + (Sidemultipiler * -90);
			//set outPutDirection by Delta rotation between actor and controller(3rd camera) 
			outPutDirection = DeltaRotator(mulValue, ActorRotation).Yaw;
           
		}
		 

	
		return outPutDirection;
	
	}
	else// if stop moving
	{
	
		outPutDirection = 0;
		return outPutDirection;
	
	}

}

//*delta Rotation Function
FRotator APlayerC::DeltaRotator(float A, FRotator B)
{
	
	FRotator makeRot = FRotator(0,0,A);
	FRotator Delta = makeRot - B;
	Delta.Normalize();	
	return Delta;
}

void APlayerC::MakeLean() {

	currentLean = 

}
