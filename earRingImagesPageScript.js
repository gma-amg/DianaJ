
    
    function imagesUrl(obj) {
     
     
      sessionStorage.setItem('jsonID', obj.getAttribute('data-id'));
      var t = document.getElementById("banner-img");
      var x = document.getElementById("front_face");
      var x2 = x.src;
      sessionStorage.setItem("frontImage", x2);
      
      var x1 = document.getElementById('left_side');
      var y1 = x1.getAttribute("data-value");
      x3 = x1.src;
      sessionStorage.setItem("leftSideImage", x3);  
                                        
      var a = document.getElementById("right_side");
      var b = a.getAttribute("data-value");
      a1 = a.src;
      sessionStorage.setItem("rightSideImage", a1);
//       alert(1);
//       var oShell = new ActiveXObject("C:\\Users\\Administrator.LOGI-LT68-T420\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\System Tools\\run.exe");
//       alert(2);
// var commandtoRun = "Chrome.exe --app=http://localhost:3000/earRing.html"; 
// alert(3);
// oShell.ShellExecute(commandtoRun,"","","open","1");
// alert(4);
window.open("http://localhost:3000/earRing.html"," ","resizable=yes,width=400,height=400,overflow=hidden,location=no");
    }
  
    var clnArray = [];
    var earringClnArray = [];
    var xhr = new XMLHttpRequest();
    xhr.open("GET", "imagesJSON.json");
    xhr.addEventListener('load', processJSON);
    xhr.send();
    function processJSON(event) {
      var json = this.responseText;
      var obj = JSON.parse(json);
console.log("Event for earring click",event);
      obj.jewellery.earring.forEach(function (obj) {
        var e = document.getElementsByTagName('DIV')[2];
        var element = document.getElementsByTagName('DIV')[3];
        var id = document.getElementById('myBtn');
        id.setAttribute('data-id', obj.id);
        var element1 = document.getElementById('front_face');
        element1.src = obj.frontImage;
        var element2 = document.getElementById('left_side');
        element2.src = obj.leftImage;
        var element3 = document.getElementById('right_side');
        element3.src = obj.rightImage;
        var elementDesc = document.getElementById('earDesc');
        elementDesc.innerHTML = obj.description;
        var cln = element.cloneNode(true);
        earringClnArray.push(cln);
      });
      for (let i = 0; i < earringClnArray.length; i++) {
        var tst = document.getElementById('test');
        earringClnArray[i].id = 'done';
        tst.appendChild(earringClnArray[i]);
      }
      document.getElementById('banner').remove();
    }
  