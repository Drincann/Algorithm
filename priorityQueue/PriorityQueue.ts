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

  private swap(i: number, j: number) {
    const swp = this.heap[i]; this.heap[i] = this.heap[j]; this.heap[j] = swp;
  }

  private shiftDown(id: number) {
    while (id * 2 + 1 < this.heap.length) {
      let childId = id * 2 + 1;
      if (childId + 1 < this.heap.length && this.compare(this.heap[childId + 1], this.heap[childId]) < 0) childId++;
      if (this.compare(this.heap[id], this.heap[childId]) <= 0) break;
      this.swap(id, childId);
      id = childId;
    }
  }

  private shiftUp(id: number) {
    let rootId = Math.floor((id - 1) / 2);
    while (id > 0 && this.compare(this.heap[id], this.heap[rootId]) < 0) {
      this.swap(id, rootId);
      id = rootId;
      rootId = Math.floor((id - 1) / 2);
    }
  }

  public peek(): T {
    return this.heap[0];
  }

  public enqueue(ele: T): PriorityQueue<T> {
    this.shiftUp(this.heap.push(ele) - 1);
    return this;
  }

  public dequeue(): T | undefined {
    if (this.heap.length !== 1) {
      const ret = this.heap[0];
      this.heap[0] = this.heap.pop() as T;
      this.shiftDown(0);
      return ret;
    } else return this.heap.pop();
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
    let peek = queue.peek();
    if (peek !== arr[i]) {
      debugger
    }
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


