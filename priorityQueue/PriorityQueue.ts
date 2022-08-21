class PriorityQueue<T> {
  private heap: T[];
  private compare: (l: T, r: T) => number;
  constructor(it: T[] | Iterable<T>, compare: (l: T, r: T) => number) {
    this.heap = [...it];
    this.compare = compare;
    this.init();
  }

  private init() {
    for (let i = Math.floor((this.heap.length - 2) / 2); i >= 0; i--) {
      this.shiftDown(i);
    }
  }

  private shiftDown(rootId: number) {
    if (rootId >= this.heap.length) return;

    let maxId = rootId;
    if (rootId * 2 + 1 < this.heap.length && this.compare(this.heap[rootId * 2 + 1], this.heap[maxId]) < 0) maxId = rootId * 2 + 1;
    if (rootId * 2 + 2 < this.heap.length && this.compare(this.heap[rootId * 2 + 2], this.heap[maxId]) < 0) maxId = rootId * 2 + 2;

    if (maxId !== rootId) { const swp = this.heap[maxId]; this.heap[maxId] = this.heap[rootId]; this.heap[rootId] = swp; this.shiftDown(maxId); }
  }

  private shiftUp(id: number) {
    if (id === 0) return;
    const parentId = Math.floor((id - 1) / 2);
    if (this.compare(this.heap[id], this.heap[parentId]) < 0) {
      const swp = this.heap[id]; this.heap[id] = this.heap[parentId]; this.heap[parentId] = swp;
      this.shiftUp(parentId);
    }
  }

  public peek(): T {
    return this.heap[0];
  }

  public enqueue(ele: T): PriorityQueue<T> {
    this.heap.push(ele)
    this.shiftUp(this.heap.length - 1);
    return this;
  }

  public dequeue(): T {
    const ret = this.heap[0];
    this.heap[0] = this.heap[this.heap.length - 1];
    this.heap.pop();
    this.shiftDown(0);
    return ret;
  }
  public empty(): boolean {
    return this.heap.length === 0;
  }
}


// test
const assert = (bool: boolean, msg: string) => {
  if (!bool) throw { msg };
}

const judge = (queue: PriorityQueue<number>, arr: number[]) => {
  for (let i = 0; i < arr.length; i++) {
    assert(queue.peek() === arr[i], `${queue.peek()} !== ${arr[i]}`);
    queue.dequeue();
  }
  console.log(`pass ${arr.length}`);
}



((testCount: number = 100, arrRange: { start: number, end: number } = { start: 10, end: 100 }, eleRange: { start: number, end: number } = { start: -100, end: 100 }) => {
  new Array(testCount).fill(undefined).map(() => {
    const arr = new Array(Math.floor(Math.random() * (arrRange.end - arrRange.start) + arrRange.start))
      .fill(undefined)
      .map(() => Math.floor(Math.random() * (eleRange.end - eleRange.start) + eleRange.start));
    return () => judge(
      new PriorityQueue(arr, (l, r) => l - r),
      [...arr].sort((l, r) => l - r)
    )
  }).map(f => f());
})();


