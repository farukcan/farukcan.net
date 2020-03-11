function Heap(sortFunc){
    this.nodes = [];
    this.sortFunc= sortFunc || function(a,b){return a-b;};

    this.func = function(a,b){
            return this.sortFunc(a,b) < 0;
    }
}



Heap.prototype = {
    add : function(e){
        var x = this.nodes.length;
        this.nodes.push(e);
        var p = this.parent(x);

        // heapify2up
        while(x!=0 && this.func(this.nodes[x],this.nodes[p])){
            this.nodes[x]=this.nodes[p];
            this.nodes[p]=e;

            x=p;
            e = this.nodes[x];
            p=this.parent(x);
        }

        return this.nodes;

    },
    get : function(){
        var r = this.nodes.shift();

        //heapify2down
        var x = 0;
        var childs = this.childs(x);
        var min;
        while(childs.length!=0){
            min=childs[0];
            if(childs.length==2 && !this.func(this.nodes[childs[0]],this.nodes[childs[1]])){
                min = childs[1];
            }

            if(this.func(this.nodes[min],this.nodes[x])){
                var temp = this.nodes[x];
                this.nodes[x] = this.nodes[min];
                this.nodes[min] = temp;
                x = min;
                childs = this.childs(x);
            }
            else childs=[]
        }
        return r;
    },
    isEmpty : function(){
        return this.nodes.length==0;
    },
    parent : function(x){
        if(this.right(x)) return x/2-1;
        return (x-1)/2;
    },
    childs : function(x){
      var a = [];
      if(this.nodes[2*x+1]){
          a.push(2*x+1);
          if(this.nodes[2*x+2])
              a.push(2*x+2);
      }
      return a;
    },
    right : function(x){
        return x%2==0;
    }
};

