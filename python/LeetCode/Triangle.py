class Solution :
	def minimumTotal(self, triangle) :
	"""
	: type triangle : List[List[int]]
	: rtype : int
	"""
	result = triangle[-1]
	for i in range(len(triangle) - 2, -1, -1) :
		for j in range(len(triangle[i])) :
			result[j] = min(result[j], result[j + 1]) + triangle[i][j]
			return result[0]