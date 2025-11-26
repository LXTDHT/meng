import { TodoItem } from "./todoItem";
import { TodoCollection } from "./todoCollection";

let todos: TodoItem[] = [
    new TodoItem(0, "Buy flowers"),
    new TodoItem(1, "Get shoes"),
    new TodoItem(2, "Collect tickets"),
    new TodoItem(3, "Call Joe", true)
];
let collection: TodoCollection = new TodoCollection("Nov 26", todos);

console.clear();
console.log(`To-Do List: ${collection.userName}`);

let newId: number = collection.addTodo("Go for run");
let todoItem: TodoItem = collection.getTodoById(newId);
// console.log(JSON.stringify(todoItem));
todoItem.printDetails();