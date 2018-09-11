class Solution:
    def canCompleteCircuit(self, gas, cost):
        total, rest, start = 0, 0, 0
        for i in range(len(gas)):
            rest = rest + gas[i] - cost[i]
            total = total + gas[i] - cost[i]
            if rest < 0:
                start = i + 1
                rest = 0
        if total >= 0:
            return start
        else:
            return -1