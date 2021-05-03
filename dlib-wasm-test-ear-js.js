const webcamVideo = document.getElementById("webcam-video");
var canvas_width = 640;
var canvas_height = 480;

const inputCanvas = document.getElementById("input-canvas");
inputCanvas.width = canvas_width;
inputCanvas.height = canvas_height;

const overlayCanvas = document.getElementById("overlay-canvas");
overlayCanvas.width = canvas_width;
overlayCanvas.height = canvas_height;


const inputCanvasCtx = inputCanvas.getContext("2d");
const overlayCanvasCtx = overlayCanvas.getContext("2d");
var earRingImageFront = sessionStorage.getItem("frontImage");
var earRingFront;
var rightEarRingURl;
var leftEarRingURl;

function mainLoop() {

	inputCanvasCtx.drawImage(webcamVideo, 0, 0, canvas_width, canvas_height);
	const inputImgData = inputCanvasCtx.getImageData(0, 0, canvas_width, canvas_height);
	const inputBufImg = Module._malloc(inputImgData.data.length);
	Module.HEAP8.set(inputImgData.data, inputBufImg);
	const ptr = Module.ccall("detect", "number", "number", [inputBufImg]) / Uint16Array.BYTES_PER_ELEMENT;
	const len = Module.HEAPU16[ptr];
	const landmarks = [];
	for (let i = 1; i < len; i += 2) {
		const l = [Module.HEAPU16[ptr + i], Module.HEAPU16[ptr + i + 1]];
		landmarks.push(l);
	}

	overlayCanvasCtx.clearRect(0, 0, canvas_width, canvas_height);
	//getting the zoom-value from the slider
	var zoomvalue=window.localStorage.getItem("zoomvalue");

	// Visually enumerate each landmark we're currently tracking
	overlayCanvasCtx.fillStyle = "rgb(130, 255, 50)";
	overlayCanvasCtx.font = "6px Arial";

	for (let i = 1; i < landmarks.length; i += 1) {

		var leftEarToNoseDistance = Math.sqrt((Math.pow(landmarks[3][0] - landmarks[6][0], 2)) + (Math.pow(landmarks[3][1] - landmarks[6][1], 2)));

		var rightEarToNoseDistance = Math.sqrt((Math.pow(landmarks[3][0] - landmarks[2][0], 2)) + (Math.pow(landmarks[3][1] - landmarks[2][1], 2)));

		var distanceVariant = leftEarToNoseDistance - rightEarToNoseDistance;
		var viewOfImage;
		if (distanceVariant < 15 && distanceVariant > -15) {
			viewOfImage = "front";
		} else if (distanceVariant < -14) {
			viewOfImage = "right";
		} else if (distanceVariant > 14) {
			viewOfImage = "left";
		}
		if (viewOfImage != null && viewOfImage == "front") {

			var earRingFront1 = '.' + earRingFront.split('5000').pop();
			const img = new Image()
			img.src = earRingFront.split('5000').pop();

			//multiplying the zoom-value/10 (because min value of slider=10)
			//so that size of earring gets increased according to zoom of video
			overlayCanvasCtx.drawImage(img, landmarks[2][0] - 6, landmarks[2][1], 25*(zoomvalue/10), 35*(zoomvalue/10));
			overlayCanvasCtx.drawImage(img, landmarks[6][0] - 6, landmarks[6][1], 25*(zoomvalue/10), 35*(zoomvalue/10));
		} else if (viewOfImage != null && viewOfImage == "right") {
			const img = new Image()
			img.src = rightEarRingURl.split('5000').pop();

			overlayCanvasCtx.drawImage(img, landmarks[2][0] - 6, landmarks[2][1], 25*(zoomvalue/10), 35*(zoomvalue/10));

		} else if (viewOfImage != null && viewOfImage == "left") {
			const img = new Image()
			img.src = leftEarRingURl.split('5000').pop();
			// overlayCanvasCtx.fillText(i, landmarks[i][0], landmarks[i][1]);

			overlayCanvasCtx.drawImage(img, landmarks[6][0] - 6, landmarks[6][1], 25*(zoomvalue/10), 35*(zoomvalue/10));
		}

	}

	Module._free(ptr);
	Module._free(inputBufImg);
	requestAnimationFrame(mainLoop);
}

window.onload = () => {

	navigator.mediaDevices.getUserMedia({ video: true }).then(stream => {
		webcamVideo.srcObject = stream;
		webcamVideo.style.display = "none";
	}).catch(err => {
		alert(err);
	});
	earRingFront = sessionStorage.getItem("frontImage");
	rightEarRingURl = sessionStorage.getItem("rightSideImage");
	leftEarRingURl = sessionStorage.getItem("leftSideImage");
	setTimeout(() => {
		const req = new XMLHttpRequest();
		req.open("GET", "/ear_model_final.dat", true);
		req.responseType = "arraybuffer";
		req.onload = (e) => {
			const payload = req.response;

			if (payload) {
				const model = new Uint8Array(payload);

				const inputBufModel = Module._malloc(model.length);
				Module.HEAPU8.set(model, inputBufModel);
				Module.ccall("init_shape_predictor", null, ["number", "number"], [inputBufModel, model.length]); // This pointer gets freed on the C++ side				
				requestAnimationFrame(mainLoop);
			}
		}

		req.send(null);
	}, 2000);
}