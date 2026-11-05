#!/bin/sh

usage()
{
	echo "사용법: $0 [-f] [-s 문자열]"
	echo " -h 도움말"
	echo " -f 플래그 활성화"
	echo " -s 문자열 지정"
	echo " e.g arg.sh -f -s \"hello\" "
	exit 1
}

if [ $# -lt 0 ]; then
	echo "인자 없음"
	exit 1
fi

STRING=""
FLAG=0

echo "실행된 스크립트 파일 명 : $0 "

echo "-- 모든 인자 목록 --"
for arg in "$@"; do
	echo "- $arg"
done

while getopts "s:fh" opt; do
	case ${opt} in

		s)
			STRING="${OPTARG}"
			;;
		f)
			FLAG=1
			;;
		h)
			usage
			;;
		\?)
			usage
			;;
	esac
done

echo "flag : $FLAG"
if [ -n "$STRING" ]; then
	echo "string : $STRING"
fi
