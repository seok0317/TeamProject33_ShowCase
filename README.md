# TeamProject33_ShowCase
- 본 Repository는 원본 프로젝트에서 제가 직접 작성한 코드만 포함되어 있습니다
- 본 프로젝트는 학습 목적의 팀 프로젝트이며, 사용된 일부 에셋은 본 Repository에 포함되어 있지 않습니다.

## 프로젝트 소개
- 언리얼 엔진 5.3 기반, 3인 팀이 제작한 턴제 · 멀티플레이 전투 프로젝트입니다.
- 개발 기간: 2026.05.21 ~ 2026.06.21 (1달)


## 영상 / 발표 자료
- [![유튜브](https://img.youtube.com/vi/KkahjDrRlY4/maxresdefault.jpg)](https://www.youtube.com/watch?v=KkahjDrRlY4)
- 📑 포트폴리오 [PDF](https://drive.google.com/file/d/1r8uo7STeOn1t6OC216ol6wmRWg2eQkWf/view?usp=drivesdk)
- 📑 포트폴리오 [PPT](https://docs.google.com/presentation/d/12xlpemVK9AF_kASMzl9C3ibNMOBrV1KR/edit?usp=drive_link&ouid=112638998788497552413&rtpof=true&sd=true)

## 팀원 소개
- 최영우(팀장): 전투 카메라/연출/전투 UI
- 김현빈: 턴제 전투 코어/캐릭터/로비
- 최우석(본인): 몬스터 AI/전투 컴포넌트/Anim Notify/스킬

## 담당 역할

**전투 시스템**
- CombatComponent, BattleManager 일부, CombatTypes 등 전투 상태 관리 로직 및 타겟팅 시스템
- 데이터 테이블 기반 스킬 설계

**패링 · 카운터 시스템**
- 데이터 주도 방식의 다단 패링 및 단체 카운터 조건 검사 로직

**애니메이션 & 액션 제어**
- AnimNotifyState_MeleeDash 기반 프레임 단위 위치 제어
- 스킬/패링/카운터 몽타주
  
**몬스터 AI**
- 필드 배회·순찰 AI, 전투 진입 시 AI 셧다운 로직

## 기술 스택
Unreal Engine 5.3, C++
