const endpoint = "http://192.168.102.146";

function getDapurLed() {
    fetch(endpoint + "/dapur", {
        method: "GET"
    }).then(response => response.text()).then(result => {
        if (result === "ON") {
            ledDapur.style.backgroundColor = "rgb(8, 31, 231)";
            dapurLedImage.src = "./assets/led-on.png";
        } else {
            ledDapur.style.backgroundColor = "rgb(6, 169, 245)";
            dapurLedImage.src = "./assets/led-off.png";
        }
    });
}

function getTamuLed() {
    fetch(endpoint + "/tamu", {
        method: "GET"
    }).then(response => response.text()).then(result => {
        if (result === "ON") {
            ledTamu.style.backgroundColor = "rgb(8, 31, 231)";
            tamuLedImage.src = "./assets/led-on.png";
        } else {
            ledTamu.style.backgroundColor = "rgb(6, 169, 245)";
            tamuLedImage.src = "./assets/led-off.png";
        }
    });
}

function getMakanLed() {
    fetch(endpoint + "/makan", {
        method: "GET"
    }).then(response => response.text()).then(result => {
        if (result === "ON") {
            ledMakan.style.backgroundColor = "rgb(8, 31, 231)";
            makanLedImage.src = "./assets/led-on.png"; 
        } else {
            ledMakan.style.backgroundColor = "rgb(6, 169, 245)";
            makanLedImage.src = "./assets/led-off.png"; 
        }
    });
}

function getToiletLed() {
    fetch(endpoint + "/toilet", {
        method: "GET"
    }).then(response => response.text()).then(result => {
        if (result === "ON") {
            ledToilet.style.backgroundColor = "rgb(8, 31, 231)";
            toiletLedImage.src = "./assets/led-on.png";
        } else {
            ledToilet.style.backgroundColor = "rgb(6, 169, 245)";
            toiletLedImage.src = "./assets/led-off.png";
        }
    });
}


function setDapurLed() {
    fetch(endpoint + "/dapur",  {
        method: "POST"
    }).then(response => response.text()).then(() => {
        getDapurLed();
    });
}

function setTamuLed() {
    fetch(endpoint + "/tamu",  {
        method: "POST"
    }).then(response => response.text()).then(() => {
        getTamuLed();
    });
}

function setMakanLed() {
    fetch(endpoint + "/makan",  {
        method: "POST"
    }).then(response => response.text()).then(() => {
        getMakanLed();
    });
}

function setToiletLed() {
    fetch(endpoint + "/toilet",  {
        method: "POST"
    }).then(response => response.text()).then(() => {
        getToiletLed();
    });
}

window.onload = () => {
    getDapurLed();
    getMakanLed();
    getTamuLed();
    getToiletLed();
};