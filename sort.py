#coding=utf-8
#从小到大排序

#直接插入排序
#时间复杂度O(n^2)，最好情况O(n)，空间复杂度O(1)，稳定
def insertSort(data_list, n):
	#保证前面i个是已经排好序的
	#只需将当前元素插入到适当位置即可
	for i in range(1, n):
		key = data_list[i]
		j = i - 1
		#寻找当前元素的合适位置
		#在已排好序的数列中从后往前比较
		#如果大于，则向后移动
		while j >= 0 and data_list[j] > key:
			data_list[j+1] = data_list[j]
			j -= 1
		#如果不大于，则插在后面，所以是稳定的
		data_list[j+1] = key
	return data_list

#希尔排序，分组插入
#时间复杂度O(N * logN)，最好情况未知，最坏情况O(N * logN)，空间复杂度O(1)，不稳定
def shellSort(data_list, n):
	#初始步长
	d = n / 2
	#d逐渐减小
	while d > 0:
		#把data_list[d, ... n-1]分别按插入排序插入到各组当前的有序区
		for i in range(d, n):
			key = data_list[i]
			j = i - d
			while j >= 0 and data_list[j] > key:
				data_list[j+d] = data_list[j]
				j -= d
			data_list[j+d] = key
		d /= 2

#冒泡排序（交换）
#时间复杂度O(N^2), 最坏O(N^2)，最好O(N)，空间复杂度O(1)，稳定
def bubbleSort(data_list, n):
	for i in range(0, n):
		#每趟只比较后面没排好序的数列
		for j in range(n-1, i, -1):
			#如果相邻两个是逆序，则交换位置，较小的数上浮
			if data_list[j] < data_list[j-1]:
				temp = data_list[j]
				data_list[j] = data_list[j-1]
				data_list[j-1] = temp
	return data_list

#快速排序（交换）
#时间复杂度O(N * logN)，最坏情况下退化为冒泡排序O(N*N)，空间复杂度O(N * logN)，不稳定
def quickSort(data_list, s, t):
	i = s
	j = t
	if s < t:
		#区间的第一个元素作为基准
		temp = data_list[s]
		#从两端交替向中间扫描
		while i != j:
			#从右边找到一个不大于基准元的位置，直至i=j为止
			while j > i and data_list[j] > temp:
				j -= 1
			#找到这个位置，先把不大于
			if i < j:
				data_list[i] = data_list[j]
				i += 1
			while i < j and data_list[i] < temp:
				i += 1
			if i < j:
				data_list[j] = data_list[i]
				j -= 1
		data_list[i] = temp
		quickSort(data_list, s, i-1)
		quickSort(data_list, i+1, t)

#直接选择排序（选择）
#时间复杂度O(N*N)，但是相对于冒泡排序，减少了交换次数，最坏情况O(N*N)，空间复杂度O(1)，不稳定
def selectSort(data_list, n):
	for i in range(0, n):
		k = i
		for j in range(i+1, n):
			if data_list[j] < data_list[k]:
				k = j
		if k != i:
			temp = data_list[i]
			data_list[i] = data_list[k]
			data_list[k] = temp
	return data_list


if __name__ == '__main__':
	data = [2, 4, 3, 6, 7, 2, 1, 5, 0, 9]
	#insertSort(data, len(data))
	#shellSort(data, len(data))
	#bubbleSort(data, len(data))
	#quickSort(data, 0, len(data)-1)
	selectSort(data, len(data))
	print data