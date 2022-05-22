class PriorityQueue {
  constructor() {
    this.heap = [];
  }

  unshift(val) {
    this.heap.push(val);
    this.shiftUp(this.heap.length - 1);

  }

  shift() {
    const ret = this.heap[0];
    this.heap[0] = this.heap[this.heap.length - 1];
    this.heap.pop();
    this.shiftDown(0);
    return ret;
  }

  shiftUp(node) {
    const parent = Math.floor((node - 1) / 2);
    if (this.heap[node] > this.heap[parent]) {
      const temp = this.heap[node]; this.heap[node] = this.heap[parent]; this.heap[parent] = temp;
      this.shiftUp(parent);
    }
  }

  shiftDown(node) {
    const left = node * 2 + 1 >= this.heap.length ? null : this.heap[node * 2 + 1];
    const right = node * 2 + 2 >= this.heap.length ? null : this.heap[node * 2 + 2];
    let largestIdx = node;
    if (left != null && left > this.heap[largestIdx]) largestIdx = node * 2 + 1;
    if (right != null && right > this.heap[largestIdx]) largestIdx = node * 2 + 2;
    if (node === largestIdx) return;
    const temp = this.heap[node]; this.heap[node] = this.heap[largestIdx]; this.heap[largestIdx] = temp;
    this.shiftDown(largestIdx);
  }

}