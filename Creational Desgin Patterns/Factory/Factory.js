var Circle = function() {
  this.draw = function() {
    console.log("Circle");
  };
};
var Rectangle = function() {
  this.draw = function() {
    console.log("Rectangle");
  };
};
var Square = function() {
  this.draw = function() {
    console.log("Square");
  };
};
function shapeFactory() {
  this.create = function(shapeType) {
    var shape = "";
    if (shapeType === "Circle") shape = new Circle();
    else if (shapeType === "Rectangle") shape = new Rectangle();
    else if (shapeType === "Square") shape = new Square();
    else console.log("not Supported yet");

    return shape;
  };
}
var factoty = new shapeFactory();

var rectangle = factoty.create("Rectangle");
var circle = factoty.create("Circle");
var square = factoty.create("Square");

rectangle.draw();
circle.draw();
square.draw();
