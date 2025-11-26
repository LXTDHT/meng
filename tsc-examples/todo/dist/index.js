"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const todoItem_1 = require("./todoItem");
const todoCollection_1 = require("./todoCollection");
let todos = [
    new todoItem_1.TodoItem(0, "Buy flowers"),
    new todoItem_1.TodoItem(1, "Get shoes"),
    new todoItem_1.TodoItem(2, "Collect tickets"),
    new todoItem_1.TodoItem(3, "Call Joe", true)
];
let collection = new todoCollection_1.TodoCollection("Nov 26", todos);
console.clear();
console.log(`To-Do List: ${collection.userName}`);
let newId = collection.addTodo("Go for run");
let todoItem = collection.getTodoById(newId);
// console.log(JSON.stringify(todoItem));
todoItem.printDetails();
