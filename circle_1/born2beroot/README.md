# born2beroot


## About
- born2beroot 프로젝트는 리눅스 기반 가상 머신(VM)을 직접 설치하고, 서버 및 시스템 관리의 기본을 익히는 과제입니다.  
- 최신 안정 버전의 Debian 또는 Rocky Linux를 사용하며, VirtualBox(혹은 UTM) 같은 가상화 소프트웨어를 활용해 VM을 만듭니다.
- 사용자, 그룹, 권한 관리부터 디스크 파티션 분할(LVM과 암호화 포함), 네트워크 설정, SSH 보안, 방화벽 설정 등 리눅스 서버를 운영하는 데 필수적인 시스템 환경을 직접 구축하는 경험을 제공합니다.  

---

## Review
- 깡통 데비안에서 apt, sudo, SSH 설정 등의 시스템 관리자의 역할을 실습할 수 있었다.
- 3tier-Web-Architecture를 경험할 수 있었다 (wordpress - nginx - mariadb)
- linux demon process를 학습하고 실제 데몬 서비스를 추가해볼 수 있었다. - gpm(리눅스 텍스트 기반 시스템에서 마우스 사용)

---

## Run & Test
### VM 설치 및 설정 개요
- VirtualBox(또는 UTM) 설치 후 VM 생성  
- Debian 최신 안정 버전 ISO 다운로드 및 설치  
- 루트(root) 계정과 관리자 계정 생성 
- LVM 기반 2개의 암호화된 파티션 생성 및 마운트  
- 기본 네트워크 설정, SSH 설치 및 보안 강화  
- 방화벽(UFW 또는 iptables) 설정 및 외부 접속 제한  
- 사용자 및 그룹 정책 설정 (`user42`, `sudo` 그룹 등)  

### 제출 방법
- VM의 디스크 이미지 SHA-256 해시 값 및 설치/설정 내역을 `signature.txt` 파일로 제출
- 실제 VM 파일의 경우, 많이 무겁다...

---

## Implementation Details
- **가상 머신 관리**: VirtualBox 명령줄 도구와 GUI를 병행 활용  
- **디스크 암호화**: LVM과 함께 dm-crypt/LUKS를 적용해 강력한 암호화 환경 구축  
- **사용자 관리**: `groupadd`, `usermod` 명령어로 필요한 그룹과 권한 관리  
- **서비스 관리**: systemctl을 통한 SSH 및 방화벽 서비스 활성화 및 상태 확인  
- **시스템 강화**: 비밀번호 정책 설정, 불필요한 서비스 비활성화, 보안 패치 적용 등  

---

##  Author
- **minhulee** (42Seoul cadet)  
