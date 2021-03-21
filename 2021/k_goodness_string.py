# for test_case in range(int(input())):
#     n, k = map(int, input().split())
#     s = input()
#     op = 0
#     for i in range(1, n//2):
#         if s[i]!=s[(n-1)-i+1]:
#             op += 1
#     if op == k:
#         op = 0
#     else:
#         op = abs(k-op)
#     print("Case #{0}: {1}".format(test_case+1, op))



t=int(input())
for j in range(1,t+1):
    n,k=map(int,input().split())
    s=input()
    l=n//2
    c=0
    c1=0
    for i in range(1,l+1):
        if s[i]!=s[(n-i+1)-1]:
            c=c+1
    if c==k:
        print("Case #{0}: {1}".format(j,c))
    else:
        for i in range(1,l+1):
            if s[i]==s[(n-i+1)-1]:
                c1=c1+1
                c=c+c1
                if c==k:
                    break
        print("Case #{0}: {1}".format(j,c1))