    //getting the image of selected earring to be placed on top of video stream
    var x = sessionStorage.getItem('jsonID');
    var xhr = new XMLHttpRequest();
    xhr.open("GET", "imagesJSON.json");
    xhr.addEventListener('load', processJSON);
    xhr.send();
    function processJSON(event) {
      var json = this.responseText;
      var obj = JSON.parse(json);

      obj.jewellery.earring.forEach(function (obj) {
        if ((obj.id) == x) {
          sessionStorage.setItem("frontImage", obj.frontImage);
          sessionStorage.setItem("leftSideImage", obj.rightImage);
          sessionStorage.setItem("rightSideImage", obj.leftImage);

          //getting the selected earing in a ear object for
          //display of product separately on right hand side
          var neck=document.getElementById("ear");
          ear.src=obj.frontImage;
        }
      });
    }
  
    //function for slider-zoom of video + earring
    navigator.mediaDevices.getUserMedia({video: { zoom: true }})
      .then(mediaStream => {
        document.querySelector('video').srcObject = mediaStream;

        const [track] = mediaStream.getVideoTracks();
        const capabilities = track.getCapabilities();
        const settings = track.getSettings();
        console.log(settings);

        const input = document.querySelector('input[type="range"]');
        console.log(input);

        // Check whether zoom is supported or not.
        if (!('zoom' in settings)) {
          return Promise.reject('Zoom is not supported by ' + track.label);
        }

        // Map zoom to a slider element.
        input.min = capabilities.zoom.min;
        input.max = capabilities.zoom.max;
        input.step = capabilities.zoom.step;

        //setting the initial input value as 0
        //so while initally trying on earring, the slider is at the beginning
        input.value = 0;
        track.applyConstraints({advanced: [ {zoom: input.value} ]});

        //on changing slider value
        input.oninput = function(event) {
          track.applyConstraints({advanced: [ {zoom: event.target.value} ]});
        }

        input.hidden = false;
      })
      .catch(error => ChromeSamples.log('Argh!', error.name || error));