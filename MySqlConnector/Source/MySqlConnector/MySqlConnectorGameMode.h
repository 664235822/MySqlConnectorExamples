// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ConnectionPoolManager.h"
#include "GameFramework/GameModeBase.h"
#include "MySqlConnectorGameMode.generated.h"

UCLASS(minimalapi)
class AMySqlConnectorGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AMySqlConnectorGameMode();

	bool UpdateMySQLWorkerbool = false;

	UPROPERTY()
	TArray<FRowData> Results; //结果

	UPROPERTY(BlueprintReadWrite)
	UConnectionPoolManager* MysqlConnectManager; //mysql连接管理器

	virtual void BeginPlay() override;
	UPROPERTY()
	FString Msg;

	UFUNCTION(BlueprintCallable)
	void InitMysqlConnectManager(bool CreateInstance);

	UFUNCTION(BlueprintCallable)
	void MySql_Query_Server(const FString& SqlQuery);
	UFUNCTION(BlueprintCallable)
	void MySQL_Query_Callback(bool IsSuccess);
	UFUNCTION(BlueprintCallable)
	void MySQL_UpdateArray_Server(const TArray<FString>& SqlArray);
	UFUNCTION(BlueprintCallable)
	void MySQL_UpdateArray_Callback(bool IsSuccess);
	UFUNCTION(BlueprintCallable)
	void MySql_InsertArray_Server(const TArray<FString>& SqlArray);
	UFUNCTION(BlueprintCallable)
	void MySQL_InsertArray_Callback(const bool IsSuccess);
	UFUNCTION(BlueprintCallable)
	void MySql_DeleteArray_Server(const TArray<FString>& SqlArray);
	UFUNCTION(BlueprintCallable)
	void MySQL_DeleteArray_Callback(const bool IsSuccess);
	UFUNCTION(BlueprintCallable)
	void MySQL_Insert_Server(const FString& SqlQuery);
	UFUNCTION(BlueprintCallable)
	void MySQL_Insert_CallBack(bool IsSuccess);
	UFUNCTION(BlueprintCallable)
	void MySQL_Update_Server(const FString& SqlQuery);
	UFUNCTION(BlueprintCallable)
	void MySQL_Update_CallBack(bool IsSuccess);
	UFUNCTION(BlueprintCallable)
	void MySQL_Delete_Server(const FString& SqlQuery);
	UFUNCTION(BlueprintCallable)
	void MySQL_Delete_CallBack(bool IsSuccess);
};
