// Sebastian Kenter

#include "PhotonTutorial.h"
#include "PTLoginGameMode.h"


void APTLoginGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
    Super::InitGame(MapName, Options, ErrorMessage);
}

void APTLoginGameMode::BeginPlay()
{
    Super::BeginPlay();

    UWorld* World = GetWorld();

    if (World)
    {
        if (World->GetMapName().Contains("LoginMap"))
        {
            Controller = World->SpawnActor<APTLoginController>(APTLoginController::StaticClass());
            Handler = NewObject<UPTLoginHandler>(Controller, "LoginHandler_");
            Handler->RegisterComponent();
        }
        else
        {
            UE_LOG(PT, Error, TEXT("Startup map not correct: %s"), *World->GetMapName());
        }
    }
}