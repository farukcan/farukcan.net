function CanvasRender(canvasId){ 
	/* var */
	this.canvas = document.getElementById(canvasId);
	this.context = this.canvas.getContext('2d');
	this.standartFont = "18px Arial";
	this.font(this.standartFont); // default font

	this.clickElement = [];
}


CanvasRender.prototype = {
	update : function (){

	},

	clear : function(){
		this.context.clearRect(0, 0,this.canvas.width, this.canvas.height);
	},

	color : function ( color ){
		return this.context.fillStyle = color;
	},

	strokeStyle : function (strokeStyleI) {
		this.context.strokeStyle = strokeStyleI;
	},

	line : function (a,b,c,d) {
		this.context.beginPath();
		this.context.moveTo(a,b);
		this.context.lineTo(c,d);
		this.context.stroke();
	},

	circle : function (x,y,r,sAngle,eAngle) {
		if(typeof sAngle == 'undefined') sAngle = 0;
		if(typeof eAngle == 'undefined') eAngle = 2*Math.PI;
		this.context.beginPath();
		this.context.arc(x,y,r,sAngle,eAngle);
		this.context.stroke();
	},

	fill : function (){
		this.context.fill();
	},

	font : function (f){
		this.context.font = f;
	},
	text : function (t,x,y,maxW){
		this.context.fillText(t,x,y,maxW);
	},

	textStroke : function (t,x,y,maxW){
		this.context.strokeText(t,x,y,maxW);
	},

	addClickListener : function(f,a){
		var t = this;
		if(typeof a != 'undefined')
			t.clickElement = a;
		this.canvas.addEventListener('click', function(event) {
			var x = event.pageX - t.canvas.offsetLeft,
				y = event.pageY - t.canvas.offsetTop;

			var founded=false;
			t.clickElement.forEach(function(element) {
				if (y > element.top && y < element.top + element.height
					&& x > element.left && x < element.left + element.width) {
					element.func();
					founded = true;
				}
			});
			if(!founded)
				f(x,y);
		}, false);
	}


}
