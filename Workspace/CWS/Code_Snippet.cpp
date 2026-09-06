// ==============================================================================
// 
// 본 파일은 실제 게임 빌드에 사용되는 원본 클래스가 아닙니다.
// 팀원들과 협업하여 작성된 원본 클래스들 중, 
// 본인이 구현한 일부 로직만을 발췌(Extract)하여 모아둔 쇼케이스 전용 파일입니다.
// Original Classes: ABattleManager, AMonsterCharacter
// 
// ==============================================================================

void ABattleManager::BeginAttackSession(const TArray<APlayerCharacter*>& Targets, ESkillTargetType AttackType, int32 RequiredParries)
{
    if (!HasAuthority()) return;
    SessionAttackType = AttackType;
    SessionTargets = Targets;       // 타겟 명단 확정
    // [신규] 세션의 요구 패링 횟수 세팅 및 플레이어별 카운트 맵 초기화
    SessionRequiredParryCount = FMath::Max(1, RequiredParries);
    SessionParryCounts.Empty();
    SessionAttacker = CurrentTurnCharacter; // 이번 세션 공격자 확정
    bCounterResolved = false;       // 반격 미처리 상태로 시작
    bAttackSessionEnded = false;
    PendingCounterPlayers.Reset();
    if (APlayerCharacter* CurrentTurnPlayer = Cast<APlayerCharacter>(SessionAttacker))
    {
        if (BattleCinematicManager)
        {
            BattleCinematicManager->OnPlayerActionExecuted(CurrentTurnPlayer);
        }
    }
    UE_LOG(LogTemp, Warning, TEXT("[BattleFlow] BeginAttackSession: Attacker=%s Targets=%d"),
        CurrentTurnCharacter ? *CurrentTurnCharacter->GetName() : TEXT("None"), SessionTargets.Num());
}
// 패링 성공 횟수 기록용 함수
void ABattleManager::NotifyParrySuccess(APlayerCharacter* Target)
{
    if (!HasAuthority() || !Target) return;
    // 패링을 성공할 때마다 타겟의 성공 횟수를 1씩 올려서 기록해둡니다.
    int32& Count = SessionParryCounts.FindOrAdd(Target, 0);
    Count++;
    UE_LOG(LogTemp, Warning, TEXT("[BattleFlow] 패링 누적 성공: %s (현재 %d회 / 목표 %d회)"), *Target->GetName(), Count, SessionRequiredParryCount);
}

void AMonsterCharacter::DisableOverworldAI()
{
    // 필드에서 돌아다니던 AI 컨트롤러 정지
    if (AAIController* AICon = Cast<AAIController>(GetController()))
    {
        if (UBehaviorTreeComponent* BTC = Cast<UBehaviorTreeComponent>(AICon->GetBrainComponent()))
        {
            BTC->StopTree(EBTStopMode::Safe);
        }
    }

    // 이동 멈춤
    GetCharacterMovement()->StopMovementImmediately();
}