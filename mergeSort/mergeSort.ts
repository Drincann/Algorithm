/**
 * 归并排
 * @param arr 
 */
const mergeSort = (arr: number[]): number[] => {
  if (arr.length <= 1) return arr;
  const mid = Math.floor(arr.length / 2);
  const left = mergeSort(arr.slice(0, mid));
  const right = mergeSort(arr.slice(mid));

  const result: number[] = [];
  while (left.length && right.length) {
    result.push(left[0] <= right[0] ? left.shift() as number : right.shift() as number);
  }
  return [...result, ...left, ...right];
};

console.log(mergeSort([3, 2, 1, 2, 1]))