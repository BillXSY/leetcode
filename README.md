# leetcode
# a backup of my own leetcode solution!

|      |      |      |
| ---- | ------------ | ---- |
| 3. |无重复字符的最长子串	|哈希集合|
|215.| 数组中的第K个最大元素|	类快排|
|206.| 反转链表|		prev curr next|
|25. |K 个一组翻转链表	|逐段检测是否足够项，逐段翻转，返回头尾|
|146. |LRU缓存机制	|	双向链表+哈希表|
|103. |二叉树的锯齿形层次遍历	|BFS+stack+bool reverseSubNodes|
|15.| 三数之和	| a+b+c=0 从左向右递增a，对于每一个a：<br />b从a+1位置开始递增，c从size()-1位置开始递减， |
|121. |买卖股票的最佳时机	|记录历史股价最小值和当天收益值 return历史最大收益值|
|160.| 相交链表		|走过你来时的路 la->lb, lb->la|
|1. |两数之和	|	哈希表<数值，下标>|
|236.| 二叉树的最近公共祖先|后序遍历 (left && right) |
|42. |接雨水	| 双指针，维护 leftMax rightMax，若height[left] < height[right] 说明右侧一定不会溢出<br />ans += leftMax - height[left]; |
|53. |最大子序和	|	localMax = max(localMax+x, x)   globalMax = max(globalMax, localMax) |
|415. |字符串相加	|	模拟位运算: '0' + thisBit |
|31. |下一个排列	| 将一个左边的「较小数」与一个右边的「较大数」交换，<br />从右向左找到第一个非递增数->「较小数」<br />若找到了「较小数」，再次从右向左找第一个比「较小数」大的数->「较大数」, 交换两者<br />「较大数」右边的数需要按照升序重新排列 |
|46. |全排列	| 回溯算法  <br />backTrack(int first, int length, vector<vector<int>>& ans, vector<int>& nums )<br />    swap(nums[i], nums[first]);   <br />    backTrack(first+1, length, ans, nums);  <br />    swap(nums[i], nums[first]); |
|23.| 合并K个升序链表	| 定义新struct，重载operator<；建priority_queue <Status> q，<br />把k个链表的head压入queue，<br />while queue不为空，pop出value最小的node，连上，<br />再把node的next*压回queue |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |
|| 	|  |