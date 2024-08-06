def solution(topping):
    answer = 0
    topping_dict = dict() # 철수 케이크
    for top in topping :
        if top in topping_dict :
            topping_dict[top] += 1
        else :
            topping_dict[top] = 1

    young_dict = dict() # 형꺼 뺏어처먹기
    for top in topping :
        if top not in young_dict:
            young_dict[top] = 1
        topping_dict[top] -= 1
        if topping_dict[top] == 0 :
            del(topping_dict[top])


    # 키 개수 맞아야지
        if len(topping_dict) == len(young_dict) :
            answer += 1

    return answer


# def solution(topping):
#     answer = 0
#     for i in range(1, len(topping)):
#         old = tuple(topping[0:i])
#         young = tuple(topping[i:])
#         #print(set(old))
#         #print(set(young))
#         if len(set(old)) == len(set(young)) :
#
#             answer += 1
#
#
#     return answer

# def solution(topping):
#     answer = 0
#     for i in range(1, len(topping)):
#         old = topping[0:i]
#         young = topping[i:]
#         if count_zero(old) == count_zero(young):
#             answer += 1
#
#     return answer
#
#
# def count_zero(arr):
#     counts = [0] * 5
#     cnt = 0
#     for i in range(len(arr)):
#         counts[arr[i]] += 1
#
#     for i in range(1, len(counts)):
#         if counts[i] == 0:
#             cnt += 1
#
#
#     return cnt

print(solution([1, 2, 1, 3, 1, 4, 1, 2]))