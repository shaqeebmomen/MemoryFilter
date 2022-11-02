
def median_of_medians(A, i):

    #divide A into sublists of len 5
    sublists = [A[j:j+5] for j in range(0, len(A), 5)]
    medians = [sorted(sublist)[int(len(sublist)/2)] for sublist in sublists]
    if len(medians) <= 5:
        pivot = sorted(medians)[int(len(medians)/2)]
    else:
        #the pivot is the median of the medians
        pivot = median_of_medians(medians, int(len(medians)/2))

    #partitioning step
    low = [j for j in A if j < pivot]
    high = [j for j in A if j > pivot]

    k = len(low)
    if i < k:
        return median_of_medians(low,i)
    elif i > k:
        return median_of_medians(high,i-k-1)
    else: #pivot = k
        return pivot

def get_median(list):
    if(len(list) == 1):
        return list
    elif(len(list) == 2):
        return (list[0]+list[1])/2
    elif(len(list)%2 == 0):
        return (median_of_medians(list,int(len(list)/2)) + median_of_medians(list,int(len(list)/2)-1))/2
    else:
        return median_of_medians(list,int(len(list)/2))

#Here are some example lists you can use to see how the algorithm works
A = [1,2,3,4,5,10,8,8,9,99,10,10]
# 0 1 2 3 4 5 8 8 9 10 10 10 99
B = [1,2,3,4,5,6]
print(get_median(A))
print(get_median(B))