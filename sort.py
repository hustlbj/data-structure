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
#时间复杂度O(N * logN)至O(N^2)，最好情况O(N ^ 1.3)，最坏情况O(N * logN)，空间复杂度O(1)，不稳定
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
		standard = data_list[s]
		#从两端交替向中间扫描
		while i != j:
			#从右边找到一个小于基准元的元素，或者直至i=j为止
			while j > i and data_list[j] >= standard:
				j -= 1
			#只针对将首元作为基准值的情况，否则在交换时还需要temp元素
			#找到这个位置，将小元放在i端，在j这里留出一个空位
			if i < j:
				data_list[i] = data_list[j]
				i += 1
			#然后从左边找一个大于基准元的元素，或者直至i=j为止
			while i < j and data_list[i] <= standard:
				i += 1
			#找到这个位置，把大元素放到j端的空位处
			if i < j:
				data_list[j] = data_list[i]
				j -= 1
		data_list[i] = standard
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

#堆排序（选择）
#时间复杂度O(N * logN)，构建最大/小堆，每次输出最大/小，最坏O(N * logN)，空间复杂度O(1)，不稳定
def heapAdjust(data_list, s, n):
	temp = data_list[s]
	#左孩子节点的位置
	child = 2*s+1
	while (child < n):
		#如果右孩子大于左孩子，找到比当前待调整节点大的孩子
		if ((child + 1 < n) and (data_list[child] < data_list[child+1])):
			child += 1
		#如果较大的子节点大于父节点
		if (data_list[child] > data_list[s]):
			#那么把较大的子节点往上移动，替换它的父节点
			data_list[s] = data_list[child]
			#继续往下调整s节点的子树
			s = child
			child = 2*s+1
		else:
			break
		#把当前调整的节点放在孩子节点位置上
		data_list[s] = temp

def buildHeap(data_list, n):
	#最后一个有孩子的节点的位置 i = (len-1)/2
	for i in range((n-1)/2, -1, -1):
		#构建堆时从最后一层非叶节点开始，自下而上
		heapAdjust(data_list, i, n)

def heapSort(data_list, n):
	buildHeap(data_list, n)
	#排好序的元素放在列表后面
	for i in range(n-1, 0, -1):
		#交换堆顶元素和堆中最后一个元素，即把最大元素放在最后
		temp = data_list[i]
		data_list[i] = data_list[0]
		data_list[0] = temp
		#每次交换对顶元素和堆中最后一个元素之后，都要对堆进行调整
		heapAdjust(data_list, 0, i)

#将data_list_s[i...m]和data_list[m+1, ...n]归并到data_list_d中
def merge(data_list_s, data_list_d, i, m, n):
	j = m + 1
	k = i
	while i <= m and j <= n:
		if (data_list_s[j] < data_list_s[i]):
			data_list_d[k] = data_list_s[j]
			j += 1
		else:
			data_list_d[k] = data_list_s[i]
			i += 1
		k += 1
	while i <= m:
		data_list_d[k] = data_list_s[i]
		k += 1
		i += 1
	while j <= n:
		data_list_d[k] = data_list_s[j]
		k += 1
		j += 1

#非递归
def mergeSort(data_list_s, data_list_d, n):
	step = 1
	while step < n:
		left, middle, right = (0, 0, 0)
		while left + step < n:
			middle = left + step
			right = middle + step - 1
			#归并非对成的剩余
			if right > n - 1:
				right = n - 1
			print left, middle-1, right
			merge(data_list_s, data_list_d, left, middle-1, right)
			left = right + 1
		step *= 2
		#每一轮的结果还是保存在原列表中，继续下一轮
		temp = data_list_d
		data_list_d = data_list_s
		data_list_s = temp

if __name__ == '__main__':
	data = [2, 4, 3, 6, 7, 2, 1, 5, 9, 0]
	#insertSort(data, len(data))
	#shellSort(data, len(data))
	#bubbleSort(data, len(data))
	#quickSort(data, 0, len(data)-1)
	#selectSort(data, len(data))
	#heapSort(data, len(data))
	data_temp = [0 for i in range(len(data))]
	mergeSort(data, data_temp, len(data))
	print data