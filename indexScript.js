 
        var slide_index = 1;  
        displaySlides(slide_index);  
  
        function nextSlide(n) {  
            displaySlides(slide_index += n);  
        }  
  
        function currentSlide(n) {  
            displaySlides(slide_index = n);  
        }  
  
        function displaySlides(n) {  
            var i;  
            var slides = document.getElementsByClassName("showSlide");  
            if (n > slides.length) { slide_index = 1 }  
            if (n < 1) { slide_index = slides.length }  
            for (i = 0; i < slides.length; i++) {  
                slides[i].style.display = "none";  
            }  
            slides[slide_index - 1].style.display = "block";  
        }  

        var indexValue = 0;
        function slideshow(){
          setTimeout(slideshow, 4500);
          var x;
          const img = document.getElementsByClassName("showSlide");
          for(x = 0; x < img.length; x++){
            img[x].style.display = "none";
          }
          indexValue++;
          if(indexValue > img.length){indexValue = 1}
          img[indexValue -1].style.display = "block";
        }
        slideshow();

    