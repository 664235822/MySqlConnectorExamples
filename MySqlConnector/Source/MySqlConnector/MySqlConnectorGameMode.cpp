// Copyright Epic Games, Inc. All Rights Reserved.

#include "MySqlConnectorGameMode.h"
#include "MySqlConnectorCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMySqlConnectorGameMode::AMySqlConnectorGameMode(): MysqlConnectManager(nullptr)
{
}

void AMySqlConnectorGameMode::BeginPlay()
{
	Super::BeginPlay();
}

void AMySqlConnectorGameMode::Destroyed()
{
	MysqlConnectManager->Close();
	
	Super::Destroyed();
}

//更新数据库
void AMySqlConnectorGameMode::MySQL_UpdateArray_Server(const TArray<FString>& SqlArray)
{
	UpdateMySQLWorkerbool = true;
	bool IsSuccess = false;
	TArray<FString> SqlArrayCopy = SqlArray;
	const FLatentActionInfo LatentInfo(0, FMath::Rand(), TEXT("MySQL_UpdateArray_Callback"), this);
	MysqlConnectManager->AExecuteUpdate(SqlArrayCopy, IsSuccess, Msg, GetWorld(),
	                                    LatentInfo);
}

void AMySqlConnectorGameMode::MySQL_UpdateArray_Callback(bool IsSuccess)
{
	if (!IsSuccess)
	{
		UE_LOG(LogTemp, Warning, TEXT("update successful"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("update failed"));
	}
}

void AMySqlConnectorGameMode::MySql_InsertArray_Server(const TArray<FString>& SqlArray)
{
	UpdateMySQLWorkerbool = true;
	bool IsSuccess = false;
	TArray<FString> SqlArrayCopy = SqlArray;
	const FLatentActionInfo LatentInfo(0, FMath::Rand(), TEXT("MySQL_InsertArray_Callback"), this);
	MysqlConnectManager->AExecute(SqlArrayCopy, IsSuccess, Msg, GetWorld(), LatentInfo);
}

void AMySqlConnectorGameMode::MySQL_InsertArray_Callback(const bool IsSuccess)
{
	if (!IsSuccess)
	{
		UE_LOG(LogTemp, Warning, TEXT("insert successful"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("insert failed"));
	}
}

void AMySqlConnectorGameMode::MySql_DeleteArray_Server(const TArray<FString>& SqlArray)
{
	UpdateMySQLWorkerbool = true;
	bool IsSuccess = false;
	TArray<FString> SqlArrayCopy = SqlArray;
	const FLatentActionInfo LatentInfo(0, FMath::Rand(), TEXT("MySQL_DeleteArray_Callback"), this);
	MysqlConnectManager->AExecute(SqlArrayCopy, IsSuccess, Msg, GetWorld(), LatentInfo);
}

void AMySqlConnectorGameMode::MySQL_DeleteArray_Callback(const bool IsSuccess)
{
	if (!IsSuccess)
	{
		UE_LOG(LogTemp, Warning, TEXT("delete successful"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("delete failed"));
	}
}

void AMySqlConnectorGameMode::MySQL_Insert_Server(const FString& SqlQuery)
{
	UpdateMySQLWorkerbool = true;
	bool IsSuccess = false;
	FString SqlCopy = SqlQuery;
	int Index = 0;
	const FLatentActionInfo LatentInfo(0, FMath::Rand(), TEXT("MySQL_Update_Callback"), this);
	MysqlConnectManager->AInsert(SqlCopy, false, IsSuccess, Msg, Index, GetWorld(), LatentInfo);
}

void AMySqlConnectorGameMode::MySQL_Insert_CallBack(bool IsSuccess)
{
	if (!IsSuccess)
	{
		UE_LOG(LogTemp, Warning, TEXT("insert successful"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("insert failed"));
	}
}

void AMySqlConnectorGameMode::MySQL_Update_Server(const FString& SqlQuery)
{
	UpdateMySQLWorkerbool = true;
	bool IsSuccess = false;
	FString SqlCopy = SqlQuery;
	const FLatentActionInfo LatentInfo(0, FMath::Rand(), TEXT("MySQL_Update_Callback"), this);
	MysqlConnectManager->AUpdate(SqlCopy, IsSuccess, Msg, GetWorld(), LatentInfo);
}

void AMySqlConnectorGameMode::MySQL_Update_CallBack(bool IsSuccess)
{
	if (!IsSuccess)
	{
		UE_LOG(LogTemp, Warning, TEXT("update successful"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("update failed"));
	}
}

void AMySqlConnectorGameMode::MySQL_Delete_Server(const FString& SqlQuery)
{
	UpdateMySQLWorkerbool = true;
	bool IsSuccess = false;
	FString SqlCopy = SqlQuery;
	const FLatentActionInfo LatentInfo(0, FMath::Rand(), TEXT("MySQL_Delete_CallBack"), this);
	MysqlConnectManager->ADelete(SqlCopy, IsSuccess, Msg, GetWorld(), LatentInfo);
}

void AMySqlConnectorGameMode::MySQL_Delete_CallBack(bool IsSuccess)
{
	if (!IsSuccess)
	{
		UE_LOG(LogTemp, Warning, TEXT("Delete successful"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Delete failed"));
	}
}

void AMySqlConnectorGameMode::InitMysqlConnectManager(bool CreateInstance)
{
	if (CreateInstance)
	{
		MysqlConnectManager = GetGameInstance()->GetSubsystem<UMySqlConnectionSubSystem>();
		MysqlConnectManager->Init("127.0.0.1", 3306,
								  "root", "123456",
								  "dbname", 1024,
								  5, 60,
								  1500);
	}
	if (MysqlConnectManager->Connect(Msg))
	{
		UE_LOG(LogTemp, Warning, TEXT("Connect Success"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Connect Failed"));
	}
}

void AMySqlConnectorGameMode::MySql_Query_Server(const FString& SqlQuery)
{
	UpdateMySQLWorkerbool = true;
	bool IsSuccess = false;
	FString SqlCopy = SqlQuery;
	const FLatentActionInfo LatentInfo(0, FMath::Rand(), TEXT("MySQL_Query_Callback"), this);
	MysqlConnectManager->AQuery(SqlCopy, IsSuccess, Msg, Results, this,
	                            LatentInfo);
}

//登录回调，将结果赋值给PlayerInformation
void AMySqlConnectorGameMode::MySQL_Query_Callback(const bool IsSuccess)
{
	if (!IsSuccess && !Results.IsEmpty())
	{
		for (const FRowData& Row : Results)
		{
			const int IDValue = FCString::Atoi(**Row.Value.Find(TEXT("ID")));

			const FString* NameValue = Row.Value.Find(TEXT("Name"));

			const float LocationX = FCString::Atof(**Row.Value.Find(TEXT("LocationX")));

			const float LocationY = FCString::Atof(**Row.Value.Find(TEXT("LocationY")));

			const float LocationZ = FCString::Atof(**Row.Value.Find(TEXT("LocationZ")));
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Query Failed"));
	}
}
