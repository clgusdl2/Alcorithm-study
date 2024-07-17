#1182 부분수열의 합 24.07.17

#입력 값 받아오기
N, S = map(int, input().split())
arr = list(map(int,input().split()))
count = 0

#부분 수열 구하기
arr_split = [[0]*(2**N)]
#재귀함수
def arr_split():
    for i in range(N):
        arr_split[[i]] = arr.remove()

#내부의 합 구하기
for i in range (len(arr_split)):
    sum_arr = sum(arr_split[i])

#S인 경우의 수
if sum_arr == S:
    count += 1

#출력문
print(count)