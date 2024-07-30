N, M = map(int, input().split())
train = [[0]*21 for _ in range (N+1)]

lst = [list(map(int,input().split())) for _ in range (M)]


for k in range (M) :
    if len(lst[k]) == 3:
        num = lst[k][0]
        i = lst[k][1]
        x = lst[k][2]
        print(num, i, x)
        if num == 1:

            train[i][x] = 1

        elif num == 2 :
            train[i][x] = 0


    elif len(lst[k]) == 2 :
        num = lst[k][0]
        i = lst[k][1]
        print(num, i)
        #한칸씩 뒤로 미루기
        if num == 3:
            print(train[i])
            train[i] = [0, 0] + train[i][1:20]
            print(train[i])
        elif num == 4 :
            print(4)
            print(train[i])
            train[i] = [0] +train[i][2:21] + [0]
            print(train[i])



train_set = set(tuple(row) for row in train if any(row))

#train_set = set(tuple(row) for row in final_train if not all(v==0 for v in row))
print(len(train_set))

