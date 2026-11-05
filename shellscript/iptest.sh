#!/bin/sh

if [ "$(id -u)" -ne 0 ]; then
    echo "root 권한으로 실행하는 스크립트" >&2
    exit 1
fi

TARGET_IP=""
LOG_MODE=0
LOG_FILE="/tmp/test_$(date +%Y%m%d_%H%M%S).log"

usage()
{
    echo "사용법: $0 [-i 대상아이피] [-l] [-h]"
    echo " -i IP    : 확인할 대상 IP 지정"
    echo " -l       : 로그 파일 생성 활성화"
    echo " -h       : 도움말 표시"
    exit 1
}

while getopts "i:lh" opt; do
    case ${opt} in
        i) TARGET_IP="$OPTARG"
            ;;
        l) LOG_MODE=1
            ;;
        h)
            usage
            ;;
        \?)
            usage
            ;;
    esac
done

if [ -z "$TARGET_IP" ]; then
    echo "대상 IP 미지정" 2>&1
    usage
fi

exec > >(tee -a "$LOG_FILE") 2>&1

echo "--------------------------------"
echo "확인 시간 : $(date)"
echo "대상 IP : $TARGET_IP"
echo "로그 모드 : $LOG_MODE"
echo "--------------------------------"

echo "ping 테스트 시작"
ping -c 3 "$TARGET_IP" > /dev/null 2>&1

if [ $? -eq 0 ]; then
    echo "ping 성공"
else
    echo "ping 실패"
fi

if [ $LOG_MODE -eq 1 ]; then
    echo "로그 생성: $LOG_FILE"
fi