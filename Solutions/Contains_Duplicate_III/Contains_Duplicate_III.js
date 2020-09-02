const containsNearbyAlmostDuplicate = (nums, k, t) => {
  const map = nums
    .map((val, idx) => ({ val, idx }))
    .sort((a, b) => a.val - b.val);

  let l = 0;
  let r = 1;

  while (r < map.length) {
    const diff = Math.abs(map[r].val - map[l].val);
    const range = Math.abs(map[r].idx - map[l].idx);

    if (diff <= t && range <= k) return true;
    else if (diff > t) l++;
    else if (range > k) r++;

    if (l === r) r++;
  }

  return false;
};

//A little faster
/**
 * @param {number[]} nums
 * @param {number} k
 * @param {number} t
 * @return {boolean}
 */
var containsNearbyAlmostDuplicate = function(nums, k, t) {
    const hash = {}
    if (t < 0) return false
    if (t === 0) {
        for (let i = 0; i < nums.length; i++) {
            if (hash[nums[i]] === undefined) hash[nums[i]] = i
            else {
                const prev = hash[nums[i]]
                if (i - prev <= k) return true
                hash[nums[i]] = i
            }
        }
    } else {
        for (let i = 0; i < nums.length; i++) {
            const bucket = Math.floor(nums[i] / t)
            if (hash[bucket] === undefined) hash[bucket] = [i, nums[i]]
            else {
                if (i - hash[bucket][0] <= k) return true
                hash[bucket] = [i, nums[i]]
            }
            if ((hash[bucket - 1] !== undefined) && i - hash[bucket - 1][0] <= k && Math.abs(nums[i] - hash[bucket - 1][1]) <= t) return true
            if ((hash[bucket + 1] !== undefined) && i - hash[bucket + 1][0] <= k && Math.abs(nums[i] - hash[bucket + 1][1]) <= t) return true
        }
    }
    return false
};