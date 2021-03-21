// Copyright Epic Games, Inc. All Rights Reserved.

#include "TEST_PlatMedSource.h"
#include "Modules/ModuleManager.h"
#include "Engine.h"
#include "Engine/World.h"
#include "Engine/Level.h"
#include "Misc/CoreDelegates.h"

class FPlatMedSourceModuleImpl : public IModuleInterface
{
	virtual void StartupModule() override
	{
		FCoreDelegates::OnPostEngineInit.AddLambda([]()
		{
			GEngine->OnLevelActorListChanged().AddLambda([]()
			{
				for (FWorldContext Context : GEngine->GetWorldContexts())
				{
					if (Context.WorldType == EWorldType::Editor)
					{
						TArray<UTexture2D*> OutLightMapsAndShadowMaps;
						for (ULevel* Level : Context.World()->GetLevels())
						{
							Context.World()->GetLightMapsAndShadowMaps(Level, OutLightMapsAndShadowMaps);
						}
					}
				}
			});
		});
	}

	virtual void ShutdownModule() override
	{
	}

	virtual bool IsGameModule() const override
	{
		return true;
	}
};

IMPLEMENT_PRIMARY_GAME_MODULE(FPlatMedSourceModuleImpl, TEST_PlatMedSource, "TEST_PlatMedSource");