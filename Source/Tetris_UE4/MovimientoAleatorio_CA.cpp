// Fill out your copyright notice in the Description page of Project Settings.


#include "MovimientoAleatorio_CA.h"

// Sets default values for this component's properties
UMovimientoAleatorio_CA::UMovimientoAleatorio_CA()
{
    // Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
    // off to improve performance if you don't need them.
    PrimaryComponentTick.bCanEverTick = true;

    // ...
    RadioMovimiento = 10.0f;
    AnchoMovimiento = 10.0f;
    AltoMovimiento = 10.0f;
    ProfundidadMovimiento = 0.0f;

    TiempoAcumulado = 0.0;
    TiempoLimite = 0.2;
    //TiempoLimiteLimite = 0.0;
}

// Called when the game starts
void UMovimientoAleatorio_CA::BeginPlay()
{
    Super::BeginPlay();

    // ...

}


// Called every frame
void UMovimientoAleatorio_CA::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    // ...
    TiempoTranscurrido += DeltaTime;

    if (EjecutarAccion && TiempoTranscurrido >= 0.2f)
    {
        TiempoAcumulado = TiempoAcumulado + TiempoTranscurrido;

            AActor* Padre = GetOwner();
            if (Padre)
            {
                int32 XAleatorio = FMath::RandRange(-1, 1);
                int32 YAleatorio = FMath::RandRange(-1, 1);
                int32 ZAleatorio = FMath::RandRange(-1, 1);
                // Find a new position for the object to go to 
                auto NuevaPosicion = Padre->GetActorLocation() +
                    FVector
                    (
                        XAleatorio * ProfundidadMovimiento,
                        YAleatorio * AnchoMovimiento,
                        ZAleatorio * AltoMovimiento
                    );
                Padre->SetActorLocation(NuevaPosicion);
            }

        TiempoTranscurrido = 0.0f;
    }

    if (TiempoAcumulado >= 3.0f)
    {
        EjecutarAccion = false;
    }

}