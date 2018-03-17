def same_fate(s1,s2):

#     if s1 == s2:
#         return ""

#     str1 = ""
#     while s1!=1:
#         if s1%2 == 1:
#             str1 = str1 + 'R'
#         else:
#             str1 = str1 + 'L'
#         s1 = s1/2

#     str2 = ""
#     while s2!=1:
#         if s2%2 == 1:
#             str2 = str2 + 'R'
#         else:
#             str2 = str2 + 'L'
#         s2 = s2/2

#   ans = ""

   s1 = str1
   s2 = str2

   n1 = len(str1)
   n2 = len(str2)

   if n1 < n2:
       swap(str1,str2)
       swap(n1,n2)

    for i in range(0,n2):
        temp = ""
        for j in range(i,n2):
            temp = temp + str2[j]
            if (temp in str1) and (len(temp) > len(ans) or (len(temp) == len(ans) and temp < ans ) ):
                ans = temp
    return ans

print same_fate(ABC, AABCAA)
