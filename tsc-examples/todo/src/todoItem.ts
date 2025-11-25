export class TodoItem {
    public id: number; // type annotation
    public task: string;
    public complete: boolean = false;

    // the keyword 'public' is explicitly used here for the TypeScript compiler to recognize it
    public constructor(id: number, task: string, complete: boolean = false) {
        this.id = id;
        this.task = task;
        this.complete = complete;
    }

    public printDetails() : void {
        console.log(`${this.id}\t${this.task} ${this.complete ? "\t(complete)" : ""}`);
    }
}