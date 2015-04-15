/*
 * Polygon-4
 * Copyright (C) 2015 lzwdgc
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "Polygon4.h"
#include "Polygon4GameMode.h"

#include "Glider.h"

#include <Polygon4/API.h>

APolygon4GameMode::APolygon4GameMode(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
    UE_LOG(LogTemp, Warning, TEXT("APolygon4GameMode::APolygon4GameMode()"));

    DefaultPawnClass = AGlider::StaticClass();
}

APolygon4GameMode::~APolygon4GameMode()
{
    UNREGISTER_API(SpawnPlayer);

    UE_LOG(LogTemp, Warning, TEXT("APolygon4GameMode::~APolygon4GameMode()"));
}

void APolygon4GameMode::BeginPlay()
{
    Super::BeginPlay();
    
    REGISTER_API(SpawnPlayer, std::bind(&APolygon4GameMode::SpawnPlayer, this, std::placeholders::_1, std::placeholders::_2));

    API_CALL(OnOpenLevel);

    UE_LOG(LogTemp, Warning, TEXT("APolygon4GameMode::BeginPlay()"));
}

void APolygon4GameMode::ShowMenu()
{
    UE_LOG(LogTemp, Warning, TEXT("APolygon4GameMode::ShowMenu()"));
}

void APolygon4GameMode::SpawnPlayer(polygon4::Vector v, polygon4::Rotation r)
{
    GetWorld()->SpawnActor<AGlider>(FVector(v.x, v.y, v.z), FRotator(r.pitch, r.yaw, r.roll));
}