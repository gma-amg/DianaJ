$(document).ready(function(){
  $('img')
    .wrap('<span style="display:inline-block"></span>')
    .css('display', 'block')
    .parent()
    .zoom();
});

$('#example').zoom(); // add zoom
$('#example').trigger('zoom.destroy'); // remove zoom