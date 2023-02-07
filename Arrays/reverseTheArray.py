# Write a program to reverse an array or string
def reverseArray(arr):
    out = []
    for i in range(len(arr)-1, -1,-1):
        out.append(arr[i])
    return out

def reverseString(word):
    out = ''
    for i in range(len(word)-1, -1,-1):
        out += word[i]
    return out

def reverseArrayeff(arr):
    start = 0
    end = len(arr)-1
    while start < end:
        arr[start],arr[end] = arr[end],arr[start]
        start += 1
        end -= 1
    return arr


print(reverseArray([1,2,3,4,5]))
print(reverseString('hello world'))
print(reverseArrayeff([1,2,3,4,5,6]))