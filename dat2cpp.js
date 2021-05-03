const fs = require("fs");
const imageName=localStorage.getItem('EarRingImage')
 if(imageName='EarRing'){
fs.readFile("/ear_model_final.dat", (err, data) => {
	if (err) {
		throw err;
	}

	for (let i = 0; i < data.length; i += 1) {
		console.log(data[i]);
	}
});
